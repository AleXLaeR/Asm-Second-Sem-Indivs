#define N 25
#include <iostream>

using namespace std;

int main(void) {
	
	long int result_maximum = 0;
	long int num_array[N];
	
	srand(time(0));
	cout << "The array: ";
	for (int i = 0; i < N; i++)
	{
		num_array[i] = (rand() % 2 == 1) ? -(rand() % 100) : rand() % 100;
		cout.width(3); cout << num_array[i] << ' ';
	}
	num_array[0] = num_array[12] = num_array[24] = 0;

	__asm {
		
		mov ecx, N
		mov ebx, 4
		xor eax, eax
		mov edx, num_array[eax]

		m_begin:
			cmp edx, num_array[ebx]
			jge m_greater_equal
			jl m_lower

		m_greater_equal:
			mov eax, edx
			jmp m_exit

		m_lower:
			mov edx, num_array[ebx]
			mov eax, edx
			jmp m_exit

		m_exit:
			add ebx, 4
			loop m_begin
			mov result_maximum, eax

		xor ebx, ebx
		mov ecx, N

		m_start:
			mov edx, num_array[ebx]

			cmp edx, 0
			je m_replace

			add ebx, 4
			loop m_start
			jmp m_end

		m_replace:
			mov num_array[ebx], eax
			add ebx, 4
			loop m_start

		m_end:
			mov eax, 4C00h
	}

	cout << endl << "The found maximum is: " << result_maximum << endl << "The changed array: ";
	for(int i = 0; i < N; i++) { 
		cout.width(3); 
		cout << num_array[i] << ' '; 
	}
	cout << endl;
	
	return 0;
}
