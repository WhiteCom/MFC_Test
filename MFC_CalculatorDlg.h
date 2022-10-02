
// MFC_CalculatorDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CMFC_CalculatorDlg dialog
class CMFC_CalculatorDlg : public CDialogEx
{
// Construction
public:
	CMFC_CalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();

	afx_msg void OnBnClickedButton_0();
	afx_msg void OnBnClickedButton_1();
	afx_msg void OnBnClickedButton_2();
	afx_msg void OnBnClickedButton_3();
	afx_msg void OnBnClickedButton_4();
	afx_msg void OnBnClickedButton_5();
	afx_msg void OnBnClickedButton_6();
	afx_msg void OnBnClickedButton_7();
	afx_msg void OnBnClickedButton_8();
	afx_msg void OnBnClickedButton_9();

	afx_msg void OnBnClickedButton_Plus();
	afx_msg void OnBnClickedButton_Minus();
	afx_msg void OnBnClickedButton_Multiply();
	afx_msg void OnBnClickedButton_Divide();
	afx_msg void OnBnClickedButton_Modulo();
	afx_msg void OnBnClickedButton_Result();

	// for calculate function
	// only integer calculator
	int precedence(TCHAR op);
	int applyOp(int op1, int op2, TCHAR op3);
	int evaluate(CString tokens);

	CEdit m_EditCalculation;
	
};
