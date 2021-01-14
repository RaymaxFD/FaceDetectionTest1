

#pragma once
#include <media/imedia.h>
#include <IWorker.h>

class IBufferPool;
class IString;

class IMountType
{
public:
	enum _eMountType
	{
		eMountNone = -1,
		eMountCeiling,
		eMountWall,
		eMountWallDiagonal,
	};
};

class IWideAngle360_V1 : public IMedia, public IWorker, public IMountType
{
public:
	virtual void SetMountType(_eMountType eType) = 0;                                              // Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¼³Á¤
	virtual _eMountType GetMountType() = 0;                                                        // ¼³Á¤µÈ Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¾ò±â
public:
	virtual void Enable(bool b) = 0;                                                               // ±¤°¢ Ã³¸® ¿©ºÎ. false·Î ¼³Á¤ÇÏ¸é ¾î¾È ¿µ»óÀÌ ±×´ë·Î Ãâ·ÂµÊ.

	virtual bool Init(HWND hWnd = NULL) = 0;                                                       // ÃÊ±âÈ­
	virtual void AllocPotBuffer(bool b1024) = 0;                                                   // ¹Ì»ç¿ë

	virtual void SetFishCenter(int iCenterX, int iCenterY) = 0;                                    // ¾î¾È ¿µ»óÀÇ Áß½É ¼³Á¤
	virtual void GetFishCenter(int& iCenterX, int& iCenterY) = 0;                                  // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ Áß½É ¾ò±â

	virtual void SetFishDimension(DWORD dwFishWidth, DWORD dwFishHeight) = 0;                      // ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¼³Á¤
	virtual void GetFishDimension(DWORD& dwFishWidth, DWORD& dwFishHeight) = 0;                    // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¾ò±â

	virtual void SetFOVDeg(double d) = 0;                                                          // ¾î¾È ¿µ»óÀÇ È­°¢ ¼³Á¤

	virtual void SetLenzMaxRPixel(int i) = 0;                                                      // ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¼³Á¤
	virtual void GetLenzMaxRPixel(int& i) = 0;                                                     // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¾ò±â

	virtual void SetLenzPixelSize(double d) = 0;                                                   // CCD³ª CMOSÀÇ ÇÈ¼¿ Å©±â ¼³Á¤
	virtual void SetSphereR(double d) = 0;	                                                       // °¡»óÀÇ °ø°£»óÀÇ ±¸¸é ¹ÝÁö¸§.
	virtual void MakeMap() = 0;                                                                    // 2D -> 3D º¯È¯ ÁÂÇ¥µé °è»ê
	virtual void SetPanTiltAngle(int iPan, int iTilt) = 0;                                         // ¹Ù¶óº¸´Â Pan/Tilt °¢µµ ¼³Á¤
	virtual void GetPanTiltAngle(int& iPan, int& iTilt) = 0;                                       // ÇöÀç ¼³Á¤µÈ Pan/Tilt °¢µµ ÀÐ±â
	virtual void GetImgPot(BYTE** ppImg, int& iWidth, int& iHeight, int& iDepth) = 0;              // 2ÀÇ ÀÚ½ÂÀ¸·Î Å©±â°¡ º¯È­µÈ ÀÌ¹ÌÁö ¾ò±â
	virtual void SetOutSize(int iW, int iH) = 0;                                                   // Ãâ·Â ¿µ»óÀÇ Å©±â ¼³Á¤
	virtual void GetOutSize(int& iW, int& iH) = 0;                                                 // ¼³Á¤µÈ Ãâ·Â ¿µ»óÀÇ Å©±â ¾ò±â
	virtual void SavePanoImg(TCHAR* pFilePath) = 0;                                                // Ãâ·Â ¿µ»óÀÇ ÀúÀå
	virtual void SetDetailLevel(double dStep = 0.05) = 0;                                          // ±¤°¢ Ã³¸® Ç°Áú ¼³Á¤

	virtual void SetDiagonalTheta(double d) = 0;                                                   // »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¼³Á¤
	virtual double GetDiagonalTheta() = 0;                                                         // ¼³Á¤µÈ »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¾ò±â

public:
	virtual void SetCustomContextID(DWORD dw) = 0;                                                 // ÀÓÀÇ·Î ¼³Á¤µÇ´Â ContextID
	virtual void SetUVOrder(bool b) = 0;                                                           // ¹Ì»ç¿ë
};






class IWideAngle360_V2 : public IMedia, public IWorker, public IMountType
{
public:
	virtual void SetMountType(_eMountType eType) = 0;                                              // Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¼³Á¤
	virtual _eMountType GetMountType() = 0;                                                        // ¼³Á¤µÈ Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¾ò±â
public:
	virtual void Enable(bool b) = 0;                                                               // ±¤°¢ Ã³¸® ¿©ºÎ. false·Î ¼³Á¤ÇÏ¸é ¾î¾È ¿µ»óÀÌ ±×´ë·Î Ãâ·ÂµÊ.

	virtual bool Init(HWND hWnd = NULL) = 0;                                                       // ÃÊ±âÈ­

	virtual void SetFishCenter(int iCenterX, int iCenterY) = 0;                                    // ¾î¾È ¿µ»óÀÇ Áß½É ¼³Á¤
	virtual void GetFishCenter(int& iCenterX, int& iCenterY) = 0;                                  // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ Áß½É ¾ò±â

	virtual void SetFishDimension(DWORD dwFishWidth, DWORD dwFishHeight) = 0;                      // ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¼³Á¤
	virtual void GetFishDimension(DWORD& dwFishWidth, DWORD& dwFishHeight) = 0;                    // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¾ò±â

	virtual void SetFOVDeg(double d) = 0;                                                          // ¾î¾È ¿µ»óÀÇ È­°¢ ¼³Á¤

	virtual void SetLenzMaxRPixel(int i) = 0;                                                      // ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¼³Á¤
	virtual void GetLenzMaxRPixel(int& i) = 0;                                                     // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¾ò±â

	virtual void SetLenzPixelSize(double d) = 0;                                                   // CCD³ª CMOSÀÇ ÇÈ¼¿ Å©±â ¼³Á¤
	virtual void SetSphereR(double d) = 0;                                                         // °¡»óÀÇ °ø°£»óÀÇ ±¸¸é ¹ÝÁö¸§.
	virtual void MakeMap() = 0;                                                                    // 2D -> 3D º¯È¯ ÁÂÇ¥µé °è»ê
	virtual void SetPanTiltAngle(int iSubChannel, int iPan, int iTilt) = 0;                        // ¹Ù¶óº¸´Â Pan/Tilt °¢µµ ¼³Á¤. ³»ºÎÀûÀ¸·Î 4°³ÀÇ ¼­ºê Ã¤³ÎÁß¿¡¼­ ¼±ÅÃµÈ °ÍÀ» Á¦¾îÇÑ´Ù.
	virtual void GetPanTiltAngle(int iSubChannel, int& iPan, int& iTilt) = 0;                      // ÇöÀç ¼³Á¤µÈ Pan/Tilt °¢µµ ÀÐ±â. ³»ºÎÀûÀ¸·Î 4°³ÀÇ ¼­ºê Ã¤³ÎÁß¿¡¼­ ¼±ÅÃµÈ °ÍÀ» Á¦¾îÇÑ´Ù.
	virtual void SetOutSize(int iW, int iH) = 0;                                                   // Ãâ·Â ¿µ»óÀÇ Å©±â ¼³Á¤
	virtual void GetOutSize(int& iW, int& iH) = 0;                                                 // ¼³Á¤µÈ Ãâ·Â ¿µ»óÀÇ Å©±â ¾ò±â
	virtual void SavePanoImg(int iSubChannel, TCHAR* pFilePath) = 0;                                                // Ãâ·Â ¿µ»óÀÇ ÀúÀå. ³»ºÎÀû Ã¤³Î Áß¿¡¼­ ¼±ÅÃÇÔ.
	virtual void SetDetailLevel(double dStep = 0.05) = 0;                                          // ±¤°¢ Ã³¸® Ç°Áú ¼³Á¤

	virtual void SetDiagonalTheta(double d) = 0;                                                   // »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¼³Á¤
	virtual double GetDiagonalTheta() = 0;                                                         // ¼³Á¤µÈ »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¾ò±â

public:
	virtual void SetCustomContextID(DWORD dw) = 0;                                                 // ÀÓÀÇ·Î ¼³Á¤µÇ´Â ContextID
};


/*
5M ¾î¾È ¿µ»ó¿ë
*/
class IWideAngle360_V3 : public IWideAngle360_V2
{
};


/*
10M ¾î¾È ¿µ»ó¿ë
*/
class IWideAngle360_V4 : public IWideAngle360_V2
{
};

/*
YUV Á÷Á¢ texture mapping
glReadPixelsÀÇ °¡¼Ó
*/
class IWideAngle360_V5 : public IWideAngle360_V2
{
public:
	virtual void SetPoolOut(IBufferPool* pI) = 0;

public:
	virtual void ZoomIn(int iStep = 10) = 0;                                                       // È­¸é È®´ë
	virtual void ZoomOut(int iStep = 10) = 0;                                                      // È­¸é Ãà¼Ò
};

class IResolution
{
public:
	enum _eResolution
	{
		_None,
		_2M,
		_3M,
		_5M,
		_10M,
		_12M,
	};
};

/*
YUV Á÷Á¢ texture mapping
glReadPixelsÀÇ °¡¼Ó
ºÎºÐ texture mapping
*/
class IWideAngle360_V6 : public IMedia, public IWorker, public IResolution, public IMountType
{
public:
	virtual void SetMountType(_eMountType eType) = 0;                                              // Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¼³Á¤
	virtual _eMountType GetMountType() = 0;                                                        // ¼³Á¤µÈ Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¾ò±â
public:
	virtual void Enable(bool b) = 0;                                                               // ±¤°¢ Ã³¸® ¿©ºÎ. false·Î ¼³Á¤ÇÏ¸é ¾î¾È ¿µ»óÀÌ ±×´ë·Î Ãâ·ÂµÊ.

	virtual void Init(HWND hWnd = NULL) = 0;                                                       // ÃÊ±âÈ­

	virtual void SetFishCenter(int iCenterX, int iCenterY) = 0;                                    // ¾î¾È ¿µ»óÀÇ Áß½É ¼³Á¤
	virtual void GetFishCenter(int& iCenterX, int& iCenterY) = 0;                                  // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ Áß½É ¾ò±â

	virtual void SetFishDimension(DWORD dwFishWidth, DWORD dwFishHeight) = 0;                      // ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¼³Á¤
	virtual void GetFishDimension(DWORD& dwFishWidth, DWORD& dwFishHeight) = 0;                    // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¾ò±â

	virtual void SetFOVDeg(double d) = 0;                                                          // ¾î¾È ¿µ»óÀÇ È­°¢ ¼³Á¤

	virtual void SetLenzMaxRPixel(int i) = 0;                                                      // ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¼³Á¤
	virtual void GetLenzMaxRPixel(int& i) = 0;                                                     // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¾ò±â

	virtual void SetLenzPixelSize(double d) = 0;                                                   // CCD³ª CMOSÀÇ ÇÈ¼¿ Å©±â ¼³Á¤
	virtual void SetSphereR(double d) = 0;                                                         // °¡»óÀÇ °ø°£»óÀÇ ±¸¸é ¹ÝÁö¸§.
	virtual void MakeMap() = 0;                                                                    // 2D -> 3D º¯È¯ ÁÂÇ¥µé °è»ê
	virtual void SetPanTiltAngle(int iPan, int iTilt) = 0;                        // ¹Ù¶óº¸´Â Pan/Tilt °¢µµ ¼³Á¤. ³»ºÎÀûÀ¸·Î 4°³ÀÇ ¼­ºê Ã¤³ÎÁß¿¡¼­ ¼±ÅÃµÈ °ÍÀ» Á¦¾îÇÑ´Ù.
	virtual void GetPanTiltAngle(int& iPan, int& iTilt) = 0;                      // ÇöÀç ¼³Á¤µÈ Pan/Tilt °¢µµ ÀÐ±â. ³»ºÎÀûÀ¸·Î 4°³ÀÇ ¼­ºê Ã¤³ÎÁß¿¡¼­ ¼±ÅÃµÈ °ÍÀ» Á¦¾îÇÑ´Ù.
	virtual void SetOutSize(int iW, int iH) = 0;                                                   // Ãâ·Â ¿µ»óÀÇ Å©±â ¼³Á¤
	virtual void GetOutSize(int& iW, int& iH) = 0;                                                 // ¼³Á¤µÈ Ãâ·Â ¿µ»óÀÇ Å©±â ¾ò±â
	virtual void SavePanoImg(TCHAR* pFilePath) = 0;                               // Ãâ·Â ¿µ»óÀÇ ÀúÀå. ³»ºÎÀû Ã¤³Î Áß¿¡¼­ ¼±ÅÃÇÔ.
	virtual void SetDetailLevel(double dStep = 0.05) = 0;                                          // ±¤°¢ Ã³¸® Ç°Áú ¼³Á¤

	virtual void SetDiagonalTheta(double d) = 0;                                                   // »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¼³Á¤
	virtual double GetDiagonalTheta() = 0;                                                         // ¼³Á¤µÈ »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¾ò±â

public:
	virtual void SetCustomContextID(DWORD dw) = 0;                                                 // ÀÓÀÇ·Î ¼³Á¤µÇ´Â ContextID

public:
	virtual void SetPoolOut(IBufferPool* pI) = 0;

public:
	virtual void ZoomIn(int iStep = 10) = 0;                                                       // È­¸é È®´ë
	virtual void ZoomOut(int iStep = 10) = 0;                                                      // È­¸é Ãà¼Ò

public:
	virtual void SetResolution(_eResolution eResol) = 0;                                           // ¾î¾È ¿µ»ó ÇØ»óµµ
};



/*
HWND¿¡ Á÷Á¢ Ãâ·Â
*/
// single output
class IWideAngle360_V7 : public IMedia, public IWorker, public IResolution, public IMountType
{
public:
	virtual void SetMountType(_eMountType eType) = 0;                                              // Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¼³Á¤
	virtual _eMountType GetMountType() = 0;                                                        // ¼³Á¤µÈ Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¾ò±â
public:
	virtual void Enable(bool b) = 0;                                                               // ±¤°¢ Ã³¸® ¿©ºÎ. false·Î ¼³Á¤ÇÏ¸é ¾î¾È ¿µ»óÀÌ ±×´ë·Î Ãâ·ÂµÊ.

	virtual void Init(HWND hWnd = NULL) = 0;                                                       // ÃÊ±âÈ­
	virtual bool IsInit() = 0;

	virtual void SetFishCenter(int iCenterX, int iCenterY) = 0;                                    // ¾î¾È ¿µ»óÀÇ Áß½É ¼³Á¤
	virtual void GetFishCenter(int& iCenterX, int& iCenterY) = 0;                                  // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ Áß½É ¾ò±â

	virtual void SetFishDimension(DWORD dwFishWidth, DWORD dwFishHeight) = 0;                      // ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¼³Á¤
	virtual void GetFishDimension(DWORD& dwFishWidth, DWORD& dwFishHeight) = 0;                    // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¾ò±â

	virtual void SetFOVDeg(double d) = 0;                                                          // ¾î¾È ¿µ»óÀÇ È­°¢ ¼³Á¤

	virtual void SetLenzMaxRPixel(int i) = 0;                                                      // ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¼³Á¤
	virtual void GetLenzMaxRPixel(int& i) = 0;                                                     // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¾ò±â

	virtual void SetLenzPixelSize(double d) = 0;                                                   // CCD³ª CMOSÀÇ ÇÈ¼¿ Å©±â ¼³Á¤
	virtual void SetSphereR(double d) = 0;                                                         // °¡»óÀÇ °ø°£»óÀÇ ±¸¸é ¹ÝÁö¸§.
	virtual void MakeMap() = 0;                                                                    // 2D -> 3D º¯È¯ ÁÂÇ¥µé °è»ê
	virtual void SetPanTiltAngle(int iPan, int iTilt) = 0;                        // ¹Ù¶óº¸´Â Pan/Tilt °¢µµ ¼³Á¤. ³»ºÎÀûÀ¸·Î 4°³ÀÇ ¼­ºê Ã¤³ÎÁß¿¡¼­ ¼±ÅÃµÈ °ÍÀ» Á¦¾îÇÑ´Ù.
	virtual void GetPanTiltAngle(int& iPan, int& iTilt) = 0;                      // ÇöÀç ¼³Á¤µÈ Pan/Tilt °¢µµ ÀÐ±â. ³»ºÎÀûÀ¸·Î 4°³ÀÇ ¼­ºê Ã¤³ÎÁß¿¡¼­ ¼±ÅÃµÈ °ÍÀ» Á¦¾îÇÑ´Ù.
	virtual void SetOutSize(int iW, int iH) = 0;                                                   // Ãâ·Â ¿µ»óÀÇ Å©±â ¼³Á¤
	virtual void GetOutSize(int& iW, int& iH) = 0;                                                 // ¼³Á¤µÈ Ãâ·Â ¿µ»óÀÇ Å©±â ¾ò±â
	virtual void SavePanoImg(TCHAR (&strFilePath)[MAX_PATH]) = 0;                               // Ãâ·Â ¿µ»óÀÇ ÀúÀå. ³»ºÎÀû Ã¤³Î Áß¿¡¼­ ¼±ÅÃÇÔ.
	virtual void SetDetailLevel(double dStep = 0.05) = 0;                                          // ±¤°¢ Ã³¸® Ç°Áú ¼³Á¤

	virtual void SetDiagonalTheta(double d) = 0;                                                   // »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¼³Á¤
	virtual double GetDiagonalTheta() = 0;                                                         // ¼³Á¤µÈ »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¾ò±â

public:
	virtual void SetCustomContextID(DWORD dw) = 0;                                                 // ÀÓÀÇ·Î ¼³Á¤µÇ´Â ContextID

public:
	virtual void SetPoolOut(IBufferPool* pI) = 0;

public:
	virtual void ZoomIn(int iStep = 10) = 0;                                                       // È­¸é È®´ë
	virtual void ZoomOut(int iStep = 10) = 0;                                                      // È­¸é Ãà¼Ò

public:
	virtual void SetResolution(_eResolution eResol) = 0;                                           // ¾î¾È ¿µ»ó ÇØ»óµµ

public:
	virtual void ScreenShot() = 0;
	virtual void ExportRGB(bool b) = 0;

public:
	virtual void SwapUV(bool b) = 0;
};



/*
À©µµ¿ì 1°³¿¡ 4°³ Ã¤³ÎÀ» Ãâ·Â
*/
// upto 4 output
class IWideAngle360_V8 : public IMedia, public IWorker, public IResolution, public IMountType
{
public:
	virtual void SetMountType(_eMountType eType) = 0;                                              // Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¼³Á¤
	virtual _eMountType GetMountType() = 0;                                                        // ¼³Á¤µÈ Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¾ò±â
public:
	virtual void Enable(bool b) = 0;                                                               // ±¤°¢ Ã³¸® ¿©ºÎ. false·Î ¼³Á¤ÇÏ¸é ¾î¾È ¿µ»óÀÌ ±×´ë·Î Ãâ·ÂµÊ.

	virtual void Init(HWND hWnd = NULL) = 0;                                                       // ÃÊ±âÈ­

	virtual void SetFishCenter(int iCenterX, int iCenterY) = 0;                                    // ¾î¾È ¿µ»óÀÇ Áß½É ¼³Á¤
	virtual void GetFishCenter(int& iCenterX, int& iCenterY) = 0;                                  // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ Áß½É ¾ò±â

	virtual void SetFishDimension(DWORD dwFishWidth, DWORD dwFishHeight) = 0;                      // ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¼³Á¤
	virtual void GetFishDimension(DWORD& dwFishWidth, DWORD& dwFishHeight) = 0;                    // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¾ò±â

	virtual void SetFOVDeg(double d) = 0;                                                          // ¾î¾È ¿µ»óÀÇ È­°¢ ¼³Á¤

	virtual void SetLenzMaxRPixel(int i) = 0;                                                      // ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¼³Á¤
	virtual void GetLenzMaxRPixel(int& i) = 0;                                                     // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¾ò±â

	virtual void SetLenzPixelSize(double d) = 0;                                                   // CCD³ª CMOSÀÇ ÇÈ¼¿ Å©±â ¼³Á¤
	virtual void SetSphereR(double d) = 0;                                                         // °¡»óÀÇ °ø°£»óÀÇ ±¸¸é ¹ÝÁö¸§.
	virtual void MakeMap() = 0;                                                                    // 2D -> 3D º¯È¯ ÁÂÇ¥µé °è»ê
	virtual void SetPanTiltAngle(int iSubChannel, int iPan, int iTilt) = 0;                        // ¹Ù¶óº¸´Â Pan/Tilt °¢µµ ¼³Á¤. ³»ºÎÀûÀ¸·Î 4°³ÀÇ ¼­ºê Ã¤³ÎÁß¿¡¼­ ¼±ÅÃµÈ °ÍÀ» Á¦¾îÇÑ´Ù.
	virtual void GetPanTiltAngle(int iSubChannel, int& iPan, int& iTilt) = 0;                      // ÇöÀç ¼³Á¤µÈ Pan/Tilt °¢µµ ÀÐ±â. ³»ºÎÀûÀ¸·Î 4°³ÀÇ ¼­ºê Ã¤³ÎÁß¿¡¼­ ¼±ÅÃµÈ °ÍÀ» Á¦¾îÇÑ´Ù.
	virtual void SetOutSize(int iW, int iH) = 0;                                                   // Ãâ·Â ¿µ»óÀÇ Å©±â ¼³Á¤
	virtual void GetOutSize(int& iW, int& iH) = 0;                                                 // ¼³Á¤µÈ Ãâ·Â ¿µ»óÀÇ Å©±â ¾ò±â
	virtual void SavePanoImg(int iSubChannel, TCHAR (&strFilePath)[MAX_PATH]) = 0;                 // Ãâ·Â ¿µ»óÀÇ ÀúÀå. ³»ºÎÀû Ã¤³Î Áß¿¡¼­ ¼±ÅÃÇÔ.
	virtual void SetDetailLevel(double dStep = 0.05) = 0;                                          // ±¤°¢ Ã³¸® Ç°Áú ¼³Á¤
	virtual void SetOSDText(int nSCh, BYTE* pStr, int nSize) = 0;

	virtual void SetDiagonalTheta(double d) = 0;                                                   // »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¼³Á¤
	virtual double GetDiagonalTheta() = 0;                                                         // ¼³Á¤µÈ »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¾ò±â

public:
	virtual void SetCustomContextID(DWORD dw) = 0;                                                 // ÀÓÀÇ·Î ¼³Á¤µÇ´Â ContextID

public:
	virtual void SetPoolOut(IBufferPool* pI) = 0;

public:
	virtual void ZoomIn(float fStep = 0.1) = 0;                                                       // È­¸é È®´ë
	virtual void ZoomOut(float fStep = 0.1) = 0;                                                      // È­¸é Ãà¼Ò

public:
	virtual void SetResolution(_eResolution eResol) = 0;                                           // ¾î¾È ¿µ»ó ÇØ»óµµ

public:
	virtual void ScreenShot() = 0;
	virtual void ExportRGB(bool b) = 0;

public:
	virtual void SwapUV(bool b) = 0;

public:
	virtual void PrintString(POINT ptPos, TCHAR (&str)[MAX_PATH]) = 0;

public:
	virtual void OnSize() = 0;
};


class ITextAlignType
{
public:
	enum _eTextAlignType
	{
		TopLeft,
		TopCenter,
		TopRight,
		MiddleLeft,
		MiddleCenter,
		MiddleRight,
		BottomLeft,
		BottomCenter,
		BottomRight
	};
};

typedef void (*SnapShot)(BYTE*, long, long, long);

class IWideAngle360_V9 : public IMedia, public IWorker, public IResolution, public IMountType, public ITextAlignType
{
public:
	virtual void SetMountType(_eMountType eType) = 0;											// Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¼³Á¤
	virtual _eMountType GetMountType() = 0;														// ¼³Á¤µÈ Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¾ò±â

public:
	virtual void Enable(bool bEb) = 0;															// ±¤°¢ Ã³¸® ¿©ºÎ. false·Î ¼³Á¤ÇÏ¸é ¾î¾È ¿µ»óÀÌ ±×´ë·Î Ãâ·ÂµÊ.
	virtual bool IsEnable() = 0;
	virtual void Init() = 0;																	// ÃÊ±âÈ­
	virtual void DeInit() = 0;

	virtual bool SetHWnd(HWND hWnd) = 0;

	virtual void SetFishCenter(int nCenterX, int nCenterY) = 0;									// ¾î¾È ¿µ»óÀÇ Áß½É ¼³Á¤
	virtual void GetFishCenter(int& nCenterX, int& nCenterY) = 0;								// ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ Áß½É ¾ò±â

	virtual void SetFishDimension(DWORD dwFishWidth, DWORD dwFishHeight) = 0;                   // ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¼³Á¤
	virtual void GetFishDimension(DWORD& dwFishWidth, DWORD& dwFishHeight) = 0;                 // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¾ò±â

	virtual void SetFOVDeg(double dFov) = 0;                                                    // ¾î¾È ¿µ»óÀÇ È­°¢ ¼³Á¤

	virtual void SetLenzMaxRPixel(int nR) = 0;													// ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¼³Á¤
	virtual void GetLenzMaxRPixel(int& nR) = 0;													// ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¾ò±â

	virtual void SetLenzPixelSize(double dPS) = 0;												// CCD³ª CMOSÀÇ ÇÈ¼¿ Å©±â ¼³Á¤
	virtual void SetSphereR(double dVR) = 0;													// °¡»óÀÇ °ø°£»óÀÇ ±¸¸é ¹ÝÁö¸§.
	virtual void MakeMap() = 0;                                                                 // 2D -> 3D º¯È¯ ÁÂÇ¥µé °è»ê
	virtual void SetPanTiltAngle(int nSCh, int nPan, int nTilt) = 0;							// ¹Ù¶óº¸´Â Pan/Tilt °¢µµ ¼³Á¤. ³»ºÎÀûÀ¸·Î 4°³ÀÇ ¼­ºê Ã¤³ÎÁß¿¡¼­ ¼±ÅÃµÈ °ÍÀ» Á¦¾îÇÑ´Ù.
	virtual void GetPanTiltAngle(int nSCh, int& nPan, int& nTilt) = 0;							// ÇöÀç ¼³Á¤µÈ Pan/Tilt °¢µµ ÀÐ±â. ³»ºÎÀûÀ¸·Î 4°³ÀÇ ¼­ºê Ã¤³ÎÁß¿¡¼­ ¼±ÅÃµÈ °ÍÀ» Á¦¾îÇÑ´Ù.
	virtual void SetOutSize(int nW, int nH) = 0;                                                // Ãâ·Â ¿µ»óÀÇ Å©±â ¼³Á¤
	virtual void GetOutSize(int& nW, int& nH) = 0;                                              // ¼³Á¤µÈ Ãâ·Â ¿µ»óÀÇ Å©±â ¾ò±â
	virtual void SavePanoImg(int nSCh, TCHAR (&strFilePath)[MAX_PATH]) = 0;						// Ãâ·Â ¿µ»óÀÇ ÀúÀå. ³»ºÎÀû Ã¤³Î Áß¿¡¼­ ¼±ÅÃÇÔ.
	virtual void SetDetailLevel(double dStep = 0.05) = 0;										// ±¤°¢ Ã³¸® Ç°Áú ¼³Á¤

	virtual void SetDiagonalTheta(double dDT) = 0;                                              // »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¼³Á¤
	virtual double GetDiagonalTheta() = 0;                                                      // ¼³Á¤µÈ »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¾ò±â

public:
	virtual void SetCustomContextID(DWORD dwID) = 0;

public:
	virtual void SetPoolOut(IBufferPool* pI) = 0;

public:
	virtual void SetZoomLimit(float fZoomMin, float fZoomMax) = 0;
	virtual void ZoomIn(int nSCh, float fStep = 0.1) = 0;                                       // È­¸é È®´ë
	virtual void ZoomOut(int nSCh, float fStep = 0.1) = 0;                                      // È­¸é Ãà¼Ò

public:
	virtual void SetResolution(_eResolution eResol) = 0;                                        // ¾î¾È ¿µ»ó ÇØ»óµµ

public:
	virtual void ScreenShot(int iChannel = -1) = 0;                                             // ÀÌ¹ÌÁö ÇÑ ÀåÀ» IMedia::NewVideoRGB()·Î Ãâ·Â
	virtual void ExportRGB(bool b) = 0;                                                         // ÆÄ³ë¶ó¸¶ Ãâ·Â °á°ú¸¦ ¿¬¼ÓÀûÀ¸·Î IMedia::NewVideoRGB()·Î Ãâ·Â

public:
	virtual void SwapUV(bool bSwap) = 0;

public:
	virtual void OnSize() = 0;

public:
	virtual void SetOSDFont(TCHAR* pFontFilePath) = 0;
	virtual void SetOSDText(int nID, int nSCh, int nRed, int nGreen, int nBlue, _eTextAlignType ePosType, TCHAR* pMsg, int nFontSize) = 0;
	virtual void KillOSDText(int nID) = 0;

public:
	virtual void SetPrivateZone(int nID, int nSCh, int nRed, int nGreen, int nBlue, int nAlpha, RECT& rtPos, bool bFill) = 0;

public:
	virtual void DrawRect(int nRed, int nGreen, int nBlue, int nLineWidth, RECT& rtPos) = 0;
	virtual void DrawRectCancel() = 0;

public:
	virtual void SetBitmap(int nID, TCHAR* pFilePath) = 0;
	virtual void DrawBitmap(int nID) = 0;
	virtual void EnableBitmap(bool bDraw) = 0;

public:
	virtual void GetSnapShot(SnapShot func) = 0;
	virtual IBuffer* GetIBuffRGB() = 0;

public:
	virtual bool GetPanoResultRGB(int nCh, int nSrcFormat, BYTE* pSrcY, BYTE* pSrcU, BYTE* pSrcV, int nSrcPitchY, int nSrcPitchUV, long lFishW, long lFishH, int& nWidth, int& nHeight, int& iOutBits, BYTE* pRGB) = 0;
};

// V9¿¡¼­ BMP È­¸é Ç¥½Ã ºÎºÐÀ» ´Ù½Ã ÀÛ¼ºÇÑ °Í.
class IEvtWideAngle360_V10;
class IWideAngle360_V10 : public IMedia, public IWorker, public IResolution, public IMountType, public ITextAlignType
{
public:
	enum _e4What
	{
		e4Normal,
		e4Pano,
		e4PicAndVideo,
		e4Face,
	};
public:
	virtual void Set4Normal() = 0;
	virtual void Set4Pano() = 0;
	virtual void Set4PicAndVideo() = 0;
	virtual void Set4Face() = 0;

public:
	enum _eDirPanTilt
	{
		eDirNone,
		eDirPan,
		eDirTilt,
	};
public:
	virtual void SetMountType(_eMountType eType) = 0;											// Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¼³Á¤
	virtual _eMountType GetMountType() = 0;														// ¼³Á¤µÈ Ä«¸Þ¶ó ÀåÂø À§Ä¡ ¾ò±â

public:
	virtual void Enable(bool bEb) = 0;															// ±¤°¢ Ã³¸® ¿©ºÎ. false·Î ¼³Á¤ÇÏ¸é ¾î¾È ¿µ»óÀÌ ±×´ë·Î Ãâ·ÂµÊ.
	virtual bool IsEnable() = 0;
	virtual void EnablePano(bool bEb) = 0;															// ±¤°¢ Ã³¸® ¿©ºÎ. false·Î ¼³Á¤ÇÏ¸é ¾î¾È ¿µ»óÀÌ ±×´ë·Î Ãâ·ÂµÊ.
	virtual bool IsEnablePano() = 0;

public:
	virtual void Init() = 0;																	// ÃÊ±âÈ­
	virtual void DeInit() = 0;

	virtual bool SetHWnd(HWND hWnd) = 0;

	virtual void SetFishCenter(int nCenterX, int nCenterY) = 0;									// ¾î¾È ¿µ»óÀÇ Áß½É ¼³Á¤
	virtual void GetFishCenter(int& nCenterX, int& nCenterY) = 0;								// ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ Áß½É ¾ò±â

	virtual void SetFishDimension(DWORD dwFishWidth, DWORD dwFishHeight) = 0;                   // ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¼³Á¤
	virtual void GetFishDimension(DWORD& dwFishWidth, DWORD& dwFishHeight) = 0;                 // ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ÇØ»óµµ ¾ò±â

	virtual double GetFOVDeg() = 0;
	virtual void SetFOVDeg(double dFov) = 0;                                                    // ¾î¾È ¿µ»óÀÇ È­°¢ ¼³Á¤

	virtual void SetLenzMaxRPixel(int nR) = 0;													// ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¼³Á¤
	virtual void GetLenzMaxRPixel(int& nR) = 0;													// ¼³Á¤µÈ ¾î¾È ¿µ»óÀÇ ¹ÝÁö¸§ ¾ò±â

	virtual void SetLenzPixelSize(double dPS) = 0;												// CCD³ª CMOSÀÇ ÇÈ¼¿ Å©±â ¼³Á¤
	virtual void SetSphereR(double dVR) = 0;													// °¡»óÀÇ °ø°£»óÀÇ ±¸¸é ¹ÝÁö¸§.
	virtual void MakeMap(_eColorFormat eFormat = eColorYUV) = 0;                                                                 // 2D -> 3D º¯È¯ ÁÂÇ¥µé °è»ê
	virtual void SetPanTiltAngle(int nSCh, int nPan, int nTilt) = 0;							// ¹Ù¶óº¸´Â Pan/Tilt °¢µµ ¼³Á¤. ³»ºÎÀûÀ¸·Î 4°³ÀÇ ¼­ºê Ã¤³ÎÁß¿¡¼­ ¼±ÅÃµÈ °ÍÀ» Á¦¾îÇÑ´Ù.	
	virtual void GetPanTiltAngle(int nSCh, int& nPan, int& nTilt) = 0;							// ÇöÀç ¼³Á¤µÈ Pan/Tilt °¢µµ ÀÐ±â. ³»ºÎÀûÀ¸·Î 4°³ÀÇ ¼­ºê Ã¤³ÎÁß¿¡¼­ ¼±ÅÃµÈ °ÍÀ» Á¦¾îÇÑ´Ù.
	virtual void SetOutSize(int nW, int nH) = 0;                                                // Ãâ·Â ¿µ»óÀÇ Å©±â ¼³Á¤
	virtual void GetOutSize(int& nW, int& nH) = 0;                                              // ¼³Á¤µÈ Ãâ·Â ¿µ»óÀÇ Å©±â ¾ò±â
	virtual void SavePanoImg(int nSCh, TCHAR(&strFilePath)[MAX_PATH]) = 0;						// Ãâ·Â ¿µ»óÀÇ ÀúÀå. ³»ºÎÀû Ã¤³Î Áß¿¡¼­ ¼±ÅÃÇÔ.
	virtual void SetDetailLevel(double dStep = 0.05) = 0;										// ±¤°¢ Ã³¸® Ç°Áú ¼³Á¤

	virtual void SetDiagonalTheta(double dDT) = 0;                                              // »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¼³Á¤
	virtual double GetDiagonalTheta() = 0;                                                      // ¼³Á¤µÈ »ç¼± Ã³¸®½Ã ³»·Á´Ù º¸´Â °¢µµ ¾ò±â

public:
	virtual void OnLButtonDown(UINT nFlags, POINT point) = 0;
	virtual void OnLButtonUp(UINT nFlags, POINT point) = 0;
	virtual void OnMouseMove(UINT nFlags, POINT point) = 0;

public:
	virtual bool CalcPanTiltCeiling(POINT ptCenter, POINT ptNewPos, double& dPan, double& dTilt) = 0;
	virtual bool CalcPanTiltWall(POINT ptCenter, POINT ptNewPos, double& dPan, double& dTilt) = 0;

public:
	virtual void SetCustomContextID(DWORD dwID) = 0;

public:
	virtual void SetPoolOut(IBufferPool* pI) = 0;

public:
	virtual void SetZoomLimit(float fZoomMin, float fZoomMax) = 0;
	virtual void ZoomIn(int nSCh, float fStep = 0.1) = 0;                                       // È­¸é È®´ë
	virtual void ZoomOut(int nSCh, float fStep = 0.1) = 0;                                      // È­¸é Ãà¼Ò

public:
	virtual void SetResolution(_eResolution eResol) = 0;                                        // ¾î¾È ¿µ»ó ÇØ»óµµ

public:
	virtual void ScreenShot(int iChannel = -1) = 0;                                             // ÀÌ¹ÌÁö ÇÑ ÀåÀ» IMedia::NewVideoRGB()·Î Ãâ·Â
	virtual void ExportRGB(bool b) = 0;                                                         // ÆÄ³ë¶ó¸¶ Ãâ·Â °á°ú¸¦ ¿¬¼ÓÀûÀ¸·Î IMedia::NewVideoRGB()·Î Ãâ·Â
	virtual void ExportRGBSub(int iSubChannel, bool b) = 0;

public:
	virtual void SwapUV(bool bSwap) = 0;

public:
	virtual void OnSize() = 0;

public:
	virtual void SetOSDFont(TCHAR* pFontFilePath) = 0;
	virtual void SetOSDText(int nID, int nSCh, int nRed, int nGreen, int nBlue, _eTextAlignType ePosType, TCHAR* pMsg, int nFontSize) = 0;
	virtual void KillOSDText(int nID) = 0;
	virtual void SetOSDText2(int nID, int nSCh, int nRed, int nGreen, int nBlue, POINT ptPos, TCHAR* pMsg, int nFontSize) = 0;
	virtual void KillOSDText2(int nID) = 0;

public:
	virtual void SetPrivateZone(int nID, int nSCh, int nRed, int nGreen, int nBlue, int nAlpha, RECT& rtPos, bool bFill) = 0;

public:
	virtual void DrawRect(int iSub, int nRed, int nGreen, int nBlue, int nLineWidth, RECT& rtPos) = 0;		// rtPos는 최대치가 1000.
	virtual void DrawRectReset() = 0;

public:
	virtual void DrawFace(int iSubChannel, IString* pIStrName, int nGreen, int nBlue, int nLineWidth, RECT& rtPos) = 0;
	virtual void DrawFaceReset() = 0;

public:
	virtual void DrawCircle(int nRed, int nGreen, int nBlue, int nLineWidth, POINT ptCenter, USHORT usRadius) = 0;		// ptCenter와 usRadius는 카메라 해상도에서.
	virtual void DrawCircleReset() = 0;

public:
	virtual void DrawLine(int nRed, int nGreen, int nBlue, int nLineWidth, POINT ptStart, POINT ptEnd) = 0;
	virtual void DrawLineReset() = 0;

public:
	virtual void DrawBitmap(TCHAR* pFilePath) = 0;

public:
	virtual void GetSnapShot(SnapShot func) = 0;
	virtual IBuffer* GetIBuffRGB(int iSub) = 0;

public:
	virtual bool GetPanoResultRGB(int nCh, int nSrcFormat, BYTE* pSrcY, BYTE* pSrcU, BYTE* pSrcV, int nSrcPitchY, int nSrcPitchUV, long lFishW, long lFishH, int& nWidth, int& nHeight, int& iOutBits, BYTE* pRGB) = 0;

public:
	virtual void MotionTracking(bool bEnable) = 0;
	//virtual void FaceIdentification(bool bEnable) = 0;

public:
	virtual void IEvtAdd(IEvtWideAngle360_V10* pI) = 0;
	virtual void IEvtRemove(IEvtWideAngle360_V10* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual void SetFaceDetectionRunning(int iChannel, bool bFound) = 0;
};

class IEvtWideAngle360_V10
{
public:
	virtual void IEvtWideAngleAddRef() = 0;
	virtual void IEvtWideAngleRelease() = 0;
	virtual long IEvtWideAngleGetRefCnt() = 0;

public:
	virtual void IEvtMotionPanTilt(int iSch, int iPan, int iTilt) {}
	virtual void IEvtMotionImage(IBuffer* pIRGB, size_t w, size_t h, size_t d) {}
	virtual void IEvtMotionImage(IBuffer* pIY, IBuffer* pIU, IBuffer* pIV, size_t w, size_t h, size_t d) {}
	virtual void IEvtImage4Face(int iSch, IBuffer* pIRGB, size_t w, size_t h, size_t d) {}
};


/*
IWideAngle360_V10의 내용을 IWideAngle360_V6의 인터페이스를 이용하여 sub channel 1개 출력을 하게 함
*/
class IWideAngle360_V11 : public IMedia, public IWorker, public IResolution, public IMountType
{
public:
	virtual void SetMountType(_eMountType eType) = 0;                                              // 천정형, 탁상형, 사선형 설정
	virtual _eMountType GetMountType() = 0;                                                        // 현재 설정된 MountType 반환
public:
	virtual void Enable(bool b) = 0;                                                               // 파노라마 처리 여부. false이면 입력된 어안 영상을 그대로 출력

	virtual void Init() = 0;                                                                       // 초기화
	virtual bool SetHWnd(HWND hWnd) = 0;                                                           // 파노라마 영상이 출력될 윈도우 핸들 설정

	virtual void SetFishCenter(int iCenterX, int iCenterY) = 0;                                    // 어안 영상의 중심설정
	virtual void GetFishCenter(int& iCenterX, int& iCenterY) = 0;                                  // 설정된 어안 영상의 중심 반환

	virtual void SetFishDimension(DWORD dwFishWidth, DWORD dwFishHeight) = 0;                      // 어안 영상의 크기 설정
	virtual void GetFishDimension(DWORD& dwFishWidth, DWORD& dwFishHeight) = 0;                    // 설정된 어안 영상의 크기 반환

	virtual void SetFOVDeg(double d) = 0;                                                          // 어안 렌즈의 천정각 설정

	virtual void SetLenzMaxRPixel(int i) = 0;                                                      // 어안 영상의 반지름을 픽셀 단위로 설정
	virtual void GetLenzMaxRPixel(int& i) = 0;                                                     // 설정된 어안 영상의 픽셀 단위 반지름 반환

	virtual void SetLenzPixelSize(double d) = 0;                                                   // 이미지 센서의 크기 설정
	virtual void SetSphereR(double d) = 0;                                                         // 가상으로 만들 공간의 반지름 설정
	virtual void MakeMap() = 0;                                                                    // 2D -> 3D 변환
	virtual void SetPanTiltAngle(int iPan, int iTilt) = 0;                                         // 현재 바라보는 지점의 Pan/Tilt 각도 설정. 카메라가 회전되는 효과 연출
	virtual void GetPanTiltAngle(int& iPan, int& iTilt) = 0;                                       // 현재 설정된 Pan/Tilt 각도 가져오기
	virtual void SetOutSize(int iW, int iH) = 0;                                                   // 만들어낼 파노라마 이미지의 크기 설정
	virtual void GetOutSize(int& iW, int& iH) = 0;                                                 // 설정된 파노라마 이미지의 크기 반환
	//virtual void SavePanoImg(TCHAR* pFilePath) = 0;                                                // 파노라마 이미지를 이미지 파일로 저장
	virtual void SetDetailLevel(double dStep = 0.05) = 0;                                          // 파노라마 출력 질(Quality) 설정

	virtual void SetDiagonalTheta(double d) = 0;                                                   // 사선형일 경우 내려다 보는 각도 설정
	virtual double GetDiagonalTheta() = 0;                                                         // 설정된 사선형의 각도 반환

public:
	virtual void SetCustomContextID(DWORD dw) = 0;                                                 // Context 번호(ex 카메라 별 번호)

public:
	virtual void SetPoolOut(IBufferPool* pI) = 0;                                                  // 사용될 버퍼의 설정

public:
	virtual void SwapUV(bool bSwap) = 0;                                                           // YUV 입력 영상에서 U와 V의 순서 설정
	virtual void OnSize() = 0;                                                                     // 윈도우 크기가 바뀌었을 경우 호출

public:
	virtual bool GetPanoResultRGB(int nCh, int nSrcFormat, BYTE* pSrcY, BYTE* pSrcU, BYTE* pSrcV, int nSrcPitchY, int nSrcPitchUV, long lFishW, long lFishH, int& nWidth, int& nHeight, int& iOutBits, IBuffer* pIResult) = 0; // 파노라마 결과를 이미지 버퍼에 담고 싶을 경우

public:
	virtual void DrawCircle(int nRed, int nGreen, int nBlue, int nLineWidth, POINT ptCenter, USHORT usRadius) = 0; // 원 그리기
	virtual void DrawCircleReset() = 0;                                                                            // 그린 원들의 초기화

public:
	virtual void SetResolution(_eResolution eResol) = 0;                                           // ¾î¾È ¿µ»ó ÇØ»óµµ

public:
	virtual void ScreenShot(int iChannel = -1) = 0;                                             // ÀÌ¹ÌÁö ÇÑ ÀåÀ» IMedia::NewVideoRGB()·Î Ãâ·Â
	virtual void ExportRGB(bool b) = 0;                                                         // ÆÄ³ë¶ó¸¶ Ãâ·Â °á°ú¸¦ ¿¬¼ÓÀûÀ¸·Î IMedia::NewVideoRGB()·Î Ãâ·Â
	virtual void ExportRGBSub(int iSubChannel, bool b) = 0;
};


// Single 출력인 IWideAngle360_V7에 기반하여 시점이 움직이도록 함.
class IWideAngle360_V12 : public IWideAngle360_V7
{
public:
	virtual void MoveTo(double dX, double dY, double dZ) = 0;
};
