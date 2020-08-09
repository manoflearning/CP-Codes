#include <stdio.h>

int sosoo_check(int s) {
	int flag=0;
	int i;
	
	for(i=2; i<=s-1; i++) {
		if(s%i==0) {
			flag++;
			break;
		}
	}
	
	if(flag==0) return 1;
	else return 0;
}

void goldbar(int n) {
	int f1, f2;
	
	f1=n/2, f2=n/2;
	
	while(1) {
		if(sosoo_check(f1) && sosoo_check(f2)) break;
		
		f1--, f2++;
	}
	/*if(n/2%2==0) {
		f1--, f2++;
		
		while(1) {
			if(sosoo_check(f1) && sosoo_check(f2)) break;
			
			f1-=2, f2+=2;
		}
	}
	else {
		while(1) {
			if(sosoo_check(f1) && sosoo_check(f2)) break;
			
			f1-=2, f2+=2;
		}
	}*/
	
	printf("%d %d\n", f1, f2);
}

int main (void) {
	int T;
	int n;
	int i;
	
	scanf("%d", &T);
	
	for(i=0; i<T; i++) {
		scanf("%d", &n);
		
		goldbar(n);
	}
	
	return 0;
}