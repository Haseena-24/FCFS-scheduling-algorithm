// programm for shortest job first algorithm
#include<stdio.h>
#include<conio.h>
main()
{
	int n;
	printf("Enter the No.of processes:");//Taking the no of process
	scanf("%d",&n);
	int at[n],at1[n],bt1[n],bt[n],ct[n],tat[n],wt[n],i,j,temp,index;
	for(i=0;i<n;i++)
	{
		printf("Enter the ArrivalTime,BurstTime of Process %d :",i+1);//Taking the arrival time and burst time of process
		scanf("%d,%d",&at[i],&bt[i]);
		at1[i]=at[i];
		bt1[i]=bt[i];
	}
	for(i=0;i<n;i++)//sorting the process with arrival time and burst time
	{
		for(j=0;j<n;j++)
		{
			if(at1[i]<at1[j])
			{
				temp=at1[i];
				at1[i]=at1[j];
				at1[j]=temp;	
				temp=bt1[i];
				bt1[i]=bt1[j];
				bt1[j]=temp;
			}
		}	
	}
	float awt=0,atat=0;
	for(i=0;i<n;i++)
	{
		if((i==0)||(at1[i]>ct[i-1])) // execution of first process
		{
			ct[i]=at1[i]+bt1[i];
			tat[i]=ct[i]-at1[i];
			wt[i]=tat[i]-bt1[i];
		}
		else
		{
		    int min=999,index=0;// execution of remaining process
	        for(j=i;j<n;j++)
		    {
			  if((at1[j]<=ct[i-1])&&(min>bt1[j]))
			  {
	            min=bt1[j];
			    index=j;
			  }
		    }
		   ct[i]=ct[i-1]+bt1[index];
	       tat[i]=ct[i]-at1[index];
	       wt[i]=tat[i]-bt1[index];
		   temp=at1[i];
	       at1[i]=at1[index];
	       at1[index]=temp;
	       temp=bt1[i];
	       bt1[i]=bt1[index];
	       bt1[index]=temp;
		}
		awt+=wt[i];
		atat+=tat[i];
	}
	printf("\nProcessID\tArrivalTime\tBurstTime\tCompleteTime\tTurnAroundTime\tWaitingTime\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		   if(at[i]==at1[j] && bt[i]==bt1[j ])
		       printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],ct[j],tat[j],wt[j]);
	   }		   
    }
	printf("\nAverage waiting Time=%.2f\n",awt/n);//average waiting time
	printf("\nAverage TurnAround Time=%.2f\n",atat/n);//AVerage turn around time
}

