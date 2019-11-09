#ifndef _NUMSYSCONVERTOR_H_
#define _NUMSYSCONVERTOR_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

class numSysConvertor {

public:
	numSysConvertor();
	~numSysConvertor();

	bool inputReceiver();
	void convertor();
	void resultDisplay() const;	
	void dataReset();

private:
	bool valueIdentifier();
	bool numSysIdentifier(int orginalSys, int targetedSys);

	char numTypeConvertor_IntToChar(int input);
	int  numTypeConvertor_CharToInt(char input);

	void convertorWDecimal();
	void convertorFDecimal();



	string inputValue;
	string outputValue;
	string numList_Whole;
	string numList_Fraction;

	map<int, vector<string>> resultList;
	map<int, char> MatchList_IntToChar;
	map<char, int> MatchList_CharToInt;

	int		inputWhole;
	float	inputFraction;

	int		numSys_Original;
	int		numSys_Target;

	bool	displayALL;
};

#endif