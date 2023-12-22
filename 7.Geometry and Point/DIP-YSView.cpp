﻿
// DIP-YSView.cpp: CDIPYSView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "DIP-YS.h"
#endif

#include "DIP-YSDoc.h"
#include "DIP-YSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MainFrm.h"
#include "CDialogSample.h"

// CDIPYSView

IMPLEMENT_DYNCREATE(CDIPYSView, CScrollView)

BEGIN_MESSAGE_MAP(CDIPYSView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDIPYSView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DIGITIZE_SUBSAMPLING, &CDIPYSView::OnDigitizeSubsampling)
	ON_COMMAND(ID_DIGITIZE_MOSAIC, &CDIPYSView::OnDigitizeMosaic)
	ON_COMMAND(ID_DIGITIZE_QUANTIZERULE, &CDIPYSView::OnDigitizeQuantizerule)
	ON_COMMAND(ID_DIGITIZE_QUANTIZE, &CDIPYSView::OnDigitizeQuantize)
	ON_COMMAND(ID_COLOR_RED, &CDIPYSView::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CDIPYSView::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CDIPYSView::OnColorBlue)
	ON_COMMAND(ID_COLOR_BGR, &CDIPYSView::OnColorBgr)
	ON_COMMAND(ID_COLOR_CYAN, &CDIPYSView::OnColorCyan)
	ON_COMMAND(ID_COLOR_MAGENTA, &CDIPYSView::OnColorMagenta)
	ON_COMMAND(ID_COLOR_YELLOW, &CDIPYSView::OnColorYellow)
	ON_COMMAND(ID_COLOR_LAB, &CDIPYSView::OnColorLab)
	ON_COMMAND(ID_COLOR_LIGHTNESS, &CDIPYSView::OnColorLightness)
	ON_COMMAND(ID_COLOR_A, &CDIPYSView::OnColorA)
	ON_COMMAND(ID_COLOR_B, &CDIPYSView::OnColorB)
	ON_COMMAND(ID_COLOR_HSV, &CDIPYSView::OnColorHsv)
	ON_COMMAND(ID_COLOR_HUE, &CDIPYSView::OnColorHue)
	ON_COMMAND(ID_COLOR_SATURATION, &CDIPYSView::OnColorSaturation)
	ON_COMMAND(ID_COLOR_VALUE, &CDIPYSView::OnColorValue)
	ON_COMMAND(ID_COLOR_HUEADD, &CDIPYSView::OnColorHueadd)
	ON_COMMAND(ID_GRAY_MIN, &CDIPYSView::OnGrayMin)
	ON_COMMAND(ID_COLORIZE_JET, &CDIPYSView::OnColorizeJet)
	ON_COMMAND(ID_COLORIZE_BONE, &CDIPYSView::OnColorizeBone)
	ON_COMMAND(ID_COLORIZE_HSV, &CDIPYSView::OnColorizeHsv)
	ON_COMMAND(ID_GRAY_MAX, &CDIPYSView::OnGrayMax)
	ON_COMMAND(ID_ARITHMETIC_ADD, &CDIPYSView::OnArithmeticAdd)
	ON_COMMAND(ID_ARITHMETIC_SUBTRACT, &CDIPYSView::OnArithmeticSubtract)
	ON_COMMAND(ID_ARITHMETIC_MULTIPLY, &CDIPYSView::OnArithmeticMultiply)
	ON_COMMAND(ID_ARITHMETIC_DIVIDE, &CDIPYSView::OnArithmeticDivide)
	ON_COMMAND(ID_ARITHMETIC_LINEARBURN, &CDIPYSView::OnArithmeticLinearburn)
	ON_COMMAND(ID_ARITHMETIC_SCREEN, &CDIPYSView::OnArithmeticScreen)
	ON_COMMAND(ID_ARITHMETIC_EXCLUSION, &CDIPYSView::OnArithmeticExclusion)
	ON_COMMAND(ID_ARITHMETIC_DIFFERENCE, &CDIPYSView::OnArithmeticDifference)
	ON_COMMAND(ID_ARITHMETIC_NEGATIVE, &CDIPYSView::OnArithmeticNegative)
	ON_COMMAND(ID_ARITHMETIC_COLORDODGE, &CDIPYSView::OnArithmeticColordodge)
	ON_COMMAND(ID_ARITHMETIC_COLORBURN, &CDIPYSView::OnArithmeticColorburn)
	ON_COMMAND(ID_GRAY_MIDDLE, &CDIPYSView::OnGrayMiddle)
	ON_COMMAND(ID_GRAY_WEIGHTEDAVERAGEHSV, &CDIPYSView::OnGrayWeightedaveragehsv)
	ON_COMMAND(ID_GRAY_COMPOUNDFORL, &CDIPYSView::OnGrayCompoundforl)
	ON_COMMAND(ID_ARITHMETIC_ALPHA, &CDIPYSView::OnArithmeticAlpha)
	ON_COMMAND(ID_ARITHMETIC_MULTIPLYALPHA, &CDIPYSView::OnArithmeticMultiplyalpha)
	ON_COMMAND(ID_ARITHMETIC_OVERLAY, &CDIPYSView::OnArithmeticOverlay)
	ON_COMMAND(ID_ARITHMETIC_HARDLIGHT, &CDIPYSView::OnArithmeticHardlight)
	ON_COMMAND(ID_ARITHMETIC_VIVIDLIGHT, &CDIPYSView::OnArithmeticVividlight)
	ON_COMMAND(ID_ARITHMETIC_LINEARLIGHT, &CDIPYSView::OnArithmeticLinearlight)
	ON_COMMAND(ID_ARITHMETIC_HUE, &CDIPYSView::OnArithmeticHue)
	ON_COMMAND(ID_ARITHMETIC_SATURATION, &CDIPYSView::OnArithmeticSaturation)
	ON_COMMAND(ID_ARITHMETIC_LUMINOSITY, &CDIPYSView::OnArithmeticLuminosity)
	ON_COMMAND(ID_ARITHMETIC_COLOR, &CDIPYSView::OnArithmeticColor)
	ON_COMMAND(ID_LOGIC_MIN, &CDIPYSView::OnLogicMin)
	ON_COMMAND(ID_LOGIC_MAX, &CDIPYSView::OnLogicMax)
	ON_COMMAND(ID_LOGIC_PINLIGHT, &CDIPYSView::OnLogicPinlight)
	ON_COMMAND(ID_LOGIC_AND, &CDIPYSView::OnLogicAnd)
	ON_COMMAND(ID_LOGIC_OR, &CDIPYSView::OnLogicOr)
	ON_COMMAND(ID_LOGIC_NOT, &CDIPYSView::OnLogicNot)
	ON_COMMAND(ID_LOGIC_XOR, &CDIPYSView::OnLogicXor)
	ON_COMMAND(ID_LOGIC_NAND, &CDIPYSView::OnLogicNand)
	ON_COMMAND(ID_LOGIC_NOR, &CDIPYSView::OnLogicNor)
	ON_COMMAND(ID_LOGIC_COMPAREAND, &CDIPYSView::OnLogicCompareand)
	ON_COMMAND(ID_LOGIC_COMPAREOR, &CDIPYSView::OnLogicCompareor)
	ON_COMMAND(ID_LOGIC_COMPAREXOR, &CDIPYSView::OnLogicComparexor)
	ON_COMMAND(ID_GEOMETRY_TRANSLATE, &CDIPYSView::OnGeometryTranslate)
	ON_COMMAND(ID_GEOMETRY_TRANSLATESCALE, &CDIPYSView::OnGeometryTranslatescale)
	ON_COMMAND(ID_GEOMETRY_TRANSLATEAFFINE, &CDIPYSView::OnGeometryTranslateaffine)
	ON_COMMAND(ID_GEOMETRY_SCALENEAREST, &CDIPYSView::OnGeometryScalenearest)
	ON_COMMAND(ID_GEOMETRY_SCALEBILINEAR, &CDIPYSView::OnGeometryScalebilinear)
	ON_COMMAND(ID_GEOMETRY_SCALEBICUBIC, &CDIPYSView::OnGeometryScalebicubic)
	ON_COMMAND(ID_GEOMETRY_SCALEBILINEAREXACT, &CDIPYSView::OnGeometryScalebilinearexact)
	ON_COMMAND(ID_GEOMETRY_ROTATE90, &CDIPYSView::OnGeometryRotate90)
	ON_COMMAND(ID_GEOMETRY_CLOCKWISE, &CDIPYSView::OnGeometryClockwise)
	ON_COMMAND(ID_GEOMETRY_ROTATE270, &CDIPYSView::OnGeometryRotate270)
	ON_COMMAND(ID_GEOMETRY_ROTATE, &CDIPYSView::OnGeometryRotate)
	ON_COMMAND(ID_GEOMETRY_ROTATESCALE, &CDIPYSView::OnGeometryRotatescale)
	ON_COMMAND(ID_GEOMETRY_SHEAR, &CDIPYSView::OnGeometryShear)
	ON_COMMAND(ID_GEOMETRY_AFFINE, &CDIPYSView::OnGeometryAffine)
	ON_COMMAND(ID_GEOMETRY_MIRROR, &CDIPYSView::OnGeometryMirror)
	ON_COMMAND(ID_GEOMETRY_MIRRORVERTICAL, &CDIPYSView::OnGeometryMirrorvertical)
	ON_COMMAND(ID_GEOMETRY_MIRRORCOMEPLETELY, &CDIPYSView::OnGeometryMirrorcomepletely)
	ON_COMMAND(ID_GEOMETRY_TRANSPOSE, &CDIPYSView::OnGeometryTranspose)
	ON_COMMAND(ID_GEOMETRY_PERSPECTIVE, &CDIPYSView::OnGeometryPerspective)
	ON_COMMAND(ID_GEOMETRY_POINTS, &CDIPYSView::OnGeometryPoints)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_GEOMETRY_TWIRL, &CDIPYSView::OnGeometryTwirl)
	ON_COMMAND(ID_GEOMETRY_RIPPLE, &CDIPYSView::OnGeometryRipple)
	ON_COMMAND(ID_GEOMETRY_SPHERICAL, &CDIPYSView::OnGeometrySpherical)
	ON_COMMAND(ID_GEOMETRY_STITCH, &CDIPYSView::OnGeometryStitch)
	ON_COMMAND(ID_POINT_BRIGHTNESSMAT, &CDIPYSView::OnPointBrightnessmat)
	ON_COMMAND(ID_POINT_BRIGHTNESS, &CDIPYSView::OnPointBrightness)
	ON_COMMAND(ID_POINT_CONTRASTMAT, &CDIPYSView::OnPointContrastmat)
	ON_COMMAND(ID_POINT_CONTRAST, &CDIPYSView::OnPointContrast)
	ON_COMMAND(ID_POINT_AUTOCONTRAST, &CDIPYSView::OnPointAutocontrast)
	ON_COMMAND(ID_POINT_GLOBALMAT, &CDIPYSView::OnPointGlobalmat)
	ON_COMMAND(ID_POINT_GLOBAL, &CDIPYSView::OnPointGlobal)
	ON_COMMAND(ID_POINT_LOCAL, &CDIPYSView::OnPointLocal)
		ON_COMMAND(ID_POINT_PIECEWISE, &CDIPYSView::OnPointPiecewise)
		ON_COMMAND(ID_POINT_LOGARITHMIC, &CDIPYSView::OnPointLogarithmic)
		ON_COMMAND(ID_POINT_EXPONENT, &CDIPYSView::OnPointExponent)
		ON_COMMAND(ID_POINT_POWER, &CDIPYSView::OnPointPower)
		ON_COMMAND(ID_POINT_BLACKWHITE, &CDIPYSView::OnPointBlackwhite)
		ON_COMMAND(ID_POINT_PRESERVE, &CDIPYSView::OnPointPreserve)
		ON_COMMAND(ID_POINT_BIT, &CDIPYSView::OnPointBit)
		ON_COMMAND(ID_POINT_AUTOCONTRASTMAT, &CDIPYSView::OnPointAutocontrastmat)
		END_MESSAGE_MAP()

// CDIPYSView 构造/析构

CDIPYSView::CDIPYSView() noexcept
{
	// TODO: 在此处添加构造代码

}

CDIPYSView::~CDIPYSView()
{
}

BOOL CDIPYSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// CDIPYSView 绘图




// CDIPYSView 打印


void CDIPYSView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDIPYSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CDIPYSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CDIPYSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CDIPYSView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CDIPYSView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CDIPYSView 诊断

#ifdef _DEBUG
void CDIPYSView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CDIPYSView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CDIPYSDoc* CDIPYSView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDIPYSDoc)));
	return (CDIPYSDoc*)m_pDocument;
}
#endif //_DEBUG


// CDIPYSView 消息处理程序
void CDIPYSView::OnDraw(CDC* pDC)
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: add draw code for native data here
	if (!pDoc->m_ImageOpen.IsNull())
	{
		pDoc->m_ImageOpen.StretchBlt(
			pDC->m_hDC,
			0, 0,
			pDoc->m_ImageOpen.GetWidth(),
			pDoc->m_ImageOpen.GetHeight(),
			SRCCOPY);
	}
}
void CDIPYSView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	if (!pDoc->m_ImageOpen.IsNull())
	{
		sizeTotal.cx = pDoc->m_ImageOpen.GetWidth();
		sizeTotal.cy = pDoc->m_ImageOpen.GetHeight();
	}
	SetScrollSizes(MM_TEXT, sizeTotal);
}


void CDIPYSView::OnDigitizeSubsampling()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	float fStepWidth;
	float fStepHeight;

	fStepWidth = 4;
	fStepHeight = 2;
	////////////////////////////////////////////////////////////////////////
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fStepWidth;
	DialogSampleOne.m_fYStep = fStepHeight;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fStepWidth = DialogSampleOne.m_fXStep;
		fStepHeight = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
////////////////////////////////////////////////////////////////////////
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows / fStepHeight,
		pDoc->m_MatOpen.cols / fStepWidth, CV_8UC3);
	int width = pDocNew->m_MatOpen.cols;//图片的宽度
	int height = pDocNew->m_MatOpen.rows;//图片的高度
	int channel = pDocNew->m_MatOpen.channels();

	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < channel; c++) {
				int k = (int)(pDoc->m_MatOpen.at<cv::Vec3b>(y * fStepHeight, x * fStepWidth)[c]);
				pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = (uchar)k;
			}
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnDigitizeMosaic()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int nMosaicWidth = 5;
	int nMosaicHeight = 10;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = nMosaicWidth;
	DialogSampleOne.m_fYStep = nMosaicHeight;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		nMosaicWidth = DialogSampleOne.m_fXStep;
		nMosaicHeight = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();

	pDocNew->m_MatOpen = pDoc->m_MatOpen;
	int width = pDocNew->m_MatOpen.rows;//图片的长度
	int height = pDocNew->m_MatOpen.cols;//图片的宽度
	//i和j代表了矩形区域的左上角的像素坐标
	for (int i = 0; i < width; i += nMosaicWidth) {
		for (int j = 0; j < height; j += nMosaicHeight) {
			//对矩形区域内的每一个像素值进行遍历
			for (int k = i; k < nMosaicWidth + i && k < width; k++) {
				for (int m = j; m < nMosaicHeight + j && m < height; m++) {
					//在这里进行颜色的修改
					pDocNew->m_MatOpen.at<Vec3b>(k, m)[0] = pDoc->m_MatOpen.at<Vec3b>(i, j)[0];
					pDocNew->m_MatOpen.at<Vec3b>(k, m)[1] = pDoc->m_MatOpen.at<Vec3b>(i, j)[1];
					pDocNew->m_MatOpen.at<Vec3b>(k, m)[2] = pDoc->m_MatOpen.at<Vec3b>(i, j)[2];
				}
			}
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnDigitizeQuantizerule()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int nLevels;
	nLevels = 2;

	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = nLevels;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		nLevels = DialogSampleOne.m_fXStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = pDoc->m_MatOpen;


	int height = pDocNew->m_MatOpen.rows;//图片的长度
	int width = pDocNew->m_MatOpen.cols;//图片的宽度
	int channel = pDocNew->m_MatOpen.channels();
	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < channel; c++) {
				pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] =
					QuantizeRule(nLevels, pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c]);
			}
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}
uchar CDIPYSView::QuantizeRule(uchar ucLevel, uchar ucChannel)
{
	// TODO: Add your implementation code here.
	if (ucLevel == 2)
	{
		if (ucChannel < 128)
			return 0;
		else
		{
			return 255;
		}
	}
	if (ucLevel == 3)
	{
		if (ucChannel < 85)
			return 0;
		else
		{
			if (ucChannel < 170)
				return 128;
			else
				return 255;
		}
	}
	if (ucLevel == 4)
	{
		if (ucChannel < 64)
			return 0;
		else
		{
			if (ucChannel < 128)
				return 64;
			else
			{
				if (ucChannel < 192)
					return 170;
				else
					return 255;
			}

		}
	}
}



void CDIPYSView::OnDigitizeQuantize()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int nLevels;
	nLevels = 4;
	int nRange = 256 / nLevels;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = nLevels;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		nLevels = DialogSampleOne.m_fXStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = pDoc->m_MatOpen;
	int width = pDocNew->m_MatOpen.rows;//图片的长度
	int height = pDocNew->m_MatOpen.cols;//图片的宽度
	int channel = pDocNew->m_MatOpen.channels();
	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < channel; c++) {
				int k = (int)(pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c] / nRange) * nRange;//向下取整
				pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = (uchar)k;//uchar类型转化 与CV_8UC3对应
			}
		}
	}

	cv::normalize(pDocNew->m_MatOpen, pDocNew->m_MatOpen, 0, 255, cv::NORM_MINMAX);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
	


}


void CDIPYSView::OnColorRed()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);

	vector<Mat> channels;
	split(pDoc->m_MatOpen, channels);
	pDocNew->m_MatOpen = channels.at(2);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnColorGreen()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);

	vector<Mat> channels;
	split(pDoc->m_MatOpen, channels);
	pDocNew->m_MatOpen = channels.at(1);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnColorBlue()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);

	vector<Mat> channels;
	split(pDoc->m_MatOpen, channels);
	pDocNew->m_MatOpen = channels.at(0);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnColorBgr()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);
	vector<Mat> channels;
	split(pDoc->m_MatOpen, channels);

	Mat ChannelTemp;
	ChannelTemp = channels[2];
	channels[2] = channels[0];
	channels[0] = ChannelTemp;

	Mat MatChannels;
	merge(channels, MatChannels);
	pDocNew->m_MatOpen = MatChannels;
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnColorCyan()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);

	Mat MatChannels;
	vector<Mat> channels;
	split(pDoc->m_MatOpen, channels);
	channels[2] = Mat::zeros(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);
	merge(channels, pDocNew->m_MatOpen);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnColorMagenta()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);

	Mat MatChannels;
	vector<Mat> channels;
	split(pDoc->m_MatOpen, channels);
	channels[1] = Mat::zeros(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);
	merge(channels, pDocNew->m_MatOpen);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnColorYellow()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);

	Mat MatChannels;
	vector<Mat> channels;
	split(pDoc->m_MatOpen, channels);
	channels[0] = Mat::zeros(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);
	merge(channels, pDocNew->m_MatOpen);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnColorLab()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);

	cvtColor(pDoc->m_MatOpen, pDocNew->m_MatOpen, COLOR_BGR2Lab);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnColorLightness()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);

	Mat MatLab;
	cvtColor(pDoc->m_MatOpen, MatLab, COLOR_BGR2Lab);
	vector<Mat> channels;
	split(MatLab, channels);//分离LAB
	pDocNew->m_MatOpen = channels[0];

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnColorA()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);

	Mat MatLab;
	cvtColor(pDoc->m_MatOpen, MatLab, COLOR_BGR2Lab);
	vector<Mat> channels;
	split(MatLab, channels);//分离LAB
	pDocNew->m_MatOpen = channels[1];


	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnColorB()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);

	Mat MatLab;
	cvtColor(pDoc->m_MatOpen, MatLab, COLOR_BGR2Lab);
	vector<Mat> channels;
	split(MatLab, channels);//分离LAB
	pDocNew->m_MatOpen = channels[2];


	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}

void CDIPYSView::OnColorHsv()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);

	cvtColor(pDoc->m_MatOpen, pDocNew->m_MatOpen, COLOR_BGR2HSV);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}

void CDIPYSView::OnColorHue()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);

	Mat MatHSV;
	cvtColor(pDoc->m_MatOpen, MatHSV, COLOR_RGB2HSV);
	vector<Mat> channels;
	split(MatHSV, channels);//分离HSV
	pDocNew->m_MatOpen = channels[0];

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnColorSaturation()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);

	Mat MatHSV;
	cvtColor(pDoc->m_MatOpen, MatHSV, COLOR_RGB2HSV);
	vector<Mat> channels;
	split(MatHSV, channels);//分离HSV

	pDocNew->m_MatOpen = channels[1];

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnColorValue()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);

	Mat MatHSV;
	cvtColor(pDoc->m_MatOpen, MatHSV, COLOR_RGB2HSV);
	vector<Mat> channels;
	split(MatHSV, channels);//分离HSV

	pDocNew->m_MatOpen = channels[2];

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnColorHueadd()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC3);

	Mat MatHSV;
	cvtColor(pDoc->m_MatOpen, MatHSV, COLOR_BGR2HSV);
	vector<Mat> channels;
	split(MatHSV, channels);//分离HSV

	int nAdd;
	nAdd = 30;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = nAdd;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		nAdd = DialogSampleOne.m_fXStep;
	}
	else
	{
		return;
	}

	Mat MatBGR;
	channels[0] = channels[0] + nAdd;
	merge(channels, MatBGR);

	cvtColor(MatBGR, pDocNew->m_MatOpen, COLOR_HSV2BGR);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGrayMin()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);


	int height = pDoc->m_MatOpen.rows;//图片的长度
	int width = pDoc->m_MatOpen.cols;//图片的宽度
	int channel = pDoc->m_MatOpen.channels();
	int nMin;
	nMin = 255;
	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			nMin = 255;
			for (int c = 0; c < channel; c++) {
				int k = pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c];
				if (k < nMin)
				{
					nMin = k;
				}
			}
			pDocNew->m_MatOpen.at<uchar>(y, x) = nMin;
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnColorizeJet()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);
	applyColorMap(pDoc->m_MatOpen, pDocNew->m_MatOpen, COLORMAP_JET);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnColorizeBone()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);
	applyColorMap(pDoc->m_MatOpen, pDocNew->m_MatOpen, COLORMAP_BONE);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnColorizeHsv()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);
	applyColorMap(pDoc->m_MatOpen, pDocNew->m_MatOpen, COLORMAP_HSV);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnGrayMax()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);


	int height = pDoc->m_MatOpen.rows;//图片的长度
	int width = pDoc->m_MatOpen.cols;//图片的宽度
	int channel = pDoc->m_MatOpen.channels();
	int nMax;
	nMax = 0;
	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			nMax = 0;
			for (int c = 0; c < channel; c++) {
				int k = pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c];
				if (k > nMax)
				{
					nMax = k;
				}
			}
			pDocNew->m_MatOpen.at<uchar>(y, x) = nMax;
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnArithmeticAdd()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();


	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	add(pDoc->m_MatOpen, pDocAnother->m_MatOpen, pDocNew->m_MatOpen);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticSubtract()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	subtract(pDoc->m_MatOpen, pDocAnother->m_MatOpen, pDocNew->m_MatOpen);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticMultiply()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	pDoc->m_MatOpen.convertTo(pDoc->m_MatOpen, CV_32FC3, 1.0 / 255.0);
	pDocAnother->m_MatOpen.convertTo(pDocAnother->m_MatOpen, CV_32FC3, 1.0 / 255.0);
	multiply(pDoc->m_MatOpen, pDocAnother->m_MatOpen, pDocNew->m_MatOpen);
	pDocNew->m_MatOpen.convertTo(pDocNew->m_MatOpen, CV_8UC3, 255);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticDivide()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	divide(pDoc->m_MatOpen, pDocAnother->m_MatOpen, pDocNew->m_MatOpen);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticLinearburn()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	pDocNew->m_MatOpen = abs(pDoc->m_MatOpen + pDocAnother->m_MatOpen - 255);


	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnArithmeticScreen()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	pDoc->m_MatOpen.convertTo(pDoc->m_MatOpen, CV_32FC3, 1.0 / 255.0);
	pDocAnother->m_MatOpen.convertTo(pDocAnother->m_MatOpen, CV_32FC3, 1.0 / 255.0);

	multiply(pDoc->m_MatOpen, pDocAnother->m_MatOpen, pDocNew->m_MatOpen);

	pDocNew->m_MatOpen = pDoc->m_MatOpen + pDocAnother->m_MatOpen - pDocNew->m_MatOpen;

	pDocNew->m_MatOpen.convertTo(pDocNew->m_MatOpen, CV_8UC3, 255);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticExclusion()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	pDoc->m_MatOpen.convertTo(pDoc->m_MatOpen, CV_32FC3, 1.0 / 255.0);
	pDocAnother->m_MatOpen.convertTo(pDocAnother->m_MatOpen, CV_32FC3, 1.0 / 255.0);

	multiply(pDoc->m_MatOpen, pDocAnother->m_MatOpen, pDocNew->m_MatOpen);

	pDocNew->m_MatOpen = pDoc->m_MatOpen + pDocAnother->m_MatOpen - 2 * pDocNew->m_MatOpen;
	pDocNew->m_MatOpen.convertTo(pDocNew->m_MatOpen, CV_8UC3, 255);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticDifference()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	pDocNew->m_MatOpen = abs(pDoc->m_MatOpen - pDocAnother->m_MatOpen);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnArithmeticNegative()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	pDocNew->m_MatOpen = cv::Scalar(255, 255, 255) - pDoc->m_MatOpen;
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();



}


void CDIPYSView::OnArithmeticColordodge()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	divide(pDoc->m_MatOpen, cv::Scalar(255, 255, 255) - pDocAnother->m_MatOpen, pDocNew->m_MatOpen);
	cv::normalize(pDocNew->m_MatOpen, pDocNew->m_MatOpen, 0, 255, cv::NORM_MINMAX);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticColorburn()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	divide(cv::Scalar(255, 255, 255) - pDoc->m_MatOpen, pDocAnother->m_MatOpen, pDocNew->m_MatOpen);
	pDocNew->m_MatOpen = cv::Scalar(255, 255, 255) - pDocNew->m_MatOpen;
	cv::normalize(pDocNew->m_MatOpen, pDocNew->m_MatOpen, 0, 255, cv::NORM_MINMAX);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGrayMiddle()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);

	int height = pDoc->m_MatOpen.rows;//图片的长度
	int width = pDoc->m_MatOpen.cols;//图片的宽度
	int channel = pDoc->m_MatOpen.channels();

	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			std::vector<int> values;
			for (int c = 0; c < channel; c++) {
				int k = pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c];
				values.push_back(k);
			}
			std::sort(values.begin(), values.end());
			int median;
			if (values.size() % 2 == 0)
				median = (values[values.size() / 2 - 1] + values[values.size() / 2]) / 2;
			else
				median = values[values.size() / 2];

			pDocNew->m_MatOpen.at<uchar>(y, x) = median;
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnGrayWeightedaveragehsv()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);

	int height = pDoc->m_MatOpen.rows;//图片的长度
	int width = pDoc->m_MatOpen.cols;//图片的宽度

	cv::Mat hsvImage;
	cv::cvtColor(pDoc->m_MatOpen, hsvImage, cv::COLOR_BGR2HSV);

	float hWeight = 0.3; // 色调的权重
	float sWeight = 0.3; // 饱和度的权重
	float vWeight = 0.4; // 值的权重

	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cv::Vec3b hsvPixel = hsvImage.at<cv::Vec3b>(y, x);

			int h = hsvPixel[0];
			int s = hsvPixel[1];
			int v = hsvPixel[2];

			int gray = h * hWeight + s * sWeight + v * vWeight;
			pDocNew->m_MatOpen.at<uchar>(y, x) = gray;
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnGrayCompoundforl()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen.create(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, CV_8UC1);

	int height = pDoc->m_MatOpen.rows;//图片的长度
	int width = pDoc->m_MatOpen.cols;//图片的宽度

	cv::Mat labImage;
	cv::cvtColor(pDoc->m_MatOpen, labImage, cv::COLOR_BGR2Lab);

	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			cv::Vec3b labPixel = labImage.at<cv::Vec3b>(y, x);

			int L = labPixel[0];

			pDocNew->m_MatOpen.at<uchar>(y, x) = L;
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();
}


void CDIPYSView::OnArithmeticAlpha()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();
	float fAlpha;
	fAlpha = 0.5;

	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fAlpha;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fAlpha = DialogSampleOne.m_fXStep;
	}
	else
	{
		return;
	}


	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	addWeighted(pDoc->m_MatOpen, fAlpha, pDocAnother->m_MatOpen, (1 - fAlpha), 0, pDocNew->m_MatOpen);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticMultiplyalpha()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);

	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	float fAlpha;
	fAlpha = 0.5;

	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fAlpha;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fAlpha = DialogSampleOne.m_fXStep;
	}
	else
	{
		return;
	}

	pDoc->m_MatOpen.convertTo(pDoc->m_MatOpen, CV_32FC3, 1.0 / 255.0);
	pDocAnother->m_MatOpen.convertTo(pDocAnother->m_MatOpen, CV_32FC3, 1.0 / 255.0);
	multiply(pDocAnother->m_MatOpen, pDoc->m_MatOpen, pDocNew->m_MatOpen);
	addWeighted(pDocNew->m_MatOpen, fAlpha, pDoc->m_MatOpen, (1 - fAlpha), 0, pDocNew->m_MatOpen);
	pDocNew->m_MatOpen.convertTo(pDocNew->m_MatOpen, CV_8UC3, 255);


	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticOverlay()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);

	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());


	int height = pDoc->m_MatOpen.rows;
	int width = pDoc->m_MatOpen.cols;
	int channel = pDoc->m_MatOpen.channels();
	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < channel; c++) {

				if (pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c] > 128)
				{
					pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] =
						abs(2 * (pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] +
							pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c] -
							pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] *
							pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c] / 255) - 255);
				}
				else
				{
					pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] =
						2 * pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] *
						pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c] / 255;
				}
			}
		}
	}

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticHardlight()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);

	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();


	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	int height = pDoc->m_MatOpen.rows;
	int width = pDoc->m_MatOpen.cols;
	int channel = pDoc->m_MatOpen.channels();
	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < channel; c++) {

				if (pDocAnother -> m_MatOpen.at<cv::Vec3b>(y, x)[c] > 128)
				{
					pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] =
						abs(2 * (pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] +
							pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c] -
							pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] *
							pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c] / 255) - 255);
				}
				else
				{
					pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] =
						2 * pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] *
						pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c] / 255;
				}
			}
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticVividlight()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);

	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();


	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	int height = pDoc->m_MatOpen.rows;
	int width = pDoc->m_MatOpen.cols;
	int channel = pDoc->m_MatOpen.channels();
	float nValue;
	nValue = 0.5;

	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = nValue;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		nValue = DialogSampleOne.m_fXStep;
	}
	else
	{
		return;
	}
	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < channel; c++) {

				if (pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] > 128)
				{
					nValue = pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c] / 2 / (256 - pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c]);
					pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = nValue;

				}
				else
				{
					pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = 255 -
						(255 - pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c]) / 2 / (pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] + 1);
				}
			}
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticLinearlight()
{
	// TODO: Add your command handler code here
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);

	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	pDocNew->m_MatOpen = abs(2 * pDocAnother->m_MatOpen + pDoc->m_MatOpen - 255);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticHue()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	Mat MatHLS;
	cvtColor(pDoc->m_MatOpen, MatHLS, COLOR_BGR2HLS);

	Mat MatHLSAnother;
	cvtColor(pDocAnother->m_MatOpen, MatHLSAnother, COLOR_BGR2HLS);

	vector<Mat> channels;
	split(MatHLS, channels);

	vector<Mat> channelsAnother;
	split(MatHLSAnother, channelsAnother);

	vector<Mat> channelsHue;
	split(MatHLSAnother, channelsHue);

	channelsHue[0] = channelsAnother[0];
	channelsHue[1] = channels[1];
	channelsHue[2] = channels[2];

	merge(channelsHue, pDocNew->m_MatOpen);

	cvtColor(pDocNew->m_MatOpen, pDocNew->m_MatOpen, COLOR_HLS2BGR);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticSaturation()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);

	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	Mat MatHLS;
	cvtColor(pDoc->m_MatOpen, MatHLS, COLOR_BGR2HLS);

	Mat MatHLSAnother;
	cvtColor(pDocAnother->m_MatOpen, MatHLSAnother, COLOR_BGR2HLS);

	vector<Mat> channels;
	split(MatHLS, channels);

	vector<Mat> channelsAnother;
	split(MatHLSAnother, channelsAnother);
	vector<Mat> channelsHue;
	split(MatHLSAnother, channelsHue);

	channelsHue[0] = channels[0];
	channelsHue[1] = channels[1];
	channelsHue[2] = channelsAnother[2];

	merge(channelsHue, pDocNew->m_MatOpen);

	cvtColor(pDocNew->m_MatOpen, pDocNew->m_MatOpen, COLOR_HLS2BGR);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();



}


void CDIPYSView::OnArithmeticLuminosity()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);

	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	Mat MatHLS;
	cvtColor(pDoc->m_MatOpen, MatHLS, COLOR_BGR2HLS);

	Mat MatHLSAnother;
	cvtColor(pDocAnother->m_MatOpen, MatHLSAnother, COLOR_BGR2HLS);

	vector<Mat> channels;
	split(MatHLS, channels);

	vector<Mat> channelsAnother;
	split(MatHLSAnother, channelsAnother);


	vector<Mat> channelsHue;
	split(MatHLSAnother, channelsHue);

	channelsHue[0] = channels[0];
	channelsHue[1] = channelsAnother[1];
	channelsHue[2] = channels[2];

	merge(channelsHue, pDocNew->m_MatOpen);

	cvtColor(pDocNew->m_MatOpen, pDocNew->m_MatOpen, COLOR_HLS2BGR);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnArithmeticColor()
{
	// TODO: Add your command handler code here
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);

	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	Mat MatHLS;
	cvtColor(pDoc->m_MatOpen, MatHLS, COLOR_BGR2HLS);

	Mat MatHLSAnother;
	cvtColor(pDocAnother->m_MatOpen, MatHLSAnother, COLOR_BGR2HLS);

	vector<Mat> channels;
	split(MatHLS, channels);

	vector<Mat> channelsAnother;
	split(MatHLSAnother, channelsAnother);


	vector<Mat> channelsHue;
	split(MatHLSAnother, channelsHue);

	channelsHue[0] = channelsAnother[0];
	channelsHue[1] = channels[1];
	channelsHue[2] = channelsAnother[2];

	merge(channelsHue, pDocNew->m_MatOpen);

	cvtColor(pDocNew->m_MatOpen, pDocNew->m_MatOpen, COLOR_HLS2BGR);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnLogicMin()
{
	// TODO: Add your command handler code here
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);

	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	int height = pDoc->m_MatOpen.rows;
	int width = pDoc->m_MatOpen.cols;
	int channel = pDoc->m_MatOpen.channels();
	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < channel; c++) {
				pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = min
				(pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c],
					pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c]);
			}
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnLogicMax()
{
	// TODO: Add your command handler code here
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);

	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	int height = pDoc->m_MatOpen.rows;
	int width = pDoc->m_MatOpen.cols;
	int channel = pDoc->m_MatOpen.channels();
	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < channel; c++) {
				pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = max
				(pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c],
					pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c]);
			}
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnLogicPinlight()
{
	// TODO: Add your command handler code here
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);

	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	int height = pDoc->m_MatOpen.rows;
	int width = pDoc->m_MatOpen.cols;
	int channel = pDoc->m_MatOpen.channels();
	float nValue;
	nValue = 0.5;

	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = nValue;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		nValue = DialogSampleOne.m_fXStep;
	}
	else
	{
		return;
	}
	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < channel; c++) {
				if (pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] > 127)
				{
					nValue = 2 * pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] - 255;
					if (nValue > pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c])
					{
						pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = nValue;
					}
					else
					{
						pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c];
					}
				}
				else
				{
					nValue = 2 * pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c];
					if (nValue > pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c])
					{
						pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c];
					}
					else
					{
						pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = nValue;
					}
				}
			}
		}
	}

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnLogicAnd()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());


	bitwise_and(pDoc->m_MatOpen, pDocAnother->m_MatOpen, pDocNew->m_MatOpen);


	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnLogicOr()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());


	bitwise_or(pDoc->m_MatOpen, pDocAnother->m_MatOpen, pDocNew->m_MatOpen);


	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnLogicNot()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());

	bitwise_not(pDoc->m_MatOpen, pDocNew->m_MatOpen);


	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();



}


void CDIPYSView::OnLogicXor()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());


	bitwise_xor(pDoc->m_MatOpen, pDocAnother->m_MatOpen, pDocNew->m_MatOpen);


	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnLogicNand()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());


	bitwise_and(pDoc->m_MatOpen, pDocAnother->m_MatOpen, pDocNew->m_MatOpen);
	bitwise_not(pDocNew->m_MatOpen, pDocNew->m_MatOpen);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnLogicNor()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());


	bitwise_or(pDoc->m_MatOpen, pDocAnother->m_MatOpen, pDocNew->m_MatOpen);
	bitwise_not(pDocNew->m_MatOpen, pDocNew->m_MatOpen);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnLogicCompareand()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());


	int height = pDoc->m_MatOpen.rows;
	int width = pDoc->m_MatOpen.cols;
	int channel = pDoc->m_MatOpen.channels();

	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < channel; c++) {
				if (pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] > pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c])
				{
					pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = 0;
				}
				else
				{
					pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c];
				}
			}
		}
	}

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnLogicCompareor()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());


	int height = pDoc->m_MatOpen.rows;
	int width = pDoc->m_MatOpen.cols;
	int channel = pDoc->m_MatOpen.channels();

	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < channel; c++) {
				if (pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] > pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c])
				{
					pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] + pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c];
				}
				else
				{
					pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c];
				}
			}
		}
	}

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnLogicComparexor()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocAnother = pViewAnother->GetDocument();

	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());


	int height = pDoc->m_MatOpen.rows;
	int width = pDoc->m_MatOpen.cols;
	int channel = pDoc->m_MatOpen.channels();

	for (unsigned y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			for (int c = 0; c < channel; c++) {
				if (pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] > pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c])
				{
					pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c] +
						pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c];
				}
				else
				{
					pDocNew->m_MatOpen.at<cv::Vec3b>(y, x)[c] = pDoc->m_MatOpen.at<cv::Vec3b>(y, x)[c] -
						pDocAnother->m_MatOpen.at<cv::Vec3b>(y, x)[c];
				}
			}
		}
	}

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnGeometryTranslate()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int nXOffset;
	int nYOffset;
	nXOffset = 20;
	nYOffset = 40;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = nXOffset;
	DialogSampleOne.m_fYStep = nYOffset;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		nXOffset = DialogSampleOne.m_fXStep;
		nYOffset = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}

	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	int rows = pDocNew->m_MatOpen.rows;
	int cols = pDocNew->m_MatOpen.cols;
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			int cc = c - nXOffset;
			int rr = r - nYOffset;
			//边界判断
			if (cc >= 0 && rr >= 0 && cc < rows && rr < cols)
			{
				pDocNew->m_MatOpen.at<Vec3b>(r, c) = pDoc->m_MatOpen.ptr<Vec3b>(rr)[cc];
			}
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryTranslatescale()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int height;
	int width;
	height = 20;
	width = 40;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = width;
	DialogSampleOne.m_fYStep = height;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		height = DialogSampleOne.m_fXStep;
		width = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}

	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows + abs(height),
		pDoc->m_MatOpen.cols + abs(width), pDoc->m_MatOpen.type());
	int rows = pDocNew->m_MatOpen.rows;
	int cols = pDocNew->m_MatOpen.cols;
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			int cc = c - width;
			int rr = r - height;
			//边界判断
			if (cc >= 0 && rr >= 0 && cc < width && rr < height)
			{
				pDocNew->m_MatOpen.at<Vec3b>(r, c) = pDoc->m_MatOpen.ptr<Vec3b>(rr)[cc];
			}
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryTranslateaffine()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	int nXOffset;
	int nYOffset;
	nXOffset = 20;
	nYOffset = 40;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = nXOffset;
	DialogSampleOne.m_fYStep = nYOffset;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		nXOffset = DialogSampleOne.m_fXStep;
		nYOffset = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}

	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows + abs(nYOffset),pDoc->m_MatOpen.cols + abs(nXOffset), pDoc->m_MatOpen.type());
	cv::Mat t_mat = cv::Mat::zeros(2, 3, CV_32FC1);
	t_mat.at<float>(0, 0) = 1;
	t_mat.at<float>(0, 2) = nXOffset; //水平平移量  
	t_mat.at<float>(1, 1) = 1;
	t_mat.at<float>(1, 2) = nYOffset; //竖直平移量  

	//根据平移矩阵进行仿射变换  
	cv::warpAffine(pDoc->m_MatOpen, pDocNew->m_MatOpen, t_mat, pDocNew->m_MatOpen.size());
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryScalenearest()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	float fXScale;
	float fYScale;
	fXScale = 2;
	fYScale = 2;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fXScale;
	DialogSampleOne.m_fYStep = fYScale;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fXScale = DialogSampleOne.m_fXStep;
		fYScale = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();

	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows * fYScale,pDoc->m_MatOpen.cols * fXScale, pDoc->m_MatOpen.type());
	resize(pDoc->m_MatOpen, pDocNew->m_MatOpen, pDocNew->m_MatOpen.size(),fXScale, fYScale, INTER_NEAREST);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryScalebilinear()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	float fXScale;
	float fYScale;
	fXScale = 2;
	fYScale = 2;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fXScale;
	DialogSampleOne.m_fYStep = fYScale;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fXScale = DialogSampleOne.m_fXStep;
		fYScale = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();

	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows * fYScale,pDoc->m_MatOpen.cols * fXScale, pDoc->m_MatOpen.type());
	resize(pDoc->m_MatOpen, pDocNew->m_MatOpen, pDocNew->m_MatOpen.size(),fXScale, fYScale, INTER_LINEAR);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryScalebicubic()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	float fXScale;
	float fYScale;
	fXScale = 2;
	fYScale = 2;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fXScale;
	DialogSampleOne.m_fYStep = fYScale;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fXScale = DialogSampleOne.m_fXStep;
		fYScale = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();

	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows * fYScale,
	pDoc->m_MatOpen.cols * fXScale, pDoc->m_MatOpen.type());
	resize(pDoc->m_MatOpen, pDocNew->m_MatOpen, pDocNew->m_MatOpen.size(),
	fXScale, fYScale, INTER_CUBIC);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryScalebilinearexact()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	float fXScale;
	float fYScale;
	fXScale = 2;
	fYScale = 2;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fXScale;
	DialogSampleOne.m_fYStep = fYScale;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fXScale = DialogSampleOne.m_fXStep;
		fYScale = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();

	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows * fYScale,
		pDoc->m_MatOpen.cols * fXScale, pDoc->m_MatOpen.type());
	resize(pDoc->m_MatOpen, pDocNew->m_MatOpen, pDocNew->m_MatOpen.size(),
		fXScale, fYScale, INTER_LINEAR_EXACT);
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryRotate90()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();

	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.cols,
		pDoc->m_MatOpen.rows, pDoc->m_MatOpen.type());
	int height = pDocNew->m_MatOpen.rows;
	int width = pDocNew->m_MatOpen.cols;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			pDocNew->m_MatOpen.at<Vec3b>(i, j) = pDoc->m_MatOpen.ptr<Vec3b>
				(pDoc->m_MatOpen.rows - j - 1)[i];
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryClockwise()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();

	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows,
		pDoc->m_MatOpen.cols, pDoc->m_MatOpen.type());

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryRotate270()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();

	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.cols,
		pDoc->m_MatOpen.rows, pDoc->m_MatOpen.type());
	int height = pDocNew->m_MatOpen.rows;
	int width = pDocNew->m_MatOpen.cols;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			pDocNew->m_MatOpen.at<Vec3b>(i, j) =
				pDoc->m_MatOpen.ptr<Vec3b>(j)[pDoc->m_MatOpen.cols - i - 1];
		}
	}
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryRotate()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc) return;
	float fAngle = 45;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fAngle;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fAngle = DialogSampleOne.m_fXStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows,
		pDoc->m_MatOpen.cols, pDoc->m_MatOpen.type());
	// get the center coordinates of the image to create the 2D rotation matrix
	Point2f center((pDoc->m_MatOpen.cols - 1) / 2.0, (pDoc->m_MatOpen.rows - 1) / 2.0);
	// using getRotationMatrix2D() to get the rotation matrix
	Mat rotation_matix = getRotationMatrix2D(center, fAngle, 1.0);
	// rotate the image using warpAffine
	warpAffine(pDoc->m_MatOpen, pDocNew->m_MatOpen, rotation_matix, pDocNew->m_MatOpen.size());
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryRotatescale()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc) return;
	float fAngle = 45;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fAngle;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fAngle = DialogSampleOne.m_fXStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();

	int h = pDoc->m_MatOpen.rows;
	int w = pDoc->m_MatOpen.cols;

	float fArc = fAngle / 180 * CV_PI;

	int h1 = static_cast<int>(w * fabs(sin(fArc)) + h * fabs(cos(fArc)));
	int w1 = static_cast<int>(w * fabs(cos(fArc)) + h * fabs(sin(fArc)));

	pDocNew->m_MatOpen = Mat::zeros(h1, w1, pDoc->m_MatOpen.type());

	// get the center coordinates of the image to create the 2D rotation matrix
	Point2f center((pDoc->m_MatOpen.cols - 1) / 2.0, (pDoc->m_MatOpen.rows - 1) / 2.0);
	// using getRotationMatrix2D() to get the rotation matrix
	Mat rotation_matix = getRotationMatrix2D(center, fAngle, 1.0);

	rotation_matix.at<double>(0, 2) += (w1 - w) / 2;
	rotation_matix.at<double>(1, 2) += (h1 - h) / 2;
	cv::warpAffine(pDoc->m_MatOpen, pDocNew->m_MatOpen, rotation_matix, pDocNew->m_MatOpen.size());
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryShear()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	float fShearX = 0.3;
	float fShearY = 0.3;

	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fShearX;
	DialogSampleOne.m_fYStep = fShearY;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fShearX = DialogSampleOne.m_fXStep;
		fShearY = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows + pDoc->m_MatOpen.cols * fShearY,
		pDoc->m_MatOpen.cols + pDoc->m_MatOpen.rows * fShearX, pDoc->m_MatOpen.type());

	float warpMatValues5[] = { 1.0, fShearX, 0, fShearY, 1.0, 0 };
	Mat warpMat(2, 3, CV_32F, warpMatValues5);
	warpAffine(pDoc->m_MatOpen, pDocNew->m_MatOpen, warpMat, pDocNew->m_MatOpen.size());

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryAffine()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;


	Point2f src_points[3];
	Point2f dst_points[3];

	src_points[0] = Point2f(0, 0);
	src_points[1] = Point2f(0, (float)(pDoc->m_MatOpen.rows - 1));
	src_points[2] = Point2f((float)(pDoc->m_MatOpen.cols - 1), (float)(pDoc->m_MatOpen.rows - 1));

	dst_points[0] = Point2f((float)(0, 0));
	dst_points[1] = Point2f((float)(pDoc->m_MatOpen.cols - 1) * 0.1, (float)(pDoc->m_MatOpen.rows - 1) * 0.5);
	dst_points[2] = Point2f((float)(pDoc->m_MatOpen.cols - 1) * 0.8, (float)(pDoc->m_MatOpen.rows - 1) * 0.8);
	CMainFrame* pFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows, pDoc->m_MatOpen.cols, pDoc->m_MatOpen.type());


	Mat affine;
	affine = getAffineTransform(src_points, dst_points);

	warpAffine(pDoc->m_MatOpen, pDocNew->m_MatOpen, affine, pDocNew->m_MatOpen.size());
	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryMirror()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	flip(pDoc->m_MatOpen, pDocNew->m_MatOpen, 1);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnGeometryMirrorvertical()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	flip(pDoc->m_MatOpen, pDocNew->m_MatOpen, 0);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnGeometryMirrorcomepletely()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.size(), pDoc->m_MatOpen.type());
	flip(pDoc->m_MatOpen, pDocNew->m_MatOpen, -1);

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();


}


void CDIPYSView::OnGeometryTranspose()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewTranspose = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocTranspose = pViewTranspose->GetDocument();
	pDocTranspose->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.cols, pDoc->m_MatOpen.rows, pDoc->m_MatOpen.type());
	transpose(pDoc->m_MatOpen, pDocTranspose->m_MatOpen);

	pDoc->MatToCImage(pDocTranspose->m_MatOpen, pDocTranspose->m_ImageOpen);
	pViewTranspose->OnInitialUpdate();


}


void CDIPYSView::OnGeometryPerspective()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows,
		pDoc->m_MatOpen.cols, pDoc->m_MatOpen.type());
	Mat Perspective;
	Perspective = getPerspectiveTransform(m_pointsSrc, m_pointsDst);
	warpPerspective(pDoc->m_MatOpen, pDocNew->m_MatOpen, Perspective, pDocNew->m_MatOpen.size());

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryPoints()
{
	m_nStart = 0;

}


void CDIPYSView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC DC(this);
	if (m_nStart < 4)
	{
		m_pointsSrc[m_nStart].x = point.x + GetScrollPosition().x;
		m_pointsSrc[m_nStart].y = point.y + GetScrollPosition().y;
		DC.Ellipse(m_pointsSrc[m_nStart].x - 3, m_pointsSrc[m_nStart].y - 3,
			m_pointsSrc[m_nStart].x + 3, m_pointsSrc[m_nStart].y + 3);
		m_nStart = m_nStart + 1;
	}
	else
	{
		m_pointsDst[m_nStart - 4].x = point.x + GetScrollPosition().x;
		m_pointsDst[m_nStart - 4].y = point.y + GetScrollPosition().y;
		DC.Ellipse(m_pointsDst[m_nStart - 4].x - 3, m_pointsDst[m_nStart - 4].y - 3,
			m_pointsDst[m_nStart - 4].x + 3, m_pointsDst[m_nStart - 4].y + 3);
		m_nStart = m_nStart + 1;
	}

	CScrollView::OnLButtonUp(nFlags, point);
}


void CDIPYSView::OnGeometryTwirl()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	float fAngle;
	fAngle = 45;

	float fArc;
	fArc = float(fAngle * 3.1415927 / 180);
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fAngle;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fAngle = DialogSampleOne.m_fXStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows,
		pDoc->m_MatOpen.cols, pDoc->m_MatOpen.type());
	int nX; int nY;
	COLORREF PixelColor;
	int nXOriginal;
	int nYOriginal;

	int nDx;
	int nDy;

	int nXc;
	int nYc;

	nXc = pDoc->m_MatOpen.cols / 2;
	nYc = pDoc->m_MatOpen.rows / 2;
	int nR;

	int nRMax;

	nRMax = sqrt(float(pDoc->m_MatOpen.cols * pDoc->m_MatOpen.cols
		+ pDoc->m_MatOpen.rows * pDoc->m_MatOpen.rows)) / 2;
	float fBeta;
	for (nY = 0; nY < pDocNew->m_MatOpen.rows; nY++)
	{
		for (nX = 0; nX < pDocNew->m_MatOpen.cols; nX++)
		{
			nDx = nX - nXc;
			nDy = nY - nYc;
			nR = sqrt(float(nDx * nDx + nDy * nDy));
			fBeta = atan2(nDy, nDx * 1.0) + fArc * (nRMax - nR) / nRMax;
			if (nR <= nRMax)
			{
				nXOriginal = int(nXc + nR * cos(fBeta));
			}
			else
			{
				nXOriginal = nX;
			}
			if (nR <= nRMax)
			{
				nYOriginal = int(nYc + nR * sin(fBeta));
			}
			else
			{
				nYOriginal = nY;
			}


			if (nYOriginal < 0)
			{
				continue;
			}
			if ((nXOriginal) < 0)
			{
				continue;
			}
			if (nXOriginal >= pDoc->m_MatOpen.cols)
			{
				continue;
			}
			if (nYOriginal >= pDoc->m_MatOpen.rows)
			{
				continue;
			}

			pDocNew->m_MatOpen.at<Vec3b>(nY, nX) =
				pDoc->m_MatOpen.ptr<Vec3b>(nYOriginal)[nXOriginal];
		}
	}

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryRipple()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	float fAx = 32;
	float fTx = 4;
	float fAy = 16;
	float fTy = 2;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fAx;
	DialogSampleOne.m_fYStep = fTx;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fAx = DialogSampleOne.m_fXStep;
		fTx = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	DialogSampleOne.m_fXStep = fAy;
	DialogSampleOne.m_fYStep = fTy;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fAy = DialogSampleOne.m_fXStep;
		fTy = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	double dAx;
	dAx = pDoc->m_ImageOpen.GetWidth() / fAx;
	double dTx;
	dTx = pDoc->m_ImageOpen.GetWidth() / fTx;

	double dAy;
	dAy = pDoc->m_ImageOpen.GetHeight() / fAy;
	double dTy;
	dTy = pDoc->m_ImageOpen.GetHeight() / fTy;
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows,
		pDoc->m_MatOpen.cols, pDoc->m_MatOpen.type());
	int nX; int nY;
	COLORREF PixelColor;
	int nXOriginal;
	int nYOriginal;
	for (nY = 0; nY < pDocNew->m_MatOpen.rows; nY++)
	{
		for (nX = 0; nX < pDocNew->m_MatOpen.cols; nX++)
		{
			nXOriginal = nX + dAx * sin(2 * 3.1415927 * nY / dTx);
			nYOriginal = nY + dAy * sin(2 * 3.1415927 * nX / dTy);

			if (nYOriginal < 0)
			{
				continue;
			}
			if ((nXOriginal) < 0)
			{
				continue;
			}

			if (nXOriginal >= pDoc->m_MatOpen.cols)
			{
				continue;
			}
			if (nYOriginal >= pDoc->m_MatOpen.rows)
			{
				continue;
			}
			pDocNew->m_MatOpen.at<Vec3b>(nY, nX) =
				pDoc->m_MatOpen.ptr<Vec3b>(nYOriginal)[nXOriginal];
		}
	}

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometrySpherical()
{
	CDIPYSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	float fRadius;
	fRadius = pDoc->m_ImageOpen.GetWidth() / 2;

	float fRefraction;
	fRefraction = 1.8;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fRadius;
	DialogSampleOne.m_fYStep = fRefraction;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRadius = DialogSampleOne.m_fXStep;
		fRefraction = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewNew =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocNew = pViewNew->GetDocument();
	pDocNew->m_MatOpen = Mat::zeros(pDoc->m_MatOpen.rows,
		pDoc->m_MatOpen.cols, pDoc->m_MatOpen.type());
	int nX; int nY;
	COLORREF PixelColor;
	int nXOriginal;
	int nYOriginal;

	int nDx;
	int nDy;

	int nXc;
	int nYc;

	nXc = pDoc->m_MatOpen.cols / 2;
	nYc = pDoc->m_MatOpen.rows / 2;

	int nR;

	int nRMax;

	nRMax = pDoc->m_MatOpen.cols / 2;

	double dRo;
	dRo = 1.8;

	float fBetaX;
	float fBetaY;

	double dZ;

	for (nY = 0; nY < pDoc->m_MatOpen.rows; nY++)
	{
		for (nX = 0; nX < pDocNew->m_MatOpen.cols; nX++)
		{
			nDx = nX - nXc;
			nDy = nY - nYc;
			nR = sqrt(float(nDx * nDx + nDy * nDy));
			dZ = sqrt(float(nRMax * nRMax - nR * nR));


			fBetaX = (1 - 1 / dRo) * asin(nDx * 1.0 / sqrt(float(nDx * nDx + dZ * dZ)));
			fBetaY = (1 - 1 / dRo) * asin(nDy * 1.0 / sqrt(float(nDy * nDy + dZ * dZ)));

			if (nR <= nRMax)
			{
				nXOriginal = int(nX - dZ * tan(fBetaX));
			}
			else
			{
				nXOriginal = nX;
			}

			if (nR <= nRMax)
			{
				nYOriginal = int(nY - dZ * tan(fBetaY));
			}
			else
			{
				nYOriginal = nY;
			}

			if (nYOriginal < 0)
			{
				continue;
			}
			if ((nXOriginal) < 0)
			{
				continue;
			}

			if (nXOriginal >= pDoc->m_MatOpen.cols)
			{
				continue;
			}
			if (nYOriginal >= pDoc->m_MatOpen.rows)
			{
				continue;
			}
			pDocNew->m_MatOpen.at<Vec3b>(nY, nX) =
				pDoc->m_MatOpen.ptr<Vec3b>(nYOriginal)[nXOriginal];
		}
	}

	pDoc->MatToCImage(pDocNew->m_MatOpen, pDocNew->m_ImageOpen);
	pViewNew->OnInitialUpdate();

}


void CDIPYSView::OnGeometryStitch()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_OPEN);
	CDIPYSView* pViewInAnother = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocInAnother = pViewInAnother->GetDocument();
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	vector<Mat>images;
	images.push_back(pDocIn->m_MatOpen);
	images.push_back(pDocInAnother->m_MatOpen);

	Ptr<Stitcher>stitcher = Stitcher::create();

	Stitcher::Status status = stitcher->stitch(images, pDocOut->m_MatOpen);

	if (status != Stitcher::OK)
		return;
	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();

}


void CDIPYSView::OnPointBrightnessmat()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	int nRAdd;
	int nGAdd;
	int nBAdd;

	nRAdd = 20;
	nGAdd = 40;
	nBAdd = 60;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = nRAdd;
	DialogSampleOne.m_fYStep = nGAdd;
	DialogSampleOne.m_fZ = nBAdd;

	if (DialogSampleOne.DoModal() == IDOK)
	{
		nRAdd = DialogSampleOne.m_fXStep;
		nGAdd = DialogSampleOne.m_fYStep;
		nBAdd = DialogSampleOne.m_fZ;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),pDocIn->m_MatOpen.type());
	Mat black = Mat::zeros(pDocIn->m_MatOpen.size(), pDocIn->m_MatOpen.type());
	black = Scalar(nBAdd, nGAdd, nRAdd);
	add(pDocIn->m_MatOpen, black, pDocOut->m_MatOpen);
	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();

}


void CDIPYSView::OnPointBrightness()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	int nRAdd;
	int nGAdd;
	int nBAdd;

	nRAdd = 20;
	nGAdd = 40;
	nBAdd = 60;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = nRAdd;
	DialogSampleOne.m_fYStep = nGAdd;
	DialogSampleOne.m_fZ = nBAdd;

	if (DialogSampleOne.DoModal() == IDOK)
	{
		nRAdd = DialogSampleOne.m_fXStep;
		nGAdd = DialogSampleOne.m_fYStep;
		nBAdd = DialogSampleOne.m_fZ;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	int height = pDocOut->m_MatOpen.rows;//图片的长度
	int width = pDocOut->m_MatOpen.cols;//图片的宽度
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (pDocOut->m_MatOpen.channels() == 3)
			{
				int b = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
				int g = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
				int r = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];

				pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b + nBAdd);
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g + nGAdd);
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r + nRAdd);
			}
			else if (pDocOut->m_MatOpen.channels() == 1)
			{
				float v = pDocIn->m_MatOpen.at<uchar>(row, col);
				pDocOut->m_MatOpen.at<uchar>(row, col) = saturate_cast<uchar>(v + nBAdd);
			}
		}
	}
	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();

}


void CDIPYSView::OnPointContrastmat()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	float fRMultiply;
	float fGMultiply;
	float fBMultiply;

	fRMultiply = 0.5;
	fGMultiply = 1;
	fBMultiply = 2;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fRMultiply;
	DialogSampleOne.m_fYStep = fGMultiply;
	DialogSampleOne.m_fZ = fBMultiply;

	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRMultiply = DialogSampleOne.m_fXStep;
		fGMultiply = DialogSampleOne.m_fYStep;
		fBMultiply = DialogSampleOne.m_fZ;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	Mat black = Mat::zeros(pDocIn->m_MatOpen.size(), pDocIn->m_MatOpen.type());
	black = Scalar(fBMultiply, fGMultiply, fRMultiply);
	pDocOut->m_MatOpen = pDocIn->m_MatOpen.mul(black);
	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();
}


void CDIPYSView::OnPointContrast()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	float fRMultiply;
	float fGMultiply;
	float fBMultiply;

	fRMultiply = 0.5;
	fGMultiply = 1;
	fBMultiply = 2;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fRMultiply;
	DialogSampleOne.m_fYStep = fGMultiply;
	DialogSampleOne.m_fZ = fBMultiply;

	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRMultiply = DialogSampleOne.m_fXStep;
		fGMultiply = DialogSampleOne.m_fYStep;
		fBMultiply = DialogSampleOne.m_fZ;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	int height = pDocOut->m_MatOpen.rows;
	int width = pDocOut->m_MatOpen.cols;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (pDocOut->m_MatOpen.channels() == 3)
			{
				int b = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
				int g = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
				int r = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];

				pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b * fBMultiply);
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g * fGMultiply);
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r * fRMultiply);
			}

			else if (pDocOut->m_MatOpen.channels() == 1)
			{
				float v = pDocIn->m_MatOpen.at<uchar>(row, col);
				pDocOut->m_MatOpen.at<uchar>(row, col) =
					saturate_cast<uchar>(v * fRMultiply);
			}
		}
	}
	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();

}


void CDIPYSView::OnPointAutocontrast()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	int nALowRed = 255;
	int nAHighRed = 0;

	int nALowGreen = 255;
	int nAHighGreen = 0;

	int nALowBlue = 255;
	int nAHighBlue = 0;
	int nAMinRed = 0;
	int nAMaxRed = 255;

	int nAMinGreen = 0;
	int nAMaxGreen = 255;

	int nAMinBlue = 0;
	int nAMaxBlue = 255;

	int col; int row;
	int nROne; int nGOne; int nBOne;
	for (row = 0; row < pDocIn->m_MatOpen.rows; row++)
	{
		for (col = 0; col < pDocIn->m_MatOpen.cols; col++)
		{
			nROne = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];
			if (nROne < nALowRed)
			{
				nALowRed = nROne;
			}
			if (nROne > nAHighRed)
			{
				nAHighRed = nROne;
			}

			nGOne = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
			if (nGOne < nALowGreen)
			{
				nALowGreen = nGOne;
			}
			if (nGOne > nAHighGreen)
			{
				nAHighGreen = nGOne;
			}
			nBOne = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
			if (nBOne < nALowBlue)
			{
				nALowBlue = nBOne;
			}
			if (nBOne > nAHighBlue)
			{
				nAHighBlue = nBOne;
			}
		}
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();

	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	for (row = 0; row < pDocOut->m_MatOpen.rows; row++)
	{
		for (col = 0; col < pDocOut ->m_MatOpen.cols; col++)
		{

			nROne = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];
			nROne = int(nAMinRed + (nROne - nALowRed) * (nAMaxRed - nAMinRed) * 1.0 / (nAHighRed - nALowRed));

			nGOne = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
			nGOne = int(nAMinGreen + (nGOne - nALowGreen) * (nAMaxGreen - nAMinGreen) * 1.0 / (nAHighGreen - nALowGreen));

			nBOne = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
			nBOne = int(nAMinBlue + (nBOne - nALowBlue) * (nAMaxBlue - nAMinBlue) * 1.0 / (nAHighBlue - nALowBlue));

			pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(nBOne);
			pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(nGOne);
			pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(nROne);
		}
	}
	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();

}


void CDIPYSView::OnPointGlobalmat()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	float fRAlpha;
	float fRBeta;
	fRAlpha = 2;
	fRBeta = 50;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fRAlpha;
	DialogSampleOne.m_fYStep = fRBeta;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRAlpha = DialogSampleOne.m_fXStep;
		fRBeta = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}

	float fGAlpha;
	float fGBeta;
	fGAlpha = 2;
	fGBeta = 50;
	DialogSampleOne.m_fXStep = fGAlpha;
	DialogSampleOne.m_fYStep = fGBeta;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fGAlpha = DialogSampleOne.m_fXStep;
		fGBeta = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	float fBAlpha;
	float fBBeta;
	fBAlpha = 2;
	fBBeta = 50;
	DialogSampleOne.m_fXStep = fBAlpha;
	DialogSampleOne.m_fYStep = fBBeta;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fBAlpha = DialogSampleOne.m_fXStep;
		fBBeta = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	Mat black = Mat::zeros(pDocIn->m_MatOpen.size(), pDocIn->m_MatOpen.type());
	black = Scalar(fBAlpha, fGAlpha, fRAlpha);
	pDocOut->m_MatOpen = pDocIn->m_MatOpen.mul(black);

	black = Scalar(fBBeta, fGBeta, fRBeta);
	add(pDocOut->m_MatOpen, black, pDocOut->m_MatOpen);
	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();

}


void CDIPYSView::OnPointGlobal()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;

	float fRAlpha;
	float fRBeta;
	fRAlpha = 2;
	fRBeta = 50;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fRAlpha;
	DialogSampleOne.m_fYStep = fRBeta;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRAlpha = DialogSampleOne.m_fXStep;
		fRBeta = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}

	float fGAlpha;
	float fGBeta;
	fGAlpha = 2;
	fGBeta = 50;
	DialogSampleOne.m_fXStep = fGAlpha;
	DialogSampleOne.m_fYStep = fGBeta;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fGAlpha = DialogSampleOne.m_fXStep;
		fGBeta = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}

	float fBAlpha;
	float fBBeta;
	fBAlpha = 2;
	fBBeta = 50;
	DialogSampleOne.m_fXStep = fBAlpha;
	DialogSampleOne.m_fYStep = fBBeta;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fBAlpha = DialogSampleOne.m_fXStep;
		fBBeta = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());

	int height = pDocOut->m_MatOpen.rows;
	int width = pDocOut->m_MatOpen.cols;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (pDocOut->m_MatOpen.channels() == 3)
			{
				int b = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
				int g = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
				int r = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];

				pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b * fBAlpha + fBBeta);
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g * fGAlpha + fGBeta);
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r * fRAlpha + fRBeta);
			}
			else if (pDocOut->m_MatOpen.channels() == 1)
			{
				float v = pDocIn->m_MatOpen.at<uchar>(row, col);
				pDocOut->m_MatOpen.at<uchar>(row, col) = saturate_cast<uchar>(v * fRAlpha + fRBeta);
			}
		}
	}

	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();
}


void CDIPYSView::OnPointLocal()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	//red channel
	float fRLow;
	float fRHigh;
	fRLow = 50;
	fRHigh = 200;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fRLow;
	DialogSampleOne.m_fYStep = fRHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRLow = DialogSampleOne.m_fXStep;
		fRHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	float fRAlpha;
	float fRBeta;
	fRAlpha = 2;
	fRBeta = 50;
	DialogSampleOne.m_fXStep = fRAlpha;
	DialogSampleOne.m_fYStep = fRBeta;

	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRAlpha = DialogSampleOne.m_fXStep;
		fRBeta = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	//green channel
	float fGLow;
	float fGHigh;
	fGLow = 50;
	fGHigh = 200;
	DialogSampleOne.m_fXStep = fGLow;
	DialogSampleOne.m_fYStep = fGHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fGLow = DialogSampleOne.m_fXStep;
		fGHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}

	float fGAlpha;
	float fGBeta;
	fGAlpha = 2;
	fGBeta = 50;
	DialogSampleOne.m_fXStep = fGAlpha;
	DialogSampleOne.m_fYStep = fGBeta;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fGAlpha = DialogSampleOne.m_fXStep;
		fGBeta = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	//blue channel
	float fBLow;
	float fBHigh;
	fBLow = 50;
	fBHigh = 200;
	DialogSampleOne.m_fXStep = fBLow;
	DialogSampleOne.m_fYStep = fBHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fBLow = DialogSampleOne.m_fXStep;
		fBHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	float fBAlpha;
	float fBBeta;
	fBAlpha = 2;
	fBBeta = 50;
	DialogSampleOne.m_fXStep = fBAlpha;
	DialogSampleOne.m_fYStep = fBBeta;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fBAlpha = DialogSampleOne.m_fXStep;
		fBBeta = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	int height = pDocOut->m_MatOpen.rows;
	int width = pDocOut->m_MatOpen.cols;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (pDocOut->m_MatOpen.channels() == 3)
			{
				int b = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
				int g = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
				int r = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];
				//blue channel
				if (b < fBLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = 0;
				}
				if (b > fBHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = 255;
				}
				if ((b >= fBLow) && (b <= fBHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b * fBAlpha + fBBeta);
				}
				//green channel
				if (g < fGLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = 0;
				}
				if (b > fGHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = 255;
				}
				if ((b >= fGLow) && (b <= fGHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g * fGAlpha + fGBeta);
				}
				//red channel
				if (r < fRLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = 0;
				}
				if (r > fRHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = 255;
				}
				if ((r >= fRLow) && (r <= fRHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r * fRAlpha + fRBeta);
				}
			}
			else if (pDocOut->m_MatOpen.channels() == 1)
			{
				float v = pDocIn->m_MatOpen.at<uchar>(row, col);
				if (v < fRLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = 0;
				}
				if (v > fRHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = 255;
				}
				if ((v >= fRLow) && (v <= fRHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(v * fRAlpha + fRBeta);
				}
			}
		}
	}
	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();

}


void CDIPYSView::OnPointPiecewise()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	//red channel
	float fRLow;
	float fRHigh;
	fRLow = 50;
	fRHigh = 200;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fRLow;
	DialogSampleOne.m_fYStep = fRHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRLow = DialogSampleOne.m_fXStep;
		fRHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	float fRAlphaLow;
	float fRBetaLow;
	fRAlphaLow = 0.5;
	fRBetaLow = 20;
	DialogSampleOne.m_fXStep = fRAlphaLow;
	DialogSampleOne.m_fYStep = fRBetaLow;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRAlphaLow = DialogSampleOne.m_fXStep;
		fRBetaLow = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	float fRAlpha;
	float fRBeta;
	fRAlpha = 2;
	fRBeta = 50;
	DialogSampleOne.m_fXStep = fRAlpha;
	DialogSampleOne.m_fYStep = fRBeta;

	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRAlpha = DialogSampleOne.m_fXStep;
		fRBeta = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	float fRAlphaHigh;
	float fRBetaHigh;
	fRAlphaHigh = 3;
	fRBetaHigh = -50;
	DialogSampleOne.m_fXStep = fRAlphaHigh;
	DialogSampleOne.m_fYStep = fRBetaHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRAlphaHigh = DialogSampleOne.m_fXStep;
		fRBetaHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	//green channel
	float fGLow;
	float fGHigh;
	fGLow = 50;
	fGHigh = 200;
	DialogSampleOne.m_fXStep = fGLow;
	DialogSampleOne.m_fYStep = fGHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fGLow = DialogSampleOne.m_fXStep;
		fGHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}

	float fGAlphaLow;
	float fGBetaLow;
	fGAlphaLow = 0.5;
	fGBetaLow = 20;
	DialogSampleOne.m_fXStep = fGAlphaLow;
	DialogSampleOne.m_fYStep = fGBetaLow;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fGAlphaLow = DialogSampleOne.m_fXStep;
		fGBetaLow = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	float fGAlpha;
	float fGBeta;
	fGAlpha = 2;
	fGBeta = 50;
	DialogSampleOne.m_fXStep = fGAlpha;
	DialogSampleOne.m_fYStep = fGBeta;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fGAlpha = DialogSampleOne.m_fXStep;
		fGBeta = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	float fGAlphaHigh;
	float fGBetaHigh;
	fGAlphaHigh = 3;
	fGBetaHigh = -50;
	DialogSampleOne.m_fXStep = fGAlphaHigh;
	DialogSampleOne.m_fYStep = fGBetaHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fGAlphaHigh = DialogSampleOne.m_fXStep;
		fGBetaHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	//blue channel
	float fBLow;
	float fBHigh;
	fBLow = 50;
	fBHigh = 200;
	DialogSampleOne.m_fXStep = fBLow;
	DialogSampleOne.m_fYStep = fBHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fBLow = DialogSampleOne.m_fXStep;
		fBHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	float fBAlphaLow;
	float fBBetaLow;
	fBAlphaLow = 0.5;
	fBBetaLow = -20;
	DialogSampleOne.m_fXStep = fBAlphaLow;
	DialogSampleOne.m_fYStep = fBBetaLow;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fBAlphaLow = DialogSampleOne.m_fXStep;
		fBBetaLow = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	float fBAlpha;
	float fBBeta;
	fBAlpha = 2;
	fBBeta = 50;
	DialogSampleOne.m_fXStep = fBAlpha;
	DialogSampleOne.m_fYStep = fBBeta;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fBAlpha = DialogSampleOne.m_fXStep;
		fBBeta = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	float fBAlphaHigh;
	float fBBetaHigh;
	fBAlphaHigh = 3;
	fBBetaHigh = -50;
	DialogSampleOne.m_fXStep = fBAlphaHigh;
	DialogSampleOne.m_fYStep = fBBetaHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fBAlphaHigh = DialogSampleOne.m_fXStep;
		fBBetaHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	int height = pDocOut->m_MatOpen.rows;
	int width = pDocOut->m_MatOpen.cols;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (pDocOut->m_MatOpen.channels() == 3)
			{
				int b = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
				int g = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
				int r = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];
				//blue channel
				if (b < fBLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b * fBAlphaLow + fBBetaLow);
				}
				if (b > fBHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b * fBAlphaHigh + fBBetaHigh);
				}
				if ((b >= fBLow) && (b <= fBHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b * fBAlpha + fBBeta);
				}
				//green channel
				if (g < fGLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g * fGAlphaLow + fGBetaLow);
				}
				if (g > fGHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g * fGAlphaHigh + fGBetaHigh);
				}

				if ((g >= fGLow) && (g <= fGHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g * fGAlpha + fGBeta);
				}
				//red channel
				if (r < fRLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r * fRAlphaLow + fRBetaLow);
				}
				if (r > fRHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r * fRAlphaHigh + fRBetaHigh);
				}
				if ((r >= fRLow) && (r <= fRHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r * fRAlpha + fRBeta);
				}
			}
			else if (pDocOut->m_MatOpen.channels() == 1)
			{
				float v = pDocIn->m_MatOpen.at<uchar>(row, col);
				if (v < fRLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(v * fRAlphaLow + fRBetaLow);
				}
				if (v > fRHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(v * fRAlphaHigh + fRBetaHigh);
				}
				if ((v >= fRLow) && (v <= fRHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(v * fRAlpha + fRBeta);
				}
			}
		}
	}
	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();

}


void CDIPYSView::OnPointLogarithmic()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	int height = pDocOut->m_MatOpen.rows;
	int width = pDocOut->m_MatOpen.cols;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (pDocOut->m_MatOpen.channels() == 3)
			{
				int b = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
				int g = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
				int r = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];

				pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = log((double)b + 1);
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = log((double)g + 1);
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = log((double)r + 1);
			}
			else if (pDocOut->m_MatOpen.channels() == 1)
			{
				float v = pDocIn->m_MatOpen.at<uchar>(row, col);
				pDocOut->m_MatOpen.at<uchar>(row, col) = log((double)v + 1);
			}
		}
	}
	normalize(pDocOut->m_MatOpen, pDocOut->m_MatOpen, 0, 255, NORM_MINMAX);
	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();

}


void CDIPYSView::OnPointExponent()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	float fRSubtract;
	float fGSubtract;
	float fBSubtract;

	fRSubtract = 0.001;
	fGSubtract = 0.001;
	fBSubtract = 0.001;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fRSubtract;
	DialogSampleOne.m_fYStep = fGSubtract;
	DialogSampleOne.m_fZ = fBSubtract;

	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRSubtract = DialogSampleOne.m_fXStep;
		fGSubtract = DialogSampleOne.m_fYStep;
		fBSubtract = DialogSampleOne.m_fZ;
	}
	else
	{
		return;
	}
	float fRMultiply;
	float fGMultiply;
	float fBMultiply;

	fRMultiply = 1.0;
	fGMultiply = 1.0;
	fBMultiply = 1.0;
	DialogSampleOne.m_fXStep = fRMultiply;
	DialogSampleOne.m_fYStep = fGMultiply;
	DialogSampleOne.m_fZ = fBMultiply;

	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRMultiply = DialogSampleOne.m_fXStep;
		fGMultiply = DialogSampleOne.m_fYStep;
		fBMultiply = DialogSampleOne.m_fZ;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	int height = pDocOut->m_MatOpen.rows;
	int width = pDocOut->m_MatOpen.cols;
	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (pDocOut->m_MatOpen.channels() == 3)
			{
				int b = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
				int g = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
				int r = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];

				pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = expf((b / 255.0 - fBSubtract) * fBMultiply) - 1;
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = expf((g / 255.0 - fGSubtract) * fGMultiply) - 1;
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = expf((r / 255.0 - fRSubtract) * fRMultiply) - 1;
			}
			else if (pDocOut->m_MatOpen.channels() == 1)
			{
				float v = pDocIn->m_MatOpen.at<uchar>(row, col);
				pDocOut->m_MatOpen.at<uchar>(row, col) = expf(((double)v / 255.0 - fRMultiply) * fRMultiply) - 1;
			}
		}
	}
	normalize(pDocOut->m_MatOpen, pDocOut->m_MatOpen, 0, 255, NORM_MINMAX);

	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();

}


void CDIPYSView::OnPointPower()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;

	float fRSubtract;
	float fGSubtract;
	float fBSubtract;

	fRSubtract = 0.001;
	fGSubtract = 0.001;
	fBSubtract = 0.001;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fRSubtract;
	DialogSampleOne.m_fYStep = fGSubtract;
	DialogSampleOne.m_fZ = fBSubtract;

	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRSubtract = DialogSampleOne.m_fXStep;
		fGSubtract = DialogSampleOne.m_fYStep;
		fBSubtract = DialogSampleOne.m_fZ;
	}
	else
	{
		return;
	}
	float fRMultiply;
	float fGMultiply;
	float fBMultiply;

	fRMultiply = 255;
	fGMultiply = 255;
	fBMultiply = 255;
	DialogSampleOne.m_fXStep = fRMultiply;
	DialogSampleOne.m_fYStep = fGMultiply;
	DialogSampleOne.m_fZ = fBMultiply;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRMultiply = DialogSampleOne.m_fXStep;
		fGMultiply = DialogSampleOne.m_fYStep;
		fBMultiply = DialogSampleOne.m_fZ;
	}
	else
	{
		return;
	}
	float fRPower;
	float fGPower;
	float fBPower;

	fRPower = 0.5;
	fGPower = 0.5;
	fBPower = 0.5;
	DialogSampleOne.m_fXStep = fRPower;
	DialogSampleOne.m_fYStep = fGPower;
	DialogSampleOne.m_fZ = fBPower;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRPower = DialogSampleOne.m_fXStep;
		fGPower = DialogSampleOne.m_fYStep;
		fBPower = DialogSampleOne.m_fZ;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	int height = pDocOut->m_MatOpen.rows;
	int width = pDocOut->m_MatOpen.cols;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (pDocOut->m_MatOpen.channels() == 3)
			{
				int b = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
				int g = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
				int r = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = fBMultiply * powf((b / 255.0 + fBSubtract), fBPower);
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = fGMultiply * powf((g / 255.0 + fGSubtract), fGPower);
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = fRMultiply * powf((r / 255.0 + fRSubtract), fRPower);
			}
			else if (pDocOut->m_MatOpen.channels() == 1)
			{
				float v = pDocIn->m_MatOpen.at<uchar>(row, col);
				pDocOut->m_MatOpen.at<uchar>(row, col) = fRMultiply * powf((v / 255.0 + fRSubtract), fRPower);
			}
		}
	}
	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();

}


void CDIPYSView::OnPointBlackwhite()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	float fRLow;
	float fRHigh;
	fRLow = 50;
	fRHigh = 200;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = fRLow;
	DialogSampleOne.m_fYStep = fRHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRLow = DialogSampleOne.m_fXStep;
		fRHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	//green channel
	float fGLow;
	float fGHigh;
	fGLow = 50;
	fGHigh = 200;
	DialogSampleOne.m_fXStep = fGLow;
	DialogSampleOne.m_fYStep = fGHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fGLow = DialogSampleOne.m_fXStep;
		fGHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	//blue channel
	float fBLow;
	float fBHigh;
	fBLow = 50;
	fBHigh = 200;
	DialogSampleOne.m_fXStep = fBLow;
	DialogSampleOne.m_fYStep = fBHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fBLow = DialogSampleOne.m_fXStep;
		fBHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	int height = pDocOut->m_MatOpen.rows;
	int width = pDocOut->m_MatOpen.cols;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (pDocOut->m_MatOpen.channels() == 3)
			{

				int b = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
				int g = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
				int r = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];
				//blue channel
				if (b < fBLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = 0;
				}
				if (b > fBHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = 0;
				}
				if ((b >= fBLow) && (b <= fBHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = 255;
				}
				//green channel
				if (g < fGLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = 0;
				}
				if (g > fGHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = 0;
				}
				if ((g >= fGLow) && (g <= fGHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = 255;
				}
				//red channel
				if (r < fRLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = 0;
				}
				if (r > fRHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = 0;
				}
				if ((r >= fRLow) && (r <= fRHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = 255;
				}
				else if (pDocOut->m_MatOpen.channels() == 1)
				{
					float v = pDocIn->m_MatOpen.at<uchar>(row, col);
					if (v < fRLow)
					{
						pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = 0;
					}
					if (v > fRHigh)
					{
						pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = 0;
					}

					if ((v >= fRLow) && (v <= fRHigh))
					{
						pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = 255;
					}
				}
			}
		}
		pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
		pViewOut->OnInitialUpdate();
	}

}


void CDIPYSView::OnPointPreserve()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;
	CDialogSample DialogSampleOne;
	float fRLow;
	float fRHigh;
	fRLow = 50;
	fRHigh = 200;
	DialogSampleOne.m_fXStep = fRLow;
	DialogSampleOne.m_fYStep = fRHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fRLow = DialogSampleOne.m_fXStep;
		fRHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	//green channel
	float fGLow;
	float fGHigh;
	fGLow = 50;
	fGHigh = 200;
	DialogSampleOne.m_fXStep = fGLow;
	DialogSampleOne.m_fYStep = fGHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fGLow = DialogSampleOne.m_fXStep;
		fGHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	//blue channel
	float fBLow;
	float fBHigh;
	fBLow = 50;
	fBHigh = 200;
	DialogSampleOne.m_fXStep = fBLow;
	DialogSampleOne.m_fYStep = fBHigh;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		fBLow = DialogSampleOne.m_fXStep;
		fBHigh = DialogSampleOne.m_fYStep;
	}
	else
	{
		return;
	}
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	int height = pDocOut->m_MatOpen.rows;
	int width = pDocOut->m_MatOpen.cols;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (pDocOut->m_MatOpen.channels() == 3)
			{

				int b = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
				int g = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
				int r = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];
				//blue channel
				if (b < fBLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = b;
				}
				if (b > fBHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = b;
				}
				if ((b >= fBLow) && (b <= fBHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = 255;
				}
				//green channel
				if (g < fGLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = g;
				}
				if (g > fGHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = g;
				}
				if ((g >= fGLow) && (g <= fGHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = 255;
				}
				//red channel
				if (r < fRLow)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = r;
				}
				if (r > fRHigh)
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = r;
				}
				if ((r >= fRLow) && (r <= fRHigh))
				{
					pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = 255;
				}
				else if (pDocOut->m_MatOpen.channels() == 1)
				{
					float v = pDocIn->m_MatOpen.at<uchar>(row, col);
					if (v < fRLow)
					{
						pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = v;
					}
					if (v > fRHigh)
					{
						pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = v;
					}

					if ((v >= fRLow) && (v <= fRHigh))
					{
						pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = 255;
					}
				}
			}
		}
		pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
		pViewOut->OnInitialUpdate();
	}
}


void CDIPYSView::OnPointBit()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;

	int nBit;
	nBit = 7;
	CDialogSample DialogSampleOne;
	DialogSampleOne.m_fXStep = nBit;
	if (DialogSampleOne.DoModal() == IDOK)
	{
		nBit = DialogSampleOne.m_fXStep;
	}
	else
	{
		return;
	}
	byte nMask;
	nMask = 256 / powf(2, (8 - nBit));
	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut =
		(CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();
	pDocOut->m_MatOpen = Mat::zeros(pDocIn->m_MatOpen.size(),
		pDocIn->m_MatOpen.type());
	int height = pDocOut->m_MatOpen.rows;
	int width = pDocOut->m_MatOpen.cols;

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
		{
			if (pDocOut->m_MatOpen.channels() == 3)
			{
				int b = pDocIn->m_MatOpen.at<Vec3b>(row, col)[0];
				int g = pDocIn->m_MatOpen.at<Vec3b>(row, col)[1];
				int r = pDocIn->m_MatOpen.at<Vec3b>(row, col)[2];
				b = b & nMask;
				g = g & nMask;
				r = r & nMask;
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = b;
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[1] = g;
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[2] = r;
			}
			else if (pDocOut->m_MatOpen.channels() == 1)
			{
				int v = pDocIn->m_MatOpen.at<uchar>(row, col);
				v = v & nMask;
				pDocOut->m_MatOpen.at<Vec3b>(row, col)[0] = v;
			}
		}
	}
	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();

}


void CDIPYSView::OnPointAutocontrastmat()
{
	CDIPYSDoc* pDocIn = GetDocument();
	ASSERT_VALID(pDocIn);
	if (!pDocIn)
		return;

	// Split the input Mat into channels
	std::vector<Mat> channels;
	split(pDocIn->m_MatOpen, channels);

	// Apply the AutoContrast operation to each channel
	for (int i = 0; i < channels.size(); ++i)
	{
		// Find the min and max values for the channel
		double minVal, maxVal;
		minMaxLoc(channels[i], &minVal, &maxVal);

		// Scale and shift values for the channel
		channels[i] = (channels[i] - minVal) * (255.0 / (maxVal - minVal));
	}

	// Merge the channels back into a 3-channel Mat
	Mat resultMat;
	merge(channels, resultMat);

	// Convert the resultMat to unsigned char
	resultMat.convertTo(resultMat, CV_8U);

	CMainFrame* pFrame = (CMainFrame*)(AfxGetApp()->m_pMainWnd);
	pFrame->SendMessage(WM_COMMAND, ID_FILE_NEW);
	CDIPYSView* pViewOut = (CDIPYSView*)pFrame->MDIGetActive()->GetActiveView();
	CDIPYSDoc* pDocOut = pViewOut->GetDocument();

	// Copy the resultMat to the output document's Mat
	pDocOut->m_MatOpen = resultMat.clone();

	pDocIn->MatToCImage(pDocOut->m_MatOpen, pDocOut->m_ImageOpen);
	pViewOut->OnInitialUpdate();
}
