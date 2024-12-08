#ifndef UTILS_HPP
#define UTILS_HPP

#include <vector>
#include <string>

class Utils {
public:
    void saveToFile(const std::string& filename, int iteration, const std::vector<std::vector<int>>& grid);
};

#endif // UTILS_HPP


 
