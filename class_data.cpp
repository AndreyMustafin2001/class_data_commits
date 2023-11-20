#include <iostream>

class Date {

    private:

        int year;
        int month;
        int day;

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
}
Date::Date(int d) {
    year = 0;
    month = 1;
    day = d;
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
    Date dt1(19,12,25);
    Date dt2(30);

    std::cout << dt1.GetYear() <<"-" <<dt1.GetMonth() <<"-" << dt1.GetDay() <<"\n";
    std::cout << dt2.GetYear() <<"-"<<dt2.GetMonth() << "-"<< dt2.GetDay() << "\n";
}
