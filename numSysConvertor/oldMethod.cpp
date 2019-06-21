void numSysConvertor::decimalToNumSys() {
	int convertingVal = inputWhole;
	int targetingSys = numSys_Target;
	int numTocheck_cDegree = 0;
	int numTocheck_nDegree = 0;
	int currDegree = 0;

	while (1) {
		numTocheck_cDegree = pow(targetingSys, currDegree);
		numTocheck_nDegree = pow(targetingSys, currDegree + 1);


		if (convertingVal >= numTocheck_nDegree) {
			currDegree = currDegree + 1;
		}
		else if (convertingVal < numTocheck_cDegree) {
			currDegree = currDegree - 1;
			numList.push_back(0);
		}
		else if (convertingVal < numTocheck_nDegree && convertingVal >= (targetingSys - 1) * numTocheck_cDegree) {
			convertingVal = convertingVal - (targetingSys - 1) * numTocheck_cDegree;
			numList.push_back(targetingSys - 1);
			currDegree = currDegree - 1;
		}
		else {
			for (int i = targetingSys - 1; i > 0; i--) {
				if (convertingVal < i * numTocheck_cDegree && convertingVal >= (i - 1) * numTocheck_cDegree) {
					convertingVal = convertingVal - (i - 1) * numTocheck_cDegree;
					numList.push_back(i - 1);
					currDegree = currDegree - 1;
					break;
				}
			}
		}

		if (convertingVal < targetingSys && currDegree <= 0) {
			for (int i = targetingSys; i >= 0; i--) {
				if (convertingVal == i) {
					numList.push_back(i);
					break;
				}
			}
			break;
		}
	}
}

void numSysConvertor::convertorFDecimal() {

	float convertingVal = inputFraction;
	float tempResult = 0.0;
	float tempResult_Two = 0.0;
	int limit = 0;

	tempResult = 16 * convertingVal;

	do {
		cout << tempResult << endl;
		cout << (int)tempResult << endl;

		if (tempResult >= 1) {
			numList_Fraction.push_back(numTypeConvertor((int)tempResult));
			limit = limit + 1;
		}
		else {
			numList_Fraction.push_back(0);
			limit = limit + 1;
		}
		tempResult = fmod(tempResult, 1);
		tempResult = 16 * tempResult;

	} while (tempResult != 0 && limit < 8);

	for (auto i : numList_Fraction) {
		cout << i;
	}
	cout << endl;
