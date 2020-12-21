#include "gtest/gtest.h"
#include "../lib/Semaphore.h"

#include <chrono>
#include <thread>

using namespace std;
namespace c = zxseitz::c3xx;

class SemaphoreFixture: public ::testing::Test {
public:
    void SetUp( ) override {
        // initialization or some code to run before each test
    }
};

TEST_F(SemaphoreFixture, test_init) {
    auto s = make_shared<c::Semaphore>(5);
    ASSERT_EQ(5, s->QueueLength());
    ASSERT_EQ(0, s->WaitingPermits());
}

TEST_F(SemaphoreFixture, test_permit) {
    auto s = make_shared<c::Semaphore>(2);
    auto i = make_shared<int>(1);
    thread t2([s]() {
        s->acquire();
        this_thread::sleep_for(chrono::milliseconds(200));
        s->release();
    });
    thread t3([s]() {
        s->acquire();
        this_thread::sleep_for(chrono::milliseconds(200));
        s->release();
    });
    thread t4([s, i]() {
        this_thread::sleep_for(chrono::milliseconds(50));
        ASSERT_EQ(1, *i);
        s->acquire();
        ASSERT_EQ(2, *i);
        s->release();
    });
    this_thread::sleep_for(chrono::milliseconds(100));
    ASSERT_EQ(2, s->WaitingPermits());
    *i = 2;
    t2.join();
    t3.join();
    t4.join();
    ASSERT_EQ(0, s->WaitingPermits());
}