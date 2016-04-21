#ifndef CHATCONTROLLER_H
#define CHATCONTROLLER_H

#include <iostream>
#include <sstream>
#include <QDebug>
#include <QCoreApplication>
#include "../database/chatdb.h"
#include "../database/messagedb.h"
#include "../database/accountdb.h"
#include "../database/frienddb.h"
#include <string>
#include "rocketuser.h"
#include "chat.h"
#include "message.h"



class ChatController
{
public:
    ChatController(QString username);

    void run();
    int selectChat();
    void createChat();
    void addMemberToChat(int chatId);
    void sendMessage(int chatId);
    void displayMessages(int chatId);
    void removeUserFromChat(int chatId);
    void deleteMessage(int chatId);
    std::vector<int>* getChatIdList();


    int requestInput();
    int requestInput2();
    int userPicksChat();
    std::string userEntersMessage();
    std::string askUserName();



private:
    AccountDB* accountDB;
    FriendDB* friendDB;
    ChatDB* chatDB;
    MessageDB* messageDB;
    QString username;
};

#endif // CHATCONTROLLER_H
