#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <exception>
#include <sys/time.h>
#include <ctime>


unsigned long jacobsthal_sec(int n);

template <typename container, typename iterator>
bool is_sorted(container& lst)
{
    iterator it = lst.begin();
    int tmp_value = *it;
    while(++it != lst.end())
    {
        if(*(it) < tmp_value){
            // std::cout << "-----------> " << *(it) << "  || " << tmp_value << '\n';
            return false;
        }
        tmp_value = *it;
    }
    return true;
}

class PmergeMe
{
    private:
        std::vector<int> vlist;
        std::deque<int> dlist;
        
        int level;
        std::clock_t vtimer;
        std::clock_t dtimer;

    public:
        // the canonical form need here
        PmergeMe( std::vector<int>, std::deque<int> );
        PmergeMe( const PmergeMe& );
        PmergeMe& operator=( const PmergeMe& );
        ~PmergeMe();

        typedef std::deque<int>::iterator d_it;
        typedef std::vector<int>::iterator v_it;

        template <typename container, typename iterator>
        void show_nbrs(iterator begin, iterator end)
        {
            for(iterator it = begin; it != end; it++){
                std::cout << *it;
                if(it != end - 1)
                    std::cout << " ";
            }
            std::cout << '\n';
        }

        template <typename container, typename iterator>
        void merge(container& lst)  // the previous one was ==> void merge(std::deque<int>& lst)
        {
            iterator first1;
            iterator last1;
            iterator first2;
            iterator last2;

            if(level > static_cast<int>(lst.size() / 2) ){
                level /= 2;
                return ;
            }

            int nb_elmts = level;
            first1 = lst.begin();
            first2 = first1 + nb_elmts;
            while(true)
            {
                last1 = first1 + nb_elmts - 1;
                last2 = first2 + nb_elmts - 1;
                if(last2 >= lst.end())
                    break;
                if(*last1 > *last2)
                    std::swap_ranges(first1, last1 + 1, first2);

                first1 += nb_elmts * 2;
                first2 += nb_elmts * 2;
            }
            level *= 2;
            merge<container, iterator>(lst);
        }

        template <typename container, typename iterator>
        void add2container(container& lst, iterator first, iterator last)
        {
            while(first != last)
            {
                lst.push_back(*first);
                first++;
            }
        }

        template <typename container, typename iterator>
        container   main_gen(container& lst)
        {
            container main;
            int nb = level;
            iterator it = lst.begin();
            add2container<container, iterator>(main, it, it + (nb * 2)); // inset b1 a1
            it += nb * 3; // skip b1 a1 b2
            while(true)
            {
                if(std::distance(it, lst.end()) < nb || it == lst.end())
                    break;
                add2container<container, iterator>(main, it, it + nb);
                it += nb * 2; // skip the next b(n+1) after a(n) inserted
            }
            return main;
        }

        template <typename container, typename iterator>
        container   pend_gen(container& lst)
        {
            container pend;
            int nb = level;
            iterator it = lst.begin() + (nb * 2);
            if (it == lst.end() || std::distance(it, lst.end()) < nb)
                return pend;
            add2container<container, iterator>(pend, it, it + nb); // add b2
            it += nb * 2; // skip a2
            while(true)
            {
                if(it == lst.end() || std::distance(it, lst.end()) < nb)
                    break;
                add2container<container, iterator>(pend, it, it + nb);
                it += nb * 2; // skip the next a(n+1) after b(n) inserted
            }
            return pend;
        }

        template <typename container, typename iterator>
        container   bigers_sorted(container& main)
        {
            container sorted;
            iterator it = main.begin() + level - 1; // get the bigger in a set inside the main
            while(it < main.end())
            {
                sorted.push_back(*it);
                it += level;
            }
            return sorted;
        }

        template <typename container, typename iterator>
        iterator    upper_pair_it(container& main, int value)
        {
            container bigers_container = bigers_sorted<container, iterator>(main);
            iterator b_it = std::upper_bound(bigers_container.begin(), bigers_container.end(), value);
            if(b_it == bigers_container.end())
                return main.end();
            iterator it = std::find(main.begin(), main.end(), *b_it);
            int n =  std::distance(main.begin(), it) % level; // offset --> the number could be somwhere in the middle of the chunk inside the main
            it -= n;
            return it;
        }

        template <typename container, typename iterator>
        void middle_insert(container& to, container&from, iterator to_it, iterator from_it)
        {
            iterator it = from_it;
            int count = 0;
            while (count < level && it != from.end() && to_it != to.end())
            {
                to_it = to.insert(to_it, *it);
                ++it;
                ++to_it;
                ++count;
            }
        }

        template <typename container, typename iterator>
        void pend2main(container& main, container pend)
        {
            if(pend.empty())
                return ;
			iterator p_chunk_start = pend.begin();
			iterator p_chunk_end = p_chunk_start + level - 1;
            iterator m_it = main.begin();
			int total_p_chunks = pend.size() / level;
			int jacob_id = 0;
			int n = -1;

            while(true)
            {                
				if(total_p_chunks == 0)
                    break;
                
                jacob_id = static_cast<int>(jacobsthal_sec(++n) % total_p_chunks);
                // jacob_id = 0;
				p_chunk_start = pend.begin() + jacob_id * level;
				p_chunk_end = p_chunk_start + level - 1;
                m_it = upper_pair_it<container, iterator>(main, *p_chunk_end);
                middle_insert<container, iterator>(main, pend, m_it, p_chunk_start);
                
				pend.erase(p_chunk_start, p_chunk_end + 1);
                --total_p_chunks;
            }
        }

        template <typename container, typename iterator>
        void new_list(container& lst, container& main)
        {
            // lst.resize(main.size());
            iterator m_it = main.begin();
            iterator lst_it = lst.begin();
            while(m_it != main.end())
            {
                *lst_it = *m_it;
                lst_it++;
                m_it++;
            }
        }

        template <typename container, typename iterator>
        void insert(container& lst)
        {
            container main;
            container pend;
            
            if(level <= 0){
                // if(is_sorted<container, iterator>(lst))
                //     return ;
                // else{
                //     level = 1;
                //     merge<container, iterator>(lst);
                //     insert<container, iterator>(lst);
                // }
                return;
            }
            
            main = main_gen<container, iterator>(lst);
            pend = pend_gen<container, iterator>(lst);
            
            
            pend2main<container, iterator>(main, pend);
            new_list<container, iterator>(lst, main);


            level /= 2;
            insert<container, iterator>(lst);
        }

        template <typename container, typename iterator>
        void merge_insertion_sort(container& set_nbrs)
        {
            level = 1;
            merge<container, iterator>(set_nbrs);
            insert<container, iterator>(set_nbrs);
        }

        void sort(void);
        void print(void);

        // getters
        std::vector<int>& get_vlist();
        std::deque<int>& get_dlist();

        // exception
        class error_execption : public std::exception
        {
            const char* what() const throw();
        };
};

PmergeMe*	take_nbrs(char **args, int count);
long long	current_time_us();



#endif