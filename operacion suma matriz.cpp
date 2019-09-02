#include <iostream>
#include <stdlib.h>   
#include <time.h>

using namespace std;

struct timespec start, end;

int **a, **b, **c;
int n,m;

procedimiento_Suma( int **a, int **b, int **c, int n, int m ){
	
	for(int i=0; i<n;i++){
		
		c[i]=new int[m];
		
		for(int j=0; j<m; j++){
		
			c[i][j]=(a[i][j]+b[i][j]);
			
		}
		
	}	
	
}

int main() {
	
	while(true){
	
	cout<<"Ingrese N"<<endl;
	cin>>n;
	
	cout<<"Ingrese M"<<endl;
	cin>>m;
	
	a=new int *[n];
	b=new int *[n];
	c=new int *[n];
	
	for(int i=0; i<n;i++){
		
		a[i]=new int[m];
		b[i]=new int[m];
		
		for(int j=0; j<m; j++){
		
			a[i][j]=rand()%10;
			b[i][j]=rand()%10;
			
		}
		
	}
	
 	struct timespec tstart={0,0}, tend={0,0};
 	
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    
    procedimiento_Suma(a,b,c,n,m);
    
    clock_gettime(CLOCK_MONOTONIC, &tend);
	
	
	for(int i=0; i<n;i++){
		
		for(int j=0; j<m; j++){
		
			cout<<a[i][j]<<" , ";
			
		}
		
		cout<<"              ";
		
		for(int j=0; j<m; j++){
		
			cout<<b[i][j]<<" , ";
			
		}	
		
		cout<<endl;
		
	}
	
	cout<<endl;
	
	for(int i=0; i<n;i++){
		
		for(int j=0; j<m; j++){
		
			cout<<c[i][j]<<" ,";
			
		}
		
		cout<<endl;
	}
	
	delete a;
	delete b;
	delete c;
	
	printf("El tiempo que ha tardado es: %.5f nanosegundos.\n",
          ((double)tend.tv_nsec) - 
          ((double)tstart.tv_nsec));
           
	}
	
}
