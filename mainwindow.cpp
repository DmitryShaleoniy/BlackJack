#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QIcon>
#include <QListView>
#include <QLabel>
#include <QListWidgetItem>
#include <bits/stdc++.h>
#include <QPixmap>
#include <QSize>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    make_vector();
    ui->setupUi(this);
    ui->dealler->setFlow(QListView::LeftToRight);
    ui->player->setFlow(QListView::LeftToRight); //карты будут выходить слева направо
    ui->dealler->setIconSize(QSize(200, 200));
    ui->player->setIconSize(QSize(200, 200));
    game();
}

MainWindow::~MainWindow() //всем привет сейчас будем писать блек джек
{
    delete ui;
}

void MainWindow::make_vector()
{
    card cur;
    char suits[4] = {'c','d','h','s'};
    //std::string cur_path;
    for(int i = 2; i <= 14; i++){
        if(i <= 10){
            cur.val = i;
        }
        else if(i == 14){
            cur.val = 11;
        }
        else {
            cur.val = 10;
        }
        //заполнили значения, теперь нужно добавить 4 карты с этими значениями (разных мастей)
        for(int g = 0; g < 4; g++){
            cur.suit = suits[g];
            cur.path = "./images/" + std::to_string(i) + cur.suit + ".png";
            cards.push_back(cur);
        }
    }
}

void MainWindow::game()
{
    //while(true){
    ui->player->clear();
    ui->dealler->clear();
    dealler_score = 0;
    player_score = 0;
    dealler_ace_count = 0;
    player_ace_count = 0;
        if (MakeBet.exec()==QDialog::Accepted) {
            std::random_device rd;
            std::mt19937 g(rd());//инициализировали генератор
            std::shuffle(cards.begin(), cards.end(), g);//перемешали колоду
            iter = cards.begin();
            bet = MakeBet.getBet();
            QString label = "ставка " + QString::number(bet);
            this->ui->bet->setText(label);

            //приступим к реализации игры
            //сначала дадим 2 карты игроку
            for(int i = 0; i < 2; i++){
                add_player_card();
            }
            std::cout<< player_score << std::endl;

            //тепреь дадим карт диллеру

            add_dealler_card(); // одну нормальную карту, а вторую пока что рубашкой вниз
            dealler_back = new QListWidgetItem();
            dealler_back->setIcon(QIcon("./images/back.png"));
            ui->dealler->addItem(dealler_back);

            //мы выдали карты, теперь надо дать возможность игроку добрать карт или начать игру
        }
    //}
}

void MainWindow::add_player_card()
{
    QListWidgetItem* item = new QListWidgetItem();
    std::string p = iter->path;
    QString path = QString::fromStdString(p);
    item->setIcon(QIcon(path));
    ui->player->addItem(item);
    //теперь надо обновить счет
    player_score += iter->val;
    if(iter->val == 11){
        player_ace_count++;
    }
    if(player_score > 21 && player_ace_count > 0){
        player_ace_count--;
        player_score -= 10;
    }
    iter++;
}

void MainWindow::add_dealler_card()
{
    QListWidgetItem* item = new QListWidgetItem();
    std::string p = iter->path;
    QString path = QString::fromStdString(p);
    item->setIcon(QIcon(path));
    ui->dealler->addItem(item);
    //теперь надо обновить счет
    dealler_score += iter->val;
    if(iter->val == 11){
        dealler_ace_count++;
    }
    if(dealler_score > 21 && dealler_ace_count > 0){
        dealler_ace_count--;
        dealler_score -= 10;
    }
    iter++;
}

void MainWindow::on_card_button_clicked()
{
    add_player_card();
    if(player_score > 21){
        QMessageBox::warning(this, "Поражение", "Вы проиграли - перебор");
        game();
    }
}

void MainWindow::on_play_button_clicked() //тут откроем карту диллера и добавим ему, если недостет до 17
{
    std::string p = iter->path;
    QString path = QString::fromStdString(p);
    dealler_back->setIcon(QIcon(path));
    dealler_score += iter->val;
    if(iter->val == 11){
        dealler_ace_count++;
    }
    if(dealler_score > 21 && dealler_ace_count > 0){
        dealler_ace_count--;
        dealler_score -= 10;
    }
    iter++; //обновили счет диллера
    //теперь проверка он меньше 17?
    while(dealler_score < 17){
        add_dealler_card();
    }
    //теперь подводим результаты
    if(dealler_score > 21 || player_score > dealler_score){
        QMessageBox::information(this, "Победа", "Вы выигарли " + QString::number(bet * 2));
    }
    else if (player_score == dealler_score){
        QMessageBox::information(this, "Ничья", "Ничья");
    }
    else{
        QMessageBox::warning(this, "Поражение", "Вы проиграли"
                                                "");
    }
    game();
}

// QPixmap pic("./images/2c.png"); //все четко, так работает

// //сейчас для теста попробую вывести всю колоду карт
// //для теста просто одну карту:

// QListWidgetItem* card_d = new QListWidgetItem();
// card_d->setIcon(QIcon(pic));
// ui->dealler->addItem(card_d);

// card_d->setIcon(QIcon("./images/3s.png"));
// //а теперь еще одну
// QListWidgetItem* back = new QListWidgetItem();
// back->setIcon(QIcon("./images/back.png"));
// ui->dealler->addItem(back);
// //ui->dealler->addItem();

//попрубую всю колоду сюда

// auto iter = cards.begin();
// while(iter != cards.end()){
//     QListWidgetItem* item = new QListWidgetItem();
//     std::string p = iter->path;
//     QString path = QString::fromStdString(p);

//     item->setIcon(QIcon(path));
//     ui->dealler->addItem(item);
//     iter++;
// }


