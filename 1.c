#include<stdio.h>
struct file
{
	int allocation[15], max[15], need[15], flag;
};
void main()
{
	struct file f[15];
	int fl;
	int i,j,k,p;
	int b,n,r,g;
	int cnt=0,id;
	//int newr;
	int errors=0;
	int newResource[15];
	int avail[15], seq[15];
	//insert the values
	printf("Enter the number of Process : ");
	scanf("%d",&n);
	printf("Enter the number of Resources : ");
	scanf("%d",&r);
	
	for(i=0;i<n;i++)													//here 'i' indicates about the process i.e. 0=>P0, 1=>P1, 2=>P2.......
	{		
		printf("\nEnter the details of Process %d :- ",i);
		printf("\nPlease fill up the Allocation row and Max row :-\n");
		for(j=0;j<r;j++)												//here 'j' indicates about the resources i.e. 0=>A, 1=>B, 2=>C.......
			scanf("%d",&f[i].allocation[j]);							// THIS LINE MEANS THAT AT THE LOCATION j THE ARRAY ALLOCATION IS PRESENT
		printf("Enter max :-\n ");
		for(j=0;j<r;j++)
			scanf("%d",&f[i].max[j]);
		f[i].flag=0;
	}
	
		// inserting the value of the available resource
	printf("\nEnter the available resources :-\n ");
	for(i=0;i<r;i++)													//here 'i' indicates about the resources i.e. 0=>A, 1=>B, 2=>C.......
		scanf("%d",&avail[i]);
		
	//inserting the value of the new process request
	printf("Enter new request details :- ");							// here any one of the assigned process is askng fr the new resourcce
	printf("\nEnter Process number (0 or 1 or 2) \t--\t : ");
	scanf("%d",&id);
	int xyz=0;
	// resourcs requet algorithm -
	printf("\nEnter the reequest for new resources :-\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			f[i].need[j] = f[i].max[j] - f[i].allocation[j];
			if(f[i].need[i]<0)
				f[i].need[j]=0;
		}
	}
	
}

