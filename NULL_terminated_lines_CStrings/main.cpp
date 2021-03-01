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

void main()
{
	setlocale(LC_ALL, "Russian");
	system("CHCP 1251");
	system("CLS");
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };

	//char str[] = "Hello";
	const int n = 40;
	char str[n];
	cout << "������� ������: ";
	//SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, n);

	//SetConsoleCP(866);
	cout << str << endl;
	cout << "������ ������ � ������: " <<sizeof(str) << endl;
	cout << "������ ������ � ��������: " << StrLen(str) << endl;
	to_upper(str);
	cout << str << endl;
	to_lower(str);
	cout << str << endl;
	capitalize(str);
	cout << str << endl;
	shrink(str);
	cout << str << endl;

	cout << (is_polindrome(str) ? "��": "���") << endl;
	cout << str << endl;


	cout << "ASCII �������:" << endl;
	//ASCII();
	
	
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
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= '�' &&  str[i]<= '�' )
		{
			str[i] -= 32;
		}
		if (str[i] == '�')str[i] -= 16;
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '�' && str[i] <= '�')
		{
			str[i] += 32;
		}
		if (str[i] == '�')str[i] += 16;

	}
}

void capitalize(char str[])
{
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= '�' && str[0] <= '�')str[0] -= 32;
	else if (str[0] == '�')str[0] -= 16;
	for (int i = 1; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= '�' && str[i] <= '�') && str[i-1] ==' ' )str[i] -= 32;
		else if (str[i] == '�' && str[i-1] == ' ')str[i] -= 16;
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
	                     //buffer - ������ ����������, 
		                 //str - ������ - ��������

	remove_symbol(buffer, ' ');
	to_lower(buffer);
	//���������� ����� ������
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

