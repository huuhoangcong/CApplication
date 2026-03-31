#include "pch.h"
#include "Application.h"
#include "afxdialogex.h"
#include "Task2.h"


// CTask2Dlg dialog

IMPLEMENT_DYNAMIC(CTask2Dlg, CDialogEx)

CTask2Dlg::CTask2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CTask2Dlg::IDD, pParent)
{

}

CTask2Dlg::~CTask2Dlg()
{

}

void CTask2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_BTN_GWM, m_btnGWM);
	DDX_Control(pDX, ID_BTN_TM, m_btnTM);
}

BOOL CTask2Dlg::OnInitDialog()
{
	InitUIComponent();
	CDialogEx::OnInitDialog();
	AdjustLayout();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CTask2Dlg, CDialogEx)
	ON_BN_CLICKED(ID_BTN_GWM, &CTask2Dlg::OnBnClickGWM)
	ON_BN_CLICKED(ID_BTN_TM, &CTask2Dlg::OnBnClickTM)
	//ON_MESSAGE(UPDATE_LABEL_MSG, &CTask2Dlg::OnUpdateLabel)
END_MESSAGE_MAP()


// CTask2Dlg message handlers

void CTask2Dlg::OnBnClickGWM()
{
	CTask2SubDlg subDlg(this, DlgOpnMode::Mode_GWM, m_iGWM);
	if (IDOK == subDlg.DoModal()) {
		m_iGWM = subDlg.GetCbbSel();
		UpdateLabel(DlgOpnMode::Mode_GWM, m_iGWM);
	}
}

void CTask2Dlg::OnBnClickTM()
{
	CTask2SubDlg subDlg(this, DlgOpnMode::Mode_TM, m_iTM);
	if (IDOK == subDlg.DoModal()) {
		m_iTM = subDlg.GetCbbSel();
		UpdateLabel(DlgOpnMode::Mode_TM, m_iTM);
	}
}

void CTask2Dlg::UpdateLabel(DlgOpnMode mode, int iMethod)
{
	CString strText = _T("");

	switch (iMethod) {
	case -1:
		strText = mode == Mode_GWM ? _T("Ground Water Method") : _T("Thermal Method");
		break;
	case 0:
		strText = mode == Mode_GWM ? _T("Static Water") : _T("Static Temperature");
		break;
	case 1:
		strText = mode == Mode_GWM ? _T("Steady FEA") : _T("Steady Thermal FEA");
		break;
	case 2:
		strText = mode == Mode_GWM ? _T("Transient FEA") : _T("Transient Thermal FEA");
		break;
	default:
		break;
	}

	if (mode == Mode_GWM)
		m_sttGWM.SetWindowText(strText);
	else
		m_sttTM.SetWindowText(strText);
}

void CTask2Dlg::InitUIComponent()
{
	m_btnGWM.Create(_T("Ground Water Method"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(0, 0, 0, 0),
		this,
		ID_BTN_GWM
	);

	m_btnTM.Create(_T("Thermal Method"),
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(0, 0, 0, 0),
		this,
		ID_BTN_TM
	);

	m_sttGWM.Create(_T("Ground Water Method"),
		WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE | WS_BORDER | WS_EX_STATICEDGE,
		CRect(0, 0, 0, 0),
		this,
		ID_LABEL_GWM
	);

	m_sttTM.Create(_T("Thermal Method"),
		WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE | WS_BORDER | WS_EX_STATICEDGE,
		CRect(0, 0, 0, 0),
		this,
		ID_LABEL_TM
	);
}

void CTask2Dlg::AdjustLayout()
{
	CRect rect;
	GetClientRect(&rect);

	CPoint pt = rect.CenterPoint();

	int cx = rect.right;
	int cy = rect.bottom;

	if (!::IsWindow(m_btnGWM.GetSafeHwnd()))
		return;

	if (!::IsWindow(m_btnTM.GetSafeHwnd()))
		return;

	if (!::IsWindow(m_sttGWM.GetSafeHwnd()))
		return;

	if (!::IsWindow(m_sttTM.GetSafeHwnd()))
		return;

	CButton* btnCancel = (CButton*)GetDlgItem(IDCANCEL);
	if (!btnCancel)
		return;

	CButton* btnOK = (CButton*)GetDlgItem(IDOK);
	if (!btnOK)
		return;

	m_btnGWM.MoveWindow(20, 20, cx / 2 - 30, cy / 2 - 40);
	m_btnTM.MoveWindow(cx / 2 + 10, 20, cx / 2 - 40, cy / 2 - 40);
	m_sttGWM.MoveWindow(20, cy / 2, cx / 2 - 30, cy / 2 - 40);
	m_sttTM.MoveWindow(cx / 2 + 10, cy / 2, cx / 2 - 40, cy / 2 - 40);
	btnOK->MoveWindow(pt.x - 80, cy - 35, 70, 30);
	btnCancel->MoveWindow(pt.x + 10, cy - 35, 70, 30);
}
