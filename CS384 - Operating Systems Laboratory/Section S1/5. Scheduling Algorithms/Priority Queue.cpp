#include<bits/stdc++.h> 
using namespace std; 
int main(){  
	int arrival[4]={0,0,2,2};  
	int burst[4]={20,16,8,4};  
	int burst1[4]={20,16,8,4};  
	int priority[4]={4,3,2,1};  
	int current_waiting_time[4]={0};  
	int waiting[10];    
	int current_executing_process=0;  
	int last_process=0; 
 	int n=4;  
	int ts=5;  
	int highest_priority=priority[0];  
	int to_run_process=0;  
	int count=0;  
	cout<<"0";    
	int tt=0; 
	for(int i=0;i<n;i++)   
		tt+=burst[i]; 
 	while(count<tt){   
		int d=current_executing_process; 
  	if(ts>0 && burst[d]<1000){       
		for(int j=0;j<n;j++){     
			if(priority[j]>highest_priority && count>=arrival[j] && burst[j]<1000){      
				highest_priority=priority[j];      
				current_executing_process=j;        
			}    
		}      
	}else{    
		priority[current_executing_process]--;    
		highest_priority=INT_MIN;    
		for(int j=0;j<n;j++){     
			if(priority[j]>highest_priority && j!=current_executing_process && count>=arrival[j] && burst[j]<1000){      
				highest_priority=priority[j];      
				current_executing_process=j;      
			}    
		}     
	} 
  	if(last_process!=current_executing_process){    
		cout<<" P"<<last_process<<" "<<count;   
		ts=5;       
		last_process=current_executing_process;   
	}    
  	count++;   
	burst[current_executing_process]--;   
	ts--; 
  	for(int k=0;k<n;k++){    
		if(k!=current_executing_process && count>arrival[k]){     
			current_waiting_time[k]++;     
			priority[k]=priority[k]+(current_waiting_time[k]/3);     
			current_waiting_time[k]=current_waiting_time[k]%3;    
		}   
	} 
	if(burst[current_executing_process]==0){ 
   //cout<<" P"<<current_executing_process<<" "<<count;    
		waiting[current_executing_process]=count-arrival[current_executing_process]-burst1[current_executing_process];    
		burst[current_executing_process]=INT_MAX;    
		ts=5;      
		last_process=current_executing_process;   
	} 
 
  /*if(count>25 && count<30){    cout<<endl<<"current "<<count<<" "<<current_executing_process<<endl;;       cout<<endl;    for(int k=0;k<n;k++){     cout<<count<<" "<<current_waiting_time[k]<<" "<<priority[k]<<" "<<burst[k]<<" "<<endl;;    }   }*/ 
 
 	}  cout<<" P"<<last_process<<" "<<count; 
 
 	int tw=0;   	
	for(int i=0;i<n;i++){   
		cout<<i<<" "<<waiting[i]<<endl;   
		tw+=waiting[i];   
	}  
	cout<<(double)tw/(double)n; 
 
} 
