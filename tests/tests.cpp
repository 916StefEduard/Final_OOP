
#include <cstring>
#include <cassert>
#include "tests.h"
#include "../repository/database_repository.h"


void test_add(){
    Repository repo;
    Movie movie;
    strcpy(movie.title,"ad");
    strcpy(movie.genre,"asd");
    strcpy(movie.release,"12");
    movie.likes=12;
    repo.add(movie);
    assert(strcmp(repo.get_title(0),"ad")==0);
    assert(strcmp(repo.get_genre(0),"asd")==0);
    assert(strcmp(repo.get_release(0),"12")==0);
    assert(repo.get_likes(0)==12);
    assert(repo.get_length()==1);
    repo.removes("ad");
    assert(repo.get_length()==0);
    repo.add(movie);
    Movie movie1;
    strcpy(movie1.title,"bd");
    strcpy(movie1.genre,"bsd");
    strcpy(movie1.release,"22");
    movie1.likes=25;
    repo.update("ad",movie1);
    assert(strcmp(repo.get_title(0),"bd")==0);
    assert(strcmp(repo.get_genre(0),"bsd")==0);
    assert(strcmp(repo.get_release(0),"22")==0);
    assert(repo.get_likes(0)==25);
    assert(repo.get_length()==1);
}




void test_all(){
    test_add();


}