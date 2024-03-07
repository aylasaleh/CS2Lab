#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "welcomewindow.h"
#include "QComboBox"
#include "Users.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);

    //make error labels invisible
    ui->username_error->setVisible(false);
    ui->age_error->setVisible(false);
    ui->pass_error->setVisible(false);
    ui->register_error->setVisible(false);

    //setting values for year combobox
    for (int i = 0; i<50; i++)
    {
        int x = 1975+i;
        QString y = QString::number(x);
        ui->year ->addItem(y);
    }

    //setting months for combobox
    ui->month->addItem("Jan");
    ui->month->addItem("Feb");
    ui->month->addItem("March");
    ui->month->addItem("April");
    ui->month->addItem("May");
    ui->month->addItem("June");
    ui->month->addItem("July");
    ui->month->addItem("August");
    ui->month->addItem("September");
    ui->month->addItem("October");
    ui->month->addItem("November");
    ui->month->addItem("December");

    //setting days for combobox
    for(int i=0;i<31;i++){
        int x=1+i;
        QString y=QString::number(x);
        ui->day_2->addItem(y);
    }


}
RegisterWindow::~RegisterWindow()
{
    delete ui;
}


void RegisterWindow::on_register_2_clicked()
{
    //make error labels invisible
    ui->username_error->setVisible(false);
    ui->age_error->setVisible(false);
    ui->pass_error->setVisible(false);
    ui->register_error->setVisible(false);

    int age = 2024 - (ui->year->currentText()).toInt();

    int gender;
    if (ui->female->isChecked()){
        gender = 0; //female =0
    }
    else if (ui->male->isChecked())
    {
        gender = 1; // male = 1
    }

    int Type;
    if(ui->admin->isChecked()){
        Type = 0; //0 stands for admin
    }
    else if(ui->user->isChecked()){
        Type = 1; //1 stands for user
    }

    if (hasError() ==false){

        // save data entered by the user
        usernames[usersCount] = ui->username-> text();
        passwords[usersCount] = ui->pass-> text();
        ages [usersCount] = age;
        usersCount ++;

        //transfer to welcome page
        hide();
        WelcomeWindow* welcomeWindow = new WelcomeWindow (ui->username-> text(),age, this); //creating a new window of type WelcomeWindow
        welcomeWindow -> show();
    }
    else
    {
        ui->pass->setText("");
        ui->re_pass->setText("");

    }

}

bool RegisterWindow:: hasError(){
    if ((ui->username -> text().isEmpty()) || ui -> pass -> text().isEmpty() || ui-> re_pass-> text().isEmpty()) {
        // Empty field error
        ui->register_error->setVisible(true);
        return true;
    }

    for (int i = 0; i< usersCount; i++)
    {
        if (ui-> username -> text()  == usernames[i]) {
            ui->username_error->setVisible(true);
            return true;
        }
    }

    // Check if passwords match
    if (ui->pass->text() != ui->re_pass->text()) {
        ui->pass_error->setVisible(true);
        return true;
    }

    int currentYear = 2024; // Current year
    int age = currentYear - (ui->year->currentText()).toInt();
    if (age < 12) {
        ui->age_error->setVisible(true);
        return true;
    }
    return false;
}







