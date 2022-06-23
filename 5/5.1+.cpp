#include <iostream>

using namespace std;

int main(void)
{
	char Number[255] = "";
	unsigned int number;
	cin >> number;
	unsigned int bit_counter = 0;
	unsigned int temp = number;

	while ((temp & 1) != 1)
	{
		temp >>= 1;
		bit_counter++;
	}
	_itoa_s(number, Number, 2);
	printf("Initial number : %u \tIn binary : \t % 032s; \n", number, Number);
	printf("The number of the first bit equal to \'1\' is: %d.\n", bit_counter);
	return 0;
}
