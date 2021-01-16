#ifndef TTT_H
#define TTT_H

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
using namespace std;


class TTT
{
    public:
        TTT(void);
        TTT(int width, int height, int numPlayers, int winLen);
        ~TTT(void);
        void display(void);
        bool makeMove(int width, int height, int player);
        int checkWin(void);
        void start(void);



    private:
        int **m_arr;
        int m_width;
        int m_height;
        int m_winLen;
        int m_numPlayers;
};





#endif // TTT_H