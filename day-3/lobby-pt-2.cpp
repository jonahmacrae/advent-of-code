#include <cmath>
#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

int main(){
  const int SELECTED_BATTERY_PACK_SIZE = 12;

	std::ifstream file("input.txt");
	std::vector<std::string> batteryPacks;
	std::string batteryPack;
		
	while (std::getline(file, batteryPack)) {
		batteryPacks.push_back(batteryPack);
	}

	file.close();

  long long totalJoltage = 0;

  // Loops through each battery pack
  for (int batteryPackIndex = 0; batteryPackIndex < batteryPacks.size(); ++batteryPackIndex) {
    std::stack<int> selectedBatteriesStack;
    std::cout << "Battery Pack " << batteryPackIndex + 1 << ": " << batteryPacks[batteryPackIndex] << std::endl;

    // Loops through each battery in the pack
    for (int batteryIndex = 0; batteryIndex < batteryPacks[batteryPackIndex].size(); ++batteryIndex) {
      int currentBattery = batteryPacks[batteryPackIndex][batteryIndex] - '0';

      while (!selectedBatteriesStack.empty() && currentBattery > selectedBatteriesStack.top() && (selectedBatteriesStack.size() - 1) + (batteryPacks[batteryPackIndex].size() - batteryIndex) >= SELECTED_BATTERY_PACK_SIZE) {
        selectedBatteriesStack.pop();
      }

      selectedBatteriesStack.push(currentBattery);

      while (selectedBatteriesStack.size() > SELECTED_BATTERY_PACK_SIZE) {
        selectedBatteriesStack.pop();
      }
    }

    long long batteryPackJoltage = 0;
    long long mult = 1;

    while (!selectedBatteriesStack.empty()) {
      batteryPackJoltage += mult * selectedBatteriesStack.top();
      selectedBatteriesStack.pop();

      mult *= 10;
    }

    std::cout << "  Selected Batteries Joltage: " << batteryPackJoltage << std::endl;
    totalJoltage += batteryPackJoltage;
  }

  std::cout << "Total Joltage: " << totalJoltage << std::endl;

	return 0;
}