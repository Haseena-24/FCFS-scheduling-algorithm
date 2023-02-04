#include<stdio.h>
int main()
{
	int at[10],bt[10],ct[10],tat[10],wt[10],i,temp,n,p,q,pos;
	float avg_tat=0,avg_wt=0;
	//Taking Input from User:
	printf("Enter no.of process:");
	scanf("%d",&n);
	printf("\nEnter Arrival Time of processes:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&at[i]);
	}
	printf("\nEnter Burst Time of processes:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	for(p=0;p<n;p++)
	{
		for(q=p+1;q<n;q++)
		{
			if(at[p]>at[q])
			{
				temp=at[p];
				at[p]=at[q];
				at[q]=temp;
				
				pos=bt[p];
				bt[p]=bt[q];
				bt[q]=pos;
			}
		}
	}
	//Calculating Completion Time:
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			ct[0]=at[0]+bt[0];//Calcutating first CT
		}
		else
		{
			//calculating remaining CT
			if(at[i]>=ct[i-1])
			{
				temp=at[i]-ct[i-1];
				ct[i]=ct[i-1]+bt[i]+temp;
			}
			else
			{
				ct[i]=ct[i-1]+bt[i];
			}
		}
	}
	//Calculating TAT and WT:
	for(i=0;i<n;i++)
	{
		tat[i]=ct[i]-at[i];
		wt[i]=tat[i]-bt[i];
		avg_tat+=tat[i];
		avg_wt+=wt[i];
	}
	avg_tat=avg_tat/n;
	avg_wt=avg_wt/n;
	//Printing Output
	printf("\nAT\tBT\tCT\tTAT\tWT");
	printf("\n...............................................");
	for(i=0;i<n;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d",at[i],bt[i],ct[i],tat[i],wt[i]);
	}
	//printing Avg.TAT and Avg.WT:
	printf("\nAverage Total Around Time= %f",avg_tat);
	printf("\nAverage Waiting Time= %f",avg_wt);
	
	
}
