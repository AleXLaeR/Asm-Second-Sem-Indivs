/* Algorithm:
* 1) declaring necessary variables a, b, c, d, which are being used in a mathematical expression;
* 2) declaring necessary variables whole_result, remainder_result for storing the whole part and the quotient;
* 3) converting a_temp, c_temp to char and initialising variables a and c with them;
* 4) moving value of a variable a to al register;
* 5) shifting bits of the number of the number stored in al register two bits right (dividing by 4);
* 6) expand al register to ax register (adding 8 zeros from the left side);
* 7) moving value of a variable d to bx register;
* 8) subtracting ax and bx registers, result stored in ax register;
* 9) moving value of register ax a to register cx;
* 10) moving value of c variable a to al register;
* 11) shifting bits of the number of the number stored in al register one bit left (multiplying by 2);
* 12) expand ax register to the pair of registers ax:dx;
* 13) moving value of b variable a to bx register;
* 14) multiplying the value stored in bx register by 23;
* 15) adding ax and bx registers, result stored in ax register;
* 16) subtracting ax register and 12, result stored in ax register;
* 17) dividing a pair of register ax:dx by the value in register cx -> whole part stored in ax, fractional in dx;
* 18) putting the value stored in ax register to the variable whole_result;
* 19) putting the value stored in dx register to the variable remainder_result;
* 20) outputting the result values to the screen.
*/


#include <iostream>

using namespace std;

int main(void) {
	
	short a_temp, b, c_temp, d;
	cin >> a_temp >> b >> c_temp >> d;

	char a = char(a_temp);
	char c = char(c_temp);
	
	int temp_result;
	int whole_result, remainder_result;

	__asm // (2с + 23b - 12)/(a/4 - d) {
		// знаменатель
		mov al, a;
		sar al, 2;
		cbw;

		mov bx, d;
		sub ax, bx;
		mov cx, ax;
		movsx ecx, cx;

		// числитель
		mov ax, b;
		mov bx, 23;
		imul bx;

		shl edx, 16;
		mov dx, ax;
		mov ebx, edx;

		mov al, c;
		cbw;
		sal ax, 1;
		movsx eax, ax;
		add eax, ebx;
		sub eax, 12;
		cdq;

		// итог
		idiv ecx;
		mov whole_result, eax;
		mov remainder_result, edx;
	}

	printf("a = %d\nb = %d\nc = %d\nd = %2d", a_temp, b, c_temp, d);
	printf("\nThe whole part: %d, The remainder: %u.\n", whole_result, remainder_result);
	
	return 0;
}
