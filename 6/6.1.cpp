/* Algorithm:
* 1) declaring necessary variables "number", "mask" (initialised with 1 (00000001)), "result" (for storing the value obtained after the operations);
* 2) declaring the necessary char arrays "Number" (for storing the binary code of the * entered number) and "Result" (for storing the binary code of the changed number);
* 3) asking a user to assign the value to a variable "number";
* 4) while a user keeps entering value, which is equal to zero or negative, he is asked * to do it again with corresponding message;
* 5) putting the value of a variable "number" in a CX register, copy it to the BX         * register with "mov";
* 6) searching for the eleventh bit of the number; if it equals to one, initialising BX    * register with the number, which bits were shifted right for 11 positions;
* 7) if value stored in the BX register is >= to 1, it becomes 1, else it is equal to zero;
* 8) putting the value stored in a BX register in a variable "result";
* 9) outputting the result of the program: initial number, its binary code, its value obtained after operations, its binary code (either 00000001 or 00000000).
*/
#include <iostream>

using namespace std;

int main(void)
{
	short number;
	short mask = 1;
	short result = 0;
	char Number[255] = "";
	char Result[255] = "";
	
	cout << "Enter the number: ";
	cin >> number;
	
	while (number <= 0) {
		cout << "You entered the number wrong (it should be a positive one). Consider reentering." << endl;
		cout << "Enter the number: ";
		cin >> number;
	}
	
	__asm {
		
		mov CX, number;
		mov BX, CX;
		sar BX, 11;
		and BX, mask;	
		mov result, BX;
	}

	_itoa_s(number, Number, 2);
	printf("Initial number:   %d In binary: \t%016s;\n", number, Number);
	_itoa_s(result, Result, 2);
	printf("Operation result:%4d  In binary: \t%016s.\n", result, Result);
	
	return 0;
}
