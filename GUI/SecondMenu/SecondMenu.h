#pragma once
#include <QObject>
#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets>

class ProgramStarter : public QObject {

Q_OBJECT

public slots:

    void start_html_menu();
    void start_csv_menu();

};
