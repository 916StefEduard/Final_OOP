#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
#include "watchlist_file_repository.h"

using namespace std;

std::vector<string> split_string(const std::string &s, char delimitator) {
    std::vector<string> elements;
    std::stringstream ss(s);
    std::string number;
    while(std::getline(ss, number, delimitator)) {
        elements.push_back(number);
    }
    return elements;
}

void watchlist_file_repository::load_data_from_csv(){
    fstream new_file;
    Movie movie;
    int i;
    new_file.open("../data/watchlist.csv");
    if (new_file.is_open()) {
        string line;
        while (getline(new_file, line)) {
            std::vector<string> strings = split_string(line, ';');
            i=0;
            while (i < strings.size()) {
                const char * title=strings[0].c_str();
                strcpy(movie.title,title);
                const char * genre=strings[1].c_str();
                strcpy(movie.genre,genre);
                const char * release=strings[2].c_str();
                strcpy(movie.release,release);
                movie.likes=0;
                const char * trailer=strings[4].c_str();
                strcpy(movie.trailer,trailer);
                i++;
            }
            watchlist_repository::repo_add(movie);
        }
        new_file.close();
    }
}

void watchlist_file_repository::store_data_from_csv(){
    ofstream new_file;
    string element;
    int i;
    new_file.open("../data/watchlist.csv");
    if(new_file.is_open()) {
        i=0;
        while(i<watchlist_repository::repo_get_length()){
            element = "";
            element += string(watchlist_repository::repo_get_title(i));
            element += string(";");
            element += string(watchlist_repository::repo_get_genre(i));
            element += string(";");
            element += string(watchlist_repository::repo_get_release(i));
            element += string(";");
            element += string(to_string(watchlist_repository::repo_get_likes(i)));
            element += string(";");
            element += string(watchlist_repository::repo_get_trailer(i));
            new_file << element;
            new_file << "\n";
            i++;
        }
    }
}

void watchlist_file_repository::store_data_from_html(){
    ofstream file;
    string element;
    int i;
    file.open("../data/watchlists.html");
    if(file.is_open()) {
        i=0;
        file<<"<!DOCTYPE html>"<<endl<<"<html>"<<endl<<"<head>"<<endl<<"    <title>Movies</title>"<<endl<<"</head>"<<endl<<"<body>"<<endl<<"<table border=1>"<<endl;
        file<<" <tr>"<<endl<<"        <td>Title</td>"<<endl<<"          <td>Genre</td>"<<endl<<"       <td>Release</td>"<<endl<<"        <td>Likes</td>"<<endl;
        file<<"     <td>Trailer</td>"<<endl<<"   </tr>"<<endl<<"    <tr>"<<endl;
        for(i=0;i<watchlist_repository::repo_get_length();++i){
            file<<"   <td>"<<watchlist_repository::repo_get_title(i)<<"</td>"<<endl<<"     <td>"<<watchlist_repository::repo_get_genre(i)<<"</td>"<<endl<<"        <td>"<<watchlist_repository::repo_get_release(i)<<"</td>"<<endl<<"    <td>"<<watchlist_repository::repo_get_likes(i)<<"</td>"<<endl<<"    <td><a href="<<watchlist_repository::repo_get_trailer(i)<<">Link</a></td>";
            file<<endl<<"</tr>"<<endl<<"<tr>";
        }
        file<<"</table>"<<endl<<"</body>"<<endl<<"</html>";
    }
}

void watchlist_file_repository::load_data_from_html(){
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
            auto strings=split_string(string,'>');
            auto strings1=split_string(strings[1],'<');
            titles=strings1[0];
            new_file>>string>>title>>genre>>release>>likes;
            strings=split_string(string,'>');
            strings1=split_string(strings[1],'<');
            genres=strings1[0];
            strings=split_string(title,'>');
            strings1=split_string(strings[1],'<');
            releases=strings1[0];
            strings=split_string(genre,'>');
            strings1=split_string(strings[1],'<');
            likess=atoi(strings1[0].c_str());
            strings=split_string(likes,'=');
            strings1=split_string(strings[1],'>');
            trailers=strings1[0];
            new_file>>string;
            strcpy(movie.title,titles.c_str());
            strcpy(movie.genre,genres.c_str());
            strcpy(movie.release,releases.c_str());
            strcpy(movie.trailer,trailers.c_str());
            movie.likes=0;
            watchlist_repository::repo_add(movie);
            i++;
        }
    }
}


void watchlist_file_repository::file_save(Movie movie){
        watchlist_repository::repo_add(movie);
}

void watchlist_file_repository::file_remove(const std::string& title){
    watchlist_repository::repo_removes(title);
}