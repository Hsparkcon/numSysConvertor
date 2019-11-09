#include "numSysConvertor.h"

int main() {
	int checker = NULL;
	bool inputChecker = false;
	numSysConvertor numConvertor;

	while (1) {

		do {
			inputChecker = numConvertor.inputReceiver();
		} while (!inputChecker);

		numConvertor.convertor();
		numConvertor.resultDisplay();
		numConvertor.dataReset();

		cout << "Press 0 to stop" << endl;
		cin >> checker;
		cout << endl;

		if (checker == 0) {
			break;
		}
	}
	
	system("PAUSE");

	return 0;
}