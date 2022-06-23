#include <iostream>

using namespace std;

int main(void)
{
	unsigned int number;
	unsigned int result;
	char Number[255] = "";
	char Result[255] = "";	
	
	scanf_s("%u", &number);

	result = number | 0;
	result <<= 8;
	result >>= 21;
	
	_itoa_s(number, Number, 2);
	printf("Initial number:   %u    In binary: \t%032s;\n", number, Number);
	_itoa_s(result, Result, 2);
	printf("Operation result: %4u        In binary: \t%011s.\n", result, Result);
	
	return 0;
}
