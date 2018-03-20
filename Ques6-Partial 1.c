#include<unistd.h>
#include<stdio.h>
int main()
{
  printf("Cpu will stay idle for 3 sec.\n");
  printf("Each process one by one.\n");
  printf("Enter number of process you want to allocate to cpu\n\n");
  int n;
  scanf("%d",&n);
  int process[n+1];
  int arrT[n+1];
  int burT[n+1];
  int remT[n+1];
  float waitT[n+1];
  float turnT[n+1];
  //int swapit[n+1];
  int i;
  int end;
  for(i=0;i<n;i++)
 {
   process[i]=i;
   printf("\nEnter the arrival time of process %d --->",process[i]+1);
   scanf("%d",&arrT[i]);
   printf("Enter the burst time of process %d --->",process[i]+1);
   scanf("%d",&burT[i]);
   remT[i]=burT[i];
 }
 int count=0;
 int time,min;
   int max=burT[0];
   burT[n]=1000;
  for(time=0;count!=n;time++)
  {
    min=n;
    for(i=0;i<n;i++)
    {
      if((arrT[i]<=time && burT[i]<burT[min] && burT[i]>0))
      {
        min=i;
      }
    }
    burT[min]=burT[min]-1;
    if(burT[min]==0)
    {
      count=count+1;
      end=time+1;
      waitT[min]=end-arrT[min]-remT[min];
      turnT[min]=end-arrT[min];
      //printf("  %d     %f     %f  \n",process[min]+1,waitT[min],turnT[min]);
    }
}
float sum_wait=0.0,sum_turn=0.0;
for(i=0;i<n;i++)
{
	sum_wait=sum_wait+waitT[i];
	sum_turn=sum_turn+turnT[i];
}
float avg_wt=sum_wait/n;
float avg_tt=sum_turn/n;
printf("\n\n Average Waiting Time: %f\n",avg_wt);
printf("Average Turnaround Time:%f\n\n",avg_tt);
return 0;
}
