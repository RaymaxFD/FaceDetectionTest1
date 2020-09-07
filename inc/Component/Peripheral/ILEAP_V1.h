
#pragma once

#include <IBase.h>

class IEvtLEAP_V1;
class ILEAP_V1 : public IBase
{
public:
	enum _ePolicy
	{
		/**
		* The default policy.
		* @since 1.0
		*/
		POLICY_DEFAULT = 0,
		/**
		* Receive background frames.
		* @since 1.0
		*/
		POLICY_BACKGROUND_FRAMES = (1 << 0),

		/**
		* Receive images from sensor cameras.
		* @since 2.1.0
		*/
		POLICY_IMAGES = (1 << 1),

		/**
		* Optimize the tracking for head-mounted device.
		* @since 2.1.2
		*/
		POLICY_OPTIMIZE_HMD = (1 << 2),

		/**
		* Allow pausing and unpausing of the Leap Motion service.
		* @since 3.0
		*/
		POLICY_ALLOW_PAUSE_RESUME = (1 << 3),

		/**
		* Receive raw images.
		*/
		POLICY_RAW_IMAGES = (1 << 6),
	};

public:
	virtual void SetPolicy(_ePolicy ePolicy = POLICY_ALLOW_PAUSE_RESUME) = 0;

public:
	virtual void Start() = 0;
	virtual void Stop() = 0;

public:
	virtual void IEvtAdd(IEvtLEAP_V1* pI) = 0;
	virtual void IEvtRemove(IEvtLEAP_V1* pI) = 0;
	virtual void IEvtReset() = 0;
};

class IEvtLEAP_V1
{};