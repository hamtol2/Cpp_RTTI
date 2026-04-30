#pragma once

#include <memory>

class CraftObject;
class TypeInfo
{
public:
    using CreateFunc = std::shared_ptr<CraftObject>(*)();

public:
    TypeInfo(const char* name, const TypeInfo* parent, CreateFunc createFunc)
        : className(name), parentType(parent), createFunc(createFunc)
    {
    }

    const char* GetName() const
    {
        return className;
    }

    bool IsChildOf(const TypeInfo* other) const
    {
        for (const TypeInfo* current = this; current; current = current->parentType)
        {
            if (current == other)
            {
                return true;
            }
        }

        return false;
    }

    std::shared_ptr<CraftObject> CreateInstance() const
    {
        if (!createFunc)
        {
            return nullptr;
        }

        return createFunc();
    }

private:
    const char* className = nullptr;
    const TypeInfo* parentType = nullptr;
    CreateFunc createFunc = nullptr;
};