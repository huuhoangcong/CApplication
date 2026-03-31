#pragma once

#include "pch.h"
#include "framework.h"
#include "afxdialogex.h"
#include "Task2SubDlg.h"

class CTask2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTask2Dlg)
public:
	CTask2Dlg(CWnd* pParent = nullptr);
	virtual ~CTask2Dlg();

	// Dialog Data
	enum { IDD = IDD_TASK2_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickGWM();
	afx_msg void OnBnClickTM();
	void UpdateLabel(DlgOpnMode mode, int iMethod);

private:
	void InitUIComponent();
	void AdjustLayout();

private:
	enum CtrlID {
		ID_BTN_GWM = 1001,
		ID_BTN_TM = 1002,

		ID_LABEL_GWM = 2001,
		ID_LABEL_TM = 2002,
	};

	CButton m_btnGWM;
	CButton m_btnTM;

	CStatic m_sttGWM;
	CStatic m_sttTM;

	int m_iGWM = -1;
	int m_iTM = -1;
};
