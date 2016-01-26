#pragma once

#include <type_traits>

namespace alcpp
{

/*
    Converts value of enum class to underlying integral type.
*/
template <typename T>
auto ToIntegral(T value) -> typename std::underlying_type<T>::type
{
    return static_cast<typename std::underlying_type<T>::type>(value);
}

}