/*Find first and follow sets of a given grammar*/
/*To check whether the grammar is LL1 or not*/
#include<stdio.h>
 int n,m=0,p,i=0,j=0,npro,b;
 char a[10][10],f[10];
  int limit;
  void follow(char c);
void first(char c);

 //For finding first
void Find_First(char* array, char ch);
void Array_Manipulation(char array[], char value);

void Find_First(char* array, char ch)
{
      int count1, j, k;
      char temporary_result[20];
      int x;
      temporary_result[0] = '\0';
      array[0] = '\0';
      if(!(isupper(ch)))
      {
                        
            Array_Manipulation(array, ch);
            return ;
      }
      for(count1 = 0; count1 < limit; count1++)
      {
            if(a[count1][0] == ch)
            {
                  if(a[count1][3] == '^') 
                  {
                  
                        Array_Manipulation(array, '^');
                  }
                  else
                  {
                  	                  
                        j = 3;
                        while(a[count1][j] != '\0')
                        {
                              x = 0;
                              Find_First(temporary_result, a[count1][j]);
                              for(k = 0; temporary_result[k] != '\0'; k++)
                              {
                                    Array_Manipulation(array,temporary_result[k]);
                              }
                              for(k = 0; temporary_result[k] != '\0'; k++)
                              {
                                    if(temporary_result[k] == '^')
                                    {
                                          x = 1;
                                          break;
                                    }
                              }
                              if(!x)
                              {
                                    break;
                              }
                              j++;
                        }
                  }     
            }
      }
     
      return;
}
 
void Array_Manipulation(char array[], char value)
{
      int temp;
      for(temp = 0; array[temp] != '\0'; temp++)
      {
            if(array[temp] == value)
            {
                  return;
            }
      }
      array[temp] = value;
      array[temp + 1] = '\0';
}

void first(char c)
 {
  int k;
   if(!isupper(c))
    f[m++]=c;
     for(k=0;k<n;k++)
      {
       if(a[k][0]==c)
 {
   if(a[k][3]=='^')
    follow_fun(a[k][0]);
   else if(islower(a[k][3]))
    f[m++]=a[k][3];
   else first(a[k][3]);
 }
       }
     }
     
 void follow_fun(char c)
  {

   if(a[0][0]==c)
    f[m++]='$';
   for(b=0;b<npro;b++)
    {
     for(j=3;j<strlen(a[b]);j++)
      {
      //printf("\nINSIDE IF for %c",c);
       if(a[b][j]==c)
		 {
		   if(a[b][j+1]!='\0')
			 first(a[b][j+1]);
			if(a[b][j+1]=='\0' && c!=a[b][0])
			 follow_fun(a[b][0]);
		  }
       }
     }
   }
   
   
void main()
{
	char pro[10][10],first[10][10],follow[10][10],nt[10],ter[10],res[10][10][10],temp[10];
	int noter=0,nont=0,k,flag=0,count[10][10],row,col,l,index;
	  char c,ch;
	   char array[25];
	//clrscr();
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			count[i][j]=NULL;
			for(k=0;k<10;k++)
			{
				res[i][j][k]=NULL;   
			}
		}
	}
	printf("Enter the no of productions:");
	scanf("%d",&npro);
	printf("Enter the productions in the form of X->xy and individual rules separately:\n");
	for(i=0;i<npro;i++)
	{
		//scanf("%s",pro[i]);
	    scanf("%s%c",a[i],&ch);
		strcpy(pro[i],a[i]);
	}
	limit = npro;
	n = npro;
	for(i=0;i<npro;i++)
	{
		flag=0;
		for(j=0;j<nont;j++)
		{
			if(nt[j]==pro[i][0])
		
			flag=1;
		
		}
		if(flag==0)
		{
			nt[nont]=pro[i][0];
			nont++;
		}
	}		
	for(i=0;i<nont;i++)
	{
		m=0;
		Find_First(array, nt[i] );
		strcpy(first[i],array);
		
		m=0;
		  follow_fun(nt[i]);
		 strcpy(follow[i],f);
	}
	for(k=0;k<nont;k++)
	{
		printf("\nFirst Value of %c:\t{ ", nt[k]);
		        for(i = 0; first[k][i] != '\0'; i++)
		        {        
		              printf(" %c ", first[k][i]);
		        }
		        printf("}\n");
		        
		  printf("Follow of %c:\t{ ",nt[k]);
		   for(i=0;i<m;i++)
			 printf(" %c ",follow[k][i]);
			 
	}
	for(i=0;i<nont;i++)
	{
	flag=0;
	for(j=0;j<strlen(first[i]);j++)
	{
	for(k=0;k<noter;k++)
	{
	if(ter[k]==first[i][j])
	{
	flag=1;
	}
	}
	if(flag==0)
	{
	if(first[i][j]!='^')
	{
	ter[noter]=first[i][j];
	noter++;
	}
	}
	}
	}
	for(i=0;i<nont;i++)
	{
	flag=0;
	for(j=0;j<strlen(follow[i]);j++)
	{
	for(k=0;k<noter;k++)
	{
	if(ter[k]==follow[i][j])
	{
	flag=1;
	}
	}
	if(flag==0)
	{
	ter[noter]=follow[i][j];
	noter++;
	}
	}
	}
	for(i=0;i<nont;i++)
	{
	for(j=0;j<strlen(first[i]);j++)
	{
	flag=0;
	if(first[i][j]=='^')
	{
	col=i;
	for(m=0;m<strlen(follow[col]);m++)
	{
	for(l=0;l<noter;l++)
		{
		if(ter[l]==follow[col][m])
		{
		row=l;
		}
		}
		temp[0]=nt[col];
		temp[1]='-' ;
		temp[2]='>';
		temp[3]='^';
		temp[4]='\0';
		printf("\ntemp %s",temp);
		strcpy(res[col][row],temp);
		count[col][row]+=1;
		for(k=0;k<10;k++){
		temp[k]=NULL;        }
		}

	}
		else{
		for(l=0;l<noter;l++)
		{
		if(ter[l]==first[i][j])
		{
		row=l;
		}
		}
		for(k=0;k<npro;k++){
		if(nt[i]==pro[k][0])
		{
		col=i;
		if((pro[k][3]==first[i][j])&&(pro[k][0]==nt[col]))
		{
		strcpy(res[col][row],pro[k]);
		count[col][row]+=1;
		}
		else
		{
		if((isupper(pro[k][3]))&&(pro[k][0]==nt[col]))
		{
		flag=0;
		for(m=0;m<nont;m++)
		{
		if(nt[m]==pro[k][3]){index=m;flag=1;}
		}
		if(flag==1){
		for(m=0;m<strlen(first[index]);m++)
		{if(first[i][j]==first[index][m])
		{strcpy(res[col][row],pro[k]);
		    count[col][row]+=1;}
		}
		}
		}}}}}
	}}
	printf("\nLL1 Table\n\n");
	flag=0;
	for(i=0;i<noter;i++)
	{
	printf("\t%c",ter[i]);
	}
	for(j=0;j<nont;j++)
	{
	printf("\n\n%c",nt[j]);
	for(k=0;k<noter;k++)
	{
	printf("\t%s",res[j][k]);
	if(count[j][k]>1){flag=1;}
	}
	}
	if(flag==1){printf("\nThe given grammar is not LL1\n");}
	else{printf("\nThe given grammar is LL1\n");}
	//getch();


}
