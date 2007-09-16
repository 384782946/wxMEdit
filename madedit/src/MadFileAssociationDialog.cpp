///////////////////////////////////////////////////////////////////////////////
// Name:        MadFileAssociationDialog.cpp
// Description: File Type Association Dialog for MSWindows
// Author:      madedit@gmail.com
// Licence:     GPL
///////////////////////////////////////////////////////////////////////////////

#include "MadFileAssociationDialog.h"
#include "MadUtils.h"
#include <wx/config.h>

#ifdef __WXMSW__

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End


#ifdef _DEBUG
#include <crtdbg.h>
#define new new(_NORMAL_BLOCK ,__FILE__, __LINE__)
#endif


const wxChar *g_PredefinedTypes[]=
{
    wxT(".txt"),
    wxT(".c"),
    wxT(".cpp"),
    wxT(".cc"),
    wxT(".cxx"),
    wxT(".h"),
    wxT(".hpp"),
    wxT(".asm"),
    wxT(".java"),
//    wxT(".htm"),
//    wxT(".html"),
    wxT(".css"),
    wxT(".js"),
    wxT(".xml"),
    wxT(".php"),
    wxT(".asp"),
    wxT(".inc"),
    wxT(".cs"),
//    wxT(".vbs"),
    wxT(".bas"),
    wxT(".frm"),
    wxT(".cls"),
//    wxT(".reg"),
//    wxT(".inf"),
    wxT(".ini"),
    wxT(".cfg"),
    wxT(".conf"),
    wxT(".mak"),
    wxT(".nfo"),
    wxT(".diz"),
    wxT(".pas"),
//    wxT(".dpr"),
//    wxT(".bat"),
//    wxT(".cmd"),
    wxT(".awk"),
    wxT(".py"),
    wxT(".python"),
    wxT(".pl"),
    wxT(".perl"),
    wxT(".rb"),
    wxT(".rbw"),
    wxT(".diff"),
    wxT(".patch"),
    wxT(".lua"),
    wxT(".nut"),
    wxT(".f90"),
    wxT(".f77"),
    wxT(".for"),
    wxT(".ftn"),
    wxT(".lat"),
    wxT(".tex"),
    wxT(".lex"),
    wxT(".as"),
    wxT(".syn"),
    wxT(".sch"),
    wxT(".att"),
};

const int g_PredefinedTypes_Count = sizeof(g_PredefinedTypes) / sizeof(g_PredefinedTypes[0]);

bool DetectType(wxString type)
{
    wxRegKey *pRegKey = new wxRegKey(wxString(wxT("HKEY_CLASSES_ROOT\\")) + type);
    if(pRegKey->Exists())
    {
        wxString str;
        if(pRegKey->QueryValue(NULL, str))
        {
            wxString value(wxT("MadEdit"));
            value += type;
            if(str == value)
            {
                delete pRegKey;
                return true;
            }
        }
    }
    delete pRegKey;
    return false;
}

void AddType(wxString type)
{
    wxRegKey *pRegKey = new wxRegKey(wxString(wxT("HKEY_CLASSES_ROOT\\")) + type);
    pRegKey->Create();
    pRegKey->SetValue(NULL, wxString(wxT("MadEdit"))+type);
    delete pRegKey;

    wxString name(wxT("HKEY_CLASSES_ROOT\\MadEdit"));
    name += type;
    name += wxT("\\shell\\open\\command");
    pRegKey = new wxRegKey(name);
    pRegKey->Create();
    wxString exepath=GetExecutablePath();
    pRegKey->SetValue(NULL, wxString(wxT('"'))+exepath+wxString(wxT("\" \"%1\"")));
    delete pRegKey;

    name = wxT("HKEY_CLASSES_ROOT\\MadEdit");
    name += type;
    name += wxT("\\DefaultIcon");
    pRegKey = new wxRegKey(name);
    pRegKey->Create();
    pRegKey->SetValue(NULL, exepath);// + wxString(wxT(",1")));
    delete pRegKey;
}

void RemoveType(wxString type)
{
    if(!type.IsEmpty())
    {
        wxRegKey *pRegKey = new wxRegKey(wxString(wxT("HKEY_CLASSES_ROOT\\")) + type);
        pRegKey->DeleteSelf();
        delete pRegKey;

        pRegKey = new wxRegKey(wxString(wxT("HKEY_CLASSES_ROOT\\MadEdit")) + type);
        pRegKey->DeleteSelf();
        delete pRegKey;
    }
}


wxArrayString as_remove; // the types will be removed

void GetListBoxSelections(wxListBox *lb, wxArrayString &as)
{
    wxArrayInt sel;
    lb->GetSelections(sel);
    int idx=0;
    const int count=int(sel.Count());
    while(idx<count)
    {
        as.Add(lb->GetString(sel[idx]));
        ++idx;
    }
}

void AddTypeToAssociated(wxListBox *WxListBoxAssociated,
                         wxListBox *WxListBoxPredefined,
                         const wxArrayString &as)
{
    int idx = 0;
    const int count = int(as.Count());
    wxString type;
    while(idx < count)
    {
        type = as[idx];

        int n = WxListBoxPredefined->FindString(type);
        if(n != wxNOT_FOUND) WxListBoxPredefined->Delete(n);

        n = WxListBoxAssociated->FindString(type);
        if(n == wxNOT_FOUND) WxListBoxAssociated->Append(type);

        n = as_remove.Index(type);
        if(n != wxNOT_FOUND) as_remove.RemoveAt(n);

        ++idx;
    }
}

void AddTypeToPredefined(wxListBox *WxListBoxAssociated,
                         wxListBox *WxListBoxPredefined,
                         const wxArrayString &as)
{
    int idx = 0;
    const int count = int(as.Count());
    wxString type;
    while(idx < count)
    {
        type = as[idx];

        int n = WxListBoxAssociated->FindString(type);
        if(n != wxNOT_FOUND) WxListBoxAssociated->Delete(n);

        n = WxListBoxPredefined->FindString(type);
        if(n == wxNOT_FOUND) WxListBoxPredefined->Append(type);

        n = as_remove.Index(type);
        if(n == wxNOT_FOUND) as_remove.Add(type);

        ++idx;
    }
}


//----------------------------------------------------------------------------
// MadFileAssociationDialog
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(MadFileAssociationDialog,wxDialog)
	////Manual Code Start
	////Manual Code End

	EVT_CLOSE(MadFileAssociationDialog::OnClose)
	EVT_BUTTON(ID_WXBUTTONCANCEL,MadFileAssociationDialog::WxButtonCancelClick)
	EVT_BUTTON(ID_WXBUTTONOK,MadFileAssociationDialog::WxButtonOKClick)
	EVT_BUTTON(ID_WXBUTTONADDCUSTOM,MadFileAssociationDialog::WxButtonAddCustomClick)

	EVT_LISTBOX_DCLICK(ID_WXLISTBOXPREDEFINED,MadFileAssociationDialog::WxListBoxPredefinedDoubleClicked)
	EVT_BUTTON(ID_WXBUTTONREMOVE,MadFileAssociationDialog::WxButtonRemoveClick)
	EVT_BUTTON(ID_WXBUTTONADD,MadFileAssociationDialog::WxButtonAddClick)

	EVT_LISTBOX_DCLICK(ID_WXLISTBOXASSOCIATED,MadFileAssociationDialog::WxListBoxAssociatedDoubleClicked)
END_EVENT_TABLE()
////Event Table End

MadFileAssociationDialog::MadFileAssociationDialog(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

MadFileAssociationDialog::~MadFileAssociationDialog()
{
}

void MadFileAssociationDialog::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxBoxSizer1 = new wxBoxSizer(wxVERTICAL);
	this->SetSizer(WxBoxSizer1);
	this->SetAutoLayout(true);

	WxBoxSizer2 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer1->Add(WxBoxSizer2, 0, wxALIGN_CENTER | wxALL, 5);

	WxBoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer4, 0, wxALIGN_CENTER | wxALL, 0);

	WxBoxSizer6 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer4->Add(WxBoxSizer6, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText1 = new wxStaticText(this, ID_WXSTATICTEXT1, _("Associated File Types:"), wxPoint(10,5), wxDefaultSize, 0, _("WxStaticText1"));
	WxBoxSizer6->Add(WxStaticText1,0,wxALIGN_CENTER | wxALL,5);

	wxArrayString arrayStringFor_WxListBoxAssociated;
	WxListBoxAssociated = new wxListBox(this, ID_WXLISTBOXASSOCIATED, wxPoint(5,32), wxSize(121,200), arrayStringFor_WxListBoxAssociated, wxLB_EXTENDED);
	WxBoxSizer6->Add(WxListBoxAssociated,0,wxALIGN_CENTER | wxALL,5);

	WxBoxSizer7 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer4->Add(WxBoxSizer7, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonAdd = new wxButton(this, ID_WXBUTTONADD, _("<- Add"), wxPoint(5,5), wxSize(100,30), 0, wxDefaultValidator, _("WxButtonAdd"));
	WxBoxSizer7->Add(WxButtonAdd,0,wxALIGN_CENTER | wxALL,5);

	WxButtonRemove = new wxButton(this, ID_WXBUTTONREMOVE, _("Remove ->"), wxPoint(5,45), wxSize(100,30), 0, wxDefaultValidator, _("WxButtonRemove"));
	WxBoxSizer7->Add(WxButtonRemove,0,wxALIGN_CENTER | wxALL,5);

	WxBoxSizer8 = new wxBoxSizer(wxVERTICAL);
	WxBoxSizer4->Add(WxBoxSizer8, 0, wxALIGN_CENTER | wxALL, 5);

	WxStaticText2 = new wxStaticText(this, ID_WXSTATICTEXT2, _("Predefined File Types:"), wxPoint(11,5), wxDefaultSize, 0, _("WxStaticText2"));
	WxBoxSizer8->Add(WxStaticText2,0,wxALIGN_CENTER | wxALL,5);

	wxArrayString arrayStringFor_WxListBoxPredefined;
	WxListBoxPredefined = new wxListBox(this, ID_WXLISTBOXPREDEFINED, wxPoint(5,32), wxSize(121,200), arrayStringFor_WxListBoxPredefined, wxLB_EXTENDED);
	WxBoxSizer8->Add(WxListBoxPredefined,0,wxALIGN_CENTER | wxALL,5);

	WxBoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer2->Add(WxBoxSizer5, 0, wxALIGN_LEFT | wxALL, 5);

	WxEditCustomType = new wxTextCtrl(this, ID_WXEDITCUSTOMTYPE, _(""), wxPoint(5,7), wxSize(121,25), 0, wxDefaultValidator, _("WxEditCustomType"));
	WxBoxSizer5->Add(WxEditCustomType,0,wxALIGN_LEFT | wxALL,5);

	WxButtonAddCustom = new wxButton(this, ID_WXBUTTONADDCUSTOM, _("<- Add Custom File Type"), wxPoint(136,5), wxSize(175,30), 0, wxDefaultValidator, _("WxButtonAddCustom"));
	WxBoxSizer5->Add(WxButtonAddCustom,0,wxALIGN_LEFT | wxALL,5);

	WxBoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	WxBoxSizer1->Add(WxBoxSizer3, 0, wxALIGN_CENTER | wxALL, 5);

	WxButtonOK = new wxButton(this, ID_WXBUTTONOK, _("&OK"), wxPoint(5,5), wxSize(85,30), 0, wxDefaultValidator, _("WxButtonOK"));
	WxBoxSizer3->Add(WxButtonOK,0,wxALIGN_CENTER | wxALL,5);

	WxButtonCancel = new wxButton(this, ID_WXBUTTONCANCEL, _("&Cancel"), wxPoint(100,5), wxSize(90,30), 0, wxDefaultValidator, _("WxButtonCancel"));
	WxBoxSizer3->Add(WxButtonCancel,0,wxALIGN_CENTER | wxALL,5);

	SetTitle(_("File Type Associations"));
	SetIcon(wxNullIcon);

	GetSizer()->Layout();
	GetSizer()->Fit(this);
	GetSizer()->SetSizeHints(this);
	Center();

	////GUI Items Creation End

    wxArrayString as_predefined(g_PredefinedTypes_Count, g_PredefinedTypes);

    wxConfigBase *cfg=wxConfigBase::Get(false);
    wxString oldpath=cfg->GetPath();
    cfg->SetPath(wxT("/AssociatedFileTypes"));

    int idx=0, idx2;
    wxString type;
    while(cfg->Read(wxString()<<idx, &type))
    {
        if(DetectType(type))
        {
            WxListBoxAssociated->Append(type);
            if((idx2=as_predefined.Index(type.c_str()))!=wxNOT_FOUND)
            {
                as_predefined.RemoveAt(idx2);
            }
        }
        ++idx;
    }

    WxListBoxPredefined->Set(as_predefined);

    cfg->SetPath(oldpath);
}

void MadFileAssociationDialog::OnClose(wxCloseEvent& /*event*/)
{
	Destroy();
}


void MadFileAssociationDialog::WxListBoxAssociatedDoubleClicked(wxCommandEvent& event)
{
    wxArrayString sel;
    GetListBoxSelections(WxListBoxAssociated, sel);
    AddTypeToPredefined(WxListBoxAssociated, WxListBoxPredefined, sel);
}

void MadFileAssociationDialog::WxListBoxPredefinedDoubleClicked(wxCommandEvent& event)
{
    wxArrayString sel;
    GetListBoxSelections(WxListBoxPredefined, sel);
    AddTypeToAssociated(WxListBoxAssociated, WxListBoxPredefined, sel);
}

void MadFileAssociationDialog::WxButtonAddClick(wxCommandEvent& event)
{
    wxArrayString sel;
    GetListBoxSelections(WxListBoxPredefined, sel);
    AddTypeToAssociated(WxListBoxAssociated, WxListBoxPredefined, sel);
}

void MadFileAssociationDialog::WxButtonRemoveClick(wxCommandEvent& event)
{
    wxArrayString sel;
    GetListBoxSelections(WxListBoxAssociated, sel);
    AddTypeToPredefined(WxListBoxAssociated, WxListBoxPredefined, sel);
}

void MadFileAssociationDialog::WxButtonAddCustomClick(wxCommandEvent& event)
{
    wxString type = WxEditCustomType->GetValue();
    type.Trim(false);
    type.Trim(true);
    if(!type.IsEmpty())
    {
        type.MakeLower();
        wxString dot(wxT('.'));
        if(type[0] != dot) type = dot + type;

        wxArrayString sel;
        sel.Add(type);
        AddTypeToAssociated(WxListBoxAssociated, WxListBoxPredefined, sel);
    }
}

void MadFileAssociationDialog::WxButtonOKClick(wxCommandEvent& event)
{
    wxConfigBase *cfg=wxConfigBase::Get(false);
    wxString oldpath=cfg->GetPath();

    // clear old filetypes
    cfg->DeleteGroup(wxT("/AssociatedFileTypes"));

    cfg->SetPath(wxT("/AssociatedFileTypes"));

    // remove types
    int idx=0;
    int count = int(as_remove.Count());
    wxString type;
    while(idx<count)
    {
        type = as_remove[idx];
        if(DetectType(type))
        {
            RemoveType(type);
        }
        ++idx;
    }

    // add types
    idx=0;
    count = int(WxListBoxAssociated->GetCount());
    while(idx<count)
    {
        type = WxListBoxAssociated->GetString(idx);
        AddType(type);
        cfg->Write(wxString()<<idx, type);
        ++idx;
    }

    cfg->SetPath(oldpath);

    Close();
}

void MadFileAssociationDialog::WxButtonCancelClick(wxCommandEvent& event)
{
    Close();
}

#endif //__WXMSW__