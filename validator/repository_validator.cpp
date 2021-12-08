

#include <stdexcept>
#include "repository_validator.h"


using namespace std;

RepositoryException::RepositoryException(char const* const message) throw()
        : std::runtime_error(message)
{

}

char const * RepositoryException::what() const throw()
{
    return std::runtime_error::what();
}