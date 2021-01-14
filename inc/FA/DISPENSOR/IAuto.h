

#pragma once

#include <IBase.h>

class IBuffer;
class IBufferPool;
class IAutoEvt_V1;
class IRecipe_V1;
class IMotion_V1;
class IAutoEvt_V2;
class IRecipe_V2;


class IRecipe_V2;
class IAuto_V2 : public IBase
{
public:
	virtual void SetEditMode(bool b) = 0;

public:
	virtual void HomingDone() = 0;
	virtual void ReleaseSafeSensorError() = 0;

public:
	virtual DWORD GetAreaFound() = 0;

public:
	virtual void Enable(bool b) = 0;
	virtual void SetIMotion(IMotion_V1* pIMotion) = 0;
	virtual void SetImg4Scratch(IBufferPool* pI) = 0;
	virtual void SetTestRun(bool b) = 0;
	virtual void SetIRecipe(IRecipe_V2* pI) = 0;
	virtual void NewImage(IBuffer* pImg, DWORD dwWidth, DWORD dwHeight) = 0;
	virtual void ApplyManualCenter(DWORD dwX, DWORD dwY) = 0;

public:
	virtual void Need2ReTeachStart(bool bStart) = 0;
	virtual void Need2ReTeachEnd() = 0;
	virtual void Need2ReTeachCancel() = 0;
	virtual void Need2ReTeachGet1stCenter(POINT& pt) = 0;

public:
	virtual void Need2RePosZStart(bool bStart) = 0;
	virtual void Need2RePosZEnd() = 0;
	virtual void Need2RePosZCancel() = 0;

public:
	virtual void SetCircleRadiusMax(DWORD dw) = 0;
	virtual void SetCircleAreaRange(DWORD dwMin, DWORD dwMax) = 0;
	virtual void SetFindCircleFailCnt(DWORD dw) = 0;
	virtual void UseTipCleaning(bool bUse) = 0;
	virtual void SetTipClaeningHeight(double dHeight) = 0;
	virtual void Delay1stProd(DWORD dwDelay) = 0;

public:
	virtual void AddIEvent(IAutoEvt_V2* pI) = 0;

public:
	virtual bool IsReady() = 0;
	virtual bool IsStageUnlaunch() = 0;

public:
	virtual void StartAuto() = 0;
	virtual void StopAuto() = 0;

public:
	virtual DWORD GetJobCount() = 0;
	virtual void SetOffsetBetweenTipAndCamX(DWORD dwOffset) = 0;
	virtual void SetOffsetBetweenTipAndCamY(DWORD dwOffset) = 0;

public:
	virtual void GetImgDimension(DWORD& dwW, DWORD& dwH, DWORD& dwD) = 0;
};

class IAutoEvt_V2
{
public:
	enum _eEvt
	{
		evtNeedNewImg,
		evtLightOn,
		evtLightOff,
		evtFindCircleFail,
		evtFindCircleFailRetryCntOver,
		evtFindCircleFailSizeMin,
		evtFindCircleFailSizeMax,
		evtFindCircleFailRadius,
		evtFindCircleFailPos,
		evtFindCircleOK,
		evtUserCircleOk,
	};

public:
	virtual void EvtIAuto(_eEvt e)                                                                                                      {}
	virtual void EvtIAutoImgThreshold(IBuffer* pIBufImg, DWORD dwWidth, DWORD dwheight)                                                 {}
	virtual void EvtIAutoImgLabeling(IBuffer* pIBufImg, DWORD dwWidth, DWORD dwheight)                                                  {}

public:
	virtual void EvtIAutoSebaStart()                                                                                                    {}
	virtual void EvtIAutoSebaStop()                                                                                                     {}
	virtual void EvtIAutoCamLightChange(BYTE ucLight)                                                                                   {}
	virtual void EvtIAutoStart()                                                                                                        {}
	virtual void EvtIAutoStop()                                                                                                         {}
	virtual void EvtIAutoFindCircleStart()                                                                                              {}
	virtual void EvtIAutoFindCircleEnd()                                                                                                {}
	virtual void EvtIAutoBeginLeft()                                                                                                    {}
	virtual void EvtIAutoBeginRight()                                                                                                   {}
	virtual void EvtIAutoActionStart()                                                                                                  {}
	virtual void EvtIAutoActionStop()                                                                                                   {}
	virtual void EvtIAutoMoveDownImpossible()                                                                                           {}
	virtual void EvtIAutoNeed2ReTeach()                                                                                                 {}
	virtual void EvtIAutoNeed2RePosZ()                                                                                                  {}
	virtual void EvtIAutoNeed2ChangeCleaningCup()                                                                                       {}
	virtual void EvtIAutoLeftMoldEmpty()                                                                                                {}
	virtual void EvtIAutoFindCircle()                                                                                                   {}
	virtual void EvtIAutoDispensingStart()                                                                                              {}
	virtual void EvtIAutoDispensingEnd()                                                                                                {}
	virtual void EvtIAutoProdOk()                                                                                                       {}
};


























class IAuto_V1 : public IBase
{
public:
	enum _eState
	{
		eIdle,
		eRunning,
		eError,
	};
public:
	virtual void Enable(bool b) = 0;

public:
	virtual void SetIRecipe(IRecipe_V1* pI) = 0;
	virtual bool Load(TCHAR* pStrFile) = 0;

public:
	virtual void SetIMotion(IMotion_V1* pI) = 0;

public:
	virtual bool StartAuto() = 0;
	virtual void StopAuto() = 0;

public:
	virtual void SetTestRun(bool b) = 0;
	virtual void SetCircleCenterLeft(int iPos, POINT pt) = 0;
	virtual void SetCircleCenterRight(int iPos, POINT pt) = 0;
	virtual void NewImage(IBuffer* pImg, DWORD dwWidth, DWORD dwHeight) = 0;
	virtual void SetImg4Scratch(IBufferPool* pI) = 0;

public:
	virtual void GetImgDimension(DWORD& dwWidth, DWORD& dwHeight, DWORD& dwDepth) = 0;

public:
	virtual void SetThresHold(BYTE ucThres) = 0;
public:
	virtual void UserConditionApply() = 0;
	virtual void UserConditionTest() = 0;

public:
	virtual void AddIEvent(IAutoEvt_V1* pI) = 0;

public:
	virtual bool IsDISP() = 0; // µð¹ö±ë¿ë!!!!! ³ªÁß¿¡ Áö¿ì»ï!!!!!!!!!!!
};

class IAutoEvt_V1
{
public:
	enum _eEvt
	{
		evtNeedNewImg,
		evtFindCircleFail,
		evtUserParamOk,
	};

public:
	virtual void EvtIAuto(_eEvt e)                                                                                                      {}
	virtual void EvtIAutoImgThreshold(IBuffer* pIBufImg, DWORD dwWidth, DWORD dwheight)                                                 {}
	virtual void EvtIAutoImgLabeling(IBuffer* pIBufImg, DWORD dwWidth, DWORD dwheight)                                                  {}

public:
	virtual void EvtIAutoSebaStart()                                                                                                    {}
	virtual void EvtIAutoSebaStop()                                                                                                     {}
	virtual void EvtIAutoCamLightChange(BYTE ucLight)                                                                                   {}
};