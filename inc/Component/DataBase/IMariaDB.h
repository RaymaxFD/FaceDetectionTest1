

#pragma once

#include <IBase.h>

#include <string>

class IEvtMariaDB_V1;
class IMariaDB_V1 : public IBase
{
public:
	virtual void AddIEvent(IEvtMariaDB_V1* pI) = 0;
public:
	virtual bool Connect(TCHAR (&strServer)[MAX_PATH], TCHAR (&strUser)[MAX_PATH], TCHAR (&strPW)[MAX_PATH], TCHAR (&strDB)[MAX_PATH]) = 0;
	virtual bool Excute(TCHAR (&strSQL)[MAX_PATH], int iExcute = 0) = 0;
	virtual bool Query(int iQueryType, TCHAR (&strSQL)[MAX_PATH]) = 0;
	virtual void Disconnect() = 0;
};

class IEvtMariaDB_V1
{
public:
	virtual void OnError(std::string& str){}

public:
	virtual void OnConnect(){}

public:
	virtual void OnQuery(int iQueryType, int icnt){}
	virtual void OnQuery(int iIndex, std::string& str){}
	virtual void OnQueryNewRecord(int iRecord){}
	virtual void OnQueryNewRecordEnd(){}
	virtual void OnQueryEnd(){}

public:
	virtual void OnExcute(int iExcute){}
};
