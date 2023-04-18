// Barros, Diego Ulises
#include <xinu.h>
#include <stdio.h>

int checkeaChar(char, char[], char[], int);
int checkeaResuelto(char[], int);
int mostrarFaltantes(char[], int);

int ahorcado()
{

	int c, respuesta, intentos, bandera, longitud;
	char incognita[] = "marmota";
	char stringActual[] = {"_______"};
	intentos = 6;

	longitud = sizeof(incognita) / sizeof(incognita[0]);

	/* Decirle al sistema que el modo input es RAW */
	control(0, TC_MODER, 0, 0);

	while (1)
	{
		printf("\r                                                          ");
		printf("\r La palabra a adivinar tiene %d letras\n", longitud - 1);
		printf("\r c = %c  ingrese una letra (0 para salir): \n", c);
		/*Muestro al usuario el stringActual*/
		printf("\n========== Progreso: ");
		mostrarFaltantes(stringActual, longitud);
		c = getchar();

		if (c == '0')
			break;

		respuesta = checkeaChar((char)c, incognita, stringActual, longitud);

		if (respuesta == 1)
		{

			bandera = checkeaResuelto(stringActual, longitud);
			if (bandera == 1)
			{
				printf("\r----------------------------------GANASTE!!----------------------------------\n");
				printf("La palabra era %s\n", stringActual);
				break;
			}
		}
		else
		{
			/*Disminuyo los intentos y checkeo si perdio*/
			intentos = intentos - 1;

			if (intentos == 0)
			{
				printf("\r------------------------PERDISTE------------------------\n");
				break;
			}
			else
			{
				printf("\n++++++++++++++++++++++ Intentos disponibles: %d ++++++++++++++++++++++\n", intentos);
			}
		}
	}

	control(0, TC_MODEC, 0, 0);
}

int checkeaChar(char c, char incognita[], char stringActual[], int longitud)
{
	/*Analiza si se encuentra el caracter en el string incognita*/
	int respuesta = 0;

	for (int i = 0; i < longitud; i++)
	{
		if (c == incognita[i])
		{
			stringActual[i] = c;
			respuesta = 1;
		}
	}
	return respuesta;
}

int checkeaResuelto(char str1[], int longitud)
{
	/*Analiza si se termino de resolver el juego */
	int respuesta = 1;

	for (int i = 0; i < longitud; i++)
	{
		if (str1[i] == '_')
		{
			respuesta = 0;
			i = longitud;
		}
	}
	return respuesta;
}

int mostrarFaltantes(char stringActual[], int longitud)
{
	// Muestra las letras que adivino hasta ahora el usuario
	for (int i = 0; i < longitud; i++)
	{
		printf("%c ", stringActual[i]);
	}
	printf(" ==========\n");
	return 0;
}