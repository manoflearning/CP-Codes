#include <iostream>

int main(void) {
	int out, in;
	int train=0;
	int max=0;
	
	
	for(int i=0; i<4; i++) {
		std::cin>>out>>in;
		
		train+=in;
		train-=out;
		
		if(train>max) max=train;
	}
	
	std::cout<<max;
	
	return 0;
}
