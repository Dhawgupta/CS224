#include<stdio.h>
int arr[100];
int n;
int subGroup(int i,int j);
int main()
{

	printf("Enter the value of N: ");
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

    printf("\n");
    for(i=0;i<n;i++)
            printf("%d ",arr[i]);

	int med = median(0,n-1);
	printf("The median Value: %d " ,med);
	//printf("The value of last is %d",subGroup(0,n-1));
}
int subGroup(int i, int j)
{
	int left = i-1;
	int right = j;
	int last = arr[j];
	while (1)
        {
		while(arr[++left] < last);
		while(arr[--right] > last && right > 0);
		if(left >= right)
			break;
		else
		{
			int s = arr[left];
			arr[left] = arr[right];
			arr[right] = s;
		}
	}
	int s = arr[left];
	arr[left] = arr[j];
	arr[j] = s;
	return left;

}

int median(int i,int j)
{
	if(i==j)
		return arr[i];
	int inx = (n+1)/2;
	//if(n%2 ==0)
		//inx = n/2;
	//else
		//inx = (n+1)/2;

	inx--;
	int s = subGroup(i,j);
	if(s == inx)
		return arr[s];
	else
	{
		if (s > inx)
		{
			 return median(i,s-1);
		}
		else
			return median(s+1,j);
  }
}



