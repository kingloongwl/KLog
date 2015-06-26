
#ifndef KLOG_KLOG_H_
#define KLOG_KLOG_H_

#include "Export.h"

#include <string>
#include <fstream>

class KLOG_EXPORT KLog
{
public:
	enum LogLevel
	{
		INFO,
		WARNING,
		ERROR
	};

	void writeLog( const std::string& logStr, LogLevel logLevel = INFO );

public:
	static KLog* getInstance();
	static void release();

private:
	KLog();
	~KLog();
	
private:
	static KLog* _sInstance;
	
private:
	std::ofstream _fstream;
};

#endif
