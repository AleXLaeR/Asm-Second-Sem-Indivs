#include <iostream>

using namespace std;

int main(void)
{
	char Number[255] = "";
	char Result[255] = "";
	unsigned int number;
	unsigned int result;
	cin >> number;
	result = number & (~(1 << 10));

	_itoa_s(number, Number, 2);
	printf("The initial number : %u.\tIn binary : % 016s\n", number, Number);
	_itoa_s(result, Result, 2);
	printf("Operation result : % 4u.\tIn binary : % 016s\n", result, Result);
	return 0;
}
