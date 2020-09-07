
#pragma once

#include <IWorker.h>

class IMP3Player_V1 : public IWorker
{
public:
	virtual bool LoadDLL(LPCWSTR dll) = 0;
	virtual void UnloadDLL() = 0;

	virtual bool Load(LPCWSTR filename) = 0;
	virtual bool Cleanup() = 0;

	virtual bool Play() = 0;
	virtual bool Pause() = 0;
	virtual bool Stop() = 0;
	virtual bool WaitForCompletion(long msTimeout, long* EvCode) = 0;

	virtual bool SetVolume(long vol) = 0;
	virtual long GetVolume() = 0;

	virtual __int64 GetDuration() = 0;
	virtual __int64 GetCurrentPosition() = 0;

	// Seek to position
	virtual bool SetPositions(__int64* pCurrent, __int64* pStop, bool bAbsolutePositioning) = 0;
};