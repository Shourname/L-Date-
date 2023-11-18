#include <iostream>
using namespace std;

class Date 
{
    private:
        bool isOurEra;
        int year, month, day, hour, minute, second;
        static int month_[13];
        
        void checkThis()
        {
            if (isOurEra == false) year = (-1)*year; else year = year;

            while(second > 60) { minute++; second -= 60; }
            while(second < 0) { minute--; second += 60; }
            while(minute > 60) { hour++; minute -= 60; }
            while(minute < 0) { hour--; minute += 60; }
            while(hour > 24) { day++; hour -= 24; }
            while(hour < 0) { day--; hour += 24; }
            while(month > 12) { year++; month -= 12; }
            while(month < 0) { year--; month += 12; }

            if (checkLeapThis(year)) { month_[2] = 29; } else month_[2] = 28;

            while(day > month_[month])
            {
                month++;
                day -= month_[month];
                if (month > 12) { year++; month = 1; }
            }
            while(day <= 0)
            {
                month--;
                day += month_[month];
                if (month < 0) {year--; month = 1; }
            }
        }

        bool checkLeapThis(int year) const
        {
            if ((year % 4 == 0 and year % 100 != 0) or (year % 400 == 0)) return true; else return false;
        }
        
    public:
        Date()
        {
            this->isOurEra = true;
            this->year = 1960;
            this->month = 1;
            this->day = 1;
            this->hour = 0;
            this->minute = 0;
            this->second = 0;
        }

        Date (const Date& dt)
        {
            this->isOurEra = dt.isOurEra;
            this->year = dt.year;
            this->month = dt.month;
            this->day = dt.day;
            this->hour = dt.hour;
            this->minute = dt.minute;
            this->second = dt.second;
        }

        Date(bool Era, int Year, int Month, int Day, int Hour, int Minute, int Second)
        {
            this->isOurEra = Era;
            this->year = Year;
            this->month = Month;
            this->day = Day;
            this->hour = Hour;
            this->minute = Minute;
            this->second = Second;

            checkThis();
        }

        Date& operator+=(const Date& dt)
        {
            this->isOurEra = dt.isOurEra;
            this->year += dt.year;
            this->month += dt.month;
            this->day += dt.day;
            this->hour += dt.hour;
            this->minute += dt.minute;
            this->second += dt.second;

            checkThis();

            return *this;
        }

        Date& operator+(const Date& dt) const
        {
            Date res = *this;
            res.checkThis();
            return res += dt;
        }

        Date& operator-=(const Date& dt)
        {
            this->isOurEra = dt.isOurEra;
            this->year -= dt.year;
            this->month -= dt.month;
            this->day -= dt.day;
            this->hour -= dt.hour;
            this->minute -= dt.minute;
            this->second -= dt.second;

            checkThis();

            return *this;
        }

        Date& operator-(const Date& dt) const
        {
            Date res = *this;
            res.checkThis();
            return res -= dt;
        }

        Date& operator=(const Date& dt)
        {
            this->isOurEra = dt.isOurEra;
            this->year = dt.year;
            this->month = dt.month;
            this->day = dt.day;
            this->hour = dt.hour;
            this->minute = dt.minute;
            this->second = dt.second;

            return *this;
        }

        bool operator==(const Date& dt) const
        {
            if (this->isOurEra == dt.isOurEra and this->year == dt.year and this->month == dt.month and this->day == dt.day and this->hour == dt.hour and this->minute == dt.minute and this->second == dt.second) return true;
            else return false;
        }

        bool operator>(const Date& dt) const
        {
            if (this->isOurEra > dt.isOurEra) return true; else
            {
                if (this->year > dt.year) return true; else
                {
                    if (this->month > dt.month) return true; else
                    {
                        if (this->day > dt.day) return true; else
                        {
                            if (this->hour > dt.hour) return true; else
                            {
                                if (this->minute > dt.minute) return true; else
                                {
                                    if (this->second > dt.second) return true; else return false;
                                }
                            }
                        }
                    }
                }
            }
        }

        bool operator<(const Date& dt) const
        {
            if (this->isOurEra < dt.isOurEra) return true; else
            {
                if (this->year < dt.year) return true; else
                {
                    if (this->month < dt.month) return true; else
                    {
                        if (this->day < dt.day) return true; else
                        {
                            if (this->hour < dt.hour) return true; else
                            {
                                if (this->minute < dt.minute) return true; else
                                {
                                    if (this->second < dt.second) return true; else return false;
                                }
                            }
                        }
                    }
                }
            }
        }

        friend ostream& operator<<(ostream& os, const Date& dt)
        {
            os << "NowDate: [ " << dt.isOurEra << " ";
            
            cout << dt.year << " ";
            cout << dt.month << " ";
            cout << dt.day << " ";
            cout << dt.hour << " ";
            cout << dt.minute << " ";
            cout << dt.second << " ";

            os << "]" << endl;
            return os;
        }

        Date add(int YEAR, int MONTH, int DAY, int HOUR, int MINUTE, int SECOND) const
        {
            Date dd = *this;

            dd.year += YEAR;
            dd.month += MONTH;
            dd.day += DAY;
            dd.hour += HOUR;
            dd.minute += MINUTE;
            dd.second += SECOND;

            dd.checkThis();

            return dd;
        }

        Date subtruct(int YEAR, int MONTH, int DAY, int HOUR, int MINUTE, int SECOND) const
        {
            Date dd = *this;

            dd.year -= YEAR;
            dd.month -= MONTH;
            dd.day -= DAY;
            dd.hour -= HOUR;
            dd.minute -= MINUTE;
            dd.second -= SECOND;

            dd.checkThis();

            return dd;
        }
        
};

int Date::month_[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
    
    Date dateOne(false, 456, 23, 18, 89, 123, 14);
    Date dateTwo;
    Date dateThree;

    cout << "Output = [ IsOurEra (1 - OurEra; 0 - BeforeOurEra) Year Month Day Hour Minute Second ]" << endl;
    
    return 0;
}
