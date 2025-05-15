#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe( std::vector<int> vlst, std::deque<int> dlst ) 
    : vlist(vlst)
    , dlist(dlst)
    , level(1)
{}

PmergeMe::PmergeMe(const PmergeMe& other)
    : vlist(other.vlist)
    , dlist(other.dlist)
    , level(other.level)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
    if(this != &other)
    {
        vlist = other.vlist;
        dlist = other.dlist;
        level = other.level;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{}

long	ft_atoi(const char *str)
{
	long res;
	int  i;
	int  sign;
    long err_ret = 9999999999;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		if (res > 2147483647)
		{
            if(sign == 1 || (sign == -1 && res > 2147483648))
                return (err_ret);
		}
		i++;
	}
    if(str[i] && (str[i] < '0' || str[i] > '9')){
        return (err_ret);
    }
	return (res * sign);
}

static bool nbr_valid(const char* nbr_s)
{
    long err_ret = 9999999999;
    long n = ft_atoi(nbr_s);

    if (n == err_ret || n < 0)
        return false;
    return true;
}

PmergeMe* take_nbrs(char **_args, int count)
{
    std::vector<int> vlst;
    std::deque<int> dlst;
    for(int i = 0; i < count; i++){
        if(!nbr_valid(_args[i]))
            throw PmergeMe::error_execption();
        dlst.push_back(std::atoi(_args[i]));
        vlst.push_back(std::atoi(_args[i]));
    }
    return new PmergeMe(vlst, dlst);
}

void PmergeMe::sort(void)
{
    vtimer = clock();
    merge_insertion_sort<std::vector<int>, v_it>(get_vlist());
    vtimer = clock() - vtimer;

    dtimer = clock();
    merge_insertion_sort<std::deque<int>, d_it>(get_dlist());
    dtimer = clock() - dtimer;
}

void PmergeMe::print(void)
{
    std::cout << "Before:   ";
    show_nbrs<std::vector<int>, v_it>(get_vlist().begin(), get_vlist().end());

    sort();

    std::cout << "After:   ";
    show_nbrs<std::vector<int>, v_it>(get_vlist().begin(), get_vlist().end());
    std::cout << "Time to process a range of   " << get_vlist().size() << " elements with std::vector :  " << vtimer / 1000.0 << " ms\n";
    std::cout << "Time to process a range of   " << get_dlist().size() << " elements with std::deque :  " << dtimer / 1000.0 << " ms\n";

}

unsigned long jacobsthal_sec(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    int a = 0;
    int b = 1;
    int result = 0;

    for (int i = 2; i <= n; ++i) {
        result = b + 2 * a;
        a = b;
        b = result;
    }

    return result;
}

std::deque<int>& PmergeMe::get_dlist()
{
    return dlist;
}

std::vector<int>& PmergeMe::get_vlist()
{
    return vlist;
}

// error_excption definition
const char* PmergeMe::error_execption::what() const throw()
{
    return "Error";
}