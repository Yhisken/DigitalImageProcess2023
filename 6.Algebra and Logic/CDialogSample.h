#pragma once
#include "afxdialogex.h"


// CDialogSample 对话框

class CDialogSample : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogSample)

public:
	CDialogSample(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogSample();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SAMPLING };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	float m_fXStep;
	float m_fYStep;
};
