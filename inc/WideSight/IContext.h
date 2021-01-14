
#pragma once

#include <IWorker.h>
#include <Component/IPCams/ICamera.h>
#include <Component/ImgAnalyser/IWideAngle360.h>
#include <Component/ImgAnalyser/IWideAngle180.h>
#include <Component\ImgAnalyser\IFaceIdentification.h>
#include <debug.h>
#include <Component/IPCams\ICamModel.h>
#include <WideSight\IPanoType.h>
#include <Media\IMedia.h>

class IWideAngle360_V7;
class IBufferPool;
class IMedia;
class IEvtContext_V1;
class IDB_V1;
class IDB_V2;
class IDB_V3;

class IContext_V1 : public IWorker
{
public:
	virtual void SetHWND(int i, HWND hWnd) = 0;

public:
	virtual void SetIDB(IDB_V2* pIDB) = 0;

public:
	virtual void SetDrive(TCHAR ucDrive) = 0;

public:
	virtual void AddIEvent(IEvtContext_V1* pI) = 0;
	virtual void RemoveIEvent(IEvtContext_V1* pI) = 0;
	virtual void ResetIEvent(IEvtContext_V1* pI) = 0;

public:
	virtual void EnableDec(bool bEn) = 0;
	virtual void EnablePano(bool bEn) = 0;

public:
	virtual bool Connect() = 0;
	virtual void Disconnect() = 0;

public:
	virtual void SetCamModel(ICamera_V1::_eCamModel eModel) = 0;
	virtual void SetCamInfoID(DWORD dwCamInfo) = 0;

public:
	virtual void SetResolution(IWideAngle360_V7::_eResolution eResol) = 0;

public:
	virtual void SetIP(TCHAR* strIP) = 0;
	virtual void GetIP(TCHAR (&strIP)[MAX_PATH]) = 0;

	virtual void SetMountType(IWideAngle360_V7::_eMountType eMount) = 0;
	virtual void GetMountType(IWideAngle360_V7::_eMountType& eMount) = 0;

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

	virtual void SetUserID(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void SetUserPass(TCHAR (&str)[MAX_PATH]) = 0;

	virtual void SetRootFolder(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void GetRootFolder(TCHAR (&str)[MAX_PATH]) = 0;

	virtual void SetCamName(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void GetCamName(TCHAR (&str)[MAX_PATH]) = 0;

	virtual void RecordingStart() = 0;
	virtual void RecordingStop() = 0;
	virtual bool IsRecording() = 0;



public:
	virtual void SetPanTiltAngle(int ichannel, int iPan, int iTilt) = 0;                        // 바라보는 Pan/Tilt 각도 설정. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.
	virtual void GetPanTiltAngle(int ichannel, int& iPan, int& iTilt) = 0;                      // 현재 설정된 Pan/Tilt 각도 읽기. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.

public:
	virtual void AddIMediaFish(IMedia* pI) = 0;
	virtual void AddIMediaPano(IMedia* pI) = 0;

public:
	virtual void ScreenShot(int iChannel, TCHAR (&strFile)[MAX_PATH]) = 0;
	//virtual void ScreenShotFish() = 0;




	// Context 동작/정지
public:
	virtual bool ContextStart() = 0;
	virtual void ContextStop() = 0;
	virtual bool IsRunning() = 0;

public:
	virtual void SetIBufferPool4Cam(IBufferPool* pI) = 0;
	virtual void SetIBufferPool4Decoder(IBufferPool* pBuffDecoded, IBufferPool* pBuffFrame) = 0;
	virtual void SetIBufferPool4Out(IBufferPool* pI) = 0;
};

class IEvtContext_V1
{
public:
	virtual void EvtContextStarted(){ASSERT(0);}
	virtual void EvtContextStoped(){ASSERT(0);}

public:
	virtual void EvtDetection(DWORD dwContextID, RECT rt){}
};

#include <Component/RTSP/IRTSPClient.h>

class IWideAngle360_V9;
class IEvtContext_V2;

class IContext_V2 : public IBase, public ICamModel
{
public:
	virtual void SetContextID(DWORD dwContext) = 0;

public:
	virtual void SetHWND(HWND hWnd) = 0;

public:
	virtual void SetIDB(IDB_V2* pIDB) = 0;

public:
	virtual void SetDrive(TCHAR ucDrive) = 0;

public:
	virtual void AddIEvent(IEvtContext_V2* pI) = 0;
	virtual void RemoveIEvent(IEvtContext_V2* pI) = 0;
	virtual void ResetIEvent(IEvtContext_V2* pI) = 0;

public:
	virtual void EnableDec(bool bEn) = 0;
	virtual void EnablePano(bool bEn) = 0;

public:
	virtual bool Connect() = 0;
	virtual void Disconnect() = 0;

public:
	virtual void SetCamModel(_eCamModel eModel) = 0;
	virtual void SetCamInfoID(DWORD dwCamInfo) = 0;

public:
	virtual void SetResolution(IWideAngle360_V9::_eResolution eResol) = 0;

public:
	virtual void SetIP(TCHAR* strIP) = 0;
	virtual void GetIP(TCHAR (&strIP)[MAX_PATH]) = 0;

	virtual void SetMountType(IWideAngle360_V9::_eMountType eMount) = 0;
	virtual void GetMountType(IWideAngle360_V9::_eMountType& eMount) = 0;

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

	virtual void SetRootFolder(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void GetRootFolder(TCHAR (&str)[MAX_PATH]) = 0;

	virtual void SetCamName(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void GetCamName(TCHAR (&str)[MAX_PATH]) = 0;

	virtual void RecordingStart() = 0;
	virtual void RecordingStop() = 0;
	virtual bool IsRecording() = 0;
	virtual void DiskFull(bool b) = 0;



public:
	virtual void SetPanTiltAngle(int ichannel, int iPan, int iTilt) = 0;                        // 바라보는 Pan/Tilt 각도 설정. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.
	virtual void GetPanTiltAngle(int ichannel, int& iPan, int& iTilt) = 0;                      // 현재 설정된 Pan/Tilt 각도 읽기. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.

public:
	virtual void AddIMediaFish(IMedia* pI) = 0;
	virtual void AddIMediaPano(IMedia* pI) = 0;

public:
	virtual void ScreenShot(int iChannel, TCHAR (&strFile)[MAX_PATH]) = 0;
	//virtual void ScreenShotFish() = 0;




	// Context 동작/정지
public:
	virtual bool ContextStart() = 0;
	virtual void ContextStop() = 0;
	virtual bool IsRunning() = 0;

public:
	virtual void SetIBufferPool4Cam(IBufferPool* pI) = 0;
	virtual void SetIBufferPool4Decoder(IBufferPool* pBuffDecoded, IBufferPool* pBuffFrame) = 0;
	virtual void SetIBufferPool4Out(IBufferPool* pI) = 0;
};

class IEvtContext_V2
{
public:
	virtual void EvtContextStarted(){ASSERT(0);}
	virtual void EvtContextStoped(){ASSERT(0);}

public:
	virtual void EvtConextConnected(){}
	virtual void EvtConextDisconnected(){}
	virtual void EvtConextReconnectRequest(){}	

public:
	virtual void EvtDetection(DWORD dwContextID, RECT rt){}
};


class IEvtContext_V3;
class IContext_V3 : public IWorker, public ICamModel
{
public:
	virtual void SetContextID(DWORD dwContext) = 0;

public:
	virtual void SetHWND(HWND hWnd) = 0;

public:
	virtual void SetIDB(IDB_V3* pIDB) = 0;

public:
	virtual void SetDrive(TCHAR ucDrive) = 0;

public:
	virtual void AddIEvent(IEvtContext_V3* pI) = 0;
	virtual void RemoveIEvent(IEvtContext_V3* pI) = 0;
	virtual void ResetIEvent(IEvtContext_V3* pI) = 0;

public:
	virtual void EnableDec(bool bEn) = 0;
	virtual void EnablePano(bool bEn) = 0;
	virtual bool IsPano() = 0;

public:
	virtual bool Connect() = 0;
	virtual void Disconnect() = 0;

public:
	virtual void SetCamModel(_eCamModel eModel) = 0;
	virtual void SetCamInfoID(DWORD dwCamInfoID) = 0;
	virtual void GetCamInfoID(DWORD& dwCamInfoID) = 0;

public:
	virtual void SetResolution(IWideAngle360_V9::_eResolution eResol) = 0;

public:
	virtual void SetIP(TCHAR* strIP) = 0;
	virtual void GetIP(TCHAR (&strIP)[MAX_PATH]) = 0;
	virtual bool CheckMacAddr() = 0;

	virtual void DeInit() = 0;

	virtual void SetMountType(IWideAngle360_V9::_eMountType eMount) = 0;
	virtual void GetMountType(IWideAngle360_V9::_eMountType& eMount) = 0;

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

	virtual void SetRootFolder(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void GetRootFolder(TCHAR (&str)[MAX_PATH]) = 0;

	virtual void SetChName(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void GetChName(TCHAR (&str)[MAX_PATH]) = 0;

	virtual void SetCamName(TCHAR (&str)[MAX_PATH]) = 0;
	virtual void GetCamName(TCHAR (&str)[MAX_PATH]) = 0;

	virtual void RecordingStart(int nCh) = 0;
	virtual void RecordingStop() = 0;
	virtual bool IsRecording() = 0;
	virtual void DiskFull(bool b) = 0;

public:
	virtual void SetPanTiltAngle(int ichannel, int iPan, int iTilt) = 0;                        // 바라보는 Pan/Tilt 각도 설정. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.
	virtual void GetPanTiltAngle(int ichannel, int& iPan, int& iTilt) = 0;                      // 현재 설정된 Pan/Tilt 각도 읽기. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.

public:
	virtual void AddIMediaFish(IMedia* pI) = 0;
	virtual void AddIMediaPano(IMedia* pI) = 0;

public:
	virtual void RemoveIMediaFish(IMedia* pI) = 0;
	virtual void RemoveIMediaPano(IMedia* pI) = 0;

public:
	virtual void ScreenShot(int iChannel, TCHAR (&strFile)[MAX_PATH]) = 0;

public:
	virtual void SetBitmap(int nID, TCHAR* pFilePath) = 0;
	virtual void DrawBitmap(int nID) = 0;
	virtual void EnableBitmap(bool bDraw) = 0;

public:
	virtual void Focus(bool bOn) = 0;

public:
	virtual void SetOSDFont(TCHAR* pFontFilePath) = 0;
	virtual void SetOSDText(int nID, int nSCh, int nRed, int nGreen, int nBlue, IWideAngle360_V9::_eTextAlignType ePosType, TCHAR* pMsg, int nFontSize) = 0;
	virtual void KillOSDText(int nID) = 0;

public:
	virtual void OnSize() = 0;

public:
	virtual bool ContextStart() = 0;
	virtual void ContextStop() = 0;
	virtual bool IsRunning() = 0;

public:
	virtual void SetIBufferPool4Cam(IBufferPool* pI) = 0;
	virtual void SetIBufferPool4Decoder(IBufferPool* pBuffDecoded, IBufferPool* pBuffFrame) = 0;
	virtual void SetIBufferPool4Out(IBufferPool* pI) = 0;
};


class IEvtContext_V3
{
public:
	virtual void EvtContextStarted(DWORD dwContextID){}
	virtual void EvtContextStoped(DWORD dwContextID){}

public:
	virtual void EvtDetection(DWORD dwContextID, RECT rt){}

public:
	virtual void EvtContext_FileSizeZero_V3(DWORD dwContextID, DWORD dwIDMedia){}
	virtual void EvtContext_RecordStarted_V3(DWORD dwContextID, DWORD dwIDMedia){}
	virtual void EvtContext_RecordStop_V3(DWORD dwContextID, DWORD dwIDMedia){}
	virtual void EvtContext_NoDrive_V3(DWORD dwContextID, DWORD dwIDMedia){}
	virtual void EvtConnected(DWORD dwContextID){}
	virtual void EvtDisconnected(DWORD dwContextID){}
	virtual void EvtPresentationTime(long lSec, long lUsec){}
};

class IEvtContext_V4;
class IContext_V4 : public IWorker, public ICamModel, public IPanoType
{
public:
	virtual void SetPanoType(_ePanoType IPano) = 0;
	virtual _ePanoType GetPanoType() = 0;

public:
	virtual void SetContextID(DWORD dwContext) = 0;

public:
	virtual void SetHWND(HWND hWnd) = 0;

public:
	virtual void SetIDB(IDB_V3* pIDB) = 0;

public:
	virtual void SetDrive(TCHAR ucDrive) = 0;

public:
	virtual void AddIEvent(IEvtContext_V4* pI) = 0;
	virtual void RemoveIEvent(IEvtContext_V4* pI) = 0;
	virtual void ResetIEvent(IEvtContext_V4* pI) = 0;

public:
	virtual void EnableDec(bool bEn) = 0;
	virtual void EnablePano(bool bEn) = 0;
	virtual bool IsPano() = 0;

public:
	virtual bool Connect() = 0;
	virtual void Disconnect() = 0;

public:
	virtual void SetCamModel(_eCamModel eModel) = 0;
	virtual void SetCamInfoID(DWORD dwCamInfoID) = 0;
	virtual void GetCamInfoID(DWORD& dwCamInfoID) = 0;

public:
	virtual void SetResolution(IWideAngle360_V9::_eResolution eResol) = 0;

public:
	virtual void SetIP(TCHAR* strIP) = 0;
	virtual void GetIP(TCHAR(&strIP)[MAX_PATH]) = 0;
	virtual bool CheckMacAddr() = 0;

	virtual void DeInit() = 0;

	virtual void SetMountType(IWideAngle360_V9::_eMountType eMount) = 0;
	virtual void GetMountType(IWideAngle360_V9::_eMountType& eMount) = 0;

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

	virtual void SetRootFolder(TCHAR(&str)[MAX_PATH]) = 0;
	virtual void GetRootFolder(TCHAR(&str)[MAX_PATH]) = 0;

	virtual void SetChName(TCHAR(&str)[MAX_PATH]) = 0;
	virtual void GetChName(TCHAR(&str)[MAX_PATH]) = 0;

	virtual void SetCamName(TCHAR(&str)[MAX_PATH]) = 0;
	virtual void GetCamName(TCHAR(&str)[MAX_PATH]) = 0;

	virtual void RecordingStart(int nCh) = 0;
	virtual void RecordingStop() = 0;
	virtual bool IsRecording() = 0;
	virtual void DiskFull(bool b) = 0;

public:
	virtual void SetPanTiltAngle(int ichannel, int iPan, int iTilt) = 0;                        // 바라보는 Pan/Tilt 각도 설정. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.
	virtual void GetPanTiltAngle(int ichannel, int& iPan, int& iTilt) = 0;                      // 현재 설정된 Pan/Tilt 각도 읽기. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.

public:
	virtual void AddIMediaFish(IMedia* pI) = 0;
	virtual void AddIMediaPano(IMedia* pI) = 0;

public:
	virtual void RemoveIMediaFish(IMedia* pI) = 0;
	virtual void RemoveIMediaPano(IMedia* pI) = 0;

public:
	virtual void ScreenShot(int iChannel, TCHAR(&strFile)[MAX_PATH]) = 0;

public:
	virtual void DrawBitmap(TCHAR* pFilePath) = 0;

public:
	virtual void Focus(bool bOn) = 0;

public:
	virtual void SetOSDFont(TCHAR* pFontFilePath) = 0;
	virtual void SetOSDText(int nID, int nSCh, int nRed, int nGreen, int nBlue, IWideAngle360_V9::_eTextAlignType ePosType, TCHAR* pMsg, int nFontSize) = 0;
	virtual void KillOSDText(int nID) = 0;

public:
	virtual void OnSize() = 0;

public:
	virtual bool ContextStart() = 0;
	virtual void ContextStop() = 0;
	virtual bool IsRunning() = 0;

public:
	virtual void SetIBufferPool4Cam(IBufferPool* pI) = 0;
	virtual void SetIBufferPool4Decoder(IBufferPool* pBuffDecoded, IBufferPool* pBuffFrame) = 0;
	virtual void SetIBufferPool4Out(IBufferPool* pI) = 0;

public:
	virtual void SetupWA() = 0;
};


class IEvtContext_V4
{
public:
	virtual void EvtContextStarted(DWORD dwContextID){}
	virtual void EvtContextStoped(DWORD dwContextID){}

public:
	virtual void EvtDetection(DWORD dwContextID, RECT rt){}

public:
	virtual void EvtContext_FileSizeZero_V3(DWORD dwContextID, DWORD dwIDMedia){}
	virtual void EvtContext_RecordStarted_V3(DWORD dwContextID, DWORD dwIDMedia){}
	virtual void EvtContext_RecordStop_V3(DWORD dwContextID, DWORD dwIDMedia){}
	virtual void EvtContext_NoDrive_V3(DWORD dwContextID, DWORD dwIDMedia){}
	virtual void EvtConnected(DWORD dwContextID){}
	virtual void EvtDisconnected(DWORD dwContextID){}
	virtual void EvtPresentationTime(long lSec, long lUsec){}
};




class IHIK_V2;
class IEvtContext_V5;
class IContext_V5 : public IWorker, public ICamModel, public IPanoType, public IMedia
{
public:
	virtual void SetAccount(TCHAR* pStrID, TCHAR* pStrPass) = 0;

public:
	virtual IFaceIdentification_V2 * GetFI() = 0;

public:
	virtual IHIK_V2* GetINVR() = 0;

public:
	virtual void SetPanoType(_ePanoType IPano) = 0;
	virtual _ePanoType GetPanoType() = 0;

public:
	virtual void SetContextID(DWORD dwContext) = 0;

public:
	virtual void SetHWND(HWND hWnd) = 0;

public:
	virtual void SetIDB(IDB_V3* pIDB) = 0;

public:
	virtual void SetDrive(TCHAR ucDrive) = 0;

public:
	virtual void AddIEvent(IEvtContext_V5* pI) = 0;
	virtual void RemoveIEvent(IEvtContext_V5* pI) = 0;
	virtual void ResetIEvent(IEvtContext_V5* pI) = 0;

public:
	virtual void EnableDec(bool bEn) = 0;
	virtual void EnablePano(bool bEn) = 0;
	virtual bool IsPano() = 0;

public:
	virtual bool Connect() = 0;
	virtual void Disconnect() = 0;

public:
	virtual void SetCamModel(_eCamModel eModel) = 0;
	virtual void SetCamInfoID(DWORD dwCamInfoID) = 0;
	virtual void GetCamInfoID(DWORD& dwCamInfoID) = 0;

public:
	virtual void SetResolution(IWideAngle360_V9::_eResolution eResol) = 0;
	virtual void GetResolution(IWideAngle360_V9::_eResolution& eResol) = 0;

public:
	virtual void SetIP(TCHAR* strIP) = 0;
	virtual void GetIP(TCHAR(&strIP)[MAX_PATH]) = 0;
	virtual bool CheckMacAddr() = 0;

	virtual void DeInit() = 0;

	virtual void SetMountType(IWideAngle360_V9::_eMountType eMount) = 0;
	virtual void GetMountType(IWideAngle360_V9::_eMountType& eMount) = 0;

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

	virtual void SetRootFolder(TCHAR(&str)[MAX_PATH]) = 0;
	virtual void GetRootFolder(TCHAR(&str)[MAX_PATH]) = 0;

	virtual void SetChName(TCHAR(&str)[MAX_PATH]) = 0;
	virtual void GetChName(TCHAR(&str)[MAX_PATH]) = 0;

	virtual void SetCamName(TCHAR(&str)[MAX_PATH]) = 0;
	virtual void GetCamName(TCHAR(&str)[MAX_PATH]) = 0;

	virtual void RecordingStart(int nCh) = 0;
	virtual void RecordingStop() = 0;
	virtual bool IsRecording() = 0;
	virtual void DiskFull(bool b) = 0;

public:
	virtual void SetPanTiltAngle(int ichannel, int iPan, int iTilt) = 0;                        // 바라보는 Pan/Tilt 각도 설정. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.
	virtual void GetPanTiltAngle(int ichannel, int& iPan, int& iTilt) = 0;                      // 현재 설정된 Pan/Tilt 각도 읽기. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.

public:
	virtual void OnLButtonDown(UINT nFlags, POINT point) = 0;
	virtual void OnLButtonUp(UINT nFlags, POINT point) = 0;
	virtual void OnMouseMove(UINT nFlags, POINT point) = 0;

public:
	virtual void AddIMediaFish(IMedia* pI) = 0;
	virtual void AddIMediaPano(IMedia* pI) = 0;

public:
	virtual void RemoveIMediaFish(IMedia* pI) = 0;
	virtual void RemoveIMediaPano(IMedia* pI) = 0;

public:
	virtual void ScreenShot(int iChannel, TCHAR(&strFile)[MAX_PATH]) = 0;

public:
	virtual void DrawBitmap(TCHAR* pFilePath) = 0;

public:
	virtual void Focus(bool bOn) = 0;

public:
	virtual void SetOSDFont(TCHAR* pFontFilePath) = 0;
	virtual void SetOSDText(int nID, int nSCh, int nRed, int nGreen, int nBlue, IWideAngle360_V9::_eTextAlignType ePosType, TCHAR* pMsg, int nFontSize) = 0;
	virtual void KillOSDText(int nID) = 0;
	virtual void SetOSDText2(int nID, int nSCh, int nRed, int nGreen, int nBlue, POINT ptPos, TCHAR* pMsg, int nFontSize) = 0;
	virtual void KillOSDText2(int nID) = 0;

public:
	virtual void OnSize() = 0;

public:
	virtual bool ContextStart() = 0;
	virtual void ContextStop() = 0;
	virtual bool IsRunning() = 0;

public:
	virtual void SetIBufferPool4Out(IBufferPool* pI) = 0;

public:
	virtual void SetupWA(_eColorFormat eColorFormat = eColorYUV) = 0;

public:
	virtual void SetCh(int iCh) = 0;

public:
	virtual void EnableFaceIdentification(bool b) = 0;
	virtual void EnableMotionTracking(bool b) = 0;

public:
	virtual void DrawRect(int iSub, int nRed, int nGreen, int nBlue, int nLineWidth, RECT& rtPos) = 0;
	virtual void DrawRectReset() = 0;

public:
	virtual void TeachNew(IFaceIdentification_V2::_stTeachNew stTeachNew) = 0; // 인식할 사람 사진 저장
	virtual void TeachNewClear() = 0;
};


class IEvtContext_V5
{
public:
	virtual void EvtContextStarted(DWORD dwContextID){}
	virtual void EvtContextStoped(DWORD dwContextID){}

public:
	virtual void EvtDetection(DWORD dwContextID, RECT rt){}

public:
	virtual void EvtContext_FileSizeZero_V3(DWORD dwContextID, DWORD dwIDMedia){}
	virtual void EvtContext_RecordStarted_V3(DWORD dwContextID, DWORD dwIDMedia){}
	virtual void EvtContext_RecordStop_V3(DWORD dwContextID, DWORD dwIDMedia){}
	virtual void EvtContext_NoDrive_V3(DWORD dwContextID, DWORD dwIDMedia){}
	virtual void EvtConnected(DWORD dwContextID){}
	virtual void EvtDisconnected(DWORD dwContextID){}
	virtual void EvtPresentationTime(long lSec, long lUsec){}

public:
	virtual void IEvtEvaluationFaceDetected(DWORD dwContextID, int iID, double dScore, RECT rtFace) {}
};


// HawkEye3D_AI를 위한
class IEVTContext_V6;
class IContext_V6 : public IWorker
{
public:
	virtual void IEvtAdd(IEVTContext_V6* pI) = 0;
	virtual void IEvtRemove(IEVTContext_V6* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void IMediaAdd(IMedia* pI) = 0;
	virtual void IMediaRemove(IMedia* pI) = 0;

public:
	virtual void SetAddr(TCHAR* pAddr) = 0;
	virtual void SetName(TCHAR* pName) = 0;
	virtual void Connection(bool bConn) = 0;
	virtual void SetupVideo() = 0;
	virtual void Init(HWND hWnd) = 0;
	virtual void OnSize() = 0;
	virtual void EnableMD(bool bMD) = 0;
	virtual void SetMDThreshold(BYTE ucTh) = 0;
	virtual void EnableMT(bool bMT) = 0;
	virtual void EnableFI(bool bFI) = 0;
	virtual bool IsMD() = 0;
	virtual bool IsMT() = 0;
	virtual bool IsFI() = 0;
	virtual void DrawRectangle(RECT& rt) = 0;
	virtual void DrawCircle(int nRed, int nGreen, int nBlue, int nLineWidth, POINT ptCenter, USHORT usRadius) = 0;
	virtual void DrawCircleReset() = 0;
	virtual void EnablePano(bool bEn) = 0;
	virtual bool IsPano() = 0;
	virtual void SetupWA() = 0;

public:
	virtual void SetMountType(IWideAngle360_V10::_eMountType eMount) = 0;
	virtual void GetMountType(IWideAngle360_V10::_eMountType& eMount) = 0;

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

	virtual void SetPanTiltAngle(int ichannel, int iPan, int iTilt) = 0;                        // 바라보는 Pan/Tilt 각도 설정. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.
	virtual void GetPanTiltAngle(int ichannel, int& iPan, int& iTilt) = 0;                      // 현재 설정된 Pan/Tilt 각도 읽기. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.
};

class IEVTContext_V6
{
public:
	virtual void EvtConnected(DWORD dwContextID) {}
	virtual void EvtDisconnected(DWORD dwContextID) {}
	virtual void EvtPresentationTime(long lSec, DWORD dwContextID) {}
	virtual void EvtRTSPVideoSize(size_t nWidth, size_t nHeight) {}
};


// AINVR을 위한
class IEVTContext_V7;
class IContext_V7 : public IWorker
{
public:
	virtual void IEvtAdd(IEVTContext_V7* pI) = 0;
	virtual void IEvtRemove(IEVTContext_V7* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void IMediaAddVPP(IMedia* pI) = 0;
	virtual void IMediaRemoveVPP(IMedia* pI) = 0;

public:
	virtual void SetContextID(DWORD dwContextID) = 0;
	virtual void SetAddr(TCHAR* pAddr) = 0;
	virtual void SetName(TCHAR* pName) = 0;
	virtual void Connection(bool bConn) = 0;
	virtual void SetupVideo() = 0;
	virtual void Init(HWND hWnd) = 0;
	virtual void OnSize() = 0;
	virtual void EnableMD(bool bMD) = 0;
	virtual void SetMDThreshold(BYTE ucTh) = 0;
	virtual void EnableMT(bool bMT) = 0;
	virtual void EnableFI(bool bFI) = 0;
	virtual bool IsMD() = 0;
	virtual bool IsMT() = 0;
	virtual bool IsFI() = 0;
	virtual void DrawRectangle(RECT& rt) = 0;
	virtual void DrawCircle(int nRed, int nGreen, int nBlue, int nLineWidth, POINT ptCenter, USHORT usRadius) = 0;
	virtual void DrawCircleReset() = 0;
	virtual void EnablePano(bool bEn) = 0;
	virtual bool IsPano() = 0;
	virtual void SetupWA() = 0;

public:
	virtual void SetMountType(IWideAngle360_V10::_eMountType eMount) = 0;
	virtual void GetMountType(IWideAngle360_V10::_eMountType& eMount) = 0;

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

	virtual void SetPanTiltAngle(int ichannel, int iPan, int iTilt) = 0;                        // 바라보는 Pan/Tilt 각도 설정. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.
	virtual void GetPanTiltAngle(int ichannel, int& iPan, int& iTilt) = 0;                      // 현재 설정된 Pan/Tilt 각도 읽기. 내부적으로 4개의 서브 채널중에서 선택된 것을 제어한다.
	virtual void SetNewMousePos(int ichannel, int iX, int iY) = 0;

public:
	virtual void LinkToNVR4Recording(IMedia* pI) = 0;
	virtual void LinkToNVR4Playing(IMedia* pI) = 0;
	virtual void UnLinkToNVR4Recording(IMedia* pI) = 0;
	virtual void UnLinkToNVR4Playing(IMedia* pI) = 0;

public:
	virtual void TeachNew(IFaceIdentification_V3::_stTeachNew& stTeachNew) = 0; // 예를 들어, 한 사람만 촬영이 되어야 함.
	virtual void TeachNewClear() = 0;
	virtual void CropFace(IBuffer* pIIn, size_t nW, size_t nH, size_t nD, IBuffer* pIOut) = 0;
	virtual void EnableMotionDetection(bool bEnable) = 0;

public:
	virtual void SetFaceDetectorFile(const TCHAR* pStr) = 0; // mmod_human_face_detector
	virtual void SetLandmarkDetectorFile(const TCHAR* pStr) = 0; // shape_predictor_5_face_landmarks
	virtual void SetFaceRecognitionFile(const TCHAR* pStr) = 0; // dlib_face_recognition_resnet_model_v1

public:
	virtual void SetFaceThres(double dThres) = 0;
	virtual void SetIBufferPool4RGB(IBufferPool* pI) = 0;

public:
	virtual void ROIAdd(RECT rt) = 0;
	virtual void ROIAddOk() = 0;
	virtual void ROIReset() = 0;

	// IFileRecorder_V6을 임시로 쓰기 위해서
//public:
//	virtual void RecordingStart(SIZE szVideo, BYTE ucFPS, BYTE ucGOP, IMedia::_eCodecVideo eCodec) = 0;
//	virtual void RecordingStop() = 0;
};

class IEVTContext_V7
{
public:
	virtual void EvtConnected(DWORD dwContextID) {}
	virtual void EvtDisconnectionFail(DWORD dwContextID) {}
	virtual void EvtDisconnected(DWORD dwContextID) {}
	virtual void EvtPresentationTime(DWORD dwContextID, long lSec) {}
	virtual void EvtRTSPVideoSize(DWORD dwContextID, size_t nWidth, size_t nHeight) {}
	virtual void EvtFPS(DWORD dwContextID, BYTE ucFPS) {}

public:
	virtual void IEvtIDecProbeVideoSize(DWORD dwContextID, size_t nWidth, size_t nHeight) {}
	virtual void IEvtIDecProbeVideoCodec(DWORD dwContextID, IMedia::_eCodecVideo) {}
	virtual void IEvtIDecProbeGOP(DWORD dwContextID, int iGOP) {}
	virtual void IEvtIDecProbeFail(DWORD dwContextID) {}

public:
	virtual void EvtIDecVideoResolution(size_t nWidth, size_t nHeight) {}
};

// WS16NVR을 위한
// 카메라 접속을 LIBVLC로
// 이벤트는 IEvtContext_V5를 그대로
class IContext_V8 : public IContext_V5
{};
