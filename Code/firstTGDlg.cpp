// firstTGDlg.cpp : implementation file
//

#include "stdafx.h"
#include "firstTG.h"
#include "firstTGDlg.h"
#include "thinkgear.h"
#include "ADOConn.h"
#include "mscomm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//CFirstTGApp theApp1;
    CMSComm m_ComPort;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFirstTGDlg dialog

CFirstTGDlg::CFirstTGDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFirstTGDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFirstTGDlg)
	m_listN = _T("");
	m_showType = _T("");
	m_CStoCH = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFirstTGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFirstTGDlg)
	DDX_Control(pDX, IDC_COMBO7, m_COM);
	DDX_Control(pDX, IDC_COMBO6, m_stop);
	DDX_Control(pDX, IDC_COMBO5, m_data);
	DDX_Control(pDX, IDC_COMBO4, m_rate);
	DDX_Control(pDX, IDC_RECT1, m_Rect1);
	DDX_Control(pDX, IDC_RECT, m_RECT);
	DDX_Control(pDX, IDC_SLIDER3, m_slider3);
	DDX_Control(pDX, IDC_SLIDER2, m_slider2);
	DDX_Control(pDX, IDC_SLIDER1, m_slider1);
	DDX_Control(pDX, IDC_COMBO3, m_find);
	DDX_Control(pDX, IDC_COMBO1, m_TGDataT);
	DDX_Control(pDX, IDC_COMBO2, m_TGName);
	DDX_Control(pDX, IDC_ADODC1, m_adodc);
	DDX_Control(pDX, IDC_DATAGRID1, m_grid);
	DDX_Text(pDX, IDC_EDIT1, m_listN);
	DDX_Text(pDX, IDC_EDIT2, m_showType);
	DDX_Control(pDX, IDC_MSCOMM1, m_commCtrl);
	DDX_Text(pDX, IDC_EDIT3, m_CStoCH);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFirstTGDlg, CDialog)
	//{{AFX_MSG_MAP(CFirstTGDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, Onconnect)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, OnStop)
	ON_BN_CLICKED(IDC_BUTTON3, OnDelete)
	ON_BN_CLICKED(IDC_BUTTON4, OnChack)
	ON_BN_CLICKED(IDC_BUTTON5, OnSetDataT)
	ON_BN_CLICKED(IDC_BUTTON6, OnShow)
	ON_BN_CLICKED(IDC_BUTTON7, OnShowWave)
	ON_BN_CLICKED(IDC_BUTTON8, OnSetCOM)
	ON_BN_CLICKED(IDC_BUTTON9, OnCommSend)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFirstTGDlg message handlers

BOOL CFirstTGDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
    m_comPortName = NULL;
    m_dllVersion = 0;
    m_connectionId = 0;
    m_packetsRead = 0;
    m_errCode = 0;
    m_count=0;
    m_clean=10;
    m_LMR='0';
    m_SP=0;
	m_comp=1;
	m_Save='7';
    for(int i=2;i<=12;i++)
	{
	    m_DataType[i]=i;
	    m_sigleValue[i]=0;
		m_siv[i]=0;
	}
	m_DataType[0]=4;
    m_DataType[13]=37;
	m_inc=0;
	m_incpoint=0;
	m_oldsigle=0;
	m_bul=1;
    m_showBu=0;
    m_start=1;
	m_break=1;
	m_rep1=0;
	m_rep2=0;

	m_TGName.InsertString(0,"TG_DATA_ATTENTION");
	m_TGName.InsertString(1,"TG_DATA_MEDITATION");

	m_TGDataT.InsertString(0,"TG_DATA_BATTERY");
	m_TGDataT.InsertString(1,"TG_DATA_POOR_SIGNAL");

//	m_TGDataT.InsertString(0,"TG_DATA_RAW");
//	m_TGDataT.InsertString(1,"TG_DATA_DELTA");

	m_TGDataT.InsertString(2,"TG_DATA_ATTENTION");
	m_TGDataT.InsertString(3,"TG_DATA_MEDITATION");
	m_TGDataT.InsertString(4,"TG_DATA_RAW");
	m_TGDataT.InsertString(5,"TG_DATA_DELTA");
	m_TGDataT.InsertString(6,"TG_DATA_THETA");
	m_TGDataT.InsertString(7,"TG_DATA_ALPHA1");
	m_TGDataT.InsertString(8,"TG_DATA_ALPHA2");
	m_TGDataT.InsertString(9,"TG_DATA_BETA1");
	m_TGDataT.InsertString(10,"TG_DATA_BETA2");
	m_TGDataT.InsertString(11,"TG_DATA_GAMMA1");
	m_TGDataT.InsertString(12,"TG_DATA_GAMMA2");
	m_TGDataT.InsertString(13,"TG_DATA_BLINK_STRENGTH");
	

	m_find.InsertString(0,"ID");
	m_find.InsertString(1,"Name2");
	m_find.InsertString(2,"Name3");
	m_find.InsertString(3,"Name4");
  


   m_slider1.SetRange(0,100);//设置滑动范围

   m_slider1.SetTicFreq(1);
   m_slider2.SetRange(0,100);//设置滑动范围

   m_slider2.SetTicFreq(1);
   m_slider3.SetRange(-1000,1000);//设置滑动范围

   m_slider3.SetTicFreq(1);


	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t sql;

	sql="select* from ThinkGear";
	_RecordsetPtr m_pRecordset;
	m_pRecordset=m_AdoConn.GetRecordSet(sql);
    UpdateData(true);
	m_pRecordset->MoveLast();
//	m_pRecordset->MovePrevious();
 	CString str=(char*)(_bstr_t)m_pRecordset->GetCollect("ID");

    MessageBox(str);
	m_inc=atoi(str);
    m_AdoConn.ExitConnect();

	DWORD style=WS_VISIBLE|WS_CHILD;
	if(!m_ComPort.Create(NULL,style,CRect(0,0,0,0),this,IDC_MSCOMM1))
	{
       TRACE0("Failed to create OLE Communications Control ");
       return -1;
	}
   InsertCom();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFirstTGDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFirstTGDlg::OnPaint() 
{
	static CBrush brush(RGB(255,0,0));
	SetClassLong(this->m_hWnd,GCL_HBRBACKGROUND,(LONG)(HBRUSH)brush);
	CPaintDC dc(this);

	CRect rect;
	if (IsIconic())
	{
		 // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);

		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		dc.DrawIcon(x, y, m_hIcon);

	}
	else
	{
		CDialog::OnPaint();
	}


	m_slider3.SetPos((int)m_sigleValue[4]);
////在对话框内显示位图 
     if(m_start==1)
	{
		 m_slider1.SetPos((int)m_sigleValue[2]);
		 m_slider2.SetPos((int)m_sigleValue[3]);
       CBitmap bmp1,bmp2;
	   bmp1.LoadBitmap(IDB_BITMAP1);

	   BITMAP bm1;
	   bmp1.GetBitmap(&bm1);

 /*      HBITMAP hbitmap;,bm2

 //      //装载图片文件MM.bmp

 //      hbitmap=(HBITMAP)::LoadImage(::AfxGetInstanceHandle(),"MM.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);

    ////   hbmp.Attach(hbitmap);

       //获取图片格式

       BITMAP bm;

       hbmp.GetBitmap(&bm);
	   */

       CDC dcMem;

       dcMem.CreateCompatibleDC(GetDC());

 


       CRect lRect;


       GetClientRect(&lRect);

       lRect.NormalizeRect();
 //     bmp1.CreateCompatibleBitmap(&dc,lRect.Width(),lRect.Height()-300);
      CBitmap * poldBitmap1;
      poldBitmap1=(CBitmap*)dcMem.SelectObject(bmp1);
       //显示位图

    
//	  dcMem.FillSolidRect(lRect.left,lRect.top+250,lRect.Width(),lRect.Height()-300,RGB(0,0,255));
//     dc.BitBlt(lRect.left,lRect.top+250,lRect.Width(),lRect.Height()-300,&dcMem,m_count,0,SRCCOPY);
	  GetDC()->StretchBlt(lRect.left+10,lRect.top+250,lRect.Width(),lRect.Height()-300,&dcMem,m_count,-5,bm1.bmWidth+10,bm1.bmHeight+100,SRCCOPY);
       dcMem.SelectObject(&poldBitmap1);
	   bmp1.DeleteObject();
	   dcMem.DeleteDC();

/*
	       bmp2.LoadBitmap(IDB_BITMAP2);
	       bmp2.GetBitmap(&bm2);
           dcMem.CreateCompatibleDC(NULL);
//           bmp2.CreateCompatibleBitmap(&dc,lRect.Width(),lRect.Height()-300);
           CBitmap * poldBitmap2=(CBitmap*)dcMem.SelectObject(bmp2);
//	   dcMem.FillSolidRect(lRect.left,lRect.top+250,lRect.Width(),lRect.Height()-300,RGB(0,0,255));

//       //显示位图
//       dc.BitBlt(lRect.left,lRect.top+250,lRect.Width(),lRect.Height()-300,&dcMem,m_count,-5,SRCCOPY);
           GetDC()->StretchBlt(lRect.left+10,lRect.top+250,lRect.Width(),lRect.Height()-300,&dcMem,m_clean,-5,bm2.bmWidth+10,bm2.bmHeight+100,SRCCOPY);
           dcMem.SelectObject(&poldBitmap2);
	       bmp2.DeleteObject();
	       dcMem.DeleteDC();
		   */
	}

 /*        if(m_sigleValue1>0)
	   {

	       bmp2.LoadBitmap(IDB_BITMAP2);
	       bmp2.GetBitmap(&bm2);
           dcMem.CreateCompatibleDC(NULL);
//           bmp2.CreateCompatibleBitmap(&dc,lRect.Width(),lRect.Height()-300);
           CBitmap * poldBitmap2=(CBitmap*)dcMem.SelectObject(bmp2);
//	   dcMem.FillSolidRect(lRect.left,lRect.top+250,lRect.Width(),lRect.Height()-300,RGB(0,0,255));

//       //显示位图
//       dc.BitBlt(lRect.left,lRect.top+250,lRect.Width(),lRect.Height()-300,&dcMem,m_count,-5,SRCCOPY);
           GetDC()->StretchBlt(lRect.left+10,lRect.top+250,lRect.Width(),lRect.Height()-300,&dcMem,m_clean,-5,bm2.bmWidth+10,bm2.bmHeight+100,SRCCOPY);
           dcMem.SelectObject(&poldBitmap2);
	       bmp2.DeleteObject();
	       dcMem.DeleteDC();

	   }
	   
//       dcMem.CreateCompatibleDC(NULL);
//       bmp1.CreateCompatibleBitmap(&dc,lRect.Width(),lRect.Height()-300);
 
      poldBitmap1=(CBitmap*)dcMem.SelectObject(bmp1);
//	   dcMem.FillSolidRect(lRect.left,lRect.top+250,lRect.Width(),lRect.Height()-300,RGB(0,0,255));

 //      //显示位图
 //      sdc->BitBlt(lRect.left,lRect.top+250,lRect.Width(),lRect.Height()-300,&dcMem,m_count,-5,SRCCOPY);
       GetDC()->StretchBlt(lRect.left+10,lRect.top+250,lRect.Width(),lRect.Height()-300,&dcMem,m_count,-5,bm1.bmWidth+10,bm1.bmHeight+100,SRCCOPY);
       dcMem.SelectObject(&poldBitmap1);
	   bmp1.DeleteObject();
	   dcMem.DeleteDC();*/
//AfxMessageBox("NULL");	   
	   CDC *myDC=this->GetDC();
	   if(m_bul)
	   {
	      CPen pen;
	      CRect rc,rect2,rect3;
	      m_RECT.GetWindowRect(&rc);
	      m_Rect1.GetWindowRect(&rect3);
	      ScreenToClient(&rc);
	      ScreenToClient(&rect3);
	      COLORREF cr=RGB(255,255,255);
	      COLORREF cr1=RGB(255,255,255);
	      CBrush br,br1;
		  br1.CreateSolidBrush(cr1);
	      br.CreateSolidBrush(cr);
		  myDC->FillRect(&rc,&br);
		  myDC->FillRect(&rect3,&br1);
	      myDC->MoveTo(520,70);
	      myDC->LineTo(780,70);
		  myDC->MoveTo(25,220);
	      myDC->LineTo(800,220);

 		  pen.CreatePen(PS_SOLID,1,RGB(0,255,255));
		  myDC->SelectObject(&pen);
		  myDC->MoveTo(660,140);
		  myDC->LineTo(700,140);
          pen.DeleteObject(); 

 		  pen.CreatePen(PS_SOLID,1,RGB(255,255,0));
		  myDC->SelectObject(&pen);
		  myDC->MoveTo(660,160);
		  myDC->LineTo(700,160);
          pen.DeleteObject(); 

 		  pen.CreatePen(PS_SOLID,1,RGB(213,23,80));
		  myDC->SelectObject(&pen);
		  myDC->MoveTo(600,140);
		  myDC->LineTo(630,140);
          pen.DeleteObject();
		  
 		  pen.CreatePen(PS_SOLID,1,RGB(188,192,4));
		  myDC->SelectObject(&pen);
		  myDC->MoveTo(330,160);
		  myDC->LineTo(360,160);
          pen.DeleteObject(); 

 		  pen.CreatePen(PS_SOLID,1,RGB(3,194,51));
		  myDC->SelectObject(&pen);
		  myDC->MoveTo(400,160);
		  myDC->LineTo(430,160);
          pen.DeleteObject();
		  
 		  pen.CreatePen(PS_SOLID,1,RGB(13,7,203));
		  myDC->SelectObject(&pen);
		  myDC->MoveTo(470,160);
		  myDC->LineTo(500,160);
          pen.DeleteObject();
		  
 		  pen.CreatePen(PS_SOLID,1,RGB(26,123,145));
		  myDC->SelectObject(&pen);
		  myDC->MoveTo(540,160);
		  myDC->LineTo(570,160);
          pen.DeleteObject();
		  
 		  pen.CreatePen(PS_SOLID,1,RGB(66,0,164));
		  myDC->SelectObject(&pen);
		  myDC->MoveTo(610,160);
		  myDC->LineTo(640,160);
          pen.DeleteObject(); 
	   }
		  if(m_rep1)
		  {	 	      
			  CRect rect3;
			  CBrush br1;   
			  m_Rect1.GetWindowRect(&rect3);     
			  ScreenToClient(&rect3);
	         COLORREF cr1=RGB(255,255,255);
			 br1.CreateSolidBrush(cr1);
			 myDC->FillRect(&rect3,&br1);
		     myDC->MoveTo(25,220);
	         myDC->LineTo(800,220);
		  }		
	   CPen pen;
       if(m_showBu)
	   {
		   CString str;
	       ADOConn m_AdoConn;
	       m_AdoConn.OnInitADOConn();
	       _bstr_t sql;
           
           int n=0;

	       sql="select* from ThinkGear";
	       _RecordsetPtr m_pRecordset;
	       m_pRecordset=m_AdoConn.GetRecordSet(sql);
	       try
		   {	 

			   m_pRecordset->MoveFirst();
               switch(m_DataType[0])
			   {
			   case TG_DATA_ATTENTION:
				   str="ATTENTION";
				   pen.CreatePen(PS_SOLID,1,RGB(0,255,255));
			       myDC->SelectObject(&pen);
                   break;
			   case TG_DATA_MEDITATION:
				   str="MEDITATION";
				   pen.CreatePen(PS_SOLID,1,RGB(255,255,0));
			       myDC->SelectObject(&pen);
				   break;
			   case TG_DATA_RAW:
				   str="RAW";
				   pen.CreatePen(PS_SOLID,1,RGB(213,23,80));
			       myDC->SelectObject(&pen);
				   break;
			   case TG_DATA_DELTA:
				   str="DELTA";
				   pen.CreatePen(PS_SOLID,1,RGB(13,7,203));
			       myDC->SelectObject(&pen);
				   break;

			   case TG_DATA_THETA:
				   str="THETA";
				   pen.CreatePen(PS_SOLID,1,RGB(3,194,51));
			       myDC->SelectObject(&pen);
				   break;
			   case TG_DATA_ALPHA1:
				   str="ALPHA1";
				   pen.CreatePen(PS_SOLID,1,RGB(188,192,5));
			       myDC->SelectObject(&pen);
				   break;
			   case TG_DATA_ALPHA2:
				   str="ALPHA2";
				   pen.CreatePen(PS_SOLID,1,RGB(183,98,4));
			       myDC->SelectObject(&pen);
				   break;

			   case TG_DATA_BETA1:
				   str="BETA1";
				   pen.CreatePen(PS_SOLID,1,RGB(26,123,145));
			       myDC->SelectObject(&pen);
				   break;
			   case TG_DATA_BETA2:
				   str="BETA2";
				   pen.CreatePen(PS_SOLID,1,RGB(116,33,137));
			       myDC->SelectObject(&pen);
				   break;
			   case TG_DATA_GAMMA1:
				   str="GAMMA1";
				   pen.CreatePen(PS_SOLID,1,RGB(66,0,64));
			       myDC->SelectObject(&pen);
				   break;
			   case TG_DATA_GAMMA2:
				   str="GAMMA2";
				   pen.CreatePen(PS_SOLID,1,RGB(200,11,171));
			       myDC->SelectObject(&pen);
				   break;
			   case TG_DATA_BLINK_STRENGTH:
				   str="BLINK_STRENGTH";
				   pen.CreatePen(PS_SOLID,1,RGB(0,255,255));
			       myDC->SelectObject(&pen);
				   break;
               default:
				   break;
			   }
		       while(m_AdoConn.m_pRecordset->adoEOF==0)
			   {	 
//				   m_showA=(atoi)((char*)(_bstr_t)m_pRecordset->GetCollect((_bstr_t)str));
//	   			    pen.CreatePen(PS_SOLID,2,RGB(0,255,255));
              if(m_DataType[0]!=2&&m_DataType[0]!=3&&m_DataType[0]!=4)
			  {
                   myDC->MoveTo(25+n,(m_showA/1000)+220);
                   m_showA=(atoi)((char*)(_bstr_t)m_pRecordset->GetCollect((_bstr_t)str));
                   myDC->LineTo(25+n+2,(m_showA/1000)+220);
			  }
			  else
			  {
                   myDC->MoveTo(25+n,(m_showA/5)+220);
                   m_showA=(atoi)((char*)(_bstr_t)m_pRecordset->GetCollect((_bstr_t)str));
				   myDC->LineTo(25+n+2,(m_showA/5)+220);
			  }
				    
                    
//                 AfxMessageBox("NULL");
					
                  
					m_pRecordset->MoveNext();
					n++;

			   }
                 
	           	
           pen.DeleteObject();
		   }
	       catch(_com_error e)
		   {
	            CString strComError;
                strComError.Format("错误编号: %08lx\n错误信息: %s\n错误源: %s\n错误描述: %s",
                e.Error(), // 错误编号
                e.ErrorMessage(), // 错误信息
                (LPCSTR) e.Source(), // 错误源
                (LPCSTR) e.Description()); // 错误描述
                ::MessageBox(NULL,strComError,"错误",MB_ICONEXCLAMATION);

		   }
	   }

       if(m_incpoint==250)
	   {
		   m_rep2=1;
           m_incpoint=0;
	   }

		  if(m_rep2)
		  {	 	      
			  CRect rc;
			  CBrush br1;   
			  m_RECT.GetWindowRect(&rc);     
			  ScreenToClient(&rc);
	         COLORREF cr1=RGB(255,255,255);
			 br1.CreateSolidBrush(cr1);
			 myDC->FillRect(&rc,&br1);
	         myDC->MoveTo(520,70);
	         myDC->LineTo(780,70);
		  }			   
       pen.CreatePen(PS_SOLID,1,RGB(0,0,0));			   
	   myDC->SelectObject(&pen);
	   myDC->MoveTo(520+m_incpoint,(int)((m_oldsigle/5))+70);
	   myDC->LineTo(520+m_incpoint+1,(int)((m_sigleValue[m_DataType[0]]/5))+70);
	   m_oldsigle=m_sigleValue[m_DataType[0]];
       pen.DeleteObject();
       if(m_incpoint==250)
	   {
		   m_rep2=1;
           m_incpoint=0;
	   }
        m_bul=0;
		m_showBu=0;
		m_rep2=0;
	    m_start=0;
//        m_sigleValue[13]=0;
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFirstTGDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFirstTGDlg::Onconnect() 
{
	// TODO: Add your control notification handler code here

    CString str;
    /* Print driver version number */
    m_dllVersion = TG_GetDriverVersion();
    str.Format("%d",m_dllVersion);
    MessageBox(str," DriverVersion");

    /* Get a connection ID handle to ThinkGear */
    m_connectionId = TG_GetNewConnectionId();
    if( m_connectionId < 0 ) {
//        AfxMessageBox(" Faile to get new connection  ");
		CString error;
		error.Format("%d",m_connectionId);
        MessageBox(TEXT(" Faile to get new connection  "),error); 
 //       exit( EXIT_FAILURE );
    }

    /* Set/open stream (raw bytes) log file for connection */
    m_errCode = TG_SetStreamLog( m_connectionId, "streamLog.txt" );
    if( m_errCode < 0 ) {
  //      AfxMessageBox("  ");
		CString error;
		error.Format("%d",m_errCode);
        MessageBox(TEXT("Faile to set streamLog"),error); 
 //       exit( EXIT_FAILURE );
    }

    /* Set/open data (ThinkGear values) log file for connection */
    m_errCode = TG_SetDataLog( m_connectionId, "dataLog.txt" );
    if( m_errCode < 0 ) {
 //       AfxMessageBox(" Faile to set dataLog  ");
		CString error;
		error.Format("%d",m_errCode);
        MessageBox(TEXT(" Faile to set dataLog  "),error); 
 //       exit( EXIT_FAILURE );
    }
     if(0!=TG_EnableBlinkDetection(m_connectionId,1)) {
		CString error;
		error.Format("%d",m_errCode);
        MessageBox(TEXT(" Faile to set BlinkDetection  "),error); 
	}
    /* Attempt to connect the connection ID handle to serial port "COM5" */
    m_comPortName = "\\\\.\\COM40";
    m_errCode = TG_Connect( m_connectionId, 
                          m_comPortName, 
                          TG_BAUD_1200, 
                          TG_STREAM_PACKETS );
    if( m_errCode < 0 ) {
 //       AfxMessageBox(" Faile to connect  ");
		CString error;
		error.Format("%d",m_errCode);
        MessageBox(TEXT(" Faile to connect  "),error); 
//        exit( EXIT_FAILURE );
    }
	else
	{
		
	}
    SetTimer(1,1,NULL);
}

void CFirstTGDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	    /* Read 10 ThinkGear Packets from the connection, 1 Packet at a time */
 //         AfxMessageBox("Reading ... ");
        /* Attempt to read a Packet of data from the connection */
        KillTimer(1);
        while(m_break)
		{

		
	    m_sigleValue[2]=0;
        m_sigleValue[3]=0;
	    m_sigleValue[4]=0;
        m_sigleValue[5]=0;
	    m_sigleValue[6]=0;
        m_sigleValue[7]=0;
	    m_sigleValue[8]=0;
        m_sigleValue[9]=0;
	    m_sigleValue[11]=0;
        m_sigleValue[12]=0;
		m_sigleValue[13]=0;
        m_errCode = TG_ReadPackets( m_connectionId, 1);

        /* If TG_ReadPackets() was able to read a complete Packet of data... */
        if( m_errCode == 1 ) 
		{


            /* If attention value has been updated by TG_ReadPackets()... */// 
            if( (TG_GetValueStatus(m_connectionId, m_DataType[2])) != 0) 
			{

 //        AfxMessageBox("Reading ... ");
				for(int n=2;n<=13;n++)
				{
                    m_sigleValue[n]=TG_GetValue(m_connectionId,m_DataType[n]);
				}

 //             m_sigleValue[13]=TG_GetValue(m_connectionId,m_DataType[13]);
			  m_break=0;
              SetTimer(1,1,NULL);
        
            }

/*			else

			 if((TG_GetValueStatus(m_connectionId, m_DataType[4]))!=0)
			{
             m_sigleValue[4]=TG_GetValue(m_connectionId,m_DataType[4]);
//            m_time= CTime::GetCurrentTime();
//			 m_inc++;
             m_siv[4]=(int)m_sigleValue[4];
//			 m_id.Format("%d",m_inc); 
//			 AddData();
			 m_break=0;
             SetTimer(1,1,NULL);
			}
*/			
			/* end "If attention value has been updated..." */
		}
		
		}
/*            else
			{
//				MessageBox("no value");||(TG_GetValueStatus(m_connectionId, m_DataType2)) != 0 
			}
            if( (TG_GetValueStatus(m_connectionId, m_DataType2)) != 0) 
			{


//              m_sigleValue1=TG_GetValue(m_connectionId,m_DataType1); 
              m_sigleValue2=TG_GetValue(m_connectionId,m_DataType2); 
            } /* end "If attention value has been updated..." */
/*			if((TG_GetValueStatus(m_connectionId, m_DataType3))!=0)
			{
             m_sigleValue3=TG_GetValue(m_connectionId,m_DataType3); 
			}
*/
		     m_break=1;
//            if(m_sigleValue[2]>0||m_sigleValue[3]>0)
//			 {
				m_inc++;
//				m_incpoint++;
                m_time= CTime::GetCurrentTime();
                for(int n=2;n<=13;n++)
				{
                     m_siv[n]=(int)m_sigleValue[n]; 
//					 m_value[n].Format("%d",siv[n]);
				}
				

				m_id.Format("%d",m_inc);  
/*                m_name[2]="ATTENTION";
				m_name[3]="MEDITATION";
                m_name[4]="RAW";
				m_name[5]="DELTA";
                m_name[6]="THETA";
				m_name[7]="ALPHA1";
                m_name[8]="ALPHA2";
				m_name[9]="BETA1";
                m_name[10]="BETA2";
				m_name[11]="GAMMA1";
                m_name[12]="GAMMA2";
                m_name[13]="BLINK_STRENGTH";
*/

//                m_name[4]=m_showType;
//// 	            m_value[4].Format("%d",siv[4]);
                AddData();
               Speed(m_sigleValue[2],m_sigleValue[13]);
//			 }
        
/*		else
		{
		   CString error;
		   error.Format("%d",m_errCode);
          MessageBox(TEXT(" Faile to get value status  "),error);
		} end "If a Packet of data was read..." */
 /* end "Read 10 Packets of data from connection..." */




              m_incpoint++;
			  
//              m_sigleValue[13]=0;

       this->Invalidate(false);
	   CDialog::OnTimer(nIDEvent);
 

			 
}

void CFirstTGDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
        TG_Disconnect( m_connectionId );
        KillTimer(1);
		m_count=0;
        AfxMessageBox("cancel connect ");
}

int CFirstTGDlg::Speed(float sigle,float EyeBlink)
{   
	 
     if(EyeBlink!=m_comp)
	 {
		 if(m_SP){
		 		 if(EyeBlink<=80)TextData[0]='1';
		         if(EyeBlink>80&&EyeBlink<120)TextData[0]='2';
		 }

		 if(EyeBlink>=120){
			 m_SP=~m_SP;
			 if(m_SP)
			 TextData[0]='7';
			 else{
				 TextData[0]='0';
                 m_start=1;
	             m_comp=EyeBlink;
                 OnCommSend();
				 return 0;
			 }
		 }
                 m_start=1;
	             m_comp=EyeBlink;
                 OnCommSend();
		 return 1;
	 }
	 else
	 {   
		 if(m_SP)
		 {
	if(sigle<=0)
	{
		m_count-=0;
		m_clean-=0;
        TextData[0]='0';
	}
	if(sigle<=20&&sigle>0)
	{
		m_count-=5;
		m_clean-=5;
        TextData[0]='5';
	}
	if(sigle<=40&&sigle>20)
	{
		m_count-=15;
		m_clean-=15;
	    TextData[0]='5';
	}
	if(sigle<=60&&sigle>40)
	{
		m_count-=20;
		m_clean-=20;
		TextData[0]='5';
//		if(m_LMR==)
	}
	if(sigle<=80&&sigle>60)
	{
		m_count-=25;
		m_clean-=25;
        TextData[0]='3';
	}
	if(sigle>80)
	{
		m_count-=30;
 		m_clean-=30;
		TextData[0]='3';
	}

		 }
	}
    m_start=1;
	m_comp=EyeBlink;
    OnCommSend();
   return 1;
}

BOOL CFirstTGDlg::AddData()
{
/**/	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t sql;

	sql="select* from ThinkGear";
	_RecordsetPtr m_pRecordset;
	m_pRecordset=m_AdoConn.GetRecordSet(sql);
//m_pRecordsetOpen("select * from stud",_variant_t((IDispatch *)pConn),adOpenDynamic,adLockOptimistic,adCmdText);



	try
	{
        
		CString m_gettime = m_time.Format( "%Y%m%d%H%M%S" );
		m_pRecordset->AddNew();
		m_pRecordset->PutCollect("ID",(_bstr_t)m_id);
//		m_pRecordset->PutCollect("Name2",(_bstr_t)m_name[2]);
		m_pRecordset->PutCollect("ATTENTION",(_bstr_t)m_siv[2]);
//		m_pRecordset->PutCollect("Name3",(_bstr_t)m_name[3]);
		m_pRecordset->PutCollect("MEDITATION",(_bstr_t)m_siv[3]);
//		m_pRecordset->PutCollect("Name3",(_bstr_t)m_name[3]);
		m_pRecordset->PutCollect("RAW",(_bstr_t)m_siv[4]);
//		m_pRecordset->PutCollect("Name4",(_bstr_t)m_name[4]);
		m_pRecordset->PutCollect("DELTA",(_bstr_t)m_siv[5]);
//		m_pRecordset->PutCollect("Name5",(_bstr_t)m_name[5]);
		m_pRecordset->PutCollect("THETA",(_bstr_t)m_siv[6]);
//		m_pRecordset->PutCollect("Name6",(_bstr_t)m_name[6]);
		m_pRecordset->PutCollect("ALPHA1",(_bstr_t)m_siv[7]);
//		m_pRecordset->PutCollect("Name7",(_bstr_t)m_name[7]);
		m_pRecordset->PutCollect("ALPHA2",(_bstr_t)m_siv[8]);
//		m_pRecordset->PutCollect("Name8",(_bstr_t)m_name[8]);
		m_pRecordset->PutCollect("BETA1",(_bstr_t)m_siv[9]);
//		m_pRecordset->PutCollect("Name9",(_bstr_t)m_name[9]);
		m_pRecordset->PutCollect("BETA2",(_bstr_t)m_siv[10]);
//		m_pRecordset->PutCollect("Name10",(_bstr_t)m_name[10]);
		m_pRecordset->PutCollect("GAMMA1",(_bstr_t)m_siv[11]);
//		m_pRecordset->PutCollect("Name11",(_bstr_t)m_name[11]);
		m_pRecordset->PutCollect("GAMMA2",(_bstr_t)m_siv[12]);
//		m_pRecordset->PutCollect("Name12",(_bstr_t)m_name[12]);
		m_pRecordset->PutCollect("BLINK_STRENGTH",(_bstr_t)m_siv[13]);
//		m_pRecordset->PutCollect("Name13",(_bstr_t)m_name[13]);
//		m_pRecordset->PutCollect("Value13",(_bstr_t)m_value[13]);
		m_pRecordset->PutCollect("Time",(_bstr_t)m_gettime);
		m_pRecordset->Update();
		m_AdoConn.ExitConnect();
	}
	catch(_com_error e)
	{
	   CString strComError;
       strComError.Format("错误编号: %08lx\n错误信息: %s\n错误源: %s\n错误描述: %s",
       e.Error(), // 错误编号
       e.ErrorMessage(), // 错误信息
       (LPCSTR) e.Source(), // 错误源
       (LPCSTR) e.Description()); // 错误描述
       ::MessageBox(NULL,strComError,"错误",MB_ICONEXCLAMATION);
		return false;
	}
	return true;

}

void CFirstTGDlg::OnDelete() 
{	
	ADOConn m_AdoConn;
	m_AdoConn.OnInitADOConn();
	_bstr_t sql;

	sql="select* from ThinkGear";
	_RecordsetPtr m_pRecordset;
	m_pRecordset=m_AdoConn.GetRecordSet(sql);
    UpdateData(true);
    m_button=(CButton*)GetDlgItem(IDC_CHECK1);
    
	if(m_button->GetCheck()==1)
	{
	    m_pRecordset->MoveFirst();
		m_pRecordset->MoveNext();
		while(m_AdoConn.m_pRecordset->adoEOF==0)
		{

	
		    m_pRecordset->Delete(adAffectCurrent);
            m_pRecordset->MoveNext();

		    
	        
		}
 //           m_pRecordset->Update();
//		    m_AdoConn.ExitConnect();
	}
	else
	{
	   try
	   {
	    m_pRecordset->MoveFirst();

//	    m_pRecordset->Move((atoi)(m_listN),vtMissing);GetDataMember
	    while(m_AdoConn.m_pRecordset->adoEOF==0)
		{
             if((char*)(_bstr_t)m_pRecordset->GetCollect("ID")==m_listN)
			 {
		          m_pRecordset->Delete(adAffectCurrent);
		          m_pRecordset->Update();
				  break;
			 }

	    m_pRecordset->MoveNext();
		}


//		m_AdoConn.ExitConnect();

	   }
	   catch(_com_error e)
	   {
	   CString strComError;
       strComError.Format("错误编号: %08lx\n错误信息: %s\n错误源: %s\n错误描述: %s",
       e.Error(), // 错误编号
       e.ErrorMessage(), // 错误信息
       (LPCSTR) e.Source(), // 错误源
       (LPCSTR) e.Description()); // 错误描述
       ::MessageBox(NULL,strComError,"错误",MB_ICONEXCLAMATION);
	   }
	}
		    m_AdoConn.ExitConnect();
//	m_grid.DeleteTempMap();
    UpdateData(false);
}
/**/
void CFirstTGDlg::OnChack() 
{


	m_adodc.SetConnectionString("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=MyDataBase.mdb;Persist Security Info=False");

    UpdateData(true);
    m_button=(CButton*)GetDlgItem(IDC_CHECK1);
	m_find.GetLBText(m_find.GetCurSel(),m_findstr);

	if(m_button->GetCheck()==1)
	{


     m_adodc.SetRecordSource("select*from ThinkGear");	
	}
	else
	{
	    m_adodc.SetRecordSource("select*from ThinkGear where "+m_findstr+" like '"+m_listN+"'");
	}


	
	m_adodc.Refresh();
    UpdateData(false);

	m_grid.SetRefDataSource(m_adodc.GetControlUnknown());	

}


void CFirstTGDlg::OnSetDataT() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_TGDataT.GetLBText(m_TGDataT.GetCurSel(),m_showType);
	m_DataType[0]=m_TGDataT.GetCurSel();
    UpdateData(false);
}

void CFirstTGDlg::OnOK() 
{
	// TODO: Add extra validation here
	    TG_FreeConnection( m_connectionId );
        KillTimer(1);
		m_count=0;
        AfxMessageBox("cancel connect ");	
	CDialog::OnOK();
}

void CFirstTGDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	    TG_FreeConnection( m_connectionId );
        KillTimer(1);
		m_count=0;
        AfxMessageBox("cancel connect ");	
	CDialog::OnCancel();
}

void CFirstTGDlg::OnShow() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
    m_button=(CButton*)GetDlgItem(IDC_CHECK2);
 	m_rep1=m_button->GetCheck();
    m_showBu=1;

//	m_TGDataT.GetLBText(m_TGDataT.GetCurSel(),m_showType);
	m_DataType[0]=m_TGDataT.GetCurSel();
    UpdateData(false);
    OnPaint();
}

void CFirstTGDlg::OnShowWave() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
    m_incpoint=0;
	m_DataType[0]=m_TGDataT.GetCurSel();
	m_rep2=1;
    OnPaint();
}

void CFirstTGDlg::OnSetCOM() 
{
	// TODO: Add your control notification handler code here
	CString Mode,s1,s2,s3;
	UpdateData(true);
    m_COM1=m_COM.GetCurSel();
    m_rate.GetLBText(m_rate.GetCurSel(),s1);
    m_data.GetLBText(m_data.GetCurSel(),s2);
    m_stop.GetLBText(m_stop.GetCurSel(),s3);
    Mode=s1+","+"n"+","+s2+","+s3;
//    m_ComPort.SetCommPort(3);　　//选择COM?
	if(m_COM1>=14)
	{  
//		AfxMessageBox(" Set Done0");
      m_ComPort.SetCommPort(m_COM1+25);
   AfxMessageBox(" Set Done1");
	}
	else
    m_ComPort.SetCommPort(m_COM1+1);
    m_ComPort. SetInBufferSize(1024); //设置输入缓冲区的大小，Bytes

    m_ComPort. SetOutBufferSize(512); //设置输入缓冲区的大小，Bytes//

   if(!m_ComPort.GetPortOpen()) //打开串口

   m_ComPort.SetPortOpen(TRUE);

   m_ComPort.SetInputMode(1); //设置输入方式为二进制方式

   m_ComPort.SetSettings(Mode); //设置波特率等参数
//   AfxMessageBox(" Set Done2");
   m_ComPort.SetRThreshold(1); //为1表示有一个字符引发一个事件

//　 m_ComPort.SetInputLen(0);
   m_ComPort.SetInputLen(0);
   AfxMessageBox(" Set Done");
}

void CFirstTGDlg::InsertCom()
{
	m_rate.InsertString(0,"1200");
	m_rate.InsertString(1,"2400");
	m_rate.InsertString(2,"4800");
	m_rate.InsertString(3,"9600");
	m_rate.InsertString(4,"19200");
	m_rate.InsertString(5,"38400");
	m_rate.InsertString(6,"57600");
	m_rate.InsertString(7,"115200");

	m_data.InsertString(0,"5");
	m_data.InsertString(1,"6");
	m_data.InsertString(2,"7");
	m_data.InsertString(3,"8");

	m_stop.InsertString(0,"1");
	m_stop.InsertString(1,"1.5");
	m_stop.InsertString(2,"2");

//	m_TGDataT.InsertString(0,"TG_DATA_RAW");
//	m_TGDataT.InsertString(1,"TG_DATA_DELTA");
	m_COM.InsertString(0,"COM1");
	m_COM.InsertString(1,"COM2");
	m_COM.InsertString(2,"COM3");
	m_COM.InsertString(3,"COM4");
	m_COM.InsertString(4,"COM5");
	m_COM.InsertString(5,"COM6");
	m_COM.InsertString(6,"COM7");
	m_COM.InsertString(7,"COM8");

	m_COM.InsertString(8,"COM9");
	m_COM.InsertString(9,"COM10");
	m_COM.InsertString(10,"COM11");
	m_COM.InsertString(11,"COM12");
	m_COM.InsertString(12,"COM13");
	m_COM.InsertString(13,"COM14");
	m_COM.InsertString(14,"COM20");
	m_COM.InsertString(15,"COM40");
	m_COM.InsertString(16,"COM41");
	m_COM.InsertString(17,"COM42");
	m_COM.InsertString(18,"COM43");
}

BEGIN_EVENTSINK_MAP(CFirstTGDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CFirstTGDlg)
	ON_EVENT(CFirstTGDlg, IDC_MSCOMM1, 1 /* OnComm */, OnOnCommMscomm1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CFirstTGDlg::OnOnCommMscomm1() 
{
	// TODO: Add your control notification handler code here
//    VARIANT vResponse;
	VARIANT vResponse;
//	int k;
	int k;

    if(m_commCtrl.GetCommEvent()==2)
	{
        k=m_commCtrl.GetInBufferCount(); 

        if(k>0)
		{

        vResponse=m_commCtrl.GetInput(); //read

//        SaveData(k,(unsigned char*) vResponse.parray->pvData);
		AfxMessageBox(" COM have data ");

		} 

	}	
}

void CFirstTGDlg::OnCommSend() 
{
	// TODO: Add your control notification handler code here
	 int Count=2;
	char TxData[2];
    UpdateData(true);

    strncpy(TxData,(LPCTSTR)m_CStoCH,sizeof(TxData));
    CByteArray array;

    array.RemoveAll();

    array.SetSize(Count);

//	for(int j=0;j<Count;j++)TxData[j]='1';
    if(m_start)
      array.SetAt(1, TextData[0]);
	else
    for(int i=0;i<Count;i++)array.SetAt(i, TxData[i]);

    m_ComPort.SetOutput(COleVariant(array)); // 发送数据
//	AfxMessageBox(" Send Done");

}

