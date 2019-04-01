#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Departamentos.h"

void accionDepartamentos(){
	int exit=0;
	char opcion='0';
	while(exit!=1){
		printf("¿Que acción desea realzar en Departamento?\n");
		printf("1)Agregar Departamento\t\t2)Eliminar Departamento\t\t3)Salir\n");
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

void AgregarDepartamentos(){
	char buffer[100];
	printf("Ingrese el Nombre del Departamento a crear\n");
	scanf(" %[^\n]",buffer);
	strcat(buffer,".txt");
	FILE *ArchivoDepartamento;
	ArchivoDepartamento=fopen(buffer,"w");
	if (ArchivoDepartamento==NULL){
		printf("Error al crear Departamento\n");
	}else{
		printf("Departamento creado exitosamente\n");
	}
	fclose(ArchivoDepartamento);
}

void EliminarDepartamentos(){
	char buffer[100];
	printf("Ingrese el Nombre del Departamento a eliminar\n");
	scanf(" %[^\n]",buffer);
	strcat(buffer,".txt");
	if (remove(buffer)==0){	
		printf("Departamento eliminado exitosamente\n");
	}else{
		printf("Error al eliminar Departamento\n");
	}
}