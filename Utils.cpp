#include "Utils.hpp"
#include <fstream>
#include <filesystem>

void Utils::saveToFile(const std::string& filename, int iteration, const std::vector<std::vector<int>>& grid) {
    std::filesystem::create_directory("output");

    std::ofstream outFile("output/" + filename + "_" + std::to_string(iteration) + ".txt");
    if (outFile.is_open()) {
        for (const auto& row : grid) {
            for (int cell : row) {
                outFile << cell << " ";
            }
            outFile << "\n";
        }
    }
}
