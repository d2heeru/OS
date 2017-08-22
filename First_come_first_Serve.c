#include <stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubbleSort(int arr[],int a[],int ar[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)        
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
              swap(&a[j],&a[j+1]);
              swap(&ar[j],&ar[j+1]);
              
}
int main()
{
	FILE *fp;
	fp=freopen("input.txt","r",stdin);
    int process_id[50],arrival_t[50],burst_t[50],com_t[50],TAT[20],WT[20];
    int n ;
    printf("Enter Number of process\n");
    scanf("%d",&n);
    printf("Enter Process _Id:\n");
    for(int i=0;i<n;i++)
    {
		scanf("%d",&process_id[i]);
	}
	 printf("Enter Arriaval_Time:\n");
	 for(int i=0;i<n;i++)
    {
		scanf("%d",&arrival_t[i]);
	}
	 printf("Enter Brust Time:\n");
	 for(int i=0;i<n;i++)
    {
		scanf("%d",&burst_t[i]);
	}
    bubbleSort(arrival_t,process_id,burst_t, n);
    com_t[0]=burst_t[0];
    for(int j=1;j<n;j++)
    {
		com_t[j]=com_t[j-1]+burst_t[j];
	}
	for(int k=0;k<n;k++)
	{
		TAT[k]=com_t[k]-arrival_t[k];
	}
	for(int k=0;k<n;k++)
	{
		WT[k]=TAT[k]-burst_t[k];
	}
     printf("\nP_ID\tArr_t\tBT\tCom_Time   TAT\t Waiting Time\n");
   for(int i=0;i<n;i++) 
		{
			printf("p%d\t ",process_id[i]);
			printf("%d\t",arrival_t[i]);
			printf("%d\t  ",burst_t[i]);
			printf("%d\t    ",com_t[i]);
			printf("%d\t\t",TAT[i]);
			printf("%d\n",WT[i]);
		}
    return 0;
}
