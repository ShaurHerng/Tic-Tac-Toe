#include <iostream>
using namespace std;

int checkWin(int **m_arr)
{
    int m_width = 5;
    int m_height = 5;
    int temp = 0;
    int tempH = 0;
    int tempW = 0;
    int len = 0;
    int m_winLen = 3;
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

// logic for any sized boards??
// I should fix this first actually lmaoo

int main()
{
/*
    int num[] = {0, 0, 0, 0, 0, 
                 0, 0, 0, 0, 0, 
                 0, 0, 0, 0, 0, 
                 0, 0, 0, 0, 0, 
                 0, 0, 0, 0, 0};
*/
    int num[] = {0, 0, 0, 0, 0, 
                 0, 0, 2, 0, 1, 
                 0, 0, 0, 2, 0, 
                 0, 0, 2, 0, 0, 
                 0, 2, 0, 0, 0};

    int **arr = new int*[5];
    for (int i = 0; i < 5; ++i)
    {
        arr[i] = new int[5];
        for (int j = 0; j < 5; ++j)
        {
            arr[i][j] = num[i * 5 + j];
        }
    }

    cout << checkWin(arr);

}

