#include "pch.h"
#include "../outputNum/lib.cpp"

TEST(TestCaseName, TestCase1Name) {
	EXPECT_EQ(compare(5, 4), 1);
	EXPECT_TRUE(true);

}
TEST(TestCaseName, TestCase2Name) {
	EXPECT_EQ(compare(4, 2), 1);
	EXPECT_TRUE(true);
}
TEST(TestCaseName, TestCase3Name) {
	EXPECT_EQ(compare(0, -5), 1);
	EXPECT_TRUE(true);
}
