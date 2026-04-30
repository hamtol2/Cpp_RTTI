#pragma once

#include "Core/TypeInfo.h"
#include <memory>

class CraftObject
{
public:
	CraftObject() = default;
	virtual ~CraftObject() = default;

	static const TypeInfo* StaticClass()
	{
		static TypeInfo typeInfo("CraftObject", nullptr);
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

#define TYPE_DECLARATIONS(Type, ParentType)                            \
using super = ParentType;                                              \
public:                                                                \
    static const TypeInfo* StaticClass()                               \
    {                                                                  \
        static TypeInfo typeInfo(#Type, ParentType::StaticClass());    \
        return &typeInfo;                                              \
    }                                                                  \
                                                                       \
    virtual const TypeInfo* GetClass() const override                  \
    {                                                                  \
        return Type::StaticClass();                                    \
    }