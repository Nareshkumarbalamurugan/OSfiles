#include<stdio.h>

void findWaitingTime(int processes[],int n,int burst_time[],int wt[]){
	wt[0]=0;
	for(int i=1;i<n;i++){
		wt[i]=wt[i-1]+burst_time[i-1];
	}

}

void findTurnAroundTime(int processes[],int n,int burst_time[],int wt[],int tat[]){
	for(int i=0;i<n;i++){
		tat[i]=burst_time[i]+wt[i];
}

}

void findAvgTime(int processes[],int n,int burst_time[]){
	int wt[n],tat[n],total_wt=0,total_tat=0;

	findWaitingTime(processes,n,burst_time,wt);
	findTurnAroundTime(processes,n,burst_time,wt,tat);


	printf("Processes   Burst time   Waiting time   Turn around time\n"); 
	for(int i=0;i<n;i++){
		total_wt = total_wt + wt[i]; 
        	total_tat = total_tat + tat[i]; 
       		 printf("   %d ",(i+1));
       		 printf("       %d ", burst_time[i] );
       		 printf("       %d",wt[i] );
       		 printf("       %d\n",tat[i] ); 
		}
	float s=(float)total_wt/(float)n;
	float t=(float)total_tat/(float)n;
	printf("Average waiting time:%f\f",s);
	printf("Average turn around time:%f",t);
}

void main(){
	int processes[]={1,2,3};
	int n=sizeof(processes)/sizeof(processes[0]);
	int burst_time[]={10,5,8};
	findAvgTime(processes,n,burst_time);
}
