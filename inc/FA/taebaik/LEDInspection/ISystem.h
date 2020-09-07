#pragma once

#include "mil.h"
#include <IBase.h>

class ISystem_V1 : public IBase
{
public:
	virtual bool Load() = 0;
	virtual void UnLoad() = 0;

public:
	virtual MIL_INT  GetDigitizerSizeX() = 0;     // Digitizer input width
	virtual MIL_INT  GetDigitizerSizeY() = 0;     // Digitizer input height
	virtual MIL_INT  GetDigitizerNbBrands() = 0;  // Number of input color bands of the digitizer
	//CView*   m_pGrabView;         // Pointer to the view that has the grab
	virtual MIL_ID   GetMilApplication() = 0;     // Application identifier.  
	virtual MIL_ID   GetMilSystem() = 0;          // System identifier.       
	virtual MIL_ID   GetMilDigitizer() = 0;       // Digitizer identifier.
};
