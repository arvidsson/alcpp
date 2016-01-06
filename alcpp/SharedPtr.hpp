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
    template <class D> SharedPtr(T *ptr, D deleter) : std::shared_ptr<T>(ptr, deleter) {}
    template <class D> SharedPtr(T *ptr, bool managed, D deleter) : std::shared_ptr<T>(ptr, managed ? deleter : nullDeleter) {}
    SharedPtr(T *ptr) : std::shared_ptr<T>(ptr) {}
    SharedPtr(const std::shared_ptr<T> &ptr) : std::shared_ptr<T>(ptr) {}
};

}