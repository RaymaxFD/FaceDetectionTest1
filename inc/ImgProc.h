#pragma once

#include <IBaseDll.h>
#include <IBaseGUID.h>
#include <IV_Macro.h>

#include <Component/ImgAnalyser/ImgProc/IColorConversion.h>
#include <Component/ImgAnalyser/ImgProc/IGeometry.h>
#include <Component/ImgAnalyser/Imgproc/IImgFile.h>
#include <Component/ImgAnalyser/Imgproc/IVideoPostProc.h>
#include <Component/ImgAnalyser/Imgproc/IImageUtil.h>
#include <Component/ImgAnalyser/ImgProc/IArithmetic.h>
#include <Component/ImgAnalyser/ImgProc/IThreshold.h>

class CImgProc
{
public:
	CImgProc()
		: m_hInstImgProc(NULL)
	{}
	~CImgProc()
	{}

private:
	HINSTANCE m_hInstImgProc;

public:
	IColorConversion* _GetICC()
	{
		IMPLEMENT_IBASE;

		IColorConversion* pI = NULL;
		IV_GET_IF(m_hInstImgProc, ID_DLL_IMGPROC, ID_IMGPROC_COLORCONVERSION, IColorConversion, pI);

		return pI;
	}
	IGeometry* _GetIGeo()
	{
		IMPLEMENT_IBASE;

		IGeometry* pI = NULL;
		IV_GET_IF(m_hInstImgProc, ID_DLL_IMGPROC, ID_IMGPROC_GEOMETRY, IGeometry, pI);

		return pI;
	}
	IImgFile* _GetIImgFile()
	{
		IMPLEMENT_IBASE;

		IImgFile* pI = NULL;
		IV_GET_IF(m_hInstImgProc, ID_DLL_IMGPROC, ID_IMGPROC_IMGFILE, IImgFile, pI);

		return pI;
	}
	IVideoPostProc* _GetIVideoPostProc()
	{
		IMPLEMENT_IBASE;

		IVideoPostProc* pI = NULL;
		IV_GET_IF(m_hInstImgProc, ID_DLL_IMGPROC, ID_IMGPROC_VIDEOPOSTPROC, IVideoPostProc, pI);

		return pI;
	}
	IImageUtil* _GetIImgUtil()
	{
		IMPLEMENT_IBASE;

		IImageUtil* pI = NULL;
		IV_GET_IF(m_hInstImgProc, ID_DLL_IMGPROC, ID_IMGPROC_IMAGEUTIL, IImageUtil, pI);

		return pI;
	}
	IArithmetic* _GetIArithmetic()
	{
		IMPLEMENT_IBASE;

		IArithmetic* pI = NULL;
		IV_GET_IF(m_hInstImgProc, ID_DLL_IMGPROC, ID_IMGPROC_ARITHMETIC, IArithmetic, pI);

		return pI;
	}
	IThreshold* _GetIThres()
	{
		IMPLEMENT_IBASE;

		IThreshold* pI = NULL;
		IV_GET_IF(m_hInstImgProc, ID_DLL_IMGPROC, ID_IMGPROC_THRESHOLD, IThreshold, pI);

		return pI;
	}

	void SaveImgFile(TCHAR* pStrFile, IBuffer* pIBuff, size_t nWidth, size_t nHeight, size_t nDepth)
	{
		IImgFile* pIImgFile = _GetIImgFile();
		pIImgFile->New(nWidth, nHeight, nDepth, pIBuff->GetBuffer());
		pIImgFile->Save(pStrFile);
		IV_RELEASE(pIImgFile);
	}
};
