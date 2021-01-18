#ifndef CMAIN_H
#define CMAIN_H

#include "wx/wx.h"

const int WINDOW_ID_ONE = 999;
const int SUBMIT_BUTTON_ID = 998;
const int DEFAULT_WIDTH = 3;
const int DEFAULT_HEIGHT = 3;
const int DEFAULT_NUM_PLAYERS = 2;
const int DEFAULT_WIN_LEN = 3;


class cMain : public wxFrame
{
public:
    cMain();
    ~cMain();

    //EVENT HANDLERS

private:
    int m_height = 3;
    int m_width = 3;
    int m_winLen = 3;

    wxButton **btn = nullptr;
    wxPanel *panel = nullptr;
    wxBoxSizer *box = nullptr;
    wxGridSizer *grid = nullptr;
    wxTextCtrl *m_txt1 = nullptr;
    wxTextCtrl *m_txt2 = nullptr;
    wxTextCtrl *m_txt3 = nullptr;
    wxTextCtrl *m_txt4 = nullptr;
    wxStaticText *m_curr_turn;
    wxString m_turn_string;
    int **m_arr = nullptr;

    int total_moves_made = 0;
    int num_players;

    void OnButtonClicked(wxCommandEvent &evt);

    void OnStartInfoInput(wxCommandEvent &evt);

    int checkWin(void);

    int Reset(void);

    int endMessage(int state);

    wxDECLARE_EVENT_TABLE();

};

#endif //CMAIN_H