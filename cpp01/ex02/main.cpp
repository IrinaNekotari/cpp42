# include <iostream>

int main(void)
{
   std::string test = "HI THIS IS BRAIN";
   std::string *stringPTR = &test;
   std::string &stringREF = test;
   std::cout << &test << ": " << test << std::endl;
   std::cout << stringPTR << ": " << *stringPTR << std::endl;
   std::cout << &stringREF << ": " << stringREF << std::endl;
}