#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    private:
        Brain* cat_brain;

    public:
        Cat();
        ~Cat();
        Cat(const Cat&);
        Cat& operator=(const Cat&);

        void makeSound() const;
        std::string getType() const;
};

#endif