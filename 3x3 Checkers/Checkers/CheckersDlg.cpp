
// CheckersDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Checkers.h"
#include "CheckersDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложени

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CCheckersDlg



CCheckersDlg::CCheckersDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHECKERS_DIALOG, pParent)
	, EDIT_CHECKERS(_T(""))
	, PUT_CHOICE(_T(""))
	, PUT_WHITE_CHOICE(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
	//  nSelectedY = 0;
	
}

void CCheckersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_CHECKERSFIELD, tttField);
	//DDX_Control(pDX, IDC_EDIT1, Edit_Checker);
	DDX_Control(pDX, IDC_EDIT3, Put_Checker);
	DDX_Control(pDX, IDC_EDIT2, Edit_Checker);
	DDX_Text(pDX, IDC_EDIT2, EDIT_CHECKERS);
	DDX_Text(pDX, IDC_EDIT3, PUT_CHOICE);
	DDX_Text(pDX, IDC_EDIT1, PUT_WHITE_CHOICE);
}

BEGIN_MESSAGE_MAP(CCheckersDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	/*ON_EN_CHANGE(IDC_EDIT1, &CCheckersDlg::OnEnChangeEdit1)*/
	/*ON_BN_CLICKED(IDC_BUTTON1, &CCheckersDlg::OnBnClickedButton1)*/
	ON_EN_CHANGE(IDC_EDIT3, &CCheckersDlg::OnEnChangeEdit3)
	/*ON_BN_CLICKED(IDC_BUTTON2, &CCheckersDlg::OnBnClickedButton2)*/
	ON_BN_CLICKED(IDC_BUTTON3, &CCheckersDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCheckersDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCheckersDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// Обработчики сообщений CCheckersDlg

BOOL CCheckersDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CCheckersDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CCheckersDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CCheckersDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCheckersDlg::OnEnChangeEdit1()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CCheckersDlg::OnBnClickedButton1()
{
	UpdateData(TRUE);
	tttField.GetUserPut_W_Choice(PUT_WHITE_CHOICE);
}


void CCheckersDlg::OnEnChangeEdit3()
{
	// TODO:  Если это элемент управления RICHEDIT, то элемент управления не будет
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// функция и вызов CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Добавьте код элемента управления
}


void CCheckersDlg::OnBnClickedButton2()
{
	
}


void CCheckersDlg::OnBnClickedButton3()
{
	UpdateData(TRUE);
	tttField.GetUserChoice(EDIT_CHECKERS);
}


void CCheckersDlg::OnBnClickedButton4()
{
	UpdateData(TRUE);
	tttField.GetUserPutChoice(PUT_CHOICE);
}


void CCheckersDlg::OnBnClickedButton5()
{
	UpdateData(TRUE);
	tttField.GetUserPut_W_Choice(PUT_WHITE_CHOICE);
}
