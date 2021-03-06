#include "logingui.h"
#include "ui_logingui.h"

bool LoginGUI::finished = false;

LoginGUI::LoginGUI(AccountController *inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginGUI)
{
    ui->setupUi(this);
    accountController = inputAccountController;
    ui->passwordBox->setEchoMode(QLineEdit::Password);
}

LoginGUI::~LoginGUI()
{
    delete ui;
}

bool LoginGUI::login() {
    QString username = ui->usernameBox->text();
    //ui->passwordBox->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    QString password = ui->passwordBox->text();


    // check username
    if (accountController->checkAccountExists(username)) {

        // if username and password match, log in and segue to main view
        if (accountController->login(username, password)) {
            this->hide();
            main->setUsername(username);
            main->setUp();
            main->show();
            return true;
        }
        else {
            ui->message->setText("Error: Wrong password!");
            return false;
        }
    }

    // display error message
    else {
        ui->message->setText("Error: Account does not exist!");
        return false;
    }
}

bool LoginGUI::on_loginButton_clicked()
{
    return login();
}

void LoginGUI::on_createAccountButton_clicked()
{

    this->close();
    createAccountView->clearAllFields();
    createAccountView->show();

}

void LoginGUI::clearAllFields() {
    ui->usernameBox->setText("");
    ui->passwordBox->setText("");
    ui->message->setText("");
}

void LoginGUI::on_quitButton_clicked()
{
    finished = true;
    this->close();
}

void LoginGUI::closeEvent(QCloseEvent *event)
{
    finished = true;
    QWidget::closeEvent(event);
}

bool LoginGUI::on_passwordBox_returnPressed()
{
    return login();
}
