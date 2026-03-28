
// ApplicationDlg.h : header file
//

#pragma once


// CApplicationDlg dialog
class CApplicationDlg : public CDialogEx
{
// Construction
public:
	CApplicationDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_APPLICATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	virtual void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnClickedTask1();
	afx_msg void OnClickedTask2();

private:
	void InitUIComponent();
	void AdjustLayout();

private:

	enum CtrlID {
		ID_BTN_TASK1 = 1001,
		ID_BTN_TASK2 = 1002
	};

	CButton m_btnTask1;
	CButton m_btnTask2;
};
