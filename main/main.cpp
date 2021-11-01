
#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include "C:\Users\hp\Documents\Semestre 2022-1\Metodos numericos I\Proyecto Métodos Numéricos\Librerias\M. Newton\Newton.h"
#include "C:\Users\hp\Documents\Semestre 2022-1\Metodos numericos I\Proyecto Métodos Numéricos\Librerias\M.Jacobi\Jacobi.h"
using namespace std;

int main(){
	
	int menu, op;
	
	menu=1;
	while(menu==1){
		
		cout<<"\n\n\t ====== Elija un metodo ====== \n\n";
		
		cout<<"1 -> Newton \n\n "<<"2 -> Jacobi \n\n";
		cout<<"-> Opcion: ";
		cin>>op;
		
		if(op==1){
			
			Newton newton;
	        newton.muestra();
		}
		
		if(op==2){
			
			Jacobi jacobi;
			jacobi.getJacobi();
		}
	}
	
	system("pause");
	return 0;
}
