#ifndef MAKEBETDIALOG_H
#define MAKEBETDIALOG_H

#include <QDialog>

namespace Ui {
class MakeBetDialog;
}

class MakeBetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MakeBetDialog(QWidget *parent = nullptr);
    int getBet();
    ~MakeBetDialog();

private:
    Ui::MakeBetDialog *ui;

};

#endif // MAKEBETDIALOG_H
