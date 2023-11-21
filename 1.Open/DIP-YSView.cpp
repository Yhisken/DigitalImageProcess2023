
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


// CDIPYSView

IMPLEMENT_DYNCREATE(CDIPYSView, CScrollView)

BEGIN_MESSAGE_MAP(CDIPYSView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDIPYSView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
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
