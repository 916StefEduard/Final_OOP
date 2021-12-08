
#include <GUI/SecondMenu/SecondMenu.h>
#include <domain/domain.h>
#include <GUI/GuiFunctions/GuiFunctions.h>
#include "Functionalities.h"
#include "../service/database_service.h"
#include "FirstMenu.h"
#include "../service/watchlist_service.h"

void Functionalities::print_movies(){
    auto *widget1=new QWidget;
    widget1->resize(300, 300);
    auto *gridLayout = new QGridLayout(widget1);
    Service<Movie,int> service;
    service.load_data();
    for(int i=0;i<service.get_length();++i){
        auto *label = new QLabel();
        QByteArray movie;
        movie+="Title: ";
        movie+=service.get_title(i);
        movie+="  Genre: ";
        movie+=service.get_genre(i);
        movie+="  Release Date: ";
        movie+=service.get_release(i);
        movie+="  Likes: ";
        movie+=std::to_string(service.get_likes(i));
        movie+="  Trailer: ";
        movie+=service.get_trailer(i);
        label->setText(movie);
        gridLayout->addWidget(label);
    }
    widget1->show();
}

void Functionalities::add_widget(){
    auto *widget=new QWidget;
    Movie movie;
    auto *label=new QLabel;
    auto *formGroupBox = new QGroupBox(tr("Add a new movie:"));
    auto *layout = new QFormLayout;
    auto *title=new QLineEdit;
    layout->addRow(new QLabel(tr("New Title:")), title);
    auto *genre=new QLineEdit;
    layout->addRow(new QLabel(tr("New Genre:")), genre);
    auto *release=new QLineEdit;
    layout->addRow(new QLabel(tr("New Release:")), release);
    layout->addRow(new QLabel(tr("New Likes:")), new QLineEdit);
    auto *trailer=new QLineEdit;
    layout->addRow(new QLabel(tr("New Trailer:")),trailer);
    auto *button=new QPushButton("Add Student");
    layout->addWidget(button);
    auto *first=new FirstMenu;
    auto *widget1=new QWidget;
    widget1->resize(300, 300);
    auto *gridLayout = new QGridLayout(widget1);
    gridLayout->addWidget(label);
    Service<Movie,int> service;
    QObject::connect(button, &QPushButton::clicked,[=]() {
        Service<Movie,int> service;
        Movie movie;
        strcpy(movie.title,title->text().toStdString().c_str());
        strcpy(movie.genre,genre->text().toStdString().c_str());
        strcpy(movie.release,release->text().toStdString().c_str());
        movie.likes=release->text().toInt();
        strcpy(movie.trailer,trailer->text().toStdString().c_str());
        service.load_data();
        service.service_add(movie);
        service.store_to_file();
        formGroupBox->hide();
    } );
    formGroupBox->setLayout(layout);
    formGroupBox->show();
}

void Functionalities::remove_widget(){
    auto *widget=new QWidget;
    auto *gridLayout = new QGridLayout(widget);
    auto *formGroupBox = new QGroupBox(tr("Delete a movie:"));
    auto *layout = new QFormLayout;
    auto *title=new QLineEdit;
    layout->addRow(new QLabel(tr("Title:")), title);
    auto *button=new QPushButton("remove movie");
    layout->addWidget(button);
    QObject::connect(button,&QPushButton::clicked,[=](){
        Service<Movie,int> service;
        char *cstr = new char[title->text().toStdString().length() + 1];
        strcpy(cstr, title->text().toStdString().c_str());
        service.load_data();
        service.service_remove(cstr);
        service.store_to_file();
        delete [] cstr;
        formGroupBox->hide();
    });
    formGroupBox->setLayout(layout);
    formGroupBox->show();
}

void Functionalities::update_widget(){
    auto *widget=new QWidget;
    auto *gridLayout = new QGridLayout(widget);
    auto *formGroupBox = new QGroupBox(tr("Delete a movie:"));
    auto *layout = new QFormLayout;
    auto *oldtitle=new QLineEdit;
    layout->addRow(new QLabel(tr("Old Title:")), oldtitle);
    auto *newtitle=new QLineEdit;
    layout->addRow(new QLabel(tr("New Title:")), newtitle);
    auto *genre=new QLineEdit;
    layout->addRow(new QLabel(tr("New Genre:")), genre);
    auto *release=new QLineEdit;
    layout->addRow(new QLabel(tr("New Release:")), release);
    auto *likes=new QLineEdit;
    layout->addRow(new QLabel(tr("New Likes:")), likes);
    auto *trailer=new QLineEdit;
    layout->addRow(new QLabel(tr("New Trailer:")), trailer);
    auto *button=new QPushButton("update movie");
    layout->addWidget(button);
    QObject::connect(button, &QPushButton::clicked,[=]() {
        Movie movie;
        Service<Movie,int> service;
        strcpy(movie.title,newtitle->text().toStdString().c_str());
        strcpy(movie.genre,genre->text().toStdString().c_str());
        strcpy(movie.release,release->text().toStdString().c_str());
        movie.likes=likes->text().toInt();
        strcpy(movie.trailer,trailer->text().toStdString().c_str());
        char *cstr = new char[oldtitle->text().toStdString().length() + 1];
        strcpy(cstr, oldtitle->text().toStdString().c_str());
        service.load_data();
        service.service_update(cstr,movie);
        service.store_to_file();
        delete [] cstr;
        formGroupBox->hide();
    } );
    formGroupBox->setLayout(layout);
    formGroupBox->show();
}


void Functionalities::genre_widget(){
        auto *widget=new QWidget;
    auto *gridLayout = new QGridLayout(widget);
    auto *formGroupBox = new QGroupBox(tr("Movies with a given genre:"));
    auto *layout = new QFormLayout;
    auto *genre=new QLineEdit;
    layout->addRow(new QLabel(tr("Genre:")), genre);
    auto *button=new QPushButton("search genre");
    layout->addWidget(button);
    auto *guif=new GuiFunctions;
    QObject::connect(button, &QPushButton::clicked,[=]() {
        Service<Movie,int> service;
        auto *widget=new QWidget;
        int position=0;
        service.load_data();
        vector<Movie> searches=service.search(genre->text().toStdString());
        guif->gui_add(searches,position);
        formGroupBox->hide();
    } );
    formGroupBox->setLayout(layout);
    formGroupBox->show();
}

void Functionalities::genre_widget_csv(){
    auto *widget=new QWidget;
    auto *gridLayout = new QGridLayout(widget);
    auto *formGroupBox = new QGroupBox(tr("Movies with a given genre:"));
    auto *layout = new QFormLayout;
    auto *genre=new QLineEdit;
    layout->addRow(new QLabel(tr("Genre:")), genre);
    auto *button=new QPushButton("search genre");
    layout->addWidget(button);
    auto *guif=new GuiFunctions;
    QObject::connect(button, &QPushButton::clicked,[=]() {
        Service<Movie,int> service;
        auto *widget=new QWidget;
        int position=0;
        service.load_data();
        vector<Movie> searches=service.search(genre->text().toStdString());
        guif->gui_add_html(searches,position);
        formGroupBox->hide();
    } );
    formGroupBox->setLayout(layout);
    formGroupBox->show();
}


void Functionalities::remove_watchlist(){
    auto *widget=new QWidget;
    auto *gridLayout = new QGridLayout(widget);
    auto *formGroupBox = new QGroupBox(tr("Delete a movie from the WatchList:"));
    auto *layout = new QFormLayout;
    auto *title=new QLineEdit;
    layout->addRow(new QLabel(tr("Title:")), title);
    auto *button=new QPushButton("remove movie");
    WatchlistService<Movie,int> watch;
    layout->addWidget(button);
    watch.load_data_from_csv();
    QObject::connect(button,&QPushButton::clicked,[=](){
        char *cstr = new char[title->text().toStdString().length() + 1];
        strcpy(cstr, title->text().toStdString().c_str());
        WatchlistService<Movie,int> watch;
        watch.load_data_from_html();
        watch.repo_removes(cstr);
        watch.store_data_from_html();
        delete [] cstr;
        formGroupBox->hide();
    });
    formGroupBox->setLayout(layout);
    formGroupBox->show();
}

void Functionalities::remove_watchlist_csv(){
    auto *widget=new QWidget;
    auto *gridLayout = new QGridLayout(widget);
    auto *formGroupBox = new QGroupBox(tr("Delete a movie from the WatchList:"));
    auto *layout = new QFormLayout;
    auto *title=new QLineEdit;
    layout->addRow(new QLabel(tr("Title:")), title);
    auto *button=new QPushButton("remove movie");
    WatchlistService<Movie,int> watch;
    layout->addWidget(button);
    watch.load_data_from_csv();
    QObject::connect(button,&QPushButton::clicked,[=](){
        char *cstr = new char[title->text().toStdString().length() + 1];
        strcpy(cstr, title->text().toStdString().c_str());
        WatchlistService<Movie,int> watch;
        watch.load_data_from_csv();
        watch.repo_removes(cstr);
        watch.store_data_from_csv();
        delete [] cstr;
        formGroupBox->hide();
    });
    formGroupBox->setLayout(layout);
    formGroupBox->show();
}

void Functionalities::print_watchlist(){
    auto *widget1=new QWidget;
    widget1->resize(300, 300);
    auto *gridLayout = new QGridLayout(widget1);
    WatchlistService<Movie,int> watchlist;
    watchlist.load_data_from_html();
    for(int i=0;i<watchlist.repo_get_length();++i){
        auto *label = new QLabel();
        QByteArray movie;
        movie+="Title: ";
        movie+=watchlist.watchlist_get_title(i);
        movie+="  Genre: ";
        movie+=watchlist.watchlist_get_genre(i);
        movie+="  Release Date: ";
        movie+=watchlist.watchlist_get_release(i);
        movie+="  Likes: ";
        movie+=std::to_string(watchlist.watchlist_get_likes(i));
        movie+="  Trailer: ";
        movie+=watchlist.watchlist_get_trailer(i);
        label->setText(movie);
        gridLayout->addWidget(label);
    }
    widget1->show();
}

void Functionalities::print_watchlist_csv(){
    auto *widget1=new QWidget;
    widget1->resize(300, 300);
    auto *gridLayout = new QGridLayout(widget1);
    WatchlistService<Movie,int> watchlist;
    watchlist.load_data_from_csv();
    for(int i=0;i<watchlist.repo_get_length();++i){
        auto *label = new QLabel();
        QByteArray movie;
        movie+="Title: ";
        movie+=watchlist.watchlist_get_title(i);
        movie+="  Genre: ";
        movie+=watchlist.watchlist_get_genre(i);
        movie+="  Release Date: ";
        movie+=watchlist.watchlist_get_release(i);
        movie+="  Likes: ";
        movie+=std::to_string(watchlist.watchlist_get_likes(i));
        movie+="  Trailer: ";
        movie+=watchlist.watchlist_get_trailer(i);
        label->setText(movie);
        gridLayout->addWidget(label);
    }
    widget1->show();
}

void Functionalities::open_htmls(){
    ShellExecute(NULL, "open", "C:\\Users\\User\\Desktop\\untitled2412\\data\\watchlists.html",
                 NULL, NULL, SW_SHOWNORMAL);
}

void Functionalities::open_csv() {
    string file_name;
    file_name="../data/watchlist.csv";
    file_name = "notepad \"" + file_name + "\"";
    system(file_name.c_str());
}
