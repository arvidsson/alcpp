#pragma once

#include <memory>

namespace alcpp
{

template <class T>
class SharedPtr : public std::shared_ptr<T>
{
protected:
    static void nullDeleter(T*) {}
    SharedPtr() {}
    SharedPtr(const std::shared_ptr<T> &ptr) : std::shared_ptr<T>(ptr) {}
    SharedPtr(T *ptr) : std::shared_ptr<T>(ptr) {}
    template <class D> SharedPtr(T *ptr, D deleter, bool retain = true) : std::shared_ptr<T>(ptr, retain ? deleter : nullDeleter) {}

public:
    T* Get() const { return get(); }
};

}