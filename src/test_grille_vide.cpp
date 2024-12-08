#include <iostream>
#include <fstream>

void createEmptyGrid(const std::string& filename, int width, int height) {
    std::ofstream file(filename);
    if (!file) {
        std::cerr << "Erreur lors de la création du fichier : " << filename << std::endl;
        return;
    }

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            file << 0 << " ";
        }
        file << "\n";
    }

    file.close();
    std::cout << "Fichier " << filename << " créé avec une grille vide." << std::endl;
}

int main() {
    int gridWidth = 10; // Modifiez si nécessaire
    int gridHeight = 10; // Modifiez si nécessaire
    createEmptyGrid("test_grille_vide.txt", gridWidth, gridHeight);
    return 0;
}
