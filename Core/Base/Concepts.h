// Concepts.h
#ifndef START_APP_NAMESPACE_CONCEPTS_H
#define START_APP_NAMESPACE_CONCEPTS_H

#include <string>
#include <type_traits>

#include <QString>

namespace START_APP_NAMESPACE
{
    template<typename EnumArg>
    concept IsEnum = std::is_enum_v<EnumArg>;

    template<typename StrArg>
    concept IsString =
        std::same_as<StrArg, std::string>   ||
        std::same_as<StrArg, QString>;

    template<typename T>
    concept HasToString = requires(T t) {
        { t.toString() } -> std::convertible_to<std::string>;
    } || requires(T t) {
        { t.toString() } -> std::convertible_to<QString>;
    };

    template<typename T, typename StrArg>
    concept HasFromString = IsString<StrArg> && requires(T t, StrArg arg) {
        { t.fromString(arg) } -> std::convertible_to<T>;
    };

}

#endif //START_APP_NAMESPACE_CONCEPTS_H
