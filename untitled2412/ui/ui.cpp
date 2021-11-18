#include <iostream>
#include "../repository/database_repository.h"
#include "ui.h"
#include "string.h"
#include "windows.h"
#include "../service/watchlist_service.h"
#include "../validator/repository_validator.h"
#include "../validator/domain_validator.h"
#include "../validator/file_validator.h"
using namespace std;

template <typename T,typename U>
void UI<T,U>::ui_add() {
    Movie movie;
    std::cout<<"Title=";
    std::cin>>movie.title;
    std::cout<<"Genre=";
    std::cin>>movie.genre;
    std::cout<<"Trailer=";
    std::cin>>movie.trailer;
    std::cout<<"Number of Likes=";
    std::cin>>movie.likes;
    std::cout<<"Year of Release=";
    std::cin>>movie.release;
    Validator::validate(movie);
    Service<T,U>::service_add(movie);
}

template <typename T,typename U>
void UI<T,U>::ui_print_watchlist(){
    std::cout<<std::endl;
    int i=0;
    while(i<WatchlistService<T,U>::watchlist_get_length()){
        std::cout<<"Title:"<<WatchlistService<T,U>::watchlist_get_title(i)<<" Genre:"<<WatchlistService<T,U>::watchlist_get_genre(i)<<" Trailer:"<<WatchlistService<T,U>::watchlist_get_trailer(i)<<" Likes:"<<WatchlistService<T,U>::watchlist_get_likes(i)<<" Release:"<<WatchlistService<T,U>::watchlist_get_release(i)<<std::endl;
        i++;
    }

}

template <typename T,typename U>
void UI<T,U>::ui_delete_watchlist(){
    Movie movie;
    Movie movie1;
    int index,likes;
    std::cout<<"Title:";
    std::cin>>movie.title;
    WatchlistService<T,U>::watchlist_remove(movie.title);
    std::cout<<"Like the movie"<<std::endl;
    std::cout<<"1.Yes     2.No"<<std::endl;
    std::cout<<"command=";
    std::cin>>movie.likes;
    if(movie.likes==1) {
        index=Service<T,U>::service_index(movie.title);
        strcpy(movie1.title,Service<T,U>::service_title(index));
        strcpy(movie1.genre,Service<T,U>::service_genre(index));
        strcpy(movie1.trailer,Service<T,U>::service_trailer(index));
        strcpy(movie1.release,Service<T,U>::service_release(index));
        likes=Service<T,U>::service_likes(index);
        likes++;
        movie1.likes=likes;
        Service<T, U>::service_update(movie.title,movie1);

    }
}
template <typename T,typename U>
void UI<T,U>::ui_delete() {
    Movie movie;
    std::cout<<"Title=";
    std::cin>>movie.title;
    Service<T,U>::service_remove(movie.title);
}
template <typename T,typename U>
void UI<T,U>::ui_update() {
    Movie movie;
    Movie new_movie;
    std::cout<<"Title=";
    std::cin>>movie.title;
    std::cout<<"New Title=";
    std::cin>>new_movie.title;
    std::cout<<"New Genre=";
    std::cin>>new_movie.genre;
    std::cout<<"New Trailer=";
    std::cin>>new_movie.trailer;
    std::cout<<"Number of Likes=";
    std::cin>>new_movie.likes;
    std::cout<<"Year of Release=";
    std::cin>>new_movie.release;
    Validator::validate(new_movie);
    Service<T,U>::service_update(movie.title,new_movie);
}

template<typename T, typename U>
void UI<T, U>::ui_open_csv() {
    string file_name;
    file_name="../data/watchlist.csv";
    file_name = "notepad \"" + file_name + "\"";
    system(file_name.c_str());
}

template<typename T, typename U>
void UI<T,U>::ui_open_html(){
    const char*  strWebPage;
    strWebPage = "file:///C:\\programming\\untitled2\\data\\watchlists.html";
    ShellExecute(NULL, "open", "C:\\Program Files\\Internet Explorer\\iexplore.exe", strWebPage, NULL, SW_SHOWNORMAL);

}

template <typename T,typename U>
void UI<T,U>::ui_print() {
    int i=0;
    while (i < Service<T,U>::get_length()) {
        std::cout <<"Title:"<< Service<T,U>::service_title(i) << " Genre:"<<Service<T,U>::service_genre(i) <<" Year of release:"<< Service<T,U>::service_release(i) <<" Number of likes:"<< Service<T,U>::service_likes(i) << " Trailer:"<<Service<T,U>::service_trailer(i)<<std::endl;
        i++;
    }
    std::cout<<std::endl;
}

void open_website (char * cpURL)
{
    ShellExecute (NULL, "open", cpURL, NULL, NULL, SW_SHOWNORMAL);
}

template <typename T,typename U>
void UI<T,U>::ui_get_genre(){
    int answer,checks;
    std::string str;
    bool done= false;
    Movie movie;
    Movie movie1;
    std::cout<<"Pick Genre:";
    std::cin>>movie.genre;
    while(!done) {
        int i=0;
        while( i < Service<T, U>::service_length()) {
            if (strcmp(Service<T, U>::service_genre(i), movie.genre) == 0) {
                open_website(Service<T,U>::service_trailer(i));
                std::cout << "Title:" << Service<T, U>::service_title(i) << " Genre:"
                          << Service<T, U>::service_genre(i) << " Trailer:" << Service<T, U>::service_trailer(i)
                          << " Likes:" << Service<T, U>::service_likes(i) << " Release:"<< Service<T,U>::service_release(i) << std::endl;
                strcpy(movie1.genre, Service<T, U>::service_genre(i));
                strcpy(movie1.title, Service<T, U>::service_title(i));
                strcpy(movie1.trailer, Service<T, U>::service_trailer(i));
                strcpy(movie1.release, Service<T, U>::service_release(i));
                movie1.likes = Service<T, U>::service_likes(i);
                print_choose_menu();
                std::cout<<"command=";
                std::cin >> answer;
                if (answer == 1)
                   WatchlistService<T,U>::watchlist_add(movie1);
                if(answer==3){
                    done= true;
                    break;
                }
            }
            i++;
        }
    }
}


template <typename T,typename U>
void UI<T,U>::print_main_menu(){
    std::cout<<std::endl;
    std::cout<<"1.Enter the administrator mode"<<std::endl;
    std::cout<<"2.Enter the user mode"<<std::endl;
    std::cout<<"3.Exit the application"<<std::endl;

}


template <typename T,typename U>
void UI<T,U>::print_user_menu(){
    std::cout<<std::endl;
    std::cout<<"1.See the watch list"<<std::endl;
    std::cout<<"2.See the movies with a given genre"<<std::endl;
    std::cout<<"3.Delete a movie from the watch list"<<std::endl;
    std::cout<<"4.Open the watch list in browser/notepad"<<std::endl;
    std::cout<<"5.Exit the user mode"<<std::endl;

}

template <typename T,typename U>
void UI<T,U>::print_choose_menu(){
    std::cout<<std::endl;
    std::cout<<"1.Like the movie"<<std::endl;
    std::cout<<"2.Check for next"<<std::endl;
    std::cout<<"3.Exit the feedback section"<<std::endl;
}
template <typename T,typename U>
void UI<T,U>::print_first_menu(){
    std::cout<<std::endl;
    std::cout<<"1.Choose HTML"<<std::endl;
    std::cout<<"2.Choose CSV"<<std::endl;
}


template <typename T,typename U>
void UI<T,U>::print_administrator_menu(){
    std::cout<<std::endl;
    std::cout<<"1.Print the movies"<<std::endl;
    std::cout<<"2.Add a new movie"<<std::endl;
    std::cout<<"3.Delete a movie"<<std::endl;
    std::cout<<"4.Update a movie"<<std::endl;
    std::cout<<"5.Exit the application"<<std::endl;
}

template <typename T,typename U>
void UI<T,U>::run_menu() {
    bool done;
    Movie movie;
    char arr[50];
    int command,option;
    Service<T,U>::service_load();
    bool first_done = false;
    print_first_menu();
    std::cout<<"command=";
    std::cin>>option;
    while(!first_done) {
        print_main_menu();
        std::cout << "command=";
        std::cin >> command;
        if (command == 1) {
            done = false;
            while (!done) {
                try {
                    Service<T,U>::service_store();
                    print_administrator_menu();
                    std::cout << "command=";
                    std::cin >> command;
                    if (command == 5)
                        done = true;
                    else if (command == 1)
                        ui_print();
                    else if (command == 2)
                        ui_add();
                    else if (command == 3)
                        ui_delete();
                    else if (command == 4)
                        ui_update();
                    else{
                        cout<<"Bad command";
                    }
                } catch (RepositoryException ex) {
                    cout<<ex.what()<<endl;
                }
                catch (DomainException ex) {
                    cout<<ex.what()<<endl;
                }
                catch (FileExceptions ex) {
                    cout<<ex.what()<<endl;
                }
            }
        }
        if (command == 2) {
            done = false;
            while (!done) {
                try{
                    if(option==2)
                        WatchlistService<T,U>::load_csv();
                    else
                        WatchlistService<T,U>::load_html();
                print_user_menu();
                std::cout << "command=";
                std::cin >> command;
                if (command == 5)
                    done = true;
                else if (command == 2)
                    ui_get_genre();
                else if (command == 1)
                    ui_print_watchlist();
                else if (command == 3)
                    ui_delete_watchlist();
                else if(command==4) {
                    if (option == 2)
                        ui_open_csv();
                    else
                        ui_open_html();
                }
            } catch(RepositoryException ex){
                cout<<ex.what()<<endl;
                }
            }

        }
        if(command==3)
            first_done=true;
    }
}

template class UI<Movie,int>;