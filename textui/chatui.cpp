#include "chatui.h"

ChatUI::ChatUI(QString username, AccountController* accountControl)
{

    this->username=username;
    this->accountControl=accountControl;
    initialize();
    takeCommand(select(3));

}

void ChatUI::drawScreen(int v) {

clear();

// print the instructions for manipulating the Value object
mvprintw(0, 0, "Chat Menu \nPlease select one by using the arrow keys and pressing enter:");
mvprintw(3, 8, "Create new Chat");
mvprintw(4, 8, "Select Chat");
mvprintw(5, 8, "Back");

mvprintw(v+2, 5, "->");
//std::to_string(v).c_str()

refresh();
}



void ChatUI::takeCommand(int selection){

    // cleanup the window and return control to bash
    endwin();

    chatControl=new ChatController(username);
   if(selection==1)
       createChat();
   else if(selection==2)
       selectChat();
   else if(selection==3)
       return;

   initialize();
   takeCommand(select(3));

}

void ChatUI::createChat(){
    chatControl->createChat();
    mvprintw(8, 6, "New Chat Created");
    getch();
    erase();
}




void ChatUI::selectChat(){
   chatList=chatControl->getChatIdList();
   //This will enter Chat at specific chat Id
   enterChat(chatList->at(chatSelection()));


}



void ChatUI::displayChats(int v) {

    erase();

    mvprintw(0, 0, "Your Chats");

    for(unsigned int i=0;i<chatList->size(); i++){
        mvprintw(i+1,3,std::to_string(chatList->at(i)).c_str());
    }

    mvprintw(v, 0, "->");

    refresh();
}




int ChatUI::chatSelection(){
    int v=1;

    // initialize the interaction loop to run
    bool continue_looping = true;

    // draw the current screen
    displayChats(v);

    do {
        // draw the new screen
        refresh();
        // obtain character from keyboard
        int ch = getch();
        // operate based on input character
        switch (ch) {
        case KEY_UP:
            if(v>0) //arrow goes up
            v--;
            if(v==0) //arrow goes to bottom
                v=chatList->size();
            break;
        case KEY_DOWN:
            if(v<chatList->size()+1) //arrows goes down
            v++;
            if(v==chatList->size()+1) //arrow goes back to top
                v=1;
            break;
        case 10: //Enter Key
            continue_looping = false;
            break;
        }

        displayChats(v);

    } while(continue_looping);

    return v;

}

void ChatUI::enterChat(int chatId){
    erase();


  //  Chat

}
