#include<iostream>
using namespace std;
class stack{
public:	
int top=-1,size=60;char a[60];
	void push(stack,char b)
	{
		if(top>size-1)
		cout<<"overflow";
		else{
			top=top+1;
			a[top]=b;
			
		    }
	}
	char pop()
	{char n;
		if(top<0)
		cout<<"underflow";
		else 
		{ n=a[top];
		top=top-1;
		}
		return n;
	}
	void display(char z[50],int j)
	{
		if(top>size-1)
		cout<<"overflow";
		   else if(top<-1)
		cout<<"underflow";
		else 
	{
		for(int i=0;i<=j;i++)
		cout<<z[i];
		
		}
}
int priorty(char ch)
{ 
 switch(ch)
{
	case'+':
	case'-':return 0;break;
	case'*':
	case'/':return 1;break;
	case'^':return 3;
  }
}

};
int main()
{stack s;char ch[100],st[100];
int i,j=0;
	cout<<"enter the infix string:";
	cin>>ch;
	
	for(i=0;ch[i]!='\0';i++)
	{
		if(ch[i]=='+'||ch[i]=='-'||ch[i]=='*'||ch[i]=='/'||ch[i]=='^')
		  {
		  	if(s.top==-1)
		  	  s.push(s,ch[i]);
		  	  
		    else if((s.priorty(ch[i]))>(s.priorty(s.a[s.top])))
		           s.push(s,ch[i]);
		           
	     	else if((s.priorty(ch[i]))<(s.priorty(s.a[s.top])))
	         	{
		     	st[j++]=s.pop();
		     	s.push(s,ch[i]);
		         }
        	}
		else
			{
			st[j]=ch[i];j++;}
		
	
	}
//	cout<<"st:"<<st<<endl;
	while(s.top!=-1)
	 {
	 char n=s.pop();
	 st[j++]=n;}
	st[j]='\0';
s.display(st,j);
	
	
}
