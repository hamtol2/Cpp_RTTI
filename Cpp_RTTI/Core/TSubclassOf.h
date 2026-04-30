#pragma once

#include "TypeInfo.h"
#include <type_traits>

class CraftObject;

template<typename T,
    typename = std::enable_if_t<std::is_base_of_v<CraftObject, T>>>
class TSubclassOf
{
public:
    TSubclassOf() = default;
    TSubclassOf(const ::TypeInfo* typeInfo)
    {
        if (typeInfo && typeInfo->IsChildOf(T::StaticClass()))
        {
            this->typeInfo = typeInfo;
        }
    }

    const ::TypeInfo* Get() const
    {
        return typeInfo;
    }

    bool IsValid() const
    {
        return typeInfo != nullptr;
    }

private:
    const TypeInfo* typeInfo = nullptr;
};