
// CheckersDlg.h: файл заголовка
//

#pragma once
#include "CChecersField.h"

// Диалоговое окно CCheckersDlg
class CCheckersDlg : public CDialogEx
{
// Создание
public:
	CCheckersDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHECKERS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	CChecersField tttField;
	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CEdit Edit_Checker;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit3();
	CEdit Put_Checker;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
private:
	CString EDIT_CHECKERS;
public:
	CString PUT_CHOICE;
	CString PUT_WHITE_CHOICE;
	afx_msg void OnBnClickedButton5();
};
