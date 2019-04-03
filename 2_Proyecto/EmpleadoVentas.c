#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "EmpleadoVentas.h"
#include "Articulos.h"
#include "Departamentos.h"

int empleadoVentas(char buffer[100]){	
	
	int usuario=0;
	int bandera=0;
	char buscador[100];
	strcat(buffer,".user");	
	FILE *Archivo;
	Archivo=fopen("EmpleadoVentas.txt","r");
	if(Archivo==NULL){
		printf("Se generó un error en la base de datos\n");
		return 1;
	}else{
		while(!feof(Archivo)){
			fgets(buscador, 100, (FILE*) Archivo);
			strtok(buscador, "\n");
			if(strcmp(buffer, buscador)==0){
				if (bandera==0){
					printf("Ingrese su contraseña: ");
					scanf(" %[^\n]",buffer);
					bandera=1;
				}
				if (strcmp(buffer, buscador)==0){
					printf("\n\n\t\t********** ¡Ingreso con éxito! **********\n\n");
					impimirDepartamentos();
					return 0;
				}
			}
		}
	}
	printf("\n\n\t\t********** ¡Usuario o contraseña no válidos! **********\n\n");
	return 1;
}


void empleadoVentasAccion(){

	char bufferDepartamento[100];
	char bufferProducto[100];
	char bufferAux[100];
	char buscador[100];
	char auxiliar1[100];
	char auxiliar2[100];
	char salto[3]="\n ";
	int bandera=0;
	int cantidad=0;
	int descontar=0;
	int contadorFormato=0;
	int largo=0;
	int contador=0;
	char cantidadChar[100];
	FILE *Archivo;
	int  cursor=0;
	printf("Ingrese el nombre del departamento: ");	
	scanf(" %[^\n]",bufferDepartamento);
	strcat(bufferDepartamento,".txt");
	Archivo=fopen (bufferDepartamento,"r+");
	if(Archivo==NULL){
		printf("\n\t\t***** ¡¡No existe ese departamento!! *****\t\t\n\n");
	}else{
		muestraInventario(bufferDepartamento);
		printf("Ingrese el nombre del producto: ");
		scanf(" %[^\n]",bufferProducto);
		while(!feof(Archivo)){
			fgets(buscador, 100, (FILE*) Archivo);
			strcpy(auxiliar1,buscador);
			strcpy(auxiliar2,buscador);
			strtok(auxiliar1,"\t");
			if(strcmp(bufferProducto, auxiliar1)==0){
				strtok(auxiliar2,"\n");
				largo=strlen(auxiliar2);
				contador=largo;
				while(auxiliar2[contador]!='\t'){
					contador--;
				};
				contador++;
				memset(cantidadChar,'\0',100);
				for(int i = 0; i < (largo-contador); i++)
					cantidadChar[i]=auxiliar2[contador+i];
				cantidad=atoi(cantidadChar);
				printf("¿Cuántas piezas desea vender?: ");
				scanf("%d",&descontar);
				while(descontar>cantidad){
					printf("\n\t\t***** ¡Cantidad Incorrecta! *****\t\t\n\n");
					printf("¿Cuántas piezas desea vender?: ");
					scanf("%d",&descontar);
				}
				cantidad-=descontar;
				gcvt(cantidad,15,cantidadChar);
				contadorFormato=strlen(cantidadChar);
				memset(bufferAux,'\0',100);
				while(contadorFormato<15){
						strcat(bufferAux,"0");
						contadorFormato++;
				}
				strcat(bufferAux,cantidadChar);
				strcpy(cantidadChar,bufferAux);
				memset(auxiliar1,'\0',100);
				strncat(auxiliar1,auxiliar2,contador);
				strncat(auxiliar1,cantidadChar,strlen(cantidadChar));
				cursor = ftell(Archivo);
				fseek(Archivo, cursor-largo-1, SEEK_SET);
				strncat(auxiliar1,salto,1);
				fputs(auxiliar1,Archivo);
				bandera=1;

				HacerTicket(char auxiliar2[100],int descontar);

				printf("\n\t\t***** ¡¡Venta realizada!! *****\t\t\n\n");
			}
		};
	if (bandera==0)
		printf("\n\t\t***** ¡¡Producto no encontrado!! *****\t\t\n\n");
	fclose(Archivo);
	}
}




void HacerTicket(char auxiliar2[100],int descontar){

int bandera=0;
	float cantidad=0;
	
	int largo=0;
	int contador=0;
	char cantidadChar[100];
	int cont=0;


	FILE *ticket;
	ticket = fopen("ticket.txt","w");
	fputs("************TICKET*************\n\n",ticket);
	fputs("Tu compra en A-shop es: \n\n",ticket);

	  char *p = strtok (auxiliar2, " ");
	  char *data[3];

	  while (p)
	    {
	      data[cont++] = p;
	      p = strtok (NULL, "-");
	    }

	  for (cont = 0; cont < 5; cont++)
	    {
	      printf ("%s\n", &data[cont]);
	    }
	    //concat(data[1],data[3]);
	    fputs(data[1],ticket);
	    fputs(data[3],ticket);



}