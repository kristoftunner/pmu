#pragma once
#include <memory>

namespace Pmu
{
    template<typename T>
    using SPtr = std::shared_ptr<T>;   
    template<typename T, typename ... Args>
    constexpr SPtr<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using SCPtr = std::shared_ptr<T const>;
}

#include "Log.hpp"