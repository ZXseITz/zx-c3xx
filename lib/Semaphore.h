#pragma once

#include <mutex>
#include <condition_variable>

namespace zxseitz::c3xx {
    class Semaphore {
    private:
        size_t m_length;
        size_t m_waiting;
        std::mutex m_mutex;
        std::condition_variable m_cond;
    public:
        explicit Semaphore(size_t permits);
        void acquire();
        void release();
        size_t QueueLength() const;
        size_t WaitingPermits();
        size_t AvailablePermits();
    };
}
