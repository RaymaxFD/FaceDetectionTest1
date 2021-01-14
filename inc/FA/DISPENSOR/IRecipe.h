

#pragma once

#include <IBase.h>
#include <FA/Dispensor/IMotion.h>

#include <vector>
using namespace std;




// Recipe setup 용
class IRecipeEVT_V2;
class IRecipe_V2 : public IBase
{
public:
	enum _eState
	{
		eStateIdle,
		eStateMoldNew,
		eStateMoldEdit,
		eStateFrameNewRegular,
		eStateFrameEditRegular,
		eStateFrameNewIrregular,
		eStateFrameEditIrregular,
		eStateLoaded,
	};
public:
	struct _stDot
	{
		DWORD dwDelayStart;
		POINT pt;
		DWORD dwTimeRemain;
		DWORD dwDelayEnd;
	};
	struct _stLine
	{		
		DWORD dwDelayStart;
		POINT ptStart;
		POINT ptEnd;
		DWORD dwTimeMoving;
		DWORD dwDelayEnd;
	};
public:
	virtual void HomingDone() = 0;
	virtual void ReleaseSafeSensorError() = 0;


public:
	virtual bool IsRegularFile() = 0;

public:
	virtual bool IsStateIdle() = 0;
	virtual bool IsStateMold() = 0;
	virtual bool IsStateMoldNew() = 0;
	virtual bool IsStateMoldEdit() = 0;
	virtual bool IsStateFrame() = 0;
	virtual bool IsStateFrameNewRegular() = 0;
	virtual bool IsStateFrameNewIrregular() = 0;
	virtual bool IsStateFrameEditRegular() = 0;
	virtual bool IsStateFrameEditIrregular() = 0;
	virtual bool IsStateLoaded() = 0;

public:
	virtual bool Load(TCHAR* pStr) = 0;
	virtual void Save(TCHAR* pStr) = 0;

public:
	virtual void SetIMotion(IMotion_V1* pIMotion) = 0;
	virtual void AddIEvent(IRecipeEVT_V2* pI) = 0;
	virtual void SetRootMLD(TCHAR* pStr) = 0;
	virtual void SetRootFRM(TCHAR* pStr) = 0;
	virtual void SetRootRCP(TCHAR* pStr) = 0;

public:
	virtual bool CreateNewRecipe(TCHAR* pStrMold, TCHAR* pStrFrame, TCHAR* pStrRecipe) = 0;
	virtual bool GetFileNameRecipe(TCHAR* pStr, int iLen) = 0;
	virtual bool GetFileNameMold(TCHAR* pStr, int iLen) = 0;
	virtual bool GetFileNameFrame(TCHAR* pStr, int iLen) = 0;
public:
	virtual bool LoadMold(TCHAR* pStr) = 0;
	virtual bool LoadFrame(TCHAR* pStr) = 0;

	// mold 관련
public:
	virtual bool MoldNew() = 0;
	virtual bool MoldEdit() = 0;
	virtual void MoldNewCancel() = 0;
	virtual bool MoldSave(TCHAR* pStr) = 0;
	virtual void MoldPara(BYTE ucPara) = 0;
	virtual void MoldLightSet(BYTE ucLight) = 0;
	virtual BYTE MoldLightGet() = 0;
	virtual void MoldNewEnd() = 0;
	virtual bool ReadMoldFile(TCHAR* pStr) = 0;
	virtual bool IsOpenMoldFile() = 0;
	virtual void GetMoldInfo(POINT& ptLeftTop, POINT& ptRightTop, POINT& ptLeftBelow, BYTE& ucPara) = 0;
	virtual POINT Get1stFrameCenter() = 0;                                                          // 좌측 몰드 가장 위 frame의 중심. 자동으로 계산을 하여 줌. pulse 단위. mold 파일의 정보로부터 만들어진다.
	virtual void AcceptNowPositionLeftTop() = 0;
	virtual void AcceptNowPositionRightTop() = 0;
	virtual void AcceptNowPositionLeftMiddle() = 0;
	virtual void SetPositionLeftTop(POINT pt) = 0;
	virtual void SetPositionRightTop(POINT pt) = 0;
	virtual void SetPositionLeftMiddle(POINT pt) = 0;

	// frame 관련
public:
	virtual bool FrameNewRegular(POINT ptCircleLeftTop, POINT ptCircleRightTop, POINT ptCircleLeftBelow, BYTE ucPara) = 0;
	virtual bool FrameEditRegular(POINT ptCircleLeftTop, POINT ptCircleRightTop, POINT ptCircleLeftBelow, BYTE ucPara, TCHAR (&strFrame)[MAX_PATH]) = 0;
	virtual void FrameNewRegularAcceptLTCirclePos() = 0;
	virtual void FrameNewRegularCancel() = 0;
	virtual bool FrameNewRegularSave(TCHAR* pStr) = 0;
	virtual void FrameNewRegularSetRowCol(BYTE ucRow, BYTE ucCol) = 0;                              // 한 frame에서 제품의 행렬 수 저장
	virtual void FrameNewRegularGetRowCol(BYTE& ucRow, BYTE& ucCol) = 0;                            // 한 frame에서 제품의 행렬 수 읽기
	virtual void FrameNewRegularSetPitch(double dXmm, double dYmm) = 0;                             // 제품간 x/y pitch. mm 단위. 저장
	virtual void FrameNewRegularGetPitch(double& dXmm, double& dYmm) = 0;                           // 제품간 x/y pitch. mm 단위. 읽기
	virtual void FrameNewRegularSetOffset(double dXmm, double dYmm) = 0;                            // frame 중심에서 첫 번째 제품까지의 x/y 거리. mm 단위. 저장
	virtual void FrameNewRegularGetOffset(double& dXmm, double& dYmm) = 0;                          // frame 중심에서 첫 번째 제품까지의 x/y 거리. mm 단위. 읽기
	virtual void FrameNewRegularSetLight(BYTE ucLight) = 0;
	virtual void FrameNewRegularGetLight(BYTE& ucLight) = 0;
	virtual bool Get1stProdCenter(POINT& pt) = 0;                                                   // 좌측 몰드 가장 위 frame에서 첫 번째 제품의 중심. pulse 단위
	virtual void FrameNewRegularInfoInputOk() = 0;	
public:
	virtual bool FrameEdit(TCHAR* pStrFile) = 0;
public:
	virtual bool IsDot() = 0;
public:
	virtual bool FrameNewRegularLineMoveFirst() = 0;
	virtual bool FrameNewRegularLineGetNext(IRecipe_V2::_stLine& st) = 0;
	virtual void FrameNewRegularLineClear() = 0;
	virtual void FrameNewRegularLineAdd(IRecipe_V2::_stLine& st) = 0;
	virtual DWORD FrameNewRegularLineGetCount() = 0;
public:
	virtual bool FrameNewRegularDotMoveFirst() = 0;
	virtual bool FrameNewRegularDotGetNext(IRecipe_V2::_stDot& st) = 0;
	virtual void FrameNewRegularDotClear() = 0;
	virtual void FrameNewRegularDotAdd(IRecipe_V2::_stDot& st) = 0;

public:
	virtual bool FrameNewIrregular(POINT ptCircleLeftTop, POINT ptCircleRightTop, POINT ptCircleLeftBelow, BYTE ucPara) = 0;
	virtual bool FrameEditIrregular(POINT ptCircleLeftTop, POINT ptCircleRightTop, POINT ptCircleLeftBelow, BYTE ucPara, TCHAR (&strFrame)[MAX_PATH]) = 0;
	virtual void FrameNewIrregularAcceptLTCirclePos() = 0;
	virtual void FrameNewIrregularCancel() = 0;
	virtual bool FrameNewIrregularSave(TCHAR* pStr) = 0;
	virtual void FrameNewIrregularSetOffset(double dXmm, double dYmm) = 0;
	virtual void FrameNewIrregularGetOffset(double& dXmm, double& dYmm) = 0;
	virtual void FrameNewIrregularSetLight(BYTE ucLight) = 0;
	virtual void FrameNewIrregularGetLight(BYTE& ucLight) = 0;
public:
	virtual bool FrameNewIrregularLineMoveFirst() = 0;
	virtual bool FrameNewIrregularLineGetNext(IRecipe_V2::_stLine& st) = 0;
	virtual void FrameNewIrregularLineClear() = 0;
	virtual void FrameNewIrregularLineAdd(IRecipe_V2::_stLine& st) = 0;
	virtual DWORD FrameNewIrregularLineGetCount() = 0;
public:
	virtual void FrameNewIrregularHeightOk() = 0;
	virtual void FrameNewIrregularInfoInputOk() = 0;
public:
	virtual void FrameNewIrregularInputClear() = 0;
	virtual void FrameNewIrregularInputOffsetX(double dOffset) = 0;
	virtual void FrameNewIrregularInputOffsetY(double dOffset) = 0;
	virtual void FrameNewIrregularOffsetXMove2First() = 0;
	virtual bool FrameNewIrregularOffsetXGetNext(double& d) = 0;
	virtual long FrameNewIrregularOffsetXCount() = 0;
	virtual void FrameNewIrregularOffsetYMove2First() = 0;
	virtual bool FrameNewIrregularOffsetYGetNext(double& d) = 0;
	virtual long FrameNewIrregularOffsetYCount() = 0;

public:
	virtual void MoveToCenterOfFrame() = 0;

public:
	virtual void FrameGetZHeight(double& dUser, double& dMMD, double& dFrame) = 0;
	virtual void FrameSetZHeight(double dUser, double dMMD, double dFrame) = 0;
	virtual void FrameHeightOk() = 0;
};

class IRecipeEVT_V2
{
public:
	enum _eEvt
	{
		evtInReadyPos,
		evtLeftEmpty,
		evtFrameTeachingStart,
		evtFrameEditTeachingStart,
		evtFrameHeightTeachingStart,
		evtTeachLeftTopPin,
		evtEditWait4Start,

		evtLeftTopPinReady,
		evtInputOffsetX,
		evtErrorXPos,
		evtInputOffsetXOk,
		evtErrorYPos,
		evtInputDISPPath,
	};

public:
	virtual void OnEvtIRecipeV2(IRecipeEVT_V2::_eEvt e)                                                                  {}
};
































class IBuffer;
class IRecipeEVT_V1;
class IRecipe_V1 : public IBase
{
public:
	enum _eState
	{
		eEmpty,
		eLoad,
		eSetup,
		eEdit,
	};
	enum _eStage
	{
		eCircle,
		eProdRegion,
		eDIspencingPath,
	};

public:
	virtual bool IsEmpty() = 0;
	virtual bool IsLoad() = 0;
	virtual bool IsSetup() = 0;
	virtual bool IsEdit() = 0;

public:
	virtual void AddEvent(IRecipeEVT_V1* pI) = 0;

public:
	virtual void SetPathType(int iType) = 0; // 0 : 점, 1 : 선, 2 : 복합
	virtual void SetLight(BYTE ucLight) = 0;
	virtual void ResetRecipe() = 0;
	virtual void SetCenter(POINT pt) = 0;
	virtual void AddProdPosX(POINT pos) = 0;
	virtual void AddPath(int iMode,	/* 0 : 시작, 1 : 중간, 2 : 종료 */
		POINT ptPos, /* 현재 위치 */
		DWORD dwMovingTime, /* 현재 위치까지의 이동 시간. */
		DWORD dwRemainTime /* 현재 위치에서 머무르는 시간. */) = 0;
	virtual void AddPathOk() = 0;
public:
	virtual void GetPathType(int& iType) = 0; // 0 : 점, 1 : 선, 2 : 복합
	virtual void GetLight(BYTE& ucLight) = 0;
	virtual void GetCenter(POINT& pt) = 0;
	virtual bool GetProdFirst(POINT& pt) = 0;
	virtual bool GetProdNext(POINT& pt) = 0;
	virtual bool GetPathFirst(int& iMode,	/* 0 : 시작, 1 : 중간, 2 : 종료 */
		POINT& ptPos, /* 현재 위치 */
		DWORD& dwMovingTime, /* 현재 위치까지의 이동 시간. */
		DWORD& dwRemainTime /* 현재 위치에서 머무르는 시간. */) = 0;
	virtual bool GetPathNext(int& iMode,	/* 0 : 시작, 1 : 중간, 2 : 종료 */
		POINT& ptPos, /* 현재 위치 */
		DWORD& dwMovingTime, /* 현재 위치까지의 이동 시간. */
		DWORD& dwRemainTime /* 현재 위치에서 머무르는 시간. */) = 0;

public:
	virtual bool Load(TCHAR* pStrFile) = 0;
	virtual bool Save(TCHAR* pStrFile) = 0;
	virtual bool GetFileName(TCHAR* pStrFile, DWORD dwLen) = 0;
	virtual void Empty() = 0;

	//////////////////////////////////////
	// Recipe setup과 edit에 필요한 함수들

public:
	virtual bool StartNew() = 0;
	virtual void EndNew() = 0;
	virtual void CancelNew() = 0;

public:
	virtual bool StartEdit() = 0;
	virtual void EndEdit() = 0;
	virtual void CancelEdit() = 0;

public:
	virtual void XSpeed(DWORD dwSpeed) = 0;
	virtual bool XMove(bool bForward) = 0;
	virtual void XStop() = 0;

public:
	virtual IRecipe_V1::_eStage GetStage() = 0;

public:
	virtual bool Prev() = 0;
	virtual bool Next() = 0;

public:
	virtual void YSpeed(DWORD dwSpeed) = 0;
	virtual bool YMove(bool bForward) = 0;
	virtual void YStop() = 0;

public:
	
	virtual bool DISPPathGetFirst(int& iMode,	/* 0 : 시작, 1 : 중간, 2 : 종료 */
		POINT& ptPos, /* 현재 위치 */
		DWORD& dwMovingTime, /* 현재 위치까지의 이동 시간. */
		DWORD& dwRemainTime /* 현재 위치에서 머무르는 시간. */) = 0;
	virtual bool DISPPathGetNext(int& iMode,	/* 0 : 시작, 1 : 중간, 2 : 종료 */
		POINT& ptPos, /* 현재 위치 */
		DWORD& dwMovingTime, /* 현재 위치까지의 이동 시간. */
		DWORD& dwRemainTime /* 현재 위치에서 머무르는 시간. */) = 0;

	// Recipe setup과 edit에 필요한 함수들
	//////////////////////////////////////


	//////////////////////////////////
	// Motion 관련 함수들
	// 내부적으로 IMotion_V1을 이용함.
public:
	virtual void SetIMotion(IMotion_V1* pIMotion) = 0;
public:
	virtual long GetNowPosX() = 0;
	virtual long GetNowPosY() = 0;
	virtual long GetNowPosZ() = 0;
	virtual double GetmmPerPulse(DWORD dwPulse) = 0;

public:
	virtual void MoveInc(IMotion_V1::_eAxis eAxis, long lPos) = 0;
	virtual void MoveAbs(IMotion_V1::_eAxis eAxis, long lPos) = 0;
	virtual void MoveJog(IMotion_V1::_eAxis eAxis, IMotion_V1::_eDir eDir) = 0;
	virtual void MoveStop(IMotion_V1::_eAxis eAxis) = 0;
	virtual void MoveXYZ(long lPosX, long lPosY, long lPosZ) = 0;
	virtual void SetSpeed(IMotion_V1::_eAxis eAxis, DWORD dwSpeed) = 0;
	virtual void SetSpeed300(IMotion_V1::_eAxis eAxis, DWORD dwPercent) = 0;

public:
	virtual void Clamp(bool bOn) = 0;
	// Motion 관련 함수들
	// 내부적으로 IMotion_V1을 이용함.
	//////////////////////////////////
};

class IRecipeEVT_V1
{
public:
	enum _eError
	{
		eErrDepth,
		eErrMatchingNumOver,
		eErrMatchingNumZero,
		eErrXPitchEmpty,
		eErrYPitchEmpty,
		eErrPatternNotFound,
	};
	enum _eEvent
	{

		// New Recipe
		eEvtNewRecipeStarted,
		eEvtNewRecipeEnd,
		eEvtNewRecipeCancel,

		// Edit Recipe
		eEvtEditRecipeStarted,
		eEvtEditRecipeEnd,
		eEvtEditRecipeCancel,

		// stage
		eEvtStageChanged,
	};

public:
	virtual void OnEvtRecipe(IRecipeEVT_V1::_eEvent e) = 0;
	virtual void OnEvtError(IRecipeEVT_V1::_eError e) = 0;
};
