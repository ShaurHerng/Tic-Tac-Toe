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

int TTT::checkWin()
{
    int temp = 0;
    int tempH = 0;
    int tempW = 0;
    int len = 0;
    int m_currentPlayer;
    bool m_isStart = true;

    for (tempH = 0; tempH < m_height; ++tempH)
    {
        tempW = 0;
        m_isStart = true;

        // win check for across (all dimensions)
        while(tempW < m_width)
        {
            if (m_isStart)
            {
                if (m_arr[tempH][tempW] != 0)
                {
                    m_currentPlayer = m_arr[tempH][tempW];
                    m_isStart = false;
                    len = 1;
                    ++tempW;
                }
                else
                {
                    ++tempW;
                }
                
                
            }
            else if (m_arr[tempH][tempW] == m_currentPlayer)
            {
                ++len;
                ++tempW;
            }
            else 
            {
                m_isStart = true; 
            }

            if (len == m_winLen)
            {
                return m_currentPlayer;
            }
        }

        cerr << "Finish across\n";

        temp = 0;
        tempW = 0;
        m_isStart = true;

        // win check for diagonal from the left column (topleft -> bottomright) 4 O'clock
        while (tempH + temp < m_height && tempW < m_width)
        {
            if (m_isStart)
            {
                if (m_arr[tempH + temp][tempW] != 0)
                {
                    m_isStart = false;
                    m_currentPlayer = m_arr[tempH + temp][tempW];
                    tempW++;
                    temp++;
                    len = 1;
                }
                else
                {
                    tempW++;
                    temp++;
                }
                
            }
            else if (m_arr[tempH + temp][tempW] == m_currentPlayer)
            {
                len++;
                temp++;
                tempW++;
            }
            else
            {
                m_isStart = true;
            }

            if (len == m_winLen)
            {
                return m_currentPlayer;
            }
        }

        cerr << "Finish left column topleft->bottomright 4 o'clock\n";

        temp = 0;
        tempW = 0;
        m_isStart = true;

        // win check for diagonal from the left column (bottomleft -> topright) 2 O'clock
        while (tempH - temp >= 0 && tempW < m_width)
        {
            if (m_isStart)
            {
                if (m_arr[tempH - temp][tempW] != 0)
                {
                    m_isStart = false;
                    m_currentPlayer = m_arr[tempH - temp][tempW];
                    tempW++;
                    temp++;
                    len = 1;
                }
                else
                {
                    tempW++;
                    temp++;
                }
                
            }
            else if (m_arr[tempH - temp][tempW] == m_currentPlayer)
            {
                len++;
                temp++;
                tempW++;
            }
            else
            {
                m_isStart = true;
            }

            if (len == m_winLen)
            {
                return m_currentPlayer;
            }
        }

        cerr << "Finish left column (bottomleft -> topright) 2 O'clock\n";

        temp = 0;
        tempW = m_width - 1;
        m_isStart = true;        

        // win check for diagonal (bottomleft -> topright) 11 O'clock
        if (tempH != m_height - 1)
        {
            while (tempH - temp >= 0 && tempW > 0)
            {
                if (m_isStart)
                {
                    if (m_arr[tempH - temp][tempW] != 0)
                    {
                        m_isStart = false;
                        m_currentPlayer = m_arr[tempH - temp][tempW];
                        tempW--;
                        temp++;
                        len = 1;
                    }
                    else
                    {
                        tempW--;
                        temp++;
                    }
                    
                }
                else if (m_arr[tempH - temp][tempW] == m_currentPlayer)
                {
                    len++;
                    temp++;
                    tempW--;
                }
                else
                {
                    m_isStart = true;
                }

                if (len == m_winLen)
                {
                    return m_currentPlayer;
                }   
            }
        }

        cerr << "Finish diagonal (bottomleft -> topright) 11 O'clock\n";

        temp = 0;
        tempW = m_width - 1;
        m_isStart = true;        

        // win check for diagonal (topright -> bottomleft) 8 O'clock
        if (tempH != 0)
        {
            while (tempH + temp < m_height && tempW > 0)
            {
                if (m_isStart)
                {
                    if (m_arr[tempH + temp][tempW] != 0)
                    {
                        m_isStart = false;
                        m_currentPlayer = m_arr[tempH + temp][tempW];
                        tempW--;
                        temp++;
                        len = 1;
                    }
                    else
                    {
                        tempW--;
                        temp++;
                    }
                    
                }
                else if (m_arr[tempH + temp][tempW] == m_currentPlayer)
                {
                    len++;
                    temp++;
                    tempW--;
                }
                else
                {
                    m_isStart = true;
                }

                if (len == m_winLen)
                {
                    return m_currentPlayer;
                }   
            }
        }

        cerr << "Finish diagonal (topright -> bottomleft) 8 O'clock\n";
    }
    // win check for down (all dimensions)
    for (tempW = 0; tempW < m_width; ++tempW)
    {
        tempH = 0;
        m_isStart = true;

        while(tempH < m_height)
        {
            if (m_isStart)
            {
                if (m_arr[tempH][tempW] != 0)
                {
                    m_currentPlayer = m_arr[tempH][tempW];
                    m_isStart = false;
                    len = 1;
                    ++tempH;
                }
                else
                {
                    tempH++;
                }
                
                
            }
            else if (m_arr[tempH][tempW] == m_currentPlayer)
            {
                ++len;
                ++tempH;
            }
            else 
            {
                m_isStart = true; 
            }

            if (len == m_winLen)
            {
                return m_currentPlayer;
            }
        }
    }
    cerr << "Finish down checking\n";

    return false;
}

void TTT::start(void)
{
    int temp = 0;
    int tempH, tempW;
    int winner = 0;

    while(!winner)
    {
        system("clear");

        display();

        do
        {

            cout << "Player " << (temp % m_numPlayers) + 1 << " please enter width & height: ";
            cin >> tempW >> tempH;


        } while(!makeMove(tempW, tempH, (temp % m_numPlayers) + 1));

        temp++;

        winner = checkWin();

    }

    system("clear");
    cout << "Game Finished!!\n";
    cout << "Player " << winner << " Won!!!\n\n";
}