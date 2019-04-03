#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Empleados.h"

void accionEmpleados(){
	int exit=0;
	char opcion='0';
	while(exit!=1){
		printf("\n¿Que acción desea realzar en Empleados?\n\n");
		printf("1)Agregar Empleados\t\t2)Eliminar Empleados\t\t3)Modificar Empleados\t\t4)Salir: ");
		scanf(" %c[^\n]",&opcion);
		switch(opcion){
			case'1':
				AgregarEmpleados();
			break;
			case'2':
				EliminarEmpleados();
			break;
			case'3':
				ModificarEmpleados();
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

void AgregarEmpleados(){
	int exit=0;
	char opcion='0';
	while(exit!=1){
		printf("\n¿Que tipo de Empleado agregará?\n\n");
		printf("1)Empleado de Ventas\t\t2)Empleado de Compras\t\t3)Salir: ");
		scanf(" %c[^\n]",&opcion);
		switch(opcion){
			case'1':
				AgregarEmpleadosVentas();
			break;
			case'2':
				AgregarEmpleadosCompras();
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

void AgregarEmpleadosVentas(){
	FILE *Archivo;
	char buffer[100];
	Archivo=fopen ("EmpleadoVentas.txt","a");
	if(Archivo==NULL){
		printf("Error al agregar Empleado\n");
	}else{
		fputs("\n",Archivo);
		printf("Ingrese el nombre de Usuario: ");
		scanf(" %[^\n]",buffer);
		strcat(buffer,".user\n");
		fputs(buffer,Archivo);
		memset(buffer,'\0',100);
		printf("Ingrese la contraseña: ");
		scanf(" %[^\n]",buffer);
		strcat(buffer,"\n");
		fputs(buffer,Archivo);
		memset(buffer,'\0',100);	
		printf("Ingrese su Nombre: ");
		scanf(" %[^\n]",buffer);
		strcat(buffer,"\n");
		fputs(buffer,Archivo);
		memset(buffer,'\0',100);
		printf("Ingrese su puesto: ");
		scanf(" %[^\n]",buffer);
		strcat(buffer,"\n");
		fputs(buffer,Archivo);
		memset(buffer,'\0',100);	
		printf("Ingrese su sueldo: ");
		scanf(" %[^\n]",buffer);
		strcat(buffer,"\n");
		fputs(buffer,Archivo);
		fclose(Archivo);
	}
}

void AgregarEmpleadosCompras(){
	FILE *Archivo;
	char buffer[100];
	Archivo=fopen ("EmpleadoCompras.txt","a");
	if(Archivo==NULL){
		printf("Error al agregar Empleado\n");
	}else{
		fputs("\n",Archivo);
		printf("Ingrese el nombre de Usuario: ");
		scanf(" %[^\n]",buffer);
		strcat(buffer,".user\n");
		fputs(buffer,Archivo);
		memset(buffer,'\0',100);
		printf("Ingrese la contraseña: ");
		scanf(" %[^\n]",buffer);
		strcat(buffer,"\n");
		fputs(buffer,Archivo);
		memset(buffer,'\0',100);	
		printf("Ingrese su Nombre: ");
		scanf(" %[^\n]",buffer);
		strcat(buffer,"\n");
		fputs(buffer,Archivo);
		memset(buffer,'\0',100);
		printf("Ingrese su puesto: ");
		scanf(" %[^\n]",buffer);
		strcat(buffer,"\n");
		fputs(buffer,Archivo);
		memset(buffer,'\0',100);	
		printf("Ingrese su sueldo: ");
		scanf(" %[^\n]",buffer);
		strcat(buffer,"\n");
		fputs(buffer,Archivo);
		fclose(Archivo);
	}
}


void EliminarEmpleados(){
	printf("\n\t\t********** Función en desarrollo .... **********\n");
	printf("\n\t\t********** Aun no se puede realizar **********\n");
}


void ModificarEmpleados(){
	printf("\n\t\t********** Función en desarrollo .... **********\n");
	printf("\n\t\t********** Aun no se puede realizar **********\n");
}