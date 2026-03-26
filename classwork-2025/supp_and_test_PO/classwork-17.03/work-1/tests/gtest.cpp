#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../modules/soundex.h"

class SoundexEncoding: public testing::Test
{
public:
    Soundex soundex;

};

TEST_F(SoundexEncoding, RetainsSoletterOfOneLetterWord)
{
    auto encoded{soundex.encode("A")};
    ASSERT_EQ(encoded, "A000");
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    auto encoded{soundex.encode("I")};
    ASSERT_EQ(encoded, "I000");
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithNumbers)
{
    EXPECT_EQ(soundex.encode("Ab"), ("A100"));
    EXPECT_EQ(soundex.encode("Ac"), ("A200"));
    EXPECT_EQ(soundex.encode("Ad"), ("A300"));
    EXPECT_EQ(soundex.encode("Ax"), ("A200"));
}

TEST_F(SoundexEncoding, IgnoreNonAlphabetics)
{
    EXPECT_EQ(soundex.encode("A#"), "A000");
}

TEST_F(SoundexEncoding, ReplaceMultipleConsonatsWithDigits)
{
    EXPECT_EQ(soundex.encode("Acdl"), "A234");
}

TEST_F(SoundexEncoding, LimitLengthToFourCharacters)
{
    EXPECT_EQ(soundex.encode("Dcdlb").length(), 4);
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters)
{
    EXPECT_EQ(soundex.encode("BaAeEiIoOuUhHyYcCdDlL"), "B234");
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings)
{
    EXPECT_EQ(soundex.encodedDigit('d'), soundex.encodedDigit('t'));
    EXPECT_EQ(soundex.encodedDigit('c'), soundex.encodedDigit('g'));
    EXPECT_EQ(soundex.encodedDigit('b'), soundex.encodedDigit('f'));
    EXPECT_EQ(soundex.encode("Abfcgdt"), "A123");
}

TEST_F(SoundexEncoding, UppercaswsFirstLetter)
{
    EXPECT_THAT(soundex.encode("abcd"), testing::StartsWith("A"));
}

TEST_F(SoundexEncoding, IgnoresCaseWhenEncodingConsonants)
{
    EXPECT_EQ(soundex.encode("BCDL"), soundex.encode("Bcdl"));
}

TEST_F(SoundexEncoding, CombinesDuplicateCodesWhen2ndLetterDuplicatesFirst)
{
    EXPECT_EQ(soundex.encode("Bbcd"), "B230");
}

TEST_F(SoundexEncoding, DoesNotCombineDuplicateEncodingsSeparetedByVowels)
{
    EXPECT_EQ(soundex.encode("Jbob"), "J110");
}