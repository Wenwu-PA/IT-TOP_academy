#include <vector>
#ifndef MERETDD_TEST_H
#define MERETDD_TEST_H
namespace MERETDD_TEST_H{
    class TestInterface
    {
    public:
        virtual ~TestInterface () = default;
        virtual void run () = 0;
    };

    std::vector<TestInterface *>& getTests(){
        static std::vector<TestInterface *> tests;;
        return tests;
    }
}
#endif

#ifndef TEST_H
#define TEST_H
#include <string_view>
#define TEST class Test \
{ \
    std::string mName; \
    bool mResult; \
public: \
    Test (std::string_view name) \
    : mName(name), mResult(true) \
    {} \
    void operator () (); \
}; \
Test test("Test_can_be_created"); \
void Test::operator () ()
#endif // TEST_H