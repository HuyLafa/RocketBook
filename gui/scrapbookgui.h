#ifndef SCRAPBOOKGUI_H
#define SCRAPBOOKGUI_H

#include <QWidget>
#include "createbloggui.h"
#include "createmultimediagui.h"
#include "createtweetgui.h"
#include "displaybloggui.h"
#include "displaymultimediagui.h"
#include "displaytweetgui.h"
#include "../model/accountcontroller.h"

class CreateTweetGUI;
class DisplayTweetGUI;
class CreateBlogGUI;
class DisplayBlogGUI;
class CreateMultimediaGUI;
class DisplayMultimediaGUI;

namespace Ui {
class ScrapbookGUI;
}

class ScrapbookGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ScrapbookGUI(AccountController *inputAccountController, QWidget *parent = 0);
    ~ScrapbookGUI();
    void switchTweetViews();
    void switchBlogViews();
    void switchMultimediaViews();
    void refreshBook();
    void displayBlog(Blog* blog);
    void displayTweet(Tweet* tweet);
    void displayMultimedia(Multimedia* multimedia);

private slots:
    void on_editButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::ScrapbookGUI *ui;
    CreateBlogGUI *createBlogView;
    CreateMultimediaGUI *createMultimediaView;
    CreateTweetGUI *createTweetView;
    DisplayBlogGUI *displayBlogView;
    DisplayMultimediaGUI *displayMultimediaView;
    DisplayTweetGUI *displayTweetView;
    AccountController *accountController;
};

#endif // SCRAPBOOKGUI_H
