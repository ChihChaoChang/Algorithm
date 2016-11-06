//姓名: 張智超 
//學號:1023003S 

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
	time_t start_time, end_time;
	float total_time = 0;  //count time
	start_time = clock();
	maxSum(data,size);
	end_time = clock();
	total_time = (float)(end_time - start_time)/CLOCKS_PER_SEC; 
	printf("\nmaxSum = [%d]\n", maxSum(data,size));
	printf("Time : %f sec \n", total_time);
			
	float total_time2 = 0; //count time
	start_time = clock();
	maxSubSum(0,size-1);
	end_time = clock();
	total_time2 = (float)(end_time - start_time)/CLOCKS_PER_SEC; 
	
	printf("\nmaxSum : [%d]\n", maxSubSum(0,size-1));
	printf("Time : %f sec \n", total_time2);
	return 0;
}

int maxSum(int data[], int size)
{
	int i,j,k;
	int sum=0;
	int maxSum =data[0];
	int currentsum=0;
	for(i=0; i < size; i++)
		{
		for(j=i; j < size; j++)
		{		
			for(k=i ; k < j+1; k++)
			{
			currentsum = currentsum + data[k];
			}
			if ( currentsum> maxSum)
			  maxSum=currentsum;
			currentsum = 0;
		}		
		}
		return maxSum;
}

int maxSubSum(int left, int right)
{		
	int mid, sum, maxonLeft, maxonRight, maxCrossing, maxofA, maxofB;
	int i;
	if(left > right)
		{
		return 0;
		}
	if(left==right)
		{
		if (data[left]>0)
			return data[left];
		else
		    return 0;	
		}
	mid = (left + right)/2;
	sum=0;
	maxonLeft=0;
	for(i=mid; i >= left; i--)
	{
		sum = sum + data[i];
		if (sum> maxonLeft )
		maxonLeft = sum;
	}
	sum=0;
	maxonRight=0;
	for(i=mid+1; i <= right; i++)
	{
		sum = sum + data[i];
		if (sum>maxonRight)
		maxonRight = sum;	
	}	
	maxCrossing = maxonLeft + maxonRight;
	maxofA = maxSubSum(left,mid);
	maxofB = maxSubSum(mid+1,right);
	return Maxpick(maxofA,maxofB ,maxCrossing);  
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

int Maxpick(int a,int b,int c)  
{  
    int Max = a;  
    if(b > Max)  
        Max = b;  
    if(c > Max)  
        Max = c;  
    return Max;  
}





