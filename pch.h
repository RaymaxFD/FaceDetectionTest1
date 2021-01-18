// pch.h: 미리 컴파일된 헤더 파일입니다.
// 아래 나열된 파일은 한 번만 컴파일되었으며, 향후 빌드에 대한 빌드 성능을 향상합니다.
// 코드 컴파일 및 여러 코드 검색 기능을 포함하여 IntelliSense 성능에도 영향을 미칩니다.
// 그러나 여기에 나열된 파일은 빌드 간 업데이트되는 경우 모두 다시 컴파일됩니다.
// 여기에 자주 업데이트할 파일을 추가하지 마세요. 그러면 성능이 저하됩니다.

#ifndef PCH_H
#define PCH_H

// 여기에 미리 컴파일하려는 헤더 추가
#include "framework.h"
#include <afxsock.h>

#include <afxsock.h>            // MFC socket extensions

#include <IBaseDll.h> // DLL 파일들을 지칭하는 GUID들
#include <IBaseGUID.h> // DLL 안에 들어 있는 인터페이스들을 지칭하는 GUID들
#include <IV_MACRO.h> // 잡다한 매크로들

enum _eMsg
{
	msgFaceBegin = WM_APP,
	msgFaceFound,
	msgLicenseFail,

	msgVideoY,
	msgVideoU,
	msgVideoV,

	msgNewFaceNew,
	msgNewFaceLT,
	msgNewFaceRB,
};

//#define DEBUG_VIDEO

#endif //PCH_H
