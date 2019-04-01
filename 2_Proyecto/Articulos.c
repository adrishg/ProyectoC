#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Articulos.h"

void accionArticulos(){
	int exit=0;
	char opcion='0';
	while(exit!=1){
		printf("¿Que acción desea realzar en Articulos?\n");
		printf("1)Agregar Articulos\t\t2)Eliminar Articulos\t\t3)Salir\n");
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

void AgregarArticulos(){
	
	int cantidad=0;
	float costo=0;
	float precio=0;

	FILE *Archivo;
	char buffer[100];
	
	printf("Ingrese el nombre del departamento: ");	
	scanf(" %[^\n]",buffer);
	strcat(buffer,".txt");
	Archivo=fopen (buffer,"a");
	
	if(Archivo==NULL){
		printf("No existe ese departamento\n");
	}else{
		fputs("\n",Archivo);
		printf("Ingrese el nombre del Articulo: ");
		scanf(" %[^\n]",buffer);
		strcat(buffer," ");
		fputs(buffer,Archivo);
		memset(buffer,'\0',100);
		printf("Ingrese el costo del Articulo: ");
		scanf("%f",&costo);
		gcvt(costo,5,buffer);
		strcat(buffer," ");
		fputs(buffer,Archivo);
		precio=costo*1.1;
		gcvt(precio,5,buffer);
		strcat(buffer," ");
		fputs(buffer,Archivo);
		printf("Ingrese la cantidad de Articulos: ");
		scanf("%d",&cantidad);
		gcvt(cantidad,5,buffer);
		fputs(buffer,Archivo);
		fclose(Archivo);
	}
}

void EliminarArticulos(){
	
	char bufferDepartamento[100];
	char bufferProducto[100];
	char buscador[100];
	char auxiliar1[100];
	char auxiliar2[100];
	char salto[2]="\n";

	int cantidad=0;
	int descontar=0;
	
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
		printf("No existe ese departamento\n");
	}else{
		printf("Ingrese el nombre del producto: ");	
		scanf(" %[^\n]",bufferProducto);
		while(!feof(Archivo)){
			fgets(buscador, 100, (FILE*) Archivo);
			strcpy(auxiliar1,buscador);
			strcpy(auxiliar2,buscador);
			strtok(auxiliar1, " ");
			if(strcmp(bufferProducto, auxiliar1)==0){
				strtok(auxiliar2, "\n");
				largo=strlen(auxiliar2);
				contador=largo;
				while(auxiliar2[contador]!=' '){
					contador--;
				};
				contador++;
				for (int i = 0; i < (largo-contador); i++)
					cantidadChar[i]=auxiliar2[contador+i];
				cantidad=atoi(cantidadChar);
				printf("Existen %d piezas.\n",cantidad);
				printf("¿Cuántas piezas desea quitar?: ");
				scanf("%d",&descontar);
				while(descontar>cantidad){
					printf("¡Valor incorrecto!\n");
					printf("¿Cuántas piezas desea quitar?: ");
					scanf("%d",&descontar);
				}
				cantidad-=descontar;
				gcvt(cantidad,5,cantidadChar);
				memset(auxiliar1,'\0',100);
				strncat(auxiliar1,auxiliar2,contador);
				strncat(auxiliar1,cantidadChar,strlen(cantidadChar));
				printf("%s\n",auxiliar1);
				cursor = ftell(Archivo);
				fseek(Archivo, cursor-largo-1, SEEK_SET);
				strncat(auxiliar1,salto,1);	
				fputs(auxiliar1,Archivo);	
			}
		}
	}
	fclose(Archivo);
}