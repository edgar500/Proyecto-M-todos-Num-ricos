

#include<iostream>
#include<math.h>
#define v 10
using namespace std;

class Jacobi{
	
	private:
		int in, j, l, cont=0, s=1;
	    float x[v], a[v][v], b[v], dd, suma;
		
	public:
	    void setJacobi();
		void metodoJacobi(int l, float x[], float a[][10], float b[]);
        void getMatrix(float a[][10], int l);
        int determinante(float a[][10], int l);
        int cofactor(float a[][10], int l, int fila, int col);	
		void getJacobi();
		
};

void Jacobi::setJacobi(){
	
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

//Determinante Jacobi
int Jacobi::determinante(float a[][v], int l){
	
	int det = 0.0;
	
	if(l==1){
		
		det=a[0][0];
		
	}else{
		
		for(int j=0; j<l; j++){
			
			det=det+a[0][j]*cofactor(a,l,0,j);
		}
	}
	
	return det;
}

//Cofactores Jacobi
int Jacobi::cofactor(float a[][v], int l, int filas, int col){
	
	float submatriz[v][v];
	int m=l-1;
	int x=0;
	int y=0;
	
	for(int i=0; i<l; i++){
		
		for(int j=0; j<l; j++){
			
			if(i != filas && j != col){
				
				submatriz[x][y] = a[i][j];
				y++;
				
				if(y>=m){
					
					x++;
					y=0;
				}
			}
		}
	} 
	
	return pow(-1.0, filas + col)*determinante(submatriz, m);
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
	    cout<<"\n El determinante es: "<<determinante(a,l)<<endl;
	    metodoJacobi(l, x, a, b);
	}
	
	else{
		
	    cout<<"\n La matriz no es diagonalmente dominante. Proceso finalizado "<<endl;
	    cout<<"\n Mostrar la matriz ingresada: "<<endl;
		getMatrix(a,l);
	}
}
 
