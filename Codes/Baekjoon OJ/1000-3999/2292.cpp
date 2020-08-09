#include <stdio.h>

int i, l, j;

int beehouse_count(int N) {
	int bh[20000]; //beehouse
	
	if(N==1) return 1;
	
	else {
		N--;
		for(i=1; i<20000; i++) {
			bh[i]=i*6;
		
			if(N<=bh[i]) break;
			
			N-=bh[i];
		}
		return i+1;
	}
}

int main (void) {
	int N;
	
	scanf("%d", &N);
	
	printf("%d", beehouse_count(N));
	
	return 0;
}
