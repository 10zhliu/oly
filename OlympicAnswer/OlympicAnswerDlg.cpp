// OlympicAnswerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OlympicAnswer.h"
#include "OlympicAnswerDlg.h"
#include<algorithm>
#include<iostream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString ipaddress="10.24.31.19";
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COlympicAnswerDlg dialog

COlympicAnswerDlg::COlympicAnswerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COlympicAnswerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COlympicAnswerDlg)
	m_outputdata = _T("");
	m_data = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COlympicAnswerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COlympicAnswerDlg)
	DDX_Text(pDX, IDC_EDIT_OUTPUTDATA, m_outputdata);
	DDX_Text(pDX, IDC_EDI_DATA, m_data);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COlympicAnswerDlg, CDialog)
	//{{AFX_MSG_MAP(COlympicAnswerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUT_OK, OnButOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COlympicAnswerDlg message handlers

BOOL COlympicAnswerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	if(AfxSocketInit(NULL)==FALSE)
	{
		AfxMessageBox("Error Init Socket");
	}	
	if(GetTime())//||GetIp())
	{
		//MessageBox("你无权使用!");
		this->EndDialog(0);
	}
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COlympicAnswerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void COlympicAnswerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR COlympicAnswerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
struct node
{
    int index;
    char s[6];    
}ss[100];
char word[15][50]={"ߔࠀߔ","ߔࠁߔ","ߔࠂߔ","ߔࠃߔ","ߔࠀߕࠁߔ",
"ߔࠀߕࠂߔ","ߔࠀߕࠃߔ","ߔࠁߕࠂߔ","ߔࠁߕࠃߔ","ߔࠂߕࠃߔ",
"ߔࠀߕࠁߕࠂߔ","ߔࠀߕࠁߕࠃߔ","ߔࠀߕࠂߕࠃߔ",
"ߔࠁߕࠂߕࠃߔ","ߔࠀߕࠁߕࠂߕࠃߔ"
};

char wordnum[16][50]={"A","B","C","D","AB","AC","AD","BC","BD","CD","ABC","ABD","ACD","BCD","ABCD"};
int find(char *a,char *b)
{
    int i,j;
    int flag;
	
    for(i=0;a[i];i++) 
    {
        flag=0;
        for(j=0;b[j];j++)
        {
            if(a[i+j]!=b[j]) 
            {
                flag=1;
                break;    
            }
        }    
        if(!flag) return i;
    }  
    return -1;
}
int cmp(node a,node b)
{
    return a.index<b.index ;   
}
void COlympicAnswerDlg::OnButOk() 
{
	// TODO: Add your control notification handler code here
	char str[100000];
	UpdateData(TRUE);
	strcpy(str,m_data.GetBuffer(0));
	int j=0;
    int i;
    while(j<60)
    {
        int p=-1;
        for(i=0;i<15;i++)
        {
            p=find(str,word[i]);  
            if(p!=-1) {str[p]+=20;break;}
        } 
        if(p==-1) break;   
        ss[j].index=p;
        strcpy(ss[j].s,wordnum[i]);
        j++;        
    }
    sort(ss,ss+j,cmp);
	CString temp;
	CString m_outputdatadata="";
    for(i=0;i<j;i++)
    {
		if(i%5==0&&i) m_outputdata+="\r\n\r\n";
		temp.Format("%-2d %-10s",i+1,ss[i].s);  
		m_outputdata+=temp;
    }
	m_data="";
	UpdateData(FALSE);
}

bool COlympicAnswerDlg::GetIp()
{
	char szhostname[128];
	CString str;
	BYTE   *p;
	gethostname(szhostname,128);//获得主机名
	// 获得主机ip地址
	struct hostent * phost;
	phost = gethostbyname(szhostname);//根据主机名获得IP地址
	p=(BYTE*)phost-> h_addr;	
	CString temp;
	temp.Format("%d.%d.%d.%d",p[0],p[1],p[2],p[3]);
	if(temp!=ipaddress)
	{
		return 1;
	}
	return 0;
}

bool COlympicAnswerDlg::GetTime()
{
	SYSTEMTIME st;
	CString strDate;
	GetLocalTime(&st);
	//strDate.Format("%4d-%2d-%2d",st.wYear,st.wMonth,st.wDay);	
	if(st.wYear>2012)
	{
		return 1;
	}
	return 0;
}
