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
}

BOOL CTask2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	MoveWindow(100, 100, 309, 176);
	return TRUE;
}


BEGIN_MESSAGE_MAP(CTask2Dlg, CDialogEx)
END_MESSAGE_MAP()


// CTask2Dlg message handlers
