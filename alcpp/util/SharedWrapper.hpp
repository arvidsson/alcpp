#pragma once

#include <memory>

namespace alcpp
{

template <class T>
class SharedWrapper : public std::shared_ptr<T>
{
protected:
    static void nullDeleter(T*) {}
    SharedWrapper() {}
    SharedWrapper(const std::shared_ptr<T> &ptr) : std::shared_ptr<T>(ptr) {}
    SharedWrapper(T *ptr) : std::shared_ptr<T>(ptr) {}
    template <class D> SharedWrapper(T *ptr, D deleter, bool retain = true) : std::shared_ptr<T>(ptr, retain ? deleter : nullDeleter) {}

public:
    T* Get() { return get(); }
};

}