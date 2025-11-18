#include "addapplication.h"
#include "ui_addapplication.h"

AddApplication::AddApplication(QWidget *parent) : QDialog(parent), ui(new Ui::AddApplication) {
    ui->setupUi(this);

    connect(ui->saveApplication, &QPushButton::clicked, this, &AddApplication::OnSave);
    connect(ui->exitAddApplication, &QPushButton::clicked, this, &AddApplication::OnCancel);
}

AddApplication::~AddApplication() {}

void AddApplication::OnSave() {

}

void AddApplication::OnCancel() {
    accept();
}
