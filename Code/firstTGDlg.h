// firstTGDlg.h : header file
//
//{{AFX_INCLUDES()
#include "adodc.h"
#include "datagrid.h"
#include "adodc1.h"
#include "datagrid1.h"
#include "mscomm.h"
//}}AFX_INCLUDES

#if !defined(AFX_FIRSTTGDLG_H__F3DCD829_2240_4AEF_B213_90AB8C0D61B3__INCLUDED_)
#define AFX_FIRSTTGDLG_H__F3DCD829_2240_4AEF_B213_90AB8C0D61B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFirstTGDlg dialog

class CFirstTGDlg : public CDialog
{
// Construction
public:
	int m_COM1;
//    void OnCommSend();
	char TextData[4];
	void InsertCom();
//    CFirstTGApp m_App;
	BOOL AddData();
	int Speed(float single,float EyeBlink);
	CFirstTGDlg(CWnd* pParent = NULL);	// standard constructor
	char *m_comPortName;
    int   m_dllVersion ;
    int   m_connectionId; 
    int   m_packetsRead ;
    int   m_errCode ;
	float m_sigleValue[15];

	CTime m_time;
	int m_count;
	int m_clean;
	int m_inc;

	CString m_id;
//    CString m_name[15]; 
	CString m_value[15];
    char m_LMR;
	BOOL m_SP;
	float m_comp;
	char m_Save;


	int m_DataType[15];
    CString m_gettime;
	CString m_str,m_findstr;
	int m_incpoint;
	float m_oldsigle;
	int m_bul;
	int m_showBu;
	int m_showA;
	CButton *m_button;
	int m_start;
	int m_break;
	long int m_siv[15];
	int m_rep1;
	int m_rep2;
	int m_cB;
// Dialog Data
	//{{AFX_DATA(CFirstTGDlg)
	enum { IDD = IDD_FIRSTTG_DIALOG };
	CComboBox	m_COM;
	CComboBox	m_stop;
	CComboBox	m_data;
	CComboBox	m_rate;
	CStatic	m_Rect1;
	CStatic	m_RECT;
	CSliderCtrl	m_slider3;
	CSliderCtrl	m_slider2;
	CSliderCtrl	m_slider1;
	CComboBox	m_find;
	CComboBox	m_TGDataT;
	CComboBox	m_TGName;
	CAdodc1	m_adodc;
	CDataGrid1	m_grid;
	CString	m_listN;
	CString	m_showType;
	CMSComm	m_commCtrl;
	CString	m_CStoCH;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFirstTGDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
//    CMSComm m_ComPort;

	// Generated message map functions
	//{{AFX_MSG(CFirstTGDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Onconnect();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnStop();
	afx_msg void OnDelete();
	afx_msg void OnChack();
	afx_msg void OnSetDataT();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnShow();
	afx_msg void OnShowWave();
	afx_msg void OnSetCOM();
	afx_msg void OnOnCommMscomm1();
	afx_msg void OnCommSend();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIRSTTGDLG_H__F3DCD829_2240_4AEF_B213_90AB8C0D61B3__INCLUDED_)
