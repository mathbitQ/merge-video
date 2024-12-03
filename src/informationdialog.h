/*
    File: informationdialog.h
    Date created: August 2024
    Author: mathbitQ
    Description: Creates a small window to pop up to
                 give information about the software
                 Requires wxWidgets library.
    Version: 1.0
*/

#ifndef INFORMATIONDIALOG_H_INCLUDED
#define INFORMATIONDIALOG_H_INCLUDED

#include <wx/dialog.h>
#include <wx/wx.h>

class InformationDialog : public wxDialog
{
public:
    InformationDialog(wxWindow *parent,
                     wxWindowID id,
                     const wxString& title,
                     const wxPoint &pos = wxDefaultPosition,
                     const wxSize &size = wxDefaultSize,
                     long style = wxDEFAULT_DIALOG_STYLE,
                     const wxString& name = wxASCII_STR(wxDialogNameStr));
    virtual ~InformationDialog();
    void SetDescription(wxString desc);
private:
    wxStaticText *description;
    void OnCloseButtonClicked(wxCommandEvent &evt);
};

#endif // INFORMATIONDIALOG_H_INCLUDED
