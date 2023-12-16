
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
