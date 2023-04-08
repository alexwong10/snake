#include <time.h>
#include <cstdlib>
#include <iostream>

const int HEIGHT = 22;
const int WIDTH = 22;

class Board {
public:
    Board();
    void PlaceFood();
    void Print(int grade,int score,int speed);
    char board_[HEIGHT][WIDTH];
    int food_x, food_y;
};

Board::Board() {
    for(int i = 1; i < HEIGHT - 1; i++) {
        for(int j = 1 ; j < WIDTH - 1; j++) {
            board_[i][j]=' ';
        }
    } 
        
    for(int i = 0; i < WIDTH - 1; i++) {
        board_[0][i] = board_[HEIGHT - 1][i] = '#';
    }

    for(int i = 1; i < HEIGHT - 1; i++) {
        board_[i][0] = board_[i][WIDTH - 1] = '#';
    }

    PlaceFood();
}

void Board::PlaceFood() {
    srand(time(0));
    do {
        food_x = rand() % HEIGHT - 1;
        food_y = rand() % WIDTH - 1;
    } while(board_[food_x][food_y]  != ' ');
    board_[food_x ] [food_y ] ='$';
}

void Board::Print(int grade,int score,int speed) {
    system("cls");
    std::cout << std::endl;
    for(int i = 0; i < HEIGHT; i++) {
        std::cout << "\t";
        for(int j = 0; j < WIDTH; j++) {
            std::cout << board_[i][j] << ' ';
        }
        switch (i) {
        case 0:
            std::cout << "\tGrade:" << grade;
            break;
        case 2:
            std::cout << "\tScore:" << score;
            break;
        case 4:
            std::cout << "\tAutomatic forward";
            break;    
        case 5:
            std::cout << "\ttime interval:" << speed << "ms";
            break;      
        default:
            break;
        }
        std::cout << std::endl;
    }
}
