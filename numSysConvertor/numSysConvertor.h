#ifndef _NUMSYSCONVERTOR_H_
#define _NUMSYSCONVERTOR_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

class numSysConvertor {
public:
	numSysConvertor();
	~numSysConvertor();

	void inputReceiver();

	void convertor();

	void resultDisplay() const;
	

private:
	void inputIdentifier();
	void numSysIdentifier();

	char numTypeConvertor_IntToChar(int input);
	int  numTypeConvertor_CharToInt(char input);

	void convertorWDecimal();
	void convertorFDecimal();

	void dataReset();

	string	inputValue;

	vector<char> numList_Whole;
	vector<char> numList_Fraction;

	int		inputWhole;
	float	inputFraction;

	int		numSys_Original;
	int		numSys_Target;

	bool	displayALL;
};

#endif