

#pragma once

#include <IBase.h>

class IEvtDB_V1;
class IBuffer;

class IDB_V1 : public IBase
{
public:
	struct _stPerson
	{
		int iID;
		char strID[MAX_PATH];
		bool bSex;
		int iAge;
	};
	struct _stRecommendation
	{
		int iPersonID;
		int iCRC;
		int iGC;
		int iBRC;
		int iLC;
		int iOVC;
		char strDate[MAX_PATH];
	};
	struct _stFinalScore
	{
		int iPersonID;
		int iCRC;
		int iGC;
		int iBRC;
		int iLC;
		int iOVC;
		char strDate[MAX_PATH];
	};
	struct _stScores
	{
		int iPersonID;
		double dCRC1;
		double dCRC2;
		char strDate[MAX_PATH];
	};
	struct _stDoctorComment
	{
		int iPersonID;
		char strComment[MAX_PATH];
		char strDate[MAX_PATH];
	};
	struct _stInspection
	{
		int iPersonID;
		char strDate[MAX_PATH];
	};

public:
	virtual void AddIEvent(IEvtDB_V1* pI) = 0;

public:
	virtual bool OpenDB(TCHAR* pStr) = 0;
	virtual void CloseDB() = 0;

	// Person
public:
	virtual bool PersonNew(TCHAR* strID, bool bSex, int iAge) = 0;
	virtual bool PersonEdit(int iID, TCHAR* strID, bool bSex, int iAge) = 0;
	virtual bool PersonDel(int iID) = 0;

	// Recommendation
public:
	virtual bool RecommendationNew(_stRecommendation& stRecommendation) = 0;	
	virtual bool RecommendationEdit(int iID, TCHAR* strID, int iCRC, int iGC, int iBRC, int iLC, int iOVC) = 0;	
	virtual bool RecommendationDel(int iID) = 0;

	// Final Score
public:
	virtual bool ScoresNew(_stScores& stScores) = 0;
	virtual bool ScoresEdit(int iID, TCHAR* strID, double dCRC1, double dCRC2) = 0;
	virtual bool ScoresDel(int iID) = 0;

	// Scores
public:
	virtual bool FinalScoreNew(_stFinalScore& stFinalScore) = 0;
	virtual bool FinalScoreEdit(int iID, int iPerson, int iCRC, int iGC, int iBRC, int iLC, int iOVC) = 0;
	virtual bool FinalScoreDel(int iID) = 0;

	// Doctor Comment
public:
	virtual bool DoctorCommentNew(_stDoctorComment& stDoctorComment) = 0;
	virtual bool DoctorCommentEdit(int iID, TCHAR* strComment) = 0;
	virtual bool DoctorCommentDel(int iID, TCHAR* strComment) = 0;

	// Inspection
public:
	virtual bool InspectionNew(int iPerson, _stRecommendation& stRecommendation, _stFinalScore& stFinalScore, _stScores& stScores, _stDoctorComment& stDoctorComment) = 0;
	virtual bool InspectionEdit(int iID, TCHAR* strID, int iRecommendation, int iFinalCore, int iScores, int iDoctorComment, TCHAR* strDate) = 0;
	virtual bool InspectionDel(int iID) = 0;

	// Query
public:
	virtual bool QueryInspection(int iPerson, char* strBegin = NULL, char* strEnd = NULL, bool bCount = false) = 0;
	virtual bool QueryRecommendation(int iPerson, char (&strDate)[MAX_PATH], bool bCount = false) = 0;
	virtual bool QueryScoresCRC(int iPerson, char (&strDate)[MAX_PATH], bool bCount = false) = 0;
	virtual bool QueryFinalScore(int iPerson, char (&strDate)[MAX_PATH], bool bCount = false) = 0;
	virtual bool QueryDoctorComment(int iPerson, char (&strDate)[MAX_PATH], bool bCount = false) = 0;
	virtual bool QueryPerson(TCHAR* strPerson, bool bCount = false) = 0;
	// Count
	virtual bool QueryPersonCount() = 0;
	virtual bool QueryRecommendationCount() = 0;
	virtual bool QueryScoresCRCCount() = 0;
	virtual bool QueryFinalScoreCount() = 0;
	virtual bool QueryDoctorCommentCount() = 0;
	virtual bool QueryInspectionCount() = 0;
};


class IEvtDB_V1
{
public:
	virtual void IEvtDBPerson(IBuffer* pIBuff){}
	virtual void IEvtDBRecommendation(IBuffer* pIBuff){}
	virtual void IEvtDBFinalScore(IBuffer* pIBuff){}
	virtual void IEvtDBDoctorComment(IBuffer* pIBuff){}
	virtual void IEvtDBInspection(IBuffer* pIBuff){}
	virtual void IEvtDBScoresCRC(IBuffer* pIBuff){}
public:
	virtual void IEvtDBPersonCount(DWORD dwCnt){}
	virtual void IEvtDBInspectionCount(DWORD dwCnt){}
	virtual void IEvtDBRecommendationCount(DWORD dwCnt){}
	virtual void IEvtDBFinalScoreCount(DWORD dwCnt){}
	virtual void IEvtDBDoctorCommentCount(DWORD dwCnt){}
	virtual void IEvtDBScoresCRCCount(DWORD dwCnt){}
};











class IEvtDB_V2;

class IDB_V2 : public IBase
{
public:
	enum _eExcute
	{
		eExcPersonNew,
		eExcRecommendationNew,
		eExcScoresCRCNew,
		eExcFianlScoreNew,
		eExcDoctorCommenNew,
		eExcDoctorCommentEdit,
	};

public:
	enum _eQuery
	{
		eQueryNone,
		eQueryPerson,
		eQueryPersonCnt,
		eQueryRecommendation,
		eQueryRecommendationCnt,
		eQueryScoresCRC,
		eQueryScoresCRCCnt,
		eQueryFinalScore,
		eQueryFinalScoreCnt,
		eQueryDoctorComment,
		eQueryDoctorCommentCnt,
		eQueryInspection,
		eQueryInspectionCnt,
	};
public:
	struct _stPerson
	{
		int iID;
		char strID[MAX_PATH];
		bool bSex;
		int iAge;
	};
	struct _stRecommendation
	{
		int iPersonID;
		int iCRC;
		int iGC;
		int iBRC;
		int iLC;
		int iOVC;
		char strDate[MAX_PATH];
	};
	struct _stFinalScore
	{
		int iPersonID;
		int iCRC;
		int iGC;
		int iBRC;
		int iLC;
		int iOVC;
		char strDate[MAX_PATH];
	};
	struct _stScoresCRC
	{
		int iPersonID;
		double dCRC1;
		double dCRC2;
		char strDate[MAX_PATH];
		bool bDel;
	};
	struct _stDoctorComment
	{
		int iPersonID;
		TCHAR strComment[MAX_PATH];
		char strDate[MAX_PATH];
	};
	struct _stInspection
	{
		int iPersonID;
		char strDate[MAX_PATH];
	};

public:
	virtual void AddIEvent(IEvtDB_V2* pI) = 0;

public:
	virtual bool OpenDB(TCHAR (&strServer)[MAX_PATH], TCHAR (&strUser)[MAX_PATH], TCHAR (&strPW)[MAX_PATH], TCHAR (&strDB)[MAX_PATH]) = 0;
	virtual void CloseDB() = 0;

	// Person
public:
	virtual bool PersonNew(TCHAR* strID, bool bSex, int iAge) = 0;
	virtual bool PersonEdit(int iID, TCHAR* strID, bool bSex, int iAge) = 0;
	virtual bool PersonDel(int iID) = 0;
	virtual bool PersonQuery(TCHAR* strPerson, bool bCount = false) = 0;

	// Recommendation
public:
	virtual bool RecommendationNew(_stRecommendation& stRecommendation) = 0;	
	virtual bool RecommendationEdit(int iID, TCHAR* strID, int iCRC, int iGC, int iBRC, int iLC, int iOVC) = 0;	
	virtual bool RecommendationDel(int iID) = 0;
	virtual bool RecommendationQuey(int iPerson, char (&strDateFrom)[MAX_PATH], char (&strDateTo)[MAX_PATH], bool bCount = false) = 0;

	// Score
public:
	virtual bool ScoresCRCNew(_stScoresCRC& stScores) = 0;
	virtual bool ScoresCRCEdit(int iID, TCHAR* strID, double dCRC1, double dCRC2) = 0;
	virtual bool ScoresCRCDel(int iID) = 0;
	virtual bool ScoresCRCQuery(int iPerson, char (&strDateFrom)[MAX_PATH], char (&strDateTo)[MAX_PATH], bool bCount = false) = 0;
	virtual bool ScoresCRCQueryScreenee(int iPerson, char (&strDateFrom)[MAX_PATH], char (&strDateTo)[MAX_PATH], bool bAsc, bool bCount = false) = 0;
	virtual bool ScoresCRCQueryDate(int iPerson, char (&strDateFrom)[MAX_PATH], char (&strDateTo)[MAX_PATH], bool bAsc, bool bCount = false) = 0;

	// Final Scores
public:
	virtual bool FinalScoreNew(_stFinalScore& stFinalScore) = 0;
	virtual bool FinalScoreEdit(int iID, int iPerson, int iCRC, int iGC, int iBRC, int iLC, int iOVC) = 0;
	virtual bool FinalScoreDel(int iID) = 0;
	virtual bool FinalScoreQuery(int iPerson, char (&strDateFrom)[MAX_PATH], char (&strDateTo)[MAX_PATH], bool bCount = false) = 0;

	// Doctor Comment
public:
	virtual bool DoctorCommentNew(_stDoctorComment& stDoctorComment) = 0;
	virtual bool DoctorCommentEdit(int iPerson, TCHAR* strComment) = 0;
	virtual bool DoctorCommentEdit(int iPerson, char (&strDate)[MAX_PATH], TCHAR* strComment) = 0;
	virtual bool DoctorCommentDel(int iID, TCHAR* strComment) = 0;
	virtual bool DoctorCommentQuery(int iPerson, char (&strDateFrom)[MAX_PATH], char (&strDateTo)[MAX_PATH], bool bCount = false) = 0;
	virtual bool DoctorCommentQuery(int iPerson, char (&strDate)[MAX_PATH]) = 0;

	// Inspection
public:
	virtual bool InspectionNew(int iPerson, _stRecommendation& stRecommendation, _stFinalScore& stFinalScore, _stScoresCRC& stScores, _stDoctorComment& stDoctorComment) = 0;
	virtual bool InspectionEdit(int iID, TCHAR* strID, int iRecommendation, int iFinalCore, int iScores, int iDoctorComment, TCHAR* strDate) = 0;
	virtual bool InspectionDel(int iID) = 0;
	virtual bool InspectionQuery(int iPerson, char* strBegin = NULL, char* strEnd = NULL, bool bCount = false) = 0;

	// Reset
public:
	virtual void ResetResultCRC() = 0;
};


class IEvtDB_V2
{
public:
	virtual void IEvtDBQueryStart(IDB_V2::_eQuery eQuery){}
	virtual void IEvtDBQueryEnd(IDB_V2::_eQuery eQuery){}
public:
	virtual void IEvtDBPerson(IDB_V2::_stPerson&){}
	virtual void IEvtDBRecommendation(IDB_V2::_stRecommendation){}
	virtual void IEvtDBFinalScore(IDB_V2::_stFinalScore){}
	virtual void IEvtDBDoctorComment(IDB_V2::_stDoctorComment){}
	virtual void IEvtDBInspection(IDB_V2::_stInspection){}
	virtual void IEvtDBScoresCRC(IDB_V2::_stScoresCRC&){}
public:
	virtual void IEvtDBPersonCount(DWORD dwCnt){}
	virtual void IEvtDBInspectionCount(DWORD dwCnt){}
	virtual void IEvtDBRecommendationCount(DWORD dwCnt){}
	virtual void IEvtDBFinalScoreCount(DWORD dwCnt){}
	virtual void IEvtDBDoctorCommentCount(DWORD dwCnt){}
	virtual void IEvtDBScoresCRCCount(DWORD dwCnt){}
public:
	virtual void IEvtDBExcute(int iExcute){}
};
