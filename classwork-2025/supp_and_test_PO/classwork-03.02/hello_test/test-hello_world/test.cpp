#include "pch.h"
#include "CppUnitTest.h"
#include "D:\git\IT-TOP_academy\classwork-2025\supp_and_test_PO\classwork-03.02\hello_test\hello-world.cpp"   // Update using your project name

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HelloWorldTests
{
    TEST_CLASS(HelloWorldTests)
    {
    public:

        TEST_METHOD(TestMethod)
        {
            std::string expected = "Hello World!\n";

            std::stringstream buffer;
            std::streambuf* sbuf = std::cout.rdbuf(); // Save cout's buffer
            std::cout.rdbuf(buffer.rdbuf()); // Redirect cout to the stringstream buffer

            // Call main() in your test
            int result = main();

            // When finished, redirect cout to the original buffer 
            std::cout.rdbuf(sbuf);
            std::cout << "std original buffer: \n";
            std::cout << buffer.get();

            // Test
            Assert::AreEqual(expected, buffer.str());
        }
        TEST_METHOD(test_summ) {
            Assert::AreEqual(9, sum(5, 4));
        }
        TEST_METHOD(search) {
            int arr[]{ 23,0,-76,3,11 };
            Assert::AreEqual(search(arr, 4);
        }
    };
}