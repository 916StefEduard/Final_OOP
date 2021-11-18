

#include <stdexcept>
#include "file_validator.h"


using namespace std;

FileExceptions::FileExceptions(char const* const message) throw()
        : std::runtime_error(message)
{
}

char const * FileExceptions::what() const throw()
{
    return std::runtime_error::what();
}