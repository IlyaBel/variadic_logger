#ifndef VARIADIC_LOGGER_H
#define VARIADIC_LOGGER_H

#include <sstream>

template <typename T>
void Join(std::stringstream& ss, const T& first){
    ss << first;
}

template <typename T, typename... Types>
void Join(std::stringstream& ss, const T& first, const Types&... args){
    ss << first;
    Join(ss, args...);
}

template <typename... Types>
std::string Join(const Types&... args){
    std::stringstream stream;
    Join(stream, args...);
    return stream.str();
}

template <typename Logger, typename... Types>
void Log(Logger& logger, const Types&... args){
    logger << Join(args...);
}

#endif // VARIADIC_LOGGER_H
