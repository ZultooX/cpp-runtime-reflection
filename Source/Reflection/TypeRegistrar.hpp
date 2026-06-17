#pragma once

#include "ClassRegistry.h"

template<typename T>
struct TypeRegistrar
{
    TypeRegistrar();
};

template<typename T>
inline TypeRegistrar<T>::TypeRegistrar()
{
    static T info;
    ClassRegistry::Register(T::Name, &info);
}