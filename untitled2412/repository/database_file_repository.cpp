#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>
#include "database_file_repository.h"
#include "../validator/file_validator.h"
using namespace std;

std::vector<string> split(const std::string &s, char delimitator) {
    std::vector<string> elements;
    std::stringstream ss(s);
    std::string number;
    while(std::getline(ss, number, delimitator)) {
        elements.push_back(number);
    }
    return elements;
}

void database_file_repository::load_data() {
    fstream new_file;
    Movie movie;
    int i;
    new_file.open("../data/database.txt");
    if (new_file.is_open()) {
        string line;
        while (getline(new_file, line)) {
            std::vector<string> strings = split(line, ';');
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
            Repository::add(movie);
        }
        new_file.close();
    }
    else
        throw FileExceptions("cannot open the file");
}

void database_file_repository::store_to_file(){
    ofstream new_file;
    string element;
    int i;
    new_file.open("../data/database.txt");
    if(new_file.is_open()) {
        i=0;
        while(i < Repository::get_length()) {
            element = "";
            element += string(Repository::get_title(i));
            element += string(";");
            element += string(Repository::get_genre(i));
            element += string(";");
            element += string(Repository::get_release(i));
            element += string(";");
            element += string(to_string(Repository::get_likes(i)));
            element += string(";");
            element += string(Repository::get_trailer(i));
            new_file << element;
            new_file << "\n";
            i++;
        }
    }
    else
        throw FileExceptions("cannot open the file");
    new_file.close();
}

void database_file_repository::file_save(Movie movie){
    Repository::add(movie);

}

void database_file_repository::file_remove(const std::string& title){
    Repository::removes(title);
}

void database_file_repository::file_update(const std::string& title, Movie new_movie){
    Repository::update(title,new_movie);
}


