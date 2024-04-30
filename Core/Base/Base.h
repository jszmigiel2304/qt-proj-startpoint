// LoggedAction.h
#ifndef START_APP_NAMESPACE_BASE_H
#define START_APP_NAMESPACE_BASE_H

#include <QMetaEnum>

#include "Concepts.h"
#include "../Base/Definitions.h"

namespace START_APP_NAMESPACE
{
    class Base {
    public:
        template<typename T>
            requires HasToString<T>
        static std::string toString(const T& obj) {
            return obj.toString();
        }

        template<typename EnumT>
            requires IsEnum<EnumT>
        static std::string toString(EnumT& obj) {
            QMetaEnum metaEnum = QMetaEnum::fromType<EnumT>();
            return metaEnum.valueToKey(static_cast<int>(obj));
        }
    };
}

#endif //START_APP_NAMESPACE_BASE_H
