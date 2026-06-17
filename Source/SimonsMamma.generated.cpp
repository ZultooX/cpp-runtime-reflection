
#include "Player.h"

#include "Reflection/ReflectionType.h"

template<>
struct TypeInfo<SimonsMamma> : TypeInfoBase
{
	static constexpr Property Properties[] =
	{
		{ "thisShouldWork", offsetof(SimonsMamma, thisShouldWork), sizeof(int)},
		{ "test", offsetof(SimonsMamma, test), sizeof(int)}
	};

	NAME(SimonsMamma);
	PROPERTY_COUNT;
	GETTER_METHODS;
};

static TypeRegistrar<TypeInfo<SimonsMamma>> SimonsMamma_registrar{};