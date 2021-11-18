#include "../GUI/FirstMenu/FirstMenu.h"
#include "../GUI/SecondMenu/SecondMenu.h"
#include "../GUI/Third_Menu/ThirdMenu.h"
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets>



void ProgramStarter::start_html_menu(){
    auto *widget1=new QWidget;
    widget1->resize(300, 300);
    auto *gridLayout = new QGridLayout(widget1);
    auto * button1 = new QPushButton("1.Enter the administrator mode");
    gridLayout->addWidget(button1);
    auto * button2=new QPushButton("2.Enter the user mode");
    gridLayout->addWidget(button2);
    auto * button3=new QPushButton("3.Exit the application");
    gridLayout->addWidget(button3);
    auto *programs= new ThirdMenu;
    QObject* button = QObject::sender();
    auto *starter=new FirstMenu;
    auto *first=new FirstMenu;
    QObject::connect(button1, SIGNAL(clicked()), programs, SLOT(start_html_administrator()));
    QObject::connect(button1, SIGNAL(clicked()), widget1, SLOT(close()));
    QObject::connect(button2, SIGNAL(clicked()), programs, SLOT(start_html_user()));
    QObject::connect(button2, SIGNAL(clicked()), widget1, SLOT(close()));
    QObject::connect(button3, SIGNAL(clicked()), widget1, SLOT(close()));
    QObject::connect(button3, SIGNAL(clicked()), first, SLOT(construct()));
    widget1->show();
}

void ProgramStarter::start_csv_menu() {
    auto *widget2=new QWidget;
    widget2->resize(300, 300);
    auto *gridLayout = new QGridLayout(widget2);
    auto * button1 = new QPushButton("1.Enter the administrator mode");
    gridLayout->addWidget(button1);
    auto * button2=new QPushButton("2.Enter the user mode");
    gridLayout->addWidget(button2);
    auto * button3=new QPushButton("3.Exit the application");
    gridLayout->addWidget(button3);
    auto *programs= new ThirdMenu;
    auto *first=new FirstMenu;
    QObject::connect(button1, SIGNAL(clicked()), programs, SLOT(start_csv_administrator()));
    QObject::connect(button1, SIGNAL(clicked()), widget2, SLOT(close()));
    QObject::connect(button2, SIGNAL(clicked()), programs, SLOT(start_csv_user()));
    QObject::connect(button2, SIGNAL(clicked()), widget2, SLOT(close()));
    QObject::connect(button3, SIGNAL(clicked()), widget2, SLOT(close()));
    QObject::connect(button3, SIGNAL(clicked()), first, SLOT(construct()));
    widget2->show();
}


