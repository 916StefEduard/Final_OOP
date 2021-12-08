#pragma once
#include <iostream>
#include "../repository/database_repository.h"
#include "../repository/database_file_repository.h"
using namespace std;

template <typename T,typename U>
class Service:public database_file_repository{
public:
    Service()=default;
    void service_add(T movie);
    void service_update(char title[100],T new_movie);
    void service_remove(char title[100]);
    char *service_title(U index);
    char *service_genre(U index);
    char *service_release(U index);
    int service_likes(U index);
    char *service_trailer(U index);
    int service_length();
    int service_index(U index);
    int service_index(char *title);
    void service_load();

    void service_store();
};