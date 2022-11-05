#include "pch.h"
#include "../class_fraction/fraction.cpp" /// с fraction.h выдаёт ошибку LNK2019, пока не разобрался
///Автор Туганов К.А.
/// 
/// 
/// Изменение дроби, получение числителя и знаменателя
TEST(TestFraction, Test_init_getNumDenomF) {
	Fraction f(2, 5);

	EXPECT_EQ(f.getNumeratorF(), 2);
	EXPECT_EQ(f.getDenominatorF(), 5);

	f.initF(5, 7);

	EXPECT_EQ(f.getNumeratorF(), 5);
	EXPECT_EQ(f.getDenominatorF(), 7);
}

/// Задание числителя и знаменателя
TEST(TestFraction, Test_setNumDenomF) {
	Fraction f(2, 5);

	EXPECT_EQ(f.getNumeratorF(), 2);
	EXPECT_EQ(f.getDenominatorF(), 5);

	f.setDemoninatorF(2);
	f.setNumeratorF(2);
	EXPECT_EQ(f.getNumeratorF(), 2);
	EXPECT_EQ(f.getDenominatorF(), 2);
}

/// Сравнение дробей
TEST(TestFraction, Test_compareF) {
	Fraction f1(11, 20);
	Fraction f2(10, 20);

	EXPECT_EQ(f1.compareF(f2), 1);
}

/// Сумма дробей
TEST(TestFraction, Test_addF) {
	Fraction f1(2, 5);
	Fraction f2(9, 5);
	
	Fraction f3 = f1.addF(f2);

	EXPECT_EQ(f3.getNumeratorF(), 11);
	EXPECT_EQ(f3.getDenominatorF(), 5);
}

/// Разность дробей
TEST(TestFraction, Test_subF) {
	Fraction f1(2, 5);
	Fraction f2(9, 5);

	Fraction f3 = f1.subF(f2);

	EXPECT_EQ(f3.getNumeratorF(), -7);
	EXPECT_EQ(f3.getDenominatorF(), 5);
}

/// Произведение дробей
TEST(TestFraction, Test_multF) {
	Fraction f1(2, 5);
	Fraction f2(9, 5);

	Fraction f3 = f1.multF(f2);

	EXPECT_EQ(f3.getNumeratorF(), 18);
	EXPECT_EQ(f3.getDenominatorF(), 25);
}

/// Частное дробей
TEST(TestFraction, Test_divF) {
	Fraction f1(2, 5);
	Fraction f2(9, 5);

	Fraction f3 = f1.divF(f2);

	EXPECT_EQ(f3.getNumeratorF(), 2);
	EXPECT_EQ(f3.getDenominatorF(), 9);
}

/// Наибольший общий делитель
TEST(TestFraction, Test_nod) {
	Fraction f;
	int x = 24;
	int y = 36;

	EXPECT_EQ(f.greaterCommonDivisor(x,y), 12);
}

/// Сокращение дроби
TEST(TestFraction, Test_shortenF) {
	Fraction f(4, 10);

	f.shortenF();

	EXPECT_EQ(f.getNumeratorF(), 2);
	EXPECT_EQ(f.getDenominatorF(), 5);
}
/// Перевод дроби в вещественное число
TEST(TestFraction, Test_convertToDoubleF) {
	Fraction f(4, 10);

	EXPECT_EQ(f.convertToDoubleF(), 0.4);

}
