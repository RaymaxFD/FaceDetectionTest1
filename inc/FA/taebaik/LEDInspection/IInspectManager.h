
#pragma once

#include <IBase.h>

// MIL include
#include "mil.h"
#include "DPoint.h"
#include "Structs.h"

class ISystem_V1;
class IEvtInspectManger_V1;

class IInspectManger_V1 : public IBase
{
public:
	struct _stMissing
	{
		int iModule;
		int iLedCount2Search;
		int iLedCountFound;
	};
public:
	static const int DEF_MAX_MODULE_COUNT = 100;
	static const int DEF_MAX_LED_COUNT = 200;

	static const double DEF_RECIPE_VERSION_001000;

	static const double DEF_RECIPE_VERSION_LEGACY;
	static const double DEF_RECIPE_VERSION_RECENT;

	static const int DEF_NONE_SELECT_AREA = -1;

	// 
	static const int DEF_MODULE_LEFT = 0;
	static const int DEF_MODULE_RIGHT = 1;
	static const int DEF_MODULE_ALL = 2;

	static const int DEF_MODULE_POS_ERROR = -1;
	static const int DEF_MODULE_POS_OUT = 0;
	static const int DEF_MODULE_POS_IN = 1;

	static const int DEF_IMAGE_WIDTH_SIZE = 2448;
	//

	static const int DEF_GRAY_RECT = 255;
	static const int DEF_GRAY_CROSS = 150;

public:
	virtual void AddIEvent(IEvtInspectManger_V1* pI) = 0;
	virtual void SetMilSystem(ISystem_V1* pI) = 0;

public:
	virtual void DataCopyTrain2Inspection() = 0;

public:
	virtual RECT GetFoundLEDRect(int iModule, int iLED) = 0;

public:
	virtual void SetInspectionOptions(stInspectOption& st) = 0;
	virtual stInspectOption& GetInspectionOptions() = 0;
	virtual void SetDisplay(stDisplay& st) = 0;
	virtual stDisplay& GetDisplay() = 0;
	virtual void SetTrainDisplay(stDisplay& st) = 0;
	virtual stDisplay& GetTrainDisplay() = 0;
	virtual void SetInspectRegion(int iModule, stInspectRegion& st) = 0;
	virtual stInspectRegion& GetInspectRegion(int iModule) = 0;
	virtual void SetInspectResultData(int iModule, stInspectResultData& st) = 0;
	virtual stInspectResultData& GetInspectResultData(int iModule) = 0;
	virtual void SetInspectRegionData(int iModule, stInspectRegionData& st) = 0;
	virtual stInspectRegionData& GetInspectRegionData(int iModule) = 0;
	virtual void SetTrainInspectResultData(int iModule, stTrainInspectResultData& st) = 0;
	virtual stTrainInspectResultData& GetTrainInspectResultData(int iModule) = 0;
	virtual stTrainInspectLEDSize& GetTrainInspectLEDSize(int iModule) = 0;
	virtual void SetTempLedRegionData(int iLED, stRegionData& st) = 0;
	virtual stRegionData GetTempLedRegionData(int iLED) = 0;
	virtual void SetTrainModuleRegion(int iModule, HRGN rgn) = 0;
	virtual HRGN GetTrainModuleRegion(int iModule) = 0;
	virtual void SetTrainRegionCount(DWORD dwCnt) = 0;
	virtual DWORD GetTrainRegionCount() = 0;

public:
	virtual void ResetInspectRegionData() = 0;

	virtual void ResetInspectResultData() = 0;
	virtual void ResetInspectResultData(int iModuleIndex) = 0;

	virtual void ResetInspectRegion() = 0;
	virtual void ResetTrainRegion() = 0;
	virtual void ResetDisplayRegion() = 0;
	virtual void ResetTrainDisplayRegion() = 0;
	virtual void ResetInspectOption() = 0;
	virtual void ResetTrainInspectResultData() = 0;
	virtual void ResetManualChangeLedIndex() = 0;

	virtual bool InspectModule(MIL_ID MilInspectImage, int iModulePos = DEF_MODULE_ALL) = 0;
	virtual bool InspectOverLed(MIL_ID MilInspectImage, int iModulePos = DEF_MODULE_ALL) = 0;	 // Over Led
	virtual bool InspectTrain(MIL_ID MilInspectImage) = 0;

	virtual bool LoadTrainFile(TCHAR* strFilePath) = 0;
	virtual bool SaveTrainFile(TCHAR* strFilePath) = 0;

	//virtual void CopyTrainRegion() = 0;
	virtual void CreateInspectRegion() = 0;

	//virtual void ManualChangeLedIndex(DPoint dpPoint) = 0;
	//virtual int FindModuleIndex(DPoint dpPoint) = 0;
	//virtual int FindLedIndex(int iModuleidx, DPoint dpPoint) = 0;

	virtual int FindModulePostion(int iModulePos, int iModuleidx) = 0;

	virtual void DeleteTrainModule(int iDrawModultCount) = 0;	 // LSH

	virtual bool InspectErrorImageSave(MIL_ID MilInspectImage, TCHAR* strPath) = 0;	 // LSH Inspect Error (Capture)	

	virtual int FindTrainModuleIndex(DPoint dpPoint, int iTrainCount) = 0;	 // LSH Train

	virtual void ResetTrainModule() = 0;	 // LSH Train
};

class IEvtInspectManger_V1
{
public:
	virtual void TrainOk(){}
	virtual void TrainLEDCountMissing(IInspectManger_V1::_stMissing* pMissing, DWORD dwCnt){}
	virtual void Missing(int iX, int iY){}
	virtual void Missing(HRGN hRgn){}
	virtual void ModuleCountOver(){}
	virtual void LEDCountOver(){}
};