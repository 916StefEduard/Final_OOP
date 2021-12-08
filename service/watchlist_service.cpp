#include "watchlist_service.h"
#include "../repository/watchlist_repository.h"
template <typename T,typename U>

void WatchlistService<T,U>::watchlist_add(T movie)
{
    watchlist_repository::repo_add(movie);
}
template <typename T,typename U>
void WatchlistService<T,U>::watchlist_remove(char title[100])
{
    watchlist_repository::repo_removes(title);
}
template <typename T,typename U>
void WatchlistService<T,U>::watchlist_update(char title[100],T new_movie)
{
    watchlist_repository::repo_update(title,new_movie);
}

template <typename T,typename U>
void WatchlistService<T,U>::load_csv(){
    watchlist_file_repository::store_data_from_csv();

}
template <typename T,typename U>
void WatchlistService<T,U>::load_html(){
    watchlist_file_repository::store_data_from_html();

}


template <typename T,typename U>

char* WatchlistService<T,U>::watchlist_get_title(U index){
    return watchlist_repository::repo_get_title(index);
}

template <typename T,typename U>
char* WatchlistService<T,U>::watchlist_get_genre(U index){
    return watchlist_repository::repo_get_genre(index);
}


template <typename T,typename U>
char* WatchlistService<T,U>::watchlist_get_release(U index){
    return watchlist_repository::repo_get_release(index);
}

template <typename T,typename U>
int WatchlistService<T,U>::watchlist_get_likes(U index){
    return watchlist_repository::repo_get_likes(index);
}

template <typename T,typename U>
char* WatchlistService<T,U>::watchlist_get_trailer(U index){
    return watchlist_repository::repo_get_trailer(index);
}
template <typename T,typename U>
int WatchlistService<T,U>::watchlist_get_length(){
    return watchlist_repository::repo_get_length();
}


template class WatchlistService<Movie,int>;