/*
    File: app.h
    Date created: August 2024
    Author: mathbitQ
    Description: Main core of the program using wxApp from wxWidgets
    Version: 1.0
*/
#ifndef APP_H
#define APP_H

#include <wx/wx.h>

// Main program using with wxWidgets wxApp
class App : public wxApp
{
public:
    virtual bool OnInit();
};

#endif // APP_H
