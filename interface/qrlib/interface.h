#ifndef QRLIB_INTERFACE_1604911737496_H
#define QRLIB_INTERFACE_1604911737496_H
#include "ccglobal/export.h"

#ifdef QRLIB_DLL
	#define QRLIB_API CC_DECLARE_EXPORT
#else
	#define QRLIB_API CC_DECLARE_IMPORT
#endif
#endif // QRLIB_INTERFACE_1604911737496_H