
#pragma once
#include "ibase.h"

class IBuffer;
class IGeometry : public IBase
{
public:
	virtual bool Resize(IBuffer* pBufOrg, IBuffer* pBufDest, size_t nWidthOrg, size_t nHeightOrg, size_t nWidthDest, size_t nHeightDest, size_t nDepth) = 0;
	virtual bool Resize32(IBuffer* pBufOrg, IBuffer* pBufDest, size_t nWidthOrg, size_t nHeightOrg, size_t nWidthDest, size_t nHeightDest) = 0;
	virtual bool Resize24(IBuffer* pBufOrg, IBuffer* pBufDest, size_t nWidthOrg, size_t nHeightOrg, size_t nWidthDest, size_t nHeightDest) = 0;
	virtual bool Resize8(IBuffer* pBufOrg, IBuffer* pBufDest, size_t nWidthOrg, size_t nHeightOrg, size_t nWidthDest, size_t nHeightDest) = 0;

public:
	virtual bool MirrorVertical(IBuffer* pIBufOrg, IBuffer* pIBufDest, size_t nWidth, size_t nHeight, size_t nDepth) = 0;
	virtual bool MirrorVertical32(IBuffer* pIBufOrg, IBuffer* pIBufDest, size_t nWidth, size_t nHeight) = 0;
	virtual bool MirrorVertical24(IBuffer* pIBufOrg, IBuffer* pIBufDest, size_t nWidth, size_t nHeight) = 0;
	virtual bool MirrorVertical8(IBuffer* pIBufOrg, IBuffer* pIBufDest, size_t nWidth, size_t nHeight) = 0;
public:
	virtual bool MirrorHorizontal(IBuffer* pIBufOrg, IBuffer* pIBufDest, size_t nWidth, size_t nHeight, size_t nDepth) = 0;
	virtual bool MirrorHorizontal32(IBuffer* pIBufOrg, IBuffer* pIBufDest, size_t nWidth, size_t nHeight) = 0;
	virtual bool MirrorHorizontal24(IBuffer* pIBufOrg, IBuffer* pIBufDest, size_t nWidth, size_t nHeight) = 0;
	virtual bool MirrorHorizontal8(IBuffer* pIBufOrg, IBuffer* pIBufDest, size_t nWidth, size_t nHeight) = 0;
public:
	virtual bool MirrorBoth32(IBuffer* pIBufOrg, IBuffer* pIBufDest, size_t nWidth, size_t nHeight) = 0;

public:
	virtual bool Copy(IBuffer* pIBufSrc, IBuffer* pIBufDst, SIZE szSrc, SIZE szDst, RECT rtROI, int iDepth) = 0;

public:
	virtual void Translate(double dX, double dY, double dZ, double& dOutX, double& dOutY, double& dOutZ, double dXmove, double dYmove, double dZmove) = 0;
	virtual void RotateX(double dThetaR, double dX, double dY, double dZ, double& dOutX, double& dOutY, double& dOutZ) = 0;
	virtual void RotateY(double dThetaR, double dX, double dY, double dZ, double& dOutX, double& dOutY, double& dOutZ) = 0;
	virtual void RotateZ(double dThetaR, double dX, double dY, double dZ, double& dOutX, double& dOutY, double& dOutZ) = 0;
	virtual void RotateImage(IBuffer* pIBufSrc, IBuffer* pIBufDst, size_t nWidth, size_t nHeight, size_t nDepth, double dDegree, RECT rtROI, RECT& rtDst) = 0;
	virtual void RotateImageIPP(IBuffer* pIBufSrc, IBuffer* pIBufDst, size_t nWidth, size_t nHeight, size_t nDepth, double dDegree, RECT rtROI, RECT& rtDst) = 0;
};