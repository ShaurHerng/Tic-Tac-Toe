#include "ttt.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
using namespace std;


TTT::TTT(void)
{
    m_width = 3;
    m_height = 3;
    m_numPlayers = 2;
    m_winLen = 3;
    m_arr = new int*[m_height];

    for (int i = 0; i < m_height; ++i)
    {
        m_arr[i] = new int[m_width];
    }

    start();
}



TTT::TTT(int width, int height, int numPlayers, int winLen)
{
    m_width = width;
    m_height = height;
    m_numPlayers = numPlayers;
    m_winLen = winLen;
    m_arr = new int*[m_height];

    for (int i = 0; i < m_height; ++i)
    {
        m_arr[i] = new int[m_width];
    }

    start();
}



TTT::~TTT(void)
{
    for (int i = 0; i < m_height; ++i)
    {
        delete m_arr[i];
    }
}



void TTT::display(void)
{
    for (int i = 0; i < m_height; ++i)
    {
        for (int j = 0; j < m_width; ++j)
        {
            cout << m_arr[i][j] << " ";
        }

        cout << "\n";
    }
}



bool TTT::makeMove(int width, int height, int player)
{
    if (!m_arr[height][width])
    {
        m_arr[height][width] = player;
        return true;
    }

    return false;
}



int TTT::checkWin(void)
{
    int temp, tempH, tempW;

    // check win conditions (across)
    for (tempH = 0; tempH < m_height; ++tempH)
    {
        for (tempW = 0; tempW < m_width; ++tempW)
        {
            if (m_arr[tempH][tempW] == 0 || m_arr[tempH][tempW] != m_arr[tempH][0])
            {
                break;
            }

            if (tempW == m_winLen - 1)
            {
                cout << "Player " << m_arr[tempH][0] << " won!\n";
                return 1;
            }
        }
    }

    // check win conditions (down)
    for (tempW = 0; tempW < m_width; ++tempW)
    {
        for (tempH = 0; tempH < m_width; ++tempH)
        {
            if (m_arr[tempH][tempW] == 0 || m_arr[tempH][tempW] != m_arr[0][tempW])
            {
                break;
            }

            if (tempH == m_winLen - 1)
            {
                cout << "Player " << m_arr[0][tempW] << " won!\n";
                return 1;
            }
        }
    }

    tempW = tempH = 0;

    
    // check win conditions (diagonal) for perfect squares
    for (tempH = tempW = 0; tempH < m_height; tempW++, tempH++)
    {
        if (m_arr[tempH][tempW] != 0 && m_arr[tempH][tempW] == m_arr[0][0])
        {
            if (tempH == m_winLen - 1)
            {
                cout << "Player " << m_arr[0][0] << " won!\n";
                return 1;
            }  
        }
        else if (m_arr[m_height - 1 - tempH][m_width - 1 - tempW] != 0 && m_arr[m_height - tempH - 1][m_width - tempW - 1] == m_arr[0][m_width - 1])
        {
            if (tempH == 0)
            {
                cout << "Player " << m_arr[0][m_width - 1] << " won!\n";
                return 1;
            }
        }
    }
    
   return 0;
}



void TTT::start(void)
{
    int temp = 0;
    int tempH, tempW;

    while(!checkWin())
    {
        system("clear");

        display();

        do
        {

            cout << "Player " << (temp % 3) + 1 << " please enter width & height: ";
            cin >> tempW >> tempH;


        } while(!makeMove(tempW, tempH, (temp % 3) + 1));

        temp++;

    }

    cout << "Game Finished!!\n";
}