#include<iostream>
#include<graphics.h>//����ͼ�ο�ͷ�ļ�
#include<conio.h>
#include<stdio.h>
#include<math.h>
using namespace std;
//���հ�
//������ʼ����
#define WIN_WiDHT 600
#define WIN_HEIGHT 600
#define size 50
IMAGE beijing;//����ͼƬ
IMAGE Map[11];
IMAGE end2;
int click;//����������ڶ��ε���Żύ��
int X1, Y1;//��һ�ε��������
int X2, Y2;//�ڶ��ε��������
void init(int(&chu)[12][12]) {
    initgraph(WIN_WiDHT, WIN_HEIGHT);

    loadimage(&beijing, "D:/Program Files (x86)/xiaoxiaole1.0/bj.jpeg", 600, 600);
    loadimage(&Map[0], "D:/Program Files (x86)/xiaoxiaole1.0/wind.jpg", 50, 50);
    loadimage(&Map[1], "D:/Program Files (x86)/xiaoxiaole1.0/water.jpg", 50, 50);
    loadimage(&Map[2], "D:/Program Files (x86)/xiaoxiaole1.0/3.jpg", 50, 50);
    loadimage(&Map[3], "D:/Program Files (x86)/xiaoxiaole1.0/4.jpg", 50, 50);
    loadimage(&Map[4], "D:/Program Files (x86)/xiaoxiaole1.0/ice.png", 50, 50);
    loadimage(&Map[5], "D:/Program Files (x86)/xiaoxiaole1.0/6.jpg", 50, 50);
    loadimage(&Map[6], "D:/Program Files (x86)/xiaoxiaole1.0/7.jpg", 50, 50);
    loadimage(&Map[7], "D:/Program Files (x86)/xiaoxiaole1.0/heng.jpg", 50, 50);
    loadimage(&Map[8], "D:/Program Files (x86)/xiaoxiaole1.0/shu.jpg", 50, 50);
    loadimage(&Map[9], "D:/Program Files (x86)/xiaoxiaole1.0/boom.jpg", 50, 50);
    loadimage(&Map[10], "D:/Program Files (x86)/xiaoxiaole1.0/15.jpg", 50, 50);
    loadimage(&end2, "D:/Program Files (x86)/xiaoxiaole1.0/end.jpg", 600, 600);
    settextstyle(45, 30, _T("����"));
    srand((unsigned)time(NULL));//��ȡ���������
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            chu[i][j] = rand() % 7 + 1;//��ȡ�������Χ��һ����
        }
    }
    click = 0;//click��ʼ��

}

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
                        
                        for (int a = 0; a < 50; a++) {
                            BeginBatchDraw();
                            
                            if(lin[i][k - 1]==1) 
                            {
                                putimage(i * 50 + 50, k * 50 +a, &Map[0]);
                            }
                            else if (lin[i][k - 1] == 2)
                            {
                                putimage(i * 50 + 50, k * 50 + a, &Map[1]);
                            }
                            else if (lin[i][k - 1] == 3)
                            {
                                putimage(i * 50 + 50, k * 50 + a , &Map[2]);
                            }
                            else if (lin[i][k - 1] == 4)
                            {
                                putimage(i * 50 + 50, k * 50 + a, &Map[3]);
                            }
                            else if (lin[i][k - 1] == 5)
                            {
                                putimage(i * 50 + 50, k * 50 + a , &Map[4]);
                            }
                            else if (lin[i][k - 1] == 6)
                            {
                                putimage(i * 50 + 50, k * 50 + a , &Map[5]);
                            }
                            else if (lin[i][k - 1] == 7)
                            {
                                putimage(i * 50 + 50, k * 50 + a , &Map[6]);
                            }
                            else if (lin[i][k - 1] == 8)
                            {
                                putimage(i * 50 + 50, k * 50 + a , &Map[7]);
                            }
                            else if (lin[i][k - 1] == 9)
                            {
                                putimage(i * 50 + 50, k * 50 + a , &Map[8]);
                            }
                            else if (lin[i][k - 1] == 10)
                            {
                                putimage(i * 50 + 50, k * 50 + a, &Map[9]);
                            }
                            else if (lin[i][k - 1] == 11)
                            {
                                putimage(i * 50 + 50, k * 50 + a , &Map[10]);
                            }
                        }
                        Sleep(8);
                        EndBatchDraw();
                        lin[i][k] = lin[i][k - 1];
                    }
                    lin[i][0] = rand() % 7 + 1;
                } while (lin[i][j] == 0);
            }
        }
    }
}
//��ȥ����
void clear(int(&lim)[12][12]) {
    srand((unsigned)time(NULL));
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
                for (int q = 1; q < k; q++)
                    {
                        lim[i][j + q] = 0;
                    }
                    lim[i][j] = rand() % 3 + 8;
                
            }
            else if (k == 5)
            {
                for (int q = 1; q < k; q++)
                {
                    lim[i][j + q] = 0;
                }
                lim[i][j] = 11;
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
                for (int q = 1; q < k; q++)
                    {
                        lim[i + q][j] = 0;
                    }
                    lim[i][j] = rand()%3+8;
            }
            else if (k == 5)
            {
                for (int q = 1; q < k; q++)
                {
                    lim[i + q][j] = 0;
                }
                lim[i][j] = 11;
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

//��ȥĳһ�ض����͵ķ���
void yuan(int a, int(&qw)[12][12]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (qw[i][j] == a) {
                qw[i][j] = 0;
            }
        }
    }
}
void quan(int(&qu)[12][12]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            qu[i][j] = 0;
        }
    }
}
void heng(int a, int(&er)[12][12]) {
    for (int i = 0; i < 10; i++) {
        er[i][a] = 0;
    }
}
void shu(int a, int(&rt)[12][12]) {
    for (int j = 0; j < 10; j++) {
        rt[a][j] = 0;
    }
}
void boom(int a, int b, int(&ty)[12][12]) {
    ty[a][b] = 0; ty[a+1][b] = 0;
    ty[a+2][b] = 0; ty[a-1][b] = 0;
    ty[a-2][b] = 0; ty[a][b+1] = 0;
    ty[a][b+2] = 0; ty[a][b-1] = 0;
    ty[a][b-2] = 0; ty[a+1][b+1] = 0;
    ty[a-1][b-1] = 0; ty[a+1][b-1] = 0;
    ty[a-1][b+1] = 0;
}
int score=0;
void update(int(&hua)[12][12]) {
    BeginBatchDraw();//��ʼ˫����
    putimage(0, 0, &beijing);//������
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (hua[i][j] != 0) {
                if (hua[i][j] == 1)
                {
                    putimage(i * 50 + 50, j * 50 + 50, &Map[0]);
                }
                else if (hua[i][j] == 2)
                {
                    putimage(i * 50 + 50, j * 50 + 50, &Map[1]);
                }
                else if (hua[i][j] == 3)
                {
                    putimage(i * 50 + 50, j * 50 + 50, &Map[2]);
                }
                else if (hua[i][j] == 4)
                {
                    putimage(i * 50 + 50, j * 50 + 50, &Map[3]);
                }
                else if (hua[i][j] == 5)
                {
                    putimage(i * 50 + 50, j * 50 + 50, &Map[4]);
                }
                else if (hua[i][j] == 6)
                {
                    putimage(i * 50 + 50, j * 50 + 50, &Map[5]);
                }
                else if (hua[i][j] == 7)
                {
                    putimage(i * 50 + 50, j * 50 + 50, &Map[6]);
                }
                else if (hua[i][j] == 8)
                {
                    putimage(i * 50 + 50, j * 50 + 50, &Map[7]);
                }
                else if (hua[i][j] == 9)
                {
                    putimage(i * 50 + 50, j * 50 + 50, &Map[8]);
                }
                else if (hua[i][j] == 10)
                {
                    putimage(i * 50 + 50, j * 50 + 50, &Map[9]);
                }
                else if (hua[i][j] == 11)
                {
                    putimage(i * 50 + 50, j * 50 + 50, &Map[10]);
                }
            }

        }
    }
    settextcolor(RGB(255, 0, 0));
    setbkmode(TRANSPARENT);
    char scorestr[16];
    sprintf_s(scorestr, sizeof(scorestr), "%d", score);
    int x = 450 + (75 - strlen(scorestr) * 20) / 2;
    outtextxy(320, 5, "�÷֣�");
    outtextxy(x, 5, scorestr);
    EndBatchDraw();//����˫����
}
int ove=0;

void userClick(int(&play)[12][12]) {
    ExMessage msg;//������ȡ�����Ϣ
    //�������Ϣ��Ϊ�������
    if (peekmessage(&msg) && msg.message == WM_LBUTTONDOWN) {
        if ((msg.x <= 550 && msg.x >= 50) && (msg.y <= 550 && msg.y >= 50))
        {
            int X = (msg.x - 50) / 50;
            int Y = (msg.y - 50) / 50;
            click++;
            if (click == 1) {
                X1 = X;
                Y1 = Y;
            }
            else if (click == 2) {
                X2 = X;
                Y2 = Y;
            }
            //abs��ʾ����ֵ
            if (abs(X1 - X2) + abs(Y1 - Y2) == 1) {
                int temp = play[X2][Y2];
                play[X2][Y2] = play[X1][Y1];
                play[X1][Y1] = temp;
                if ((play[X1][Y1] - 7 > 0) || (play[X2][Y2] - 7 > 0)) 
                {
                    if (play[X1][Y1] == 11 || play[X2][Y2] == 11) 
                    {
                        if (play[X1][Y1] == 11 && play[X2][Y2] != 11) {
                            yuan(play[X2][Y2], play); play[X1][Y1] = 0;
                        }
                        else if (play[X1][Y1] != 11 && play[X2][Y2] == 11) {
                            yuan(play[X1][Y1], play); play[X2][Y2] = 0;
                        }
                        else if (play[X1][Y1] == 11 && play[X2][Y2] == 11) { quan(play); }
                        score = score + add(play);
                        ove++;
                        fill(play);
                        do {
                            clear(play);
                            score = score + add(play);
                            fill(play);
                            
                        } while (exc(play) != 0);
                    }
                    else if (play[X1][Y1] == 8 || play[X2][Y2] == 8) 
                    {
                        if (play[X1][Y1] == 8 && play[X2][Y2] != 8) {
                            heng(Y1, play); play[X1][Y1] = 0;
                        }
                        else if (play[X1][Y1] != 8 && play[X2][Y2] == 8) {
                            heng(Y2, play); play[X2][Y2] = 0;
                        }
                        else if (play[X1][Y1] == 8 && play[X2][Y2] == 8) { quan(play); }
                        score = score + add(play);
                        ove++;
                        fill(play);
                        do {
                            clear(play);
                            score = score + add(play);
                            fill(play);
                            
                        } while (exc(play) != 0);
                    }
                    else if (play[X1][Y1] == 9 || play[X2][Y2] == 9)
                    {
                        if (play[X1][Y1] == 9 && play[X2][Y2] != 9) {
                            shu(X1, play); play[X1][Y1] = 0;
                        }
                        else if (play[X1][Y1] != 9 && play[X2][Y2] == 9) {
                            shu(X2, play); play[X2][Y2] = 0;
                        }
                        else if (play[X1][Y1] == 9 && play[X2][Y2] == 9) { quan(play); }
                        score = score + add(play);
                        ove++;
                        fill(play);
                        do {
                            clear(play);
                            score = score + add(play);
                            fill(play);
                            
                        } while (exc(play) != 0);
                    }
                    else if (play[X1][Y1] == 10 || play[X2][Y2] == 10)
                    {
                        if (play[X1][Y1] == 10 && play[X2][Y2] != 10) { boom(X1,Y1, play); }
                        else if (play[X1][Y1] != 10 && play[X2][Y2] == 10) { boom(X2,Y2, play); }
                        else if (play[X1][Y1] == 10 && play[X2][Y2] == 10) { quan(play); }
                        score = score + add(play);
                        ove++;
                        fill(play);
                        do {
                            clear(play);
                            score = score + add(play);
                            fill(play);
                            
                        } while (exc(play) != 0);
                    }
                    update(play);
                }
                else if (exc(play)) {
                    ove++;
                    do {//��ȥ����
                        clear(play);
                        //��¼����
                        score = score + add(play);
                        //��ʾ���ǰ�Ŀհ�
                        update(play);
                        
                        //��䷽��
                        fill(play);
                        //��¼��Ч�ƶ�����
                        
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
            clear(map);//��䷽��
            fill(map);
        } while (exc(map) != 0);
    }
    update(map);
    while (1) {

        userClick(map);//�����û��ĵ��
        if (ove >= 15) {
            putimage(0, 0, &end2);
            char scorestr[16];
            sprintf_s(scorestr, sizeof(scorestr), "%d", score);
            int x = 220 + (75 - strlen(scorestr) * 20) / 2;
            outtextxy(120, 200, "��Ϸ����������");
            outtextxy(80, 250, "�÷֣�");
            outtextxy(x, 250, scorestr);
        }
        Sleep(10);
    
    }
    
    system("pause");
    return 0;
}

