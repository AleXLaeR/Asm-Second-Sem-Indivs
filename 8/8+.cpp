#include <iostream>

using namespace std;

int main(void){
	
	long double a = -2.0f;
	long double b = 1.5f;

/* Блок обязательных для вычисления переменных */
	float x = 2.0f;
	float y = -2.0f;
	float z = 5.0f;

	long double result = 0.0f;

	__asm {
		
		fld b; // помещаю в регистр st0 значение b
		fld a; // помещаю в регистр st0 значение a
		fcomi st(0), st(1); // сравниваю значения регистров st0 и st1 (a и b)

		je _equal; // если значения регистров равны
		ja _greater; // если значение st0 > st1
		jb _lower; // если значение st0 < st1

	_equal:

		fld y; // помещаю в регистр st0 значение y
		jmp _exitt; // перехожу по метке _exitt

	_lower:

		fld z; // помещаю в регистр st0 значение z
		fld a; // помещаю в регистр st0 значение a
		fsub st(0), st(1); вычитаю регистры st0 и st1; результат в st0

		fdiv b; // делю значение в st0 на значение b
		jmp _exitt; // перехожу по метке _exitt

	_greater:

		fmul x; // умножаю значение в st0 на значение x
		fadd b; // складываю st0 и b; результат в st0
		jmp _exitt; // перехожу по метке _exitt

	_exitt:
		fst result; // помещаю значение регистра st0 в переменную result
	}
	
	if (result == SHRT_MIN)
		printf ("\nThe denominator is equal to zero.\n");
	else
		printf("%.3lf.\n", result);

	return 0;
}
