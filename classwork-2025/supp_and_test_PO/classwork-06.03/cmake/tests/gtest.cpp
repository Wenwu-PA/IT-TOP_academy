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
	EXPECT_EQ(soundex.encode("Ac"), ("A200"));
	EXPECT_EQ(soundex.encode("Ad"), ("A300"));
	EXPECT_EQ(soundex.encode("Ax"), ("A200"));
}
TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
	EXPECT_EQ(soundex.encode("A#"),"A000");
	
}
TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits){
	EXPECT_EQ(soundex.encode("Acdl"),("A230"));
}
TEST_F(SoundexEncoding, limitsLenghToFourCharacters){
	EXPECT_EQ(soundex.encode("Dcdlb"),("D231"));
}