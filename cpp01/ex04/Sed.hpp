# pragma once
# include <iostream>
# include <fstream>
# include <cstdlib>

# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define BLUE "\x1b[34m"
# define CYAN "\x1b[36m"
# define YELLOW "\x1b[33m"
# define PURPLE "\x1b[35m"
# define WHITE "\x1b[37m"
# define BOLD "\x1b[1m"
# define LINE "\x1b[4m"
# define END "\x1b[0m"

class SedObject
{
    private :
        std::string     old_file;
        std::string     new_file;
    public :
        SedObject(std::string file);
        ~SedObject();
        void    replace(std::string a, std::string b);
};