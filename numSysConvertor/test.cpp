#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {

	int currDegree = 0;
	int targetingSys = 8;
	double currVal = 0;
	double valDecimal = 0;
	double numMulti = 0;

	string inputNum;
	cin >> inputNum;

	string numWhole;
	string numFraction;
	
	size_t floatingPoint = inputNum.find('.');

	if (floatingPoint != string::npos) {
		numWhole = inputNum.substr(0, floatingPoint);
		numFraction = inputNum.substr(floatingPoint + 1);
		
		cout << numWhole << endl;
		cout << numFraction << endl;
	}
	else {
		numWhole = inputNum;
	}

	while (!numWhole.empty()) {

		switch (numWhole.back()) {
			case '0':
				currVal = 0;
				break;
			case '1':
				currVal = 1;
				break;
			case '2':
				currVal = 2;
				break;
			case '3':
				currVal = 3;
				break;
			case '4':
				currVal = 4;
				break;
			case '5':
				currVal = 5;
				break;
			case '6':
				currVal = 6;
				break;
			case '7':
				currVal = 7;
				break;
			case '8':
				currVal = 8;
				break;
			case '9':
				currVal = 9;
				break;
			case 'a':
				currVal = 10;
				break;
			case 'b':
				currVal = 11;
				break;
			case 'c':
				currVal = 12;
				break;
			case 'd':
				currVal = 13;
				break;
			case 'e':
				currVal = 14;
				break;
			case 'f':
				currVal = 15;
				break;
			case 'A':
				currVal = 10;
				break;
			case 'B':
				currVal = 11;
				break;
			case 'C':
				currVal = 12;
				break;
			case 'D':
				currVal = 13;
				break;
			case 'E':
				currVal = 14;
				break;
			case 'F':
				currVal = 15;
				break;		
			default:
				cout << "Unexpected Input detected :	" << numWhole.back() << endl;
		}

		if (currVal > targetingSys) {
			cout << "Input mismatch:	" << numWhole.back() << endl;
		}


		numWhole.pop_back();

		numMulti = pow(targetingSys, currDegree);
		valDecimal = valDecimal + currVal * numMulti;
		currDegree = currDegree + 1;
	}

	while (!numFraction.empty()) {

		switch (numFraction.back()) {
		case '0':
			currVal = 0;
			break;
		case '1':
			currVal = 1;
			break;
		case '2':
			currVal = 2;
			break;
		case '3':
			currVal = 3;
			break;
		case '4':
			currVal = 4;
			break;
		case '5':
			currVal = 5;
			break;
		case '6':
			currVal = 6;
			break;
		case '7':
			currVal = 7;
			break;
		case '8':
			currVal = 8;
			break;
		case '9':
			currVal = 9;
			break;
		case 'a':
			currVal = 10;
			break;
		case 'b':
			currVal = 11;
			break;
		case 'c':
			currVal = 12;
			break;
		case 'd':
			currVal = 13;
			break;
		case 'e':
			currVal = 14;
			break;
		case 'f':
			currVal = 15;
			break;
		case 'A':
			currVal = 10;
			break;
		case 'B':
			currVal = 11;
			break;
		case 'C':
			currVal = 12;
			break;
		case 'D':
			currVal = 13;
			break;
		case 'E':
			currVal = 14;
			break;
		case 'F':
			currVal = 15;
			break;
		default:
			cout << "Unexpected Input detected :	" << numFraction.back() << endl;
		}

		if (currVal > targetingSys) {
			cout << "Input mismatch:	" << numFraction.back() << endl;
		}

		currDegree = numFraction.size();
		numMulti = pow(targetingSys, -1 * currDegree);
		valDecimal = valDecimal + currVal * numMulti;

		numFraction.pop_back();
	}

	cout << valDecimal << endl;
	
	system("PAUSE");
	return 0;
}