#include<stdio.h>
struct process
{
    int pro_name;
    int arrT,burT,waiturnT,turnT,priority,burTcopy;
}queue1[10],queue2[10];
void main()
{
	struct process temp;
    int i,time=0,t1,t2,bu_t=0,largest,totalProcess,count=0,k,pf2=0,totalProcess2,n,pos,j,flag=0,y;
    float wait_time=0,turnaround_time= 0,average_waiting_time,average_turnaround_time;
    printf("\nEnter Total Number of Processes:\t");
    scanf("%d",&totalProcess);
    n=totalProcess;
    for(i=0;i<totalProcess;i++)
    {
    	printf("\nEnter Process name:-");
    	//fflush(stdin);
        scanf("%d",&queue1[i].pro_name);
        printf("\nEnter Details For processor %d:\n",queue1[i].pro_name);
        printf("Enter Arrival Time:-");
        scanf("%d",&queue1[i].arrT);
        printf("Enter Burst Time:-");
        scanf("%d",&queue1[i].burT);
        queue1[i].burTcopy=queue1[i].burT;
        printf("Enter Priority:\t");
        scanf("%d",&queue1[i].priority);
    }
    printf("\nEnter Time Quantum for Fixed priority queue:-");
    scanf("%d",&t1);
    printf("\nEnter Time Quantum for Round Robin queue:-");
    scanf("%d",&t2);
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
    for(i=0;i<totalProcess;i++)
    {
        pos=i;
        for(j=i+1;j<totalProcess;j++)
        {
            if(queue1[j].arrT<queue1[pos].arrT)
                pos=j;
        }
        temp=queue1[i];
        queue1[i]=queue1[pos];
        queue1[pos]=temp;
    }
}