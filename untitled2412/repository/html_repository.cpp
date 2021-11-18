//
// Created by User on 5/18/2021.
//

#include "html_repository.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
#include <validator/repository_validator.h>
#include "watchlist_file_repository.h"

using namespace std;

std::vector<string> split_strings(const std::string &s, char delimitator) {
    std::vector<string> elements;
    std::stringstream ss(s);
    std::string number;
    while(std::getline(ss, number, delimitator)) {
        elements.push_back(number);
    }
    return elements;
}



void html_repository::store_html(){
    fstream file;
    string element;
    int i;
    file.open("../data/watchlists.html");
    if(file.is_open()) {
        i=0;
        file<<"<!DOCTYPE html>"<<endl<<"<html>"<<endl<<"<head>"<<endl<<"    <title>Movies</title>"<<endl<<"</head>"<<endl<<"<body>"<<endl<<"<table border=1>"<<endl;
        file<<" <tr>"<<endl<<"        <td>Title</td>"<<endl<<"          <td>Genre</td>"<<endl<<"       <td>Release</td>"<<endl<<"        <td>Likes</td>"<<endl;
        file<<"     <td>Trailer</td>"<<endl<<"   </tr>"<<endl<<"    <tr>"<<endl;
        for(i=0;i<arrays.size();++i){
            file<<"   <td>"<<arrays[i].title<<"</td>"<<endl<<"     <td>"<<arrays[i].genre<<"</td>"<<endl<<"        <td>"<<arrays[i].release<<"</td>"<<endl<<"    <td>"<<arrays[i].likes<<"</td>"<<endl<<"    <td><a href="<<arrays[i].trailer<<">Link</a></td>";
            file<<endl<<"</tr>"<<endl<<"<tr>";
        }
        file<<"</table>"<<endl<<"</body>"<<endl<<"</html>";
    }
}

void html_repository::load_html(){
    fstream new_file;
    std::string titles,genres,releases,likess,trailers;
    std::string string,title,genre,release,likes,trailer;
    int i;
    new_file.open("../data/watchlists.html");
    if(new_file.is_open()){
        new_file>>string>>title>>genre>>release>>likes>>trailer;
        new_file>>string>>title>>genre>>release>>likes>>trailer;
        new_file>>string>>title>>genre>>release;
        i=0;
        while(i<10) {
            Movie movie;
            new_file >> title>>string;
            if(title=="<tr></table>"){
                break;
            }
            auto strings=split_strings(string,'>');
            auto strings1=split_strings(strings[1],'<');
            titles=strings1[0];
            new_file>>string>>title>>genre>>release>>likes;
            strings=split_strings(string,'>');
            strings1=split_strings(strings[1],'<');
            genres=strings1[0];
            strings=split_strings(title,'>');
            strings1=split_strings(strings[1],'<');
            releases=strings1[0];
            strings=split_strings(genre,'>');
            strings1=split_strings(strings[1],'<');
            likess=atoi(strings1[0].c_str());
            strings=split_strings(likes,'=');
            strings1=split_strings(strings[1],'>');
            trailers=strings1[0];
            new_file>>string;
            strcpy(movie.title,titles.c_str());
            strcpy(movie.genre,genres.c_str());
            strcpy(movie.release,releases.c_str());
            strcpy(movie.trailer,trailers.c_str());
            movie.likes=0;
            arrays.push_back(movie);
            i++;
        }
    }
}
char* html_repository::html_title(int index){
    return arrays[index].title;
}


char* html_repository::html_genre(int index){
    return arrays[index].genre;
}


char* html_repository::html_release(int index){
    return arrays[index].release;
}


int html_repository::html_likes(int index){
    return arrays[index].likes;
}


char* html_repository::html_trailer(int index){
    return arrays[index].trailer;
}



int html_repository::html_length(){
    return arrays.size();
}


void html_repository::html_add(Movie movie){
    int count=0;
    for(Movie movies:arrays) {
        if(strcmp(movies.title,movie.title)==0)
            throw RepositoryException("duplicate movie");
    }
    arrays.push_back(movie);
}

void html_repository::html_remove(const std::string& title){
    int position=0,count=0;
    for(Movie movie:arrays){
        if(movie.title==title) {
            count++;
            break;
        }
        position++;
    }
    if(count==0)
        throw RepositoryException("the movie does not exist");
    else
        arrays.erase(arrays.begin()+position);
}