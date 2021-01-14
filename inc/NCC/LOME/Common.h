
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
	CString strWorking; // �Ϻ�/�������Ϻ� ����
	CString strMass; // �Ϻ� ���� ���ϵ��� mv�� �Ѱ� ��µ� ������ ���� ���� ��. ������.
	CString str2ndCol; // �Ϻ� ���� ���ϵ��� mv�� �Ѱ� ��µ� ������ �� ��° ��.
	CString strAverage; // nRef�� Intensity���� ���
	CString strSD; // nRef�� Intensity���� ǥ�� ���� ����
	CString strWeighttingFactor; // ����ġ ����
};

struct _stResultCRC
{
	CString strScreenee;
	double dScore1;
	double dScore2;
	DATE m_dtScreening;
};