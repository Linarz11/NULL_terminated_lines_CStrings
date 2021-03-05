#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

int StrLen(char str[]);
void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}

}
void to_upper(char str[]);
void to_lower(char str[]);
void capitalize(char str[]);
void shrink(char str[]);
void remove_symbol(char str[], char symbol);
bool is_polindrome(char str[]);

//Numeric functions
bool is_int_number(char str[]);// ОБъявление функции (Function declaration)
int to_int_number(char str[]);

bool is_bin_number(char str[]);
int bin_to_dec(char str[]);

//#define BASE_STRING_OPERATIONS
void main()
{
	setlocale(LC_ALL, "Russian");
	system("CHCP 1251");
	system("CLS");
#ifdef BASE_STRING_OPERATIONS
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };

//char str[] = "Hello";
	const int n = 40;
	char str[n];
	cout << "Введите строку: ";
	//SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, n);

	//SetConsoleCP(866);
	cout << str << endl;
	cout << "Размер строки в байтах: " << sizeof(str) << endl;
	cout << "Размер строки в символах: " << StrLen(str) << endl;
	to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
	capitalize(str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;

	cout << (is_polindrome(str) ? "Да" : "Нет") << endl;
	cout << str << endl;

	cout << (is_int_number(str) ? "Да" : "Нет") << endl;
	cout << str << endl;


	cout << "ASCII таблица:" << endl;
	//ASCII();  
#endif // BASE_STRING_OPERATIONS


	const int n = 256;
	char str[n] = {};
	cout << "Введите строку: "; 
	//cin >> str;
	cin.getline(str, n);
	//cout << (is_int_number(str) ? "Число" : "Не число") << endl;
	//cout << str * 2 << endl;
	//cout << to_int_number(str)*10;

	cout << "Строка " << (is_bin_number(str) ? "" : "НЕ ") << "является двоичным числом" << endl;
	cout << str << "(bin) = " << bin_to_dec(str) << "(dec)" << endl;

}

int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' &&  str[i]<= 'я' )
		{
			str[i] -= 32;
		}
		if (str[i] == 'ё')str[i] -= 16;
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')
		{
			str[i] += 32;
		}
		if (str[i] == 'Ё')str[i] += 16;

	}
}

void capitalize(char str[])
{
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= 'а' && str[0] <= 'я')str[0] -= 32;
	else if (str[0] == 'ё')str[0] -= 16;
	for (int i = 1; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я') && str[i-1] ==' ' )str[i] -= 32;
		else if (str[i] == 'ё' && str[i-1] == ' ')str[i] -= 16;
	}
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while ((str[i] == ' ') && (str[i + 1] == ' '))
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];

			}
		}
	}				
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
}
}

bool is_polindrome(char str[])
{
	int size = StrLen(str);
	char* buffer = new char[size+1] {};
	//for (int i = 0; str[i]; i++)buffer[i] = str[i];
	strcpy(buffer, str); //String copy. 
	                     //buffer - строка получатель, 
		                 //str - строка - источник

	remove_symbol(buffer, ' ');
	to_lower(buffer);
	//Определяем длину строки
	size = strlen(buffer);
	for (int i = 0; i < (size/2); i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}

	}
	delete[] buffer;
	return true;
}

bool is_int_number(char str[])
{
	/*for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i]==' ') return false;
	}
	 return true;*/

	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i]!=' ')return false;
		if (str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}

int to_int_number(char str[])
{
	if (!is_int_number(str))return 0;
	int number = 0;
	for (int i = 0; str[i]; i++)
	{
		
		{
			if (str[i] == ' ')continue;
			number *= 10; //Сдвигаем число на разряд влево(освобождаем младший разряд)
			number += str[i] - 48;
		}
	}
	return number;

}

bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')return false;
		if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] == ' ')
			return false;
	}
	return true;
}

int bin_to_dec(char str[])
{

	if (!is_bin_number(str))return 0;
	int n = StrLen(str);
	int decimal = 0;// конечное десятичное число
	int weight = 1;//Весовой коэффициент разряда
	for (int i = n-1; i>=0; i--)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48)*weight;
			weight *= 2;
		}
	}
	return decimal;
}


