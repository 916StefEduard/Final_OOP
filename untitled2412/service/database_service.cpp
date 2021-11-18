#include <iostream>
#include "../repository/database_repository.h"
#include "database_service.h"
using namespace std;


template <typename T,typename U>
void Service<T,U>::service_add(T movie)
{
    database_file_repository::file_save(movie);
}
template <typename T,typename U>
void Service<T,U>::service_load(){
    database_file_repository::load_data();
}


template <typename T,typename U>
void Service<T,U>::service_store(){
    database_file_repository::store_to_file();
}

template <typename T,typename U>
void Service<T,U>::service_remove(char title[100])
{
    database_file_repository::file_remove(title);
}

template <typename T,typename U>
void Service<T,U>::service_update(char title[100],T new_movie)
{
    database_file_repository::file_update(title, new_movie);
}



template <typename T,typename U>
char* Service<T,U>::service_title(U index){
    Repository::get_title(index);
}

template <typename T,typename U>
char* Service<T,U>::service_genre(U index){
    Repository::get_genre(index);
}

template <typename T,typename U>
char* Service<T,U>::service_release(U index){
    Repository::get_release(index);}


template <typename T,typename U>
int Service<T,U>::service_likes(U index){
    Repository::get_likes(index);}


template <typename T,typename U>
char* Service<T,U>::service_trailer(U index){
    Repository::get_trailer(index);}


template <typename T,typename U>
int Service<T,U>::service_index(char* title){
    Repository::get_index(title);
}


template <typename T,typename U>
int Service<T,U>::service_length()
{
    Repository::get_length();
}

template class Service<Movie,int>;

