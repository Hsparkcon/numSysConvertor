#include "numSysConvertor.h"

numSysConvertor::numSysConvertor() {

	inputValue;

	MatchList_IntToChar = {
		{0, '0'},
		{1, '1'},
		{2, '2'},
		{3, '3'},
		{4, '4'},
		{5, '5'},
		{6, '6'},
		{7, '7'},
		{8, '8'},
		{9, '9'},
		{10, 'A'},
		{11, 'B'},
		{12, 'C'},
		{13, 'D'},
		{14, 'E'},
		{15, 'F'}
	};

	MatchList_CharToInt = {
		{'0', 0},
		{'1', 1},
		{'2', 2},
		{'3', 3},
		{'4', 4},
		{'5', 5},
		{'6', 6},
		{'7', 7},
		{'8', 8},
		{'9', 9},
		{'a', 10},
		{'b', 11},
		{'c', 12},
		{'d', 13},
		{'e', 14},
		{'f', 15},
		{'A', 10},
		{'B', 11},
		{'C', 12},
		{'D', 13},
		{'E', 14},
		{'F', 15}
	};

	resultList = {
		{2,  {"Binary:       ", "0"}},
		{3,  {"Ternary:      ", "0"}},
		{4,  {"Quaternary:   ", "0"}},
		{5,  {"Quinary:      ", "0"}},
		{6,  {"Senary:       ", "0"}},
		{8,  {"Octal:        ", "0"}},
		{10, {"Decimal:      ", "0"}},
		{12, {"Duodecimal:   ", "0"}},
		{16, {"Hexadecimal:  ", "0"}}
	};	
	
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
	int currVal = 0;
	int numMulti = 0;

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

		if (currVal > numSys_Original - static_cast<int>(1)) {
			cout << "Input mismatch:	" << currVal << endl;
		}
		
		numWhole.pop_back();

		numMulti = pow(numSys_Original, currDegree);
		inputWhole = inputWhole + currVal * numMulti;
		currDegree = currDegree + 1;

	}

	while (!numFraction.empty()) {

		currVal = numTypeConvertor_CharToInt(numFraction.back());

		if (currVal > numSys_Original - static_cast<int>(1)) {
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
	map<int, char>::iterator itMap;

	itMap = MatchList_IntToChar.find(input);

	if (itMap != MatchList_IntToChar.end()) {
		indentifiedVal = itMap->second;
	}
	else {
		cout << "Unexpected Input detected :	" << input << endl;
	}

	return indentifiedVal;
}

int numSysConvertor::numTypeConvertor_CharToInt(char input) {
	int indentifiedVal = NULL;
	map<char, int>::iterator itMap;

	itMap = MatchList_CharToInt.find(input);

	if (itMap != MatchList_CharToInt.end()) {
		indentifiedVal = itMap->second;
	}
	else {
		cout << "Unexpected Input detected :	" << input << endl;
	}

	return indentifiedVal;

}

void numSysConvertor::convertor() {
	if (displayALL == false) {
		convertorWDecimal();
		convertorFDecimal();

		if (!numList_Whole.empty()) {
			outputValue = numList_Whole;
		}
		else {
			outputValue = '0';
		}

		if (!numList_Fraction.empty()) {
			outputValue = outputValue + '.' + numList_Fraction;
		}

		resultList[numSys_Target][1] = outputValue;

	}
	else {
		int numSysToDisplay[9] = { 2, 3, 4, 5, 6, 8, 10, 12, 16};

		for (int i = 0; i < 9; i++) {
			numSys_Target = numSysToDisplay[i];
			convertorWDecimal();
			convertorFDecimal();

			if (!numList_Whole.empty()) {
				outputValue = numList_Whole;
			}
			else {
				outputValue = '0';
			}

			if (!numList_Fraction.empty()) {
				outputValue = outputValue + '.' + numList_Fraction;
			}

			resultList[numSys_Target][1] = outputValue;

			numList_Whole.clear();
			numList_Fraction.clear();
		}
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

	map<int, char>::iterator itMap;

	while (convertingVal != 0) {
		tempRemainder = convertingVal % targetingSys;
		convertingVal = convertingVal / targetingSys;
		tempResult.push_back(tempRemainder);
	}

	while (!tempResult.empty()){

		itMap = MatchList_IntToChar.find(tempResult.back());

		if (itMap != MatchList_IntToChar.end()) {
			indentifiedVal = itMap->second;
		}
		else {
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
	cout << "Input :	" << inputValue << "	" << numSys_Original << endl;
	cout << "result :	" << endl;


	if (displayALL) {
		for (auto i : resultList) {
			cout << i.second[0] << i.second[1] << endl;
		}
		cout << endl;
	}
	else {
		auto iter = resultList.find(numSys_Target);
		cout << iter->second[0] << iter->second[1] << endl;
	}
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