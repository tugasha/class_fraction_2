/// Обыкновенные дроби и операции над ними
/// Реализания методов класса
/// Автор Туганов К.А.
#include <iostream>
#include <string>
#include "fraction.h"

using namespace std;


	/// Конструктор без параметров
    Fraction::Fraction(){ 
    	numerator = 1; denominator = 1;
    }

	/// Конструктор с параметрами
	Fraction::Fraction(int num, int denom) {
		setNumeratorF(num);
		setDemoninatorF(denom);
	}

	/// Задать числитель
	void Fraction::setNumeratorF(int num) {
		numerator = num;
	}

	/// Задать знаменатель
	void Fraction::setDemoninatorF(int denom) {
		if (denom == 0) throw invalid_argument("Error: denominator < 0");
		denominator = denom;
	}
	//Деструктор
	Fraction::~Fraction() { }//cout << "Destructor called for Fraction " << stringFraction() << endl;  }

    /// Задание/изменение дроби
    void Fraction::initF(int num, int denom){  
		setNumeratorF(num);
		setDemoninatorF(denom);
    }

    /// Вернуть числитель
	int Fraction::getNumeratorF() const {
		return numerator;
	}

    /// Вернуть знаменатель
	int Fraction::getDenominatorF() const {
		return denominator;
	}

	/// Сравнить дроби
	int Fraction::compareF( Fraction f1 ) { 
		Fraction f;

		f = (*this).subF(f1);/// Вычитание дроби
		if (f.numerator > 0) {/// Проверка знака числителя
			return 1;
		}
		else {
			if (f.numerator < 0) {
				return -1;
			}
			else {
				return 0;
			}
		}
		cout << endl;
	}

	/// Сумма дробей
    Fraction Fraction::addF(Fraction const& f1){

    	int num_ = (this->numerator * f1.denominator) + (f1.numerator* this->denominator);
		int denom_ = this->denominator*f1.denominator;
		Fraction f(num_, denom_);
		f.shortenF();
		return f;
		//return Fraction((this->numerator * f1.denominator) + (f1.numerator * this->denominator), this->denominator * f1.denominator);
    }

	/// Вычитание дроби
	Fraction Fraction::subF(Fraction const &f1) {  
		
		int num_ = (this->numerator * f1.denominator) - (f1.numerator * this->denominator);
		int denom_ = this->denominator * f1.denominator;
		Fraction f(num_, denom_);
		f.shortenF();
		return f;
	}

    /// Произведение дробей
    Fraction Fraction::multF(Fraction const& f1){

		int num_ = this->numerator*f1.numerator;
		int denom_ = this->denominator*f1.denominator;
		Fraction f(num_, denom_);
		f.shortenF();
		return f;
	}

	/// Частное дробей
    Fraction Fraction::divF(Fraction const& f1){

		int num_ = this->numerator*f1.denominator;
		int denom_ = this->denominator*f1.numerator;
		Fraction f(num_, denom_);
		f.shortenF();
		return f;
	}

	///// Вывод дроби
	//void Fraction::printF() {
	//	cout << numerator << "/" << denominator;
	//}


	/// Наибольший общий делитель
	int Fraction::greaterCommonDivisor(int a, int b) const
	{
		a = abs(a);
		b = abs(b);
			while ((a!=0) && (b!=0)) 
			{
				if (a > b) 
				{
					a = a - b;
				} 
				else 
				{
					b = b - a;
				}
			}
		if (a!= 0) 
		{
			return a;
		} 
		else 
		{
			return b;
		}
	}


	/// Сокращение
	Fraction Fraction::shortenF() {
		
		int divisor = greaterCommonDivisor(this->numerator, this->denominator);
		numerator = this->numerator / divisor;
		denominator = this->denominator / divisor;
		return *this;
	}

	/// Перевод в десятичную дробь
	double Fraction::convertToDoubleF() const 
		{
			return (double(numerator) / denominator);
		}

	/// Перевод в строку
	string Fraction::stringFraction() {
		return to_string(numerator) + "/" + to_string(denominator);
	}



