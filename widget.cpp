#include "widget.h"
#include "ui_widget.h"
#include<QThread>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{


            ui->setupUi(this);
            suzu=new Suzu();
            suzu1=new Suzu();
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    suzu->map[i][j]=0;
                    suzu1->map[i][j]=0;
                }
            }





            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    xuanze(i,j,0);
                }
            }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::zuoyi(Suzu *suzu, Suzu *suzu1)
{
                               //往左移动
    {

        for(int i = 0;i<4;i++) //初始suzu元素都都为0
        {
            for(int j =0 ;j<4;j++)
            {
                suzu->map[i][j]=0;
            }
        }
        for(int i = 0;i<4;i++) //将suzu1元素都往坐对齐并给数组suzu
        {  int m=0;
            for(int j =0 ;j<4;j++)
            {
                if(suzu1->map[i][j]!=0){suzu->map[i][m]=suzu1->map[i][j];m++;}
            }
        }
        for(int i = 0;i<4;i++) //将suzu元素复制给suzu1
        {
            for(int j =0 ;j<4;j++)
            {
               suzu1->map[i][j]=suzu->map[i][j];
            }
        }

        for(int i=0;i<4;i++) //将相同元素结合在一起
        {
            for(int j = 0;j < 4;j++)
            {
                if(suzu1->map[i][j]==suzu1->map[i][j+1]){suzu1->map[i][j]*=2;suzu1->map[i][j+1]=0;j+=2;}
                else if(j>=3){break;}
            }


        }

        int suzu2[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

        for(int i = 0;i<4;i++)//再次往左对齐并放到数组suzu2
        {  int m=0;
            for(int j =0 ;j<4;j++)
            {
                if(suzu1->map[i][j]!=0){suzu2[i][m]=suzu1->map[i][j];m++;}
            }
        }
        for(int i=0;i<4;i++) //将suzu2的元素赋给suzu1
            for(int j=0;j<4;j++)
                suzu1->map[i][j]=suzu2[i][j];

        //在空的地方随机生成2或者4;
           rand1(suzu1);

    }





}

void Widget::youyi(Suzu *suzu, Suzu *suzu1 )                              //往右移动
{
    for(int i = 0;i<4;i++) //初始suzu元素都都为0
    {
        for(int j =0 ;j<4;j++)
        {
            suzu->map[i][j]=0;
        }
    }
    for(int i = 0;i<4;i++)//将suzu1元素都往右对齐给数组suzu
    {  int m=0;
        for(int j =3 ;j>=0;j--)
        {
            if(suzu1->map[i][j]!=0){suzu->map[i][3-m]=suzu1->map[i][j];m++;}
        }
    }

    for(int i=0;i<4;i++)//将相同元素结合在一起
    {
        for(int j = 3;j >= 0;j--)
        {
            if(suzu1->map[i][j]==suzu1->map[i][j-1]){suzu1->map[i][j]*=2;suzu1->map[i][j-1]=0;j-=2;}
            else if(j<=0){break;}
        }


    }

    int suzu2[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    for(int i = 0;i<4;i++) // 再次往右对齐并放到数组suzu2
    {  int m=0;
        for(int j =3 ;j>=0;j--)
        {
            if(suzu1->map[i][j]!=0){suzu2[i][3-m]=suzu1->map[i][j];m++;}
        }
    }

    for(int i=0;i<4;i++)   //将suzu2的元素赋给suzu1
        for(int j=0;j<4;j++)
            suzu1->map[i][j]=suzu2[i][j];

   rand1(suzu1);//随机生成一个数
}



void Widget::shangyi(Suzu *suzu, Suzu *suzu1 )                             // 上移
{
for(int i = 0;i<4;i++) //初始suzu元素都都为0
{
    for(int j =0 ;j<4;j++)
    {
        suzu->map[i][j]=0;
    }
}
for(int i = 0;i<4;i++) //将suzu1元素都往上对齐并给数组suzu
{  int m=0;
    for(int j =0 ;j<4;j++)
    {
        if(suzu1->map[j][i]!=0){suzu->map[m][i]=suzu1->map[j][i];m++;}
    }
}
for(int i = 0;i<4;i++) //将suzu元素复制给suzu1
{
    for(int j =0 ;j<4;j++)
    {
       suzu1->map[i][j]=suzu->map[i][j];
    }
}

for(int i=0;i<4;i++) //将相同元素结合在一起
{
    for(int j = 0;j < 4;j++)
    {
        if(suzu1->map[j][i]==suzu1->map[j+1][i]){suzu1->map[j][i]*=2;suzu1->map[j+1][i]=0;j+=2;}
        else if(j>=3){break;}
    }


}

int suzu2[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

for(int i = 0;i<4;i++)//再次往上对齐并放到数组suzu2
{  int m=0;
    for(int j =0 ;j<4;j++)
    {
        if(suzu1->map[j][i]!=0){suzu2[m][i]=suzu1->map[j][i];m++;}
    }
}
for(int i=0;i<4;i++) //将suzu2的元素赋给suzu1
    for(int j=0;j<4;j++)
        suzu1->map[i][j]=suzu2[i][j];

//在空的地方随机生成2或者4;
   rand1(suzu1);



}




void Widget::xiayi(Suzu *suzu, Suzu *suzu1)                               //下移

{

    for(int i = 0; i<4; i++) //初始suzu元素都都为0
    {
        for(int j =0 ;j<4;j++)
        {
            suzu->map[i][j] = 0;
        }
    }
    for(int i = 0;i<4;i++)//将suzu1元素都往xia对齐给数组suzu
    {  int m=0;
        for(int j =3 ;j>=0;j--)
        {
            if(suzu1->map[j][i]!=0){suzu->map[3-m][i]=suzu1->map[j][i];m++;}
        }
    }

    for(int i=0;i<4;i++)//将相同元素结合在一起
    {
        for(int j = 3;j >= 0;j--)
        {
            if(suzu1->map[j][i]==suzu1->map[j-1][i]){suzu1->map[j][i]*=2;suzu1->map[j-1][i]=0;j-=2;}
            else if(j<=0){break;}
        }


    }

    int suzu2[4][4]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    for(int i = 0;i<4;i++) // 再次往右对齐并放到数组suzu2
    {  int m=0;
        for(int j =3 ;j>=0;j--)
        {
            if(suzu1->map[j][i]!=0){suzu2[3-m][i]=suzu1->map[j][i];m++;}
        }
    }

    for(int i=0;i<4;i++)   //将suzu2的元素赋给suzu1
        for(int j=0;j<4;j++)
            suzu1->map[i][j]=suzu2[i][j];

   rand1(suzu1);//随机生成一个数



}





void Widget::rand1(Suzu *suzu1)
{
    int GAME=0;
    game=0;
    qsrand(time(0));//取随机种子
    for(int i=0;i<4;i++)
    {
       { for(int j=0;j<4;j++)
            if(suzu1->map[i][j]==0){GAME=1;game=1;break;}
       }
    }

   if(GAME==0)
              {
                 ui->pushButton_xiayi->setText("重新开始");
                 ui->lineEdit_00->setText("G");
                 ui->lineEdit_01->setText("A");             
                 ui->lineEdit_02->setText("M");
                 ui->lineEdit_03->setText("E");
                 ui->lineEdit_20->setText("O");
                 ui->lineEdit_21->setText("V");
                 ui->lineEdit_22->setText("E");
                 ui->lineEdit_23->setText("R");
                 ui->lineEdit_10->clear();
                 ui->lineEdit_11->clear();
                 ui->lineEdit_12->clear();
                 ui->lineEdit_13->clear();
                 ui->lineEdit_30->clear();
                 ui->lineEdit_31->clear();
                 ui->lineEdit_32->clear();
                 ui->lineEdit_33->clear();
                 for(int i=0;i<4;i++)         //将数组清空
                 {
                     for(int j=0;j<4;j++)
                     {
                      suzu1->map[i][j]=0;
                     }

                 }


               }//判断游戏是否结束
    else if(GAME==1)
           {
               while(1)                   //没结束就给定随机数
               {
                   int a =qrand()%4;
                   int b =qrand()%4;
                   int c=qrand()%2;
                   int d;
                   switch (c) {
                   case 0:
                       d=2;
                       break;
                   case 1:
                       d=4;
                       break;
                   default:
                       break;
                   }
                   if(suzu1->map[a][b]==0){suzu1->map[a][b]=d;break;}
               }

           }

}



void Widget::on_pushButton_zuoyi_clicked()
{
    zuoyi(suzu,suzu1);
    {
        for(int i=0;i<4;i++)
        { for(int j=0;j<4;j++)
            {int bb=suzu1->map[i][j];
                int xx=i;
                int yy=j;
                xuanze(xx,yy,bb);
            }
        }
    }
}

void Widget::on_pushButton_youyi_clicked()
{
   youyi(suzu,suzu1);
   if(game)
   {
       for(int i=0;i<4;i++)
       { for(int j=0;j<4;j++)
           {int bb=suzu1->map[i][j];
               int xx=i;
               int yy=j;
               xuanze(xx,yy,bb);
           }
       }
   }
}

void Widget::on_pushButton_shangyi_clicked()
{
    shangyi(suzu,suzu1);
    if(game)
    {
        for(int i=0;i<4;i++)
        { for(int j=0;j<4;j++)
            {int bb=suzu1->map[i][j];
                int xx=i;
                int yy=j;
                xuanze(xx,yy,bb);
            }
        }
    }
}

//void Widget::on_pushButton_4_clicked()
//{

//}
void Widget::xuanze(int xx,int yy,int bb)
{
    QString str=QString( "%1").arg(bb);
    switch (xx) {
    case 0:
        switch (yy) {
        case 0:
            ui->lineEdit_00->setText(str);
            break;
        case 1:
            ui->lineEdit_01->setText(str);
            break;
        case 2:
            ui->lineEdit_02->setText(str);
            break;
        case 3:
            ui->lineEdit_03->setText(str);
            break;
        default:
            break;
        }



        break;
    case 1:
        switch (yy) {
        case 0:
            ui->lineEdit_10->setText(str);
            break;
        case 1:
            ui->lineEdit_11->setText(str);
            break;
        case 2:
            ui->lineEdit_12->setText(str);
            break;
        case 3:
            ui->lineEdit_13->setText(str);
            break;
        default:
            break;
        }




        break;
    case 2:
        switch (yy) {
        case 0:
            ui->lineEdit_20->setText(str);
            break;
        case 1:
            ui->lineEdit_21->setText(str);
            break;
        case 2:
            ui->lineEdit_22->setText(str);
            break;
        case 3:
            ui->lineEdit_23->setText(str);
            break;
        default:
            break;
        }




        break;
    case 3:
        switch (yy) {
        case 0:
            ui->lineEdit_30->setText(str);
            break;
        case 1:
           ui->lineEdit_31->setText(str);
            break;
        case 2:
           ui->lineEdit_32->setText(str);
            break;
        case 3:
            ui->lineEdit_33->setText(str);
            break;
        default:
            break;
        }




        break;
    default:
        break;
    }
}



void Widget::on_pushButton_xiayi_clicked()
{
    xiayi(suzu,suzu1);
    if(game)
    {
    for(int i=0;i<4;i++)
       { for(int j=0;j<4;j++)
           {int bb=suzu1->map[i][j];
           int xx=i;
           int yy=j;
           xuanze(xx,yy,bb);
           }
       }
    }
}
