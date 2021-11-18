#pragma once
#include <QObject>
#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets>


class FirstMenu: public QObject {
Q_OBJECT
public slots:


    int start_gui(int argc, char **argv);

    void construct();
};
