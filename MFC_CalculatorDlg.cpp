
// MFC_CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFC_Calculator.h"
#include "MFC_CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//================================================================================================
// Global Variale ( 계산을 위한 전역 변수 ) 
//
// 개인 프로젝트이고, 간단한 계산기이다 보니 전역변수로 처리했지만,
// 다수인원이 참가하는 프로젝트에선 이렇게 하지말기
//================================================================================================

CString g_Calculate_Numbers;

//================================================================================================
// MFC Basic Code
//================================================================================================

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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

// CMFC_CalculatorDlg dialog

CMFC_CalculatorDlg::CMFC_CalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC_CALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC_CalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EditCalculation);
}

BEGIN_MESSAGE_MAP(CMFC_CalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_EN_CHANGE(IDC_EDIT1, &CMFC_CalculatorDlg::OnEnChangeEdit1)

	ON_BN_CLICKED(IDC_BUTTON1, &CMFC_CalculatorDlg::OnBnClickedButton_1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC_CalculatorDlg::OnBnClickedButton_2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC_CalculatorDlg::OnBnClickedButton_3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFC_CalculatorDlg::OnBnClickedButton_4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFC_CalculatorDlg::OnBnClickedButton_5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFC_CalculatorDlg::OnBnClickedButton_6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFC_CalculatorDlg::OnBnClickedButton_7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFC_CalculatorDlg::OnBnClickedButton_8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFC_CalculatorDlg::OnBnClickedButton_9)
	ON_BN_CLICKED(IDC_BUTTON0, &CMFC_CalculatorDlg::OnBnClickedButton_0)

	ON_BN_CLICKED(IDC_BUTTON_PLUS,		&CMFC_CalculatorDlg::OnBnClickedButton_Plus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS,		&CMFC_CalculatorDlg::OnBnClickedButton_Minus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY,	&CMFC_CalculatorDlg::OnBnClickedButton_Multiply)
	ON_BN_CLICKED(IDC_BUTTON_DIVIDE,	&CMFC_CalculatorDlg::OnBnClickedButton_Divide)
	ON_BN_CLICKED(IDC_BUTTON_MODULO,	&CMFC_CalculatorDlg::OnBnClickedButton_Modulo)
	ON_BN_CLICKED(IDC_BUTTON_RESULT,	&CMFC_CalculatorDlg::OnBnClickedButton_Result)
END_MESSAGE_MAP()


// CMFC_CalculatorDlg message handlers

BOOL CMFC_CalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	g_Calculate_Numbers = _T("");

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	ShowWindow(SW_MINIMIZE);

	// TODO: Add extra initialization here
	UpdateData(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFC_CalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFC_CalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFC_CalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//================================================================================================
// Edit Box : 계산식 표기용
//================================================================================================

void CMFC_CalculatorDlg::OnEnChangeEdit1()
{

}

//================================================================================================
// Button
// 0 ~ 9 : 숫자
// +, -, *, /, % : 계산 수식
//================================================================================================
void CMFC_CalculatorDlg::OnBnClickedButton_0()
{
	g_Calculate_Numbers.Append(L"0");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_1()
{
	g_Calculate_Numbers.Append(L"1");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}
void CMFC_CalculatorDlg::OnBnClickedButton_2()
{
	g_Calculate_Numbers.Append(L"2");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_3()
{
	g_Calculate_Numbers.Append(L"3");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_4()
{
	g_Calculate_Numbers.Append(L"4");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_5()
{
	g_Calculate_Numbers.Append(L"5");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_6()
{
	g_Calculate_Numbers.Append(L"6");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_7()
{
	g_Calculate_Numbers.Append(L"7");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_8()
{
	g_Calculate_Numbers.Append(L"8");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_9()
{
	g_Calculate_Numbers.Append(L"9");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_Plus()
{
	g_Calculate_Numbers.Append(L"+");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_Minus()
{
	g_Calculate_Numbers.Append(L"-");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_Multiply()
{
	g_Calculate_Numbers.Append(L"*");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_Divide()
{
	g_Calculate_Numbers.Append(L"/");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_Modulo()
{
	g_Calculate_Numbers.Append(L"%");

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

void CMFC_CalculatorDlg::OnBnClickedButton_Result()
{
	if (g_Calculate_Numbers.IsEmpty())
		MessageBox(L"No Message in g_Calculate_Numbers!", L"Null Error", 0);

	// Call calculate function : evaluate
	int calc_result = evaluate(g_Calculate_Numbers);
	
	//g_Calculate_Numbers.Format(_T("%d", calc_result));
	g_Calculate_Numbers.Format(L"%d", calc_result);
	

	m_EditCalculation.SetWindowTextW(g_Calculate_Numbers);
}

//================================================================================================
// Calculate Function
//================================================================================================

// 연산자 우선순위 결정
int CMFC_CalculatorDlg::precedence(TCHAR op)
{
	if (op == '-' || op == '+')
		return 1;
	if (op == '*' || op == '/' || op == '%')
		return 2;
	return 0;
}

// 중간연산자 처리용
int CMFC_CalculatorDlg::applyOp(int op1, int op2, TCHAR op3)
{
	switch (op3)
	{
	case '+': return op1 + op2;
	case '-': return op1 - op2;
	case '*': return op1 * op2;
	case '/': return op1 / op2;
	case '%': return op1 % op2;
	}

	return -1;
}

// 연산결과 반환
int CMFC_CalculatorDlg::evaluate(CString tokens)
{
	std::stack<int> values;
	std::stack<TCHAR> ops;

	for (int i = 0; i < tokens.GetLength(); i++)
	{
		if (tokens[i] == ' ')
			continue;
		else if (tokens[i] == '(')
			ops.push(tokens[i]);
		else if (isdigit(tokens[i]))
		{
			int val = 0;

			while (i < tokens.GetLength() && isdigit(tokens[i]))
			{
				val = (val * 10) + (tokens[i] - '0');
				i++;
			}

			values.push(val);

			// right now the i points to
			// the character next to the digit
			// since the for loop also increases
			// the i, we would skip one
			// token position; we need to
			// decrease the value of i by 1 to
			// correct the offset
			i--;
		}

		else if (tokens[i] == ')')
		{
			while (!ops.empty() && ops.top() != '(')
			{
				int val2 = values.top();
				values.pop();

				int val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(applyOp(val1, val2, op));
			}

			// pop opening brace.
			if (!ops.empty())
				ops.pop();
		}

		// Current token is an operator
		else
		{
			while (!ops.empty() && precedence(ops.top())
				>= precedence(tokens[i]))
			{
				int val2 = values.top();
				values.pop();

				int val1 = values.top();
				values.pop();

				char op = ops.top();
				ops.pop();

				values.push(applyOp(val1, val2, op));
			}
			
			// Push Current token to 'ops'
			ops.push(tokens[i]);
		}
	}

	// Entire expression has been parsed at
	// this point, apply remaining ops to remaining
	// values.

	while (!ops.empty())
	{
		int val2 = values.top();
		values.pop();

		int val1 = values.top();
		values.pop();

		char op = ops.top();
		ops.pop();

		values.push(applyOp(val1, val2, op));
	}

	// Top of 'values' contains result, return it
	return values.top();
}


