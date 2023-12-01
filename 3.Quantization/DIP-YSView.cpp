
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


	int width = pDocNew->m_MatOpen.rows;//图片的长度
	int height = pDocNew->m_MatOpen.cols;//图片的宽度
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
