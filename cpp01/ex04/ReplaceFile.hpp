#ifndef REPLACEFILE_HPP
# define REPLACEFILE_HPP

# include <string>

class ReplaceFile
{
    private:
        std::string filename;
        std::string s1;
        std::string s2;
    
    public:
        ReplaceFile(const std::string& filename, const std::string& s1, const std::string& s2);
        int replacing();

};

#endif