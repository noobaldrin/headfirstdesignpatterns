#include <wx/gdicmn.h>

#include "DPGUI.hpp"
#include "DPClasses.hpp"

bool DPGUI::OnInit()
{
    m_frame = new Frame(nullptr, wxID_ANY, "DPGUI");
    SetTopWindow(m_frame);
    m_frame->Show();

    return true;
}

Frame::Frame(wxWindow *parent, wxWindowID id, const wxString &title)
    : wxFrame(parent, id, title)
{
    menubar_ = new wxMenuBar;
    wxMenu *file_menu = new wxMenu;
    file_menu->Append(wxID_EXIT, "Exit\t\tEsc", "Exit Program", false);

    menubar_->Append(file_menu, "File");
    SetMenuBar(menubar_);

    main_panel_ = new wxPanel(this);
    notebook_ = new wxNotebook(main_panel_, wxID_ANY, wxDefaultPosition,
                   wxDefaultSize, wxNB_LEFT, "");
    log_text_ = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition,
                   wxDefaultSize, wxTE_MULTILINE);
    logtxt_clrbtn_ =  new wxButton(this, wxID_ANY, "Clear Log");

    dp_panels.emplace_back(std::make_pair<std::string, wxPanel *>(
    "Strategy", new StrategyPanel(notebook_, wxID_ANY)));
    dp_panels.emplace_back(std::make_pair<std::string, wxPanel *>(
    "Observer", new ObserverPanel(notebook_, wxID_ANY)));
    dp_panels.emplace_back(std::make_pair<std::string, wxPanel *>(
    "Decorator", new DecoratorPanel(notebook_, wxID_ANY)));
    dp_panels.emplace_back(std::make_pair<std::string, wxPanel *>(
    "Factory", new FactoryPanel(notebook_, wxID_ANY)));

    for (auto itr : dp_panels)
    notebook_->AddPage(itr.second, itr.first);

    dolayout();
}

void Frame::dolayout()
{
    top_sizer_ = new wxBoxSizer(wxVERTICAL);
    top_sizer_->Add(main_panel_, 0, wxEXPAND | wxALL, 5);
    //top_sizer_->Add(log_text_, 0, wxEXPAND | wxALL, 5);

    wxFlexGridSizer *log_sizer = new wxFlexGridSizer(2);
    log_sizer->Add(log_text_, 0, wxEXPAND | wxALL, 5);
    log_sizer->Add(logtxt_clrbtn_, 0, wxALL, 5);

    wxBoxSizer *panel_sizer = new wxBoxSizer(wxVERTICAL);
    panel_sizer->Add(notebook_, 0, wxEXPAND | wxALL, 5);
    panel_sizer->Add(log_sizer, 0, wxEXPAND | wxALL, 5);
        main_panel_->SetSizerAndFit(panel_sizer);
}

StrategyPanel::StrategyPanel(wxWindow *parent, wxWindowID id)
    : wxPanel(parent, id)
{
    wxArrayString choices;

    ducks.emplace_back(
    std::make_pair<std::string, Duck *>("Mallard Duck", new MallardDuck()));
    ducks.emplace_back(std::make_pair<std::string, Duck *>("Red Head Duck",
                               new RedheadDuck()));
    ducks.emplace_back(
    std::make_pair<std::string, Duck *>("Rubber Duck", new RubberDuck()));
    ducks.emplace_back(
    std::make_pair<std::string, Duck *>("Decoy Duck", new DecoyDuck()));

    for (auto &itr : ducks)
    choices.Add(itr.first);

    cmbbox_ = new wxComboBox(this, wxID_ANY, "Choose Duck...",
                 wxDefaultPosition, wxDefaultSize, choices,
                 wxCB_SORT, wxDefaultValidator, "Ducks:");
    lstbox_ = new wxListBox(this, wxID_ANY, wxDefaultPosition, wxSize(200,100),
                wxArrayString(), wxLB_NEEDED_SB | wxLB_SINGLE);

    addbtn_ = new wxButton(this, wxID_ANY, "Add");
    rmbtn_ = new wxButton(this, wxID_ANY, "Remove");
    clrbtn_ = new wxButton(this, wxID_ANY, "Clear");

    wxArrayString quack_choices;
    quack_choices.Add(wxString("Quack!"));
    quack_choices.Add(wxString("Mute Quack!"));
    quack_choices.Add(wxString("Squeak!"));
    quack_radio_
    = new wxRadioBox(this, wxID_ANY, "Quack Behavior", wxDefaultPosition,
             wxDefaultSize, quack_choices, 0, wxRA_SPECIFY_ROWS);
    quack_btn_ = new wxButton(this, wxID_ANY, "Quack!");

    wxArrayString fly_choices;
    fly_choices.Add("Fly with Wings");
    fly_choices.Add("No flying");
    fly_choices.Add("Fly Rocket Powered");
    fly_radio_
    = new wxRadioBox(this, wxID_ANY, "Fly Behavior", wxDefaultPosition,
             wxDefaultSize, fly_choices, 0, wxRA_SPECIFY_ROWS);
    fly_btn_ = new wxButton(this, wxID_ANY, "Fly!");

    dolayout();
}

void StrategyPanel::dolayout()
{
    top_sizer_ = new wxGridBagSizer;

    wxBoxSizer *ducks_sizer = new wxBoxSizer(wxHORIZONTAL);
    ducks_sizer->Add(cmbbox_, wxSizerFlags().Center().Border(wxALL, 5));
    ducks_sizer->Add(addbtn_, wxSizerFlags().Center().Border(wxALL, 5));

    wxBoxSizer *buttons_sizer = new wxBoxSizer(wxVERTICAL);
    buttons_sizer->Add(rmbtn_,
               wxSizerFlags().Center().Border(wxALL, 5).Expand());
    buttons_sizer->Add(clrbtn_,
               wxSizerFlags().Center().Border(wxALL, 5).Expand());

    wxBoxSizer *lstbox_sizer = new wxBoxSizer(wxHORIZONTAL);
    lstbox_sizer->Add(lstbox_,
              wxSizerFlags().Center().Border(wxALL, 5).Expand());
    lstbox_sizer->Add(buttons_sizer, wxSizerFlags().Right().Border(wxALL, 5).Expand());

    wxBoxSizer *quack_sizer = new wxBoxSizer(wxVERTICAL);
    quack_sizer->Add(quack_radio_, wxSizerFlags().Center().Border(wxALL, 5));
    quack_sizer->Add(quack_btn_, wxSizerFlags().Left().Border(wxALL, 5));

    wxBoxSizer *fly_sizer = new wxBoxSizer(wxVERTICAL);
    fly_sizer->Add(fly_radio_, wxSizerFlags().Center().Border(wxALL, 5));
    fly_sizer->Add(fly_btn_, wxSizerFlags().Left().Border(wxALL, 5));

    wxBoxSizer *behavior_sizer = new wxBoxSizer(wxHORIZONTAL);
    behavior_sizer->Add(quack_sizer);
    behavior_sizer->Add(fly_sizer);

    top_sizer_->Add(ducks_sizer, wxGBPosition(0, 0), wxGBSpan(1, 2),
            wxGROW | wxALL, 5);
    top_sizer_->Add(lstbox_sizer, wxGBPosition(1, 0), wxGBSpan(1, 5));
    top_sizer_->Add(behavior_sizer, wxGBPosition(2, 0));

    SetSizerAndFit(top_sizer_);
}

wxIMPLEMENT_APP(DPGUI);
