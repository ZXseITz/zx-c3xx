#include "CountDownLatch.h"

using namespace std;
namespace c = zxseitz::c3xx;

c::CountDownLatch::CountDownLatch(size_t count): m_count(count) {

}

void zxseitz::c3xx::CountDownLatch::Await() {
    unique_lock<mutex> lock(m_mutex);
    if (m_count > 0) {
        m_cond.wait(lock);
    }
}

void zxseitz::c3xx::CountDownLatch::CountDown() {
    unique_lock<mutex> lock(m_mutex);
    if (m_count > 1) {
        m_count--;
    } else if (m_count > 0) {
        m_count--;
        m_cond.notify_all();
    }
}

size_t zxseitz::c3xx::CountDownLatch::Count() {
    lock_guard<mutex> lock(m_mutex);
    return m_count;
}