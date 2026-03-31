#pragma once

#include "pch.h"
#include "framework.h"
#include "afxdialogex.h"

enum DlgOpnMode {
	Mode_GWM = 0,
	Mode_TM
};

class CTask2SubDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTask2SubDlg)
public:
	CTask2SubDlg(CWnd* pParent = nullptr, DlgOpnMode mode = Mode_GWM, int iSel = 0);
	virtual ~CTask2SubDlg();

	// Dialog Data
	enum { IDD = IDD_SUB_DLG };

	DlgOpnMode GetOpnMode() { return m_mode; }
	int GetCbbSel() { return m_iCbbSel; }

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	// Implementation
protected:
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//afx_msg void OnCbnChange();

private:
	void InitUIComponent();
	void AdjustLayout();

private:
	enum CtrlID {
		ID_LABEL = 1001,
		ID_CBB_METHOD = 1002,
	};

	DlgOpnMode m_mode = DlgOpnMode::Mode_GWM;
	CString m_strDlgName = _T("");

	CStatic m_sttLabel;
	CComboBox m_cbbMethod;
	int m_iCbbSel = 0;
};
