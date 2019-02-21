// firstTG.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "firstTG.h"
#include "firstTGDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFirstTGApp

BEGIN_MESSAGE_MAP(CFirstTGApp, CWinApp)
	//{{AFX_MSG_MAP(CFirstTGApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFirstTGApp construction

CFirstTGApp::CFirstTGApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CFirstTGApp object

CFirstTGApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CFirstTGApp initialization

BOOL CFirstTGApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CFirstTGDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
		/*
	DWORD style=WS_VISIBLE|WS_CHILD;
	if(!m_ComPort.Create(NULL,style,CRect(0,0,0,0),this,IDC_MSCOMM1))
	{
       TRACE0("Failed to create OLE Communications Control ");
       return -1;
	}
*/
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
