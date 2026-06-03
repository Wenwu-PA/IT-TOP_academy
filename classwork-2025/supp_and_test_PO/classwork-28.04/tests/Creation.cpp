#include "../Test.h"

TEST("1 Test can be vreated")
{}

TEST("2 Test that throws unexpectedly can be created")
{
    setExpectedFailureReason("Unexpected exception thrown.");
    throw "Unexpected";
}

// This test should throw an unexpected exception
// but it doesn't. We need to somehow let the user
// know what happened. This will result in a missed failure.
TEST("3 Test that should throw unexpectedly can be created")
{
    setExpectedFailureReason("Unexpected exception thrown.");
}

TEST_EX("4 Test with throw can be vreated", int)
{
    throw 1;
}

TEST_EX("5 Test that never throws can be created", int)
{
    setExpectedFailureReason("Expected exception type int was not thrown.");
}

TEST_EX("6 Test that throws wrong type can be created", int)
{
    setExpectedFailureReason("Unexpected exception thrown.");
    throw "Wrong type";
}
