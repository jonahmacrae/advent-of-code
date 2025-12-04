#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main(){
    std::cout << "Welcome to the secret entrance!" << std::endl;

    std::ifstream file("input.txt");
    std::vector<std::pair<char, int>> moves;
    std::string move;
    
    while (file >> move) {
        char direction = move[0];               // L or R
        int steps = std::stoi(move.substr(1));  // number of steps
        moves.push_back({direction, steps});
    }
    file.close();

    // To access direction, use moves[i].first
    // To access steps, use moves[i].second

    int dial = 50;
    int zeroCount = 0;
    
    for (int i = 0; i < moves.size(); i++) {
        std::cout << "Move #" << i << " : " << moves[i].first << moves[i].second << std::endl;

        if (moves[i].first == 'L') {
            dial -= moves[i].second;
            std::cout << "Dial: " << dial << std::endl;
        } else {
            dial += moves[i].second;
            std::cout << "Dial: " << dial << std::endl;
        }

        if ((dial < 0 || dial == 0) && dial + moves[i].second > 0) {   // crossed zero going left
            zeroCount++;
        }

        zeroCount += std::floor(std::abs(dial / 100.0));
        dial %= 100;
        if (dial < 0) { // wrap around for negative values
            dial += 100;
        }

        std::cout << "Zero Count: " << zeroCount << std::endl;
        std::cout << "Dial 2: " << dial << std::endl;
        std::cout << "------------------------" << std::endl;
        
        // std::cout << "Press Enter to continue...";
        // std::cin.get();
    }

    std::cout << "The dial goes through zero " << zeroCount << " times." << std::endl;

    return 0;
}