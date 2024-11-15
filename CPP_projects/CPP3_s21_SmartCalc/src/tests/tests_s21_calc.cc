#include <gtest/gtest.h>

#include "../Calculator/Controller/calculator_controller.h"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(CalculationTest, CosFunction) {
  s21::CalculatorController c("cos(1)");
  ASSERT_NEAR(c.GetDoubleRes(0), cos(1), 0.00000001);
}

TEST(CalculationTest, SinFunction) {
  s21::CalculatorController c("sin(1)");
  ASSERT_NEAR(c.GetDoubleRes(0), sin(1), 0.00000001);
}

TEST(CalculationTest, SqrtFunction) {
  s21::CalculatorController c("sqrt(1)");
  ASSERT_NEAR(c.GetDoubleRes(0), sqrt(1), 0.00000001);
}

TEST(CalculationTest, TanFunction) {
  s21::CalculatorController c("tan(1)");
  ASSERT_NEAR(c.GetDoubleRes(0), tan(1), 0.00000001);
}

TEST(CalculationTest, AcosFunction) {
  s21::CalculatorController c("acos(1)");
  ASSERT_NEAR(c.GetDoubleRes(0), acos(1), 0.00000001);
}

TEST(CalculationTest, AsinFunction) {
  s21::CalculatorController c("asin(1)");
  ASSERT_NEAR(c.GetDoubleRes(0), asin(1), 0.00000001);
}

TEST(CalculationTest, AtanFunction) {
  s21::CalculatorController c("atan(1)");
  ASSERT_NEAR(c.GetDoubleRes(0), atan(1), 0.00000001);
}

TEST(CalculationTest, LnFunction) {
  s21::CalculatorController c("ln(1)");
  ASSERT_NEAR(c.GetDoubleRes(0), log(1), 0.00000001);
}

TEST(CalculationTest, LogFunction) {
  s21::CalculatorController c("log(1)");
  ASSERT_NEAR(c.GetDoubleRes(0), log10(1), 0.00000001);
}

TEST(CalculationTest, ModOperation) {
  s21::CalculatorController c("3.3mod7.9");
  s21::CalculatorController c1("(-3.3)mod7.9");
  s21::CalculatorController c2("3.3mod(-7.9)");
  s21::CalculatorController c3("(-3.3)mod(-7.9)");
  ASSERT_NEAR(c.GetDoubleRes(0), fmod(3.3, 7.9), 0.00000001);
  ASSERT_NEAR(c1.GetDoubleRes(0), fmod(-3.3, 7.9), 0.00000001);
  ASSERT_NEAR(c2.GetDoubleRes(0), fmod(3.3, -7.9), 0.00000001);
  ASSERT_NEAR(c3.GetDoubleRes(0), fmod(-3.3, -7.9), 0.00000001);
}

TEST(CalculationTest, PowOperation) {
  s21::CalculatorController c("9.5^3.3");
  ASSERT_NEAR(c.GetDoubleRes(0), pow(9.5, 3.3), 0.00000001);
}

TEST(CalculationTest, PlusMinusOperation) {
  s21::CalculatorController c("cos(1)+sin(1)-tan(1)");
  ASSERT_NEAR(c.GetDoubleRes(0), cos(1) + sin(1) - tan(1), 0.00000001);
}

TEST(ValidationTest, GetRes) {
  s21::CalculatorController c("(((cos(1 )))");
  s21::CalculatorController c2("(22.23mod 3.2))^3");
  s21::CalculatorController c3("cos");
  s21::CalculatorController c4("cos(1) + sin()");
  s21::CalculatorController c5(".23 - 5");
  s21::CalculatorController c6("23+0.5-21.");
  s21::CalculatorController c7("24.055.22+3");
  s21::CalculatorController c8("2s-2p");
  s21::CalculatorController c9("(3.22*5)2-2");
  s21::CalculatorController c10("(4*)-cos(1)");
  s21::CalculatorController c11("3.24+-3");
  s21::CalculatorController c12("(mod13)*2");
  s21::CalculatorController c13("5mod*25");
  s21::CalculatorController c14("4+5*xcos(1)");
  s21::CalculatorController c15("(-5)x+0.25");
  s21::CalculatorController c16("-sin(0.25)");
  s21::CalculatorController c17("*sin(0.25)");
  ASSERT_EQ(c.GetRes("0"), "Input error!");
  ASSERT_EQ(c2.GetRes("0"), "Input error!");
  ASSERT_EQ(c3.GetRes("0"), "Input error!");
  ASSERT_EQ(c4.GetRes("0"), "Input error!");
  ASSERT_EQ(c5.GetRes("0"), "Input error!");
  ASSERT_EQ(c6.GetRes("0"), "Input error!");
  ASSERT_EQ(c7.GetRes("0"), "Input error!");
  ASSERT_EQ(c8.GetRes("0"), "Input error!");
  ASSERT_EQ(c9.GetRes("0"), "Input error!");
  ASSERT_EQ(c10.GetRes("0"), "Input error!");
  ASSERT_EQ(c11.GetRes("0"), "Input error!");
  ASSERT_EQ(c12.GetRes("0"), "Input error!");
  ASSERT_EQ(c13.GetRes("0"), "Input error!");
  ASSERT_EQ(c14.GetRes("0"), "Input error!");
  ASSERT_EQ(c15.GetRes("0"), "Input error!");
  ASSERT_EQ(c16.GetRes("0"), "Input error!");
  ASSERT_EQ(c17.GetRes("0"), "Input error!");
}

TEST(Validation, ExpressionValid) {
  s21::CalculatorController c1("-sin(21)");
  ASSERT_TRUE(c1.ExpressionValid());
}

TEST(Validation, GraphicValid) {
  s21::CalculatorController c1("cos(1)");
  ASSERT_TRUE(c1.GraficValid(-1000000000, 100000, -100, 1000));
  ASSERT_TRUE(c1.GraficValid(-100, 100, -100, -500));
  ASSERT_TRUE(c1.GraficValid(10, 10, -100, 100));
}

TEST(ValidationTest, Maxlen) {
  std::string str =
      "cos(1)-tan(0.1122)+5 - cos(1)-tan(0.1122)+5 * cos(1)-tan(0.1122)+5 - cos(1)-tan(0.1122)+5 * cos(1)-tan(0.1122)+5  - \
                        cos(1)-tan(0.1122)+5 + cos(1)-tan(0.1122)+5 / cos(1)-tan(0.1122)+5 - cos(1)-tan(0.1122)+5 * cos(1)-tan(0.1122)+5 - cos(1)-tan(0.1122)+5 *cos(1)-\
                        tan(0.1122)+5 + cos(1)-tan(0.1122)+5";
  s21::CalculatorController ctr(str);
  ASSERT_EQ(ctr.GetRes("0"), "Input error!");
}

TEST(Validation, xValid) {
  s21::CalculatorController c1("x*x");
  s21::CalculatorController c2("cos(x)");
  s21::CalculatorController c3("3.3modx");
  ASSERT_EQ(c1.GetRes("-3"), "9.000000");
  ASSERT_EQ(c1.GetRes(".12"), "Input error!");
  ASSERT_EQ(c1.GetRes("23.5-"), "Input error!");
  ASSERT_EQ(c1.GetRes("12.25.12"), "Input error!");
  ASSERT_EQ(c1.GetRes("a"), "Input error!");
  ASSERT_EQ(c1.GetRes("5a"), "Input error!");
  ASSERT_EQ(c1.GetRes("--5"), "Input error!");
  ASSERT_EQ(c2.GetRes("-5"), "0.283662");
  ASSERT_EQ(c3.GetRes("-3"), "0.300000");
}
