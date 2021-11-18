#pragma once
#include <QObject>
#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets>

class Functionalities: public QObject {
Q_OBJECT
public slots:

    void remove_watchlist_csv();
    void print_movies();

    void add_widget();

    void remove_widget();

    void update_widget();

    void genre_widget();

    void print_watchlist();

    void remove_watchlist();

    void open_csv();

    void open_htmls();

    void genre_widget_csv();

    void print_watchlist_csv();
};
