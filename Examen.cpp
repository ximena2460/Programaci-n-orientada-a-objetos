#include<stdio.h>
 #include<conio.h>
 #include<cstdio>
 
 class Lavadora{
 	public: 
 	
 	int estado;
 	 void Lavadoraestado()
 	 {
 	 	printf("\nEstado de la lavadora: 1)apagado 2)reposo ");
 	 	scanf("%d", & estado);
 	 	if(estado==1)
 	 	{ 
		printf("\n necesita enceder la lavadora");
	}
		while (estado != 1 && estado != 2)
		{
		  printf("\nopcion no disponible");
		  printf("\npresione el estado de la lavadora: 1)apagado 2)reposo");
		  scanf("%d", & estado);
		}
		printf("\nprecione encender");
 	 	
	  }
 	
 };
 
 class Modo{
 	public:
 	int tipo;
 	int continuar;
 		
	 void Seleccionarmodo()
	 {//poner un while para q cuando termine vuelva a empezae o yoqse
	 	
	 	while (continuar==1){
	   printf("\nSeleccione el modo: 1)Regular 2)Delicado 3)Super delicado");
	   scanf("%d", & tipo);
	   if(tipo==1)
	   { printf("\npasa al remojo");
	     printf("\n..... espere 30 segundos");
	     printf("\n listo, pasa a enjuague");
	     printf("\n..... espere 30 minutos");
	    printf("\n listo, pasa adrenaje");
	    printf("\n..... espere 5 minutos");
	    printf("\n listo, paso a secado");
	    printf("\n..... espere 20 minutos");
	    printf("\n termino su ciclo");
	   }
	   else if(tipo==2)
	   { printf("\npasa al remojo");
	     printf("\n..... espere 30 segundos");
	     printf("\n listo, pasa a enjuague");
	     printf("\n..... espere 30 minutos");
	    printf("\n listo, pasa adrenaje");
	    printf("\n..... espere 5 minutos");
	    printf("\n termino su ciclo");
	   }
	   else if(tipo==3)
	   { printf("\npasa al remojo");
	     printf("\n..... espere 30 segundos");
	     printf("\n listo, pasa a enjuague");
	     printf("\n..... espere 30 minutos");
	    printf("\n listo, pasa adrenaje");
	    printf("\n..... espere 5 minutos");
	    printf("\n termino su ciclo");
	   }
	   else {
	   	printf("\nopcion no valida");
	   }
	     printf("\n\n¿Desea ejecutar otro ciclo? 1)S1  0) = No: ");
        scanf("%d", &continuar);
	 }	
	 printf("\nLavadora apagada");

   }
 };
 
 int main(){
 
  Lavadora l;
   Modo m;
   
   l.Lavadoraestado();
   m.Seleccionarmodo();
   
   return 0;
}
