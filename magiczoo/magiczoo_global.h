#ifndef MAGICZOO_GLOBAL_H
#define MAGICZOO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MAGICZOO_LIBRARY)
#  define MAGICZOOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define MAGICZOOSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // MAGICZOO_GLOBAL_H
