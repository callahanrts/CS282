#include "vec3.h"

#include "gtest/gtest.h"

/*
  Note that even without proper implementations, this test will
  pass. Why is that? You should make the test pass because the code is
  correct, not because of trivial correctness conditions.
 */
TEST(Vec3Test, VectorAdditionCommutativity) {
  simphys::vec3 v1(1.0f, 2.0f, 3.0f);
  simphys::vec3 v2(4.0f, 5.0f, 6.0f);

  simphys::vec3 v3 = v1 + v2;
  simphys::vec3 v4 = v2 + v1;
  
  // EXPECT_FLOAT_EQ tests two floating-point numbers for equality and
  // is aware of numerical precision.
  EXPECT_FLOAT_EQ(v3.getX(), v4.getX());
  EXPECT_FLOAT_EQ(v3.getY(), v4.getY());
  EXPECT_FLOAT_EQ(v3.getZ(), v4.getZ());
}

/*
  TODO - put your tests here.
*/

TEST(Norms, RightMath){
	simphys::vec3 v1(1.0f, 2.0f, 2.0f);
	EXPECT_EQ(9, v1.norm_sq());
	EXPECT_EQ(3, v1.norm());
}

TEST(Normalized, Correctly){
	simphys::vec3 v1(1.0f, 2.0f, 2.0f);
	simphys::vec3 v2 = v1.normalized();

	EXPECT_FLOAT_EQ(v1.getX()/3, v2.getX());
	EXPECT_FLOAT_EQ(v1.getY()/3, v2.getY());
	EXPECT_FLOAT_EQ(v1.getZ()/3, v2.getZ());
	
	v1.normalize();
	EXPECT_FLOAT_EQ(v1.getX(), v2.getX());
	EXPECT_FLOAT_EQ(v1.getY(), v2.getY());
	EXPECT_FLOAT_EQ(v1.getZ(), v2.getZ());
}

TEST(Product, dot){
	simphys::vec3 v1(1.0f, 2.0f, 3.0f);
	simphys::vec3 v2(4.0f, 5.0f, 6.0f);
	EXPECT_FLOAT_EQ(32, v1.dotProduct(v2));
}

TEST(Product, cross){
	simphys::vec3 v1(1.0f, 2.0f, 3.0f);
	simphys::vec3 v2(4.0f, 5.0f, 6.0f);
	simphys::vec3 v3 = v1.crossProduct(v2);
	EXPECT_FLOAT_EQ(-3, v3.getX());
	EXPECT_FLOAT_EQ( 6, v3.getY());
	EXPECT_FLOAT_EQ(-3, v3.getZ());
}

TEST(Operator, Addition){
	simphys::vec3 v1(4.0f, 5.0f, 6.0f);
	simphys::vec3 v2(5.0f, 3.0f, 1.0f);
	simphys::vec3 v3 = v1 + v2;
	EXPECT_FLOAT_EQ(9, v3.getX());
	EXPECT_FLOAT_EQ(8, v3.getY());
	EXPECT_FLOAT_EQ(7, v3.getZ());
}

TEST(Operator, Subtraction){
	simphys::vec3 v1(4.0f, 5.0f, 6.0f);
	simphys::vec3 v2(5.0f, 3.0f, 1.0f);
	simphys::vec3 v3 = v1 - v2;
	EXPECT_FLOAT_EQ(-1, v3.getX());
	EXPECT_FLOAT_EQ( 2, v3.getY());
	EXPECT_FLOAT_EQ( 5, v3.getZ());
}

TEST(Operator, Multiplication){
	simphys::vec3 v1(4.0f, 5.0f, 6.0f);
	simphys::vec3 v2 = v1 * 3;
	EXPECT_FLOAT_EQ(12, v2.getX());
	EXPECT_FLOAT_EQ(15, v2.getY());
	EXPECT_FLOAT_EQ(18, v2.getZ());

	v2 = 3 * v1;
	EXPECT_FLOAT_EQ(12, v2.getX());
	EXPECT_FLOAT_EQ(15, v2.getY());
	EXPECT_FLOAT_EQ(18, v2.getZ());
}

TEST(Root, Accuracy){
	simphys::vec3 v1(51.0f, 23.0f, 19.0f);
	EXPECT_FLOAT_EQ(59.08468499, v1.norm());
}












