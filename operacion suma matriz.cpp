#include <iostream>
#include <stdlib.h>     
#include <windows.h>
#include <time.h>

#define BILLION  1000000000.0;

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
	
	procedimiento_Suma(a,b,c,n,m);
	
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
	
}
