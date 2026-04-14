#ifndef MERETDD_TEST_H
#define MERETDD_TEST_H

#include <ostream>
#include <string_view>
#include <string>
#include <vector>

namespace MereTDD
{
    class TestBase
    {
    public:
        TestBase (std::string_view name)
        : mName(name), mPassed(true)
        { }
        virtual ~TestBase () = default;
        virtual void run () = 0;
        std::string_view name () const
        {
            return mName;
        }

        bool passed () const
        {
            return mPassed;
        }

        std::string_view reason () const
        {
            return mReason;
        }

        void setFailed (std::string_view reason)
        {
            mPassed = false;
            mReason = reason;
        }

    private:
        std::string mName;
        bool mPassed;
        std::string mReason;
    };
    
    inline std::vector<TestBase*> & getTests ()
    {
        static std::vector<TestBase *> tests;
        return tests;
    }

    inline int runTests(std::ostream & output)
    {
        output << "Running " << getTests().size() << " tests\n";

        int numPassed{};
        int numFailed{};

        for (auto * test: MereTDD::getTests())
        {
            output << "---------------\n"
                    << test->name() << "\n";
            try
            {
                test->run();
            }
            catch(...)
            {
                test->setFailed("Unexpected exception thrown.");
            }

            if(test->passed())
            {
                output << "Passed\n";
                numPassed++;
            }
            else
            {
                output << "Failed\n"
                          << test->reason() << "\n";
                numFailed++;
            }
        }
        output << "---------------\n";
        if(numFailed == 0)
        {
            output << "All tests passed.\n";
        }
        else
        {
            output << "Tests passed: " << numPassed << "\nTests failed: " << numFailed << "\n";
        }
        return numFailed;
    }
} // namespace MereTDD

#define MERETDD_CLASS_FINAL( line ) Test##line
#define MERETDD_CLASS_RELAY( line ) MERETDD_CLASS_FINAL( line )
#define MERETDD_CLASS MERETDD_CLASS_RELAY( __LINE__ )

#define MERETDD_INSTANCE_FINAL( line ) test##line
#define MERETDD_INSTANCE_RELAY( line ) MERETDD_INSTANCE_FINAL(line)
#define MERETDD_INSTANCE MERETDD_INSTANCE_RELAY( __LINE__ )

#define TEST_H

#define TEST(testName) \
class MERETDD_CLASS : public MereTDD::TestBase \
{ \
public: \
    MERETDD_CLASS (std::string_view name): TestBase(name) \
    { \
        MereTDD::getTests().push_back(this); \
    } \
    void run() override; \
}; \
MERETDD_CLASS MERETDD_INSTANCE(testName); \
void MERETDD_CLASS::run()
#endif // TEST_H

