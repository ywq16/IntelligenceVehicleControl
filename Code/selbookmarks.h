#if !defined(AFX_SELBOOKMARKS_H__959363FB_4890_4779_9878_D8AF33172E9B__INCLUDED_)
#define AFX_SELBOOKMARKS_H__959363FB_4890_4779_9878_D8AF33172E9B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.

/////////////////////////////////////////////////////////////////////////////
// CSelBookmarks wrapper class

class CSelBookmarks : public COleDispatchDriver
{
public:
	CSelBookmarks() {}		// Calls COleDispatchDriver default constructor
	CSelBookmarks(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSelBookmarks(const CSelBookmarks& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetCount();
	VARIANT GetItem(const VARIANT& Index);
	void Remove(const VARIANT& Index);
	void Add(const VARIANT& Bookmark);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELBOOKMARKS_H__959363FB_4890_4779_9878_D8AF33172E9B__INCLUDED_)
