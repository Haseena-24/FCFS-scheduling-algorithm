#include<stdio.h>
#include<conio.h>
main()
{
	int n;
	printf("Enter the No.of processes:");
	scanf("%d",&n);
	int i,j,temp,at[n],at1[n],bt1[n],bt[n],ct[n],wt[n],tat[n];
	float awt=0,atat=0;
	for(i=0;i<n;i++)
	{
		printf("Enter the ArrivalTime,BurstTime of Process %d :",i+1);
		scanf("%d,%d",&at[i],&bt[i]);
		at1[i]=at[i];
		bt1[i]=bt[i];
	}
	printf("\nProcessID\tArrivalTime\tBurstTime\n");
	for(i=0;i<n;i++)
	{
		printf("P%d\t\t%d\t\t%d\n",i+1,at[i],bt[i]);
	}
	for(i=0;i<n;i++)
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

	for(i=0;i<n;i++)
	{
		if(i==0 || at1[i]>ct[i-1])
			ct[i]=at1[i]+bt1[i];
		else
			ct[i]=ct[i-1]+bt1[i];
		tat[i]=ct[i]-at1[i];
		wt[i]=tat[i]-bt1[i];
		awt+=wt[i];
		atat+=tat[i];	
	}
	printf("\nProcessID\tArrivalTime\tBurstTime\tCompleteTime\tTurnAroudTime\tWaitingTime\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		   if(at[i]==at1[j] && bt[i]==bt1[j ])
		       printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],ct[j],tat[j],wt[j]);
	   }		   
	}
	awt=awt/n;
	atat=atat/n;
	printf("\nAverage waiting Time=%.2f\n",awt);
	printf("\nAverage TurnAround Time=%.2f\n",atat);
}

