/*Problem can be found at: https://adventofcode.com/2022/day/5 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void moveCrate(int num, vector <char> &fromStack, vector <char> &toStack) {
	
	/*
		for (size_t i = 0; i < num; i++) {
		toStack.push_back(fromStack.back());
		fromStack.pop_back();
	}
	*/

	size_t size = fromStack.size();

	for (size_t i = num; i > 0; i--) {
		toStack.push_back(fromStack[size - i]);
	}
	for (size_t i = 0; i < num; i++) {
		fromStack.pop_back();
	}
}

int main() {

	ifstream crateFile("crate_stacks.txt");
	string input, blank;
	const int numStacks = 9;
	vector <char> stacks[numStacks];
	size_t num, from, to;
	
	if (crateFile.good()) {
		while (getline(crateFile, input)) {
			if (input.substr(1,1) == "1") break; //when we hit 1, we are done inputting data based on the text file given
			for (size_t i = 0; i < numStacks; i++) {
				if (input.substr(4 * i + 1, 1) == " ") continue;
				stacks[i].push_back(input[4 * i + 1]);
			}
		}
		
		// reverse the order of each vector so it is ordered top to bottom as if standing on its side
		for (size_t i = 0; i < numStacks; i++) {
			reverse(stacks[i].begin(), stacks[i].end());
		}

		while (crateFile >> blank >> num >> blank >> from >> blank >> to) {
			moveCrate(num, stacks[from - 1], stacks[to - 1]);
		}

		for (size_t i = 0; i < numStacks; i++) {
			cout << stacks[i].back();
		}
		cout << endl;
	}

	return 0;
}