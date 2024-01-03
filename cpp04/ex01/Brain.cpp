# include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain created." << std::endl;
    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = "";
    }
    
}

Brain::~Brain()
{
    std::cout << "Brain destroyed." << std::endl;
}

Brain::Brain(const Brain& b)
{
    (*this) = b;
}

Brain& Brain::operator=(const Brain& b)
{
    std::cout << "Brain copied." << std::endl;
    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = b.ideas[i];
    }
    return (*this);
}

std::string Brain::getIdea(int index)
{
    if (index >= 0 && index <= 99)
        return (this->ideas[index]);
    return ("");
}

void    Brain::setIdea(int index, std::string idea)
{
    if (index >= 0 && index <= 99)
        this->ideas[index] = idea;
}

void    Brain::setIdea(std::string idea)
{
    for (size_t i = 0; i < 100; i++)
    {
        if (this->ideas[i] == "")
        {
           this->ideas[i] = idea;
           break ; 
        }
    }
}