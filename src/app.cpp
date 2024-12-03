/*
    File: app.cpp
    Date created: August 2024
    Author: mathbitQ
    Description: Main core of the program using wxApp from wxWidgets. All initialization
                 goes here.
    Version: 1.0
*/

#include "app.h"
#include "mainframe.h"
#include <wx/wx.h>

//Initialize main program with fixed border to prevent from resizing and maximizing the window
bool App::OnInit()
{
    MainFrame *mainFrame = new MainFrame("Merge Video");
    mainFrame->SetWindowStyle(wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX));
    wxIcon mainIcon;
    mainIcon.LoadFile("./resource/logo.ico", wxBITMAP_TYPE_ICO);
    mainFrame->SetIcon(mainIcon);

    mainFrame->Show();
    return true;
}
