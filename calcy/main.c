#include "header.h"

void eraseString(char *s,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	 	s[i]=0;
	}
	
}

void eraseIntArr(int *p,int n)
{
	   int i;
		for(i=0;i<=n;i++)
		{
	 		p[i]=0;
		}

}

void eraseFloatArr(float *p,int n)
{
	   int i;
		for(i=0;i<=n;i++)
		{
	 		p[i]=0;
		}

}

char s[100]={0};
float arr[20]={0},num=0,decimal=1,b=0 ;
int i,j,flag=0,m=0,f=0;
char operator[20]={0},k=0;
char fn[20]={0};


main()
 {
	uart0init(9600);
	init();
 
 while(1)
 {	

 	eraseFloatArr(arr,20);
 	eraseString(s,100);	
	eraseString(operator,20);
	eraseString(fn,20);

	uart0RxString(s,60);
	//uart0TxString(s);
	
	num=0,decimal=1,b=0;
	flag=0,m=0,f=0;
	k=0;

	if(s[0]=='-'||s[0]=='+')
	{
	 	i=1;
	}
	else
	{
	 	i=0;
	}
	j=0;

	for(;s[i];i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
		 	if(flag==0)
			{
			 	num=num*10+s[i]-'0';
			}
			else
			{
			 	b=b*10+(s[i]-'0');
				decimal=decimal*0.1f;
			}
			if(s[i+1]==0)
			{
				arr[j]=num+b*decimal;
			}
			continue;
		}

		if(s[i]=='.')
		{
		 	flag=1;
			continue;
		}

		if(s[0]=='-' && j==0)
		{
		 	arr[j]=-num-b*decimal;
		}
		else
		{
		 	arr[j]=num+b*decimal;
		}
		j++;
		
		switch(s[i])
		{
		 	case '+':
			case '-':
			case '*':
			case '/':decimal=1;
					flag=0;
					operator[k]=s[i];
					k++;
					break;

		}
		num=0;b=0;
	}

	uart0TxString("\r\n");

	for(m=0;m<=j;m++)
	{
			 sprintf2(fn,arr[m]);
			 uart0TxString("   ");
			 uart0TxString(fn);
			 uart0TxString("   ");
			 eraseString(fn,20);
	}
	  uart0TxString(operator);
		
	m=0;

	while(operator[m])
	{
			if(operator[m]=='/'||operator[m]=='*')
			{
			 	if(operator[m]=='/')
				{
				 	if(arr[m+1]==0)
					{
					 	uart0TxString("\r\n NOT POSSIBLE   ");
						return 1;
					}
					arr[m]=arr[m]/arr[m+1];
				}
				else
				{
			 		arr[m]=arr[m]*arr[m+1];
				}

				for(f=m+1;f<j;f++)
				{
			 		arr[f]=arr[f+1];
				}
				j--;

				for(f=m;operator[f];f++)
				{
			 		operator[f]=operator[f+1];
				}
				k--;

				m--;
	           }
			  m++	 ;
	}	
	  m=0;

	 	 while(operator[m])
		{
			if(operator[m]=='+'||operator[m]=='-')
			{
			 	if(operator[m]=='+')
				{
					arr[m]=arr[m]+arr[m+1];
				}
				else
				{
			 		arr[m]=arr[m]-arr[m+1];
				}

				for(f=m+1;f<j;f++)
				{
			 		arr[f]=arr[f+1];
				}
				j--;

				for(f=m;operator[f];f++)
				{
			 		operator[f]=operator[f+1];
				}
				k--;

				m--;
		}
			m++	   ;
		}	
		uart0TxString("\r\n");
			sprintf2(fn,arr[0]);
			 uart0TxString("   ");
			 uart0TxString(fn);
			 uart0TxString("   ");
			 eraseString(fn,20);
		uart0TxString("\r\n");
}

}


