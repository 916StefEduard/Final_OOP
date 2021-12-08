
#ifndef UNTITLED4_DATABASE_FILE_REPOSITORY_H
#define UNTITLED4_DATABASE_FILE_REPOSITORY_H
#include "../repository/database_repository.h"

class database_file_repository: public Repository {
public:

    void load_data();

    void file_save(Movie movie);

    void file_remove(const std::string &title);

    void file_update(const std::string &title, Movie new_movie);

    void store_to_file();
};


#endif //UNTITLED4_DATABASE_FILE_REPOSITORY_H
