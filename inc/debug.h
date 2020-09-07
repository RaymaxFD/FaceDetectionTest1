#ifndef __DEBUG_H__
#define __DEBUG_H__

#include <crtdbg.h>

#ifdef _DEBUG
#ifndef ASSERT
#define ASSERT(x)       _ASSERT(x)
#endif
#ifndef VERIFY
#define VERIFY(x)       ASSERT(x)
#endif
#else
#ifndef ASSERT
#define ASSERT(x)
#endif
#ifndef VERIFY
#define VERIFY(x)       x
#endif
#endif

#endif