
#pragma once

#include <IBase.h>
#include <media/IMedia.h>
#include <WideSight/IDB.h>
#include <Component/ImgAnalyser/IWideAngle360.h>
#include <Component/IPCams/ICamera.h>

#define MAX_DATE		20
#define FILE_BEGIN_DATA	34000

class IEvtPlaying_V1;
class IEvtPlaying_V2;
class IDB_V1;
class IBufferPool;
class IMedia;

class IPlaying_V1 : public IBase, public IMedia
{
public:
	virtual void SetHWND(int i, HWND hWnd) = 0;

public:
	virtual void AddIEvent(IEvtPlaying_V1* pI) = 0;
	virtual void RemoveIEvent(IEvtPlaying_V1* pI) = 0;
	virtual void ResetIEvent(IEvtPlaying_V1* pI) = 0;

public:
	virtual void SetIPool4Reading(IBufferPool* pI) = 0;

public:
	virtual bool MediaOpen(IDB_V1::_stMedia& stMedia) = 0;
	virtual void MediaClose() = 0;

public:
	virtual void Play() = 0;
	virtual void Pause(bool bPause) = 0;
	virtual void Stop() = 0;

public:
	virtual void SetPlayingPos(IDB_V1::_stVideoPos& stVideoPos) = 0;
	virtual void SetNextEventPos(IDB_V1::_stVideoPos& stVideoPos) = 0;

public:
	virtual void IMediaAddPano(IMedia* pI) = 0;
	virtual void IMediaRemovePano(IMedia* pI) = 0;
	virtual void IMediaResetPano(IMedia* pI) = 0;

	virtual void IMediaAddFish(IMedia* pI) = 0;
	virtual void IMediaRemoveFish(IMedia* pI) = 0;
	virtual void IMediaResetFish(IMedia* pI) = 0;

	virtual void SetResolution(IWideAngle360_V7::_eResolution eResol) = 0;
	virtual void SetFishCenter(int iCenterX, int iCenterY) = 0;                                    // 어안 영상의 중심 설정
	virtual void GetFishCenter(int& iCenterX, int& iCenterY) = 0;                                  // 설정된 어안 영상의 중심 얻기
	virtual void SetFishDimension(DWORD dwFishWidth, DWORD dwFishHeight) = 0;                      // 어안 영상의 해상도 설정
	virtual void GetFishDimension(DWORD& dwFishWidth, DWORD& dwFishHeight) = 0;                    // 설정된 어안 영상의 해상도 얻기
	virtual void SetFOVDeg(double d) = 0;                                                          // 어안 영상의 화각 설정
	virtual void GetFOVDeg(double& d) = 0;                                                          // 어안 영상의 화각 설정
	virtual void SetLenzMaxRPixel(DWORD dw) = 0;                                                      // 어안 영상의 반지름 설정
	virtual void GetLenzMaxRPixel(DWORD& dw) = 0;                                                     // 설정된 어안 영상의 반지름 얻기
	virtual void SetLenzPixelSize(double d) = 0;                                                   // CCD나 CMOS의 픽셀 크기 설정
	virtual void GetLenzPixelSize(double& d) = 0;                                                   // CCD나 CMOS의 픽셀 크기 설정
	virtual void SetSphereR(double d) = 0;                                                         // 가상의 공간상의 구면 반지름.
	virtual void GetSphereR(double& d) = 0;                                                         // 가상의 공간상의 구면 반지름.
	virtual void SetOutSize(int iW, int iH) = 0;
	virtual void GetOutSize(int& iW, int& iH) = 0;
	virtual void SetCamModel(ICamModel::_eCamModel eModel) = 0;
	virtual void SetPanTiltAngle(int iChannel, int iPan, int iTilt) = 0;                        // 바라보는 Pan/Tilt 각도 설정. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.
	virtual void GetPanTiltAngle(int iChannel, int& iPan, int& iTilt) = 0;                      // 현재 설정된 Pan/Tilt 각도 읽기. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.

public:
	virtual void SetIBufferPool4Decoder(IBufferPool* pBuffDecoded, IBufferPool* pBuffFrame) = 0;
	virtual void SetIBufferPool4Out(IBufferPool* pI) = 0;
};

class IEvtPlaying_V1
{
public:
	virtual void EvtPlayerMediaOpenedV1(){}
	virtual void EvtPlayerMediaPlayBegin(){}
	virtual void EvtPlayerMediaPlayDone(){}
	virtual void EvtPlayerPosChanged(){}
};

class IPlaying_V2 : public IBase, public IMedia
{
public:
	virtual void SetHWND(int nNo, HWND hWnd) = 0;

public:
	virtual void AddIEvent(IEvtPlaying_V2* pI) = 0;
	virtual void RemoveIEvent(IEvtPlaying_V2* pI) = 0;
	virtual void ResetIEvent(IEvtPlaying_V2* pI) = 0;

public:
	virtual void SetIPool4Reading(IBufferPool* pI) = 0;

public:
	virtual bool MediaOpen(IDB_V2::_stMedia& stMedia) = 0;
	virtual void MediaClose() = 0;

public:
	virtual void Play() = 0;
	virtual void Pause(bool bPause) = 0;
	virtual void Stop() = 0;

public:
	virtual void SetPlayingPos(DWORD dwVideoPos) = 0;
	virtual void SetNextEventPos(DWORD dwVideoPos) = 0;

public:
	virtual int GetPlayingPosSize() = 0;

public:
	virtual void OnMediaParsingPosCnt() = 0;
	virtual void OnMediaParsingPos() = 0;

public:
	virtual void IMediaAddPano(IMedia* pI) = 0;
	virtual void IMediaRemovePano(IMedia* pI) = 0;
	virtual void IMediaResetPano(IMedia* pI) = 0;

	virtual void IMediaAddFish(IMedia* pI) = 0;
	virtual void IMediaRemoveFish(IMedia* pI) = 0;
	virtual void IMediaResetFish(IMedia* pI) = 0;

	virtual void SetResolution(IWideAngle360_V7::_eResolution eResol) = 0;

	virtual void SetFishCenter(int nCenterX, int nCenterY) = 0;									
	virtual void GetFishCenter(int& nCenterX, int& nCenterY) = 0;
	virtual void SetFishDimension(DWORD dwFishWidth, DWORD dwFishHeight) = 0;
	virtual void GetFishDimension(DWORD& dwFishWidth, DWORD& dwFishHeight) = 0;
	virtual void SetFOVDeg(double dFv) = 0;
	virtual void GetFOVDeg(double& dFv) = 0;
	virtual void SetLenzMaxRPixel(DWORD dwR) = 0;
	virtual void GetLenzMaxRPixel(DWORD& dwR) = 0;
	virtual void SetLenzPixelSize(double dPS) = 0;
	virtual void GetLenzPixelSize(double& dPS) = 0;
	virtual void SetSphereR(double dVR) = 0;
	virtual void GetSphereR(double& dVR) = 0;
	virtual void SetOutSize(int nW, int nH) = 0;
	virtual void GetOutSize(int& nW, int& nH) = 0;
	virtual void SetCamModel(ICamModel::_eCamModel eModel) = 0;
	virtual void SetPanTiltAngle(int nChannel, int nPan, int nTilt) = 0;
	virtual void GetPanTiltAngle(int nChannel, int& nPan, int& nTilt) = 0;
	virtual void SetMountType(IWideAngle360_V7::_eMountType eMount) = 0;
	virtual void GetMountType(IWideAngle360_V7::_eMountType& eMount) = 0;

public:
	virtual void SetIBufferPool4Decoder(IBufferPool* pBuffDecoded, IBufferPool* pBuffFrame) = 0;
	virtual void SetIBufferPool4Out(IBufferPool* pI) = 0;

public:
	virtual void SetDrive(TCHAR ucDrive) = 0;
};

class IEvtPlaying_V2
{
public:
	virtual void EvtPlayerMediaOpenedV2(){}
	virtual void EvtPlayerMediaPlayBeginV2(){}
	virtual void EvtPlayerMediaPlayDoneV2(){}
	virtual void EvtPlayerPosChangedV2(){}
	virtual void EvtPlayerPosCompletedV2(){}
	virtual void EvtPlayerFileNotExistV2(DWORD dwID){}
};

class IEvtPlaying_V3;

class IPlaying_V3 : public IBase, public IMedia
{
public:
	virtual void SetHWND(HWND hWnd) = 0;

public:
	virtual void AddIEvent(IEvtPlaying_V3* pI) = 0;
	virtual void RemoveIEvent(IEvtPlaying_V3* pI) = 0;
	virtual void ResetIEvent(IEvtPlaying_V3* pI) = 0;

public:
	virtual void SetIPool4Reading(IBufferPool* pI) = 0;
	virtual void SetIPool4Enc(IBufferPool* pI) = 0;

public:
	virtual bool MediaOpen(IDB_V2::_stMedia& stMedia) = 0;
	virtual void MediaClose() = 0;

public:
	virtual void Play() = 0;
	virtual void Pause(bool bPause) = 0;
	virtual void Stop() = 0;

public:
	virtual void SetPlayingPos(DWORD dwVideoPos) = 0;
	virtual void SetNextEventPos(DWORD dwVideoPos) = 0;

public:
	virtual int GetPlayingPosSize() = 0;

public:
	virtual void OnMediaParsingPosCnt() = 0;
	virtual void OnMediaParsingPos() = 0;

public:
	virtual void IMediaAddPano(IMedia* pI) = 0;
	virtual void IMediaRemovePano(IMedia* pI) = 0;
	virtual void IMediaResetPano(IMedia* pI) = 0;

	virtual void IMediaAddFish(IMedia* pI) = 0;
	virtual void IMediaRemoveFish(IMedia* pI) = 0;
	virtual void IMediaResetFish(IMedia* pI) = 0;

	virtual void SetResolution(IWideAngle360_V7::_eResolution eResol) = 0;

	virtual void SetFishCenter(int nCenterX, int nCenterY) = 0;									
	virtual void GetFishCenter(int& nCenterX, int& nCenterY) = 0;
	virtual void SetFishDimension(DWORD dwFishWidth, DWORD dwFishHeight) = 0;
	virtual void GetFishDimension(DWORD& dwFishWidth, DWORD& dwFishHeight) = 0;
	virtual void SetFOVDeg(double dFv) = 0;
	virtual void GetFOVDeg(double& dFv) = 0;
	virtual void SetLenzMaxRPixel(DWORD dwR) = 0;
	virtual void GetLenzMaxRPixel(DWORD& dwR) = 0;
	virtual void SetLenzPixelSize(double dPS) = 0;
	virtual void GetLenzPixelSize(double& dPS) = 0;
	virtual void SetSphereR(double dVR) = 0;
	virtual void GetSphereR(double& dVR) = 0;
	virtual void SetOutSize(int nW, int nH) = 0;
	virtual void GetOutSize(int& nW, int& nH) = 0;
	virtual void SetCamModel(ICamera_V1::_eCamModel eModel) = 0;
	virtual void SetPanTiltAngle(int nChannel, int nPan, int nTilt) = 0;
	virtual void GetPanTiltAngle(int nChannel, int& nPan, int& nTilt) = 0;
	virtual void SetMountType(IWideAngle360_V7::_eMountType eMount) = 0;
	virtual void GetMountType(IWideAngle360_V7::_eMountType& eMount) = 0;
	virtual void SetCamName(TCHAR (&strName)[MAX_PATH]) = 0;
	virtual void SetExportMargin(double dMargin) = 0;

public:
	virtual void SetIBufferPool4Decoder(IBufferPool* pBuffDecoded, IBufferPool* pBuffFrame) = 0;
	virtual void SetIBufferPool4Out(IBufferPool* pI) = 0;

public:
	virtual void SetDrives(TCHAR (&strDrive)[MAX_PATH]) = 0;

public:
	virtual bool ExportStart(int iSubCH) = 0;
	virtual void ExportStop(int iSubCH) = 0;
};

class IEvtPlaying_V4;

class IPlaying_V4 : public IWorker, public IMedia
{
public:
	enum _ePlayingState
	{
		eStateIdle,
		eStateRunning
	};

public:
	virtual void SetState(_ePlayingState eStateType) = 0;
	virtual _ePlayingState GetState() = 0;

public:
	virtual void SetHWND(HWND hWnd) = 0;

public:
	virtual void AddIEvent(IEvtPlaying_V4* pI) = 0;
	virtual void RemoveIEvent(IEvtPlaying_V4* pI) = 0;
	virtual void ResetIEvent(IEvtPlaying_V4* pI) = 0;

public:
	virtual void SetIPool4Reading(IBufferPool* pI) = 0;
	virtual void SetIPool4Enc(IBufferPool* pI) = 0;

public:
	virtual bool MediaOpen(IDB_V3::_stMedia& stMedia) = 0;
	virtual void MediaClose() = 0;

public:
	virtual void Play() = 0;
	virtual void Pause(bool bPause) = 0;
	virtual void Stop() = 0;

public:
	virtual void SetPlayingPos(DWORD dwVideoPos) = 0;
	virtual void SetNextEventPos(DWORD dwVideoPos) = 0;

public:
	virtual int GetPlayingPosSize() = 0;

public:
	virtual void OnMediaParsingPosCnt() = 0;
	virtual void OnMediaParsingPos() = 0;

public:
	virtual void IMediaAddPano(IMedia* pI) = 0;
	virtual void IMediaRemovePano(IMedia* pI, bool bEn) = 0;
	virtual void IMediaResetPano(bool bEn) = 0;

	virtual void IMediaAddFish(IMedia* pI) = 0;
	virtual void IMediaRemoveFish(IMedia* pI, bool bEn) = 0;
	virtual void IMediaResetFish(bool bEn) = 0;

	virtual void SetResolution(IWideAngle360_V9::_eResolution eResol) = 0;

	virtual void SetFishCenter(int nCenterX, int nCenterY) = 0;									
	virtual void GetFishCenter(int& nCenterX, int& nCenterY) = 0;
	virtual void SetFishDimension(DWORD dwFishWidth, DWORD dwFishHeight) = 0;
	virtual void GetFishDimension(DWORD& dwFishWidth, DWORD& dwFishHeight) = 0;
	virtual void SetFOVDeg(double dFv) = 0;
	virtual void GetFOVDeg(double& dFv) = 0;
	virtual void SetLenzMaxRPixel(DWORD dwR) = 0;
	virtual void GetLenzMaxRPixel(DWORD& dwR) = 0;
	virtual void SetLenzPixelSize(double dPS) = 0;
	virtual void GetLenzPixelSize(double& dPS) = 0;
	virtual void SetSphereR(double dVR) = 0;
	virtual void GetSphereR(double& dVR) = 0;
	virtual void SetOutSize(int nW, int nH) = 0;
	virtual void GetOutSize(int& nW, int& nH) = 0;
	virtual void SetCamModel(ICamModel::_eCamModel eModel) = 0;
	virtual void SetPanTiltAngle(int nChannel, int nPan, int nTilt) = 0;
	virtual void GetPanTiltAngle(int nChannel, int& nPan, int& nTilt) = 0;
	virtual void SetMountType(IMountType::_eMountType eMount) = 0;
	virtual void GetMountType(IMountType::_eMountType& eMount) = 0;
	virtual void SetCamName(TCHAR (&strName)[MAX_PATH]) = 0;
	virtual void SetExportMargin(double dMargin) = 0;

public:
	virtual void SetIBufferPool4Decoder(IBufferPool* pBuffDecoded, IBufferPool* pBuffFrame) = 0;
	virtual void SetIBufferPool4Out(IBufferPool* pI) = 0;

public:
	virtual void SetDrives(TCHAR (&strDrive)[MAX_PATH]) = 0;

public:
	virtual bool ExportStart(int iSubCH) = 0;
	virtual void ExportStop(int iSubCH) = 0;

public:
	virtual void SetSetupWA(bool bSetupWA) = 0;
	virtual bool IsSetupWA() = 0;
};

class IPlaying_V5 : public IWorker, public IMedia
{
public:
	virtual void AddPlaying(DWORD dwPlayer) = 0;

public:
	virtual bool IsPlaying(int iCam) = 0;
	virtual void Play(int iCam, IString* pMediaFile, SYSTEMTIME syPlayTime) = 0;
	virtual void Stop() = 0;
	virtual void Pause() = 0;
};

class IEvtPlaying_V3
{
public:
	virtual void EvtPlayerMediaOpenedV3(){}
	virtual void EvtPlayerMediaPlayBeginV3(){}
	virtual void EvtPlayerMediaPlayDoneV3(){}
	virtual void EvtPlayerPosChangedV3(){}
	virtual void EvtPlayerPosCompletedV3(){}
	virtual void EvtPlayerFileNotExistV3(DWORD dwID){}
	virtual void EvtPlayerExportDone(int iSubCh){}
};

class IEvtPlaying_V4
{
public:
	virtual void EvtPlayerMediaOpened(){}
	virtual void EvtPlayerMediaPlayBegin(){}
	virtual void EvtPlayerMediaPlayDone(){}
	virtual void EvtPlayerPosChanged(){}
	virtual void EvtPlayerPosCompleted(){}
	virtual void EvtPlayerFileNotExist(DWORD dwID){}
	virtual void EvtPlayerExportDone(int iSubCh){}
	virtual void EvtPlayerRemovePanoCompleted(bool bEn){}
	virtual void EvtPlayerRemoveFishCompleted(bool bEn){}
};


// 단순 저장된 파일의 재생
class IEvtCustomVideoFilePlaying
{
public:
	virtual void PlayingDone(DWORD dwContextID) {}
};

class ICustomVideoFilePlaying_V1 : public IWorker, public IMedia
{
public:
	virtual void IEvtAdd(IEvtCustomVideoFilePlaying* pI) = 0;
	virtual void IEvtRemove(IEvtCustomVideoFilePlaying* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void SetContextID(DWORD dw) = 0;
	virtual void OpenVideoFile(TCHAR* pStr) = 0;
	virtual void Play() = 0;
	virtual void Stop() = 0;
	virtual void Pause() = 0;
	virtual void Close() = 0;
	virtual bool IsPlaying() = 0;

public:
	virtual void SetFilePointer(LARGE_INTEGER& liNfs) = 0;
	virtual void SetIPool4Reading(IBufferPool* pIPool) = 0;
	virtual void SetPlayingTime(SYSTEMTIME stTime) = 0;
	virtual SYSTEMTIME GetEndTime() = 0;
};