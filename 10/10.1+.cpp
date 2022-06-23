#define NUMBER_OF_ELEMENTS 25
#include <iostream>

using namespace std;

int main(void) {
	
	float num_array[NUMBER_OF_ELEMENTS];
	float result_maximum = 0.0f, temp = 0.0f;

	srand(time(0));

	cout << "The array: ";
	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++) {
		num_array[i] = (rand() % 2 == 1) ? 
		-(0.01 * (rand() % 100) + rand() % 100) : 0.01 * (rand() % 100) + rand() % 100;
	}

	num_array[rand() % 25] = num_array[rand() % 25] = num_array[rand() % 25] = num_array[rand() % 25] = num_array[rand() % 25] = 0;

	for (int i = 0; i < NUMBER_OF_ELEMENTS; i++)
		cout << num_array[i] << ' ';

	__asm {
		
		mov ecx, NUMBER_OF_ELEMENTS - 1
		xor esi, esi
		fld num_array[esi]
		add esi, 4

		m_begin:
			fld num_array[esi]
			fxch st(1)
			fcomi st, st(1)
			jae m_greater_equal
			jb m_lower

		m_greater_equal:
			fst st(1)
			jmp m_exit

		m_lower:
			fld st(1)
			fstp temp
			jmp m_exit

		m_exit:
			add esi, 4

			fstp temp

			loop m_begin

			fst result_maximum

			fninit
			mov ecx, NUMBER_OF_ELEMENTS
			xor esi, esi

		m_beg_replace:
			fld num_array[esi]
			fldz

			fcomi st, st(1)
			je m_equal
			jne m_end

		m_equal:
			fld result_maximum
			fstp num_array[esi]

		m_end:
			add esi, 4

			fstp temp
			fstp temp

			loop m_beg_replace
	}
