// CDialogSample.cpp: 实现文件
//

#include "pch.h"
#include "DIP-YS.h"
#include "afxdialogex.h"
#include "CDialogSample.h"


// CDialogSample 对话框

IMPLEMENT_DYNAMIC(CDialogSample, CDialogEx)

CDialogSample::CDialogSample(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SAMPLING, pParent)
	, m_fXStep(0)
	, m_fYStep(0)
	, m_fZ(0)
{

}

CDialogSample::~CDialogSample()
{
}

void CDialogSample::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_XSTEP, m_fXStep);
	DDX_Text(pDX, IDC_EDIT_YSTEP, m_fYStep);
	DDX_Text(pDX, IDC_EDIT_Z, m_fZ);
}


BEGIN_MESSAGE_MAP(CDialogSample, CDialogEx)
END_MESSAGE_MAP()


// CDialogSample 消息处理程序
