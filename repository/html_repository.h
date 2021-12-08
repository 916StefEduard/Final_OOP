//
// Created by User on 5/18/2021.
//

#ifndef HELLOWORLD_HTML_REPOSITORY_H
#define HELLOWORLD_HTML_REPOSITORY_H


#include "watchlist_repository.h"

class html_repository{
private:
    std::vector<Movie> arrays;
public:



    void html_add(Movie movie);

    void html_remove(const std::string &title);

    int html_length();

    char *html_title(int index);

    char *html_genre(int index);

    char *html_release(int index);

    int html_likes(int index);

    char *html_trailer(int index);

    void store_html();

    void load_html();
};


#endif //HELLOWORLD_HTML_REPOSITORY_H
