#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

int main(){
	std::cout << "Welcome to the lobby!" << std::endl;

	std::ifstream file("input.txt");
	std::vector<std::string> batteryPacks;
	std::string batteryPack;
		
	while (std::getline(file, batteryPack)) {
		batteryPacks.push_back(batteryPack);
	}
	file.close();

  int totalJoltage = 0;

  for (int i = 0; i < batteryPacks.size(); ++i) {
    std::cout << "Battery Pack " << i + 1 << ": " << batteryPacks[i] << std::endl;

    int maxJoltage = -1;
    int maxJoltageIndex = -1;
    
    int secondMaxJoltage = -1;
    int secondMaxJoltageIndex = -1;

    for (int j = 0; j < batteryPacks[i].size(); ++j) {
      if (batteryPacks[i][j] - '0' > maxJoltage && j < batteryPacks[i].size() - 1) {
        maxJoltage = batteryPacks[i][j] - '0';
        maxJoltageIndex = j;
        secondMaxJoltage = 0;
        secondMaxJoltageIndex = 0;
      }

      if (batteryPacks[i][j] - '0' > secondMaxJoltage && j > maxJoltageIndex) {
        secondMaxJoltage = batteryPacks[i][j] - '0';
        secondMaxJoltageIndex = j;
      }
    }

    std::cout << "Max Joltage: " << maxJoltage * 10 + secondMaxJoltage << std::endl;
    totalJoltage += maxJoltage * 10 + secondMaxJoltage;
  }

  std::cout << "Total Joltage: " << totalJoltage << std::endl;

	return 0;
}