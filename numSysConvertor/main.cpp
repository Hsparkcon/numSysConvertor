#include "numSysConvertor.h"

int main() {
	int checker = NULL;
	numSysConvertor numConvertor;

	while (1) {
		numConvertor.inputReceiver();
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