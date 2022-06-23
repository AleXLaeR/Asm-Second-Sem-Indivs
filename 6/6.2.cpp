/* Algorithm:
* 1) declaring necessary variables "number", "result" (for storing the value obtained after the operations);
* 2) declaring the necessary char arrays "Number" (for storing the binary code of the entered number) and "Result" (for storing the binary code of the changed number);
* 3) asking a user to assign the value to a variable "number";
* 4) while a user keeps entering value, which is equal to zero or negative, he is asked to do it again with corresponding message;
* 5) putting the value of a variable "number" in a ECX register, copy it to the EAX register with "mov";
* 6) shifting left bits of the number stored in EAX register for (max register bit number (31) - the far right of the given field (23));
* 7) shifting right bits of the number stored in EAX register for (the far right of the given field (13) - (max register bit number (31) - the far right of the given field (23)));
* 8) putting the value stored in a EAX register in a variable "result";
* 9) outputting the result of the program: initial number, its binary code, its value obtained after operations, its binary code.
*/
#include <iostream>

using namespace std;

int main(void) {
	
	int number;
	int result = 0;
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
		
		mov ECX, number;
		mov EAX, ECX;
		shl EAX, 31 - 23;
		shr EAX, 13 + (31 - 23);
		mov result, EAX;
	}

	_itoa_s(number, Number, 2);
	printf("Initial number:   %d In binary: \t%032s;\n", number, Number);
	_itoa_s(result, Result, 2);
	printf("Operation result:%4d   In binary: \t%011s.\n", result, Result);
	
	return 0;
}
