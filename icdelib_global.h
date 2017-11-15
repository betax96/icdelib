#ifndef ICDELIB_GLOBAL_H
#define ICDELIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(ICDELIB_LIBRARY)
#  define ICDELIBSHARED_EXPORT Q_DECL_EXPORT
#else
#  define ICDELIBSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // ICDELIB_GLOBAL_H
