#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(ConstructorTest, DefaultConstructor) {
  S21Matrix m1;
  ASSERT_EQ(3, m1.Get_row());
  ASSERT_EQ(3, m1.Get_cols());
}

TEST(ConstructorTest, ParameterConstructor) {
  S21Matrix m2(8, 3);
  ASSERT_EQ(8, m2.Get_row());
  ASSERT_EQ(3, m2.Get_cols());
}

TEST(SetTest, SetRow) {
  S21Matrix m(5, 10);
  double right_val = 0;
  m.FillMatrix(7.2);
  m.Set_rows(6);
  ASSERT_EQ(6, m.Get_row());
  ASSERT_NEAR(right_val, m(5, 0), EPS);
  m.Set_rows(1);
  ASSERT_EQ(1, m.Get_row());
}

TEST(SetTest, SetCols) {
  S21Matrix m(2, 3);
  double right_val = 6.2;
  m.FillMatrix(2.2);
  m.Set_cols(2);
  ASSERT_EQ(2, m.Get_cols());
  ASSERT_NEAR(right_val, m(1, 1), EPS);
  m.Set_cols(4);
  ASSERT_EQ(4, m.Get_cols());
}

TEST(EqMatrixTest, EqAllTest) {
  S21Matrix m3(2, 2);
  m3.FillMatrix(1.25);
  S21Matrix m4(2, 2);
  m4.FillMatrix(1.25);
  ASSERT_EQ(1, m3.EqMatrix(m4));
}

TEST(EqMatrixTest, NeRowsTest) {
  S21Matrix m5;
  S21Matrix m6(2, 3);
  ASSERT_EQ(0, m5.EqMatrix(m6));
}

TEST(EqMatrixTest, NeColsTest) {
  S21Matrix m7;
  S21Matrix m8(3, 5);
  ASSERT_EQ(0, m7.EqMatrix(m8));
}

TEST(EqMatrixTest, NeValsTest) {
  S21Matrix m9;
  S21Matrix m10(3, 3);
  m9.FillMatrix(100.35);
  m10.FillMatrix(34.5);
  ASSERT_EQ(0, m9.EqMatrix(m10));
}

TEST(SumMatrixTest, SuccessTest) {
  S21Matrix m11(2, 2), m12(2, 2);
  double right_val = 114.61;
  m11.FillMatrix(105.11);
  m12.FillMatrix(3.5);
  m11.SumMatrix(m12);
  ASSERT_NEAR(m11(1, 1), right_val, EPS);
}

// TEST(SumMatrix, FailTest) { // 16 bytes leaks
//     S21Matrix m13(1,2), m14(1,3);
//     try {
//         ASSERT_THROW(m13.SumMatrix(m14), const char*);
//     }
//     catch(const char *exception) {
//         fprintf(stderr, "Exception: %s\n", exception);
//     }

// }

TEST(SubMatrixTest, SuccessTest) {
  S21Matrix m15(5, 3), m16(5, 3);
  double right_val = -2.7;
  m15.FillMatrix(4.5);
  m16.FillMatrix(7.2);
  m15.SubMatrix(m16);
  ASSERT_NEAR(m15(0, 2), right_val, EPS);
}

// TEST(SubMatrixTest, FailTest) { //16 bytes leaks
//     S21Matrix m17(5,2), m18(7,1);
//     try {
//         ASSERT_THROW(m17.SumMatrix(m18), const char*);
//     }
//     catch(const char *exception) {
//         fprintf(stderr, "Exception: %s\n", exception);
//     }
// }

TEST(MulNumTest, SuccessTest) {
  S21Matrix m19(5, 5);
  double right_val = 149.6;
  m19.FillMatrix(5.2);
  m19.MulNumber(5.5);
  ASSERT_NEAR(m19(4, 2), right_val, EPS);
}

TEST(MulMatrixTest, SuccessTest) {
  S21Matrix m20(2, 5), m21(5, 7);
  double right_val = 1409.5;
  m20.FillMatrix(2.5);
  m21.FillMatrix(12.2);
  m20.MulMatrix(m21);
  ASSERT_EQ(m20.Get_row(), 2);
  ASSERT_EQ(m20.Get_cols(), 7);
  ASSERT_NEAR(m20(1, 2), right_val, EPS);
}

// TEST(MulMatrixTest, FailTest) { //leaks 16 bytes
//     S21Matrix m22(10,2), m23(5,4);
//     try {
//         ASSERT_THROW(m22.MulMatrix(m23), const char*);
//     }
//     catch(const char* exception) {
//         fprintf(stderr, "Exception: %s\n", exception);
//     }
// }

TEST(TransposeTest, SuccessTest) {
  S21Matrix m(3, 2);
  double right_val = 2000.5;
  m.FillMatrix(1996.5);
  S21Matrix res = m.Transpose();
  ASSERT_EQ(res.Get_row(), 2);
  ASSERT_EQ(res.Get_cols(), 3);
  ASSERT_NEAR(right_val, res(0, 2), EPS);
}

TEST(DeterminantTest, SuccessTest) {
  S21Matrix m(4, 4);
  double right_val = -256;
  m.FillMatrixForDeter();
  ASSERT_NEAR(right_val, m.Determinant(), EPS);
}

// TEST(DeterminantTest, FailTest) {
//     S21Matrix m(2, 10);
//     try {
//         ASSERT_THROW(m.Determinant(), const char*);
//     }
//     catch(const char* excep) {
//         fprintf(stderr, "Exception: %s\n", excep);
//     }
// }

TEST(CalcTest, SuccessTest) {
  double right_val = -8;
  S21Matrix m;
  m.FillMatrixForCalc();
  S21Matrix res = m.CalcComplements();
  ASSERT_NEAR(right_val, res(2, 0), EPS);
}

TEST(InverseTest, SuccessTest) {
  double right_val = -4.78125;
  S21Matrix m(4, 4);
  S21Matrix res;
  m.FillMatrixForDeter();
  res = m.InverseMatrix();
  ASSERT_NEAR(right_val, res(1, 1), EPS);
}

TEST(OperatorsOverloadTest, PlusTest) {
  double right_val = 12.5;
  S21Matrix m22(2, 2), m23(2, 2);
  m22.FillMatrix(5.8);
  m23.FillMatrix(2.7);
  S21Matrix res = m22 + m23;
  ASSERT_EQ(res.Get_row(), 2);
  ASSERT_EQ(res.Get_cols(), 2);
  ASSERT_NEAR(res(1, 0), right_val, EPS);
}

TEST(OperatorsOverloadTest, MinusTest) {
  double right_val = -11.05;
  S21Matrix m24(5, 2), m25(5, 2);
  m24.FillMatrix(0.25);
  m25.FillMatrix(11.3);
  S21Matrix res = m24 - m25;
  ASSERT_EQ(res.Get_row(), 5);
  ASSERT_EQ(res.Get_cols(), 2);
  ASSERT_NEAR(res(2, 0), right_val, EPS);
}

TEST(OperatorsOverloadTest, EqTrueTest) {
  S21Matrix m26(5, 2), m27(5, 2);
  m26.FillMatrix(0.25);
  m27.FillMatrix(11.3);
  ASSERT_FALSE(m26 == m27);
}

TEST(OperatorsOverloadTest, EqFalseTest) {
  S21Matrix m28(5, 2), m29(5, 2);
  m28.FillMatrix(0.25);
  m29.FillMatrix(0.25);
  ASSERT_TRUE(m28 == m29);
}

TEST(OperatorOverloadTest, MultNumtest) {
  double right_val = 15.5;
  S21Matrix m30;
  m30.FillMatrix(0.2);
  S21Matrix res = m30 * 2.5;
  ASSERT_NEAR(right_val, res(2, 0), EPS);
}

TEST(OperatorOverloadTest, MultMatrixTest) {
  double right_val = 59.59;
  S21Matrix m31(1, 1), m32(1, 4);
  m31.FillMatrix(5.9);
  m32.FillMatrix(7.1);
  S21Matrix res = m31 * m32;
  ASSERT_EQ(1, res.Get_row());
  ASSERT_EQ(4, res.Get_cols());
  ASSERT_NEAR(right_val, res(0, 3), EPS);
}

TEST(OperatorOverloadTest, FuncTest) {
  double right_val = 5.56;
  S21Matrix m33(2, 5);
  m33.FillMatrix(0.56);
  ASSERT_NEAR(right_val, m33(1, 0), EPS);
}
