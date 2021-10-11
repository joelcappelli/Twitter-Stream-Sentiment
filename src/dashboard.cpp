#include <wx/filename.h>
#include <wx/colour.h>
#include <wx/image.h>
#include <string>
#include <chrono>
#include <thread>

#include "dashboard.h"

// size of chatbot window
const int width = 414;
const int height = 736;

IMPLEMENT_APP(TwitterApp);

bool TwitterApp::OnInit()
{
    // create window with name and show it
    DashboardFrame *dashboardFrame = new DashboardFrame(wxT("Twitter-Stream-Sentiment"));
    dashboardFrame->Show(true);

    for(int i =0;i < 10000; ++i){
        std::string response = "Some text....\r\n";
        dashboardFrame->AddSomeText(wxString(response.c_str(), wxConvUTF8));
        dashboardFrame->Show(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }

    return true;
}

TweetStreamPanel::TweetStreamPanel(wxFrame *parent) : wxPanel(parent)
{
}

TweetStreamPanel::~TweetStreamPanel(){

}

// wxWidgets FRAME
DashboardFrame::DashboardFrame(const wxString &title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(width, height))
{
    // create panel with background image
    TweetStreamPanel *ctrlPanel = new TweetStreamPanel(this);

    // create controls and assign them to control panel
    _panelText = new TweetStreamPanelScrWindow(ctrlPanel, wxID_ANY);

    // create vertical sizer for panel alignment and add panels
    wxBoxSizer *vertBoxSizer = new wxBoxSizer(wxVERTICAL);
    vertBoxSizer->Add(_panelText, 6, wxEXPAND | wxALL, 0);

    // create text control for user input
    int idTextXtrl = 1;
    _userTextCtrl = new wxTextCtrl(ctrlPanel, idTextXtrl, "", wxDefaultPosition, wxSize(width, 50), wxTE_MULTILINE);

    // create vertical sizer for panel alignment and add panels
    vertBoxSizer->Add(_userTextCtrl, 1, wxEXPAND | wxALL, 5);

    ctrlPanel->SetSizer(vertBoxSizer);

    // position window in screen center
    this->Centre();
}

void DashboardFrame::AddSomeText(wxString s )
{
    // HACK: Under Windows (using wxTE_RICH2) we have trouble ensuring that the last
    // entered line is really at the bottom of the screen. We jump through some
    // hoops to get this working.

    // Count number of newlines (i.e lines)
    int lines = 0;
    const char* cstr = s.c_str();
    for( ; *cstr ; ++cstr )
        if( *cstr == '\n' )
            ++lines;

    // Dance...
    _userTextCtrl->Freeze();                 // Freeze the window to prevent scrollbar jumping
    _userTextCtrl->AppendText( s );          // Add the text
    _userTextCtrl->ScrollLines( lines + 1 ); // Scroll down correct number of lines + one (the extra line is important for some cases!)
    _userTextCtrl->ShowPosition( _userTextCtrl->GetLastPosition() ); // Ensure the last line is shown at the very bottom of the window
    _userTextCtrl->Thaw();                   // Allow the window to redraw
}

TweetStreamPanelScrWindow::TweetStreamPanelScrWindow(wxWindow *parent, wxWindowID id)
    : wxScrolledWindow(parent, id)
{
    // sizer will take care of determining the needed scroll size
    _dialogSizer = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(_dialogSizer);

}

TweetStreamPanelScrWindow::~TweetStreamPanelScrWindow()
{

}

TweetStreamPanelText::TweetStreamPanelText(wxPanel *parent, wxString text)
    : wxPanel(parent, -1, wxPoint(-1, -1), wxSize(-1, -1), wxBORDER_NONE)
{
    _tweetTxt = new wxStaticText(this, wxID_ANY, text, wxPoint(-1, -1), wxSize(150, -1), wxALIGN_CENTRE | wxBORDER_NONE);
    _tweetTxt->SetForegroundColour(wxColor(*wxBLACK));

    // create sizer and add elements
    wxBoxSizer *horzBoxSizer = new wxBoxSizer(wxHORIZONTAL);
    horzBoxSizer->Add(_tweetTxt, 8, wxEXPAND | wxALL, 1);
    this->SetSizer(horzBoxSizer);

    // wrap text after 150 pixels
    _tweetTxt->Wrap(150);

    // set background color
    this->SetBackgroundColour(wxT("WHITE"));
}

void TweetStreamPanelScrWindow::AddDialogItem(wxString text)
{
    // add a single dialog element to the sizer
    TweetStreamPanelText *item = new TweetStreamPanelText(this, text);
    _dialogSizer->Add(item, 0, wxALL | wxALIGN_LEFT, 8);
    _dialogSizer->Layout();

    // make scrollbar show up
    this->FitInside(); // ask the sizer about the needed size
    this->SetScrollRate(5, 5);
    this->Layout();

    // scroll to bottom to show newest element
    int dx, dy;
    this->GetScrollPixelsPerUnit(&dx, &dy);
    int sy = dy * this->GetScrollLines(wxVERTICAL);
    this->DoScroll(0, sy);
}

void TweetStreamPanelScrWindow::PrintTweets(std::string response)
{
    // convert string into wxString and add dialog element
    wxString botText(response.c_str(), wxConvUTF8);
    AddDialogItem(botText);
}