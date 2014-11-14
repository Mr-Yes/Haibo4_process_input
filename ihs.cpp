/*Fisher¨CYates shuffle
/
/is an algorithm for generating a random permutation of a finite set
/
/this cpp generate N random permutation of the number set from 1 to M
/
/M Points in an N dimensional Latin hypercube are to be selected. 
/Each of the N coordinate dimensions is discretized to the values 1 through M. 
/The points are to be chosen in such a way that no two points have any coordinate value in common. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define random(x) (rand()%x)

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	int m;
	printf("Please type in the dimension N:\n");
	scanf("%d",&n);
	//system("pause");
	printf("Please type in the POINTS to be selected M:\n");
	scanf("%d",&m);
//	system("pause");
	
	int head=0;
	int end=10;
//	printf("HERE/n");
//	system("pause");
	double p[m];
	for(int i=0;i<m;i++){
		p[i]=(2*i+1)*(end-head)/(double)(2*m);
		//printf("%lf  ",p[i]);
	}
//	system("pause");
	srand((unsigned int)time(NULL)); 
	
	double point[n][m];
	for(int k=0;k<n;k++){
		
		int j;
		for(int j=m-1;j>0;j--){
				
			int x,y;
			x=random(j);
			y=j;
			double tmp=p[x];
			p[x]=p[y];
			p[y]=tmp;
		}
		for(j=0;j<m;j++){
			point[k][j]=p[j];
		}
	}
	/*
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%lf  ",point[j][i]);
		}
		printf("\n");
	}
	*/
//	system("pause");
	return 0;
}

int ihs_random(double*){
	int n;
	int m;
	printf("Please type in the dimension N:\n");
	scanf("%d",&n);
	//system("pause");
	printf("Please type in the POINTS to be selected M:\n");
	scanf("%d",&m);
//	system("pause");
	
	int head=0;
	int end=10;
//	printf("HERE/n");
//	system("pause");
	double p[m];
	for(int i=0;i<m;i++){
		p[i]=(2*i+1)*(end-head)/(double)(2*m);
		//printf("%lf  ",p[i]);
	}
//	system("pause");
	srand((unsigned int)time(NULL)); 
	
	double point[n][m];
	for(int k=0;k<n;k++){
		
		int j;
		for(int j=m-1;j>0;j--){
				
			int x,y;
			x=random(j);
			y=j;
			double tmp=p[x];
			p[x]=p[y];
			p[y]=tmp;
		}
		for(j=0;j<m;j++){
			point[k][j]=p[j];
		}
	}
	/*
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			printf("%lf  ",point[j][i]);
		}
		printf("\n");
	}
	*/
//	system("pause");
	return 0;
}

