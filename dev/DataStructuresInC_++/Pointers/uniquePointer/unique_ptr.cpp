#include <iostream>
#include <vector>
#include <memory>
#include <utility>

template <class T>
class unique_ptr {
    public:
     unique_ptr() noexcept : unique_ptr(nullptr) {} // Constructor delegation to explicit constructor using nullptr base
     explicit unique_ptr(T *ptr) noexcept : m_ptr{ptr} {} // Constructor that takes a ptr

     unique_ptr(const unique_ptr &) = delete; // Copy constructor = delete means do not let this function be used
     unique_ptr &operator=(const unique_ptr &) = delete; // Copy assignment operator

     unique_ptr(unique_ptr &&other) noexcept : m_ptr{other.release()} {} // Move assignment
     unique_ptr &operator=(unique_ptr &&other) noexcept { // Move assignment operator
        if (this != &other) {
            reset(other.release());
        }
        return *this;
     }

     T *release() noexcept {
        return std::exchange(m_ptr, nullptr); // Release the object held by uniqueptr and return old ptr
        // T* old = m_ptr;
        // m_ptr = nullptr;
        // return old;
     }

     void reset(T* ptr = nullptr) noexcept {
        T* old = std::exchange(m_ptr, ptr);
        if (old) {
            delete old;
        }
     }

     T* get() const noexcept { return m_ptr; } // get() function
     T *operator->() const noexcept { return m_ptr; } // Arrow operator
     T &operator*() const noexcept { returen *m_ptr; } // Dereference operator
     explicit operator bool() const noexcept { // Allows if(unique_ptr)
        return static_cast<bool>(m_ptr);
     }
      ~unique_ptr() noexcept { // Destructor
        if (m_ptr) {
            delete m_ptr;
        }
     }
    private:
     T *m_ptr;
}

template <class T, class... Args> // Take and number ofargs as a spread and pack them into the given type
unique_ptr<T> make_unique(Args &&...args) { // Make unique perfect forwarding of args
    return unique_ptr<T>(new T(std::forward<Args>(args)...)); // Return a unique_ptr of type T which contains all the args passed
}