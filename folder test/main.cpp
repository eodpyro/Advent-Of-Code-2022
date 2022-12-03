/*The purpose of this code is to determine which elf has the highest
amount of calories carried. Problem can be found at:

https://adventofcode.com/2022/day/1
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	ifstream calorieFile("elf_calorie_list.txt");
	string inputString;
	int sum = 0;
	vector<int> elves;

	if (calorieFile.is_open()) {

		while (getline(calorieFile, inputString)) {

			if (!inputString.empty()) {
				sum += stoi(inputString, NULL);
			}
			else {
				elves.push_back(sum);
				sum = 0;
			}
		}

		sort(elves.begin(), elves.end(), greater<int>());

		sum = 0;
		for (int i = 0; i < 3; i++) {
			 sum += elves.at(i);
		}

		cout << sum << " calories.";
	}
	else {
		cout << "did not open";
	}

	return 0;
}