#include "pch.h"
#include <gtest/gtest.h>
#include "../main/main.cpp"

TEST(TestCaseName, TestName) {
	EXPECT_EQ(compare(5, 4), 1);
	EXPECT_TRUE(true);

}
TEST(TestCaseName, TestName) {
	EXPECT_EQ(compare(4, 2), 1);
	EXPECT_TRUE(true);
}
TEST(TestCaseName, TestName) {
	EXPECT_EQ(compare(0, -5), 1);
	EXPECT_TRUE(true);
}
