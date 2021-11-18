#pragma once

#include <vector>
#include <string>
#include "../domain/domain.h"
class watchlist_repository{
private:
    std::vector<Movie> array;

public:
    void repo_add(Movie element);
    void repo_update(const char *title, Movie new_movie);

    char *repo_get_title(int index);
    int repo_get_length();
    char *repo_get_trailer(int index);
    int repo_get_likes(int index);
    char *repo_get_release(int index);
    char *repo_get_genre(int index);
    void repo_removes(const std::string &title);

};