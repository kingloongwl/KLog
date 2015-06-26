

#include <string>

class KTime
{
public:
	int getYear() const { return _year; }
	int getMonth() const { return _month; }
	int getDay() const { return _day; }
	
	int getHour() const { return _hour; }
	int getMinute() const { return _minute; }
	int getSecond() const { return _second; }
	
	int getWday() const { return _wday; }

	std::string getDate( const std::string &sep = "" );
	std::string getTime( const std::string &sep = "" );
	
	double operator-( const KTime &time );

public:
	static KTime* getInstance();
	static void release();

	static KTime *_sInstance;
	
	void updateTime();
private:
	KTime();
	~KTime();
	
	
	
private:
	int _year;
	int _month;
	int _day;
	int _hour;
	int _minute;
	int _second;
	int _wday;
	
};
