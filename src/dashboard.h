#include <wx/wx.h>
#include <memory>

class TwitterApp : public wxApp
{
  public:
    virtual bool OnInit();
};


// middle part of the window containing the dialog between user and chatbot
class TweetStreamPanelScrWindow : public wxScrolledWindow
{
private:
    // control elements
    wxBoxSizer *_dialogSizer;

public:
    // constructor / destructor
    TweetStreamPanelScrWindow(wxWindow *parent, wxWindowID id);
    ~TweetStreamPanelScrWindow();

    // getter / setter

    // events

    // proprietary functions
    void AddDialogItem(wxString text);
    void PrintTweets(std::string response);

};

// control panel for background image display
class TweetStreamPanel : public wxPanel
{
    // control elements

public:
    // constructor / desctructor
    TweetStreamPanel(wxFrame *parent);
    ~TweetStreamPanel();

    // events

};

// dialog item shown in ChatBotPanelDialog
class TweetStreamPanelText : public wxPanel
{
private:
    // control elements
    wxStaticText *_tweetTxt;

public:
    // constructor / destructor
    TweetStreamPanelText(wxPanel *parent, wxString text);
};

// frame containing all control elements
class DashboardFrame : public wxFrame
{
private:
    // control elements
    TweetStreamPanelScrWindow *_panelText;
    wxTextCtrl *_userTextCtrl;

    // events

public:
    // constructor / desctructor
    DashboardFrame(const wxString &title);

    void AddSomeText(wxString s );
};
