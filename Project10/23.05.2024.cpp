#include <iostream>
#pragma warning(disable : 4996) 
using namespace std;
/*Задача 1. Дано два текстові файли. З'ясувати, чи збігаються їхні рядки.
Якщо ні, то вивести рядок, який не збігається, з кожного файлу.*/
/*int main()
{
	const char* PATH_TO_FILE1 = "data.txt";
	const char* PATH_TO_FILE2 = "data1.txt";
	FILE* file1 = fopen(PATH_TO_FILE1, "r");
	FILE* file2 = fopen(PATH_TO_FILE2, "r");
	const int MAX = 255;
	char line1[MAX];
	char line2[MAX];
	bool filesMatch = true;
	while (fgets(line1, MAX, file1) && fgets(line2, MAX, file2))
	{
		for (int i = 0; line1[i] != '\0'; ++i)
		{
			if (line1[i] == '\r' || line1[i] == '\n')
			{
				line1[i] = '\0';
				break;
			}
		}
		for (int i = 0; line2[i] != '\0'; ++i)
		{
			if (line2[i] == '\r' || line2[i] == '\n')
			{
				line2[i] = '\0';
				break;
			}
		}
		if (strcmp(line1, line2) != 0)
		{
			filesMatch = false;
			cout << "Mismatch found:" << endl;
			cout << "File 1: " << line1 << endl;
			cout << "File 2: " << line2 << endl;
		}
	}
	if (!feof(file1) || !feof(file2))
	{
		filesMatch = false;
		if (!feof(file1))
		{
			cout << "File 1:" << endl;
			while (fgets(line1, MAX, file1))
			{
				cout << line1 << endl;
			}
		}
		if (!feof(file2))
		{
			cout << "File 2:" << endl;
			while (fgets(line2, MAX, file2))
			{
				cout << line2 << endl;
			}
		}
		if (filesMatch)
		{
			cout << "Files match." << endl;
		}
		fclose(file1);
		fclose(file2);
	}
	else
	{
		cout << "Error";
		if (file1 == nullptr) fclose(file1);
		if (file2 == nullptr) fclose(file2);
	}
}*/
/*Дан текстовий файл. Необхідно створити
новий файл і записати в нього таку статистику по вихідному файлу:
? Кількість символів;
? Кількість рядків;
? Кількість голосних;
? Кількість приголосних;
? Кількість цифр*/
bool isVowel(char c)
{
	return (c == 'a' c=='o' c=='e'  c == 'i' c == 'u' || c == 'A' c == 'I' c=='O' c=='E' c == 'U');
}

bool isConsonant(char c)
{
	return (c >= 'a' && c <= 'z' && !isVowel(c)) || (c >= 'A' && c <= 'Z' && !isVowel(c));
}

int main()
{
	const char* file1 = "in.txt";
	const char* file2 = "out.txt";
	FILE* File1 = fopen(file1, "r");
	FILE* File2 = fopen(file2, "w");
	if (File1 == nullptr)
	{
		cout << "Error" << endl;
	}
	if (File2 == nullptr)
	{
		cout << "Error" << endl;
		fclose(File1);
	}
	int countch = 0;
	int countst = 0;
	int countvo = 0;
	int countcon = 0;
	int countdig = 0;
	char c;
	while (!feof(File2))
	{
		c = fgetc(File1);

		countch++;

		if (c == '\n')
		{
			countst++;
		}

		if (c >= '0' && c <= '9')
		{
			countdig++;
		}
		else if (isVowel(c))
		{
			countvo++;
		}
		else if (isConsonant(c))
		{
			countcon++;
		}
	}
	fprintf(File2, "Ammount of char symbols ", countch);
	fprintf(File2, "Ammount of strings ", countst);
	fprintf(File2, "Ammount of vowels letters ", countvo);
	fprintf(File2, "Ammount of consonants ", countcon);
	fprintf(File2, "Ammount of digits symbols ", countdig);
	fclose(File1);
	fclose(File2);
	return 0;
}