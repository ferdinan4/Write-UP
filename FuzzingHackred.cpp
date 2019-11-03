#include <array>
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;
boolean fuzzingmodificacion2(char* array); //declaracion funcion;
char sacarindice(char* puntero, char* puntero_diccionario, char i);
void comprobacionIndices(char indice1, char indice2, char indice3, char  indice4);
int main()
{

	string Input2 = "";
	char Array_Diccionario[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8',',9','/' };
	int tamayo = 0;
	boolean match = FALSE;
	char indice1 = 0x00;
	char indice2 = 0x00;
	char indice3 = 0x00;
	char indice4 = 0x00;
	char indice5 = 0x00;
	char indice6 = 0x00;
	char indice7 = 0x00;
	char indice8 = 0x00;
	char* puntero = Array_Diccionario;
	std::cout << "Vamos a crackear el binario hackred \n Sabemos que la cadena g;jf\"db\% es la ganadora por lo tanto vamos a fuzzear!";
	char end = 0;
	char i = 0;
	while (end != 8 && *puntero!=0x2F)
	{
		//printf("Introducimos el %c tiene tamayo %d \n" ,*puntero, i);
		match = fuzzingmodificacion2(puntero);
		if (match == TRUE) {
			end = end + 1;
		}
		puntero = puntero + 1;
		i = i + 1;
	}
	std::cout << "Mete los caracteres para conseguir la cadena g;jf\"db\% y vamos a por la primera parte! \n Recuerda que vamos de atrás para delante: jejej\n";
	std::cout << "Introduce Input para la parte 2\n";
	getline(cin, Input2);

	//Input2 = "SmFRdTNk";
	char *Array_Input2 = new char[Input2.length()]; //Creamos array con el tamaño correcto
	strcpy_s(Array_Input2, sizeof(Input2), Input2.c_str());
	char* puntero_diccionario = Array_Diccionario;
	
	/*************************Sacamos los indices************************/
	
	for (i = 0; i < 63; i++)
	{
		indice1 = sacarindice(Array_Input2, puntero_diccionario,i);
		if (indice1 != 0x00) {
			printf("\nindice1 = %x", indice1);
			break;
		}

	}
	for (i = 0; i < 63; i++)
	{
		indice2 = sacarindice(Array_Input2+1, puntero_diccionario, i);
		if (indice2 != 0x00) {
			printf("\nindice2 = %x", indice2);
			break;
		}

	}
	for (i = 0; i < 63; i++)
	{
		indice3 = sacarindice(Array_Input2 +2, puntero_diccionario, i);
		if (indice3 != 0x00) {
			printf("\nindice3 = %x", indice3);
			break;
		}

	}
	for (i = 0; i < 63; i++)
	{
		indice4 = sacarindice(Array_Input2 + 3, puntero_diccionario, i);
		if (indice4 != 0x00) {
			printf("\nindice4 = %x", indice4);
			break;
		}

	}
	for (i = 0; i < 63; i++)
	{
		indice5 = sacarindice(Array_Input2+4, puntero_diccionario, i);
		if (indice5 != 0x00) {
			printf("\nindice5 = %x", indice5);
			break;
		}

	}
	for (i = 0; i < 63; i++)
	{
		indice6 = sacarindice(Array_Input2 + 5, puntero_diccionario, i);
		if (indice6 != 0x00) {
			printf("\nindice6 = %x", indice6);
			break;
		}

	}
	for (i = 0; i < 63; i++)
	{
		indice7 = sacarindice(Array_Input2 +6, puntero_diccionario, i);
		if (indice7 != 0x00) {
			printf("\nindice7 =  %x", indice7);
			break;
		}

	}
	for (i = 0; i < 63; i++)
	{
		indice8 = sacarindice(Array_Input2 + 7, puntero_diccionario, i);
		if (indice8 != 0x00) {
			printf("\nindice8 = %x", indice8);
			break;
		}

	}

	comprobacionIndices(indice1, indice2, indice3, indice4);
	comprobacionIndices(indice5, indice6, indice7, indice8);

	/*
		indice2 = sacarindice(Array_Input2, puntero_diccionario, i);
		indice3 = sacarindice(Array_Input2, puntero_diccionario, i);
		indice4 = sacarindice(Array_Input2, puntero_diccionario, i);
		indice5 = sacarindice(Array_Input2, puntero_diccionario, i);
		indice6 = sacarindice(Array_Input2, puntero_diccionario, i);
		indice7 = sacarindice(Array_Input2, puntero_diccionario, i);
		indice8 = sacarindice(Array_Input2, puntero_diccionario, i);
		*/
}

void comprobacionIndices(char indice1, char indice2, char indice3, char  indice4) {
	char caracter3;
	char caracter2;
	char caracter1;
	for (caracter3 = 0x20; caracter3 < 0x7E; caracter3++)
	{
		//printf("\nPrueba caracter3 = %c", caracter3);
		if ((caracter3 & 0x3F) == indice4) {
			for (char caracter2 = 0x20; caracter2 < 0x7E; caracter2++)
			{
				//printf("\nPrueba caracter2 = %c", caracter2);
				//(input3 >> 6) + 4 * (input2 & 0xF);
				if ((caracter3 >> 6) + 4 * (caracter2 & 0xF) == indice3) {
					for (char caracter1 = 0x20; caracter1 < 0x7E; caracter1++)
					{
						//printf("\nPrueba caracter1 = %c", caracter1);
						//(input2 >> 4) + 16 * (input1 & 3);
						if ((((caracter2 >> 4) + 16 * (caracter1 & 3)) == indice2) && (caracter1 >> 2 == indice1)) {
							printf("\nCaracter = %c", caracter1);
							printf("\nCaracter = %c", caracter2);
							printf("\nCaracter = %c", caracter3);
							break;


						}
					}
					
				}
			}
			
		}
	}
	caracter3 = caracter3 / 64;
	

}





boolean fuzzingmodificacion2(char* array) {
	BYTE salida1;
	
		
	salida1 = *(array) + 1; 
	salida1 = (3 * salida1);
	salida1 = (salida1 / 3);
	salida1 = (salida1 - 7) ^ 0x2A;


	if (salida1 == 0x67 || salida1 == 0x3b || salida1 == 0x6a || salida1 == 0x66 || salida1 == 0x22 || salida1 == 0x64 || salida1 == 0x62 || salida1 == 0x25) {
		printf("\nInput %c", *(array)); // con C, c+1 etc puedo ir controlando los caracteres:
		printf("\nGenera la salida %c", salida1); // con C, c+1 etc puedo ir controlando los caracteres:
		return TRUE;
	}

	else {
		return FALSE;
	}

}





char sacarindice( char* puntero, char* puntero_diccionario, char i) {
	//printf("\nMostramos el Valor que queremos tener %c y el que estamos probando %c y el indice que llevamos %x", *puntero, *(puntero_diccionario+i), i);
	if (*(puntero_diccionario+i) == *puntero) {
		return (i); 

	}
	else {
		return 0x00;
	}
	
	
}