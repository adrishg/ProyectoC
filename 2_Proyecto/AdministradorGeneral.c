#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Departamentos.h"
#include "Articulos.h"
#include "Empleados.h"

int AdministradorGeneral(char buffer[100]){	
	int usuario=0;
	int bandera=0;
	char buscador[100];
	strcat(buffer,".user");
	FILE *Archivo;
	Archivo=fopen("AdministradorGeneral.txt","r");
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
					return 0;
				}
			}
		}
	}
	printf("\n\n\t\t********** ¡Usuario o contraseña no válidos! **********\n\n");
	return 1;
}

void AdministradorAccion(){
	int exit=0;
	char opcion='0';
	while(exit!=1){
		printf("¿En qúe área quiere trabajar?\n\n");
		printf("1)Departamentos\t\t2)Articulos\t\t3)Empleados\t\t4)Salir: ");
		scanf(" %c[^\n]",&opcion);
		switch(opcion){
			case'1':
				accionDepartamentos();
			break;
			case'2':
				accionArticulos();
			break;
			case'3':
				accionEmpleados();
			break;
			case'4':
				exit=1;
			break;
			default:
				printf("\n\t\t********** Opción no válida **********\n");
			break;
		}
	}
}