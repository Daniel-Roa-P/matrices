#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

struct timespec start, end;

int **a, **b, **c;
int n,m;

procedimiento_Multiplicacion( int **a, int **b, int **c, int n, int m ){
	
	for(int i=0; i<n;i++){
		
		c[i]=new int[n];
		
		for(int j=0; j<n; j++){
		
			c[i][j]=0;
			
			for(int k=0; k<m; k++){
				
				c[i][j]=c[i][j]+(a[i][k]*b[k][j]);
				
			}
			
		}
		
	}	
	
}

int main() {
	
	cout<<"Ingrese N"<<endl;
	cin>>n;
	
	cout<<"Ingrese M"<<endl;
	cin>>m;

	a=new int *[n];
	b=new int *[m];
	c=new int *[n];
	
	cout<<endl;
	
	for(int i=0; i<n;i++){
		
		a[i]=new int[m];
		
		for(int j=0; j<m; j++){
		
			a[i][j]=(i*m)+j;
			
		}
		
	}
	
	for(int i=0; i<m;i++){
		
		b[i]=new int[n];
		
		for(int j=0; j<n; j++){
		
			b[i][j]=(m*n)-((i*n)+j);
			
		}
		
	}
	
	struct timespec tstart={0,0}, tend={0,0};
 	
    clock_gettime(CLOCK_MONOTONIC, &tstart);
	
	procedimiento_Multiplicacion(a,b,c,n,m);

	clock_gettime(CLOCK_MONOTONIC, &tend);

	for(int i=0; i<n;i++){
		
		for(int j=0; j<m; j++){
		
			cout<<a[i][j]<<" , ";
			
		}
		
		cout<<endl;
		
	}
	
	cout<<endl;
	
	for(int i=0; i<m;i++){
		
		for(int j=0; j<n; j++){
		
			cout<<b[i][j]<<" , ";
			
		}
		
		cout<<endl;
		
	}
	
	cout<<endl;
	
	for(int i=0; i<n;i++){
		
		for(int j=0; j<n; j++){
		
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
