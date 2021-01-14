
#pragma once

#include <IBaseGUID.h>
#include "media/imedia.h"
#include <IWorker.h>
#include <stddef.h>
#include <vfw.h>

class IBufferPool;
class IString;

class IFilePlayerEVT_V1;
class IFilePlayerEVT_V2;
class IFilePlayer_V1 : public IWorker
{
public:
	virtual bool SetIEvent(IFilePlayerEVT_V1* p) = 0;
	virtual void RemoveIEvent() = 0;

public:
	virtual bool Open(TCHAR* pStrFile, bool bAVI) = 0;
	virtual void Close() = 0;
	virtual bool Play() = 0;
	virtual bool Pause() = 0;
	virtual bool Stop() = 0;
	virtual bool IsOpened() = 0;

public:
	virtual void AddMediaOutput(IMedia* p) = 0;
	virtual bool SetIBufferPool(IBufferPool* pI) = 0;

public:
	virtual void SetContextID(DWORD dw) = 0;
};

class IFilePlayer_V2 : public IWorker
{
public:
	virtual void AddIEvent(IFilePlayerEVT_V2* pEvt) = 0;
	virtual void RemoveIEvent(IFilePlayerEVT_V2* pEvt) = 0;

public:
	virtual bool Open(TCHAR* pStrFile) = 0;
	virtual void Close() = 0;
	virtual bool Play() = 0;
	virtual void Stop() = 0;
	virtual bool IsOpen() = 0;

public:
	virtual void AddMediaOutput(IMedia* pM) = 0;
	virtual void RemoveMediaOutput(IMedia* pM) = 0;
	virtual void ResetMediaOutput() = 0;
	virtual size_t GetMediaOutputCnt() = 0;

public:
	virtual void SetIBufferPool(IBufferPool* pI) = 0;

public:
	virtual void SetContextID(DWORD dwID) = 0;

public:
	virtual double GetRotation() = 0;
};

class IFilePlayerEVT_V1
{
public:
	enum _eErrorCode
	{
		eFileOpend = 0,
		eFileOpenFail,
	};

public:
	virtual void AddRef() = 0;
	virtual void Release() = 0;
	virtual long GetRefCnt() = 0;

public:
	virtual void EvtIPlayerError(_eErrorCode e)	{}
	virtual void EvtIPlayerPlay()	{}
	virtual void EvtIPlayerStop()	{}
	virtual void EvtIPlayerPause()	{}
	virtual void EvtIPlayerOpen()	{}
	virtual void EvtIPlayerClose()	{}
	virtual void EvtIPlayerDone()	{}
};

class IFilePlayerEVT_V2
{
public:
	enum _eErrorCode
	{
		eFileOpend = 0,
		eFileOpenFail,
	};

public:
	virtual void EvtIPlayerError(_eErrorCode e)	{}
	virtual void EvtIPlayerPlay()	{}
	virtual void EvtIPlayerStop()	{}
	virtual void EvtIPlayerPause()	{}
	virtual void EvtIPlayerOpen()	{}
	virtual void EvtIPlayerClose()	{}
	virtual void EvtIPlayerDone()	{}
};

class IEvtFilePlayer_V3;
class IFilePlayer_V3 : public IWorker
{
public:
	virtual void SetIBufferPool(IBufferPool* pI) = 0;

public:
	virtual bool player_open(char *file) = 0;
	virtual void player_close() = 0;
	virtual void player_play() = 0;
	virtual void player_pause() = 0;
	virtual void player_seek(int64_t ms, int type) = 0;
	virtual void player_setrect(int type, int x, int y, int w, int h) = 0; // type: 0 - video rect, 1 - visual effect rect
	virtual int player_snapshot(char *file, int w, int h, int waitt) = 0;
	virtual int player_record(char *file) = 0;
	virtual void player_setparam(int id, void *param) = 0;
	virtual void player_getparam(int id, void *param) = 0;
	virtual void ParamRead(char* strIni) = 0;
	virtual void ParamWrite(char* strIni) = 0;

public:
	virtual void IEvtAdd(IEvtFilePlayer_V3* pI) = 0;
	virtual void IEvtRemove(IEvtFilePlayer_V3* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void IMediaAdd(IMedia* pM) = 0;
	virtual void IMediaRemove(IMedia* pM) = 0;
	virtual void IMediaReset() = 0;
};

class IEvtFilePlayer_V3
{
public:
	virtual void IEvtFFOpenDone() {}
	virtual void IEvtFFOpenFail() {}
	virtual void IEvtFFPlayCompleted() {}
	virtual void IEvtFFTakeSnapshot(IBuffer* pIImg, size_t nWidth, size_t nHeight, size_t nDepth) {}
};

class IEvtFilePlayer_V4;
class IFilePlayer_V4 : public IWorker
{
public:
	virtual void Play() = 0;
	virtual void Pause() = 0;
	virtual void Stop() = 0;
	virtual void VolumeUp() = 0;
	virtual void VolumeDoen() = 0;
	virtual void Mute() = 0;
	virtual void Rewind() = 0;
	virtual void Fast() = 0;
	virtual void OpenFile(TCHAR* pStrFile) = 0;
	virtual void SetHWND(HWND hWnd) = 0;
	virtual void OnSize() = 0;
	virtual void MoveWindow(WPARAM wParam, LPARAM lParam) = 0;
};

class IEvtFilePlayer_V4
{};

class IEvtFilePlayer_V5;
class IFilePlayer_V5 : public IWorker
{
public:
	virtual void SetContextID(DWORD dw) = 0;
	virtual void SetIBufferPool4RGB(IBufferPool* pI) = 0;

public:
	virtual void Play() = 0;
	virtual void Pause() = 0;
	virtual void Stop() = 0;
	virtual void VolumeUp() = 0;
	virtual void VolumeDoen() = 0;
	virtual void Mute() = 0;
	virtual void Rewind() = 0;
	virtual void Fast() = 0;
	virtual void OpenFile(TCHAR* pStrFile) = 0;

public:
	virtual void IEvtAdd(IEvtFilePlayer_V5* pI) = 0;
	virtual void IEvtRemove(IEvtFilePlayer_V5* pI) = 0;
	virtual void IEvtReset(IEvtFilePlayer_V5* pI) = 0;

public:
	virtual void IMediaAdd(IMedia* pI) = 0;
	virtual void IMediaRemove(IMedia* pI) = 0;
	virtual void IMediaReset() = 0;
};

class IEvtFilePlayer_V5
{
public:
	virtual void IEvtFilePlayBegin() {}
	virtual void IEvtFilePlayEnd() {}
};


class IEvtFilePlayer_V6;
class IFilePlayer_V6 : public IWorker, public IMedia
{

public:
	virtual void IEvtAdd(IEvtFilePlayer_V6* pI) = 0;
	virtual void IEvtRemove(IEvtFilePlayer_V6* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void SetContextID(DWORD dwContextID) = 0;
	virtual void SetBufferPool(IBufferPool* pIBuff) = 0;

public:
	virtual void SetMediaFileName(IString* pIStr) = 0;
	virtual IString* GetMediaFileName() = 0;
	virtual void Playing(bool bConn) = 0;
	virtual void PlayingPos(int iMin) = 0;
	virtual bool IsPlaying() = 0;
};

class IEvtFilePlayer_V6
{
public:
	enum _eErrorCode
	{
	};
public:
};