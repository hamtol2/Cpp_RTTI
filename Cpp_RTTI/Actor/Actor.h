#pragma once

#include "Core/CraftObject.h"
#include "Core/TSubclassOf.h"

class Actor : public CraftObject
{
	TYPE_DECLARATIONS(Actor, CraftObject)
};

template<typename T,
    typename = std::enable_if_t<std::is_base_of_v<CraftObject, T>>>
std::shared_ptr<T> SpawnActor(TSubclassOf<T> classType)
{
    if (!classType.IsValid())
    {
        return nullptr;
    }

    std::shared_ptr<CraftObject> object = classType.Get()->CreateInstance();

    if (!object)
    {
        return nullptr;
    }

    return std::static_pointer_cast<T>(object);
}