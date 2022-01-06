#include <iostream>
#include <memory>
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
    Clockk operatorPlusWithoutFormat(const Clockk& ccopy)
    {
        Clockk clk;
        clk.hours=ccopy.hours+this->hours;
        clk.minutes=ccopy.minutes+this->minutes;
        clk.seconds=ccopy.seconds+this->seconds;
        //clk.fixClockFormat();
        return clk;
    }
    Clockk& operatorPlusEgalWithoutFormat(const Clockk& ccopy)
    {
        hours+=ccopy.hours;
        minutes+=ccopy.minutes;
        seconds+=ccopy.seconds;
        //fixClockFormat();
        //*properties=*ccopy.properties;
        //delete properties;
        ClockkProps* old=properties;
        properties=new ClockkProps(*ccopy.properties);
        delete old;
        return *this;
    }
    int fixClockFormat()
    {
        int days=0;
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
            days=hours/24;
            hours=hours%24;
        }
        return days;
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
class DaysClockk : public Clockk {
    private:
    int days;
    public:
    DaysClockk()
    :Clockk(),
    days(0){}
    DaysClockk(string m)
    :Clockk(m),
    days(0){}
    DaysClockk(int h,int m,int s)
    :Clockk(h,m,s),
    days(0){}
    DaysClockk(int h,int min,int s,string m)
    :Clockk(h,min,s,m),
    days(0){}
    DaysClockk(int d)
    :Clockk(),
    days(d){}
    DaysClockk(int d,string m)
    :Clockk(m),
    days(d){}
    DaysClockk(int d,int h,int m,int s)
    :Clockk(h,m,s),
    days(d){}
    DaysClockk(int d,int h,int min,int s,string m)
    :Clockk(h,min,s,m),
    days(d){}
    DaysClockk(const DaysClockk& dccopy)
    :Clockk(dccopy)
    {
        days=dccopy.days;
    }

    DaysClockk& operator=(const DaysClockk& dccopy)
    {
        Clockk::operator=(dccopy);
        days=dccopy.days;
        return *this;
    }
    DaysClockk& operator+=(const DaysClockk& dccopy)
    {
        Clockk::operatorPlusEgalWithoutFormat(dccopy);
        //Clockk::fixClockFormat();
        //Clockk::operator+=(dccopy);
        fixClockFormat();
        days+=dccopy.days;
        return *this;
    }
    DaysClockk& operator+(const DaysClockk& dccopy)
    {
        Clockk::operatorPlusWithoutFormat(dccopy);
        fixClockFormat();
        return *this;
    }
    void fixClockFormat()
    {
        days+=Clockk::fixClockFormat();
    }
    void show()
    {
        cout<<"DC("<<days<<",";
        Clockk::show();
        cout<<")\n";
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
    //Clockk c8(c8); //???
    //c8.show();
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
    //delete &c13;
    Clockk c14(*new Clockk);
    c14.show();
    //delete &c14;
    cout<<"\n";
    DaysClockk c15(14,15,29);
    DaysClockk c16(2);
    c7=c15;
    c7.show();
    c15=c15;
    c15+=c15;
    c15+=c16;
    c15.show();
    c16.show();
    cout<<"\n";
    /* auto_ptr<Clockk> apc(&c14);
    apc->show(); 
    double free error
    pentru ca se da free (delete) la c14 si la apc (adica tot c14) 
    */
    auto_ptr<Clockk> apc1(new Clockk(13,29,29));
    apc1->show();
    Clockk* c17=new Clockk(18,34,52);
    auto_ptr<Clockk> apc2(c17);
    c17->show();
    c17=new Clockk(21,13,15);
    apc2->show();
    c17->show();
    shared_ptr<Clockk> spc1(c17);
    spc1->show();
    auto_ptr<Clockk> apc3(apc1);
    //apc1->show(); NULL!!!
    apc3->show();
    //auto_ptr<Clockk> apc4(c17); Double free pt ca spc1 da free la c17 si apc4 da free tot la c17
    shared_ptr<Clockk> spc2(spc1);
    spc1->show();
    spc2->show();
    cout<<"Nr. referinte:"<<spc2.use_count()<<"\n";
    cout<<"Nr. referinte:"<<spc1.use_count()<<"\n";
    return 0;
}
