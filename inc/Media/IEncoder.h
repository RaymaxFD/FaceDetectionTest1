
#pragma once

#include "imedia.h"
#include "..\ibase.h"

class IBufferPool;
class IEncoder_V1 : public IMedia
{
public:
	virtual void SetBufferpoolEncoded(IBufferPool* p) = 0;

	virtual void SetVideoStreamTypeUNDEF() = 0;
	virtual void SetVideoStreamTypeUNCOMPRESSED() = 0;
	virtual void SetVideoStreamTypeMPEG1() = 0;
	virtual void SetVideoStreamTypeMPEG2() = 0;
    virtual void SetVideoStreamTypeMPEG4() = 0;
    virtual void SetVideoStreamTypeH261() = 0;
    virtual void SetVideoStreamTypeH263() = 0;
    virtual void SetVideoStreamTypeH264() = 0;
    virtual void SetVideoStreamTypeDIGITAL_VIDEO_SD() = 0;
    virtual void SetVideoStreamTypeDIGITAL_VIDEO_50() = 0;
    virtual void SetVideoStreamTypeDIGITAL_VIDEO_HD() = 0;
    virtual void SetVideoStreamTypeDIGITAL_VIDEO_SL() = 0;
    virtual void SetVideoStreamTypeWMV() = 0;
    virtual void SetVideoStreamTypeMJPEG() = 0;
    virtual void SetVideoStreamTypeYV12() = 0;
    virtual void SetVideoStreamTypeVC1() = 0;
    virtual void SetVideoStreamTypeAVS() = 0;

	virtual void SetImgDimension(Ipp32s w, Ipp32s h) = 0;
	virtual void SetFrameRate(Ipp64f  rate) = 0;
	virtual void SetBitRate(Ipp32s  bitrate) = 0;
	virtual void SetMaxFrames(Ipp32s max) = 0;
};