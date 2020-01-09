#include "asyncTest.hpp"

TESTS_INIT();

int main()
{
    // global test initialization code (if any) goes here
    TestGroup("group one")
    {
        group.beforeEach = [&](test::Test& t){ printf("beforeEach\n"); };

        asyncTest("test one",
        {{"event 1", "order", 1}, {"event 2", "timeout", 4000, "order", 2}})
        {
            loop.jitterPct = 40; //set the default schedCall() delay fuziness. By default it's 50%
            loop.schedCall([&]()
            {
                test.done("event 1");
                loop.schedCall([&]()
                {
                    test.done("event 2");
                });
            });
         });
         syncTest("test three")
         {
             int a = 2;
             check(a == 2); // if a is not 2, calls test.error() and throws test::BailoutException
         });
    });
    //  global cleanup code (if any) goes here>
    return test::gNumFailed; //return the total error count to the calling process. Useful for automation
}

