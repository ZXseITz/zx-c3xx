#include "gtest/gtest.h"
#include "../lib/Exchanger.h"

using namespace std;
namespace c3xx = zxseitz::c3xx;

class ExchangerFixture: public ::testing::Test {
public:
    void SetUp( ) override {
        // initialization or some code to run before each test
    }
};

TEST_F(ExchangerFixture, test1) {
    auto* ex = new c3xx::Exchanger<int32_t>();
    thread t2([ex]() {
        auto* i2 = new int (2);
        auto* i1 = ex->Exchange(i2);
        ASSERT_EQ(1, *i1);
    });
    auto* i1 = new int(1);
    auto* i2 = ex->Exchange(i1);
    ASSERT_EQ(2, *i2);
    t2.join();
    delete ex;
}