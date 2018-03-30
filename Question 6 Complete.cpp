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
    printf("--------------------------------------------------------------------------------");
    printf("\n\nPROCESS NO\t\tArrival-Time\t\t\tBurst-Time\t\n");
    for(i=0;i<=total_process-1;i++)
    {
    printf("%d                \t\t%d       \t\t%d   \n\n",p[i].pno,p[i].arrT,p[i].burT);
    }
    minimum=p[0].arrT;
    for(i=1;i<total_process;i++)
    {
    	if(p[i].arrT<minimum)
    		minimum=p[i].arrT;
	}
	if(minimum>3)
	{
		time=minimum;
	}
	printf("\n\n------------------------------------------------------------------------------------------\n\n");
	printf("Process\t|TurnAround-time|Waiting-time\t\n");
	for(i=0;count!=total_process;i++)
	{
		if(p[i].arrT<=time && p[i].burT<=time_Quanta && p[i].burT>0)
		{
		  time+=p[i].burT;
		  p[i].burT=0;
		  flag=1;
		}
		else if(p[i].arrT<=time && p[i].burT>0)
		{
			p[i].burT-=time_Quanta;
			time+=time_Quanta;
		}
		if(p[i].burT==0 && flag==1)
		{
				count++;
				turn_T[i]=time-p[i].arrT;
				wait_T[i]=time-p[i].arrT-burst_time[i];
				printf("P[%d]\t|\t%d\t|\t%d\n",p[i].pno,turn_T[i],wait_T[i]);
				flag=0;
		}
		if((i+1)==total_process)
			i=-1;
	}
	printf("\n---------------------------------------------------------------------------------------------\n");
	for(i=0;i<total_process;i++)
	{
		total_wait_time+=wait_T[i];
		total_turnaround_time+=turn_T[i];
	}
	printf("\nAverage Waiting Time= %f\n",total_wait_time*1.0/total_process); 
	printf("\n\n");
    printf("Avg Turnaround Time = %f",total_turnaround_time*1.0/total_process);  
    printf("\n");
}
