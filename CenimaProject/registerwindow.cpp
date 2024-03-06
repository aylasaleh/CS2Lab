#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "Users.h"
#include "welcomewindow.h"
#include "QComboBox"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->username_error->setVisible(false);
    ui->age_error->setVisible(false);
    ui->pass_error->setVisible(false);
    ui->register_error->setVisible(false);
    for (int i = 0; i<30; i++)
    {
        int x = 1985+i;
        QString y = QString::number(x);
        ui->year ->addItem(y);
    }
    //forloop for year
    //for monthd
    //for days

}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_register_2_clicked()
{

    // Retrieve data entered by the user
    QString username = ui->username->text();
    QString password = ui->pass->text();
    QString retypedpass= ui->re_pass->text();
    QString gender=ui->female->isChecked();//if statement
    QString account=ui->account->currentText();//if statement
    QString year=ui->year->text();

    if (hasError==false){
        //transfer to welcome page
    }
    else
    {
        //fado password and age
        ui->pass -> setText ("");
        //same for age
    }

}

RegisterWindow::bool hasError (bool x)
{//if statement for false x
    if (username.isEmpty() || pass.isEmpty() || re_pass.isEmpty()) {
        // Empty field error
        ui->register_error->setVisible(true);
        hasError = true;
    }
    else {
        // Check if username already exists
        if (usernameExists(username)) {
            ui->username_error->setVisible(true);
            hasError = true;
        }

        // Check if passwords match
        if (password != retypedPassword) {
            ui->pass_error->setVisible(true);
            hasError = true;
        }
    }




    int currentYear = 2024; // Current year
    int age = currentYear - year;
    if (age < 12) {
        ui->age_error->setVisible(true);
        hasError = true;
    }






}


