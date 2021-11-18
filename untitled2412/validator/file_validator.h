#include <exception>
#include <string>
#include <utility>
#include <stdexcept>
#pragma once

class FileExceptions : public std::runtime_error
{
public:
    FileExceptions(char const* const message) throw();
    virtual char const* what() const throw();
};