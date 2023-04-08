#include "board.h"

using namespace std;

class Snake : public Board {
public:
    int zb[2][100];
    long start;
    int head, tail, grade, score, gamespeed, length, timeover, snake_x, snake_y;
    // arrow ASCII code
    char direction;
    Snake();
    void Move();
 };

Snake::Snake() {
    cout << "\n\n\t\tThe game is about to begin!" << endl;
    for(int i = 3; i >= 0; i--) {
        start = clock();
        while(clock()-start<=1000);
        system("cls");
        if(i > 0) {
            cout << "\n\n\t\tCountdown:" << i << endl;
        }
    }
    for(int i = 1; i <= 3; i++) {
        board_[1][i]='*';
    }
    board_[1][4]='@';
    for(int i = 0; i < 4; i++) {
        zb[0][i] = 1;
        zb[1][i] = i + 1;
    }
}

void Snake::Move()
{
    score = 0;
    head = 3,tail = 0;
    grade = 1, length = 4;
    gamespeed = 500;
    direction = 77;
    while(1) {
        timeover = 1;
        start = clock();
        // FIXME, header file conio.h inavailable in linux
        while((timeover = (clock() - start <= gamespeed)) && !kbhit());
        if(timeover) {
            getch();
            direction = getch();
        }
        switch(direction) {
        // left
        case 72: 
            snake_x = zb[0][head] - 1; 
            snake_y = zb[1][head];
            break;
        // right
        case 80: 
            snake_x= zb[0][head] + 1; 
            snake_y = zb[1][head];
            break;
        // down
        case 75: 
            snake_x= zb[0][head]; 
            snake_y= zb[1][head] - 1;
            break;
        // up
        case 77: 
            snake_x= zb[0][head]; 
            snake_y= zb[1][head]+1;
            break;
        default:
            break;
        }
        if(snake_x==0 || snake_x==21 || snake_y==0 || snake_y==21) {
            cout << "\tGame over!" << endl;
            break;
        }
        if(board_[snake_x][snake_y]!=' '&&!(snake_x==food_x&&snake_y==food_y))
        {
            cout << "\tGame over!" << endl;break;
        }
        if(snake_x==food_x && snake_y==food_y)
        {
            length ++;
            score=score+100;
            if(length>=8)
            {
                length -= 8;
                grade ++;
                if(gamespeed>=200)
                    gamespeed = 550 - grade * 50;
            }
            board_[snake_x][snake_y]= '@';
            board_[zb[0][head]][zb[1][head]] = '*';
            head = (head+1)%100;
            zb[0][head] = snake_x;
            zb[1][head] = snake_y;
            PlaceFood();
            Print(grade,score,gamespeed);
        }
        else
        {
            board_[zb[0][tail]][zb[1][tail]]=' ';
            tail=(tail+1)%100;
            board_[zb[0][head]][zb[1][head]]='*';
            head=(head+1)%100;
            zb[0][head]=snake_x;
            zb[1][head]=snake_y;
            board_[zb[0][head]][zb[1][head]]='@';
            Print(grade,score,gamespeed);
        }
    }
}

int main()
{
    Board cb;
    Snake s;
    s.Move();
}