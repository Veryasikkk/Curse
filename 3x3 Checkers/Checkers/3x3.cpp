// CChecersField.cpp: файл реализации
//

#include "pch.h"
#include "Checkers.h"
#include "CChecersField.h"
#define CHECKERSFIELD_CLASSNAME L"CheckersField"
#define Space 2
#define Spacebottom 20
#define Spaceright 23
#define Space3 40.9
#define Space4 44.3
// CChecersField

IMPLEMENT_DYNAMIC(CChecersField, CWnd)

CChecersField::CChecersField()
{
	this->RegisteClass();

	CHOICE_ = -1;
	CHOICE2_ = -1;
	MASSCHOICEX=-1;
	MASSCHOICEY=-1;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j > 2 && j < 5)

				MASSIV[i][j] = 0;
			if (j < 3 && i < 3)
				MASSIV[i][j] = 1;

			if (j > 4 && i > 4 )
				MASSIV[i][j] = -1;
			
		}
	}
}

CChecersField::~CChecersField()
{
}


BEGIN_MESSAGE_MAP(CChecersField, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// Обработчики сообщений CChecersField




bool CChecersField::RegisteClass()
{
	WNDCLASS wndclass;
	HINSTANCE hInst = AfxGetInstanceHandle();

	if (!(::GetClassInfo(hInst, CHECKERSFIELD_CLASSNAME, &wndclass)))
	{
		wndclass.style = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
		wndclass.lpfnWndProc = ::DefWindowProc;
		wndclass.cbClsExtra = wndclass.cbWndExtra = 0;
		wndclass.hInstance = hInst;
		wndclass.hIcon = NULL;
		wndclass.hCursor = LoadCursor(hInst, MAKEINTRESOURCE(230));
		wndclass.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
		wndclass.lpszMenuName = NULL;
		wndclass.lpszClassName = CHECKERSFIELD_CLASSNAME;

		if (!AfxRegisterClass(&wndclass))
		{
			AfxThrowResourceException();
			return false;
		}
		return true;
	}
}

void CChecersField::OnPaint()
{
	CPaintDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	CPen ourPen;
	HGDIOBJ oldPen;
	ourPen.CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
	oldPen = dc.SelectObject(ourPen);

	// Разделение на клетки
	int hPartSize = rect.right / 8 - Space;
	int vPartSize = rect.bottom / 8 - Space;
	int ch = 47;

	//Настройки текста
	CString str_;
	dc.SetTextColor(RGB(0, 0, 0));
	dc.SetTextAlign(TA_TOP | TA_LEFT);
	dc.SetBkMode(TRANSPARENT);




	dc.TextOutW(hPartSize / 2, rect.bottom - Spacebottom + 4, L"1");
	dc.TextOutW(hPartSize / 2 + Space4, rect.bottom - Spacebottom + 4, L"2");
	dc.TextOutW(hPartSize / 2 + Space4 * 2, rect.bottom - Spacebottom + 4, L"3");
	dc.TextOutW(hPartSize / 2 + Space4 * 3, rect.bottom - Spacebottom + 4, L"4");
	dc.TextOutW(hPartSize / 2 + Space4 * 4, rect.bottom - Spacebottom + 4, L"5");
	dc.TextOutW(hPartSize / 2 + Space4 * 5, rect.bottom - Spacebottom + 4, L"6");
	dc.TextOutW(hPartSize / 2 + Space4 * 6, rect.bottom - Spacebottom + 4, L"7");
	dc.TextOutW(hPartSize / 2 + Space4 * 7, rect.bottom - Spacebottom + 4, L"8");

	// Вывод чисел справа 
	CString str;
	for (int i = 0; i < 9; i++)
	{
		str.Format(L"%d", i + 1);
		dc.TextOutW(rect.right - 12, rect.bottom - Spacebottom - 26 - i * Space3, str);
	}


	// Линии клеток 


	/*for (int i = 0; i < 9; i++)
	{
		dc.MoveTo(i * hPartSize, 0);
		dc.LineTo(i * hPartSize, rect.bottom - Spacebottom);
		dc.MoveTo(0, i * vPartSize);
		dc.LineTo(rect.right - Spaceright, i * vPartSize);
	}
	*/


	// Закраска Поля
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i != 8; i += 2)
		{
			if (j % 2 != 0)
			{
				Rectangle(dc, i * hPartSize + hPartSize, j * vPartSize + rect.top + 2, rect.right / 8 + i * hPartSize + hPartSize, j * vPartSize + rect.bottom / 8);
			}
			else
			{
				Rectangle(dc, i * hPartSize, j * vPartSize + rect.top, rect.right / 8 + i * hPartSize, j * vPartSize + rect.bottom / 8);
			}
		}
	}
	RECT r;
	SelectObject(dc, GetStockObject(2));   // Выбор кисти для закраски
	for (int j = 0; j < 8; j++)
	{
		for (int i = 0; i != 8; i += 2)
		{
			if (j % 2 != 0)
			{

				Rectangle(dc, i * hPartSize, j * vPartSize + rect.top, rect.right / 8 + i * hPartSize, j * vPartSize + rect.bottom / 8);
				//r.left = i * hPartSize; //левый верхний угол
				//r.top = j * vPartSize + rect.top;
				//r.right = rect.right / 8 + i * hPartSize ; //правый нижний
				//r.bottom = j * vPartSize + rect.bottom / 8 ;
				//FillRect(dc, &r, HBRUSH(CreateSolidBrush(RGB(107, 67, 33))));
			}
			else
			{
				//r.left = i * hPartSize + hPartSize; //левый верхний угол
				//r.top = j * vPartSize + rect.top;
				//r.right = rect.right / 8 + i * hPartSize + hPartSize; //правый нижний
				//r.bottom = j * vPartSize + rect.bottom / 8;
				//FillRect(dc, &r, HBRUSH(CreateSolidBrush(RGB(107, 67, 33))));
				Rectangle(dc, i * hPartSize + hPartSize, j * vPartSize + rect.top, rect.right / 8 + i * hPartSize + hPartSize, j * vPartSize + rect.bottom / 8);

			}
		}
	}

	// Пешки

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (MASSIV[i][j] == -1)
			{


				SelectObject(dc, GetStockObject(WHITE_BRUSH));




				Ellipse(dc, i * hPartSize + 11, j * vPartSize + rect.top + 9, rect.right / 8 + i * hPartSize - 12, j * vPartSize + rect.bottom / 8 - 8);



			}
			if (MASSIV[i][j] == 1)

			{



				SelectObject(dc, GetStockObject(BLACK_BRUSH));






				Ellipse(dc, i * hPartSize + 11, j * vPartSize + rect.top + 9, rect.right / 8 + i * hPartSize - 12, j * vPartSize + rect.bottom / 8 - 8);


			}



		



			}
			

		}

	
}
	




// Контроль нажатий 

void CChecersField::OnLButtonDown(UINT nFlags, CPoint point)
{
	int x, y;
	this->GetFieldPosition(point, x, y);
	CString str;
	str.Format(L"X=%d, Y=%d", x, y);
	AfxMessageBox(str);
	CWnd::OnLButtonDown(nFlags, point);
}


void CChecersField::GetFieldPosition(CPoint point, int& xpos, int& ypos)
{
	CRect rect;
	GetClientRect(&rect);
	int hPartSize = rect.right / 8 - Space;
	int vPartSize = rect.bottom / 8 - Space;
	for (int i = 0; i < 8; i++)
	{
		if ((point.x > i * hPartSize) && (point.x < (i + 1) * hPartSize))
		xpos = i;
		if ((point.y > i * vPartSize) && (point.y < (i + 1) * vPartSize))
		ypos = i;
	}
}






void CChecersField::GetUserChoice(CString UserChoice)
{
	switch (UserChoice[0])
	{
	case '1':
		CHOICE_ = 0;
		break;
	case'2':
		CHOICE_ = 1;
		break;
	case'3':
		CHOICE_ = 2;
		break;
	case'4':
		CHOICE_ = 3;
		break;
	case'5':
		CHOICE_ = 4;
		break;
	case'6':
		CHOICE_ = 5;
		break;
	case'7':
		CHOICE_ = 6;
		break;
	case'8':
		CHOICE_ = 7;
		break;
	default:
		break;
	}
	switch (UserChoice[1])
	{
	case '1':
		CHOICE2_ = 7;
		break;
	case'2':
		CHOICE2_ = 6;
		break;
	case'3':
		CHOICE2_ = 5;
		break;
	case'4':
		CHOICE2_ = 4;
		break;
	case'5':
		CHOICE2_ = 3;
		break;
	case'6':
		CHOICE2_ = 2;
		break;
	case'7':
		CHOICE2_ = 1;
		break;
	case'8':
		CHOICE2_ = 0;
		break;
	default:
		break;


	}
	MASSIV[CHOICE_][CHOICE2_] = 0;

	this->Invalidate();



}

void CChecersField::GetUserPut_W_Choice(CString UserChoice)
{
	switch (UserChoice[0])
	{
	case '1':
		CHOICE_ = 0;
		break;
	case'2':
		CHOICE_ = 1;
		break;
	case'3':
		CHOICE_ = 2;
		break;
	case'4':
		CHOICE_ = 3;
		break;
	case'5':
		CHOICE_ = 4;
		break;
	case'6':
		CHOICE_ = 5;
		break;
	case'7':
		CHOICE_ = 6;
		break;
	case'8':
		CHOICE_ = 7;
		break;
	default:
		break;
	}
	switch (UserChoice[1])
	{
	case '1':
		CHOICE2_ = 7;
		break;
	case'2':
		CHOICE2_ = 6;
		break;
	case'3':
		CHOICE2_ = 5;
		break;
	case'4':
		CHOICE2_ = 4;
		break;
	case'5':
		CHOICE2_ = 3;
		break;
	case'6':
		CHOICE2_ = 2;
		break;
	case'7':
		CHOICE2_ = 1;
		break;
	case'8':
		CHOICE2_ = 0;
		break;
	default:
		break;


	}
	MASSIV[CHOICE_][CHOICE2_] = -1;

	this->Invalidate();



}
void CChecersField::GetUserPutChoice(CString UserChoice)
{
	switch (UserChoice[0])
	{
	case '1':
		CHOICE_ = 0;
		break;
	case'2':
		CHOICE_ = 1;
		break;
	case'3':
		CHOICE_ = 2;
		break;
	case'4':
		CHOICE_ = 3;
		break;
	case'5':
		CHOICE_ = 4;
		break;
	case'6':
		CHOICE_ = 5;
		break;
	case'7':
		CHOICE_ = 6;
		break;
	case'8':
		CHOICE_ = 7;
		break;
	default:
		break;
	}
	switch (UserChoice[1])
	{
	case '1':
		CHOICE2_ = 7;
		break;
	case'2':
		CHOICE2_ = 6;
		break;
	case'3':
		CHOICE2_ = 5;
		break;
	case'4':
		CHOICE2_ = 4;
		break;
	case'5':
		CHOICE2_ = 3;
		break;
	case'6':
		CHOICE2_ = 2;
		break;
	case'7':
		CHOICE2_ = 1;
		break;
	case'8':
		CHOICE2_ = 0;
		break;
	default:
		break;


	}
	MASSIV[CHOICE_][CHOICE2_] = 1;

	this->Invalidate();



}







