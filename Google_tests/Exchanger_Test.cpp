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

TEST(ExchangerFixture, test1) {
    auto ex = c3xx::Exchanger<int32_t>();
    auto* exp = &ex;
    ASSERT_NE(nullptr, exp);
}