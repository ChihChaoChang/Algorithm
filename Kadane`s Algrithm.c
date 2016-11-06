
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void inputarr (int*,int);
void showdata (int*,int);
int MaxSubArray(int*, int);
int Maxpick(int,int,int);  
int maxSum(int*, int);
int size,data[10000]={0};

int main()

{
	srand((unsigned)time(NULL));
	printf("Please Enter the amount of Maximum Subarray problem (under 10,000):");
	scanf("%d",&size);
	printf("Random data:\n");
	printf("\n");
	inputarr (data,size);
	showdata(data,size);
	
	int sum=0;
	int max=data[0];
	int i;
	time_t start_time, end_time;
	float total_time = 0;  //count time
	start_time = clock();
	
	for( i=0; i<size;i++)
	{
		sum=sum+data[i];
		if (sum>= max)
		max=sum;
		 if (sum<0)
	 	{
		sum=0;
		max=0;
		}

	}
		end_time = clock();
	total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC; 
	
		printf("\nmaxSum = [%d]\n", max);
	printf("Time : %f sec \n", total_time);

	return 0;
	
}
void inputarr(int data[], int size)
{
      int i;
      for(i=0;i<size;i++)
        data[i]=(rand()%100-50)+1;
}
void showdata (int data[],int size)  
{
      int i;      
        for(i=0; i<size; i++)       
        { 
        if(i==size-1)
            {
             printf("%d",data[i]);  
             printf("\n");
            }
          else
            {
            printf("%d,",data[i]);        
            }
        } 
         printf("\n");   
}



