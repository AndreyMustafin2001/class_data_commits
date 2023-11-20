#include <iostream>

class Date {

    private:

        int year;
        int month;
        int day;

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    void Normalize() {

    while (month > 12) {
            month -= 12;
            year++;
        }

    while (month <= 0) {
            month += 12;
            year--;
        }

    while (day <= 0) {
        month--;
        if (month < 1) {
            month += 12;
            year--;
            }
            day += (month == 2) ? (isLeapYear(year) ? 29 : 28) :
                ((month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31);
        }

    int maxDays = 31;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        maxDays = 30;
    }
    else if (month == 2) {
        maxDays = isLeapYear(year) ? 29 : 28;
    }

    while (day > maxDays) {
        day -= maxDays;
        month++;
        if (month > 12) {
            month -= 12;
            year++;
        }
        maxDays = (month == 2) ? (isLeapYear(year) ? 29 : 28) :
             ((month == 4 || month == 6 || month == 9 || month == 11) ? 30 : 31);
    }
}
    public:

        Date(int y, int m, int d);

        Date(int d);

        int GetYear() const;
        int GetMonth() const;
        int GetDay() const;

        Date& operator += (int d) {
            day += d;
            Normalize();
            return *this;
        }

        Date operator+ (int d) const {
            int daynew = day + d;
            return Date(year, month, daynew);
        }

        Date operator- (int d) const {
            int daynew = day - d;
            return Date(year, month, daynew);
        }

};

std::ostream& operator << (std::ostream& out, const Date& dt) {
    out << dt.GetYear() << " year " << dt.GetMonth() << " month " << dt.GetDay() << " day " ;
    return out;
}

std::istream& operator >> (std::istream& in, Date& date) {
    int y, m, d;
    char c;

    in >> y >> c;
    in >> m >> c;
    in >> d;

    date = Date(y, m, d);

    return in;
}

Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
     Normalize();
}

Date::Date(int d) {
    year = 0;
    month = 1;
    day = d;
    Normalize();
}

int Date::GetYear() const {
    return year;
}

int Date::GetMonth() const {
    return month;
}

int Date::GetDay() const {
    return day;
}

int main(){
    Date dt1(19,60,70);
    Date dt2(40000);

    // dt2 += 50;
    // Date dt3 = dt1 - 50
    // Date dt3 = dt1 + 50;
    // std::cin >> dt1;

    std::cout << dt1 << "\n";
    std::cout << dt2 << "\n";
}
