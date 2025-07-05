#include "makebetdialog.h"
#include "ui_makebetdialog.h"

MakeBetDialog::MakeBetDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MakeBetDialog)
{
    ui->setupUi(this);
}

MakeBetDialog::~MakeBetDialog()
{
    delete ui;
}

int MakeBetDialog::getBet()
{
    return ui->spinBox->value();
}
