#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class date{
	int day;
	int month;
	int year;
	public:
		void getdate();
		int validate(int);
		void display();
		friend char* get_date(int);
};

void date::getdate()
{
	cout<<"Enter the Date:";
	scanf("%d/%d/%d",&day,&month,&year);
}

int date::validate(int age)
{
	int y;
	y=2021-year;
	if(month>12||month<=0)
		return 0;
	
		switch(month)
		{
			case 1:
				case 3:
					case 5:
						case 7:
							case 8:
								case 10:
									case 12:
										if(day>31||day<=0)			
											return 0;
											break;
			case 4:
				case 6:
					case 9:
						case 11:
							if(day>30||day<=0)
								return 0;
								break;
			case 2:
				if(day>28||day<=0)
					return 0;
					break;
		}
	if(07<month)
	{
		y--;
	}
	if(y>=age)return 1; else return 0;
}

void date::display()
{
	cout<<day<<endl<<month<<endl<<year;
}
char dob[11];

char* get_date(int n)
{
	
	date d;
	d.getdate();
	while(!d.validate(n))
	{
		cout<<"Invalid Date!!";
		d.getdate();
	}
//		d.display();

	sprintf((char*)dob,"%d/%d/%d",d.day,d.month,d.year);
	return dob;
}

// int main()
// {
// 	char ch[11];
// 	strcpy(ch,get_date(18));
// 	cout<<"DOB"<<ch;
// }
