#include <iostream>
using namespace std;
class Clockk{
    private:
    int hours;
    int minutes;
    int seconds;
    public:
    Clockk()
    :hours(12),
    minutes(0),
    seconds(0){}
    Clockk(const Clockk& ccopy)
    {
        hours=ccopy.hours;
        minutes=ccopy.minutes;
        seconds=ccopy.seconds;
    }
    Clockk& operator=(const Clockk& ccopy)
    {
        hours=ccopy.hours;
        minutes=ccopy.minutes;
        seconds=ccopy.seconds;
        return *this;
    }
    Clockk& operator+=(const Clockk& ccopy)
    {
        hours+=ccopy.hours;
        minutes+=ccopy.minutes;
        seconds+=ccopy.seconds;
        fixClockFormat();
        return *this;
    }
    Clockk operator+(const Clockk& ccopy)
    {
        Clockk clk;
        clk.hours=ccopy.hours+this->hours;
        clk.minutes=ccopy.minutes+this->minutes;
        clk.seconds=ccopy.seconds+this->seconds;
        clk.fixClockFormat();
        return clk;
    }
    void fixClockFormat()
    {
        if(seconds>=60)
        {
            minutes+=seconds/60;
            seconds=seconds%60;
        }
        if(minutes>=60)
        {
            hours+=minutes/60;
            minutes=minutes%60;
        }
        if(hours>=24)
        {
            hours=hours%24;
        }
    }
    ~Clockk()
    {

    }
    Clockk(int h,int m,int s)
    :hours(h),
    minutes(m),
    seconds(s){}
    void show()
    {
        cout<<"C("<<hours<<","<<minutes<<","<<seconds<<")"<<"\n";
    }
};
int main()
{
    int a;
    int b=3;
    cout<<a<<" "<<b;
    Clockk c1;
    Clockk c2(23,59,59);
    Clockk c3(c2);
    c1.show();
    c2.show();
    c2=c1=c3;
    c2.show();
    c3.show();
    cout<<"\n";
    Clockk c4;
    Clockk c5(13,55,59);
    Clockk c7(1,1,1);
    Clockk c6(c7);
    c4=c5+c6+c7;
    c6+=c5+=c4;
    c4.show();
    c5.show();
    c6.show();
    c7.show();
    return 0;
}