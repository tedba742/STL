#ifndef COUNTED_PTR_HPP
#define COUNTED_PTR_HPP

/* Class for counted reference semantics
 * - Deletes the object to which it refers when the last CountedPtr
 *   that refers to it is destroyed
 */
template <class T>
class CountedPtr {
private:
    T* ptr;     // Pointer to the value
    long* count;    // Shared number of owners

public:
    // Initialize pointer with existing pointer
    // - Requires that the pointer p is a return value of new
    explicit CountedPtr(T* p = 0)
        : ptr(p), count(new long(1)) {}

    // Copy pointer (one more owner)
    CountedPtr(const CountedPtr<T>& p) throw()
        : ptr(p.ptr), count(p.count) {
        ++*count;
    }

    // Destructor (delete value if this was the last owner)
    ~CountedPtr() throw() {
        dispose();
    }

    // Assignment (unshare old and share new value)
    CountedPtr<T>& operator=(const CountedPtr<T>& p) throw() {
        if (this != &p) {
            dispose();
            ptr = p.ptr;
            count = p.count;
            ++*count;
        }
        return *this;
    }

    // Access the value to which the pointer refers
    T& operator*() const throw() {
        return *ptr;
    }

    T* operator->() const throw() {
        return ptr;
    }

private:
    void dispose() {
        if (--*count == 0) {
            delete count;
            delete ptr;
        }
    }
};

#endif /* COUNTED_PTR_HPP */
