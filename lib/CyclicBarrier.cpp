#include "CyclicBarrier.h"

using namespace std;
namespace c = zxseitz::c3xx;

c::CyclicBarrier::CyclicBarrier(size_t parties): m_parties(parties), m_waiting(0) {

}

void c::CyclicBarrier::Await() {
    unique_lock<mutex> lock(m_mutex);
    if (m_waiting < m_parties - 1) {
        m_waiting++;
        m_cond.wait(lock);
    } else {
        m_waiting = 0;
        m_cond.notify_all();
    }
}

size_t c::CyclicBarrier::Parties() const {
    return m_parties;
}

size_t c::CyclicBarrier::Waiting() {
    lock_guard<mutex> lock(m_mutex);
    return m_waiting;
}
