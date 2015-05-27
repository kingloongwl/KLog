
#ifndef KLOG_EXPORT_H_
#define KLOG_EXPORT_H_

#if defined(_MSC_VER) || defined(__CYGWIN__) || defined(__MINGW32__) || defined( __BCPLUSPLUS__) || defined( __MWERKS__)
    #  if defined( KLOG_LIBRARY )
    #    define KLOG_EXPORT   __declspec(dllexport)
    #  else
    #    define KLOG_EXPORT   __declspec(dllimport)
    #endif
#else
    #define KLOG_EXPORT 
#endif 

#endif
