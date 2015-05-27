
#include "KLog.h"
#include "KTime.h"

KLog* KLog::_sInstance = NULL;

KLog::KLog()
{
	std::string dateStr = KTime::getInstance()->getDate();
	std::string filename = "Log/" + dateStr + ".log";

	_fstream.open( filename.c_str(), std::ios_base::out | std::ios_base::app );
}

KLog::~KLog()
{
	if ( _fstream.is_open() )
	{
		_fstream.close();
	}

}

KLog* KLog::getInstance()
{
	if ( KLog::_sInstance == NULL )
	{
		KLog::_sInstance = new KLog();
	}
	
	return KLog::_sInstance;
}

void KLog::release()
{
	if ( KLog::_sInstance != NULL )
	{
		delete KLog::_sInstance;
		
		KLog::_sInstance = NULL;
	}

	KTime::release();
}

void KLog::writeLog( const std::string &logStr, LogLevel logLevel )
{
	if ( !_fstream.is_open() )
	{
		return;
	}

	std::string flagStr = "信息";
	switch ( logLevel )
	{
	case INFO:
		flagStr = "信息";
		break;
	case WARNING:
		flagStr = "警告";
		break;
	case ERROR:
		flagStr = "错误";
		break;
	default: 
		break;
	}
	
	std::string newLogStr = flagStr + ":" + logStr + "\n";
	_fstream<<newLogStr;
}
