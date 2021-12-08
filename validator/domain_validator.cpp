
#include <typeinfo>
#include <stdexcept>
#include <iostream>
#include <cstring>
#include "repository_validator.h"
#include "domain_validator.h"
#include "../domain/domain.h"
#include "string.h"
using namespace std;

DomainException::DomainException(char const* const message) throw()
        : std::runtime_error(message)
{

}

char const * DomainException::what() const throw()
{
    return std::runtime_error::what();
}

void Validator::validate(Movie movie) {
    const char *error = nullptr;
    if(movie.likes<=0)
        error="Negative number of likes";
    if(error!= nullptr)
        throw DomainException(error);
}