#pragma once

#include <mutex>
#include <condition_variable>

namespace zxseitz::c3xx {
    class CyclicBarrier {
    private:
        size_t m_parties;
        size_t m_waiting;
        std::mutex m_mutex;
        std::condition_variable m_cond;
    public:
        explicit CyclicBarrier(size_t parties);
        void Await();
        size_t Parties() const;
        size_t Waiting();
    };
}