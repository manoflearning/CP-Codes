#include <iostream>
#include <cstring>

int main(void) {
	int t;
	
	std::cin>>t;
	
	for(int i=0; i<t; i++) {
		char arr[53];
		
		std::cin>>arr;
		
		int length = strlen(arr);
		
		//문자열 중복 여부 확인
		for(int l=1; l<=length/2; l++) {
			if(length%l==0) {
				int flag=0;
	
				for(int j=0; j<l; j++) {
					for(int k=j; k<length-l; k+=l) {
						if(arr[k]!=arr[k+l]) {
							j = l;
							break;
						}
					}
					
					if(j==l-1) flag=1;
				}
				
				if(flag==1) {
					for(int j=l; j<length; j++)
						arr[j] = '\0';
					
					length = strlen(arr);
				}
			}
		}
		//문자열 계산 
		if(length%2==1) {
			strcat(arr, arr), length=strlen(arr);
			
			for(int l=0; l<length; l+=2)
				std::cout<<arr[l];
			std::cout<<std::endl;
			
			for(int l=1; l<length; l+=2)
				std::cout<<arr[l];
			std::cout<<std::endl;
		}
		else {
			for(int l=0; l<length; l+=2)
				std::cout<<arr[l];
			std::cout<<std::endl;
			
			for(int l=1; l<length; l+=2)
				std::cout<<arr[l];
			std::cout<<std::endl;
		}
	}
	
	return 0;
}