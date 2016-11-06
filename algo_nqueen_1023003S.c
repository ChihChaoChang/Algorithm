#include <stdio.h>  
#include <stdlib.h>  
  
const int N=100;   //maximum number of the queen
int q[100];         //record each queen on the line
int cont = 0;     //count overall the solution

void print(int n); 
int find(int i,int k);
void place(int k,int n); 

int main(void)  
{  
    int n;  
    printf("Please enter the queen's size(n<=100),n=:");  
    scanf("%d",&n);  
    if(n>100)  
        printf("n is too big to cross the line!\n");  
    else  
    {  
        printf("%d's queens solution is as follows:\n",n);  
        place(1,n);        //solve the problem form the begining
        printf("There is total %d's solution.",cont);
        printf("\n");  
    }  
    return 0;  
}  

//output the solution 
void print(int n)  
{  
    int i,j;  
    cont++;  
  /*  printf("No.%d's solution'：",cont);  
	 for(i=1;i<=n;i++)  
      {
 		printf("(%d,%d) ",i,q[i]); 
		}
    printf("\n");  
    for(i=1;i<=n;i++)        //column
    {                  
        for(j=1;j<=n;j++)    //row  
        {  
            if(q[i]!=j)  
                printf("x ");  
            else   
                printf("Q ");   
        }  
        printf("\n");  
    } 
      //因題目未要求列印出每一個解,故用反斜線隱藏起來 
  
    */
}  


//check i column k row wether can put the queen
int find(int i,int k)    
{  
    int j=1;  
    while(j<i)  //j=1~i-1是already put queen row 
    {  
        //when j row's queen is it on the k orw or 在(j,q[j])and(i,k)and the diagonal? 
        if(q[j]==k || abs(j-i)==abs(q[j]-k))   
            return 0;  
        j++;  
    }  
    return 1;  
}  

//put queen on the chessboard
void place(int k,int n)    
{  
    int j;  
    if(k>n)  
        print(n);  
    else  
    {  
        for(j=1;j<=n;j++)   //?try on evey k column's every row  
        {  
            if(find(k,j))  
            {  
                q[k] = j;  
                place(k+1,n);  //if it is successive then do th next job
            }  
        }  
    }  
}  
  
