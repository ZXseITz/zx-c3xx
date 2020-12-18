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
    }
}