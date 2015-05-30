
#include "KTime.h"

#include <time.h>
#include <strstream>
#include <iomanip>
#include <stdio.h>

KTime* KTime::_sInstance = NULL;

KTime::KTime()
: _year( 1900 )
, _month( 1 )
, _day( 1 )
, _hour( 0 )
, _minute( 0 )
, _second( 0 )
{
	updateTime();
}

KTime::~KTime()
{

}

KTime* KTime::getInstance()
{
	if ( KTime::_sInstance == NULL )
	{
		KTime::_sInstance = new KTime;
	}
	else
	{
		KTime::_sInstance->updateTime();
	}
	
	return KTime::_sInstance;
}

void KTime::release()
{
	if ( KTime::_sInstance != NULL )
	{
		delete KTime::_sInstance;
		KTime::_sInstance = NULL;
	}
}

void KTime::updateTime()
{
	time_t currentTime = time( NULL );

//	struct tm* timeLocal = new tm;
//	localtime_t( timeLocal, &currentTime );	//windows
// 	localtime_r(&currentTime, timeLocal);	//linux

	struct tm* timeLocal = localtime( &currentTime );	//windows & linux
	
	_year = timeLocal->tm_year + 1900;
	_month = timeLocal->tm_mon + 1;
	_day = timeLocal->tm_mday;
	
	_hour = timeLocal->tm_hour;
	_minute = timeLocal->tm_min;
	_second = timeLocal->tm_sec;
	
	_wday = timeLocal->tm_wday;
	
	
// 	delete timeLocal;
}

std::string KTime::getDate( const std::string &sep )
{
	std::strstream ss;
	ss<<_year<<sep
	<<std::setw(2)<<std::setfill('0')<<_month<<sep
	<<_day<<'\0';
	
	return ss.str();
}

std::string KTime::getTime( const std::string &sep )
{
	std::strstream ss;
	ss<<std::setw(2)<<std::setfill('0')<<_hour<<sep
	<<_minute<<sep
	<<_second<<'\0';
	
	return ss.str();
}

double KTime::operator-( const KTime &time )
{
	struct tm tm1 = { _second, _minute, _hour, _day, _month, _year, _wday };
	struct tm tm2 = { time.getSecond(), time.getMinute(), time.getHour(), time.getDay(), time.getMonth(), time.getYear(), time.getWday() };
	
	time_t time1 = mktime( &tm1 );
	time_t time2 = mktime( &tm2 );
	
	return difftime( time1, time2 );
	
}
