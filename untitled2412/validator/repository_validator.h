#include <exception>
#include <string>
#include <utility>
#include <stdexcept>
#pragma once

class RepositoryException : public std::runtime_error
{
public:
    RepositoryException(char const* const message) throw();
    virtual char const* what() const throw();
};