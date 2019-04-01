#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "EmpleadoVentas.h"
#include "EmpleadoCompras.h"
#include "AdministradorGeneral.h"

int main(int argc, char const *argv[])
{
	
	int exit=0;
	int permiso=1;
	char opcion='0';
	char buffer[100];

	int empleadoVentas(char buffer[100]);
	int empleadoCompras(char buffer[100]);
	int AdministradorGeneral(char buffer[100]);

	printf("\n\t\t***** Bienvenido a Tienda A-shop *****\n\n");

	while(exit!=1){
		printf("¿Qué puesto tiene usted?\n\n");
		printf("1)Empleado de Ventas\t\t2)Empleado Empleado de Compras\t\t3)Administrador\t\t4)Salir : ");
		scanf(" %c[^\n]",&opcion);
		switch(opcion){
			case'1':
				printf("Ingrese su usuario de Empleado de Ventas: ");
				scanf(" %[^\n]",buffer);
				permiso=empleadoVentas(buffer);
				if (permiso==0){
					empleadoVentasAccion();
				}
			break;
			case'2':
				printf("Ingrese su usuario de Empleado de Compras: ");
				scanf(" %[^\n]",buffer);
				permiso=empleadoCompras(buffer);
				if (permiso==0){
					empleadoComprasAccion();
				}
			break;
			case'3':
				printf("Ingrese su usuario de Administrador General: ");
				scanf(" %[^\n]",buffer);
				permiso=AdministradorGeneral(buffer);
				if (permiso==0){
					AdministradorAccion();
				}
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