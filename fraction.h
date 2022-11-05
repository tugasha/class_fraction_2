/// Обыкновенные дроби и операции над ними
/// Заголовки методов, описание класса
/// Автор Туганов К.А.
#include <iostream>

using namespace std;

class Fraction  
{

	private:
	    int numerator;
	    int denominator;
    

  	public:
  		/// Конструктор без параметров
	    Fraction();

		/// Конструктор с параметрами
		Fraction(int num, int denom);

		/// Задать числитель
		void setNumeratorF(int num);

		/// Задать знаменатель
		void setDemoninatorF(int denom);

		//Деструктор
		~Fraction();
		
	    /// Задание дроби
	    void initF(int num, int denom);

	    /// Вернуть знаменатель
	    int getNumeratorF() const;

	    /// Вернуть числитель
	    int getDenominatorF() const; 

	    /// Сравнение дробей
	    int compareF(Fraction f1);

	    /// Сумма дробей
	    Fraction addF(Fraction const& f1);

	    /// Разность дробей
	   	Fraction subF(Fraction const& f1);

	   	/// Произведение дробей
	    Fraction multF(Fraction const& f1);

	    /// Частное дробей
	    Fraction divF(Fraction const& f1);

	    /// Вывод дроби
		//void printF();

		/// Наибольший общий делитель
		int greaterCommonDivisor(int a, int b) const;

		/// Сокращение
		Fraction shortenF();

		/// Перевод в десятичную дробь
		double convertToDoubleF() const;

		/// Перевод в строку
		string stringFraction();
};

