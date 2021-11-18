#pragma once
#include "../repository/watchlist_repository.h"

class watchlist_file_repository:public watchlist_repository {

public:
    void store_data_from_csv();
    void file_save(Movie movie);
    void file_remove(const std::string &title);
    void load_data_from_csv();
    void store_data_from_html();

    void load_data_from_html();
};