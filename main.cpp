#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("text.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open text.txt\n";
        return 1;
    }

    std::string line;
    while (getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
    return 0;
}
