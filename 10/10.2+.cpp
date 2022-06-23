#define N 5
#include <iostream>

using namespace std;

int main(void) {
	
	float num_array[N][N];
	float sum = 0.0, product = 0.0, temp = 0.0;

	srand(time(0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			num_array[i][j] = (rand() % 2 == 1) ? -(0.01 * (rand() % 100) + rand() % 4) : 0.01 * (rand() % 100) + rand() % 4;
			cout.width(5); cout.precision(4); cout << num_array[i][j] << ' ';
		}
		cout << endl;
	}

	long int n_size = N * sizeof(long int);

	__asm {
		
		mov ecx, N
		mov eax, 1
		lea ebx, num_array
		fld1
		fldz

		m_beg_n:
			push ecx
			mov ecx, N
			xor esi, esi

		m_beg_m:
			fldz
			fld [ebx][esi * 4]

			fcomi st, st(1)

			jb m_sum
			jae m_cycle

		m_sum:
			fadd st(2), st(0)
			jmp m_product

		m_product:
			fmul st(3), st(0)
			jmp m_cycle

		m_cycle:
			inc esi

			fstp temp
			fstp temp

			loop m_beg_m

			fst sum
			fxch st(1)
			fst product
			fxch st(1)

			add ebx, n_size
			pop ecx
			loop m_beg_n
			jmp m_exit

		m_exit:
			mov eax, 4C00h
	}

	cout << endl << "The sum of all neg elem-ts: " << sum << endl << "The product of all neg elements: " << product << endl;
	return 0;
}
