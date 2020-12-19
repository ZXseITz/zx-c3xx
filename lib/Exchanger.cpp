#include "Exchanger.h"

using namespace std;
namespace c = zxseitz::c3xx;

template<typename T>
std::shared_ptr<T> c::Exchanger<T>::Exchange(std::shared_ptr<T> data) {
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