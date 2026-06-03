#ifndef MERETDD_TEST_H
#define MERETDD_TEST_H

#include <ostream>
#include <string_view>
#include <string>
#include <vector>

namespace MereTDD
{
    class MissingException
    {
        std::string mExType;
    public:
        MissingException(std::string_view exType): mExType(exType)
        {}
        std::string_view exType() const
        { return mExType; }
    };

    class TestBase
    {
        std::string mName;
        bool mPassed;
        std::string mReason;
        std::string mExpectedReason;
    public:
        TestBase (std::string_view name)
        : mName(name), mPassed(true)
        { }
        virtual ~TestBase () = default;
        virtual void runEx()
        { run(); }
        virtual void run () = 0;

        std::string_view name() const
        {
            return mName;
        }

        bool passed() const
        {
            return mPassed;
        }

        std::string_view reason() const
        {
            return mReason;
        }

        std::string_view expectedReason() const
        { return mExpectedReason; }

        void setFailed(std::string_view reason)
        {
            mPassed = false;
            mReason = reason;
        }

        void setExpectedFailureReason(std::string_view reason)
        { mExpectedReason = reason; }
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
        int numMissedFailed{};
        int numFailed{};

        for (auto * test: MereTDD::getTests())
        {
            output << "---------------\n"
                    << test->name() << "\n";
            try
            {
                test->runEx();
            }
            catch(MissingException const& ex)
            {
                std::string message = "Expected exception type ";
                message += ex.exType();
                message += " was not thrown.";
                test->setFailed(message);
            }
            catch(...)
            {
                test->setFailed("Unexpected exception thrown.");
            }

            if(test->passed())
            {
                if(!(test->expectedReason().empty()))
                {
                    numMissedFailed++;
                    output << "Missed expected failure\nTest passed but was expected to fail\n";
                }
                else
                {
                    output << "Passed\n";
                    numPassed++;
                }
            }
            else if(!(test->expectedReason().empty()) && test->expectedReason() == test->reason())
            {
                numPassed++;
                output << "Expected failure\n" << test->reason() << "\n";
            }
            else
            {
                output << "Failed\n"
                          << test->reason() << "\n";
                numFailed++;
            }
        }
        output << "---------------\n";
        output << "Tests passed: " << numPassed << "\nTests failed: " << numFailed << "\n";
        if(numMissedFailed != 0)
        { output << "Tests failures missed: " << numMissedFailed << "\n"; }
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

#define TEST_EX(testName, exceptionType) \
class MERETDD_CLASS: public MereTDD::TestBase \
{ \
public: \
    MERETDD_CLASS(std::string_view name): TestBase(name) \
    { MereTDD::getTests().push_back(this); } \
    void runEx() override \
    { \
        try \
        { \
            run(); \
        } \
        catch(exceptionType const&) \
        { \
            return; \
        } \
        throw MereTDD::MissingException(#exceptionType); \
    } \
    void run() override; \
}; \
MERETDD_CLASS MERETDD_INSTANCE(testName); \
void MERETDD_CLASS::run()

#define TEST(testName) \
class MERETDD_CLASS : public MereTDD::TestBase \
{ \
public: \
    MERETDD_CLASS (std::string_view name): TestBase(name) \
    { MereTDD::getTests().push_back(this); } \
    void run() override; \
}; \
MERETDD_CLASS MERETDD_INSTANCE(testName); \
void MERETDD_CLASS::run()
#endif // TEST_H

