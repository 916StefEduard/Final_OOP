#include <QtWidgets>
#include "../GUI/FirstMenu/FirstMenu.h"
#include "repository/database_repository.h"
#include "service/database_service.h"
#include "ui/ui.h"

int main(int argc,char* argv[]) {
    cout<<endl;
    cout<<"INTERFACE MENU"<<endl;
    cout<<"   1.GUI"<<endl;
    cout<<"   2.UI"<<endl;
    cout<<"   command:";
    int command;
    cin>>command;
    if(command==1){
        FirstMenu fs;
        fs.start_gui(argc, argv);
    }
    else {
        UI<Movie, int> ui;
        ui.run_menu();
    }
    return 0;
}