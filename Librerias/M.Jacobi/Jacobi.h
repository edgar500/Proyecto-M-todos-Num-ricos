

#include<iostream>
#include<math.h>
#define v 10
using namespace std;

class Jacobi{
	
	private:
		int in, j, l, cont=0, s=1;
	    float x[v], a[v][v], b[v], dd, suma;
		
	public:
	    Jacobi();
		void metodoJacobi(int l, float x[], float a[][10], float b[]);
        void getMatrix(float a[][10], int l);	
		void getJacobi();
		
};

Jacobi::Jacobi(){
	
	cout<<"\n\n\t ====== Metodo de Jacobi ====== \n\n";
    cout<<"-> Introduce el numero de ecuaciones: ";
	cin>>l;
	
	while(l<0 || l > v){
		
		cout<<"\n\n\t ====== El orden de la matriz no pude ser mayor que "<<v<<" ====== \n\n";
		cout<<"-> Ingresa nuvamente el orden de la matriz: ";
		cin>>l;
	}
	
	cout<<"\n\n -> Introduce la matriz con los coeficientes: "<<endl;
	
	for(int i=0; i<l; i++){
		
		x[i]=0;
		
		for(int j=0; j<l; j++){
			
			cout<<"\n a["<<i<<", "<<j<<"]: ";
			cin>>a[i][j];
		}
	}
	
	cout<<"\n\n -> Introduce el vector de los resultados: "<<endl;
	cout<<"\n ";
	
	for(int i=0; i<l; i++){
		
		cout<<"b[ "<<i<<", 0]: ";
		cin>>b[i];
	}
	
	for(int i=0; i<l; i++){
		
		suma=0;
		
		for(int j=0; j<l; j++){
			
			if(i==j){
				
			dd=a[i][j];
			}
			
			else{
				suma += a[i][j];
			}
		}
	    if(dd>suma){
		  cont++;
	    }
	}
}

// Mostrar matriz Jacobi
void Jacobi::getMatrix(float a[][v], int l){
	
	cout<<"\n ";
	
	for(int i=0; i<l; i++){
		
		for(int j=0; j<l; j++){
			
			cout<<"\t "<<a[i][j]<<" ";
		}
		
		cout<<"\n ";
	}
	
	cout<<"\n Numero de ecuaciones: "<<l<<endl;
	cout<<"\n ";
}

//Metodo Jacobi
 void Jacobi::metodoJacobi(int l, float x[], float a[][10], float b[]){
 	
    char p;
	float c[v];
	int k, i, j;
	line:
		
	for(int k=0; k<10; k++){
		
		for(int i=0; i<l; i++){
			
			c[i]=b[i];
			
			for(int j=0; j<l; j++){
				
				if(i != j){
					
					c[i]=c[i]-a[i][j]*x[j];
				}
			}
		}
		
		for(int i=0; i<v; i++){
			x[i]=c[i]/a[i][i];
		}
	}
	
	cout<<"\n La solucion es: "<<endl;
	cout<<"\n ";
	
	for(int i=0; i<l; i++){
		cout<<"x("<<i<<")= "<<x[i]<<endl;
	}
}


void Jacobi::getJacobi(){
	
	
	
	if(cont==l || cont<l){
		
		cout<<"\n Mostrar la matriz ingresada: "<<endl;
	    getMatrix(a,l);
	    metodoJacobi(l, x, a, b);
	}
	
	else{
		
	    cout<<"\n La matriz no es diagonalmente dominante. Proceso finalizado "<<endl;
	    cout<<"\n Mostrar la matriz ingresada: "<<endl;
		getMatrix(a,l);
	}
}
 
