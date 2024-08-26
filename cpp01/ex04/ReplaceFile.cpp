#include "ReplaceFile.hpp"
#include <iostream>
#include <fstream>

ReplaceFile::ReplaceFile(const std::string& filename, const std::string& s1, const std::string& s2) : filename(filename), s1(s1), s2(s2) {}

int ReplaceFile::replacing()
{
    std::ifstream infile(this->filename);
    if (!infile)
    {
        std::cout << "Failed to open file" << std::endl;
        return (1);
    }

    std::string new_infile = this->filename + ".replace";
    std::ofstream outfile(new_infile);
    if (!outfile)
    {
        std::cout << "Failed to open file" << std::endl;
        return (1);
    }

    std::string line;
    size_t pos;

    while (std::getline(infile, line))
    {
        pos = line.find(s1);
        while (pos != std::string::npos)
        {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos = line.find(s1, pos + s2.length());
        }
        outfile << line;
        if(!infile.eof())
            outfile << std::endl;
    }
    return (0);
}