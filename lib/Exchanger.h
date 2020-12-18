#pragma once

#include <mutex>
#include <condition_variable>
#include <memory>

namespace zxseitz {
    namespace c3xx {
        template<typename T>
        class Exchanger {
        private:
            std::shared_ptr<T> m_data;
            std::mutex m_mutex;
            std::condition_variable m_cond;
        public:
            Exchanger() = default;
            std::shared_ptr<T> Exchange(std::shared_ptr<T> data);
        };

        template<typename T>
        std::shared_ptr<T> Exchanger<T>::Exchange(std::shared_ptr<T> data) {
            std::unique_lock <std::mutex> lock(m_mutex);
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
}
