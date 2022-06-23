#define N 11

#include <iostream>

using namespace std;

int main(void) {
	
	long int result = 0;
	_int8 num_array[N] = { 134, -34, 8, 0, 78, 7, 8, -3, 7, 27, -68 };

	cout << "The array: ";
	for (int i = 0; i < N; i++)
		printf("%d ", num_array[i]);

	_asm {
		
		cld
		mov ecx, N
		xor ebx, ebx
		mov al, 7
		lea edi, num_array

		m_search_l:
			repe scasb // do cmp al, edi while al == edi
			jecxz m_look // if ecx = 0
			jl m_inc_l // if al < edi, sf != of
			jmp m_search_l

		m_inc_l:
			inc ebx
			jmp m_search_l

		m_look:
			lea edi, num_array
			mov ecx, N
			jmp m_search_e

		m_search_e:
			repne scasb // do cmp al, edi while al != edi
			jecxz m_end // ecx = 0
			je m_inc_e // if al = edi, zf = 1
			jmp m_search_e

		m_inc_e:
			inc ebx
			jmp m_search_e

		m_end:
			mov result, ebx
	}

	printf("\n\nThe amount of numbers that are greater or equal to 7 are: %ld.\n", result);
	return 0;
}
