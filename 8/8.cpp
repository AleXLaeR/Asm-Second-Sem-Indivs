#include <iostream>

using namespace std;

int main(void) {
	
	short int ax, bx;
	cin >> ax >> bx;
	
	if ((ax > 127) || (ax < -128) || (bx > 127) || (bx < -128)) {
		cout << "\nYou have entered wrong variable values.\n";
		return 1;
	}

	char a = char(ax);
	char b = char(bx);

	long int result, result_second;
	result = result_second = 0;

	__asm {
		
		mov al, a;
		cmp al, b;

			je _equal
			jg _greater
			jl _lower

			_equal :
		{
			mov eax, -2;
			jmp _exitt;
		}
			_greater:
		{
			sal al, 1;
			add al, b;
			cbw;
			movsx eax, ax;
			cbw;
			jmp _exitt;
		}
			_lower:
		{
			mov al, a;
			sub al, 5;
			cbw;
			movsx ebx, ax;

			mov al, b;
			cbw;
			mov cx, ax;
			movsx ecx, cx;

			mov eax, ebx;
			cdq;

			cmp ecx, 0;
			je _divzero;

			idiv ecx;
			mov result_second, edx;
			jmp _exitt;
		}
				_divzero:
		{
			mov result_second, SHRT_MIN;
			mov ax, 4C00h;
		}
			_exitt:
		{
			mov result, eax;
		}
	}

	if (result_second == SHRT_MIN)
		printf("\nThe denominator is equal to zero.\n");
	else
		printf("\nWhole part: %ld; Remainder: %ld\n", result, result_second);
	
	return 0;
}
