/* Algorithm:
* 1) declaring necessary variables "temp", "number" and "result";
* 2) declaring the necessary char array "Number" (for storing the binary code of the number);
* 3) asking a user to assign the value to a variable "temp";
* 4) while a user keeps entering value, which is higher than int max or lower than int min, he is asked to do it again with special preventive message;
* 5) if the entered value is "correct", the program keeps going;
* 6) clearing the screen every cycle's iteration;
* 7) putting the value of a variable "number" in a ECX register;
* 8) searching for the first equal to '1' bit in a ECX register, and overwrite data stored in ECX register with the number of that bit;
* 9) putting the value stored in a CX register in a variable "result";
* 10) outputting the result of the program; initial number, its binary code, the number of the first equal to '1' bit.
*/
#include <iostream>
using namespace std;

int main(void) {
	
    long long temp;
    int number;
    int result = 0;
	
    char Number[255] = "";
    srand(time(0));
	
    std::cout << "Enter the number: ";
    std::cin >> temp;

    while ((temp > INT32_MAX) || (temp < INT32_MIN)) {
		
        std:cout << "You entered inadmissible value, it should be lesser than " << INT32_MAX << " or greater than " << INT32_MIN << "" << std::endl;
        std::cout << "Please reenter the number: ";
        std::cin >> temp;
    }
	
    number = temp;

    for (int i = 0; i != 4; i++) {
        system("cls");
        //number = rand() % 2000000;
		
        __asm {		
            bsf ECX, number;
            mov result, ECX;
        }
		
        if (number == 0) {
            printf("There are no bites that equal one in this number.\n");
            system("pause");
            return 0;
        }
		
        _itoa_s(number, Number, 2);
        printf("The initial number: %d\tIn binary: %08s\n", number, Number);
        printf("operation result  : %d.\n", result);
        system("pause");
    }
	
    return 0;
}
