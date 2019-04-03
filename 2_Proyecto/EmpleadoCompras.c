#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "EmpleadoCompras.h"
#include "Articulos.h"
#include "Departamentos.h"


int empleadoCompras(char buffer[100]){	

	int usuario=0;
	int bandera=0;
	char buscador[100];
	strcat(buffer,".user");	
	FILE *Archivo;
	Archivo=fopen("EmpleadoCompras.txt","r");
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


void empleadoComprasAccion(){
	
	char bufferDepartamento[100];
	char bufferProducto[100];
	char bufferAux[100];
	char buffer[100];
	char buscador[100];
	char auxiliar1[100];
	char auxiliar2[100];
	char salto[3]="\n ";
	int bandera=0;
	int cantidad=0;
	int agregar=0;
	int contadorFormato=0;
	int largo=0;
	int contador=0;
	char cantidadChar[100];
	float costo=0;
	float precio=0;
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
				strcat(bufferProducto,"\t\t\t");
				printf("Ingrese el nuevo costo del producto: ");
				scanf("%f",&costo);
				gcvt(costo,15,buffer);				
				contadorFormato=strlen(buffer);
				memset(bufferAux,'\0',100);
				while(contadorFormato<15){
					strcat(bufferAux,"0");
					contadorFormato++;
				}
				strcat(bufferAux,buffer);
				strcat(bufferAux,"\t\t");
				strcat(bufferProducto,bufferAux);
				memset(buffer,'\0',100);
				memset(bufferAux,'\0',100);
				precio=costo*1.1;
				gcvt(precio,15,buffer);
				contadorFormato=strlen(buffer);
				while(contadorFormato<15){
					strcat(bufferAux,"0");
					contadorFormato++;
				}
				strcat(bufferAux,buffer);
				strcat(bufferAux,"\t\t");
				strcat(bufferProducto,bufferAux);
				printf("Ingrese la nueva cantidad del producto: ");
				scanf("%d",&agregar);
				while(agregar<0){
					printf("\n\t\t***** ¡Cantidad Incorrecta! *****\t\t\n\n");
				printf("Ingrese la nueva cantidad del producto: ");
					scanf("%d",&agregar);
				}
				cantidad+=agregar;
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
				strcpy(auxiliar1,bufferProducto);
				strncat(auxiliar1,cantidadChar,strlen(cantidadChar));
				cursor = ftell(Archivo);
				fseek(Archivo, cursor-largo-1, SEEK_SET);
				strncat(auxiliar1,salto,1);	
				fputs(auxiliar1,Archivo);
				bandera=1;
				printf("\n\t\t***** ¡¡Compra realizada!! *****\t\t\n\n");
			}
		};
	if (bandera==0)
		printf("\n\t\t***** ¡¡Producto no encotrado!! *****\t\t\n\n");
	fclose(Archivo);
	}
}