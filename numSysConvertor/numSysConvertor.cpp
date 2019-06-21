#include "numSysConvertor.h"

numSysConvertor::numSysConvertor() {
	inputValue;
	numList_Whole;
	numList_Fraction;

	inputWhole = 0;
	inputFraction = 0;

	numSys_Original = 0;
	numSys_Target = 0;

	displayALL = false;
}

numSysConvertor::~numSysConvertor() {
	cout << "see you" << endl;
}

void numSysConvertor::inputReceiver() {

	cout << "Please enter a value" << endl;
	cin >> inputValue;

	cout << "Please enter numerical system of the Input" << endl;
	cin >> numSys_Original;

	cout << "Please enter targeting numerical system" << endl;
	cin >> numSys_Target;
	cout << endl;

	inputIdentifier();
	numSysIdentifier();
}

void numSysConvertor::inputIdentifier() {
	int currDegree = 0;
	double currVal = 0;
	double numMulti = 0;

	string numWhole;
	string numFraction;

	size_t floatingPoint = inputValue.find('.');

	if (floatingPoint != string::npos) {
		numWhole = inputValue.substr(0, floatingPoint);
		numFraction = inputValue.substr(floatingPoint + 1);

		cout << "Whole Number:	" << numWhole << endl;
		cout << "Fraction Number:	" << numFraction << endl;
		cout << endl;
	}
	else {
		numWhole = inputValue;
		cout << "Whole Number:	" << numWhole << endl;
		cout << endl;
	}

	while (!numWhole.empty()) {

		currVal = numTypeConvertor_CharToInt(numWhole.back());

		cout << "Input : " << numWhole.back() << endl;
		cout << "Return: " << currVal << endl;

		if (currVal > numSys_Original - 1) {
			cout << "Input mismatch:	" << currVal << endl;
		}
		
		numWhole.pop_back();

		numMulti = pow(numSys_Original, currDegree);
		inputWhole = inputWhole + currVal * numMulti;
		currDegree = currDegree + 1;
	}

	while (!numFraction.empty()) {

		currVal = numTypeConvertor_CharToInt(numFraction.back());

		if (currVal > numSys_Original - 1) {
			cout << "Input mismatch:	" << currVal << endl;
		}

		currDegree = numFraction.size();
		numMulti = pow(numSys_Original, -1 * currDegree);
		inputFraction = inputFraction + currVal * numMulti;

		numFraction.pop_back();
	}

}

void numSysConvertor::numSysIdentifier() {

	string inputCheck_Ori;
	string inputCheck_Tar;

	switch (numSys_Original) {
	case 2:
		inputCheck_Ori = "Binary";
		break;
	case 3:
		inputCheck_Ori = "Ternary";
		break;
	case 4:
		inputCheck_Ori = "Quaternary";
		break;
	case 5:
		inputCheck_Ori = "Quinary";
		break;
	case 6:
		inputCheck_Ori = "Senary";
		break;
	case 8:
		inputCheck_Ori = "Octal";
		break;
	case 10:
		inputCheck_Ori = "Decimal";
		break;
	case 12:
		inputCheck_Ori = "Duodecimal";
		break;
	case 16:
		inputCheck_Ori = "Hexadecimal";
		break;
	default:
		cout << "Incorrect Input is identified" << endl;
	}

	switch (numSys_Target) {
		case 0:
			inputCheck_Tar = "Display ALL";
			displayALL = true;
			break;
		case 2:
			inputCheck_Tar = "Binary";
			break;
		case 3:
			inputCheck_Tar = "Ternary";
			break;
		case 4:
			inputCheck_Tar = "Quaternary";
			break;
		case 5:
			inputCheck_Tar = "Quinary";
			break;
		case 6:
			inputCheck_Tar = "Senary";
			break;
		case 8:
			inputCheck_Tar = "Octal";
			break;
		case 10:
			inputCheck_Tar = "Decimal";
			break;
		case 12:
			inputCheck_Tar = "Duodecimal";
			break;
		case 16:
			inputCheck_Tar = "Hexadecimal";
			break;
		default:
			cout << "Incorrect Input is identified" << endl;
	}

	if (numSys_Original != numSys_Target) {
		cout << "Numerical System of Input :	" << inputCheck_Ori << endl;
		cout << "Numerical System of Target:	" << inputCheck_Tar << endl;
	}
	else {
		cout << "Error, conversion between same system cannot be performed" << endl;
	}
	cout << endl;
}

char numSysConvertor::numTypeConvertor_IntToChar(int input) {

	char indentifiedVal = NULL;

	switch (input) {
	case 0:
		indentifiedVal = '0';
		break;
	case 1:
		indentifiedVal = '1';
		break;
	case 2:
		indentifiedVal = '2';
		break;
	case 3:
		indentifiedVal = '3';
		break;
	case 4:
		indentifiedVal = '4';
		break;
	case 5:
		indentifiedVal = '5';
		break;
	case 6:
		indentifiedVal = '6';
		break;
	case 7:
		indentifiedVal = '7';
		break;
	case 8:
		indentifiedVal = '8';
		break;
	case 9:
		indentifiedVal = '9';
		break;
	case 10:
		indentifiedVal = 'A';
		break;
	case 11:
		indentifiedVal = 'B';
		break;
	case 12:
		indentifiedVal = 'C';
		break;
	case 13:
		indentifiedVal = 'D';
		break;
	case 14:
		indentifiedVal = 'E';
		break;
	case 15:
		indentifiedVal = 'F';
		break;
	default:
		cout << "Unexpected Input detected :	" << input << endl;
	}

	return indentifiedVal;

}

int numSysConvertor::numTypeConvertor_CharToInt(char input) {

	int indentifiedVal = NULL;

	switch (input) {
	case '0':
		indentifiedVal = 0;
		break;
	case '1':
		indentifiedVal = 1;
		break;
	case '2':
		indentifiedVal = 2;
		break;
	case '3':
		indentifiedVal = 3;
		break;
	case '4':
		indentifiedVal = 4;
		break;
	case '5':
		indentifiedVal = 5;
		break;
	case '6':
		indentifiedVal = 6;
		break;
	case '7':
		indentifiedVal = 7;
		break;
	case '8':
		indentifiedVal = 8;
		break;
	case '9':
		indentifiedVal = 9;
		break;
	case 'a':
		indentifiedVal = 10;
		break;
	case 'b':
		indentifiedVal = 11;
		break;
	case 'c':
		indentifiedVal = 12;
		break;
	case 'd':
		indentifiedVal = 13;
		break;
	case 'e':
		indentifiedVal = 14;
		break;
	case 'f':
		indentifiedVal = 15;
		break;
	case 'A':
		indentifiedVal = 10;
		break;
	case 'B':
		indentifiedVal = 11;
		break;
	case 'C':
		indentifiedVal = 12;
		break;
	case 'D':
		indentifiedVal = 13;
		break;
	case 'E':
		indentifiedVal = 14;
		break;
	case 'F':
		indentifiedVal = 15;
		break;
	default:
		cout << "Unexpected Input detected :	" << indentifiedVal << endl;
	}

	return indentifiedVal;

}

void numSysConvertor::convertor() {
	if (displayALL == false) {
		convertorWDecimal();
		convertorFDecimal();
		resultDisplay();
		dataReset();
	}
	else {
		int numSysToDisplay[9] = { 2, 3, 4, 5, 6, 8, 10, 12, 16};

		for (int i = 0; i < 9; i++) {
			numSys_Target = numSysToDisplay[i];
			convertorWDecimal();
			convertorFDecimal();
			resultDisplay();

			numList_Whole.clear();
			numList_Fraction.clear();
		}
		dataReset();
	}
}

void numSysConvertor::convertorWDecimal() {
	int convertingVal		= inputWhole;
	int targetingSys		= numSys_Target;
	int numTocheck_cDegree	= 0;
	int numTocheck_nDegree	= 0;
	int currDegree			= 0;

	vector<int>tempResult;
	int tempRemainder;
	char indentifiedVal;

	while (convertingVal != 0) {
		tempRemainder = convertingVal % targetingSys;
		convertingVal = convertingVal / targetingSys;
		tempResult.push_back(tempRemainder);
	}

	while (!tempResult.empty()){

		switch (tempResult.back()) {
		case 0:
			indentifiedVal = '0';
			break;
		case 1:
			indentifiedVal = '1';
			break;
		case 2:
			indentifiedVal = '2';
			break;
		case 3:
			indentifiedVal = '3';
			break;
		case 4:
			indentifiedVal = '4';
			break;
		case 5:
			indentifiedVal = '5';
			break;
		case 6:
			indentifiedVal = '6';
			break;
		case 7:
			indentifiedVal = '7';
			break;
		case 8:
			indentifiedVal = '8';
			break;
		case 9:
			indentifiedVal = '9';
			break;
		case 10:
			indentifiedVal = 'A';
			break;
		case 11:
			indentifiedVal = 'B';
			break;
		case 12:
			indentifiedVal = 'C';
			break;
		case 13:
			indentifiedVal = 'D';
			break;
		case 14:
			indentifiedVal = 'E';
			break;
		case 15:
			indentifiedVal = 'F';
			break;
		default:
			cout << "Unexpected Input detected :	" << tempResult.back() << endl;
		}

		numList_Whole.push_back(indentifiedVal);
		tempResult.pop_back();
	}

}

void numSysConvertor::convertorFDecimal() {
	float convertingVal = numSys_Target * inputFraction;
	int limit = 0;

	while (convertingVal > 0 && limit < 8) {
		numList_Fraction.push_back(numTypeConvertor_IntToChar((int)convertingVal));

		limit = limit + 1;

		convertingVal = fmod(convertingVal, 1);
		convertingVal = numSys_Target * convertingVal;
	}
}

void numSysConvertor::resultDisplay() const {
	cout << "Input :	" << inputValue << endl;

	cout << "Result:	";
	if (!numList_Whole.empty()) {
		for (auto i : numList_Whole) {
			cout << i;
		}
	}

	if (!numList_Fraction.empty()) {
		cout << '.';
		for (auto i : numList_Fraction) {
			cout << i;
		}
	}
	cout << endl;
	cout << endl;
}

void numSysConvertor::dataReset() {
	inputValue.clear();
	numList_Whole.clear();
	numList_Fraction.clear();
	displayALL = false;

	
	inputWhole = 0;
	inputFraction = 0;
	numSys_Original = 0;
	numSys_Target = 0;
}