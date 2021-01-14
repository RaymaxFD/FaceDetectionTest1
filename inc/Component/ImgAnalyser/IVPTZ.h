
#pragma once

class IVPTZ
{
public:	
	virtual bool PanLeft(int iStep = 10) = 0;
	virtual bool PanRight(int iStep = 10) = 0;
	virtual bool TiltUp(int iStep = 10) = 0;
	virtual bool TiltDown(int iStep = 10) = 0;
	virtual bool ZoomIn(int iStep = 10) = 0;
	virtual bool ZoomOut(int iStep = 10) = 0;
};
