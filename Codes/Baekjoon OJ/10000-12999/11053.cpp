#include <iostream>
#include <algorithm>

#define MAX 1000

int dp[MAX+1];

void most_long(int arr[], int n);

int main()
{
	//�Է� 
	int n;
	std::cin>>n;
	
	int arr[n+1];
	for(int i=1; i<=n; i++)
		std::cin>>arr[i];
	//i�� 1~n������ ������ �������� ��, arr[i]�� ���������� �ϴ� ���� �� �κм��� ���ϱ� 
	most_long(arr, n);
	//�ִ� ã�� ��� 
	int max=dp[1];
	for(int i=2; i<=n; i++)
		max = std::max(max, dp[i]);
	
	std::cout<<max;
		
	return 0;
}

void most_long(int arr[], int n)
{	
	for(int i=1; i<=n; i++)
	{
		for(int l=1; l<=i-1; l++)
			if(arr[l]<arr[i])
				dp[i] = std::max(dp[i], dp[l]);
				
		dp[i]++;
	}
}