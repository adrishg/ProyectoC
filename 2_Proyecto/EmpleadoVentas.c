#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "EmpleadoVentas.h"

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
					printf("¡Ingreso con éxtio!\n");
					return 0;
				}
			}
		}
	}
	printf("¡Usuario o contraseña no válidos!\n");
	return 1;
}

void empleadoVentasAccion(){
}