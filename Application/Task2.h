#pragma once

#include "pch.h"
#include "framework.h"
#include "ApplicationDlg.h"
#include "afxdialogex.h"

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
};
