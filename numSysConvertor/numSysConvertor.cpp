#include "numSysConvertor.h"

numSysConvertor::numSysConvertor() {

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
		{2, {"Binary", "0"}},
		{3, {"Ternary", "0"}},
		{4, {"Quaternary", "0"}},
		{5, {"Quinary", "0"}},
		{6, {"Senary", "0"}},
		{8, {"Octal", "0"}},
		{10,{"Decimal", "0"}},
		{12, {"Duodecimal", "0"}},
		{16, {"Hexadecimal", "0"}}
	};	
	
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

bool numSysConvertor::inputReceiver() {

	cout << "Please enter a value" << endl;
	cin >> inputValue;

	cout << "Please enter numerical system of the Input" << endl;
	cin >> numSys_Original;

	cout << "Please enter targeting numerical system" << endl;
	cin >> numSys_Target;
	cout << endl;

	if (!numSysIdentifier(numSys_Original, numSys_Target)) {
		std::cout << "Please check entered numeric system." << std::endl;
		return false;
	}

	if (!valueIdentifier()) {
		std::cout << "Please check the entered value to be converted." << std::endl;
		return false;
	}

	return true;

}

bool numSysConvertor::valueIdentifier() {
	int currDegree = 0;
	double currVal = 0;
	double numMulti = 0;

	string numWhole;
	string numFraction;
	size_t floatingPoint = inputValue.find('.');

	if (floatingPoint != string::npos) {
		numWhole = inputValue.substr(0, floatingPoint);
		numFraction = inputValue.substr(floatingPoint + 1);

		//cout << "Whole Number:    " << numWhole << endl;
		//cout << "Fraction Number: " << numFraction << endl;
		//cout << endl;

	}
	else {
		numWhole = inputValue;
		
		//cout << "Whole Number:	" << numWhole << endl;
		//cout << endl;

	}

	while (!numWhole.empty()) {

		currVal = numTypeConvertor_CharToInt(numWhole.back());

		if (static_cast<int>(currVal) == -1) {	return false;	}
		
		numWhole.pop_back();

		numMulti = pow(numSys_Original, currDegree);
		inputWhole = inputWhole + currVal * numMulti;
		currDegree = currDegree + 1;

	}

	while (!numFraction.empty()) {

		currVal = numTypeConvertor_CharToInt(numFraction.back());

		if (static_cast<int>(currVal) == -1) {	return false;	}

		currDegree = numFraction.size();
		numMulti = pow(numSys_Original, -1 * currDegree);
		inputFraction = inputFraction + currVal * numMulti;

		numFraction.pop_back();
	}

	return true;
}

bool numSysConvertor::numSysIdentifier(int originalSys, int targetedSys) {
	if (originalSys == targetedSys) {
		std::cout << "numeric system of entered value is same as targeted system." << std::endl;
		return false;
	}

	switch (originalSys) {
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 8:
		break;
	case 10:
		break;
	case 12:
		break;
	case 16:
		break;
	default:
		std::cout << "ERROR in entered numeric system of original value." << std::endl;
		return false;
	}

	switch (targetedSys) {
	case 0:
		displayALL = true;
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 8:
		break;
	case 10:
		break;
	case 12:
		break;
	case 16:
		break;
	default:
		std::cout << "ERROR in entered targeted numeric system." << std::endl;
		return false;
	}

	return true;

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
	auto itMap = MatchList_CharToInt.find(input);

	if (itMap != MatchList_CharToInt.end()) {

		if (itMap->second > numSys_Original - static_cast<int>(1)) {
			cout 
				<< "Error in input value - " 
				<< input 
				<< " cannot be appeared in " 
				<< resultList.find(numSys_Original)->second[0]
				<< std::endl;

			return -1;
		}
			   
	}
	return itMap->second;
}

void numSysConvertor::convertor() {

	if (displayALL == false) {
		convertorWDecimal();
		convertorFDecimal();

		outputValue = numList_Whole.empty() ? "0" : numList_Whole;

		if (!numList_Fraction.empty()) {
			outputValue = outputValue + '.' + numList_Fraction;
		}

		resultList[numSys_Target][1] = outputValue;

	} else {

		int numSysToDisplay[9] = { 2, 3, 4, 5, 6, 8, 10, 12, 16};

		for (int i = 0; i < 9; i++) {
			numSys_Target = numSysToDisplay[i];
			convertorWDecimal();
			convertorFDecimal();

			outputValue = numList_Whole.empty() ? "0" : numList_Whole;

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
		numList_Fraction.push_back(numTypeConvertor_IntToChar(static_cast<int>(convertingVal)));

		limit = limit + 1;

		convertingVal = fmod(convertingVal, 1);
		convertingVal = numSys_Target * convertingVal;
	}
}

void numSysConvertor::resultDisplay() const {
	cout << "Input :	" << inputValue << "	" << resultList.find(numSys_Original)->second[0] << endl;
	cout << "result :	" << endl;


	if (displayALL) {
		for (auto i : resultList) {
			cout.width(11);
			cout << left <<  i.second[0] << " : " << i.second[1] << endl;
		}
		cout << endl;
	}
	else {
		auto iter = resultList.find(numSys_Target);
		cout.width(11);
		cout << left << iter->second[0] << " : " << iter->second[1] << endl;
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