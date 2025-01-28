#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        static std::string level[];
        typedef void (Harl::*ptr)(void);
        static ptr complain_list[];

    public:
        Harl();
        ~Harl();
        void complain( std::string level );
        
};

#endif