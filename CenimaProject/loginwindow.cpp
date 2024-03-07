#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "Users.h"
#include "welcomewindow.h"
#include "registerwindow.h"


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui-> ErrorL -> setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_LoginB_clicked()
{
    QString u = ui-> UsernameLE -> text();
    QString p = ui-> PasswordLE -> text();

    for (int i = 0; i < usersCount ; i++) // go through all elements of arrays username and passwords
    {
        if (( u == usernames[i]) && (p == passwords[i])) // if username is equal and password
        {// note to make it case sensetive?
            //go to welcome page
            hide (); // hiding this page
            WelcomeWindow* welcomeWindow = new WelcomeWindow (usernames[i], ages[i], this); //creating a new window of type WelcomeWindow
            welcomeWindow -> show();
        }

    }
    //reset login page and show error message
    ui -> UsernameLE -> setText ("");
    ui -> PasswordLE -> setText ("");
    ui-> ErrorL -> setVisible(true);
}


void LoginWindow::on_RegisterB_clicked()
{
    //redirect to register page
    hide (); // hiding this page
    RegisterWindow* registerWindow = new RegisterWindow (this); //creating a new window of type Register
    registerWindow -> show();
}

