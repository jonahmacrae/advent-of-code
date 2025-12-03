#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

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
    int pointAtZeroCount = 0;
    
    for (int i = 0; i < moves.size(); i++) {
        if (moves[i].first == 'L') {
            dial -= moves[i].second;
            std::cout << "Dial: " << dial << std::endl;
        } else {
            dial += moves[i].second;
            std::cout << "Dial: " << dial << std::endl;
        }

        dial %= 100;

        if (dial == 0) {
            pointAtZeroCount++;
        }
    }

    std::cout << "The dial points at zero " << pointAtZeroCount << " times." << std::endl;

    return 0;
}