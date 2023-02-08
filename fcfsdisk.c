// C++ program to demonstrate
// FCFS Disk Scheduling algorithm
#include <stdio.h>
#include <math.h>

int size = 8;

void FCFS(int req[],int head)
{
	int seek_count = 0;
	int cur_track, distance;
	int i;

	for( i=0;i<size;i++)
	{
		cur_track = req[i];
	
		// calculate absolute distance
		distance = fabs(head - cur_track);
	
		// increase the total count
		seek_count += distance;
	
		// accessed track is now new head
		head = cur_track;
	}

	printf("Total number of seek operations: %d\n",seek_count);
	
	// Seek sequence would be the same
	// as request array sequence
	printf("Seek Sequence is\n");

	for (i = 0; i < size; i++) {
		printf("%d\n",req[i]);
	}
}

//Driver code
int main()
{
	// request array
	int req[100],n,i;
	int head ;
	printf("Enter no of requests:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the request no %d :",i+1);
		scanf("%d",&req[i]);
	}
		printf("Enter the Header position:");
		scanf("%d",&head);
	FCFS(req,head);
	return 0;
}

