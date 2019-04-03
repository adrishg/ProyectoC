#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Departamentos.h"

char NombreDepartamento[100][100];
int ContadorDepa=0;

void accionDepartamentos(){
	int exit=0;
	char opcion='0';
	while(exit!=1){
		printf("\n¿Que acción desea realizar en Departamento?\n\n");
		printf("1)Agregar Departamento\t\t2)Eliminar Departamento\t\t3)Salir: ");
		scanf(" %c[^\n]",&opcion);
		switch(opcion){
			case'1':
				AgregarDepartamentos();
			break;
			case'2':
				EliminarDepartamentos();
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

int CargarDepartamentos(){
	char buscador[100];
	FILE *Archivo;
	Archivo=fopen("Departamentos.txt","r");
	if(Archivo==NULL){
		printf("Se generó un error en la base de datos\n");
		return 1;
	}else{
		while(!feof(Archivo)){
			fgets(buscador, 100, (FILE*) Archivo);
			strtok(buscador, "\n");
			if (buscador!=" \0"){
				strcpy(NombreDepartamento[ContadorDepa],buscador);
				ContadorDepa++;
			}
		}
	ContadorDepa--;
	fclose(Archivo);
	}
}


void impimirDepartamentos(){
	printf("\n\t\t********** Departamentos de A-shop **********\n\n");
	for (int i = 0; i < ContadorDepa; i++)
		printf("Departamento de %s\n",NombreDepartamento[i]);
	printf("\n");
}


void AgregarDepartamentos(){
	impimirDepartamentos();
	int cursor=0;
	int largo=0;
	char salto[3]="\n";
	char buffer[100];
	printf("\nIngrese el Nombre del Departamento a crear: ");
	scanf(" %[^\n]",buffer);
	strcpy(NombreDepartamento[ContadorDepa],buffer);
	strcat(buffer,".txt");
	FILE *ArchivoDepartamento;
	ArchivoDepartamento=fopen(buffer,"w");
	if (ArchivoDepartamento==NULL){
		printf("\n\n\t\t********** Error al crear Departamento **********\n");
	}else{
		fclose(ArchivoDepartamento);
		printf("\n\n\t\t********** Departamento creado exitosamente **********\n");
		ContadorDepa++;
		FILE *Archivo;
		Archivo=fopen("Departamentos.txt","a");
		if(Archivo==NULL){
			printf("Se generó un error en la base de datos\n");
		}else{
			memset(buffer,'\0',100);
			strcpy(buffer,NombreDepartamento[ContadorDepa-1]);
			strcat(buffer,"\n");
			fputs(buffer,Archivo);
			fclose(Archivo);
		}
	}
}


void EliminarDepartamentos(){
	printf("\n\t\t********** Función en desarrollo .... **********\n");
	printf("\n\t\t********** Aun no se puede realizar **********\n");
}