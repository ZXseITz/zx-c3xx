#include "gtest/gtest.h"
#include "../lib/CyclicBarrier.h"

#include <chrono>
#include <thread>

using namespace std;
namespace c = zxseitz::c3xx;

class CyclicBarrierFixture: public ::testing::Test {
public:
    void SetUp( ) override {
        // initialization or some code to run before each test
    }
};

TEST_F(CyclicBarrierFixture, test_init) {
    auto cb = make_shared<c::CyclicBarrier>(5);
    ASSERT_EQ(5, cb->Parties());
    ASSERT_EQ(0, cb->Waiting());
}

TEST_F(CyclicBarrierFixture, test_await) {
    auto cb = make_shared<c::CyclicBarrier>(3);
    thread t2([cb]() {
        cb->Await();
    });
    thread t3([cb]() {
        cb->Await();
    });

    // hope for t2 and t3 to await before waiting is accessed
    this_thread::sleep_for(chrono::milliseconds(100));

    ASSERT_EQ(2, cb->Waiting());

    // release threads
    cb->Await();
    t2.join();
    t3.join();

    ASSERT_EQ(0, cb->Waiting());
}