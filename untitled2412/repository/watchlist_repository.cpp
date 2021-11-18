#include "watchlist_repository.h"
#include "../domain/domain.h"
#include <iostream>
#include "../validator/repository_validator.h"
#include "stdlib.h"
#include "string.h"
using namespace std;


void watchlist_repository:: repo_add(Movie element)
{   int count=0;
    for(Movie movie:array) {
        if(strcmp(movie.title,element.title)==0)
            throw RepositoryException("duplicate movie");
    }
    array.push_back(element);
}


void watchlist_repository::repo_removes(const string& title){
    int position=0,count=0;
    for(Movie movie:array){
        if(movie.title==title) {
            count++;
            break;
        }
        position++;
    }
    if(count==0)
        throw RepositoryException("the movie does not exist");
    else
        array.erase(array.begin()+position);

}


void watchlist_repository::repo_update(const char* title, Movie new_movie)
{int i,position=0,count=0;
    for(Movie movie:array){
        if(movie.title==title) {
            count++;
            break;
        }
        position++;
    }
    if(count==0)
        throw RepositoryException("the movie does not exist");
    else
        array[position]=new_movie;
}


char* watchlist_repository::repo_get_title(int index){
    return array[index].title;
}

char* watchlist_repository::repo_get_genre(int index){
    return array[index].genre;
}

char* watchlist_repository::repo_get_release(int index){
    return array[index].release;
}

int watchlist_repository::repo_get_likes(int index){
    return array[index].likes;
}

char* watchlist_repository::repo_get_trailer(int index){
    return array[index].trailer;
}

int watchlist_repository::repo_get_length()
{
    return array.size();

}