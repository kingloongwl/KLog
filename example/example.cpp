
#include "KLog.h"


int main()
{
	KLog::getInstance()->writeLog( "��һ����Ϣ" );
	KLog::getInstance()->writeLog( "��һ������", KLog::WARNING );
	KLog::getInstance()->writeLog( "��һ������", KLog::ERROR );

	KLog::release();
	return 0;
}

