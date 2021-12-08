#include <exception>
#include <string>
#include <utility>
#include <stdexcept>
#include "../domain/domain.h"

#pragma once

class DomainException : public std::runtime_error
{
public:
    DomainException(char const* const message) throw();
    virtual char const* what() const throw();
};


class Validator{
public:
    static void validate(Movie movie);

};