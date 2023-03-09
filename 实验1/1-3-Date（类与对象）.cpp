#include <iostream>
#include <iomanip>
using namespace std;

bool isRun(int year) // 是否闰年
{
	if(year % 400 == 0) return 1;
	else if(year % 4 == 0 && year % 100 != 0) return 1;
	else return 0;
}

class Date
{
private:
	int year, month, day;
public:
	Date();
	Date(int y, int m, int d);
	int getYear();
	int getMonth();
	int getDay();
	void setDate(int y, int m, int d);
	void print();
	void addOneDay();
};

Date::Date():year(1900),month(1), day(1){}
Date::Date(int y, int m, int d):year(y), month(m), day(d){}
int Date::getYear(){ return year; }
int Date::getMonth(){ return month; }
int Date::getDay(){ return day; }
void Date::setDate(int y, int m, int d){ year=y; month=m; day=d; }
void Date::print()
{
	cout << year << '/';
	cout << setfill('0') << setw(2) << month << '/';
	cout << setfill('0') << setw(2) << day << endl;
}
void Date::addOneDay()
{
	int dayInEachMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(isRun(year)) dayInEachMonth[2]++; // 闰年
	// +1
	if(++day>dayInEachMonth[month])
	{
		day = 1;
		if(++month>12)
		{
			month = 1;
			++year;
		}
	}
}

int main()
{
	int t;
	cin >> t;
	int year, month, day;
	for(int i=0; i<t; i++)
	{
		cin >> year >> month >> day;
		// 构造函数
		if(i%2)
		{
			Date d(year, month, day);
			cout << "Today is ";
			d.print();
			d.addOneDay();
			cout << "Tomorrow is ";
			d.print();
		}
		else  // setDate
		{
			Date d;
			d.setDate(year, month, day);
			cout << "Today is ";
			d.print();
			d.addOneDay();
			cout << "Tomorrow is ";
			d.print();
		}
	}
	
	return 0;
}
