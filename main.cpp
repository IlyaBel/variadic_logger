#include <iostream>
#include <sstream>

template <typename T>
void Log(std::stringstream& ss, const T& first){
    ss << first;
}

template <typename T, typename... Types>
void Log(std::stringstream& ss, const T& first, const Types&... args){
    ss << first;
    Log(ss, args...);
}

template <typename Logger, typename... Types>
void Log(Logger& logger, const Types&... args){
    std::stringstream stream;
    Log(stream, args...);
    logger << stream.str();
}

//Our custom class for errors
class Error{
private:
    using error_code_type = int;
    const error_code_type error_code_;

public:
    Error(error_code_type error_code_0) : error_code_(error_code_0) {}

    error_code_type getErrorCode() const {
        return error_code_;
    }
};

//How to put error information into stream
std::ostream & operator << (std::ostream &stream, const Error& error){
    stream << "Error code: "<< error.getErrorCode();
    return stream;
}

int main()
{
    Log(std::cout, "An error occured!\nTimestamp: ", time(NULL), "\nError desctiption:\n", Error(1), "\n");

    return 0;
}
