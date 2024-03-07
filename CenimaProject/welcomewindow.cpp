#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"
#include"Users.h"
#include <QPixmap>

WelcomeWindow::WelcomeWindow(QString n, int a, QWidget *parent) // parameters must come before parent widget parmeter
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this); // ui is an object of main class? function setup this windowwith it's design formats in .ui file?

    QString z = QString::number (a);//typecasting int to string
    ui -> HelloL -> setText ("Hello "+ n + " " + z );

    QPixmap pix (":/new/prefix1/p.png");

    int w = ui-> Image -> width ();
    int h = ui -> Image -> height ();
    ui -> Image -> setPixmap (pix.scaled (w,h, Qt::KeepAspectRatio));
}


WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_LogoutB_clicked()
{
    hide ();
    LoginWindow *newlogin = new LoginWindow;
    newlogin -> show ();
}

