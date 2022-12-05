/*The purpose of this program is to find the duplicate item(char) in each
* set and give it a value then tally all of the duplicate items.
* 
Problem can be found at: https://adventofcode.com/2022/day/3 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//compare the three strings to find the common character found in all of them
char determineDuplicate(string bag1, string bag2, string bag3) {
	vector<char> compartment1 = {};
	vector<char> compartment2 = {};
	vector<char> compartment3 = {};
	vector<char> tempVector = {};
	int count;
	char duplicate;

	//put the strings in to vectors in order to manipulate them better
	for (count = 0; count < bag1.length(); count++) {
		compartment1.push_back(bag1.at(count));
	}
	for (count = 0; count < bag2.length(); count++) {
		compartment2.push_back(bag2.at(count));
	}
	for (count = 0; count < bag3.length(); count++) {
		compartment3.push_back(bag3.at(count));
	}
	
	//compare the first two vectors and input it in to a tempVector
	for (count = 0; count < bag1.size(); count++) {
		for (int x = 0; x < bag2.size(); x++) {
			if (bag1.at(count) == bag2.at(x)) {
				tempVector.push_back(bag1.at(count));
			}
		}
	}
	//compare the tempVector with the thrid to find the common character between all 3 vectors
	for (count = 0; count < tempVector.size(); count++) {
		for (int y = 0; y < bag3.size(); y++) {
			if (tempVector.at(count) == bag3.at(y)) {
				duplicate = tempVector.at(count);
			}
		}
	}

	return duplicate;
}

//assign a value based on the character
int determineValue(char duplicate) {
	int value, count;
	char lowerCase[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	char upperCase[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };

	if (islower(duplicate)) {
		for (count = 0; count < sizeof(lowerCase) / sizeof(lowerCase[0]); count++) {
			if (duplicate == lowerCase[count]) {
				value = count + 1;
			}
		}
	}
	else if (isupper(duplicate)) {
		for (count = 0; count < sizeof(upperCase) / sizeof(upperCase[0]); count++) {
			if (duplicate == upperCase[count]) {
				value = count + 27;
			}
		}
	}

	return value;
}
int main() {

	ifstream rucksack("rucksack_contents.txt");
	string line, bag1, bag2, bag3;
	char duplicate;
	int value = 0;

	if (rucksack.good()){
		do {
			//grab 3 lines at a time
			for (int x = 1; x <= 3; x++) {
				getline(rucksack, line);
				switch (x) {
					case 1: {
						bag1 = line;
						break;
					}
					case 2: {
						bag2 = line;
						break;
					}
					case 3: {
						bag3 = line;
						break;
					}
				}
			}
			duplicate = determineDuplicate(bag1, bag2, bag3);
			value += determineValue(duplicate);
		} while (!rucksack.eof());
	}
	cout << value;

	return 0;
}