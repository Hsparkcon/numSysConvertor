#include "numSysConvertor.h"

int main() {
	int checker = NULL;
	numSysConvertor numConvertor;
		
	while (1) {
		numConvertor.inputReceiver();
		numConvertor.convertor();

		cout << "Press 0 to stop" << endl;
		cin >> checker;
		cout << endl;

		if (checker == 0) {
			break;
		}
	}
	
	numConvertor.~numSysConvertor();

	system("PAUSE");

	return 0;
}