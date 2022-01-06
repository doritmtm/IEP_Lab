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
    ~Clockk()
    {
        //delete &hours;
        //delete &minutes;
       // delete &seconds;
    }
    Clockk(int h,int m,int s)
    :hours(h),
    minutes(m),
    seconds(s){}
    void show()
    {
        cout<<"C("<<hours<<","<<minutes<<","<<seconds<<")";
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
    c2=c1;
    c2.show();
    c3.show();
    cout<<"\n";
    return 0;
}