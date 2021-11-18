#pragma once
#include <iostream>
#include "../service/database_service.h"
#include "../service/watchlist_service.h"
using namespace std;

template <typename T,typename U>
class UI:public Service<T,U>,public WatchlistService<T,U>{
public:
    UI()=default;
    void ui_add();
    void ui_delete();
    void ui_update();
    void ui_print();
    void run_menu();
    void print_administrator_menu();
    void print_main_menu();
    void print_choose_menu();
    void print_user_menu();
    void ui_get_genre();
    void ui_print_watchlist();
    void ui_delete_watchlist();
    void ui_open_csv();
    void print_first_menu();


    void ui_open_html();
};