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
    // Retrieve data entered by the user
    QString username = ui->username->text();
    QString password = ui->pass->text();
    QString retypedpass= ui->re_pass->text();
    if (ui->female->isChecked()){
        ui->female->setChecked(true);
    }
    else{
        ui->male->setChecked(true);
    }
    if(ui->admin->isChecked()){
        ui->admin->setChecked(true);
    }
    else{
        ui->user->setChecked(true);
    }
    QString year=ui->year->currentText();
    //usernames array
    if (hasError()==false){
        //transfer to welcome page
        //RegisterWindow* registerWindow = new RegisterWindow (this); //creating a new window of type Register
        hide();
        int age = 2024 - (ui->year->currentText()).toInt();
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


