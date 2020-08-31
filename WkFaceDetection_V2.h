#pragma once

#include <Worker.h>
#include <Media/IMedia.h>
#include <StdIV.h>
#include <ImgProc.h>

class CWkFaceDetection_V2 : public CStdIV, public CWorker, public IMedia, public CImgProc
{
private:
	IMedia* m_pIDebug = nullptr;
public:
	void SetIMedia4Debug(IMedia* pI)
	{
		m_pIDebug = pI;
	}

public:
	DECLARE_WORKER;
public:
	CWkFaceDetection_V2();
protected:
	~CWkFaceDetection_V2();

protected:
	virtual void DoJob() override;
	virtual void DoMsgProc(MSG msg, void* pParam) override;
	virtual void DoMsgProc(UINT message, WPARAM wParam, LPARAM lParam, void* pParam) override;
	virtual void OnStartThread() override;
	virtual void OnStopThread() override;

protected:
	enum _eMsg
	{
		msgImageY = MSG_BASE,
		msgImageU,
		msgImageV,
	};

private:
	IBuffer* m_pIY = nullptr;
	IBuffer* m_pIU = nullptr;
	IBuffer* m_pIV = nullptr;
	size_t m_strideY = 0, m_strideUV = 0, m_nWidth = 0, m_nHeight = 0;
protected:
	virtual void NewVideoYUV(DWORD dwContextID, IBuffer* pIY, IBuffer* pIU, IBuffer* pIV, size_t strideY, size_t strideUV, size_t nWidth, size_t nHeight, _eYUV eYUV = eYUV420) override;

private:
	IColorConversion* m_pICC = nullptr;
	IArithmetic* m_pIArith = nullptr;
	IBuffer* m_pIBuffBk = nullptr;
	IBuffer* m_pIGrayThres = nullptr;
	IGeometry* m_pIGeo = nullptr;
	IThreshold* m_pIThres = nullptr;

private:
	IBufferPool* m_pIPool = nullptr;
public:
	void SetIBuffPool(IBufferPool* pI);
protected:
	bool DoFaceDetection();
	bool DoMotionDetection();

protected:
	void ShowDebugVideo(IBuffer* pIBuff, size_t nWidth, size_t nHeight, size_t nDepth);
};

