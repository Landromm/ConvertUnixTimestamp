// ConvertUnixTimestamp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int seconds, minutes, hours, days, year, month;

void ConvertUnixTime(int unixTime)
{
    seconds = unixTime + 3600 * 3;
    minutes = seconds / 60;
    seconds -= minutes * 60;
    hours = minutes / 60;
    minutes -= hours * 60;
    days = hours / 24;
    hours -= days * 24;

    /* Unix time стартует в 1970 году.*/
    year = 1970;
    
    while (1)
    {
        bool     leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        short daysInYear = leapYear ? 366 : 365;
        if (days >= daysInYear)
        {
            days -= daysInYear;
            year++;
        }
        else
        {
            /* Расчет месяца и дня */
            static const char daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            for (month = 0; month < 12; ++month)
            {
                char dim = daysInMonth[month];

                /* Добавляем день если год високосный.*/
                if (month == 1 && leapYear)
                    dim++;

                if (days >= dim)
                    days -= dim;
                else
                    break;
            }
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    seconds = 1230757199;

    ConvertUnixTime(seconds);

    std::cout << days+1 << "." << month+1 << "." << year << " " << hours << ":" << minutes << ":" << seconds << "\n";

}
