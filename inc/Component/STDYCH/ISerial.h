
#pragma once

#include <IWorker.h>
#include <assert.h>

//////////////////////////////////////////////////////////////////////
// The SERIAL_DEFAULT_OVERLAPPED defines if the default open mode uses
// overlapped I/O. When overlapped I/O is available (normal Win32
// platforms) it uses overlapped I/O. Windows CE doesn't allow the use
// of overlapped I/O, so it is disabled there by default.

#ifndef SERIAL_DEFAULT_OVERLAPPED
#ifndef SERIAL_NO_OVERLAPPED
#define SERIAL_DEFAULT_OVERLAPPED	true
#else
#define SERIAL_DEFAULT_OVERLAPPED	false
#endif
#endif

class IBufferPool;
class IBuffer;
class ISerialEvt;

class ISerial : public IWorker
{
public:
	// Communication event
	typedef enum
	{
		EEventUnknown  	   = -1,			// Unknown event
		EEventNone  	   = 0,				// Event trigged without cause
		EEventBreak 	   = EV_BREAK,		// A break was detected on input
		EEventCTS   	   = EV_CTS,		// The CTS signal changed state
		EEventDSR   	   = EV_DSR,		// The DSR signal changed state
		EEventError 	   = EV_ERR,		// A line-status error occurred
		EEventRing  	   = EV_RING,		// A ring indicator was detected
		EEventRLSD  	   = EV_RLSD,		// The RLSD signal changed state
		EEventRecv  	   = EV_RXCHAR,		// Data is received on input
		EEventRcvEv 	   = EV_RXFLAG,		// Event character was received on input
		EEventSend		   = EV_TXEMPTY,	// Last character on output was sent
		EEventPrinterError = EV_PERR,		// Printer error occured
		EEventRx80Full	   = EV_RX80FULL,	// Receive buffer is 80 percent full
		EEventProviderEvt1 = EV_EVENT1,		// Provider specific event 1
		EEventProviderEvt2 = EV_EVENT2,		// Provider specific event 2
	} 
	EEvent;

	// Baudrate
	typedef enum
	{
		EBaudUnknown = -1,			// Unknown
		EBaud110     = CBR_110,		// 110 bits/sec
		EBaud300     = CBR_300,		// 300 bits/sec
		EBaud600     = CBR_600,		// 600 bits/sec
		EBaud1200    = CBR_1200,	// 1200 bits/sec
		EBaud2400    = CBR_2400,	// 2400 bits/sec
		EBaud4800    = CBR_4800,	// 4800 bits/sec
		EBaud9600    = CBR_9600,	// 9600 bits/sec
		EBaud14400   = CBR_14400,	// 14400 bits/sec
		EBaud19200   = CBR_19200,	// 19200 bits/sec (default)
		EBaud38400   = CBR_38400,	// 38400 bits/sec
		EBaud56000   = CBR_56000,	// 56000 bits/sec
		EBaud57600   = CBR_57600,	// 57600 bits/sec
		EBaud115200  = CBR_115200,	// 115200 bits/sec
		EBaud128000  = CBR_128000,	// 128000 bits/sec
		EBaud256000  = CBR_256000,	// 256000 bits/sec
	}
	EBaudrate;

	// Data bits (5-8)
	typedef enum
	{
		EDataUnknown = -1,			// Unknown
		EData5       =  5,			// 5 bits per byte
		EData6       =  6,			// 6 bits per byte
		EData7       =  7,			// 7 bits per byte
		EData8       =  8			// 8 bits per byte (default)
	}
	EDataBits;

	// Parity scheme
	typedef enum
	{
		EParUnknown = -1,			// Unknown
		EParNone    = NOPARITY,		// No parity (default)
		EParOdd     = ODDPARITY,	// Odd parity
		EParEven    = EVENPARITY,	// Even parity
		EParMark    = MARKPARITY,	// Mark parity
		EParSpace   = SPACEPARITY	// Space parity
	}
	EParity;

	// Stop bits
	typedef enum
	{
		EStopUnknown = -1,			// Unknown
		EStop1       = ONESTOPBIT,	// 1 stopbit (default)
		EStop1_5     = ONE5STOPBITS,// 1.5 stopbit
		EStop2       = TWOSTOPBITS	// 2 stopbits
	} 
	EStopBits;

	// Handshaking
	typedef enum
	{
		EHandshakeUnknown		= -1,	// Unknown
		EHandshakeOff			=  0,	// No handshaking
		EHandshakeHardware		=  1,	// Hardware handshaking (RTS/CTS)
		EHandshakeSoftware		=  2	// Software handshaking (XON/XOFF)
	} 
	EHandshake;

	// Timeout settings
	typedef enum
	{
		EReadTimeoutUnknown		= -1,	// Unknown
		EReadTimeoutNonblocking	=  0,	// Always return immediately
		EReadTimeoutBlocking	=  1	// Block until everything is retrieved
	}
	EReadTimeout;

	// Communication errors
	typedef enum
	{
		EErrorUnknown = 0,			// Unknown
		EErrorBreak   = CE_BREAK,	// Break condition detected
		EErrorFrame   = CE_FRAME,	// Framing error
		EErrorIOE     = CE_IOE,		// I/O device error
		EErrorMode    = CE_MODE,	// Unsupported mode
		EErrorOverrun = CE_OVERRUN,	// Character buffer overrun, next byte is lost
		EErrorRxOver  = CE_RXOVER,	// Input buffer overflow, byte lost
		EErrorParity  = CE_RXPARITY,// Input parity error
		EErrorTxFull  = CE_TXFULL	// Output buffer full
	}
	EError;

	// Port availability
	typedef enum
	{
		EPortUnknownError = -1,		// Unknown error occurred
		EPortAvailable    =  0,		// Port is available
		EPortNotAvailable =  1,		// Port is not present
		EPortInUse        =  2		// Port is in use

	} 
	EPort;



public:
	virtual void SetIBufPool4Recv(IBufferPool* pI) = 0;
	virtual bool CheckPort(int iPort) = 0;
	virtual bool Open(int iPort, int iID = 0, bool bAsync = false, DWORD dwInQueue = 0, DWORD dwOutQueue = 0, bool fOverlapped = SERIAL_DEFAULT_OVERLAPPED) = 0;
	virtual LONG Close (void) = 0;

public:
	virtual LONG Setup (EBaudrate eBaudrate = EBaud9600,
						EDataBits eDataBits = EData8,
						EParity   eParity   = EParNone,
						EStopBits eStopBits = EStop1) = 0;
	virtual LONG SetEventChar (BYTE bEventChar, bool fAdjustMask = true) = 0;
	virtual LONG SetMask (DWORD dwMask = EEventBreak|EEventError|EEventRecv) = 0;
	virtual LONG WaitEvent (LPOVERLAPPED lpOverlapped = 0, DWORD dwTimeout = INFINITE) = 0;
	virtual LONG SetupHandshaking (EHandshake eHandshake) = 0;
	virtual LONG SetupReadTimeouts (EReadTimeout eReadTimeout) = 0;

public:
	virtual EBaudrate  GetBaudrate    (void) = 0;
	virtual EDataBits  GetDataBits    (void) = 0;
	virtual EParity    GetParity      (void) = 0;
	virtual EStopBits  GetStopBits    (void) = 0;
	virtual EHandshake GetHandshaking (void) = 0;
	virtual DWORD      GetEventMask   (void) = 0;
	virtual BYTE       GetEventChar   (void) = 0;

public:
	virtual bool Write (const void* pData, size_t iLen, DWORD* pdwWritten = 0, LPOVERLAPPED lpOverlapped = 0, DWORD dwTimeout = INFINITE) = 0;
	virtual bool Write (LPCSTR pString, DWORD* pdwWritten = 0, LPOVERLAPPED lpOverlapped = 0, DWORD dwTimeout = INFINITE) = 0;

public:
	virtual LONG Read (void* pData, size_t iLen, DWORD* pdwRead = 0, LPOVERLAPPED lpOverlapped = 0, DWORD dwTimeout = INFINITE) = 0;

public:
	virtual LONG Break (void) = 0;
	virtual EEvent GetEventType (void) = 0;
	virtual EError GetError (void) = 0;
	virtual HANDLE GetCommHandle (void) = 0;
	virtual bool IsOpen (void) = 0;
	virtual LONG GetLastError (void) = 0;

public:
	virtual bool GetCTS (void) = 0;
	virtual bool GetDSR (void) = 0;
	virtual bool GetRing (void) = 0;
	virtual bool GetRLSD (void) = 0;

public:
	virtual LONG Purge (void) = 0;

public:
	virtual bool AddIEvent(ISerialEvt* pI) = 0;	// event는 한 객체에서만 받는다. 2개 이상 등록시 실패함.
	virtual void ResetIEvent() = 0;
};

class ISerialEvt
{
public:
	virtual void OnSerialEvtConnection(int iID, LONG lRst){}
	virtual DWORD OnSerialEvtReadData(int iID, BYTE* pData, DWORD dwRead)	{		assert(0);return dwRead;	}
	virtual DWORD OnSerialEvtReadData(int iID, IBuffer* pI) { assert(0); return 0; } // 처리가 된 byte 수 리턴할 것.
};


class IEvtSerial2;

class ISerial2 : public IWorker
{
public:
	virtual void IEvtAdd(IEvtSerial2* pI) = 0;
	virtual void IEvtRemove(IEvtSerial2* pI) = 0;
	virtual void IEvtReset() = 0;

public:
	virtual bool Open(int iID, int nPort, int nBaud = 9600) = 0;
	virtual bool Close(void) = 0;

	//virtual int ReadData(void *, int) = 0;
	virtual int SendData(const char *, int) = 0;
	virtual int ReadDataWaiting(void) = 0;
	virtual bool CheckPort(int iPort) = 0;

	virtual bool IsOpened(void) = 0;

	virtual void SetIBufferPool(IBufferPool* pI) = 0;
};

class IEvtSerial2
{
public:
	virtual void IEvtSerial2Read(int iID, IBuffer* pI) {}
};