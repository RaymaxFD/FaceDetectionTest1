#pragma once

#include <Component\stdych\IBufferPool.h>
#include <Media/IMedia.h>

enum YUV_FORMAT {yuv_420, yuv_422};

struct FrameYUV
{
	unsigned char* Y;
	unsigned char* U;
	unsigned char* V;

	int width;
	int height;

	int strideY;
	int strideCRCB;


	YUV_FORMAT format;
};

class IBuffer;
class FrameYUV2
{
public:
	FrameYUV2() {}
	FrameYUV2(IBuffer* pIY, IBuffer* pIU, IBuffer* pIV, size_t width, size_t height, size_t strideY, size_t strideUV, IMedia::_eYUV format)
		: Y(pIY), U(pIU), V(pIV), width(width), height(height), strideY(strideY), strideCRCB(strideUV), format(format)
	{}
public:
	IBuffer* Y;
	IBuffer* U;
	IBuffer* V;

	size_t width;
	size_t height;

	size_t strideY;
	size_t strideCRCB;


	IMedia::_eYUV format;

	void AddRef()
	{
		Y->AddRef();
		U->AddRef();
		V->AddRef();
	}
	void Release()
	{
		Y->Release();
		U->Release();
		V->Release();
	}
};

struct FrameRGB
{
	IBuffer * pIBuf;
	size_t nWidth;
	size_t nHeight;
	size_t nDepth;

	void AddRef()
	{
		pIBuf->AddRef();
	}

	void Release()
	{
		pIBuf->Release();
	}
};

struct FrameVideo
{
	DWORD dwContextID;
	IBuffer* pVideo;
	bool bIFrame;
	long lSec;
	long lUSec;
	IMedia::_eCodecVideo eCodec;

	void AddRef()
	{
		pVideo->AddRef();
	}

	void Release()
	{
		pVideo->Release();
	}
};