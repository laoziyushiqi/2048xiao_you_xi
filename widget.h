#ifndef WIDGET_H
#define WIDGET_H
#include<QThread>
#include <QWidget>
#include<QTime>

namespace Ui {
class Widget;
}
class Suzu
{
public:
    int map[4][4];
    Suzu()
    {
       this->map[4][4]={0};
    }
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    int map[4][4];
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void zuoyi(Suzu *suzu,Suzu *suzu1); //左移
    void youyi(Suzu *suzu,Suzu *suzu1 );//右移
    void shangyi(Suzu *suzu,Suzu *suzu1);//上移
    void xiayi(Suzu *suzu,Suzu *suzu1);//下移
    void rand1(Suzu *suzu1);            //取随机数
    void xuanze(int xx,int yy,int bb);
    bool game ;
private slots:
    void on_pushButton_zuoyi_clicked();

    void on_pushButton_youyi_clicked();

    void on_pushButton_shangyi_clicked();

    //void on_pushButton_4_clicked();


    void on_pushButton_xiayi_clicked();

private:
    Ui::Widget *ui;
    Suzu *suzu;
    Suzu *suzu1;


};

#endif // WIDGET_H
