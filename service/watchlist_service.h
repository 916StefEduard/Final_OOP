#pragma once
#include <iostream>
#include "../repository/watchlist_repository.h"
#include "../repository/watchlist_file_repository.h"
using namespace std;

template <typename T,typename U>
class WatchlistService: public watchlist_file_repository{
public:
    WatchlistService()=default;
    void watchlist_add(T movie);
    void watchlist_update(char title[100],T new_movie);
    void watchlist_remove(char title[100]);
    char* watchlist_get_release(U index);
    char* watchlist_get_title(U index);
    char* watchlist_get_genre(U index);
    int watchlist_get_likes(U index);
    char* watchlist_get_trailer(U index);
    int watchlist_get_length();
    void load_csv();

    void load_html();
};