
#pragma once

#include <IBase.h>

class IEvtIO_V1;
class IAlphaMotionBA432P_V1;
class IIO_V1 : public IBase
{
public:
	virtual void SetIAM(IAlphaMotionBA432P_V1* pIAM) = 0;

public:
	virtual void AddIEvent(IEvtIO_V1* pI) = 0;

public:
	virtual void OutBallFeeder(bool bOut) = 0;
	virtual void OutLineFeeder(bool bOut) = 0;
	virtual void OutCyli_1_Up(bool bOut) = 0;
	virtual void OutCyli_1_Down(bool bOut) = 0;
	virtual void OutCyli_1_VacuOn(bool bOut) = 0;
	virtual void OutCyli_1_VacuOff(bool bOut) = 0;
	virtual void OutCyli_2_Up(bool bOut) = 0;
	virtual void OutCyli_2_Down(bool bOut) = 0;
	virtual void OutCyli_2_VacuOn(bool bOut) = 0;
	virtual void OutCyli_2_VacuOff(bool bOut) = 0;
	virtual void OutCyli_3_Up(bool bOut) = 0;
	virtual void OutCyli_3_Down(bool bOut) = 0;
	virtual void OutCyli_3_VacuOn(bool bOut) = 0;
	virtual void OutCyli_3_VacuOff(bool bOut) = 0;
	virtual void OutCaptStagVacOn(bool bOut) = 0;
	virtual void OutCaptStagVacOff(bool bOut) = 0;
	virtual void OutBuffStagVacOn(bool bOut) = 0;
	virtual void OutBuffStagVacOff(bool bOut) = 0;
	virtual void OutToweLamp1(bool bOut) = 0;
	virtual void OutToweLamp2(bool bOut) = 0;
	virtual void OutToweLamp3(bool bOut) = 0;
	virtual void OutBuzz(bool bOut) = 0;
	virtual void OutStopBttnLed(bool bOut) = 0;
	virtual void OutStrtBttnLed(bool bOut) = 0;

public:
	virtual bool InBallFeeder() = 0;
	virtual bool InLineFeeder() = 0;
	virtual bool InCyli_1_Down() = 0;
	virtual bool InCyli_2_Down() = 0;
	virtual bool InCyli_3_Down() = 0;
	virtual bool InStopBttn() = 0;
	virtual bool InServOn() = 0;
	virtual bool InStrtBttn() = 0;
	virtual bool InEmgrBttn() = 0;
	virtual bool InDoorOpen() = 0;
	virtual bool InMainAir() = 0;
	virtual bool InMainVacc() = 0;

};

class IEvtIO_V1
{
public:
	virtual void EvtInBallFeeder(bool bOn)                       {}
	virtual void EvtInLineFeeder(bool bOn)                       {}
	virtual void EvtInCyli_1_Down(bool bOn)                      {}
	virtual void EvtInCyli_2_Down(bool bOn)                      {}
	virtual void EvtInCyli_3_Down(bool bOn)                      {}
	virtual void EvtInStopBttn(bool bOn)                         {}
	virtual void EvtInServOn(bool bOn)                           {}
	virtual void EvtInStrtBttn(bool bOn)                         {}
	virtual void EvtInEmgrBttn(bool bOn)                         {}
	virtual void EvtInDoorOpen(bool bOn)                         {}
	virtual void EvtInMainAir(bool bOn)                          {}
	virtual void EvtInMainVacc(bool bOn)                         {}
};

