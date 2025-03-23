#include "../complexlib/TComplex.h"

#include <gtest.h>

TEST(TComplexTest, constructor_and_getters_int) {
  TComplex<double> c(3.0, 4.0);
  EXPECT_EQ(c.GetRe(), 3.0);
  EXPECT_EQ(c.GetIm(), 4.0);
}

TEST(TComplexTest, constructor_and_getters_double) {
  TComplex<int> c(3, 4);
  EXPECT_EQ(c.GetRe(), 3);
  EXPECT_EQ(c.GetIm(), 4);
}

TEST(TComplexTest, addition_operator_double) {
  TComplex<double> c1(1.0, 2.0);
  TComplex<double> c2(3.0, 4.0);
  TComplex<double> result = c1 + c2;
  EXPECT_EQ(result.GetRe(), 4.0);
  EXPECT_EQ(result.GetIm(), 6.0);
}

TEST(TComplexTest, addition_operator_int) {
  TComplex<int> c1(1, 2);
  TComplex<int> c2(3, 4);
  TComplex<int> result = c1 + c2;
  EXPECT_EQ(result.GetRe(), 4);
  EXPECT_EQ(result.GetIm(), 6);
}

TEST(TComplexTest, minus_operator_double) {
  TComplex<double> c1(1.0, 2.0);
  TComplex<double> c2(3.0, 4.0);
  TComplex<double> result = c1 - c2;
  EXPECT_EQ(result.GetRe(), -2.0);
  EXPECT_EQ(result.GetIm(), -2.0);
}

TEST(TComplexTest, minus_operator_int) {
  TComplex<int> c1(1, 2);
  TComplex<int> c2(3, 4);
  TComplex<int> result = c1 - c2;
  EXPECT_EQ(result.GetRe(), -2);
  EXPECT_EQ(result.GetIm(), -2);
}

TEST(TComplexTest, multiplication_operator_double) {
  TComplex<double> c1(1.0, 2.0);
  TComplex<double> c2(3.0, 4.0);
  TComplex<double> result = c1 * c2;
  EXPECT_EQ(result.GetRe(), -5.0); 
  EXPECT_EQ(result.GetIm(), 10.0); 
}

TEST(TComplexTest, multiplication_operator_int) {
  TComplex<int> c1(1, 2);
  TComplex<int> c2(3, 4);
  TComplex<int> result = c1 * c2;
  EXPECT_EQ(result.GetRe(), -5); 
  EXPECT_EQ(result.GetIm(), 10); 
}

TEST(TComplexTest, sum_operator_double) {
  TComplex<double> a(4.0, 6.0);
  TComplex<double> b(2.0, 2.0);
  a += b;
  EXPECT_DOUBLE_EQ(a.GetRe(), 6.0);
  EXPECT_DOUBLE_EQ(a.GetIm(), 8.0);
}

TEST(TComplexTest, sum_operator_int) {
  TComplex<int> a(4, 6);
  TComplex<int> b(2, 2);
  a += b;
  EXPECT_EQ(a.GetRe(), 6);
  EXPECT_EQ(a.GetIm(), 8);
}

TEST(TComplexTest, MultiplicationAssignmentOperator) {
  TComplex<int> a(2, 3);  
  TComplex<int> b(4, 5);  

  a *= b;

  EXPECT_EQ(a.GetRe(), -7);  
  EXPECT_EQ(a.GetIm(), 22);  
}

TEST(TComplexTest, MultiplicationAssignmentOperator_double) {
  TComplex<double> a(2.0, 3.0); 
  TComplex<double> b(4.0, 5.0);  

  a *= b;

  EXPECT_EQ(a.GetRe(), -7.0);  
  EXPECT_EQ(a.GetIm(), 22.0);  
}

TEST(TComplexTest, division_assignment_operator) 
{
  TComplex<double> a(4.0, 6.0); 
  TComplex<double> b(2.0, 2.0); 
  a /= b;
  EXPECT_DOUBLE_EQ(a.GetRe(), 2.5);  
  EXPECT_DOUBLE_EQ(a.GetIm(), 0.5);  
}

TEST(TComplexTest, assignment_operator_int) {
  TComplex<int> a(3, 4);
  TComplex<int> b(1, 2);

  a = b;
  EXPECT_EQ(a.GetRe(), 1);
  EXPECT_EQ(a.GetIm(), 2);
}

TEST(TComplexTest, assignment_operator_double) {
  TComplex<double> a(3.0, 4.0);
  TComplex<double> b(1.0, 2.0);

  a = b;
  EXPECT_EQ(a.GetRe(), 1.0);
  EXPECT_EQ(a.GetIm(), 2.0);
}

TEST(TComplexTest, equality_operator_double) {
  TComplex<double> a(3.0, 4.0);
  TComplex<double> b(3.0, 4.0);
  TComplex<double> c(1.0, 2.0);

  EXPECT_TRUE(a == b);
  EXPECT_FALSE(a == c);
}

TEST(TComplexTest, equality_operator_int) {
  TComplex<int> a(3, 4);
  TComplex<int> b(3, 4);
  TComplex<int> c(1, 2);

  EXPECT_TRUE(a == b);
  EXPECT_FALSE(a == c);
}

TEST(TComplexTest, inequality_operator_double) {
  TComplex<double> a(3.0, 4.0);
  TComplex<double> b(1.0, 2.0);

  EXPECT_TRUE(a != b);
  EXPECT_FALSE(a != a);
}


TEST(TComplexTest, inequality_operator_int) {
  TComplex<int> a(3, 4);
  TComplex<int> b(1, 2);

  EXPECT_TRUE(a != b);
  EXPECT_FALSE(a != a);
}

TEST(TComplexTest, CopyConstructor) {

  TComplex<double> original(3.0, 4.0);  

  TComplex<double> copy(original);

  EXPECT_DOUBLE_EQ(copy.GetRe(), original.GetRe());  
  EXPECT_DOUBLE_EQ(copy.GetIm(), original.GetIm()); 
}

TEST(TComplexTest, CopyConstructorWithZeroValues) {
  TComplex<double> original(0.0, 0.0);  
  TComplex<double> copy(original);

  EXPECT_DOUBLE_EQ(copy.GetRe(), 0.0);
  EXPECT_DOUBLE_EQ(copy.GetIm(), 0.0);
}

TEST(TComplexTest, CopyConstructorWithNegativeValues) {
  TComplex<double> original(-2.5, -3.5);  
  TComplex<double> copy(original);

  EXPECT_DOUBLE_EQ(copy.GetRe(), -2.5);
  EXPECT_DOUBLE_EQ(copy.GetIm(), -3.5);
}

TEST(TComplexTest, Magnitude) {
  TComplex<double> a(3.0, 4.0); 
  EXPECT_DOUBLE_EQ(a.Magnitude(), 5.0); 
}


TEST(TComplexTest, PowerPositive) {
  TComplex<double> a(1.0, 1.0);  
  TComplex<double> result = a.Power(3);  

  EXPECT_NEAR(result.GetRe(), -2.0, 1e-9);  
  EXPECT_NEAR(result.GetIm(), 2.0, 1e-9);   
}

TEST(TComplexTest, PowerZero) {
  TComplex<double> a(1.0, 1.0);  
  TComplex<double> result = a.Power(0);  

  EXPECT_DOUBLE_EQ(result.GetRe(), 1.0);  
  EXPECT_DOUBLE_EQ(result.GetIm(), 0.0);  
}