#include <iostream>
using namespace std;
class Time
{
private:
    int hour, min;

public:
    Time(int h, int m) : hour(h), min(m) {}
    Time(int h) : hour(h), min(0) {}
    void changetime(int h, int m)
    {
        hour = h;
        min = m;
    }
    inline int get_hour() { return hour; }
    inline int get_min() { return min; }
    int compare(Time t2)
    {
        int x1 = hour * 100 + min;
        int x2 = t2.hour * 100 + t2.min;
        if (x1 > x2)
            return 1;
        else if (x1 == x2)
            return 0;
        else
            return -1;
    }
    string daytime()
    {
        if (hour >= 0 && hour < 12)
            return "morning";
        else if (hour == 12 && min == 0)
            return "noon";
        else if (hour < 17)
            return "afternoon";
        else if (hour < 20)
            return "evening";
        else
            return "night";
    }
};
bool test(int h, int m)
{
    if (h < 0 || h > 23)
        return false;
    if (m < 0 || m > 59)
        return false;
    return true;
}
int main()
{
    int h, m;
    cout << "Hour:";
    cin >> h;
    cout << "Min:";
    cin >> m;
    if (test(h, m))
    {
        Time time(h, m);
        bool contin = true;
        int list = 0;
        while (contin)
        {
            system("cls");
            cout << "1-see time\n2-change time\n3-compare\n4-day time\n5-exit";
            cin >> list;
            switch (list)
            {
            case 1:
                system("cls");
                cout << time.get_hour() << ":" << time.get_min() << "\n";
                system("pause");
                break;
            case 2:
                system("cls");
                int h0, m0;
                cout << "Hour:";
                cin >> h0;
                cout << "Min:";
                cin >> m0;
                if (test(h0, m0))
                    time.changetime(h0, m0);
                else
                    cout << "wrong\n";
                system("pause");
                break;
            case 3:
                system("cls");
                int h1, m1;
                cout << "Hour:";
                cin >> h1;
                cout << "Min:";
                cin >> m1;
                if (test(h1, m1))
                {
                    Time time2(h1, m1);
                    cout << time.compare(time2) << "\n";
                }
                else
                    cout << "wrong\n";
                system("pause");
                break;
            case 4:
                system("cls");
                cout << time.daytime() << "\n";
                system("pause");
                break;
            case 5:
                contin = false;
                break;
            }
        }
        system("pause");
        return 0;
    }
}