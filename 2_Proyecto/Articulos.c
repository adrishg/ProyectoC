#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Articulos.h"
#include "Departamentos.h"

void accionArticulos(){
	
	int exit=0;
	char opcion='0';
	while(exit!=1){
		printf("\n¿Que acción desea realzar en Articulos?\n\n");
		printf("1)Agregar Articulos\t\t2)Eliminar Articulos\t\t3)Salir: ");
		scanf(" %c[^\n]",&opcion);
		switch(opcion){
			case'1':
				AgregarArticulos();
			break;
			case'2':
				EliminarArticulos();
			break;
			case'3':
				exit=1;
			break;
			default:
				printf("\n\t\t********** Opción no válida **********\n");
			break;
		}
	}
}

void muestraInventario(char bufferDepartamento[100]){
	
	char buscador[100];
	FILE *Archivo;
	Archivo=fopen (bufferDepartamento,"r");
	if(Archivo==NULL){
		printf("Se generó un error en la base de datos\n");
	}else{
		printf("\n\t\t********** Departamento de %s **********\n\n",bufferDepartamento);
		printf("Producto\t\t\tCosto\t\t\tPrecio\t\t\tCantidad\n\n");
		
		while(!feof(Archivo)){
			fgets(buscador, 100, (FILE*) Archivo);
			printf("%s",buscador);
		};
		printf("\n");
		fclose(Archivo);
	}
}

void AgregarArticulos(){
	
	impimirDepartamentos();
	int contadorFormato=0;
	int cursor=0;
	int cantidad=0;
	float costo=0;
	float precio=0;
	FILE *Archivo;
	char buffer[100];
	char bufferAux[100];
	memset(bufferAux,'\0',100);
	printf("\nIngrese el nombre del departamento: ");	
	scanf(" %[^\n]",buffer);
	strcat(buffer,".txt");
	Archivo=fopen (buffer,"r+");
	if(Archivo==NULL){
		printf("\n\t\t***** ¡¡No existe ese departamento!! *****\t\t\n\n");
	}else{
		fseek(Archivo, -1, SEEK_END);
		printf("Ingrese el nombre del Articulo: ");
		scanf(" %[^\n]",buffer);
		strcat(buffer,"\t\t\t");
		fputs(buffer,Archivo);
		memset(buffer,'\0',100);
		printf("Ingrese el costo del Articulo: ");
		scanf("%f",&costo);
		gcvt(costo,15,buffer);
		contadorFormato=strlen(buffer);
		while(contadorFormato<15){
			strcat(bufferAux,"0");
			contadorFormato++;
		}
		strcat(bufferAux,buffer);
		strcat(bufferAux,"\t\t");
		fputs(bufferAux,Archivo);
		memset(bufferAux,'\0',100);
		memset(buffer,'\0',100);
		precio=costo*1.1;
		gcvt(precio,15,buffer);
		contadorFormato=strlen(buffer);
		while(contadorFormato<15){
			strcat(bufferAux,"0");
			contadorFormato++;
		}
		strcat(bufferAux,buffer);
		strcat(bufferAux,"\t\t");
		fputs(bufferAux,Archivo);
		memset(buffer,'\0',100);
		memset(bufferAux,'\0',100);
		printf("Ingrese la cantidad de Articulos: ");
		scanf("%d",&cantidad);
		gcvt(cantidad,15,buffer);
		contadorFormato=strlen(buffer);
		while(contadorFormato<15){
			strcat(bufferAux,"0");
			contadorFormato++;
		}
		strcat(bufferAux,buffer);
		strcat(bufferAux,"\n ");
		fputs(bufferAux,Archivo);
		memset(buffer,'\0',100);
		memset(bufferAux,'\0',100);
		fclose(Archivo);
	}
}

void EliminarArticulos(){
	
	impimirDepartamentos();
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
				printf("¿Cuántas piezas desea eliminar?: ");
				scanf("%d",&descontar);
				while(descontar>cantidad){
					printf("\n\t\t***** ¡Cantidad Incorrecta! *****\t\t\n\n");
					printf("¿Cuántas piezas desea elimnar?: ");
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
				printf("\n\t\t***** ¡¡Productos eliminados!! *****\t\t\n\n");
			}
		};
	if (bandera==0)
		printf("\n\t\t***** ¡¡Producto no encotrado!! *****\t\t\n\n");
	fclose(Archivo);
	}
}