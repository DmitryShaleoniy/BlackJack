#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "makebetdialog.h"
#include <string>
#include <vector>
#include <QListWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_card_button_clicked();

    void on_play_button_clicked();

private:
    Ui::MainWindow *ui;
    int bet;
    MakeBetDialog MakeBet;
    struct card{
        int val;
        char suit;
        std::string path;
    };
    std::vector<card> cards;
    std::vector<card>::iterator iter;

    void make_vector();
    void game();

    void add_player_card();
    void add_dealler_card();

    QListWidgetItem * dealler_back;

    int dealler_score = 0;
    int player_score = 0;

    int dealler_ace_count = 0;
    int player_ace_count = 0;
};
#endif // MAINWINDOW_H
