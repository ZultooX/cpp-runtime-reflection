#pragma once

#include <cstddef>

#include <unordered_map>
#include <iostream>
#include <string_view>

struct Property
{
	const char* name;
	unsigned long long offset;
	unsigned long long size;
};

struct TypeInfoBase
{
	virtual const char* GetName() const = 0;
	virtual const Property* GetProperties() const = 0;
	virtual size_t GetPropertyCount() const = 0;

	virtual ~TypeInfoBase() = default;
};

template<typename  T>
struct TypeInfo : TypeInfoBase
{
    static constexpr const char* Name = "Unknown";
    static constexpr Property Properties[] = {};
    static constexpr size_t PropertyCount = 0;

    const char* GetName() const override
    {
        return Name;
    }

    const Property* GetProperties() const override
    {
        return Properties;
    }

    size_t GetPropertyCount() const override
    {
        return PropertyCount;
    }
};


class TypeRegistry
{
public:
    static void Register(const char* name, TypeInfoBase* info)
    {
        GetMap()[std::string(name)] = info;
    }

    static TypeInfoBase* Get(const char* name)
    {
        auto& map = GetMap();
        auto it = map.find(std::string(name));
        return it != map.end() ? it->second : nullptr;
    }

private:
    static std::unordered_map<std::string, TypeInfoBase*>& GetMap()
    {
        static std::unordered_map<std::string, TypeInfoBase*>& map =
            *new std::unordered_map<std::string, TypeInfoBase*>();
        return map;
    }
};

template<typename T>
struct TypeRegistrar
{
    TypeRegistrar()
    {
        static T info;
        TypeRegistry::Register(T::Name, &info);
    }
};

#define NAME(name) static constexpr const char* Name = #name;
#define PROPERTY_COUNT static constexpr size_t PropertyCount = sizeof(Properties) / sizeof(Properties[0]);
#define GETTER_METHODS \
	inline const char* GetName() const override { return Name; }                \
inline const Property* GetProperties() const override { return Properties; }    \
inline size_t GetPropertyCount() const override { return PropertyCount; }