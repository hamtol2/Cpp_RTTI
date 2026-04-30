#pragma once

#include <memory>

class CraftObject
{
public:
	CraftObject() = default;
	virtual ~CraftObject() = default;

	// 현재 객체의 타입 ID 반환.
	virtual size_t GetType() const = 0;

	// 타입 비교 함수.
	virtual bool Is(size_t id) const
	{
		return false;
	}

	// 템플릿 기반 타입 확인.
	template<typename T>
	bool IsTypeOf() const
	{
		return Is(T::TypeId());
	}

	// 안전한 형변환(캐스팅) 함수.
	template<typename T, typename U>
	static std::shared_ptr<T> Cast(const std::shared_ptr<U>& object)
	{
		if (!object)
		{
			return nullptr;
		}
		if (object->Is(T::TypeId()))
		{
			return std::static_pointer_cast<T>(object);
		}

		return nullptr;
	}
};

#define TYPE_DECLARATIONS(Type, ParentType)                         \
    using super = ParentType;                                       \
protected:                                                          \
    static size_t TypeIdClass()                                     \
    {                                                               \
        static int runtimeTypeId = 0;                               \
        return reinterpret_cast<size_t>(&runtimeTypeId);            \
    }                                                               \
public:                                                             \
    static size_t TypeId()                                          \
    {                                                               \
        return Type::TypeIdClass();                                 \
    }                                                               \
    virtual size_t GetType() const override                         \
    {                                                               \
        return Type::TypeIdClass();                                 \
    }                                                               \
    virtual bool Is(size_t id) const override                       \
    {                                                               \
        return (id == TypeIdClass()) ? true : ParentType::Is(id);   \
    }