#include<iostream>
#include<graphics.h>//����ͼ�ο�ͷ�ļ�
#include<conio.h>
#include<stdio.h>
#include<math.h>
using namespace std;
//���հ�
void fill(int(&lin)[12][12])//��������Ĳ���,Ӧ������������
{
    for (int i = 9; i >= 0; i--) {
        for (int j = 9; j >= 0; j--) {
            if (lin[i][j] != 0)
            {
                continue;
            }
            else {
                do//���µ�
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
//��ȥ����
void clear(int(&lim)[12][12]) {

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            if (lim[i][j] == 0) {
                continue;
            }
            //��
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
            //��
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
//�������
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
//�ж��Ƿ������ȥ
int exc(int(&lap)[12][12]) {
    int a = 0, b = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            //��

            for (int k = 1; lap[i][j + k] == lap[i][j]; k++)
            {
                if (k >= 2)//map[i][j+1],map[i][j+2]
                {
                    a = k;
                }
                else { continue; }
            }
            //��

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
//������ʼ����
#define WIN_WiDHT 600
#define WIN_HEIGHT 600
#define size 50
IMAGE beijing;//����ͼƬ
IMAGE Map[7];
int click ;//����������ڶ��ε���Żύ��
int X1, Y1;//��һ�ε��������
int X2, Y2;//�ڶ��ε��������
//����һ���ṹ�����ͣ���ʾ����
struct block {
    int x, y;//���������
    int we;//���������

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
    srand((unsigned)time(NULL));//��ȡ���������
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            chu[i][j] = rand() % 7 + 1;//��ȡ�������Χ��һ����
        }
    }
    click = 0;//click��ʼ��
}

void update(int (&hua)[12][12]) {
    BeginBatchDraw();//��ʼ˫����
    putimage(0, 0, &beijing);//������
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
    EndBatchDraw();//����˫����
}
void userClick(int(&play)[12][12]) {
    ExMessage msg;//������ȡ�����Ϣ
    //�������Ϣ��Ϊ�������
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
            
           
            //abs��ʾ����ֵ
            if (abs(X1-X2)+abs(Y1-Y2)==1) {
                
                int temp = play[X2][Y2];
                play[X2][Y2] = play[X1][Y1];
                play[X1][Y1] = temp;
                
                if (exc(play)) {
                    
                    do {//��ȥ����
                        clear(play);
                        
                        //��ʾ���ǰ�Ŀհ�
                        update(play);
                        //��¼����
                        score = score + add(play);
                        //��䷽��
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
    init(map);//��ʼ��
    if (exc(map)) {
       do {//��ȥ����
           clear(map);
           
           //��䷽��
           fill(map);
           
       } while (exc(map) != 0);
   }
    
    update(map);
    
    while (1) {
        
        userClick(map);//�����û��ĵ��
        
            Sleep(10);//���������Ż�
    }
    
    system("pause");
    return 0;
}

