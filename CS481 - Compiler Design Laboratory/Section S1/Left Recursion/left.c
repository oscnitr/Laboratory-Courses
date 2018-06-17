
#include<stdio.h>
#include<string.h>
void main()  {
    char input[10][100],*l[10],*r[10],*temp[10],tempprod[10][20],productions[10][25][50];
    int k,n,i[10];
    int j=0,flag[10];
    printf("\nEnter no. of productions : ");
    scanf("%d",&n);
    printf("Enter the productions: \n");
    for(k=0;k<n;k++)
    {
    
    
    
    scanf("%s",input[k]);
    l[k] = strtok(input[k],"->");
    r[k] = strtok(NULL,"->");
    temp[k] = strtok(r[k],"|");
    while(temp[k])  {
        if(temp[k][0] == l[k][0])  {
            flag[k] = 1;
            sprintf(productions[k][i[k]++],"%s'->%s%s'\0",l[k],temp[k]+1,l[k]);
        }
        else
            sprintf(productions[k][i[k]++],"%s->%s%s'\0",l[k],temp[k],l[k]);
        temp[k] = strtok(NULL,"|");
    }
    sprintf(productions[k][i[k]++],"%s->\u03B5",l[k]);
    }
    for(k=0;k<n;k++)
    {
	    if(flag[k] == 0)
    		    printf("\nThe given productions don't have Left Recursion");
	    else
		for(j=0;j<i[k];j++)  {
		    printf("\n%s",productions[k][j]);
		}
	printf("\n");
    }
    printf("\n");
}
