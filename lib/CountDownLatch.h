#pragma once

#include <mutex>
#include <condition_variable>

namespace zxseitz::c3xx {
    class CountDownLatch {
    private:
        size_t m_count;
        std::mutex m_mutex;
        std::condition_variable m_cond;
    public:
        explicit CountDownLatch(size_t count);
        void Await(); //todo set timeout
        void CountDown();
        size_t Count();
    };
}
