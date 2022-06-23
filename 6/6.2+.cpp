using namespace std;

int main(void) {
	
	int mask = 2048; // 2**11 = 2048
	unsigned int number;
	unsigned int result;
	char Number[255] = "";
	char Result[255] = "";
	
	scanf_s("%u", &number);
	
	result = number & mask;
	result >>= 11;
	
	_itoa_s(number, Number, 2);
	printf("Initial number:   %u    In binary: \t%032s;\n", number, Number);
	_itoa_s(result, Result, 2);
	printf("Operation result: %3u     In binary: \t%011s.\n", result, Result);
	
	return 0;
}
