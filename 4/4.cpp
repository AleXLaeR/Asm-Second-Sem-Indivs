/* Algorithm:
* 1) declaring variables "number" (which will store the number from 0 to 255) and "result" (which will store the result of the logical operation);
* 2) declaring the variable "mask" and initializing it with 7 (1, 2, 3 bites will be 1);
* 3) in the assembler part:
*	3.1) putting the value of the variable "number" in the AX register;
*	3.2) putting the value of the variable "mask" in the BX register;
*	3.3) performing a bitwise operation on two numbers stored in the BX and AX registers respectively; result overwrites the BX register value;
*	3.4) taking the value stored in the BX register and putting it as a value of the variable "result";
* 4) declaring char-type arrays for storing the binary code of the variables "number", "mask" and "result";
* 5) outputting the initial values of the variables "number", "mask" and "result" and first 8 elements of the specialized char-type arrays.
*/
#include <iostream>
constexpr auto BYTE_MAX_VALUE = 256;

int main(void) {
	int number = 0; // starting from 0 and go on until 255 to get through all the 256 possible options
	int mask = 14; // 2**3 + 2**2 + 2**1 = 8 + 4 + 2 = 12 + 2 = 14 (00001110)
	int result = 0; // a variable which stores the result value of "or" operation in assembler part

	while (number != 255) {
		
		__asm {
			
			mov eax, number; // putting the value of the variable "number" in the AX register
			mov ebx, mask; // putting the value of the variable "mask" in the BX register
			or ebx, eax; // performing a bitwise operation on two numbers stored in the BX and AX registers respectively; result overwrites the BX register value
			mov result, ebx; // taking the value stored in the BX register and putting it as a value of the variable "result"
			
		}
		
		char Number[BYTE_MAX_VALUE] = "0"; // creating an array for storing the binary code of a value of the variable "number"
		char Mask[BYTE_MAX_VALUE] = "0"; // creating an array for storing the binary code of a value of the variable "mask"
		char Result[BYTE_MAX_VALUE] = "0"; // creating an array for storing the binary code of a value of the variable "result"

		_itoa_s(number, Number, 2); // converting integer to a string, storing its binary code in specialized char array
		printf("The number =\t%2d\t%08s\n", number, Number); // outputting the value of the variable "number" and fist 8 symbols of its char array
		_itoa_s(mask, Mask, 2); // converting integer to a string, storing its binary code in specialized char array
		printf("The  mask  =\t%2d\t%08s\n", mask, Mask); // outputting the value of the variable "mask" and fist 8 symbols of its char array
		_itoa_s(result, Result, 2); // converting integer to a string, storing its binary code in specialized char array
		printf("The result =\t%2d\t%08s\n", result, Result); // outputting the value of the variable "result" and fist 8 symbols of its char array

		system("pause");
		system("cls"); // clearing the screen every iteration 
		number++;
	}
	
	return 0;
}
