#pragma once

#include "ReflectionType.h"

#define PROPERTY_LIST(...) static constexpr const Property* Properties[] = { __VA_ARGS__ };

#define TYPE(type) using TYPE = type;

#define EXPAND(x) x

#define PROPERTY(member) \
inline static const TypedProperty<TYPE, decltype(TYPE::EXPAND(member))> member \
{ \
#member, \
sizeof(decltype(TYPE::EXPAND(member))), \
&TYPE::EXPAND(member) \
};

#define NAME(name) static constexpr const char* Name = #name;
#define GETTER_METHODS \
	inline const char* GetName() const override { return Name; }                \
inline const Property* const* GetProperties() const override { return Properties; }    \
inline size_t GetPropertyCount() const override { return PropertyCount; }
