//Universidad Nacional Autónoma de México.
//Programa de Tecnología en Cómputo. Generación 38. Inventario Dinámico Tienda A-Shop.  
//Programa creado por Adriana Hernández González y Edivaldo Gómez Hernández

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "EmpleadoVentas.h"
#include "EmpleadoCompras.h"
#include "AdministradorGeneral.h"
#include "Departamentos.h"

int main(int argc, char const *argv[]){
	CargarDepartamentos();
	int exit=0;
	int permiso=1;
	char opcion='0';
	char buffer[100];
	int empleadoVentas(char buffer[100]);
	int empleadoCompras(char buffer[100]);
	int AdministradorGeneral(char buffer[100]);
	printf("\n\t\t********** Bienvenido a Tienda A-shop **********\n\n");
	while(exit!=1){
		printf("¿Qué puesto tiene usted?\n\n");
		printf("1)Empleado de Ventas\t\t2)Empleado de Compras\t\t3)Administrador\t\t4)Salir : ");
		scanf(" %c[^\n]",&opcion);
		switch(opcion){
			case'1':
				printf("\nIngrese su usuario de Empleado de Ventas: ");
				scanf(" %[^\n]",buffer);
				permiso=empleadoVentas(buffer);
				if (permiso==0){
					empleadoVentasAccion();
				}
			break;
			case'2':
				printf("\nIngrese su usuario de Empleado de Compras: ");
				scanf(" %[^\n]",buffer);
				permiso=empleadoCompras(buffer);
				if (permiso==0){
					empleadoComprasAccion();
				}
			break;
			case'3':
				printf("\nIngrese su usuario de Administrador General: ");
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
				printf("\n\n\t\t********** Opción no válida **********\n\n");
			break;
		}
	}
}