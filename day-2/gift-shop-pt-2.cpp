#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

int main(){
	std::cout << "Welcome to the gift shop!" << std::endl;

	std::ifstream file("input.txt");
	std::vector<std::pair<long long, long long>> ranges;
	std::string range;
		
	while (std::getline(file, range, ',')) {
		int dashPos = range.find('-');
		long long lb = std::stoll(range.substr(0, dashPos)); // lower bound
		long long ub = std::stoll(range.substr(dashPos + 1));  // upper bound
		ranges.push_back({lb, ub});
	}
	file.close();

	// To access lower bound, use ranges[i].first
	// To access upper bound, use ranges[i].second

	long long invalidCount = 0;

    for (int i = 0; i < ranges.size(); i++) {
        for (long long j = ranges[i].first; j <= ranges[i].second; j++) {
            
        }
    }

	std::cout << "The total of invalid ids is " << invalidCount << std::endl;
	return 0;
}