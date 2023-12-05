
// DIP-YSView.h: CDIPYSView 类的接口
//

#pragma once


class CDIPYSView : public CScrollView
{
protected: // 仅从序列化创建
	CDIPYSView() noexcept;
	DECLARE_DYNCREATE(CDIPYSView)

// 特性
public:
	CDIPYSDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CDIPYSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;


#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDigitizeSubsampling();
	afx_msg void OnDigitizeMosaic();
	afx_msg void OnDigitizeQuantizerule();
	uchar QuantizeRule(uchar ucLevel, uchar ucChannel);
	afx_msg void OnDigitizeQuantize();
	afx_msg void OnColorRed();
	afx_msg void OnColorGreen();
	afx_msg void OnColorBlue();
	afx_msg void OnColorBgr();
	afx_msg void OnColorCyan();
	afx_msg void OnColorMagenta();
	afx_msg void OnColorYellow();
	afx_msg void OnColorLab();
	afx_msg void OnColorLightness();
	afx_msg void OnColorA();
	afx_msg void OnColorB();
	afx_msg void OnColorHsv();
	afx_msg void OnColorHue();
	afx_msg void OnColorSaturation();
	afx_msg void OnColorValue();
	afx_msg void OnColorHueadd();
	afx_msg void OnGrayMin();
	afx_msg void OnColorizeJet();
	afx_msg void OnColorizeBone();
	afx_msg void OnColorizeHsv();
	afx_msg void OnGrayMax();
};

#ifndef _DEBUG  // DIP-YSView.cpp 中的调试版本
inline CDIPYSDoc* CDIPYSView::GetDocument() const
   { return reinterpret_cast<CDIPYSDoc*>(m_pDocument); }
#endif

