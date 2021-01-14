
#pragma once

#include "ibase.h"

class IBuffer;
class IImgFile : public IBase
{
public:
	virtual bool New(size_t lWidth, size_t lHeight, size_t lDepth, BYTE* pImg = NULL) = 0;
	virtual bool Load(TCHAR* pStrFile) = 0;
	virtual bool Save(TCHAR* pStrFile) = 0;
	virtual bool SetImage(BYTE* pImg, size_t lWidth, size_t lHeight, size_t lDepth) = 0;

public:
	// GetBuffer -> GetImage·Î ¹Ù²Þ
	virtual BYTE* GetImage() = 0;
	virtual bool GetImage(IBuffer** pIBuff) = 0;
	virtual size_t GetWidth() = 0;
	virtual size_t GetHeight() = 0;
	virtual size_t GetDepth() = 0;
	virtual size_t GetImgSize() = 0;
	virtual void GetDimension(size_t& nWidth, size_t& nHeight, size_t& nDepth) = 0;
	virtual bool IsNull() = 0;

public:
	virtual bool GetPallette(RGBQUAD pallette[]) = 0;
};