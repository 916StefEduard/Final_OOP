#include <QObject>
#include <QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets>
#include <GUI/Third_Menu/ThirdMenu.h>
#include <domain/domain.h>
#include <GUI/FirstMenu/Functionalities.h>
#include <GUI/SecondMenu/SecondMenu.h>
#include "ThirdMenu.h"
#include "ui/ui.h"



void ThirdMenu::start_html_administrator(){
    auto *widget1=new QWidget;
    widget1->resize(300, 300);
    auto *gridLayout = new QGridLayout(widget1);
    auto * button1 = new QPushButton("1.Print the movies");
    gridLayout->addWidget(button1);
    auto * button2=new QPushButton("2.Add a new movie");
    gridLayout->addWidget(button2);
    auto * button3=new QPushButton("3.Delete a movie");
    gridLayout->addWidget(button3);
    auto * button4=new QPushButton("4.Update a movie");
    gridLayout->addWidget(button4);
    auto * button5=new QPushButton("5.Exit the application");
    gridLayout->addWidget(button5);
    auto *programs= new ProgramStarter;
    auto *print=new Functionalities;
    auto *second=new ThirdMenu;
    UI<Movie, int> ui;
    QObject::connect(button5, SIGNAL(clicked()), widget1, SLOT(close()));
    QObject::connect(button5,SIGNAL(clicked()),programs,SLOT(start_html_menu()));
    QObject::connect(button1,SIGNAL(clicked()),print,SLOT(print_movies()));
    QObject::connect(button2,SIGNAL(clicked()),print,SLOT(add_widget()));
    QObject::connect(button3,SIGNAL(clicked()),print,SLOT(remove_widget()));
    QObject::connect(button4,SIGNAL(clicked()),print,SLOT(update_widget()));
    widget1->show();
}

void ThirdMenu::start_html_user(){
    auto *widget1=new QWidget;
    widget1->resize(300, 300);
    auto *gridLayout = new QGridLayout(widget1);
    auto * button1 = new QPushButton("1.See the watch list");
    gridLayout->addWidget(button1);
    auto * button2=new QPushButton("2.See the movies with a given genre");
    gridLayout->addWidget(button2);
    auto * button3=new QPushButton("3.Delete a movie from the watch list");
    gridLayout->addWidget(button3);
    auto * button4=new QPushButton("4.Open the watch list in browser/notepad");
    gridLayout->addWidget(button4);
    auto * button5=new QPushButton("5.Exit the user mode");
    gridLayout->addWidget(button5);
    auto *programs= new ProgramStarter;
    auto *print=new Functionalities;
    QObject::connect(button5, SIGNAL(clicked()), widget1, SLOT(close()));
    QObject::connect(button5,SIGNAL(clicked()),programs,SLOT(start_html_menu()));
    QObject::connect(button2,SIGNAL(clicked()),print,SLOT(genre_widget()));
    QObject::connect(button3,SIGNAL(clicked()),print,SLOT(remove_watchlist()));
    QObject::connect(button1,SIGNAL(clicked()),print,SLOT(print_watchlist()));
    QObject::connect(button4,SIGNAL(clicked()),print,SLOT(open_htmls()));
    widget1->show();
}

void ThirdMenu::start_csv_administrator(){
    auto *widget1 = new QWidget;
    widget1->resize(300, 300);
    auto *gridLayout = new QGridLayout(widget1);
    auto *button1 = new QPushButton("1.Print the movies");
    gridLayout->addWidget(button1);
    auto *button2 = new QPushButton("2.Add a new movie");
    gridLayout->addWidget(button2);
    auto *button3 = new QPushButton("3.Delete a movie");
    gridLayout->addWidget(button3);
    auto *button4 = new QPushButton("4.Update a movie");
    gridLayout->addWidget(button4);
    auto *button5 = new QPushButton("5.Exit the application");
    gridLayout->addWidget(button5);
    auto *programs= new ProgramStarter;
    auto *print=new Functionalities;
    QObject::connect(button5, SIGNAL(clicked()), widget1, SLOT(close()));
    QObject::connect(button5,SIGNAL(clicked()),programs,SLOT(start_csv_menu()));
    QObject::connect(button1,SIGNAL(clicked()),print,SLOT(print_movies()));
    QObject::connect(button2,SIGNAL(clicked()),print,SLOT(add_widget()));
    QObject::connect(button3,SIGNAL(clicked()),print,SLOT(remove_widget()));
    QObject::connect(button4,SIGNAL(clicked()),print,SLOT(update_widget()));
    widget1->show();
}

void ThirdMenu::start_csv_user(){
    auto *widget1=new QWidget;
    widget1->resize(300, 300);
    auto *gridLayout = new QGridLayout(widget1);
    auto * button1 = new QPushButton("1.See the watch list");
    gridLayout->addWidget(button1);
    auto * button2=new QPushButton("2.See the movies with a given genre");
    gridLayout->addWidget(button2);
    auto * button3=new QPushButton("3.Delete a movie from the watch list");
    gridLayout->addWidget(button3);
    auto * button4=new QPushButton("4.Open the watch list in browser/notepad");
    gridLayout->addWidget(button4);
    auto * button5=new QPushButton("5.Exit the user mode");
    gridLayout->addWidget(button5);
    auto *programs= new ProgramStarter;
    auto *print=new Functionalities;
    QObject::connect(button5, SIGNAL(clicked()), widget1, SLOT(close()));
    QObject::connect(button5,SIGNAL(clicked()),programs,SLOT(start_csv_menu()));
    QObject::connect(button2,SIGNAL(clicked()),print,SLOT(genre_widget_csv()));
    QObject::connect(button3,SIGNAL(clicked()),print,SLOT(remove_watchlist_csv()));
    QObject::connect(button1,SIGNAL(clicked()),print,SLOT(print_watchlist_csv()));
    QObject::connect(button4,SIGNAL(clicked()),print,SLOT(open_csv()));
    widget1->show();
}