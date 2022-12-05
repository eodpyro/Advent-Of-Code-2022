/*The purpose of this project is to determine the total score
after several rock papaer scissors rounds while following a certain
strategy as laid out in the text document.

Points: rock		= 1	(A)
		paper		= 2	(B)
		scissors	= 3	(C)
		loss		= 0	(X)
		draw		= 3	(Y)
		win			= 6	(Z)

Problem can be found at: https://adventofcode.com/2022/day/2 */

#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int determinewinner(char opponent, char self) {
	
	int tempScore = 0;

	if (opponent == 'A') {
		switch (self) {
		case 'Y':
			cout << "Your rock and their rock draw. 3 points for draw and 1 point for picking rock.";
			tempScore = 4;
			break;
		case 'Z':
			cout << "Your paper beats their rock. 6 points for winning and 2 points for picking paper.";
			tempScore = 8;
			break;
		case 'X':
			cout << "Your scissors loses to their rock. 0 points for losing and 3 points for picking scissors.";
			tempScore = 3;
			break;
		default:
			cout << "Error in A";
		}
	}
	if (opponent == 'B') {
		switch (self) {
		case 'X':
			cout << "Your rock loses to their paper. 0 points for losing and 1 point for picking rock.";
			tempScore = 1;
			break;
		case 'Y':
			cout << "Your paper and their paper draw. 3 points for drawing and 2 points for picking paper.";
			tempScore = 5;
			break;
		case 'Z':
			cout << "Your scissors beats their paper. 6 points for winning and 3 points for picking paper.";
			tempScore = 9;
			break;
		default:
			cout << "Error in B";
		}
	}
	if (opponent == 'C') {
		switch (self) {
		case 'Z':
			cout << "Your rock beats their scissors. 6 points for winning and  1 point for picking rock.";
			tempScore = 7;
			break;
		case 'X':
			cout << "Your paper loses to their scissors. 0 points for losing and 2 points for picking paper.";
			tempScore = 2;
			break;
		case 'Y':
			cout << "Your scissors and their scissors draw. 3 points for drawing and 3 points for picking scissors.";
			tempScore = 6;
			break;
		default:
			cout << "Error in C";
		}
	}
	return tempScore;
}

int main() {

	ifstream RPSfile("rock_paper_scissors_strat.txt");
	string input;
	int score = 0;
	char opponent, self;

	if (RPSfile.is_open()) {

		cout << "open";
		while (getline(RPSfile, input)) {
			for (int x = 0; x < input.length(); ++x) {
				if (x == 0) {
					opponent = input.at(x);
					cout << opponent << " ";
				}
				if (x == 2) {
					self = input.at(x);
					cout << self;
				}
			}
			score += determinewinner(opponent, self);
			cout << "\n";
		}
	}
	else {
		cout << "not open";
	}
	cout << score;

	return 0;
}