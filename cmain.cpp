#include "cmain.h"
#include <iostream>
using namespace std;

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
    EVT_BUTTON(SUBMIT_BUTTON_ID, cMain::OnStartInfoInput)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, WINDOW_ID_ONE, "Tic-Tac-Toe", wxPoint(0, 0), wxSize(800, 800))
{
    Reset();
}

cMain::~cMain()
{
}

void cMain::OnButtonClicked(wxCommandEvent &evt)
{
    int x = (evt.GetId() - 10000) % m_height;
    int y = (evt.GetId() - 10000) / m_height;

    int curr_player = (total_moves_made % num_players) + 1;
    int next_player = ((total_moves_made + 1) % num_players) + 1;
    m_turn_string = wxString::Format(wxT("Player %i's turn"), next_player);
    m_curr_turn->SetLabel(m_turn_string);
    m_curr_turn->Refresh();

    btn[x + y * m_height]->Enable(false);
    btn[x + y * m_height]->SetLabel(wxString::Format(wxT("%i"), curr_player));
    m_arr[y][x] = curr_player;

    for (int i = 0 ; i < m_width; i++)
    {
        for (int j = 0; j < m_height; j++)
        {
            cout << m_arr[i][j];
        }

        cout << endl;
    }
    

    int winner = checkWin();    

    cerr << winner << endl;

    if (winner != -1)
    {
        //endMessage(winner);
        cerr << "you won\n";
        cerr << winner << endl;
        panel->Destroy();
    }
    
    total_moves_made++;

    if (total_moves_made == (m_height * m_width))
    {
        //endMessage(0);
        cerr << "draw\n";
        panel->Destroy();
    }
}

void cMain::OnStartInfoInput(wxCommandEvent &evt)
{
    if (!m_txt1->GetValue().IsEmpty())
        num_players = wxAtoi(m_txt1->GetValue());
    else
        num_players = DEFAULT_NUM_PLAYERS;
    if (!m_txt2->GetValue().IsEmpty())
        m_winLen = wxAtoi(m_txt2->GetValue());
    else
        m_winLen = DEFAULT_WIN_LEN;
    if (!m_txt3->GetValue().IsEmpty())
        m_width = wxAtoi(m_txt3->GetValue());
    else
        m_width = DEFAULT_WIDTH;
    if (!m_txt4->GetValue().IsEmpty())
        m_height = wxAtoi(m_txt4->GetValue());
    else
        m_height = DEFAULT_HEIGHT; 


    panel->Destroy();

    panel = new wxPanel(this, wxID_ANY);
    box = new wxBoxSizer(wxVERTICAL);
    btn = new wxButton*[m_height * m_width];
    grid = new wxGridSizer(m_height, m_width, 0, 0);
    m_arr = new int*[m_height];
    m_turn_string = wxString::Format(wxT("Player %i's turn"), 1);
    m_curr_turn = new wxStaticText(panel, wxID_ANY, m_turn_string, wxDefaultPosition, wxSize(100, 50), wxALIGN_CENTER_HORIZONTAL);
    box->Add(m_curr_turn);

    for (int i = 0; i < m_height; i++)
    {
        m_arr[i] = new int[m_height];
        for (int j = 0; j < m_width; j++)
        {
            btn[j + i * m_height] = new wxButton(panel, (10000 + j + (i * m_height)));
            grid->Add(btn[j + i * m_height], 1, wxEXPAND | wxALL);

            btn[j + i * m_height]->Bind(wxEVT_BUTTON, &cMain::OnButtonClicked, this);
            m_arr[i][j] = 0;
        }
    }

    box->Add(grid);
    panel->SetSizerAndFit(box);
    grid->Layout();
    box->Layout();
    //this->SetSize(0, 0, 860, 860);
    this->CentreOnScreen();
    panel->SetSize(this->GetClientSize());
    box->SetDimension(wxDefaultPosition, panel->GetClientSize());
    box->Layout();

    if (this->GetClientSize() == panel->GetClientSize())
    {
        cout << "YASSSSSS\n";
    }

    
}

int cMain::Reset(void)
{
    panel = new wxPanel(this, wxID_ANY);
    box = new wxBoxSizer(wxVERTICAL);
    grid = new wxGridSizer(4, 2, 0, 0);

    m_txt1 = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(50, 30));
    m_txt2 = new wxTextCtrl(panel, wxID_ANY, "");
    m_txt3 = new wxTextCtrl(panel, wxID_ANY, "");
    m_txt4 = new wxTextCtrl(panel, wxID_ANY, "");

    box->Add(new wxStaticText(panel, wxID_ANY, "\n\nWelcome to Tic-Tac-Toe!\n\nPlease enter the game settings below to your liking", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL), 1, wxEXPAND | wxALL);

    grid->Add(new wxStaticText(panel, wxID_ANY, "\n\nNumber of players: ", wxPoint(10, 10), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL), 1, wxEXPAND | wxALL);
    grid->Add(m_txt1, 1, wxEXPAND | wxALL);
    grid->Add(new wxStaticText(panel, wxID_ANY, "\n\nWin length: ", wxPoint(10, 10), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL), 1, wxEXPAND | wxALL);
    grid->Add(m_txt2, 1, wxEXPAND | wxALL);    
    grid->Add(new wxStaticText(panel, wxID_ANY, "\n\nBoard width: ", wxPoint(10, 10), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL), 1, wxEXPAND | wxALL);
    grid->Add(m_txt3, 1, wxEXPAND | wxALL);
    grid->Add(new wxStaticText(panel, wxID_ANY, "\n\nBoard height: ", wxPoint(10, 10), wxDefaultSize, wxALIGN_CENTER_HORIZONTAL), 1, wxEXPAND | wxALL);
    grid->Add(m_txt4, 1, wxEXPAND | wxALL);
    //grid->Add(new wxButton(panel, SUBMIT_BUTTON_ID, "Submit"), 1, wxEXPAND | wxALL, 100);
    
    box->Add(grid);
    box->Add(new wxButton(panel, SUBMIT_BUTTON_ID, "Submit",  wxDefaultPosition, wxSize(50, 30)), 1, wxEXPAND | wxALL);

    panel->SetSizer(box);
    grid->Layout();
    box->Layout();
    panel->Show(true);
}

int cMain::endMessage(int state)
{
    panel->Destroy();
    panel = new wxPanel(this, wxID_ANY);

    // draw
    if (state == 0)
    {
        

    }
}

int cMain::checkWin(void)
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

        //cerr << "Finish across\n";

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

        //cerr << "Finish left column topleft->bottomright 4 o'clock\n";

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

        //cerr << "Finish left column (bottomleft -> topright) 2 O'clock\n";

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

        //cerr << "Finish diagonal (bottomleft -> topright) 11 O'clock\n";

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

        //cerr << "Finish diagonal (topright -> bottomleft) 8 O'clock\n";
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
    //cerr << "Finish down checking\n";

    return -1;
}



