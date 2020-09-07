

#pragma once
#include <ibase.h>
#include <Media/frame_image.h>

class IBuffer;
class IImageUtil : public IBase
{
public:
	virtual bool SwapChannel3To4(IBuffer* pSrc, IBuffer* pDst, DWORD dwWidth, DWORD dwHeight) = 0;
	virtual bool SwapChannel4To3(IBuffer* pSrc, IBuffer* pDst, DWORD dwWidth, DWORD dwHeight) = 0;

	virtual bool CopyImage(IBuffer* pIDst, size_t strideDst, IBuffer* pISrc, size_t strideSrc, size_t nWidth, size_t nHeight, size_t nDepth) = 0;
	virtual bool CopyImage(FrameRGB& src, FrameRGB& dst, RECT rtROI) = 0;
};
