#include <gtest/gtest.h>
#include "../modules/soundex.h"

class SoundexEncoding: public testing::Test{
	public:
	Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoletterOfOneLetterWord) {

	auto encoded = soundex.encode("A");

	ASSERT_EQ(encoded, "A000");
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
	auto encoded = soundex.encode("I");

	ASSERT_EQ(encoded, "I000");
}
TEST_F(SoundexEncoding, Replace) {

	EXPECT_EQ(soundex.encode("Ab"), ("A100"));
}