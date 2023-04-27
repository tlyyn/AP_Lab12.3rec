#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab12.3rec/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SwapListRecursiveUnitTest
{
    TEST_CLASS(SwapListRecursiveUnitTest)
    {
    public:

        TEST_METHOD(TestSwapList)
        {
            // Arrange
            Elem* first = NULL, * last = NULL;
            enqueue(first, last, 1);
            enqueue(first, last, 2);
            enqueue(first, last, 3);
            enqueue(first, last, 4);
            enqueue(first, last, 5);
            enqueue(first, last, 6);
            int expected[] = { 6, 5, 4, 3, 2, 1 };

            // Act
            swapList(first, last);

            // Assert
            int i = 0;
            while (first != NULL) {
                Assert::AreEqual(expected[i++], first->info);
                first = first->next;
            }
        }
    };
}
