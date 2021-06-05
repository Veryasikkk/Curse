#pragma once


// CChecersField

class CChecersField : public CWnd
{
	DECLARE_DYNAMIC(CChecersField)

public:
	CChecersField();
	virtual ~CChecersField();

protected:
	DECLARE_MESSAGE_MAP()
private:
	bool RegisteClass();
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	void GetFieldPosition(CPoint point, int& xpos, int& ypos);
public:
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
private:
//	int nSelectedX;
//	int nSelectedY;
	void highlight(CPaintDC& dc);
public:
	void User_choice();
	void GetUserChoice(CString UserChoice);
	
	void GetUserPutChoice(CString PutChoice);
	void GetUserPut_W_Choice(CString PUT_WHITE_ChOICE);
private:
	int CHOICE_;
	int MASSCHOICEX;
	int MASSCHOICEY;
	int MASSIV[8][8];
public:
	int CHOICE2_;
private:
	bool USLOVIE(int choi, int choi2);
protected:

	
	
};


