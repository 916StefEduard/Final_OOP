#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include "GuiFunctions.h"
#include <GUI/FirstMenu/Functionalities.h>
#include <domain/domain.h>
#include "../service/watchlist_service.h"
#include "cstring"

void open_websites (char * cpURL)
{
    ShellExecute (NULL, "open", cpURL, NULL, NULL, SW_SHOWNORMAL);
}

void GuiFunctions::gui_add(const std::vector<Movie>& searches,int position){
    auto *widget=new QWidget;
    auto *gridLayout = new QGridLayout(widget);
    auto *label = new QLabel();
    char *cstr = new char[sizeof(searches[position].trailer) + 1];
    strcpy(cstr, searches[position].trailer);
    open_websites(cstr);
    QByteArray moviess;
    moviess += "Title: ";
    moviess += searches[position].title;
    moviess += "  Genre: ";
    moviess += searches[position].genre;
    moviess += "  Release Date: ";
    moviess += searches[position].release;
    moviess += "  Likes: ";
    moviess += std::to_string(searches[position].likes);
    moviess += "  Trailer: ";
    moviess += searches[position].trailer;
    label->setText(moviess);
    gridLayout->addWidget(label);
    const QSize btnSize = QSize(100, 30);
    auto *button1 = new QPushButton("Next");
    button1->setFixedSize(btnSize);
    gridLayout->addWidget(button1);
    auto *button2 = new QPushButton("Like");
    button2->setFixedSize(btnSize);
    gridLayout->addWidget(button2);
    auto *button3 = new QPushButton("Exit");
    button3->setFixedSize(btnSize);
    gridLayout->addWidget(button3);
    QObject::connect(button1, &QPushButton::clicked,[=]() {
            widget->close();
            if(position+1!=searches.size()) {
                this->gui_add(searches, position + 1);
            }
    });
    QObject::connect(button2, &QPushButton::clicked,[=]() {
        Movie movie;
        WatchlistService<Movie,int> watchlistService;
        strcpy(movie.title,searches[position].title);
        strcpy(movie.genre,searches[position].genre);
        strcpy(movie.release,searches[position].release);
        movie.likes=searches[position].likes;
        strcpy(movie.trailer,searches[position].trailer);
        watchlistService.load_data_from_html();
        watchlistService.repo_add(movie);
        watchlistService.store_data_from_html();
        widget->close();
        if(position+1!=searches.size()) {
            this->gui_add(searches, position + 1);
        }
    });
    widget->show();
}

void GuiFunctions::gui_add_html(const std::vector<Movie>& searches,int position){
    auto *widget=new QWidget;
    auto *gridLayout = new QGridLayout(widget);
    auto *label = new QLabel();
    char *cstr = new char[sizeof(searches[position].trailer) + 1];
    strcpy(cstr, searches[position].trailer);
    open_websites(cstr);
    QByteArray moviess;
    moviess += "Title: ";
    moviess += searches[position].title;
    moviess += "  Genre: ";
    moviess += searches[position].genre;
    moviess += "  Release Date: ";
    moviess += searches[position].release;
    moviess += "  Likes: ";
    moviess += std::to_string(searches[position].likes);
    moviess += "  Trailer: ";
    moviess += searches[position].trailer;
    label->setText(moviess);
    gridLayout->addWidget(label);
    const QSize btnSize = QSize(100, 30);
    auto *button1 = new QPushButton("Next");
    button1->setFixedSize(btnSize);
    gridLayout->addWidget(button1);
    auto *button2 = new QPushButton("Like");
    button2->setFixedSize(btnSize);
    gridLayout->addWidget(button2);
    auto *button3 = new QPushButton("Exit");
    button3->setFixedSize(btnSize);
    gridLayout->addWidget(button3);
    QObject::connect(button1, &QPushButton::clicked,[=]() {
        widget->close();
        if(position+1!=searches.size()) {
            this->gui_add(searches, position + 1);
        }
    });
    QObject::connect(button2, &QPushButton::clicked,[=]() {
        Movie movie;
        WatchlistService<Movie,int> watchlistService;
        strcpy(movie.title,searches[position].title);
        strcpy(movie.genre,searches[position].genre);
        strcpy(movie.release,searches[position].release);
        movie.likes=searches[position].likes;
        strcpy(movie.trailer,searches[position].trailer);
        watchlistService.load_data_from_csv();
        watchlistService.repo_add(movie);
        watchlistService.store_data_from_csv();
        widget->close();
        if(position+1!=searches.size()) {
            this->gui_add(searches, position + 1);
        }
    });
    widget->show();
}