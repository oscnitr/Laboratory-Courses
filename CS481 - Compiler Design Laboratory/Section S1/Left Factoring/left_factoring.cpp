#include<iostream>
#include<stdio.h>
//#include<conio.h>
#include<string.h>
using namespace std;	
//Structure Declaration

struct production
{
            char lf;
            char rt[10];
            int prod_rear;
            int fl;
};
struct production rule[20],rule_new[20];     //Creation of object

//Variables Declaration

int b=-1,d,f,q,n,m=0,c=0;
char terminal[20],nonterm[20],alpha[10],extra[10],temp[20];
char epsilon='^';

//Beginning of Main Program

int main()
{

   cout<<"\nEnter the number of Special characters(except non-terminals): ";
   cin>>q;
   cout<<"Enter the special characters for your production: ";
   int cnt,g,cnt3;
   for(cnt=0;cnt<q;cnt++)
   {
     cin>>alpha[cnt];
   }


   cout<<"\nEnter the number of productions: ";
   cin>>n;
   for(cnt=0;cnt<n;cnt++)
   {
     cout<<"Enter the "<< cnt+1<<" production: ";
     
     cin>>temp;
     rule[cnt].lf = temp[0];
     int index = 0;
	 for(int pos = 3;pos<strlen(temp);pos++)
	 {
	 	rule[cnt].rt[index++] = temp[pos];
	 }
     
     //cin>>rule[cnt].lf;
     //cout<<"->";
     //cin>>rule[cnt].rt;
     rule[cnt].prod_rear=strlen(rule[cnt].rt);
     rule[cnt].fl=0;
   }

   //Condition for left factoring

   for(int cnt1=0;cnt1<n;cnt1++)
   {
     for(int cnt2=cnt1+1;cnt2<n;cnt2++)
     {
            if(rule[cnt1].lf==rule[cnt2].lf)
            {
              cnt=0;
              int p=-1;
              while((rule[cnt1].rt[cnt]!='\0')&&(rule[cnt2].rt[cnt]!='\0'))
              {
                if(rule[cnt1].rt[cnt]==rule[cnt2].rt[cnt])
                {
                  extra[++p]=rule[cnt1].rt[cnt];
                  rule[cnt1].fl=1;
                  rule[cnt2].fl=1;
                }
                else
                {
                  if(p==-1)
                          break;
                  else
                  {
                          int h=0,u=0;
                          rule_new[++b].lf=rule[cnt1].lf;
                          strcpy(rule_new[b].rt,extra);
                          rule_new[b].rt[p+1]=alpha[c];
                          rule_new[++b].lf=alpha[c];
                          for(g=cnt;g<rule[cnt2].prod_rear;g++)
                           rule_new[b].rt[h++]=rule[cnt2].rt[g];
                           rule_new[++b].lf=alpha[c];
                          for(g=cnt;g<=rule[cnt1].prod_rear;g++)
                           rule_new[b].rt[u++]=rule[cnt1].rt[g];
                           m=1;
                           break;
                   }
                 }
                 cnt++;
               }
               if((rule[cnt1].rt[cnt]==0)&&(m==0))
               {
                         int h=0;
                         rule_new[++b].lf=rule[cnt1].lf;
                         strcpy(rule_new[b].rt,extra);
                         rule_new[b].rt[p+1]=alpha[c];
                         rule_new[++b].lf=alpha[c];
                         rule_new[b].rt[0]=epsilon;
                         rule_new[++b].lf=alpha[c];
                         for(int g=cnt;g<rule[cnt2].prod_rear;g++)
                         rule_new[b].rt[h++]=rule[cnt2].rt[g];
               }
               if((rule[cnt2].rt[cnt]==0)&&(m==0))
               {
                 int h=0;
                 rule_new[++b].lf=rule[cnt1].lf;
                 strcpy(rule_new[b].rt,extra);
                 rule_new[b].rt[p+1]=alpha[c];
                 rule_new[++b].lf=alpha[c];
                 rule_new[b].rt[0]=epsilon;
                 rule_new[++b].lf=alpha[c];
                 for(int g=cnt;g<rule[cnt1].prod_rear;g++)
                  rule_new[b].rt[h++]=rule[cnt1].rt[g];
               }
               c++;
               m=0;
             }
       }
    }

   //Display of Output

    cout<<"\nProduction rules after removing left factoring : \n";
    
    for(cnt3=0;cnt3<=b;cnt3++)
            {
                        cout<<"Production "<<cnt3+1<<" is: ";
                        cout<<rule_new[cnt3].lf;
                        cout<<"->";
                        cout<<rule_new[cnt3].rt;
                        cout<<endl;
            }

    for(int cnt4=0;cnt4<n;cnt4++)
    {
    if(rule[cnt4].fl==0)
    {
    cout<<"Production "<<++cnt3<<" is: ";
    cout<<rule[cnt4].lf;
    cout<<"->";
    cout<<rule[cnt4].rt;
    cout<<endl<<endl;
    }
  }
 //getche();
}    //end of main program
