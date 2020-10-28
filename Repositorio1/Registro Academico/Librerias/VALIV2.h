#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

/*Codigo hecho por Jurgen Francisco Bermudez Picado 1M1-CO*/

char obte1();/*Obtencion del caracter unicamente del primer Byte*/
char obte2();/*Obtencion del caracter unicamente del segundo Byte, si hay*/
char obte3();/*Obtencion del caracter de ambos byte si se puede*/

/*Obteción de enteros Validados, Se le pide que escriba en pantalla un entero(Validado con el rango capaz de almacenar)y retorna ese entero*/
/*La variable se le asigna esta funcion*/

int intValidacion();					/*Para numeros enteros, */
unsigned int unintValidacion();			/*Para numeros enteros sin signo*/
long int lintValidacion();				/*Para numeros enteros largos*/
unsigned long int unlintValidacion();	/*Para numeros enteros largos sin signo*/

/*Obtención de cadena de caracteres Validados*/
/*La cadena de caracteres se coloca como primer parametro*/
/*En el segundo parametro se coloca 0 para que sea visible lo que se escribe, o un numero diferente de 0 para no verlo.*/
/*En el tercer parametro se coloca la longitud Maxima de la cadena que se indico al momento de declararse.*/

void SoloCarValidacion(char*Cadena,int Ver,int Longitud);		/*Para cadenas de caracteres unicamente de letras*/
void CarEspacioValidacion(char*Cadena2,int Ver,int Longitud);	/*Para cadenas de caracteres con letras y espacios*/
void CarNumValidacion(char*Cadena3,int Ver,int Longitud);		/*Para cadenas de caracteres con letras y numeros*/
void CarNumSigValidacion(char*Cadena4,int Ver,int Longitud);	/*Para cadenas de caracteres con letras, numeros y simbolo*/

/*Obtencion de variables flotante*/

double doubleValidacion();


int intValidacion()
{
	char*LecturaNumero;
	int Lector,i,Numero,largo,bolretorno;
	
	largo=5;
	bolretorno=0;
	
	LecturaNumero=calloc(10,sizeof(char));
	
	i=0;
	
	while ((bolretorno==0)||(LecturaNumero[0]==NULL))
	{
		
		Lector=obte1();
		if(/*isdigit (Lector)*/ Lector>='0' && '9'>=Lector)
		{
			if(i<largo)
			{
				printf("%c",Lector);
				LecturaNumero[i]=Lector;
				i++;
				
			}
			bolretorno=0;
		}
		if (Lector==8)
		{
			if(i>0)
			{
				
				printf("%c",Lector);
				printf("%c",0);
				printf("%c",Lector);
			
				LecturaNumero[i-1]=NULL;
				
				i--;
			}
			bolretorno=0;
		}
		if (Lector==13)
		{	
				
			if (strlen(LecturaNumero)<largo)bolretorno=1;
			else
			{
				if (LecturaNumero[0]<'3')bolretorno=1;
				else if(LecturaNumero[0]=='3')
				{
					if(LecturaNumero[1]<'2')bolretorno=1;
					else if(LecturaNumero[1]=='2')
					{
						if(LecturaNumero[2]<'7')bolretorno=1;
						else if(LecturaNumero[2]=='7')
						{
							
							if(LecturaNumero[3]<'6')bolretorno=1;
							else if(LecturaNumero[3]=='6')
							{
								if(LecturaNumero[4]<='7')
								{
									bolretorno=1;
								}
							}
						}	
					}
				}
			}
			
		}
		
		fflush(stdin);
	}
	
	printf("\n");
	
	Numero=atoi(LecturaNumero);
	
	free(LecturaNumero);
	
	return Numero;
}

long int lintValidacion()
{
	char*LecturaNumero;
	int Lector,i,largo,bolretorno;
	int long Numero;
	largo=10;
	bolretorno=0;
	
	LecturaNumero=calloc(15,sizeof(char));
	
	i=0;
	
	while ((bolretorno==0)||(LecturaNumero[0]==NULL))
	{
		
		Lector=obte1();
		if(/*isdigit (Lector)*/ Lector>='0' && '9'>=Lector)
		{
			if(i<largo)
			{
				printf("%c",Lector);
				LecturaNumero[i]=Lector;
				i++;
				
			}
			bolretorno=0;
		}
		if (Lector==8)
		{
			if(i>0)
			{
				
				printf("%c",Lector);
				printf("%c",0);
				printf("%c",Lector);
			
				LecturaNumero[i-1]=NULL;
				
				i--;
			}
			bolretorno=0;
		}
		if (Lector==13)
		{	
				
			if (strlen(LecturaNumero)<largo)bolretorno=1;
			else
			{
				if (LecturaNumero[0]<'2')bolretorno=1;
				else if(LecturaNumero[0]=='2')
				{
					if(LecturaNumero[1]<'1')bolretorno=1;
					else if(LecturaNumero[1]=='1')
					{
						if(LecturaNumero[2]<'4')bolretorno=1;
						else if(LecturaNumero[2]=='4')
						{
							if(LecturaNumero[3]<'7')bolretorno=1;
							else if(LecturaNumero[3]=='7')
							{
								if(LecturaNumero[4]<'4')bolretorno=1;
								else if(LecturaNumero[4]=='4')
								{
									if(LecturaNumero[5]<'8')bolretorno=1;
									else if(LecturaNumero[5]=='8')
									{
										if(LecturaNumero[6]<'3')bolretorno=1;
										else if(LecturaNumero[6]=='3')
										{
											if(LecturaNumero[7]<'6')bolretorno=1;
											else if(LecturaNumero[7]=='6')
											{
												if(LecturaNumero[8]<'4')bolretorno=1;
												else if(LecturaNumero[8]=='4')
												{
													if(LecturaNumero[9]<='7')
													{
														bolretorno=1;
													}
												
												}
											}
										}
									}
								}	
								
							}
						}	
					}
				}
			}
			
		}
		
		fflush(stdin);
	}
	
	printf("\n");
	
	Numero=atoi(LecturaNumero);

	free(LecturaNumero);
	
	return Numero;
}

unsigned int unintValidacion()
{
	char*LecturaNumero;
	int Lector,i,Numero,largo,bolretorno;
	
	largo=5;
	bolretorno=0;
	
	LecturaNumero=calloc(10,sizeof(char));
	
	i=0;
	
	while ((bolretorno==0)||(LecturaNumero[0]==NULL))
	{
		
		Lector=obte1();
		if(/*isdigit (Lector)*/ Lector>='0' && '9'>=Lector)
		{
			if(i<largo)
			{
				printf("%c",Lector);
				LecturaNumero[i]=Lector;
				i++;
				
			}
			bolretorno=0;
		}
		if (Lector==8)
		{
			if(i>0)
			{
				
				printf("%c",Lector);
				printf("%c",0);
				printf("%c",Lector);
			
				LecturaNumero[i-1]=NULL;
				
				i--;
			}
			bolretorno=0;
		}
		if (Lector==13)
		{	
				
			if (strlen(LecturaNumero)<largo)bolretorno=1;
			else
			{
				if (LecturaNumero[0]<'6')bolretorno=1;
				else if(LecturaNumero[0]=='6')
				{
					if(LecturaNumero[1]<'5')bolretorno=1;
					else if(LecturaNumero[1]=='5')
					{
						if(LecturaNumero[2]<'5')bolretorno=1;
						else if(LecturaNumero[2]=='5')
						{
							
							if(LecturaNumero[3]<'3')bolretorno=1;
							else if(LecturaNumero[3]=='3')
							{
								if(LecturaNumero[4]<='5')
								{
									bolretorno=1;
								}
							}
						}	
					}
				}
				
			}

		}
		
		fflush(stdin);
	}
	
	printf("\n");
	
	Numero=atoi(LecturaNumero);
	
	free(LecturaNumero);
	
	return Numero;
}

unsigned long int unlintValidacion()
{
	char*LecturaNumero;
	int Lector,i,largo,bolretorno;
	unsigned long int Numero;
	largo=10;
	bolretorno=0;
	
	LecturaNumero=calloc(15,sizeof(char));
	
	i=0;
	
	while ((bolretorno==0)||(LecturaNumero[0]==NULL))
	{
		
		Lector=obte1();
		if(/*isdigit (Lector)*/ Lector>='0' && '9'>=Lector)
		{
			if(i<largo)
			{
				printf("%c",Lector);
				LecturaNumero[i]=Lector;
				i++;
				
			}
			bolretorno=0;
		}
		if (Lector==8)
		{
			if(i>0)
			{
				
				printf("%c",Lector);
				printf("%c",0);
				printf("%c",Lector);
			
				LecturaNumero[i-1]=NULL;
				
				i--;
			}
			bolretorno=0;
		}
		if (Lector==13)
		{	
				
			if (strlen(LecturaNumero)<largo)bolretorno=1;
			else
			{
				if (LecturaNumero[0]<'4')bolretorno=1;
				else if(LecturaNumero[0]=='4')
				{
					if(LecturaNumero[1]<'2')bolretorno=1;
					else if(LecturaNumero[1]=='2')
					{
						if(LecturaNumero[2]<'9')bolretorno=1;
						else if(LecturaNumero[2]=='9')
						{
							if(LecturaNumero[3]<'4')bolretorno=1;
							else if(LecturaNumero[3]=='4')
							{
								if(LecturaNumero[4]<'9')bolretorno=1;
								else if(LecturaNumero[4]=='9')
								{
									if(LecturaNumero[5]<'6')bolretorno=1;
									else if(LecturaNumero[5]=='6')
									{
										if(LecturaNumero[6]<'7')bolretorno=1;
										else if(LecturaNumero[6]=='7')
										{
											if(LecturaNumero[7]<'2')bolretorno=1;
											else if(LecturaNumero[7]=='2')
											{
												if(LecturaNumero[8]<'9')bolretorno=1;
												else if(LecturaNumero[8]=='9')
												{
													if(LecturaNumero[9]<='5')
													{
														bolretorno=1;
													}
												
												}
											}
										}
									}
								}	
								
							}
						}	
					}
				}
				
				
			}
			
		}
		
		fflush(stdin);
	}
	
	printf("\n");
	
	Numero=atol(LecturaNumero);
	
	free(LecturaNumero);
	
	return Numero;
}

void SoloCarValidacion(char*Cadena,int Ver,int Longitud)
{
	
	int Lector,i,largo,bolretorno;
	
	fflush(stdin);
	
	largo=(Longitud-1);
	
	bolretorno=0;
	
	i=0;
	
	while ((bolretorno==0)||(Cadena[0]==NULL))
	{
		
		Lector=obte1();
		if(/*isalpha(Lector)*/ (65<=Lector && 90>=Lector ) ||(97<=Lector && 122>=Lector ))/*Cambiado a rangos por problemas de Teclado en español*/
		{
			if(i<largo)
			{
				if(Ver==0)
				{
					printf("%c",Lector);
					Cadena[i]=Lector;
					i++;
				}
				else
				{
					printf("*");
					Cadena[i]=Lector;
					i++;
					
				}
			}
			bolretorno=0;
		}
		if (Lector==8)
		{
			if(i>0)
			{
				
				printf("%c",Lector);
				printf("%c",0);
				printf("%c",Lector);
			
				Cadena[i-1]=NULL;
				
				i--;
			}
			bolretorno=0;
		}
		if (Lector==13)
		{	
				Cadena[i]='\0';
				bolretorno=1;
			
		}
		
		fflush(stdin);
	}
	
	printf("\n");
	
	return;
	
}

void CarEspacioValidacion(char*Cadena2,int Ver,int Longitud)
{
	
	int Lector,i,largo,bolretorno;
	
	fflush(stdin);
	
	largo=(Longitud-1);
	
	bolretorno=0;
	
	i=0;
	
	while ((bolretorno==0)||(Cadena2[0]==NULL))
	{
		
		Lector=obte1();
		if(/*isalpha(Lector)*/(65<=Lector && 90>=Lector ) ||(97<=Lector && 122>=Lector )||(Lector==32))
		{
			if(i<largo)
			{
				if(Ver==0)
				{
					printf("%c",Lector);
					Cadena2[i]=Lector;
					i++;
				}
				else
				{
					printf("*");
					Cadena2[i]=Lector;
					i++;
					
				}
			}
			bolretorno=0;
		}
		if (Lector==8)
		{
			if(i>0)
			{
				
				printf("%c",Lector);
				printf("%c",0);
				printf("%c",Lector);
			
				Cadena2[i-1]=NULL;
				
				i--;
			}
			bolretorno=0;
		}
		if (Lector==13)
		{	
				Cadena2[i]='\0';
				bolretorno=1;
			
		}
		
		fflush(stdin);
	}
	
	printf("\n");
	
	return;
	
}

void CarNumValidacion(char*Cadena3,int Ver,int Longitud)
{
	
	int Lector,i,largo,bolretorno;
	
	fflush(stdin);
	
	largo=(Longitud-1);
	
	bolretorno=0;
	
	i=0;
	
	while ((bolretorno==0)||(Cadena3[0]==NULL))
	{
		
		Lector=obte1();
		if(isalnum(Lector))
		{
			if(i<largo)
			{
				if(Ver==0)
				{
					printf("%c",Lector);
					Cadena3[i]=Lector;
					i++;
				}
				else
				{
					printf("*");
					Cadena3[i]=Lector;
					i++;
					
				}
			}
			bolretorno=0;
		}
		if (Lector==8)
		{
			if(i>0)
			{
				
				printf("%c",Lector);
				printf("%c",0);
				printf("%c",Lector);
			
				Cadena3[i-1]=NULL;
				
				i--;
			}
			bolretorno=0;
		}
		if (Lector==13)
		{	
				Cadena3[i]='\0';
				bolretorno=1;
			
		}
		
		fflush(stdin);
	}
	
	printf("\n");
	
	return;
	
	
}

void CarNumSigValidacion(char*Cadena4,int Ver,int Longitud)
{
	
	int Lector,i,largo,bolretorno;
	
	fflush(stdin);
	
	largo=(Longitud-1);
	
	bolretorno=0;
	
	i=0;
	
	while ((bolretorno==0)||(Cadena4[0]==NULL))
	{
		
		Lector=obte1();
		if(isgraph(Lector))
		{
			if(i<largo)
			{
				if(Ver==0)
				{
					printf("%c",Lector);
					Cadena4[i]=Lector;
					i++;
				}
				else
				{
					printf("*");
					Cadena4[i]=Lector;
					i++;
					
				}
			}
			bolretorno=0;
		}
		if (Lector==8)
		{
			if(i>0)
			{
				
				printf("%c",Lector);
				printf("%c",0);
				printf("%c",Lector);
			
				Cadena4[i-1]=NULL;
				
				i--;
			}
			bolretorno=0;
		}
		if (Lector==13)
		{	
				Cadena4[i]='\0';
				bolretorno=1;
			
		}
		
		fflush(stdin);
	}
	
	printf("\n");
	
	return;
	
	
	
}

double doubleValidacion()
{
	char*LecturaNumero;
	int Lector,i,largo,bolretorno,bolpunto;
	double Numero;
	
	largo=11;
	bolretorno=0;
	bolpunto=0;
	LecturaNumero=calloc(15,sizeof(char));
	
	i=0;
	
	while ((bolretorno==0)||(LecturaNumero[0]==NULL))
	{
		
		Lector=obte1();
		if(/*isdigit (Lector)*/ Lector>='0' && '9'>=Lector)
		{
			if(i<largo)
			{
				printf("%c",Lector);
				LecturaNumero[i]=Lector;
				i++;
				
			}
			bolretorno=0;
		}
		if ((Lector==46)&&(bolpunto==0))
		{
			if(i<largo)
			{
				printf("%c",Lector);
				LecturaNumero[i]=Lector;
				i++;
				
			}
			bolpunto=1;
			bolretorno=0;
		}
		if (Lector==8)
		{
			if(i>0)
			{
				
				printf("%c",Lector);
				printf("%c",0);
				printf("%c",Lector);
				
				if(LecturaNumero[i-1]==46)bolpunto=0;
				
				LecturaNumero[i-1]=NULL;
				
				i--;
			}
			bolretorno=0;
		}
		if (Lector==13)
		{	
	
			bolretorno=1;	
			
		}
		
		fflush(stdin);
	}
	
	printf("\n");

	Numero=atof(LecturaNumero);
	
	free(LecturaNumero);
	
	return Numero;
	

}

char obte1()
{
	char a, b;
	
	fflush(stdin);
	
	a=getch();
	
	if(a==0)
	{
		b=getch();
	}
	
	return a;
	
}

char obte2()
{
	char a, b;
	
	fflush(stdin);
	
	a=getch();
	
	if(a==0)
	{
		b=getch();
		return b;
	}
	else return 0;
	
}

char obte3()
{
	char a, b;
	
	fflush(stdin);
	
	a=getch();
	
	if(a==0)
	{
		b=getch();
		return b;
	}
	else return a;
}

