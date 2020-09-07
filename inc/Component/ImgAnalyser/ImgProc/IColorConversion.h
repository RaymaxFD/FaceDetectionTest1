

#pragma once
#include <ibase.h>
#include <media/frame_image.h>

class IBuffer;
class IColorConversion : public IBase
{
public:
	virtual bool ConvertYUV420ToRGB32(IBuffer* pIBufYUV, IBuffer* pIBufRGB, long nWidth,long nHeight, bool bUVorder = true) = 0;
	virtual bool ConvertYUV420ToRGB32(IBuffer* pIBufYUV, IBuffer* pIBufRGB, long nWidth,long nHeight, RECT rtROI, bool bUVorder = true) = 0;
	virtual bool ConvertYUV420ToRGB32(IBuffer* pIBufY, int iStepY, IBuffer* pIBufU, int iStepU, IBuffer* pIBufV, int iStepV, IBuffer* pIBufRGB, long nWidth,long nHeight, RECT rtROI) = 0;
	virtual bool ConvertYUV420ToRGB24(IBuffer* pIBufY, int iStepY, IBuffer* pIBufU, int iStepU, IBuffer* pIBufV, int iStepV, IBuffer* pIBufRGB, long nWidth, long nHeight, RECT rtROI) = 0;
	virtual bool ConvertYUV420ToRGB24(IBuffer* pIBufRGB, FrameYUV2& frame) = 0;

public:
	virtual bool ConvertYUV422PackedToRGB24(IBuffer* pIBufYUV, IBuffer* pIBufRGB, long nWidth,long nHeight) = 0;

public:
	virtual bool ConvertRGB32ToYUV420(IBuffer* pIBufRGB, FrameYUV2& frame) = 0;
	virtual bool ConvertRGB24ToYUV420(IBuffer* pIBufRGB, FrameYUV2& frame) = 0;

public:
	virtual bool RGB24ToGray(IBuffer* pIBufRGB, IBuffer* pIBufGray, long nWidth, long nHeight, RECT rtROI) = 0;
	virtual bool RGB32ToGray(IBuffer* pIBufRGB, IBuffer* pIBufGray, long nWidth, long nHeight, RECT rtROI) = 0;

public:
	virtual bool RGB24ToRGB32(IBuffer* pIBufRGB24, IBuffer* pIBufRGB32, size_t nWidth, size_t nHeight, RECT rtROI) = 0;
	virtual bool RGB32ToRGB24(IBuffer* pIBufRGB32, IBuffer* pIBufRGB24, size_t nWidth, size_t nHeight, RECT rtROI) = 0;

public:
	virtual bool SwapRGB(IBuffer* pIImg, long nWidth, long nHeight, long nPitch, int iDepth, int dstOrder[3]) = 0;
};
