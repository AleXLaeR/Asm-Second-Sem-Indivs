/* Algorithm:
* 1) declaring necessary variables "temp", "number" and "result";
* 2) declaring necessary char arrays "Number" and "Result" (for storing the binary code of the number);
* 3) asking a user to assign the value to a variable "temp";
* 4) while a user keeps entering value, which is higher than short max or lower than short min, he is asked to do it again with special preventive message;
* 5) if the entered value is "correct", the program keeps going;
* 6) clearing the screen every cycle's iteration;
* 7) putting the value of a variable "number" in a CX register;
* 8) searching for the 10-th bit in a CX register and resetting it to 0;
* 9) putting the value stored in a CX register in a variable "result";
* 10) outputting the resukt of the program; initial number, its binary code, changed number, and its binary code.
*/


#include <iostream>

using namespace std;

int main(void) {
	
    int temp;
    short number;
    short result = 0;
	
    char Number[255] = "";
    char Result[255] = "";
	
    srand(time(0));
	
    std::cout << "Enter the number: ";
    std::cin >> temp;


    while ((temp > SHRT_MAX) || (temp < SHRT_MIN)) {
        std:cout << "You entered inadmissible value, it should be lesser than " 
		<< SHRT_MAX << " or greater than " << SHRT_MIN << "" << std::endl;
        std::cout << "Please reenter the number: ";
        std::cin >> temp;
    }
    number = temp;

    for (int i = 0; i != 4; i++) {
        system("cls");
     // number = rand() % 32700;
	 
        __asm {
			
            mov CX, number;
            btr CX, 10;
            mov result, CX;
        }
		
        _itoa_s(number, Number, 2);
        printf("The initial number: %d.\tIn binary: %016s\n", number, Number);
        _itoa_s(result, Result, 2);
        printf("Operation result  : %4d.\tIn binary: %016s\n", result, Result);
        system("pause");
    }
	
    return 0;
}
