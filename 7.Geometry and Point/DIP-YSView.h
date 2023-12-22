
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
	afx_msg void OnArithmeticAdd();
	afx_msg void OnArithmeticSubtract();
	afx_msg void OnArithmeticMultiply();
	afx_msg void OnArithmeticDivide();
	afx_msg void OnArithmeticLinearburn();
	afx_msg void OnArithmeticScreen();
	afx_msg void OnArithmeticExclusion();
	afx_msg void OnArithmeticDifference();
	afx_msg void OnArithmeticNegative();
	afx_msg void OnArithmeticColordodge();
	afx_msg void OnArithmeticColorburn();
	afx_msg void OnGrayMiddle();
	afx_msg void OnGrayWeightedaveragehsv();
	afx_msg void OnGrayCompoundforl();
	afx_msg void OnArithmeticAlpha();
	afx_msg void OnArithmeticMultiplyalpha();
	afx_msg void OnArithmeticOverlay();
	afx_msg void OnArithmeticHardlight();
	afx_msg void OnArithmeticVividlight();
	afx_msg void OnArithmeticLinearlight();
	afx_msg void OnArithmeticHue();
	afx_msg void OnArithmeticSaturation();
	afx_msg void OnArithmeticLuminosity();
	afx_msg void OnArithmeticColor();
	afx_msg void OnLogicMin();
	afx_msg void OnLogicMax();
	afx_msg void OnLogicPinlight();
	afx_msg void OnLogicAnd();
	afx_msg void OnLogicOr();
	afx_msg void OnLogicNot();
	afx_msg void OnLogicXor();
	afx_msg void OnLogicNand();
	afx_msg void OnLogicNor();
	afx_msg void OnLogicCompareand();
	afx_msg void OnLogicCompareor();
	afx_msg void OnLogicComparexor();
	afx_msg void OnGeometryTranslate();
	afx_msg void OnGeometryTranslatescale();
	afx_msg void OnGeometryTranslateaffine();
	afx_msg void OnGeometryScalenearest();
	afx_msg void OnGeometryScalebilinear();
	afx_msg void OnGeometryScalebicubic();
	afx_msg void OnGeometryScalebilinearexact();
	afx_msg void OnGeometryRotate90();
	afx_msg void OnGeometryClockwise();
	afx_msg void OnGeometryRotate270();
	afx_msg void OnGeometryRotate();
	afx_msg void OnGeometryRotatescale();
	afx_msg void OnGeometryShear();
	afx_msg void OnGeometryAffine();
	afx_msg void OnGeometryMirror();
	afx_msg void OnGeometryMirrorvertical();
	afx_msg void OnGeometryMirrorcomepletely();
	afx_msg void OnGeometryTranspose();
	afx_msg void OnGeometryPerspective();
	int m_nStart;
	afx_msg void OnGeometryPoints();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnGeometryTwirl();
	afx_msg void OnGeometryRipple();
	afx_msg void OnGeometrySpherical();
	afx_msg void OnGeometryStitch();
	Point2f m_pointsSrc[100];
	Point2f m_pointsDst[100];
	afx_msg void OnPointBrightnessmat();
	afx_msg void OnPointBrightness();
	afx_msg void OnPointContrastmat();
	afx_msg void OnPointContrast();
	afx_msg void OnPointAutocontrast();
	afx_msg void OnPointGlobalmat();
	afx_msg void OnPointGlobal();
	afx_msg void OnPointLocal();
	afx_msg void OnPointPiecewise();
	afx_msg void OnPointLogarithmic();
	afx_msg void OnPointExponent();
	afx_msg void OnPointPower();
	afx_msg void OnPointBlackwhite();
	afx_msg void OnPointPreserve();
	afx_msg void OnPointBit();
	afx_msg void OnPointAutocontrastmat();
};

#ifndef _DEBUG  // DIP-YSView.cpp 中的调试版本
inline CDIPYSDoc* CDIPYSView::GetDocument() const
   { return reinterpret_cast<CDIPYSDoc*>(m_pDocument); }
#endif

