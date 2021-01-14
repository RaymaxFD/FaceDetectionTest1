
#pragma once

struct _stPerson
{
	int iID;
	char strID[MAX_PATH];
	bool bSex;
	int iAge;
};

enum _eCancerType
{
	eCancerCRC,
	eCancerGC,
	eCancerBRC,
	eCancerLC,
	eCancerOVC,
};

enum _eCRCRef
{
	eCRC1,
	eCRC2,
};

struct _stCancerFile
{
	CString strWorking; // 암별/기준파일별 폴더
	CString strMass; // 암별 기준 파일들을 mv에 넘겨 출력된 파일의 가장 좌측 열. 질량임.
	CString str2ndCol; // 암별 기준 파일들을 mv에 넘겨 출력된 파일의 두 번째 열.
	CString strAverage; // nRef의 Intensity들의 평균
	CString strSD; // nRef의 Intensity들의 표준 편차 파일
	CString strWeighttingFactor; // 가중치 파일
};

struct _stResultCRC
{
	CString strScreenee;
	double dScore1;
	double dScore2;
	DATE m_dtScreening;
};