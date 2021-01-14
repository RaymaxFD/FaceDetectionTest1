
#pragma once
#include <IBase.h>
#include <debug.h>
#include <stdint.h>

class IBase;
class IBuffer;

class IMedia
{
public:
	enum _eCodecVideo
	{
		eUnknown = 0,
		eJpeg,
		eH264,
		eH265,
		eIV50,
		eDIB,
		eMSVC,
		eMPG1,
		eMPG4,
	};
	enum _eCodecSound
	{
	};
	enum _eYUV
	{
		eYUV420,
		eYUV411,
		eYUV422,
		eYUV422Packed,
		eYUV444,
	};
	enum _eColorFormat
	{
		eColorRGB,
		eColorYUV,
	};

public:
	virtual IMedia* GetIMedia(IBase* pISender = NULL) { return (IMedia*)this;}
	virtual bool RemoveSender(IBase* pIReceiver) {	/*ASSERT(0);*/    return false;	}

	virtual void NewVideoRGB(DWORD dwContextID, IBuffer * pIBuf, size_t nWidth, size_t nHeight, size_t nDepth)	{}
	virtual void NewVideoYUV(DWORD dwContextID, IBuffer* pIY, IBuffer* pIU, IBuffer* pIV, size_t strideY, size_t strideUV, size_t nWidth, size_t nHeight, _eYUV eYUV = eYUV420) {}
	virtual void NewVideo(DWORD dwContextID, IBuffer* pVideo, bool bIFrame, long lSec, long lUSec, _eCodecVideo eCodec) {}
	
	virtual void NewVideo(DWORD dwContextID, IBuffer* pVideo, bool bIFrame, _eCodecVideo eCodec) {}
	virtual void NewVideoYUV(DWORD dwContextID, BYTE* pY, BYTE* pU, BYTE* pV, size_t strideY, size_t strideUV, size_t nWidth, size_t nHeight, _eYUV eYUV = eYUV420) {}
	virtual void NewSound(DWORD dwContextID, IBuffer* pSound, _eCodecSound eCodec) {}
	virtual void NewMic(DWORD dwContextID, IBuffer* pMic, _eCodecSound eCodec) {}

	virtual void IMediaAdd(IMedia* p)	{ }
	virtual void IMediaRemove(IMedia* p)	{ }
	virtual void IMediaReset(){}

	virtual void IMediaAddRef() {  };
	virtual void IMediaRelease() {  };
	virtual long IMediaGetRefCnt() { return 0; };
};
