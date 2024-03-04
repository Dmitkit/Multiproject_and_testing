#include <gtest/gtest.h>

#include "long_number.hpp"
//переписать текст ошибок к тестам и добавить тесты с assert_false
TEST(get_digits_number, check_positive) {
	IBusko::LongNumber x("12345");
	ASSERT_EQ(5, x.get_digits_number())
		<< "Неправильно подсчитано количество разрядов в числе " << x;
}

TEST(get_digits_number, check_negative) {
	IBusko::LongNumber x("-1");
	ASSERT_EQ(1, x.get_digits_number())
		<< "Неправильно подсчитано количество разрядов в числе " << x;
}

TEST(addition, positives_and_zero) {
	for (int i = 0; i < 1000; i++){

    	char xnum[5];
        itoa(i, xnum, 10);
		IBusko::LongNumber x(xnum);

		for (int j = 0; j < 1000; j++){
			char ynum[5];
			itoa(j, ynum, 10);
			IBusko::LongNumber y(ynum);

			int correct = j + i;
			char char_correct[5];
			itoa(correct, char_correct, 10);
			IBusko::LongNumber z = x + y;
			IBusko::LongNumber answer(char_correct);
			ASSERT_EQ(answer, z)
			<< "Неверно посчитана сумма положительных чисел" << j << " + " << i << " = " << correct;
		}}
}

TEST(addition, negatives) {
	for (int i = -1000; i < 0; i++){

    	char xnum[6];
        itoa(i, xnum, 10);
		IBusko::LongNumber x(xnum);

		for (int j = -1000; j < 0; j++){
			char ynum[6];
			itoa(j, ynum, 10);
			IBusko::LongNumber y(ynum);

			int correct = j + i;
			char char_correct[5];
			itoa(correct, char_correct, 10);
			IBusko::LongNumber z = x + y;
			IBusko::LongNumber answer(char_correct);
			ASSERT_EQ(answer, z)
			<< "Неверно посчитана сумма отрицательных чисел" << j << " + " << i << " = " << correct;
		}}
}

TEST(subtraction, positives_and_zero) {
	for (int i = 0; i < 1000; i++){

    	char xnum[5];
        itoa(i, xnum, 10);
		IBusko::LongNumber x(xnum);

		for (int j = 0; j < 1000; j++){
			char ynum[5];
			itoa(j, ynum, 10);
			IBusko::LongNumber y(ynum);

			int correct = i - j;
			char char_correct[5];
			itoa(correct, char_correct, 10);
			IBusko::LongNumber z = x - y;
			IBusko::LongNumber answer(char_correct);
			ASSERT_EQ(answer, z)
			<< "Неверно посчитана разница положительных чисел" << i << " - " << j << " = " << correct;
		}}
}

TEST(subtraction, negatives) {
	for (int i = -1000; i < 0; i++){

    	char xnum[6];
        itoa(i, xnum, 10);
		IBusko::LongNumber x(xnum);

		for (int j = -1000; j < 0; j++){
			char ynum[6];
			itoa(j, ynum, 10);
			IBusko::LongNumber y(ynum);

			int correct = i - j;
			char char_correct[5];
			itoa(correct, char_correct, 10);
			IBusko::LongNumber z = x - y;
			IBusko::LongNumber answer(char_correct);
			ASSERT_EQ(answer, z)
			<< "Неверно посчитана разница отрицательных чисел" << i << " - " << j << " = " << correct;
		}}
}

class EqualityFixture : public testing::Test {
	public:
		IBusko::LongNumber one_v1 = IBusko::LongNumber("1");
		IBusko::LongNumber one_v2 = IBusko::LongNumber("1");
		IBusko::LongNumber twelve = IBusko::LongNumber("12");
		IBusko::LongNumber negative_one = IBusko::LongNumber("-1");
};

TEST_F(EqualityFixture, equal) {
	ASSERT_TRUE(one_v1 == one_v2) << "Проверка " << one_v1 << " == " << one_v2;
}

TEST_F(EqualityFixture, not_equal) {
	ASSERT_FALSE(one_v1 == twelve) << "Проверка " << one_v1 << " == " << twelve;
}

TEST_F(EqualityFixture, not_equal_negative_var) {
	ASSERT_FALSE(one_v1 == negative_one) 
		<< "Проверка " << one_v1 << " == " << negative_one;
}

// class SubtractionFixture : public testing::Test {
// 	public:
// 		IBusko::LongNumber one = IBusko::LongNumber("1");
// 		IBusko::LongNumber two = IBusko::LongNumber("2");
// 		IBusko::LongNumber three = IBusko::LongNumber("3");
// 		IBusko::LongNumber twelve = IBusko::LongNumber("12");
// 		IBusko::LongNumber minus_one = IBusko::LongNumber("-1");
// 		IBusko::LongNumber nine = IBusko::LongNumber("9");
// 		IBusko::LongNumber z1 = two - one;
// 		IBusko::LongNumber z2 = one - two;
// 		IBusko::LongNumber z3 = twelve - three;
// 		IBusko::LongNumber z4 = two - minus_one;

// };

// TEST_F(SubtractionFixture, single_digits_plus) {
// 	ASSERT_EQ(z1, one) << "Проверка " << two << " - " << one;
// }

// TEST_F(SubtractionFixture, single_digits_minus) {
// 	ASSERT_EQ(z2, minus_one) << "Проверка " << one << " - " << two;
// }

// TEST_F(SubtractionFixture, different_digits) {
// 	ASSERT_EQ(z3, nine) << "Проверка " << twelve << " - " << three;
// }

// TEST_F(SubtractionFixture, same_sign) {
// 	ASSERT_EQ(z4, three) << "Проверка " << two << " - " << minus_one;
// }

// class IsBiggerFixture : public testing::Test {
// 	public:
// 		IBusko::LongNumber one = IBusko::LongNumber("1");
// 		IBusko::LongNumber two = IBusko::LongNumber("2");
// 		IBusko::LongNumber twelve = IBusko::LongNumber("12");
// 		IBusko::LongNumber minus_one = IBusko::LongNumber("-1");
// 		IBusko::LongNumber minus_twelve = IBusko::LongNumber("-12");
// 		IBusko::LongNumber nine = IBusko::LongNumber("9");
// 		IBusko::LongNumber minus_thirteen = IBusko::LongNumber("-13");
// };

// TEST_F(IsBiggerFixture, is_bigger_negative_var) {
// 	ASSERT_FALSE(one > two) << "Проверка " << one << " > " << two;
// }
// TEST_F(IsBiggerFixture, is_bigger) {
// 	ASSERT_TRUE(two > one) << "Проверка " << one << " > " << two;
// }
// TEST_F(IsBiggerFixture, is_bigger_negative_negative_var) {
// 	ASSERT_FALSE(minus_twelve > minus_one) << "Проверка " << minus_twelve << " > " << minus_one;
// }
// TEST_F(IsBiggerFixture, is_bigger_negative) {
// 	ASSERT_TRUE(minus_one > minus_twelve) << "Проверка " << minus_one << " > " << minus_twelve;
// }
// TEST_F(IsBiggerFixture, is_bigger_by_absolute) {
// 	ASSERT_FALSE(minus_thirteen > twelve) << "Проверка " << minus_one << " > " << minus_twelve;
// }

// class IsLessFixture : public testing::Test {
// 	public:
// 		IBusko::LongNumber one = IBusko::LongNumber("1");
// 		IBusko::LongNumber two = IBusko::LongNumber("2");
// 		IBusko::LongNumber twelve = IBusko::LongNumber("12");
// 		IBusko::LongNumber minus_one = IBusko::LongNumber("-1");
// 		IBusko::LongNumber minus_twelve = IBusko::LongNumber("-12");
// 		IBusko::LongNumber nine = IBusko::LongNumber("9");
// 		IBusko::LongNumber minus_thirteen = IBusko::LongNumber("-13");
// };

// TEST_F(IsLessFixture, is_less_negative_var) {
// 	ASSERT_TRUE(one < two) << "Проверка " << one << " < " << two;
// }
// TEST_F(IsLessFixture, is_less) {
// 	ASSERT_FALSE(two < one) << "Проверка " << one << " < " << two;
// }
// TEST_F(IsLessFixture, is_less_negative) {
// 	ASSERT_TRUE(minus_twelve < minus_one) << "Проверка " << minus_twelve << " < " << minus_one;
// }
// TEST_F(IsLessFixture, is_less_negative_negative_var) {
// 	ASSERT_FALSE(minus_one < minus_twelve) << "Проверка " << minus_one << " < " << minus_twelve;
// }
// TEST_F(IsLessFixture, is_bigger_by_absolute) {
// 	ASSERT_TRUE(minus_thirteen < twelve) << "Проверка " << minus_one << " < " << minus_twelve;
// }

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
