#define N 5
#include <iostream>

using namespace std;

int main(void) {
	
	long int num_array[N][N];
	long int sum = 0, product = 0;

	srand(time(0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			
			num_array[i][j] = (rand() % 2 == 1) ? -(rand() % 10) : rand() % 10;
			cout.width(3); cout << num_array[i][j] << ' ';
		}
		cout << endl;
	}

	long int n_size = N * sizeof(long int);

	__asm {
		
		mov ecx, N
		mov edx, 1
		lea ebx, num_array

		m_beg_n:
			push ecx
			mov ecx, N
			xor esi, esi

		m_beg_m:
			mov eax, [ebx][4 * esi]
			cmp eax, 0

			jl m_sum
			jge m_cycle

		m_sum:
			add sum, eax
			jmp m_product

		m_product:
			imul edx, eax
			jmp m_cycle

		m_cycle:
			inc esi
			loop m_beg_m

			add ebx, n_size
			pop ecx
			loop m_beg_n

		m_end:
			mov product, edx

	}

	cout << endl << "The sum of all neg elem-ts: " << sum << endl << "The product of all neg elements: " << product << endl;
	return 0;
}
