#include <gtest/gtest.h>
#include "../cmake-test/lib.h"

TEST(TestCompare, TestSmall) {
	EXPECT_EQ(compare(0, -5), 1);
}
TEST(TestCompare, TestEqua) {
	EXPECT_EQ(compare(5, 5), 1);
}
TEST(TestCompare, TestBig) {
	EXPECT_EQ(compare(25, -5), 1);
}
TEST(TestFact, Test) {
	EXPECT_EQ(120,fact(5));
}
