/*
	X Macro example for creating enums in C++
	https://ideone.com/bPAVTM
*/

#include <iostream>

#define WEEK_DAYS \
X(MON, "Monday", true) \
X(TUE, "Tuesday", true) \
X(WED, "Wednesday", true) \
X(THU, "Thursday", true) \
X(FRI, "Friday", true) \
X(SAT, "Saturday", false) \
X(SUN, "Sunday", false)

#define X(day, name, workday) day,
enum WeekDay : size_t
{
    WEEK_DAYS
};
#undef X

#define X(day, name, workday) name,
char const *weekday_name[] =
{
    WEEK_DAYS
};
#undef X

#define X(day, name, workday) workday,
bool weekday_workday[]
{
    WEEK_DAYS
};
#undef X

int main()
{
    std::cout << "Enum value: " << WeekDay::THU << std::endl;
    std::cout << "Name string: " << weekday_name[WeekDay::THU] << std::endl;
    std::cout << std::boolalpha << "Work day: " << weekday_workday[WeekDay::THU] << std::endl;

    WeekDay wd = SUN;
    std::cout << "Enum value: " << wd << std::endl;
    std::cout << "Name string: " << weekday_name[wd] << std::endl;
    std::cout << std::boolalpha << "Work day: " << weekday_workday[wd] << std::endl;

    return 0;
}
