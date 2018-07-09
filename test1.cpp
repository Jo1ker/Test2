#include<iostream>
using namespace std;

class Clock
{
	private:
		int Hour;
		int Minute;
		int Second;
	public:
		Clock(int hour=0,int minute=0,int second=0);
		void display();
		Clock operator+(Clock &c);
		Clock operator-(Clock &c);
		Clock operator++();	  //前置； 
		Clock operator++(int);//后置； 
		Clock operator--();   //前置； 
		Clock operator--(int);//后置； 
 } ;
 
 Clock::Clock(int hour,int minute,int second)
 {
 	Hour=hour;
 	Minute=minute;
 	Second=second;
 }
 
 void Clock::display()
 {
 	cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
 }
 
 Clock Clock::operator+(Clock &c) 
 {
 	int h,m,s;
 	s=Second+c.Second;
 	m=Second>=60?(Minute+c.Minute+1):(Minute+c.Minute);
 	h=Minute>=60?(Hour+c.Hour+1):(Hour+c.Hour);
 	s%=60;
 	m%=60;
 	h%=24;
 	return Clock(h,m,s);
 }
 
 Clock Clock::operator-(Clock &c)
 {
 	int h,m,s,s1,s2,s3;
 	s1=Hour*3600+Minute*60+Second;
 	s2=c.Hour*3600+c.Minute*60+c.Second;
 	s3=(s1-s2)>0?(s1-s2):(s2-s1);
 	h=s3/3600;
 	m=(s3-3600*h)/60;
 	s=(s3-3600*h)%60;
 	return Clock(h,m,s);
 }
 
 Clock Clock::operator++()	//前置++； 
 {
 	Second++;
 	return *this;
 }
 
 Clock Clock::operator++(int)//后置++（返回原值）； 
 {
 	Clock c=*this;
 	Second++;
 	return c;
 }
 
 Clock Clock::operator--()	//前置--； 
 {
 	int s=Hour*3600+Minute*60+Second;
 	s--;
 	if (s<0){cout<<"error!!"<<endl;return 0; }
 	Hour=s/3600;
 	Minute=(s-3600*Hour)/60;
 	Second=(s-3600*Hour)%60;
 	return *this;
  } 
  
 Clock Clock::operator--(int) //后置--（返回原值）； 
 {
 	Clock c=*this; 
 	int s=Hour*3600+Minute*60+Second;
 	s--;
 	if (s<0){cout<<"error!!"<<endl;return 0; }
 	Hour=s/3600;
 	Minute=(s-3600*Hour)/60;
 	Second=(s-3600*Hour)%60;
 	return c;
  } 
 
 int main()
 {
 	Clock c1(1,0,0),c2(0,0,1),c3,c4;
 	c3=c1+c2;
 	c3.display() ;
 	c4=c1-c2;
 	c4.display() ;
 	++c1;
 	c1.display() ;
 	++c2;
 	c2.display() ;
 	--c1;
 	c1.display() ;
 	c1--;
 	c1.display() ;
 	
 	return 0;
 }
