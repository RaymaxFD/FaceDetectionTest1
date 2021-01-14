
#pragma once

struct _stProd
{
	DWORD dwWidth;
	DWORD dwHeight;
};

struct _stGroup
{
	_stProd stProd;
	UINT uiProdRow;
	UINT uiProdCol;
	DWORD dwProdRowPitch;
	DWORD dwProdColPitch;
};

struct _stSheet
{
	_stGroup stGroup;
	BYTE ucGroupRow;
	BYTE ucGroupCol;
	DWORD dwGroupRowPitch;
	DWORD dwGroupColPitch;
	DWORD dwStartYFront;
	DWORD dwStartYRear;
	DWORD dwStepPos[8];
	BYTE ucLight[4];
	DWORD dwDelay;
	BYTE ucThres;
	DWORD dwCuttingLine;
	DWORD dwROIWidth;
	DWORD dwROIHeight;
	int iMarginLeft;
	int iMarginTop;
	int iMarginRight;
	int iMarginBottom;
	TCHAR strPatternFrontLeft[MAX_PATH];
	TCHAR strPatternFrontRight[MAX_PATH];
	TCHAR strPatternRearLeft[MAX_PATH];
	TCHAR strPatternRearRight[MAX_PATH];
	bool bPlane;
	double dOffsetFront;
	double dOffsetRear;
};
