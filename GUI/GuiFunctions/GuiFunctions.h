//
// Created by User on 5/17/2021.
//

#ifndef HELLOWORLD_GUIFUNCTIONS_H
#define HELLOWORLD_GUIFUNCTIONS_H
#include <vector>
#include <QObject>
#include <domain/domain.h>

class GuiFunctions: public QObject{
    Q_OBJECT
public slots:
    void gui_add(const std::vector<Movie> &searches, int position);

    void gui_add_html(const std::vector<Movie> &searches, int position);
};


#endif //HELLOWORLD_GUIFUNCTIONS_H
