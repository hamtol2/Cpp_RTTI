#pragma once

#include "TypeInfo.h"

class CraftObject
{
public:
    CraftObject() = default;
    virtual ~CraftObject() = default;

    static const TypeInfo* StaticClass()
    {
        static TypeInfo typeInfo("CraftObject", nullptr, nullptr);
        return &typeInfo;
    }

    virtual const TypeInfo* GetClass() const
    {
        return CraftObject::StaticClass();
    }

    template<typename T>
    bool Is() const
    {
        return GetClass()->IsChildOf(T::StaticClass());
    }
};

#define TYPE_DECLARATIONS(Type, ParentType)                                                \
    using super = ParentType;                                                              \
public:                                                                                    \
    static std::shared_ptr<CraftObject> CreateObject()                                     \
    {                                                                                      \
        return std::make_shared<Type>();                                                   \
    }                                                                                      \
                                                                                           \
    static const ::TypeInfo* StaticClass()                                                 \
    {                                                                                      \
        static ::TypeInfo typeInfo(#Type, ParentType::StaticClass(), &Type::CreateObject); \
        return &typeInfo;                                                                  \
    }                                                                                      \
                                                                                           \
    virtual const ::TypeInfo* GetClass() const override                                    \
    {                                                                                      \
        return Type::StaticClass();                                                        \
    }