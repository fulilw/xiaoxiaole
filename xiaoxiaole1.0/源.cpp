#include<iostream>
#include<graphics.h>//引用图形库头文件
#include<conio.h>
#include<stdio.h>
#include<math.h>
using namespace std;
//填充空白
void fill(int(&lin)[12][12])//填充消掉的部分,应当从下往上填
{
    for (int i = 9; i >= 0; i--) {
        for (int j = 9; j >= 0; j--) {
            if (lin[i][j] != 0)
            {
                continue;
            }
            else {
                do//往下掉
                {
                    for (int k = j; k > 0; k--) {
                        lin[i][k] = lin[i][k-1];
                    }
                    lin[i][0] = rand() % 7 + 1;
                } while (lin[i][j] == 0);
            }
        }
    }
}
//消去方块
void clear(int(&lim)[12][12]) {

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            if (lim[i][j] == 0) {
                continue;
            }
            //横
            int k = 1;
            for (; lim[i][j + k] == lim[i][j]; k++);
            if (k == 3)
            {
                for (int q = 0; q < k; q++)
                {
                    lim[i][j + q] = 0;
                }
            }
            else if (k == 4)
            {
                for (int q = 0; q < k; q++)
                {
                    lim[i][j + q] = 0;
                }
            }
            else if (k == 5)
            {
                for (int q = 0; q < k; q++)
                {
                    lim[i][j + q] = 0;
                }
            }
            //横
            for (k = 1; lim[i + k][j] == lim[i][j]; k++);
            if (k == 3)
            {
                for (int q = 0; q < k; q++)
                {
                    lim[i + q][j] = 0;
                }
            }
            else if (k == 4)
            {
                for (int q = 0; q < k; q++)
                {
                    lim[i + q][j] = 0;
                }
            }
            else if (k == 5)
            {
                for (int q = 0; q < k; q++)
                {
                    lim[i + q][j] = 0;
                }
            }

        }
    }

}
//计算分数
int add(int(&jia)[12][12]) {
    int a = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (jia[i][j] == 0) {
                a++;
            }
        }
    }
    return a;
}
//判断是否可以消去
int exc(int(&lap)[12][12]) {
    int a = 0, b = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            //横

            for (int k = 1; lap[i][j + k] == lap[i][j]; k++)
            {
                if (k >= 2)//map[i][j+1],map[i][j+2]
                {
                    a = k;
                }
                else { continue; }
            }
            //竖

            for (int n = 1; lap[i + n][j] == lap[i][j]; n++) {
                if (n >= 2)//map[i+1][j],map[i+2][j]
                {
                    b = n;
                }
                else { continue; }
            }
        }
    }

    if (a == 0 && b == 0) { return 0; }
    else if (a != 0 && b == 0) { return a; }
    else if (b != 0 && a == 0) { return b; }
    else { return a; }
}
//构建初始界面
#define WIN_WiDHT 600
#define WIN_HEIGHT 600
#define size 50
IMAGE beijing;//背景图片
IMAGE Map[7];
int click ;//点击次数，第二次点击才会交换
int X1, Y1;//第一次点击的坐标
int X2, Y2;//第二次点击的坐标
//定义一个结构体类型，表示方块
struct block {
    int x, y;//方块的坐标
    int we;//方块的数字

};
void init(int(&chu)[12][12]) {
    initgraph(WIN_WiDHT, WIN_HEIGHT);
    
    loadimage(&beijing, L"D:/Program Files (x86)/xiaoxiaole1.0/bj.jpeg",600,600);
    loadimage(&Map[0], L"D:/Program Files (x86)/xiaoxiaole1.0/wind.jpg",50,50);
    loadimage(&Map[1], L"D:/Program Files (x86)/xiaoxiaole1.0/water.jpg",50,50);
    loadimage(&Map[2], L"D:/Program Files (x86)/xiaoxiaole1.0/3.jpg",50,50);
    loadimage(&Map[3], L"D:/Program Files (x86)/xiaoxiaole1.0/4.jpg",50,50);
    loadimage(&Map[4], L"D:/Program Files (x86)/xiaoxiaole1.0/ice.png",50,50);
    loadimage(&Map[5], L"D:/Program Files (x86)/xiaoxiaole1.0/6.jpg",50,50);
    loadimage(&Map[6], L"D:/Program Files (x86)/xiaoxiaole1.0/7.jpg",50,50);
    srand((unsigned)time(NULL));//获取随机数种子
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            chu[i][j] = rand() % 7 + 1;//获取随机数范围从一到七
        }
    }
    click = 0;//click初始化
}

void update(int (&hua)[12][12]) {
    BeginBatchDraw();//开始双缓冲
    putimage(0, 0, &beijing);//画背景
    for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (hua[i][j] !=0 ) {
                        if (hua[i][j] == 1)
                        {
                            putimage(i * 50+50, j * 50+50, &Map[0]);
                        }
                        else if (hua[i][j] == 2)
                        {
                            putimage(i * 50+50, j * 50+50, &Map[1]);
                        }
                        else if (hua[i][j] == 3)
                        {
                            putimage(i * 50+50, j * 50+50, &Map[2]);
                        }
                        else if (hua[i][j] == 4)
                        {
                            putimage(i * 50+50, j * 50+50, &Map[3]);
                        }
                        else if (hua[i][j] == 5)
                        {
                            putimage(i * 50+50, j * 50+50, &Map[4]);
                        }
                        else if (hua[i][j] == 6)
                        {
                            putimage(i * 50+50, j * 50+50, &Map[5]);
                        }
                        else if (hua[i][j] == 7)
                        {
                            putimage(i * 50+50, j * 50+50, &Map[6]);
                        }
                   }
                    
                }
            }
    EndBatchDraw();//结束双缓冲
}
void userClick(int(&play)[12][12]) {
    ExMessage msg;//用来获取鼠标信息
    //有鼠标信息且为按下左键
    int score = 0;
    if (peekmessage(&msg)&&msg.message==WM_LBUTTONDOWN) {
        if ((msg.x <= 550 && msg.x >= 50) && (msg.y <= 550 && msg.y >= 50)) 
        {
            int X = (msg.x-50)/ 50;
            int Y = (msg.y-50) / 50;
            click++;
            if (click == 1) {
                X1 = X;
                Y1 = Y;
                cout << X1 << " " << X2;
            }
            else if (click == 2) {
                X2 = X;
                Y2 = Y;
                
            }
            
           
            //abs表示绝对值
            if (abs(X1-X2)+abs(Y1-Y2)==1) {
                
                int temp = play[X2][Y2];
                play[X2][Y2] = play[X1][Y1];
                play[X1][Y1] = temp;
                
                if (exc(play)) {
                    
                    do {//消去方块
                        clear(play);
                        
                        //显示填充前的空白
                        update(play);
                        //记录分数
                        score = score + add(play);
                        //填充方块
                        fill(play);
                        
                    } while (exc(play) != 0);

                    update(play);
                    //click--;
                }
                else {
                    int tem = play[X2][Y2];
                    play[X2][Y2] = play[X1][Y1];
                    play[X1][Y1] = tem;
                    update(play);
                }
                click = 0;
            }
            else {
                update(play);
                click = 1;
                X1 = X;
                Y1 = Y;
            }
        }
    }
}
int main() {
    int map[12][12] = { 0 };
    init(map);//初始化
    if (exc(map)) {
       do {//消去方块
           clear(map);
           
           //填充方块
           fill(map);
           
       } while (exc(map) != 0);
   }
    
    update(map);
    
    while (1) {
        
        userClick(map);//处理用户的点击
        
            Sleep(10);//后续考虑优化
    }
    
    system("pause");
    return 0;
}

