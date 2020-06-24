#include <stdio.h>
#include <stdlib.h>
 
void init();
char *CalculateDay( int y, int m, int d );	   /*用于计算输入的年月日对应的是周几*/ 
void showCalendar(int y, int m);		/*显示日历*/ 
int CalculatePerMonth(int y,int m);		/*计算每月都有多少天*/ 
 
int year;
int month;
int day;
 
int main(int argc, char *argv[])
 {
	char *weekstr; 
	
	init();				/*初始化界面，提示用户输入年月日*/
	scanf("%d%d%d",&year,&month,&day);	
	weekstr=CalculateDay(year,month,day); /*根据用户的输入计算年月日*/
	printf("\n%d年%d月%d日是\t%s",year,month,day,weekstr);
	showCalendar(year,month) ;/*显示日历*/
	
	getch();   //画面暂停，按任意键继续
	
	return 0;	
}
 
/**
*模块名称：init
* 功   能：初始化显示界面，提示用户输入年月日
*输    入：无
*输    出：无
*/ 
void init()
{
	printf("\n========欢迎使用万年日历简洁版========\n");
	printf("\n请输入年月日:\n");
}
 
/**
*模块名称:CalculateDay
*功    能：根据输入的年月日计算是周几
*输    入：年  月  日
*返回值  ：周几
*/ 
 
char *CalculateDay( int y, int m, int d)
{
	static int r[13]={0,0,3,3,6,1,4,6,2,5,0,3,5};
	int c,w;
	char *week;
	y %= 400;
    if ((y == 0 || y % 4 == 0 && y % 100 != 0) && m < 3) 
         c = 5;
    else 
         c = 6;
    w = (y + y / 4 - y / 100 + r[m] + d + c) % 7;
    switch(w)
    {
    	case 0:
    		week="星期天";
    		break;
    	case 1:
    		week="星期一";
    		break;
    	case 2:
    		week="星期二";
    	    break;
    	case 3:
    		week="星期三";
    		break;
    	case 4:
    		week="星期四";
    		break;
    	case 5:
    		week="星期五";
    		break;
    	case 6:
    		week="星期六";
    		break;
    }
    
    return week;    
}
 
/**
*模块名称： 计算每月有多天
*输    入：年，月
*输    出：每月天数
*/ 
int CalculatePerMonth( int y,int m)
{
	if((m==1) || (m==3) || (m==5) ||(m==7) || (m==8) || (m==10) || (m==12))
		return 31;
	else if(m!=2)
		return 30;
	else if((y%4 == 0)&&(y%100 != 0)||(y%400 ==0))
	    return 29;
	else 
		return 28;
}
 
/**
*模块名称：showCalendar
*功    能：显示日历
*输    入：年  月   日 
*输    出：无
*/ 
void showCalendar(int y, int m)
{
	char *week;          /*每月的1号是周几*/ 
	int perMonth;	/*每月共有多少天*/
	int w; 
	
	perMonth=CalculatePerMonth(y,m);	
	week=CalculateDay(y,m,1);
			
	if(week=="星期天")
		w=0;
	else if(week=="星期一")
		w=1;
	else if(week=="星期二")
		w=2;
	else if(week=="星期三")
		w=3;
	else if(week=="星期四")
		w=4;
	else if(week=="星期五")
		w=5;
	else if(week="星期六")
		w=6;
	 
	printf("\n======================================\n");
	printf("\n日    一    二    三    四    五    六\n");
	printf("\n======================================\n");
	
	
	int i=0;
	int count=w;
	
	while(w>0)
	{ 
		printf("      ");
		w--;
	}			
			
	for(i=1;i<=perMonth;i++)
	{
		printf("%-6d",i);
		count++;
		if(count==7)
		{
			printf("\n");
			count=0;
		}				
	}
} 