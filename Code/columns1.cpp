// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


#include "stdafx.h"
#include "columns1.h"

// Dispatch interfaces referenced by this interface
#include "Column1.h"


/////////////////////////////////////////////////////////////////////////////
// CColumns properties

/////////////////////////////////////////////////////////////////////////////
// CColumns operations

long CColumns::GetCount()
{
	long result;
	InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

CColumn CColumns::Add(short Index)
{
	LPDISPATCH pDispatch;
	static BYTE parms[] =
		VTS_I2;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_DISPATCH, (void*)&pDispatch, parms,
		Index);
	return CColumn(pDispatch);
}

CColumn CColumns::GetItem(const VARIANT& Index)
{
	LPDISPATCH pDispatch;
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&pDispatch, parms,
		&Index);
	return CColumn(pDispatch);
}

void CColumns::Remove(const VARIANT& Index)
{
	static BYTE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &Index);
}