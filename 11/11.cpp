#include <iostream>

using namespace std;

int main(void) {
	
	srand(time(0));
	short int first_num, second_num, result = 0;
	first_num = (rand() % 2 == 1) ?  -(rand() % 100) : rand() % 100;
	second_num = (rand() % 2 == 1) ? -(rand() % 100) : rand() % 100;
	cout << endl << "first number = " << first_num << endl << "second number = " << second_num << endl;

	__asm {
		
		push first_num
		push second_num

		call sum
		jmp m_exit

		sum:
			push esp
			mov ax, word ptr[esp + 8]
			mov bx, word ptr[esp + 10]
			add ax, bx
			pop esp
			ret 4

		m_exit:
			mov result, ax
	}

	cout << "Their sum is " << result << '.' << endl;
	system("pause");
	return 0;
}

