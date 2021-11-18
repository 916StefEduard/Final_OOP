#include <iostream>
#include "database_repository.h"
#include "../domain/domain.h"
#include "stdlib.h"
#include "string.h"
#include "../validator/repository_validator.h"
using namespace std;


void Repository:: add( Movie element)
{   int count=0;
    for(Movie movie:array) {
        if(strcmp(movie.title,element.title)==0)
            throw RepositoryException("duplicate movie");
    }
    array.push_back(element);
}


void Repository::removes(const string& title){
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


void Repository::update(const string& title,Movie new_movie)
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

vector<Movie> Repository::search(const string&genre){
    std::vector<Movie> searches;
    for(Movie movie1:array){
        if(movie1.genre==genre){
            searches.push_back(movie1);
        }
    }
    return searches;
}



int Repository::get_length()
    {
        return array.size();

    }


char* Repository::get_title(int index){
    return array[index].title;
}


char* Repository::get_genre(int index){
    return array[index].genre;
}


char* Repository::get_release(int index){
    return array[index].release;
}


int Repository::get_likes(int index){
    return array[index].likes;
}


char* Repository::get_trailer(int index){
    return array[index].trailer;
}


int Repository::get_index(char* title){
    int i, position = 0;
    for(Movie movie:array){
        position++;
        if(strcmp(movie.title,title)==0)
            break;
    }
    if(position==0)
        throw RepositoryException("index does not exist");
    return position;
}
