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
        std::cout << "Range " << i + 1 << ": " << ranges[i].first << " - " << ranges[i].second << std::endl;

        for (long long j = ranges[i].first; j <= ranges[i].second; j++) {
            int numDigits = std::to_string(j).length();

                if (numDigits % 2 == 1) {
                    continue;
                }

            std::string firstHalfNum = std::to_string(j).substr(0, numDigits / 2);
            std::string secondHalfNum = std::to_string(j).substr(numDigits / 2, numDigits);

            if (firstHalfNum == secondHalfNum) {
                std::cout << "Invalid code found: " << j << " (" << firstHalfNum << "|" << secondHalfNum << ")" << std::endl;
                invalidCount += j;
            }
        }
    }

	std::cout << "The total of invalid ids is " << invalidCount << std::endl;
	return 0;
}