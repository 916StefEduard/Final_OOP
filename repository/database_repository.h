
#ifndef UNTITLED4_DATABASE_REPOSITORY_H
#define UNTITLED4_DATABASE_REPOSITORY_H
#include "../domain/domain.h"
#include <vector>
#include <string>
class Repository{
    std::vector<Movie> array;

public:
    void add(Movie element);

public:
    char *get_title(int index);
    char *get_genre(int index);
    char *get_release(int index);
    int get_likes(int index);
    char *get_trailer(int index);
    int get_index(char *title);
    void removes(const std::string &title);
    int get_length();
    void update(const std::string &title, Movie new_movie);

    std::vector<Movie> search(const std::string &genre);
};


#endif
