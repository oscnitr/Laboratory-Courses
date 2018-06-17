#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
struct production
{
            char lf;
            char rt[10];
            int prod_rear;
            int fl;
};
struct production rule[20],rule_new[20];     //Creation of object

int b=-1,d,f,q,n,m=0,c=0,count_1=0;
char terminal[20],nonterm[20],alpha[10],extra[10],temp2[20];
char epsilon='^';


int main()  {
    char input[10][100],*l[10],*r[10],*temp[10],tempprod[10][20],productions[10][25][50];
    int k,n,i[10];
    int j=0,flag[10];
    char *spcl = "X";
    l[0] = spcl;
    printf("\nEnter no. of productions : ");
    scanf("%d",&n);
    printf("Enter the productions (in the form X->Xy|Xx|x) : \n");
    for(k=0;k<n;k++)
    {
	    scanf("%s",input[k]);
	    l[k] = strtok(input[k],"->");
	    r[k] = strtok(NULL,"->");
	    temp[k] = strtok(r[k],"|");
	    while(temp[k])  {
	        if(temp[k][0] == l[k][0])  {
	            flag[k] = 1;
	            sprintf(productions[k][i[k]++],"%s->%s%s\0",spcl,temp[k]+1,spcl);
	        }
	        else
	            sprintf(productions[k][i[k]++],"%s->%s%s\0",l[k],temp[k],spcl);
	        temp[k] = strtok(NULL,"|");
	    }
	
	    sprintf(productions[k][i[k]++],"%s->^",spcl);
    }
    
    for(k=0;k<n;k++)
    {
	    if(flag[k] == 0)
    	{
    		printf("\nThe given productions don't have Left Recursion");
    		count_1 = i[k];
    	}    
	    else
	    {
		    printf("For removal of left recursion, special character used is : %s",spcl);
		    printf("\nAfter removing left recursion, productions are : \n");
			for(j=0;j<i[k];j++)  {
				
			    printf("\n%s",productions[k][j]);
			    count_1 = i[k];
			}
		}
		printf("\n");
    }
    printf("\n");

	//Remove left factoring

	cout<<"\nFor removal of left factoring, special character used is : Y";
	q = 1;
	alpha[0] = 'Y';
	int cnt,g,cnt3;
	n = count_1;
	for(cnt=0;cnt<n;cnt++)
	{
		//cout<<"\nProduction no. "<<cnt+1<<"  "<<productions[0][cnt];
		strcpy(temp2,productions[0][cnt]);
		rule[cnt].lf = temp2[0];
	     int index = 0;
		 for(int posn = 3;posn<strlen(temp2);posn++)
		 {
		 	rule[cnt].rt[index++] = temp2[posn];
		 }
	 
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

    cout<<"\n\nProduction rules after removing left factoring : \n";
    
    for(cnt3=0;cnt3<=b;cnt3++)
            {
                        //cout<<"Production "<<cnt3+1<<" is: ";
                        cout<<rule_new[cnt3].lf;
                        cout<<"->";
                        cout<<rule_new[cnt3].rt;
                        cout<<endl;
            }

    for(int cnt4=0;cnt4<n;cnt4++)
    {
    if(rule[cnt4].fl==0)
    {
    //cout<<"Production "<<++cnt3<<" is: ";
    cout<<rule[cnt4].lf<<"->"<<rule[cnt4].rt<<endl;
    
    }
  }
	

}
