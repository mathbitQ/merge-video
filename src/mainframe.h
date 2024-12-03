/*
    File: mainframe.h
    Date created: August 2024
    Author: mathbitQ
    Description: A main core of the software. This includes
                 controlling files (from import folder, file,
                 remove, clear all file list), setting (
                 choosing number of video to export, random
                 video that will be merged, changing bit rate,
                 constant bit rate, buffer size of bit rate, frame
                 rate, include tracklist).
                 Requires wxWidgets, FFmpeg and other headers file
                 to support the main program.
                 Currently support only ".mp4" file, will be added
                 in the future. *** Maybe for a long time ***
    Version: 1.0
*/

#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/font.h>
#include <wx/spinctrl.h>
#include <wx/filedlg.h>
#include <wx/dirdlg.h>
#include <wx/dir.h>
#include <wx/msgdlg.h>
#include <wx/wfstream.h>
#include <wx/image.h>
#include <wx/bitmap.h>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <atomic>

#include "app.h"
#include "media_reader.h"
#include "informationdialog.h"
#include "medialist.h"
#include "ffmpeg_define.h"

#define FILETYPE "MP4 Files (*.mp4)|*.mp4"
#define FILESAVE "Text file (*.txt)|*.txt"

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
    void BindAction();                                  // Binds all the actions defined from the main window
    void CreateComponent();                             // Creates a list of components defined from the main window
    void SetupSizer();                                  // Arranges and manages a list of components to fit right into
                                                        // the main window.
private:
    //List count and file list
    int fileItemListCount;
    MediaList mediaList;

    //Holding state, for multi-threaded processing
    bool onProcessing{false};                           // Checks for current task running
    std::atomic<bool> quitRequested{false};             // Checks for quit request from the user
    std::thread backgroundThread;                       // A thread for processing video (with FFmpeg command)
    //Main panel container
    wxPanel *container;

    //Left Panel
    wxPanel *leftPanel;
    wxStaticText *labelFolder;
    wxButton *btnImportFolder;
    wxStaticText *labelFile;
    wxButton *btnImportFile;
    wxButton *btnDisplayInfo;
    wxStaticText *listFileText;
    wxListView *listFile;
    wxButton *btnClearFile;
    wxButton *btnRemoveFile;
    wxButton *btnExportFile;

    // Right panel with both top and bottom panel
    wxStaticText *settingText;
    wxPanel *rightPanel;

    // Right top panel
    wxPanel *rightTopPanel;
    wxStaticText *numberVideoText;
    wxSpinCtrl *spinCtrlNumberVideo;
    wxStaticText *randomMergeText;
    wxStaticText *rangeCharacter;
    wxSpinCtrl *minNumberMergeVideo;
    wxSpinCtrl *maxNumberMergeVideo;
    wxStaticText *bitrateText;
    wxComboBox *bitrateConversion;
    wxSpinCtrlDouble *bitrateAmount;
    wxStaticText *bitrateBuffText;
    wxSpinCtrlDouble *bitrateBuffAmount;
    wxStaticText *framerateText;
    wxSpinCtrl *framerateAmount;
    wxCheckBox *includeTrackList;
    wxCheckBox *constantBitrate;

    // Right bottom panel
    wxPanel *rightBottomPanel;
    wxStaticText *commandText;
    wxStaticText *commandDisplay;
    wxStaticText *gaugeProgressText;
    wxGauge *gaugeProgress;

    //Action
    void OnImportFileClicked(wxCommandEvent &evt);      // Imports media files (single file and multiple files selection are supported)
    void OnImportFolderClicked(wxCommandEvent &evt);    // Imports a folder that contains media file (has filter)
    void OnClearAllClicked(wxCommandEvent &evt);        // Clears all the imported files from the list view
    void OnRemoveClicked(wxCommandEvent &evt);          // Removes a single files from the list view
    void OnExportClicked(wxCommandEvent &evt);          // Exports a list of media files to the final product (with FFmpeg)
    void OnInformationClicked(wxCommandEvent &evt);     // Pops up a window displaying some information about how to use this software
    void ToggleButton(bool toggle);                     // Toggles import file, import folder, remove, clear all and export file button
                                                        // To avoid the user from modifying current list of media file.
    void OnWindowClosed(wxCloseEvent &evt);             // Checks whether the window is closed to check if the current task is running
    void OnToggleBufferConstant(wxCommandEvent &evt);   // Toggles the constant bit rate and buffer rate
    void OnConversionBitrateChanged(wxCommandEvent &evt);  // Checks for the unit conversion of the bit rate (kbps and Mbps)
};

// Defined function to support for file extraction, processing FFmpeg command
// and scanning processed videos
bool filterExtension(const std::string, const std::string);
wxString getFileName(const wxString);
wxString getFileNameWExtension(const wxString);
bool isScanned(int*, int);
wxString setAllSettingMedia(wxString, wxString, double, int, int, bool, double);
wxString mergeVideo(wxString, wxString);

#endif // MAINFRAME_H
