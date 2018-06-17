#include<bits/stdc++.h>
#include<string>

using namespace std;

char stac[20],val1[20],sym[20];
int val[20];
int top1=-1,top2=-1,top3=-1;
string input;

void print_stac()
{
	for(int i=0;i<=top1;i++)
	{
		cout<<stac[i];
	}
}
void print_val()
{
	for(int i=0;i<=top2;i++)
	{
		cout<<val[i]<<" ";
	}
}
void print_val1()
{
	for(int i=0;i<=top2;i++)
	{
		cout<<val1[i];
	}
}
void sdt()
{
	stac[0] = '$';top1=0;
	input[input.length()]='$';
	cout<<"Stack\tValue\n---------------\n";
	for(int i=0;i<input.length();i++)
	{
		if(input[i]>='0' && input[i]<='9')
		{
			stac[top1+1] = 'd';
			top1+=1;
			val[top2+1] = int(input[i])-48;
			top2+=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		else
		{
			stac[top1+1] = input[i];
			top1+=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='d' && stac[top1-1]=='I')
		{
			stac[top1-1] = 'I';
			top1-=1;
			val[top2-1] = 10*val[top2-1] + val[top2];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='d')
		{
			stac[top1]='I';
			
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='I' && (input[i+1]<'0' || input[i+1]>'9'))
		{
			stac[top1] = 'E';
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]==')' && stac[top1-1]=='E' && stac[top1-2]=='(')
		{
			stac[top1-2]='E';
			top1-=2;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='E' && stac[top1-1]=='+' && stac[top1-2]=='E')
		{
			stac[top1-2]='E';
			top1-=2;
			val[top2-1] = val[top2]+val[top2-1];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='E' && stac[top1-1]=='*' && stac[top1-2]=='E')
		{
			stac[top1-2]='E';
			top1-=2;
			val[top2-1] = val[top2]*val[top2-1];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='E' && stac[top1-1]=='/' && stac[top1-2]=='E')
		{
			stac[top1-2]='E';
			top1-=2;
			val[top2-1] = val[top2-1]/val[top2];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='E' && stac[top1-1]=='-' && stac[top1-2]=='E')
		{
			stac[top1-2]='E';
			top1-=2;
			val[top2-1] = val[top2-1]-val[top2];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='$' && stac[top1-1]=='E')
		{
			stac[top1-1]='S';
			top1-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}		
	}
	cout<<val[top2]<<endl;
}
int main()
{
	cout<<"Enter the input : ";
	cin>>input;
	cout<<"Syntax Directed Translation\n-----------------------------\n";
	sdt();
	return 0;
}
