// firstTG.h : main header file for the FIRSTTG application
//

#if !defined(AFX_FIRSTTG_H__BDA744E1_9BFB_4C4B_816D_645D53F64D13__INCLUDED_)
#define AFX_FIRSTTG_H__BDA744E1_9BFB_4C4B_816D_645D53F64D13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "mscomm.h"

/////////////////////////////////////////////////////////////////////////////
// CFirstTGApp:
// See firstTG.cpp for the implementation of this class
//

class CFirstTGApp : public CWinApp
{
public:
	CFirstTGApp();
    CMSComm m_ComPort;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFirstTGApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFirstTGApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIRSTTG_H__BDA744E1_9BFB_4C4B_816D_645D53F64D13__INCLUDED_)
