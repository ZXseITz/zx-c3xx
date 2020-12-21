#include "Semaphore.h"

using namespace std;
namespace c = zxseitz::c3xx;

c::Semaphore::Semaphore(size_t permits): m_length(permits), m_waiting(0) {

}

void c::Semaphore::acquire() {
    unique_lock<mutex> lock(m_mutex);
    if (m_waiting == m_length) {
        m_cond.wait(lock);
    }
    m_waiting++;
}

void c::Semaphore::release() {
    unique_lock<mutex> lock(m_mutex);
    if (m_waiting > 0) {
        if (m_waiting-- == m_length) {
            m_cond.notify_one();
        }
    }
}

size_t c::Semaphore::QueueLength() const {
    return m_length;
}

size_t c::Semaphore::WaitingPermits() {
    lock_guard<mutex> lock(m_mutex);
    return m_waiting;
}

size_t c::Semaphore::AvailablePermits() {
    lock_guard<mutex> lock(m_mutex);
    return m_length - m_waiting;
}
