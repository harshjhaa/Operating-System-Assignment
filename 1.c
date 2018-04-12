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
	
		for(i=0;i<r;i++)
	{
		scanf("%d",&newResource[i]);
	}
	//checking if the requested resource is available or not
	for(i=0;i<r;i++)
	{
		if(newResource[i]>f[id].need[i] || newResource[i]<0)
			errors=1;
	}
		
	if(errors==1)
		goto X;
		
	for(i=0;i<r;i++)
		{
			//scanf("%d",&newr);
			f[id].allocation[i] = f[id].allocation[i] + newResource[i];
			avail[i]=avail[i]-newResource[i];
		}
		cnt = 0;
	fl = 0;
	
	//checking for the safe sequence
	//applyig safety algorithm
	while(cnt!=n)													
		{
			g=0;
			for(j=0;j<n;j++)	// here j belogs to the number of process
			{
				if(f[j].flag == 0)
				{
					b=0;
					for(p=0;p<r;p++)		// here p belongs to the number of resources
					{
						if(avail[p]>=f[j].need[p]) 	// checking: work>=need
							b++;
						else
							b--;
					}
					if(b==r)
					{
						printf("\nP%d is visited",j);
						seq[fl++]=j;
						f[j].flag=1;
						for(k=0;k<r;k++)
						{
							avail[k] = avail[k] + f[j].allocation[k]; // work=work+allocation
						}
						cnt++;
						printf("\t\tNew Work :: ");
						for(k=0;k<r;k++)
						{
							printf("%3d",avail[k]);
							printf("  ");
						}
						g=1;
					}
				}
			}	
			if(g==0)
			{
				printf("\nRequest cannot be granted and deadlok has occured !");
				goto X;
			}
		}	
}

