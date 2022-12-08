/*The purpose of this program is to find the duplicate item(char) in each
* set and give it a value then tally all of the duplicate items.
* 
Problem can be found at: https://adventofcode.com/2022/day/4 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int * parseInput(string input) {
	string parsed, token, Sx1, Sx2, Sy1, Sy2;
	stringstream input_stringstream(input);
	char dash = '-';
	int found;
	int static results[4];
	

	if (getline(input_stringstream, parsed, ',')) {
		token = input.substr(1 + parsed.length(), input.length());
	}


	found = parsed.find(dash);
	if (found != string::npos) {
		Sx1 = parsed.substr(0, found);
		Sy1 = parsed.substr(1 + found, parsed.length());
	}
	found = token.find(dash);
	if (found != string::npos) {
		Sx2 = token.substr(0, found);
		Sy2 = token.substr(1 + found, token.length());
	}

	results[0] = stoi(Sx1);
	results[1] = stoi(Sy1);
	results[2] = stoi(Sx2);
	results[3] = stoi(Sy2);

	return results;
}

int checkOverlap(int *numberRanges) {

	int x1, x2, y1, y2;
	x1 = numberRanges[0];
	y1 = numberRanges[1];
	x2 = numberRanges[2];
	y2 = numberRanges[3];

	if ((y1 >= x2) && (x1<=y2)) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {

	ifstream sections("section_assignments.txt");
	string input;
	int* numberRanges;
	int overlaps = 0;

	if (sections.good()) {
		while (getline(sections, input)) {
			numberRanges = parseInput(input);
			overlaps += checkOverlap(numberRanges);
		}
		cout << overlaps;
	}

	return 0;
}