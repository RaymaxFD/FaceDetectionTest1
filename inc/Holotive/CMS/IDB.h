

#pragma once
#include <IBase.h>
#include <tchar.h>

class IBuffer;

struct _stScheduler
{
	int iID;
	int iIDXML;
	int iIDMedia;
};

struct _stClient
{
	_stClient(){}
	_stClient(const _stClient &T)
	{
		iID = T.iID;
		_tcscpy_s(strName, MAX_PATH, T.strName);
		_tcscpy_s(strPass, MAX_PATH, T.strPass);
		iIDXML = T.iIDXML;
		_tcscpy_s(strDesc, MAX_PATH, T.strDesc);
		iPosX = T.iPosX;
		iPosY = T.iPosY;
	}

	int iID;
	TCHAR strName[MAX_PATH];
	TCHAR strPass[MAX_PATH];
	int iIDXML;
	TCHAR strDesc[MAX_PATH];
	int iPosX;
	int iPosY;
	bool bDirty;
};

struct _stMedia
{
	_stMedia(){}
	_stMedia(const _stMedia &T)
	{
		iID = T.iID;
		_tcscpy_s(strFile, MAX_PATH, T.strFile);
	}

	int iID;
	TCHAR strFile[MAX_PATH];
};

struct _stXML
{
	_stXML(){}
	_stXML(const _stXML &T)
	{
		iID = T.iID;
		_tcscpy_s(strFile, MAX_PATH, T.strFile);
	}
	int iID;
	TCHAR strFile[MAX_PATH];
};

class IBufferPool;
class IString;
class IEvtDB_V1;

class IDB_V1 : public IBase
{
public:
	virtual void IEvtAdd(IEvtDB_V1* pI) = 0;
	virtual void IEvtRemove(IEvtDB_V1* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual bool Open(IString* pIStr) = 0;
	virtual void Close() = 0;

public:
	virtual void ScheduelrAdd(_stScheduler& st) = 0;
	virtual void SchedulerRemove(int iID) = 0;
	virtual void SchedulerQuery(IString* pIStr = NULL) = 0;
	virtual void SchedulerQuery(int iID) = 0;

public:
	virtual void ClientAdd(_stClient& st) = 0;
	virtual void ClientEdit(_stClient& st) = 0;
	virtual void ClientRemove(int iID) = 0;
	virtual void ClientQuery(IString* pIStr = NULL) = 0;
	virtual void ClientQuery(int iID) = 0;

public:
	virtual void XMLAdd(_stXML& st) = 0;
	virtual void XMLEdit(_stXML& st) = 0;
	virtual void XMLRemove(int iID) = 0;
	virtual void XMLQuery(IString* pIStr = NULL) = 0;
	virtual void XMLQuery(int iID) = 0;

public:
	virtual void MediaAdd(_stMedia& st) = 0;
	virtual void MediaRemove(int iID) = 0;
	virtual void MediaQuery(IString* pIStr = NULL) = 0;
	virtual void MediaQuery(int iID) = 0;

public:
	virtual void SetPool4Client(IBufferPool* pI) = 0;
	virtual void SetPool4XML(IBufferPool* pI) = 0;
	virtual void SetPool4Media(IBufferPool* pI) = 0;
	virtual void SetPool4Scheduler(IBufferPool* pI) = 0;
};

class IEvtDB_V1
{
public:
	virtual void IEvtDBSchedulerBegin(){}
	virtual void IEvtDBSchedulerEnd(){}
	virtual void IEvtDBScheduler(IBuffer* pIBuff){}

public:
	virtual void IEvtDBClientBegin(){}
	virtual void IEvtDBClientEnd(){}
	virtual void IEvtDBClient(IBuffer* pIBuff){}

public:
	virtual void IEvtDBXMLBegin(){}
	virtual void IEvtDBXMLEnd(){}
	virtual void IEvtDBXML(IBuffer* pIBuff){}

public:
	virtual void IEvtDBMediaBegin(){}
	virtual void IEvtDBMediaEnd(){}
	virtual void IEvtDBMedia(IBuffer* pIBuff){}
};