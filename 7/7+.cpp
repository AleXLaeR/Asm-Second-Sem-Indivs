#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
	
	float a = 12.32;
	float b = 35.129;
	float c = 71.908;
	float d = 0.01;

	float x = 4;
	float y = 2;
	float z = 23;
	float u = 12;

	float result = 0;

	__asm {
		
		fld a; // передаю в st(0) значение a
		fdiv x; // делю st(0) = a на 4
		fld d; // передаю в st(0) значение d
		fxch st(1); обмениваю значения 0 и 1 регистров
		fsub st(0), st(1); // вычитаю из 0 регистра 1, результат записывается в st(0)

		fld c; // передаю в st(0) значение c
		fmul y; // умножаю st(0) на значение y
		fld b; // передаю в st(0) значение b
		fmul z; // умножаю st(0) на значение z
		fadd st(0), st(1); // складываю 0 и 1 регистры, результат записывается в st(0)
		fld u; // передаю в st(0) значение u
		fsub st(1), st(0); // вычитаю из 1 регистра 0, результат записывается в st(1)
		fxch st(3); // обмениваю значения 0 и 3 регистров
		fst result; // значение result = st(0) (бывшему st(3))
		fxch st(1); // обмениваю значения 3 и 0 регистров обратно

		fdiv result; // делю числитель в st(0) на знаменатель = result
		fst result; // значение result = st(0) – итоговому значению выражения
	}
	printf("\n%.3f.\n", result);
	
	return 0;
}
