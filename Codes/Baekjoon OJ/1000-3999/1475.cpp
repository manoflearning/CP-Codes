#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
	int n;
	std::cin>>n;
	
	int count_number[10]={0};
	
	for(int i=0; pow(10, i)<=n; i++)
		count_number[ n%(int)pow(10, i+1)/(int)pow(10, i) ]++;
		
	count_number[6] += count_number[9];
	if(count_number[6]%2==1)
	{
		count_number[6]++;
		count_number[6]/=2;
	}
	else
		count_number[6]/=2;
		
	int max=1;//n==0�� ��� 
	for(int i=0; i<=8; i++)
		max = std::max(count_number[i], max);
		
	std::cout<<max;
	
	return 0;
}