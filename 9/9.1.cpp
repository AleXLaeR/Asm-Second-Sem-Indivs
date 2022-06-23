Найти и заменить все символы ‘0’ в исходной строке на символ ‘*’. Размер строки – 50 символов.

#include <iostream>

using namespace std;

int main(void) {
	
	char16_t ch[50];
	char temp_arr[50] = "0s///khgjvsdgfm,e5345-p09-0sf-sdv890-=/09wt054350";

	for (int i = 0; i < 50; i++)
		ch[i] = temp_arr[i];
	
	_asm {
		cld // обнуляю флаг направления df
		mov ecx, 50 // размер строки – 50 символов
		mov ax, '0' // искомый символ – ‘0’
		lea edi, ch // адрес первого элемента цепочки в edi

		m_beg:	
			repne scasw // команда scasw с помощью приставки repne повторяется до первого совпадения edi с ax
			jz m_replace // было найдено совпадение, т. е.элемент цепочки = ‘0’
			jecxz m_end // если ecx = 0, происходит переход по метке выхода
			jmp m_beg // метка m_beg повторяется

		m_replace:
			mov word ptr[edi - 2], '*' // заменяем предыдущий символ (т к после выполнения scasw edi продвинулся на 2 вперед) с ‘0’ на ‘*’
			jmp m_beg // безусловный переход по метке m_beg

		m_end:
			mov ax, 4C00h
	}

	cout << "The original sentence is: " << temp_arr << endl << "The changed  sentence is: ";
	for (int i = 0; i < 50; i++)
		printf("%c", ch[i]);

	return 0;
}
