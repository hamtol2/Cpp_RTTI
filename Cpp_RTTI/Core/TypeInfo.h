#pragma once

class TypeInfo
{
public:
	TypeInfo(const char* name, const TypeInfo* parent)
		: className(name), parentType(parent)
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

private:
	const char* className = nullptr;
	const TypeInfo* parentType = nullptr;
};