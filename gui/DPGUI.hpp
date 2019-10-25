#ifndef _DPGUI_HPP
#define _DPGUI_HPP

#include <wx/wxprec.h>

#ifndef _WX_PRECOMP
#include <wx/app.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/notebook.h>
#include <wx/menu.h>
#include <wx/combobox.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/radiobox.h>
#include <wx/gbsizer.h>
#endif

#include <string>
#include <vector>

#include "DPClasses.hpp"

class Frame;

class DPGUI : public wxApp
{
public:
    virtual bool OnInit();

private:
    Frame *m_frame;
};

class Frame : public wxFrame
{
public:
    //    using wxFrame::wxFrame;
    Frame(wxWindow *parent, wxWindowID id, const wxString &title);

protected:
    wxPanel *main_panel_;
    wxNotebook *notebook_;
    wxMenuBar *menubar_;
    wxTextCtrl *log_text_;
    wxButton *logtxt_clrbtn_;
    std::vector<std::pair<std::string, wxPanel *>> dp_panels;

    // Sizers
    wxBoxSizer *top_sizer_;

private:
    void dolayout();
};

// Strategy Class

class StrategyPanel : public wxPanel
{
public:
    StrategyPanel(wxWindow *parent, wxWindowID id);

protected:
    wxComboBox *cmbbox_;
    wxListBox *lstbox_;
    wxButton *addbtn_;
    wxButton *rmbtn_;
    wxButton *clrbtn_;
    wxRadioBox *quack_radio_;
    wxButton *quack_btn_;
    wxRadioBox *fly_radio_;
    wxButton *fly_btn_;

    // Sizers
    wxGridBagSizer *top_sizer_;
private:
    std::vector<std::pair<std::string, Duck *>> ducks;
//    std::vector<std::string, QuackBehavior *> quacks;
//    std::vector<std::string, FlyBehavior *> flies;
    void dolayout();
};

// Observer Class

class ObserverPanel : public wxPanel
{
public:
    using wxPanel::wxPanel;
};

// Decorator Class

class DecoratorPanel : public wxPanel
{
public:
    using wxPanel::wxPanel;
};

// Factory Class
class FactoryPanel : public wxPanel
{
public:
    using wxPanel::wxPanel;
};
#endif    // _DPGUI_HPP
