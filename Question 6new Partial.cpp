#include<stdio.h> 
struct Process
{
	int pno;
	int arrT;
	int burT;
};
int main() 
{
	int i,j,minimum,total_process;
	int count=0,time=3,flag=0,time_Quanta=10;;
	float total_wait_time=0,total_turnaround_time=0;
	float average_waiting_time,average_turnaround_time;
	printf("\nEnter the Total Number of Processes:\t\n");
	scanf("%d",&total_process);
	struct Process p[total_process];
	struct Process temp;
	int burst_time[total_process],wait_T[total_process],turn_T[total_process]; 
	printf("\n\nEnter Details of %d Processes\n\n\n",total_process);
	for(i=0;i<total_process;i++)
	{
		printf("Enter the process: \t");
		scanf("%d",&p[i].pno);
		printf("Enter Arrival Time:\t");
		scanf("%d",&p[i].arrT);
		printf("Enter Burst Time:  \t");
		scanf("%d",&p[i].burT);
		burst_time[i]=p[i].burT; 
		printf("\n\n");
		
	}
	int temp2;
	for(i=0;i<total_process;i++)
    {
        for(j=i;j<total_process-1;j++)
        {
            if(p[j].burT>p[j+1].burT)
            {
            	 temp=p[j+1];
                 p[j+1]=p[j];
                 p[j]=temp;
                 temp2=burst_time[j+1];
                 burst_time[j+1]=burst_time[j];
                 burst_time[j]=temp2;
            }
        }
       
    }
 }