#include "pch.h"
#include "Application.h"
#include "afxdialogex.h"
#include "Task2SubDlg.h"

// CTask2Dlg dialog

IMPLEMENT_DYNAMIC(CTask2SubDlg, CDialogEx)

CTask2SubDlg::CTask2SubDlg(CWnd* pParent, DlgOpnMode mode)
	: CDialogEx(CTask2SubDlg::IDD, pParent)
{
	m_mode = mode;
	m_strDlgName = m_mode == Mode_GWM ? _T("Water Ground Method") : _T("Thermal Method");
}

CTask2SubDlg::~CTask2SubDlg()
{
}

BEGIN_MESSAGE_MAP(CTask2SubDlg, CDialogEx)
	ON_CBN_SELCHANGE(ID_CBB_METHOD, &CTask2SubDlg::OnCbnChange)
END_MESSAGE_MAP()

void CTask2SubDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, ID_CBB_METHOD, m_cbbMethod);
	DDX_Control(pDX, ID_LABEL, m_sttLabel);
}

BOOL CTask2SubDlg::OnInitDialog()
{
	SetWindowText(m_strDlgName);
	InitUIComponent();
	CDialogEx::OnInitDialog();

	m_cbbMethod.AddString(_T(""));
	if (m_mode == Mode_GWM) {
		m_cbbMethod.AddString(_T("Static Water"));
		m_cbbMethod.AddString(_T("Steady FEA"));
		m_cbbMethod.AddString(_T("Transient FEA"));
	}
	else {
		m_cbbMethod.AddString(_T("Static Temperature"));
		m_cbbMethod.AddString(_T("Steady Thermal FEA"));
		m_cbbMethod.AddString(_T("Transient Thermal FEA"));
	}
	m_cbbMethod.SetCurSel(0);

	AdjustLayout();
	return TRUE;
}

void CTask2SubDlg::OnCbnChange()
{
	int iMethod = m_cbbMethod.GetCurSel();
	m_pParentWnd->SendMessage(UPDATE_LABEL_MSG, WPARAM(m_mode), LPARAM(iMethod));
}

void CTask2SubDlg::InitUIComponent()
{
	m_sttLabel.Create(m_strDlgName,
		WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE,
		CRect(0, 0, 0, 0),
		this,
		ID_LABEL
	);

	m_cbbMethod.Create(
		CBS_DROPDOWNLIST | WS_VSCROLL | WS_TABSTOP | WS_VISIBLE, 
		CRect(0, 0, 0, 0), 
		this, 
		ID_CBB_METHOD);
}

void CTask2SubDlg::AdjustLayout()
{
	CRect rect;
	GetClientRect(&rect);

	CPoint pt = rect.CenterPoint();

	int cx = rect.right;
	int cy = rect.bottom;

	if (!::IsWindow(m_sttLabel.GetSafeHwnd()))
		return;

	if (!::IsWindow(m_cbbMethod.GetSafeHwnd()))
		return;

	CButton* btnCancel = (CButton*)GetDlgItem(IDCANCEL);
	if (!btnCancel)
		return;

	CButton* btnOK = (CButton*)GetDlgItem(IDOK);
	if (!btnOK)
		return;

	m_sttLabel.MoveWindow(cx / 4, cy / 2 - 40, cx / 2, 40);
	m_cbbMethod.MoveWindow(cx / 4, cy / 2, cx / 2, 50);

	btnOK->MoveWindow(pt.x - 80, cy - 35, 70, 30);
	btnCancel->MoveWindow(pt.x + 10, cy - 35, 70, 30);
}
