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

};

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

    std::cout << dt1.GetYear() <<"." <<dt1.GetMonth() <<"." << dt1.GetDay() <<"\n";
    std::cout << dt2.GetYear() <<"."<<dt2.GetMonth() << "."<< dt2.GetDay() << "\n";
}
