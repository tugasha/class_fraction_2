/// Обыкновенные дроби и операции над ними
/// Главная программа
/// Автор Туганов К.А.
#include <iostream>
#include <stdio.h>
#include <exception>
#include <fstream>
#include <string>
#include "fraction.h"

using namespace std;

void outputFraction(Fraction f, string name, int number) {
	ofstream outFile(name, ios_base::app);

	if (name == "")  throw invalid_argument("File's name error");/// Если имя файла пустое
	if (!outFile.is_open()) /// Вызов метода is_open()
		throw invalid_argument("File isn't open!");/// Если файл не открыт

	outFile << "f[" << number <<"] = " << f.stringFraction() << endl;/// Вывод дробей
	//outFile << f.stringFraction() << endl;/// Вывод дробей

	outFile.close();// Закрытие файла
}

/// Количество строк в файле
int rowsNumber(string name) {
	ifstream inFile(name);

	if (name == "")  throw invalid_argument("File's name error");
	//Если файл не открыт
	if (!inFile.is_open()) // вызов метода is_open()
		throw invalid_argument("File isn't open!");//Если файл не открыт

	string s;//Буферная строка 

	int k = 0;
	while (inFile.peek() != EOF) {
		getline(inFile, s);
		k++;
	}
	inFile.close();// Закрытие файла
	if (k == 0) throw invalid_argument("Empty file");
	return k;
}

/// Чтение объектов из файла строк в файле
void getFraction(Fraction *f, string name, int k) {

	ifstream inFile(name);

	if (name == "")  throw invalid_argument("File's name error");
	if (!inFile.is_open()) /// Вызов метода is_open()
		throw invalid_argument("File isn't open!");/// Если файл не открыт

	char s;
	int denom;
	int num; 
	char n[255];
	char d[255];
	for (int i = 0; i < 50; i++)
	{
		do
		{
			char ch = inFile.get();
			n[i] = ch;

		} while (n[i+1] != '/' && i < k);

		do
		{
			char ch = inFile.get();
			d[i] = ch;

		} while (d[i+1] != '\n' || !inFile.eof());
		cout << n << d;
		num = stoi(n);
		denom = stoi(d);
		f[i].initF(num, denom);

	}

	inFile.close();// Закрытие файла
}

int main()
{
	string fileOutName = "outFile.txt";/// Имя файла вывода
	string fileInName = "inFile.txt";/// Имя файла вывода
	int k;/// Количество строк в файле ввода

	try {

		Fraction f1, f2;
		f1.initF(6, 5);/// Задание дробей
		f2.initF(4, 5);

		cout << "f1 = " << f1.stringFraction() << endl;/// Вывод дробей
		cout << "f2 = " << f2.stringFraction() << endl;

		int sign = f1.compareF(f2);/// Сравнение дробей
		switch (sign) {
		case  0: {
			cout << "f1 is equal f2" << endl;
			break;
		}

		case  1: {
			cout << "f1 is larger than f2" << endl;
			break;
		}
		case -1: {
			cout << "f2 is larger than f1" << endl;
			break;
		}

		}


		int a, b, c, d;
		a = 2; b = 7; c = 4; d = 14;
		//cout << "Input fractions: " << endl;
		//cin >> a >> b >> c >> d;

		Fraction f5;

		Fraction f3(a, b); ///Задание дробей
		Fraction f4(c, d);
		cout << endl << "f3 = " << f3.stringFraction() << endl; /// Вывод дробей
		cout << "f4 = " << f4.stringFraction() << endl;


		f5 = f3.addF(f4); /// Расчёт суммы дробей
		cout << endl << "f5 = f3 + f4 = " + f5.stringFraction(); /// Вывод суммы дробей


		cout << endl << "f5.numerator = " << f5.getNumeratorF() << endl; /// Получение знаменателя дроби f3

		//f3.shortenF();/// Сокращение дроби
		//cout << endl << "f3(shorten) = " + f3.stringFraction() << endl; /// Вывод после сокращения


		cout << endl << "f5 = " << f5.convertToDoubleF() << endl<< endl; /// Перевод в десятичную дробь


			/// Массив из объектов
			const int size = 5;
			Fraction *arrF = new Fraction [size];
			int j = 2;

			for (int i = 1; i < size; i++) { /// Задание значений объектов
				arrF[i].initF(i, j);
				j++;
			}

			for (int i = 1; i < size; i++) { /// Вывод объектов
				cout << "fr[" << i << "] = " << arrF[i].stringFraction() << endl;
			}

			/// Вывод чистилеля 3-й дроби
			cout << endl << "fr[" << 3 << "].numerator = "<< arrF[3].getNumeratorF() << endl;
			/// Сумма дробей
			Fraction f_sum = arrF[3].addF(arrF[4]);
			cout << endl << "f_sum = fr[" << 3 << "] + fr[" << 4 << "] = " + f_sum.stringFraction(); /// Вывод суммы дробей

			delete []arrF;/// Освобождение памяти



			/// Массив из указателей на объекты
			Fraction *aF[size];

			for (int i = 1; i < size; i++) { /// Присваивание массиву aF указателей на массив arrF
				aF[i] = &arrF[i];
			}

			for (int i = 1; i < size; i++) { /// Вывод числителей объектов через указатели
				cout << endl << "aF[" << i << "].numerator = " << aF[i]->getNumeratorF() << endl;
			}

			outputFraction(f1, fileOutName, 1);/// Вывод дробей в файл
			outputFraction(f2, fileOutName, 2);
			outputFraction(f3, fileOutName, 3);
			outputFraction(f4, fileOutName, 4);
			outputFraction(f5, fileOutName, 5);

			for (int i = 1; i <= 4; i++) /// Вывод массива дробей в файл
			{
				outputFraction(arrF[i], fileOutName, i);
			}

			k = rowsNumber(fileInName);
			//cout << k;

			Fraction *arr2 = new Fraction [k];
			getFraction(arrF, fileInName, k);

			for (int i = 1; i <= k; i++) /// Вывод массива дробей в файл
			{
				outputFraction(arr2[i], fileOutName, i);
			}

}
	
	catch (invalid_argument e) {
		cout << e.what();
	}

	
	return 0;
}

    

