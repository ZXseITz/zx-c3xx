#pragma once

#include <mutex>
#include <condition_variable>

namespace c3xx {
    template<typename T>
    class Exchanger {
    private:
        volatile T* m_data;
        std::mutex m_mutex;
        std::condition_variable m_cond;
    public:
        Exchanger();
        T* exchange(T* data);
    };

    template<typename T>
    Exchanger<T>::Exchanger(): m_mutex(), m_cond() {
        m_data(nullptr);
    }

    template<typename T>
    T* Exchanger<T>::exchange(T *data) {
        std::unique_lock<std::mutex> lock(m_mutex);
        if (m_data == nullptr) {
            m_data = data;
            m_cond.wait(lock);
            auto result = m_data;
            m_data = nullptr;
            return result;
        } else {
            auto result = m_data;
            m_data = data;
            m_cond.notify_one();
            return result;
        }
    }
}
