#include<iostream>
#include<String.h>
#include<math.h>
using namespace std;
class  CDate {
	int Year, Month, Day; //分别存放年、月、日
	//static int format;  //用于确定采用哪种格式显示日期
	enum WeekName { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
	enum { January = 1, February, Mars, April, May, June, July, August, September, October, November, December };
public:
	CDate();
	CDate(const CDate& d);
	CDate(int y = 0, int m = 0, int d = 0) :Year(y), Month(m), Day(d) {}
	//void SetDate(int ,int ,int );
	//void GetDate(char *);
	inline void SetYear(int y) { Year = y; }
	inline void SetMonth(int m) { Month = m; }
	inline void SetDay(int d) { Day = d; }
	inline int GetYear() { return Year; }
	inline int GetMonth() { return Month; }
	inline int GetDay() { return Day; }
	inline void ShowDate() { cout << Year << "." << Month << "." << Day << endl; }
	char* GetWeekNameofDate(const CDate& d) {
		int month = d.Month, year = d.Year, day = d.Day;
		if (month == 1 || month == 2)	year--, month += 12;
		int c = year / 100, y = year - c * 100, week = (c / 4) - 2 * c + (y + y / 4) + (13 * (month + 1) / 5) + day - 1;
		while (week < 0) { week += 7; }	week %= 7;
		switch (week) {
		case Monday:cout << "Monday"; break;	case Tuesday:cout << "Tuesday"; break;
		case Wednesday:cout << "Wednesday"; break;	case Thursday:cout << "Thursday"; break;
		case Friday:cout << "Friday"; break;	case Saturday:cout << "Saturday"; break;
		case Sunday:cout << "Sunday"; break;
			cout << endl;
		}
	}
	char* GetMonthNameofDate(const CDate& d) {
		if (d.Month == January) cout << "January"; else if (d.Month == February)cout << "February"; else if (d.Month == Mars)cout << "Mars"; else if (d.Month == April)cout << "April";
		else if (d.Month == May)cout << "May"; else if (d.Month == June)cout << "June"; else if (d.Month == July)cout << "July"; else if (d.Month == August)cout << "August";
		else if (d.Month == September)cout << "September"; else if (d.Month == October)cout << "October"; else if (d.Month == November)cout << "November"; else cout << "December";
		cout << endl;
	}
	bool IsLeapYear(int year) { year = Year; if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return true; else return false; }
	bool operator <(const CDate& d) const {
		if (Year < d.Year)	return true;
		else if (Year == d.Year) {
			if (Month < d.Month)  return true;
			else if (Month == d.Month) {
				if (Day < d.Day)  return true;
				else  return false;
			}
			else return false;
		}
		else return false;
	}
	bool operator <=(const CDate& d) const {
		if (Year <= d.Year)	return true;
		else if (Year == d.Year) {
			if (Month <= d.Month)  return true;
			else if (Month == d.Month) {
				if (Day <= d.Day)  return true;
				else  return false;
			}
			else return false;
		}
		else return false;
	}
	bool operator >(const CDate& d) const {
		if (Year > d.Year)	return true;
		else if (Year == d.Year) {
			if (Month > d.Month)  return true;
			else if (Month == d.Month) {
				if (Day > d.Day)  return true;
				else  return false;
			}
			else return false;
		}
		else return false;
	}
	bool operator >=(const CDate& d) const {
		if (Year >= d.Year)	return true;
		else if (Year == d.Year) {
			if (Month >= d.Month)  return true;
			else if (Month == d.Month) {
				if (Day >= d.Day)  return true;
				else  return false;
			}
			else return false;
		}
		else return false;
	}
	bool operator ==(const CDate& d) const {
		if (Year == d.Year && Month == d.Month && Day == d.Day)return true;
		else return false;
	}
	bool operator !=(const CDate& d) const {return !(*this == d); }
	CDate& operator +(const CDate& d) {	Year += d.Year; Month = +d.Month; Day += d.Day;	}
	CDate& operator -(const CDate& d) { Year -= d.Year; Month -= d.Month; Day -= d.Day; }
	int operator +(int tday);
	void operator ++();
	void operator --();
	//friend ostream& operator <<(ostream& out, const CDate& d);
	//friend istream& operator >>(istream& in, CDate& d);
};
class  CTime {
	int Hour, Minute, Second; //分别存放时、分、秒
	//static int format;      //用于确定采用哪种制式显示时间
public:
	CTime();
	CTime(const CTime& d);
	CTime(int h = 0, int m = 0, int s = 0) :Hour(h), Minute(m), Second(s) {}
	//void SetTime(int ,int ,int );
	//void GetTime(char *);
	inline void SetHour(int h) { Hour = h; }
	inline void SetMinute(int m) { Minute = m; }
	inline void SetSecond(int s) { Second = s; }
	inline int GetHour() { return Hour; }
	inline int GetMinute() { return Minute; }
	inline int GetSecond() { return Second;  }
	inline void ShowTime() { cout << Hour << ":" << Minute << ":" << Second << endl; }
	bool operator <(const CTime& t) const {
		if (Hour < t.Hour)	return true;
		else if (Hour == t.Hour) {
			if (Minute < t.Minute)  return true;
			else if (Minute == t.Minute) {
				if (Second < t.Second)  return true;
				else  return false;
			}
			else return false;
		}
		else return false;
	}
	bool operator <=(const CTime& t) const {
		if (Hour <= t.Hour)	return true;
		else if (Hour == t.Hour) {
			if (Minute <= t.Minute)  return true;
			else if (Minute == t.Minute) {
				if (Second <= t.Second)  return true;
				else  return false;
			}
			else return false;
		}
		else return false;
	}
	bool operator >(const CTime& t) const {
		if (Hour > t.Hour)	return true;
		else if (Hour == t.Hour) {
			if (Minute > t.Minute)  return true;
			else if (Minute == t.Minute) {
				if (Second > t.Second)  return true;
				else  return false;
			}
			else return false;
		}
		else return false;
	}
	bool operator ==(const CTime& t) const {
		if (Hour == t.Hour && Minute == t.Minute && Second == t.Second)	return true;
		else  return false;
	}
	bool operator !=(const CTime& t) const { return (*this) == t; }
	CTime& operator +(const CTime& t) { Hour += t.Hour; Minute += t.Minute; Second += t.Second; }
	CTime& operator -(const CTime& t) { Hour -= t.Hour; Minute -= t.Minute; Second -= t.Second; }
	void operator ++() { Hour += 1; Minute += 1; Second += 1; }
	void operator --() { Hour -= 1; Minute -= 1; Second -= 1; }
	//friend ostream& operator <<(ostream& out, const CTime& t);
	//friend istream& operator >>(istream& in, CTime& t);
};
class Time:public CDate,public CTime {
public:
	Time(int y, int m1, int d, int h, int m2, int s) :CDate(y, m1, d), CTime(h, m2, s) {}
};
int main() {
	Time t(2023, 12, 10, 18, 24, 27);
	t.ShowDate(); t.ShowTime();
	return 0;
}


