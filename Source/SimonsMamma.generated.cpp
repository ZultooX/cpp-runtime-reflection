#include "C:/Users/zulto/Desktop/MyFiles/Projects/cpp-runtime-reflection/Source/Player.h"
#include "C:/Users/zulto/Desktop/MyFiles/Projects/cpp-runtime-reflection/Source/Reflection/ReflectionCommon.hpp"

template<>
struct TypeInfo<SimonsMamma> : ClassInfoBase
{
	TYPE(SimonsMamma);

	NAME(SimonsMamma);

	PROPERTY(thisShouldWork);
	PROPERTY(test);

	PROPERTY_LIST(
		&thisShouldWork,
		&test
	);

	static constexpr const unsigned long long PropertyCount = 2;
	GETTER_METHODS;
};

static TypeRegistrar<TypeInfo<SimonsMamma>> SimonsMamma_registrar{};
