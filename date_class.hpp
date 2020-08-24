#ifndef _DATE_H_
#define _DATE_H_
#include <string>
using namespace std;
const int days_of_month_common[] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
const int days_of_month_leap[] = {31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
class Date {
  private:
    int _year, _month, _day;

  public:
    Date(int y = 0, int m = 1, int d = 1) : _year(y), _month(m), _day(d) {}
    static bool leapyear(int year) {
        if (year % 100 == 0) {
            return year % 400 == 0;
        } else {
            return year % 4 == 0;
        }
    }
    int getYear() const { return _year; }
    int getMonth() const { return _month; }
    int getDay() const { return _day; }
    void setYear(int y) { _year = y; }
    void setMonth(int m) { _month = m; }
    void setDay(int d) { _day = d; }

    void legalize() {
        const int* arr = leapyear(getYear()) ? days_of_month_leap : days_of_month_common;
        while (getDay() < 1) {
            int lastmonth = getMonth() - 1;
            if (lastmonth < 0) {
                lastmonth += 12;
            }
            _day += arr[lastmonth];
            _month -= 1;
            if (getMonth() < 1) {
                _month += 12;
                _year -= 1;
                arr = leapyear(getYear()) ? days_of_month_leap : days_of_month_common;
            }
        }
        while (getDay() > arr[getMonth() % 12]) {
            _day -= arr[getMonth() % 12];
            _month += 1;
            if (getMonth() > 12) {
                _month -= 12;
                _year += 1;
                arr = leapyear(getYear()) ? days_of_month_leap : days_of_month_common;
            }
        }
    }

    Date& operator=(Date rhs) {
        setYear(rhs.getYear());
        setMonth(rhs.getMonth());
        setDay(rhs.getDay());
        return *this;
    }
    bool operator==(Date& rhs) { return (getYear() == rhs.getYear()) && (getMonth() == rhs.getMonth()) && (getDay() == rhs.getDay()); }
    bool operator!=(Date& rhs) { return !(*this == rhs); }
    bool operator>(Date& rhs) {
        if (getYear() == rhs.getYear()) {
            if (getMonth() == rhs.getMonth()) {
                return getDay() > rhs.getDay();
            } else {
                return getMonth() > rhs.getMonth();
            }
        } else {
            return getYear() > rhs.getYear();
        }
    }
    bool operator>=(Date& rhs) { return (*this > rhs) && (*this == rhs); }
    bool operator<(Date& rhs) { return !(*this >= rhs); }
    bool operator<=(Date& rhs) { return !(*this > rhs); }

    Date operator+(int i) const {
        Date result(*this);
        result._day += i;
        result.legalize();
        return result;
    }
    Date& operator++() {
        *this = *this + 1;
        return *this;
    }
    Date operator++(int) {
        Date temp(*this);
        (*this)++;
        return temp;
    }
    Date operator-(int i) const {
        Date result(*this);
        result._day -= i;
        result.legalize();
        return result;
    }
    Date& operator--() {
        *this = *this - 1;
        return *this;
    }
    Date operator--(int) {
        Date temp(*this);
        (*this)--;
        return *this;
    }

    Date& operator+=(int i) {
        *this = *this + i;
        return *this;
    }
    Date& operator-=(int i) {
        *this = *this - i;
        return *this;
    }

    int& operator[](string s) {
        if (s == "year") {
            return _year;
        } else if (s == "month") {
            return _month;
        } else if (s == "day") {
            return _day;
        }
    }
    int operator[](string s) const {
        if (s == "year") {
            return getYear();
        } else if (s == "month") {
            return getMonth();
        } else if (s == "day") {
            return getDay();
        }
    }
};

#endif