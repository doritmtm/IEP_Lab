#include <iostream>
using namespace std;
class ClockkProps
{
    private:
    string manufacturer;
    public:
    ClockkProps(string manufacturer)
    {
        this->manufacturer=manufacturer;
    }
    ClockkProps(const ClockkProps& ccopy)
    {
        manufacturer=ccopy.manufacturer;
    }
    string getManufacturer()
    {
        return manufacturer;
    }
};
class Clockk{
    private:
    int hours;
    int minutes;
    int seconds;
    ClockkProps *properties;
    public:
    Clockk()
    :hours(12),
    minutes(0),
    seconds(0)
    {
        properties=new ClockkProps("");
    }
    Clockk(string manufacturer)
    :hours(12),
    minutes(0),
    seconds(0)
    {
        properties=new ClockkProps(manufacturer);
    }
    Clockk(const Clockk& ccopy)
    {
        hours=ccopy.hours;
        minutes=ccopy.minutes;
        seconds=ccopy.seconds;
        properties=new ClockkProps(*ccopy.properties);
    }
    Clockk& operator=(const Clockk& ccopy)
    {
        hours=ccopy.hours;
        minutes=ccopy.minutes;
        seconds=ccopy.seconds;
        //*properties=*ccopy.properties;
        //delete properties;
        ClockkProps* old=properties;
        properties=new ClockkProps(*ccopy.properties);
        delete old;
        return *this;
    }
    Clockk& operator+=(const Clockk& ccopy)
    {
        hours+=ccopy.hours;
        minutes+=ccopy.minutes;
        seconds+=ccopy.seconds;
        fixClockFormat();
        //*properties=*ccopy.properties;
        //delete properties;
        ClockkProps* old=properties;
        properties=new ClockkProps(*ccopy.properties);
        delete old;
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
    seconds(s)
    {
        properties=new ClockkProps("");
    }
    Clockk(int h,int m,int s,string manufacturer)
    :hours(h),
    minutes(m),
    seconds(s)
    {
        properties=new ClockkProps(manufacturer);
    }
    void show()
    {
        if(properties->getManufacturer().compare("")==0)
        {
            cout<<"C("<<hours<<","<<minutes<<","<<seconds<<")"<<"\n";
        }
        else
        {
            cout<<"C("<<hours<<","<<minutes<<","<<seconds<<","<<properties->getManufacturer()<<")"<<"\n";
        }
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
    c4.show();
    Clockk c7(1,1,1);
    Clockk c6(c7);
    c4=c5+c6+c7;
    c6+=c5+=c4;
    c4.show();
    c5.show();
    c6.show();
    c7.show();
    cout<<'\n';
    Clockk c8(c8); //???
    c8.show();
    Clockk c9("Samsung");
    c9.show();
    Clockk c10(15,14,23,"Motorola");
    c10.show();
    Clockk c11(c9);
    c11=c10;
    c11+=c11;
    c11=c11;
    c11.show();
    Clockk& c12=*new Clockk;
    c12.show();
    delete &c12;
    Clockk c13=*new Clockk; //=> Clockk c13(*new Clockk);
    c13.show();
    Clockk c14(*new Clockk);
    c14.show();
    return 0;
}