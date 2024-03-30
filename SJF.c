#include<stdio.h>
#include<conio.h>
main()
{
	int p[20],bt[20],wt[20],tat[20],i,k,n,temp;
	float wtavg,tatavg;
	printf("\n enter the number of processes--");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		p[i]=i;
		printf("enter burst time for process %d--",i);
		scanf("%d",&bt[i]);
	}
	for(i=0;i<n;i++)
	for(k=i+1;k<n;k++)
	if(bt[i]>bt[k])
	{
		temp=bt[i];
		bt[i]=bt[k];
		bt[k]=temp;
		temp=p[i];
		p[i]=p[k];
		p[k]=temp;
	}
	wt[0]=wtavg=0;
	tat[0]=tatavg=bt[0];
	for(i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=tat[i-1]+bt[i];
		wtavg=wtavg+wt[i];
		tatavg=tatavg+tat[i];
	}
	printf("\t process\t burst time\t waiting time\t turn around time\n");
	for(i=0;i<n;i++)
	printf("\n\tp%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
	printf("\n average waiting time---%f",wtavg/n);
	printf("\n average turn around time---%f",tatavg/n);
	getch();
}
