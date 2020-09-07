
#pragma once

#include "Dpoint.h"

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

struct stInspectOption
{
	int iModuleCount;
	int iLedCount;

	int iMinThreshold;
	int iMaxThreshold;

	int iMinLedSize;

	int iLedSizeOffsetX;
	int iLedSizeOffsetY;

	int iErrorCorssSize;

	stInspectOption()
	{
		iModuleCount = 1;
		iLedCount = 1;

		iMinThreshold = 100;
		iMaxThreshold = 255;

		iMinLedSize = 100;

		iLedSizeOffsetX = 0;
		iLedSizeOffsetY = 0;

		iErrorCorssSize = 50;
	}
};

struct stDisplay
{
	HRGN HModuleDispRegion[DEF_MAX_MODULE_COUNT];
	HRGN HLedDispRegion[DEF_MAX_MODULE_COUNT][DEF_MAX_LED_COUNT];
	HRGN HInspectErrorDispXld[DEF_MAX_MODULE_COUNT][DEF_MAX_LED_COUNT];
	DWORD dwErrorSize[DEF_MAX_MODULE_COUNT][DEF_MAX_LED_COUNT];
	HRGN HInspectOverLedDispXld[DEF_MAX_MODULE_COUNT][DEF_MAX_LED_COUNT];	 // Over Led
	DWORD dwOverSize[DEF_MAX_MODULE_COUNT][DEF_MAX_LED_COUNT];

	HRGN HInspectLedErrorCaptureRect;	 // Inspect Led Error 
	HRGN HInspectLedErrorCaptureCross;	 // Inspect Led Error 
	HRGN HInspectOverLedErrorCaptureRect;	 // Inspect Over Led Error 
	HRGN HInspectOverLedErrorCaptureCross;	 // Inspect Over Led Error 

	stDisplay()
	{
		int i = 0;
		ZeroMemory(HModuleDispRegion, sizeof(HRGN) * DEF_MAX_MODULE_COUNT);
		for (i = 0; i < DEF_MAX_MODULE_COUNT; i++)
		{
			ZeroMemory(HLedDispRegion[i], sizeof(HRGN) * DEF_MAX_LED_COUNT);
			ZeroMemory(HInspectErrorDispXld[i], sizeof(HRGN) * DEF_MAX_LED_COUNT);
			ZeroMemory(HInspectOverLedDispXld[i], sizeof(HRGN) * DEF_MAX_LED_COUNT);
			ZeroMemory(dwErrorSize[i], sizeof(DWORD) * DEF_MAX_LED_COUNT);
			ZeroMemory(dwOverSize[i], sizeof(DWORD) * DEF_MAX_LED_COUNT);
		}

		HInspectLedErrorCaptureRect = NULL;	 // Inspect Led Error 
		HInspectLedErrorCaptureCross = NULL;	 // Inspect Led Error 
		HInspectOverLedErrorCaptureRect = NULL;	 // Inspect Over Led Error 
		HInspectOverLedErrorCaptureCross = NULL;	 // Inspect Over Led Error 
	}
	~stDisplay()
	{
		Reset();
	}
	void Reset()
	{
		int i = 0, j = 0;
		for (i = 0; i < DEF_MAX_MODULE_COUNT; i++)
		{
			if (HModuleDispRegion[i])
			{
				DeleteObject(HModuleDispRegion[i]);
				HModuleDispRegion[i] = NULL;
			}
			ZeroMemory(dwErrorSize[i], sizeof(DWORD) * DEF_MAX_LED_COUNT);
			ZeroMemory(dwOverSize[i], sizeof(DWORD) * DEF_MAX_LED_COUNT);
		}
		for (i = 0; i < DEF_MAX_MODULE_COUNT; i++)
		{
			for (j = 0; j < DEF_MAX_LED_COUNT; j++)
			{
				if (HLedDispRegion[i][j])
				{
					DeleteObject(HLedDispRegion[i][j]);
					HLedDispRegion[i][j] = NULL;
				}
				if (HInspectErrorDispXld[i][j])
				{
					DeleteObject(HInspectErrorDispXld[i][j]);
					HInspectErrorDispXld[i][j] = NULL;
				}
				if (HInspectOverLedDispXld[i][j])
				{
					DeleteObject(HInspectErrorDispXld[i][j]);
					HInspectErrorDispXld[i][j] = NULL;
				}
			}
		}

		DeleteObject(HInspectLedErrorCaptureRect);	 // Inspect Led Error 
		HInspectLedErrorCaptureRect = NULL;
		DeleteObject(HInspectLedErrorCaptureCross);	 // Inspect Led Error 
		HInspectLedErrorCaptureCross = NULL;
		DeleteObject(HInspectOverLedErrorCaptureRect);	 // Inspect Over Led Error 
		HInspectOverLedErrorCaptureRect = NULL;
		DeleteObject(HInspectOverLedErrorCaptureCross);	 // Inspect Over Led Error 
		HInspectOverLedErrorCaptureCross = NULL;
	}
};

struct stInspectRegion
{
	HRGN HModuleInspectRegion;
	HRGN HLedInspectRegion[DEF_MAX_LED_COUNT];	
	HRGN HOverLedInspectRegion;	 // Over Led

	stInspectRegion()
	{
		Destroy();
	}
	void Destroy()
	{
		if (HModuleInspectRegion)
		{
			DeleteObject(HModuleInspectRegion);
			HModuleInspectRegion = NULL;
		}
		if (HOverLedInspectRegion)
		{
			DeleteObject(HOverLedInspectRegion);
			HOverLedInspectRegion = NULL;
		}
		for(int i = 0; i < DEF_MAX_LED_COUNT; i++)
		{
			if (HLedInspectRegion[i])
				DeleteObject(HLedInspectRegion[i]);
		}
	}
};

// Region Data
struct stRegionData
{
	double dLTPoint_X;
	double dLTPoint_Y;
	double dRBPoint_X;
	double dRBPoint_Y;

	stRegionData()
	{
		dLTPoint_X = 0.0;
		dLTPoint_Y = 0.0;
		dRBPoint_X = 0.0;
		dRBPoint_Y = 0.0;
	}
};

// Module Region Data
struct stInspectRegionData
{
	stRegionData stModuleRegionData;
	stRegionData stLedRegionData[DEF_MAX_LED_COUNT];

	int iLedCount;

	stInspectRegionData()
	{
		iLedCount = 0;
	}
};


struct stInspectResultData
{
	bool bError;
	int	iLedCount;

	int iLedSize[DEF_MAX_LED_COUNT];

	// Over Led
	bool bOverError;
	int iOverLedCount;
	int iErrorLedCount;
	DPoint dpOverLedPos[DEF_MAX_LED_COUNT];
	// 

	stInspectResultData()
	{
		bError = FALSE;
		iLedCount = 0;

		// Over Led
		bOverError = FALSE;
		iOverLedCount = 0;
		iErrorLedCount = 0;
		//

		for(int i = 0; i < DEF_MAX_LED_COUNT; i++)
		{
			iLedSize[i] = 0;

			// Over Led
			dpOverLedPos[i].x = -1;
			dpOverLedPos[i].y = -1;
			// 
		}
	}
};

struct stTrainInspectLEDSize
{
	int iTranedLEDSize[DEF_MAX_LED_COUNT];
	double dCenterPos_X[DEF_MAX_LED_COUNT];
	double dCenterPos_Y[DEF_MAX_LED_COUNT];
	int iTranedLEDCount;

	stTrainInspectLEDSize()
	{
		ZeroMemory(iTranedLEDSize, sizeof(int) * DEF_MAX_LED_COUNT);
		ZeroMemory(dCenterPos_X, sizeof(double) * DEF_MAX_LED_COUNT);
		ZeroMemory(dCenterPos_Y, sizeof(double) * DEF_MAX_LED_COUNT);
		iTranedLEDCount = 0;
	}
};


struct stTrainInspectResultData
{
	int iLedCount;
	int iLedSize[DEF_MAX_LED_COUNT];
	double dCenterPos_X[DEF_MAX_LED_COUNT];
	double dCenterPos_Y[DEF_MAX_LED_COUNT];
	RECT rtLED[DEF_MAX_LED_COUNT];
	//RECT* rtLED;

	int iLedMinSize;

	stTrainInspectResultData()
	{
		iLedCount = 0;

		iLedMinSize = 0;

		//rtLED = new RECT[DEF_MAX_LED_COUNT];

		for(int i = 0; i < DEF_MAX_LED_COUNT; i++)
		{
			iLedSize[i] = 0;
			dCenterPos_X[i] = 0.0;
			dCenterPos_Y[i] = 0.0;
			SetRectEmpty(&rtLED[i]);
		}
	}
	~stTrainInspectResultData()
	{
		//delete [] rtLED;
	}
};