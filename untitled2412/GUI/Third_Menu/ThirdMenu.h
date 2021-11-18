#pragma once
#include <QObject>
#include <QWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets>

class ThirdMenu: public QObject {
Q_OBJECT

public slots:
    void start_html_administrator();
    void start_html_user();
    void start_csv_administrator();
    void start_csv_user();
};