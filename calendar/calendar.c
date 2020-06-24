#include <stdio.h>
#include <stdlib.h>
 
void init();
char *CalculateDay( int y, int m, int d );	   /*���ڼ�������������ն�Ӧ�����ܼ�*/ 
void showCalendar(int y, int m);		/*��ʾ����*/ 
int CalculatePerMonth(int y,int m);		/*����ÿ�¶��ж�����*/ 
 
int year;
int month;
int day;
 
int main(int argc, char *argv[])
 {
	char *weekstr; 
	
	init();				/*��ʼ�����棬��ʾ�û�����������*/
	scanf("%d%d%d",&year,&month,&day);	
	weekstr=CalculateDay(year,month,day); /*�����û����������������*/
	printf("\n%d��%d��%d����\t%s",year,month,day,weekstr);
	showCalendar(year,month) ;/*��ʾ����*/
	
	getch();   //������ͣ�������������
	
	return 0;	
}
 
/**
*ģ�����ƣ�init
* ��   �ܣ���ʼ����ʾ���棬��ʾ�û�����������
*��    �룺��
*��    ������
*/ 
void init()
{
	printf("\n========��ӭʹ��������������========\n");
	printf("\n������������:\n");
}
 
/**
*ģ������:CalculateDay
*��    �ܣ���������������ռ������ܼ�
*��    �룺��  ��  ��
*����ֵ  ���ܼ�
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
    		week="������";
    		break;
    	case 1:
    		week="����һ";
    		break;
    	case 2:
    		week="���ڶ�";
    	    break;
    	case 3:
    		week="������";
    		break;
    	case 4:
    		week="������";
    		break;
    	case 5:
    		week="������";
    		break;
    	case 6:
    		week="������";
    		break;
    }
    
    return week;    
}
 
/**
*ģ�����ƣ� ����ÿ���ж���
*��    �룺�꣬��
*��    ����ÿ������
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
*ģ�����ƣ�showCalendar
*��    �ܣ���ʾ����
*��    �룺��  ��   �� 
*��    ������
*/ 
void showCalendar(int y, int m)
{
	char *week;          /*ÿ�µ�1�����ܼ�*/ 
	int perMonth;	/*ÿ�¹��ж�����*/
	int w; 
	
	perMonth=CalculatePerMonth(y,m);	
	week=CalculateDay(y,m,1);
			
	if(week=="������")
		w=0;
	else if(week=="����һ")
		w=1;
	else if(week=="���ڶ�")
		w=2;
	else if(week=="������")
		w=3;
	else if(week=="������")
		w=4;
	else if(week=="������")
		w=5;
	else if(week="������")
		w=6;
	 
	printf("\n======================================\n");
	printf("\n��    һ    ��    ��    ��    ��    ��\n");
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