#include "loginui.h"



LoginUI::LoginUI(AccountController* accountControl){

    this->accountControl=accountControl;
    initialize();
    echo();
    mvprintw(0,0,"Welcome to Rocketbook!");
    run();

}


void LoginUI::run(){

    char name[80], pass[80];

    mvprintw(1,0,"Enter Username: ");

    getstr(name);

    initscr();
    //  getch();

    mvprintw(2,0,"Enter Password: ");

    getstr(pass);

  //  accountController->createNewAccount(QString::fromStdString(name),QString::fromStdString(pass),x,x,x,0);


    if(accountControl->login(QString::fromStdString(name),QString::fromStdString(pass))){
        erase();
        refresh();
        mvprintw(2,0,"Login Successful. Welcome ");
        printw(name);
        refresh();


        menu=new MainMenu(accountControl);


    }
    else{
        erase();
        refresh();
        mvprintw(0,0,"Login Failed. Try Again.");
        run();
    }

}
