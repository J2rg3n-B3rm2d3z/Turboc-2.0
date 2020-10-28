#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include"vali.h"	/*Libreria de validadcion*/

int AdquirirNumero();

int ObInversion();

void Presentacion();

void main(void)
{
	int Lectura,bolsalir,Seleccion,menu_x,menu_y,Seleccion_x,Seleccion_y,Datos_x,Datos_y,Numeros_x,Numeros_y,x,y;	/*Variables de impresion de menu*/
	int bolNumero,boljuego,Numero,Inversion,bolEnter,D1,D2,D3,Enter,i,j,bolWin,bolColor,Color1,Color2; /*Variable de funcionamiento de menu*/
	
	clrscr();
	
	Seleccion=1; /*Variable de seleccion de opcion de menu*/
	
	/*Posicionamiento de menu*/
	menu_x=3;	
	menu_y=13;
	/*Posicionamiento de la Seleccion*/
	Seleccion_x=menu_x;
	Seleccion_y=menu_y;
	/*Posicionamiento de los datos*/
	Datos_x=51;
	Datos_y=2;
	/*Posicionamiento de los numeros*/
	Numeros_x=menu_x+15;
	Numeros_y=menu_y-7;
	
	 /*Variable de cambio de color en juego*/
	Color1=CYAN;
	Color2=WHITE;
	
	 /*Variables boleanas*/
	bolColor=1;
	bolWin=0;
	bolEnter=0;
	bolsalir=0;
	boljuego=0;
	
	 /*Variables de control de datos*/
	Enter=0;
	D3=0;
	Numero=-1;
	Inversion=0;
	
	 /*Funciones de presentacion*/

	
	/*Inicio de funcionamiento*/
	
	while (bolsalir==0)/*Mientras no sea igual a 0*/
	{
		clrscr();
		
		
		/*
		En el caso del siguiente bucle se usa la variable "Lectura" para verificar que tecla se toco, 
		Lectura tendra un numero del codigo ASCII que equivale al caracter que se tecleo, 
		en el siguiente caso, 13 equivale a que se presione Enter en el teclado.
		*/
		
		while(Lectura!=13)/*Mientras no pulse Enter*/
		{
			
			clrscr();
			
			/*Codigo de imprecion del diseño de la interface*/
			
			/*Codigo de imprecion del diseño de separacion*/
			
			x=1;/*Inicio de impresion en x*/
			y=1;/*Inicio de impresion en y*/
			
			textcolor(RED);/*Se elige el color rojo*/
			
			/*Se usa i para señalar la longitud de la linea*/
			
			for(i=0;i<80;i+=2)
			{
				/*La variable i llega hasta 80, lo que hace una linea de extremo a extremo*/
				gotoxy(x+i,y);/*Se ubica el puntero donde se debe de pintar, x se le suma a i para indicar que lugar pintar*/
				cprintf("%c",177);/*Se usa este caracter para el pintado de la division*/
			}
			
			/*En este caso se le ha sumado dos unidades a i, para que de esa manera se pinte de manera intercalada*/
			
			
			/*Se hace lo mismo que se hizo anteriormente*/
			
			x=1;
			y=1;
			
			for(i=0;i<25;i+=2)
			{
				gotoxy(x,y+i);/*En este caso se suma a y, para crear una linea vertical*/
				cprintf("%c",177);
			}
			
			x=80;
			y=2;
			
			for(i=0;i<24;i+=2)
			{
				gotoxy(x,y+i);
				cprintf("%c",177);
			}
			y=1;
			x=49;
			
			for(i=0;i<22;i+=2)
			{
				gotoxy(x,y+i);
				cprintf("%c",177);
			}
			
			y=22;
			x=2;
			
			for(i=0;i<80;i+=2)
			{
				gotoxy(x+i,y);
				cprintf("%c",177);
			}
			
			y=12;
			x=2;
			
			for(i=0;i<48;i+=2)
			{
				gotoxy(x+i,y);
				cprintf("%c",177);
			}
			
			
			x=1;
			y=1;
			
			/*En este caso se hace lo mismo que antes unicamente en posiciones diferente para rellenar y en color blanco*/
			
			textcolor(WHITE);
			
			for(i=1;i<80;i+=2)
			{
				gotoxy(x+i,y);
				cprintf("%c",177);
			}
			
			x=1;
			y=2;
			
			for(i=0;i<24;i+=2)
			{
				gotoxy(x,y+i);
				cprintf("%c",177);
			}
			
			x=80;
			y=1;
			
			for(i=0;i<24;i+=2)
			{
				gotoxy(x,y+i);
				cprintf("%c",177);
			}
			
			x=49;
			
			for(i=1;i<22;i+=2)
			{
				gotoxy(x,y+i);
				cprintf("%c",177);
			}
			
			y=22;
			x=1;
			
			for(i=0;i<80;i+=2)
			{
				gotoxy(x+i,y);
				cprintf("%c",177);
			}
			
			y=12;
			x=1;
			
			for(i=0;i<48;i+=2)
			{
				gotoxy(x+i,y);
				cprintf("%c",177);
			}
			
			/*Ubicacion de los numeros de la loteria*/
			
			textcolor(LIGHTGRAY);
			gotoxy(Numeros_x,Numeros_y);/*Se ubica en los valores ya declarados anteriormente*/
			if (boljuego==0)cprintf("0");/*Si no se ha jugado aun, se pone 0*/
			else cprintf("%d",D1);		/*En caso contrario se ubica uno de los dos numeros aleatorios*/
			gotoxy(Numeros_x+14,Numeros_y);/*Se hace lo mismo con el otro numero con una separacion ya indicada*/
			if (boljuego==0)cprintf("0");
			else cprintf("%d",D2);
			
			/*Ubicacion del marco para los numeros*/
			
			textcolor(CYAN);
			
			gotoxy(Numeros_x-2,Numeros_y);
			cprintf("%c",186);
			gotoxy(Numeros_x+14+2,Numeros_y);
			cprintf("%c",186);
			gotoxy(Numeros_x-2,Numeros_y-1);
			cprintf("%c",201);
			gotoxy(Numeros_x-2,Numeros_y+1);
			cprintf("%c",200);
			gotoxy(Numeros_x+14+2,Numeros_y-1);
			cprintf("%c",187);
			gotoxy(Numeros_x+14+2,Numeros_y+1);
			cprintf("%c",188);
			
			textcolor(Color1);/*Se colorea segun la variable que tiene color1*/
			
			/*De la misma forma que se hizo anteriormente, se crean las lineas del marco de los numeros*/
			
			for(i=0;i<17;i+=2)
			{
				gotoxy(Numeros_x-1+i,Numeros_y-1);
				cprintf("%c",205);
			
			}
			
			for(i=0;i<17;i+=2)
			{
				gotoxy(Numeros_x-1+i,Numeros_y+1);
				cprintf("%c",205);
			
			}
			
			textcolor(Color2);
			
			for(i=1;i<17;i+=2)
			{
				gotoxy(Numeros_x-1+i,Numeros_y-1);
				cprintf("%c",205);
			
			}
			
			for(i=1;i<17;i+=2)
			{
				gotoxy(Numeros_x-1+i,Numeros_y+1);
				cprintf("%c",205);
			
			}
			
			/*Adecoraciones*/
			
			textcolor(DARKGRAY);
			
			for(i=0;i<23;i++)
			{
				gotoxy(Numeros_x-4+i,Numeros_y-3);
				cprintf("%c",205);
			}
			
			for(i=0;i<23;i++)
			{
				gotoxy(Numeros_x-4+i,Numeros_y+3);
				cprintf("%c",205);
			}
			
			
			/*Escritura del menu*/
			
			textcolor(LIGHTGRAY);
			gotoxy(menu_x,menu_y);
			cprintf("1.Presentacion");
			gotoxy(menu_x,menu_y+2);
			cprintf("2.Adquirir un numero");
			gotoxy(menu_x,menu_y+4);
			cprintf("3.Comenzar a jugar");
			gotoxy(menu_x,menu_y+6);
			cprintf("4.Volver a jugar");
			gotoxy(menu_x,menu_y+8);
			cprintf("5.Salir");
			
			/*Escritura de la indicacion de los datos*/
			gotoxy(Datos_x,Datos_y);
			textcolor(LIGHTGRAY);
			cprintf("Su numero es:");
			gotoxy(Datos_x,Datos_y+4);
			cprintf("La cantidad invertida es:");
			gotoxy(Datos_x,Datos_y+8);
			cprintf("El numero ganador es:");
			gotoxy(Datos_x,Datos_y+12);
			cprintf("Estado del juego:");
			gotoxy(Datos_x,Datos_y+16);
			cprintf("Premio:");
			
			/*Escritura de los datos*/
			gotoxy(Datos_x,Datos_y+2);
			textcolor(CYAN);
			if (Numero==-1)cprintf("");
			else cprintf("%d",Numero);
			gotoxy(Datos_x,Datos_y+4+2);
			if (Inversion==0)cprintf("");
			else cprintf("%d",Inversion);
			gotoxy(Datos_x,Datos_y+8+2);
			if (boljuego==0)cprintf("");
			else cprintf("%d",D3);
			gotoxy(Datos_x,Datos_y+12+2);
			if (boljuego==0)cprintf("");
			else 
			{	
				if(Numero==D3)cprintf("Ganaste!");
				else cprintf("Perdiste");
			}
			gotoxy(Datos_x,Datos_y+16+2);
			if (boljuego==0)cprintf("");
			else 
			{	
				if(Numero==D3)cprintf("%d",Inversion*5);
			}
			/*Escritura del cursor de seleccion*/
			gotoxy(menu_x,Seleccion_y);
			textcolor(CYAN);
			cprintf("%d",Seleccion);
			
			/*Mensaje para el usuario*/
			textcolor(LIGHTGRAY);
			gotoxy(menu_x,menu_y+11);
			cprintf("Usa las direccionales y pulse enter para elegir la opcion.");
			
			gotoxy(menu_x,menu_y+12);
			
			if (bolWin!=0)
			{
				
				if(Numero==D3)
				{
					sound(369.99);
					delay(234);
					sound(587.33);
					delay(234);
					sound(392.00);
					delay(234);
					sound(587.33);
					delay(234);
					sound(440.00);
					delay(234);
					sound(587.33);
					delay(234);
					sound(493.88);
					delay(234);
					sound(587.33);
					delay(234*2);
					nosound();
					
					
				}
				else 
				{
					sound(110.00);
					delay(234);
					sound(87.307);
					delay(234*2);
					nosound();
				}
				
			}
			
			bolWin=0;
			
			Lectura=getch();/*Lee el teclado*/
			
			/*Aumenta o disminuye la opcion de seleccion para indicar cual opcion quiere*/
			
			if((Lectura==72)&&(Seleccion>1))/*Si presiona arriba*/
			{
				Seleccion--;
				Seleccion_y-=2;
				sound(277.18);
				delay(25);
				sound(329.73);
				delay(25);
				nosound();
			}
			else if((Lectura==80)&&(Seleccion<5))/*Si presiona abajo*/
			{
				Seleccion++;
				Seleccion_y+=2;
				sound(329.73);
				delay(25);
				sound(277.18);
				delay(25);
				nosound();
			}
			
			
			
		}
		
		/*Al haber presionado Enter(Romper el bucle)*/
		
		
		switch(Seleccion)
		{
			case 1:
			
			sound(277.18);
			delay(25*5);
			sound(329.73);
			delay(25*5);
			nosound();
			
			Presentacion();
			
			break;
			
			case 2:
			
			sound(277.18);
			delay(25*5);
			sound(329.73);
			delay(25*5);
			nosound();
			
			
			Numero=AdquirirNumero();
			Inversion=ObInversion();
			bolNumero=0;
			boljuego=0;
			
			break;
			
			case 3:
			
			if (Numero!=-1 && bolNumero==0)
			{
				
				sound(277.18);
				delay(25*5);
				sound(329.73);
				delay(25*5);
				nosound();
				
				
				
				gotoxy(menu_x,menu_y+11);
				cprintf("                                                                              ");
				gotoxy(menu_x,menu_y+11);
				cprintf("Pulsa Enter.");
				
				bolNumero=1;
				
			
				while(bolEnter==0)
				{
					textcolor(LIGHTGRAY);
					
					gotoxy(Numeros_x,Numeros_y);

					D1=(rand()%10);

					printf("%d",D1);

					gotoxy(Numeros_x+14,Numeros_y);

					D2=(rand()%10);

					printf("%d",D2);

					sleep(1);
					
					textcolor(Color1);
					
					for(i=0;i<17;i+=2)
					{
						gotoxy(Numeros_x-1+i,Numeros_y-1);
						cprintf("%c",205);
					
					}
					
					for(i=0;i<17;i+=2)
					{
						gotoxy(Numeros_x-1+i,Numeros_y+1);
						cprintf("%c",205);
					
					}
					
					textcolor(Color2);
					
					for(i=1;i<17;i+=2)
					{
						gotoxy(Numeros_x-1+i,Numeros_y-1);
						cprintf("%c",205);
					
					}
					
					for(i=1;i<17;i+=2)
					{
						gotoxy(Numeros_x-1+i,Numeros_y+1);
						cprintf("%c",205);
					
					}
							
					if(bolColor==1)
					{
					Color1=CYAN;
					Color2=WHITE;
						
					}
					else if(bolColor==-1)
					{
					Color1=WHITE;
					Color2=CYAN;
						
					}
					
					while(kbhit())
					{
						Enter=getch();
						if (Enter==13)bolEnter=1;
						
					}
					fflush(stdin);
					
					bolColor*=-1;
					
				}

				D3=(D1*10)+D2;
				bolEnter=0;
				boljuego=1;
				bolWin=1;
				sound(277.18);
				delay(25*5);
				sound(329.73);
				delay(25*5);
				nosound();
				
			}
			
			
			
			break;
			
			case 4:
			
			if(Numero!=-1 && bolNumero==1)
			{
				sound(277.18);
				delay(25*5);
				sound(329.73);
				delay(25*5);
				nosound();
					
				
				gotoxy(menu_x,menu_y+11);
				cprintf("                                                                           ");
				gotoxy(menu_x,menu_y+11);
				cprintf("Pulsa Enter.");
		
			while(bolEnter==0)
			{
				
				gotoxy(Numeros_x,Numeros_y);

				D1=(rand()%10);

				printf("%d",D1);

				gotoxy(Numeros_x+14,Numeros_y);

				D2=(rand()%10);

				printf("%d",D2);

				sleep(1);
				
				textcolor(Color1);
					
					for(i=0;i<17;i+=2)
					{
						gotoxy(Numeros_x-1+i,Numeros_y-1);
						cprintf("%c",205);
					
					}
					
					for(i=0;i<17;i+=2)
					{
						gotoxy(Numeros_x-1+i,Numeros_y+1);
						cprintf("%c",205);
					
					}
					
					textcolor(Color2);
					
					for(i=1;i<17;i+=2)
					{
						gotoxy(Numeros_x-1+i,Numeros_y-1);
						cprintf("%c",205);
					
					}
					
					for(i=1;i<17;i+=2)
					{
						gotoxy(Numeros_x-1+i,Numeros_y+1);
						cprintf("%c",205);
					
					}
							
					if(bolColor==1)
					{
					Color1=CYAN;
					Color2=WHITE;
						
					}
					else if(bolColor==-1)
					{
					Color1=WHITE;
					Color2=CYAN;
						
					}
				
				while(kbhit())
				{
					Enter=getch();
					if (Enter==13)bolEnter=1;
					
				}
				fflush(stdin);
				
				bolColor*=-1;
				
			}
			

			D3=(D1*10)+D2;
			bolEnter=0;
			boljuego=1;
			bolWin=1;
			
				sound(277.18);
				delay(25*5);
				sound(329.73);
				delay(25*5);
				nosound();
			}
			
			break;
			
			case 5:
			
			sound(277.18);
			delay(25*5);
			sound(329.73);
			delay(25*5);
			nosound();
			
			
			gotoxy(menu_x,menu_y+11);
			cprintf("                                                                           ");
			gotoxy(menu_x,menu_y+11);
			cprintf("Saliendo...");
			bolsalir=1;
			getch();
				
			break;
		}
		/*if(Seleccion==5)*/
	
	
		
		
	
	
	
		Lectura=0;
	}
	
}

int AdquirirNumero()
{
	int Retorno;
	clrscr();
	gotoxy(27,10);
	printf("Elija un numero del 0-99\n");
	gotoxy(35,12);
	Retorno = intValidacion();

	while(Retorno<0 || Retorno>99)
	{
	clrscr();
	gotoxy(32,8);
	printf("Valor invalido\n");
	gotoxy(27,11);
	printf("Elija un numero del 0-99\n");
	gotoxy(35,13);
	Retorno = intValidacion();
	}
	
	sound(277.18);
	delay(25*5);
	sound(329.73);
	delay(25*5);
	nosound();
	

	return Retorno;

}

int ObInversion()
{
	int Retorno;
	clrscr();
	gotoxy(20,10);
	printf("Escriba la inversion que desea, no mayor a 999\n");
	gotoxy(33,12);
	Retorno = intValidacion();

	while(Retorno<1 || Retorno>999)
	{
	clrscr();
	gotoxy(32,8);
	printf("Valor invalido\n");
	gotoxy(20,11);
	printf("Escriba la inversion que desea, no mayor a 999\n");
	gotoxy(33,13);
	Retorno = intValidacion();
	}
	
	sound(277.18);
	delay(25*5);
	sound(329.73);
	delay(25*5);
	nosound();
	

	return Retorno;

}

void Presentacion()
{
int x,y,Margin,i;
Margin=10;
x=1;
y=1;

clrscr();


textcolor(RED);

for(i=0;i<80;i+=2)
{
				
	gotoxy(x+i,y);
	cprintf("%c",177);
}

x=1;
y=25;

for(i=0;i<80;i+=2)
{
				
	gotoxy(x+i,y);
	cprintf("%c",177);
}

x=1;
y=1;
			
for(i=0;i<25;i+=2)
{
	gotoxy(x,y+i);
	cprintf("%c",177);
}

x=80;
y=2;
			
for(i=0;i<23;i+=2)
{
	gotoxy(x,y+i);
	cprintf("%c",177);
}

textcolor(WHITE);
x=2;
y=1;

for(i=0;i<78;i+=2)
{
				
	gotoxy(x+i,y);
	cprintf("%c",177);
}

x=2;
y=25;

for(i=0;i<78;i+=2)
{
				
	gotoxy(x+i,y);
	cprintf("%c",177);
}

x=1;
y=2;
			
for(i=0;i<23;i+=2)
{
	gotoxy(x,y+i);
	cprintf("%c",177);
}

x=80;
y=1;
			
for(i=0;i<23;i+=2)
{
	gotoxy(x,y+i);
	cprintf("%c",177);
}







x=6+Margin;
y=3;

gotoxy(x,y);
textcolor(WHITE);
cprintf("Universidad Nacional de Ingenieria.");
gotoxy(x,y+2);
cprintf("Facultad de Electronica y Computacion.");
gotoxy(x,y+4);
textcolor(LIGHTGRAY);
cprintf("1M1-CO.");
gotoxy(x,y+6);
cprintf("Loteria.");
gotoxy(x,y+8);
cprintf("Integrantes:");
gotoxy(x,y+10);
textcolor(CYAN);
cprintf("Jurgen Francisco Bermudez Picado 2020-0290U");
gotoxy(x,y+12);
cprintf("Shania Joshua Levy Omier 2020-0494U");
gotoxy(x,y+14);
cprintf("Milton Agustin Salazar Roque 2020-0456U");
gotoxy(x,y+16);
textcolor(LIGHTGRAY);
cprintf("Docente:");
textcolor(CYAN);
gotoxy(x,y+18);
cprintf("Nelson Alejandro Barrios Gonzales");
gotoxy(x,y+20);
textcolor(LIGHTGRAY);
cprintf("Presione cualquier tecla para seguir.");


getch();


sound(277.18);
delay(25*5);
sound(329.73);
delay(25*5);
nosound();


	
	
	
	
	






	
}


