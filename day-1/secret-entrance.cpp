#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(){
    std::cout << "Welcome to the secret entrance!" << std::endl;

    std::ifstream file("input.txt");
    std::vector<std::string> moves;
    std::string move;
    
    while (file >> move) {
        moves.push_back(move);
    }
    file.close();

    return 0;
}