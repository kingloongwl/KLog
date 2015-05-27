
#include "KLog.h"


int main()
{
	KLog::getInstance()->writeLog( "第一条信息" );
	KLog::getInstance()->writeLog( "第一条警告", KLog::WARNING );
	KLog::getInstance()->writeLog( "第一条错误", KLog::ERROR );

	KLog::release();
	return 0;
}

