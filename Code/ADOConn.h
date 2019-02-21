// ADOConn.h: interface for the ADOConn class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONN_H__ED0C08CC_37A3_44B2_8300_BD142C50C645__INCLUDED_)
#define AFX_ADOCONN_H__ED0C08CC_37A3_44B2_8300_BD142C50C645__INCLUDED_

//#pragma warning(disable:4146)
#import "C:\Program Files\Common Files\System\ado\msado15.dll"no_namespace \
	rename("EOF","adoEOF")rename("BOF","adoBOF")rename("DataTypeEnum","adoDataTypeEnum")rename("FieldAttributeEnum", "adoFielAttributeEnum")rename("LockTypeEnum", "adoLockTypeEnum")rename("EditModeEnum", "adoEditModeEnum")rename("RecordStatusEnum", "adoRecordStatusEnum")rename("ParameterDirectionEnum", "adoParameterDirectionEnum")

//#pragma warning(default:4146)
//using namespace ADODB;
/*
#pragma warning(disable:4146)
#import "C:/Program Files/Common Files/System/ado/msado15.dll" /
no_namespace /
rename("EOF","adoEOF") rename("DataTypeEnum","adoDataTypeEnum") /
rename("FieldAttributeEnum", "adoFielAttributeEnum") rename("EditModeEnum", "adoEditModeEnum") /
rename("LockTypeEnum", "adoLockTypeEnum") rename("RecordStatusEnum", "adoRecordStatusEnum") /
rename("ParameterDirectionEnum", "adoParameterDirectionEnum")
*/
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ADOConn  
{
public:
	BOOL ExecuteSQL(_bstr_t bstrSQL);
	_RecordsetPtr& GetRecordSet(_bstr_t bstrSQL);
	void ExitConnect();
	void OnInitADOConn();
	ADOConn();
	virtual ~ADOConn();
    _ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;

};

#endif // !defined(AFX_ADOCONN_H__ED0C08CC_37A3_44B2_8300_BD142C50C645__INCLUDED_)
