#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;

class Newton{
	
	private:
		double X, Fx, Fx1, X1;
        
    public: 
        Newton();
	    double funcion(double, double);
        double derivada(double, double); 
		void muestra();  	
};

Newton::Newton(){
	
	float x;
	int i, n;
	
    cout<<"\t\n\n ====== Metodo de Newton ====== \n\n";
	
	cout<<"\t Ecuacion:  x(e^x)-2  \n\n";
	cout<<"\n";
	cout<<"\t Ingresa el valor de x0: ";
	cin>>x;
	X=x;
	cout<<"\n";
	cout<<"\t Numero de iteraciones: "; 
	cin>>n;
	
	for(int i=1;i<n;i++){
		
		X1= X-(funcion(X,Fx)/derivada(X,Fx1));
		X=X1;
	} 
	
	
	cout<<"\t\n\n ====== Fin del programa ====== \a\a\a\a \n\n";
}

double Newton::funcion(double X, double Fx){
	
	Fx=X*exp(X)-2;
	
	return(Fx);
}

double Newton::derivada(double X, double Fx1){
	
	Fx1=exp(X)*(X+1);
	
	return(Fx1);
}

void Newton::muestra(){
	
	cout<<"\t\n\n ->El valor de la funcion es: "<<funcion(X,Fx)<<endl;
	cout<<"\t\n\n ->El valor de la derivada es: "<<derivada(X,Fx1)<<endl;
	cout<<"\t\n\n ->El valor de x+1 es: "<<X1<<endl;
	cout<<"\n\n ====================================================== \n\n";
	cout<<"\t\n\n ====== Fin del programa ====== \a\a\a\a \n\n";
	
} 

