#include "Sed.hpp"

SedObject::SedObject(std::string file)
{
    this->old_file = file;
    this->new_file = file + ".replace";
}

SedObject::~SedObject(void){}

void SedObject::replace(std::string a, std::string b) 
{
    std::ifstream   file(this->old_file.c_str());
    std::string line;
    if (file.is_open()) 
    {
        if (std::getline(file, line, '\0')) {
            std::ofstream ofs(this->new_file.c_str());
            size_t pos = line.find(a);
            while (pos != std::string::npos) 
            {
                line.erase(pos, a.length());
                line.insert(pos, b);
                pos = line.find(a);
            }
            ofs << line;
            ofs.close();
        }
        else 
        {
            std::cout << RED << BOLD << "Erreur !" << END << std::endl;
            std::cerr << WHITE << "Fichier vide." << END << std::endl;
        }
        file.close();
    }
    else 
    {
        std::cout << RED << BOLD << "Erreur !" << END << std::endl;
        std::cerr << WHITE << "Fichier introuvable ou inexistant." << END << std::endl;
        exit(1);
    }
}