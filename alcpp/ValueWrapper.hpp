#pragma once

namespace alcpp
{

template <class T>
class ValueWrapper
{
public:
    operator T &() { return value; }
    operator const T &() const { return value; }
    T& Get() { return value; }
    const T& Get() const { return value; }

protected:
    ValueWrapper() {}
    ValueWrapper(const T &value) : value(value) {}

private:
    T value;
};

}