#include "QWidget"
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <../GUI/SecondMenu/SecondMenu.h>
#include "FirstMenu.h"


int FirstMenu::start_gui(int argc, char *argv[]) {
    QApplication app(argc, argv);
    construct();
    return QApplication::exec();
}


void FirstMenu::construct(){
    auto *widget=new QWidget;
    widget->resize(300, 300);
    auto *gridLayout = new QGridLayout(widget);
    auto * button1 = new QPushButton("1.HTML");
    gridLayout->addWidget(button1);
    auto * button2 = new QPushButton("2.CSV");
    gridLayout->addWidget(button2);
    auto * button3 = new QPushButton("3.Exit");
    gridLayout->addWidget(button3);
    button1->setGeometry(540,440,93,27);
    auto *program = new ProgramStarter;
    QObject::connect(button1, SIGNAL(clicked()), program, SLOT(start_html_menu()));
    QObject::connect(button1, SIGNAL(clicked()), widget, SLOT(close()));
    QObject::connect(button2, SIGNAL(clicked()), program, SLOT(start_csv_menu()));
    QObject::connect(button2, SIGNAL(clicked()), widget, SLOT(close()));
    QObject::connect(button3, SIGNAL(clicked()), widget, SLOT(close()));
    widget->show();
}