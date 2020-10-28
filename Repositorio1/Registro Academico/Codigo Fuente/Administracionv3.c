#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<dos.h>
#include<ctype.h>
#include"recursos.h"
#include"valiv2.h"


#define MAX 11
#define MARGIN 13
#define PROLENOM 23
#define MAXCURSOS 9
#define ALU 10

struct Data
{
	char Nombres[PROLENOM];
	char Apellidos[PROLENOM];
	char Carnet[MAX];
	int Cursos[MAXCURSOS];
	int bolCursos[MAXCURSOS];

};

#include"adlib1.h"


void Menu(int Usuario);/*Funcion Para el menu*/

void Agregar(int Seccion);/*Funcion Agregar*/

void Actualizar(int indice);/*Funcion para actualizar*/

void Ayuda(void);/*Funcion para explicar el funcionamiento*/

void Mostrar(int Seccion);/*Funcion para Mostrar los datos obtenido*/

void Lista(int Seccion, int bol);/*Funcion para Lista de Alumnos*/

void Busqueda(int Seccion);/*Funcion para Buscar Registros*/

void Eliminar(int indice,int Seccion);/*Funcion para Eliminar*/

void BusquedaNC(int bol,int Seccion);


struct Data Alumno[20];

int Indi_Alu1=0,Indi_Alu2=ALU,NumCar=0;



void main (void)
{
	int Acc,x,y,a,b;
	FILE *fichero,*Indices;
	
	x=6+MARGIN;
	y=8;
	
	Logo();
	Carga();
	
	textcolor(WHITE);
	
	clrscr();
	
	fflush(stdin);

	Acc=Acceso();
	
	if (Acc==0)
	{
		clrscr();
		
		Dibujo2(4,12);
		textcolor(WHITE);
		
		gotoxy(40-13,y-6);
		cprintf("REGISTRO ACADEMICO UNI-RUSB");
		gotoxy(40-7,y-4);
		cprintf("ACCESO DENEGADO");
		gotoxy(x,y+14);
		delay(1000);
		
	}
	else
	{
		fichero = fopen( "C:\\FileC\\ALUMNOS.dat", "rb" );
		
		if(fichero)
		{
			clrscr();
			
			Dibujo2(2,10);
			textcolor(WHITE);
			
			gotoxy(40-13,y-6);
			cprintf("REGISTRO ACADEMICO UNI-RUSB");
			gotoxy(40-16,y-4);
			cprintf("LEYENDO DATOS DE lOS REGISTROS...");
			fread(Alumno, sizeof(struct Data),20,fichero);
			delay(500);
			rewind(fichero);

			
			if(!fclose(fichero))
			{
				clrscr();
				
				Dibujo2(2,10);
				textcolor(WHITE);
				
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-4,y-4);
				cprintf("CARGANDO...");
				delay(500);

			} 
			else
			{
				clrscr();
				
				Dibujo2(2,10);
				textcolor(WHITE);
				
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-8,y-4);
				cprintf("ERROR DE LECTURA");
				delay(500);

			}
		}
		
		Indices=fopen("C:\\FileC\\INDICES.txt","r");
		
		if(Indices)
		{
			
			clrscr();
			
			Dibujo2(2,10);
			textcolor(WHITE);
		
			gotoxy(40-13,y-6);
			cprintf("REGISTRO ACADEMICO UNI-RUSB");
			gotoxy(40-10,y-4);
			cprintf("CARGANDO OTROS DATOS...");
			fscanf(Indices,"%d %d %d",&Indi_Alu1,&Indi_Alu2,&NumCar);
			delay(500);
			rewind(Indices);
		
			if(!fclose(Indices))
			{
				clrscr();
				
				Dibujo2(2,10);
				textcolor(WHITE);
				
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-6,y-4);
				cprintf("CARGA EXITOSA...");
				delay(500);
				gotoxy(40-6,y-4);
				cprintf("                ");
			} 
			else
			{
				clrscr();
				
				Dibujo2(2,10);
				textcolor(WHITE);
				
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-7,y-4);
				cprintf("ERROR AL CARGAR.");
				delay(500);


			}
	
		}
		
		Menu(Acc);
	
		clrscr();
		
		fichero = fopen( "C:\\FileC\\ALUMNOS.dat", "wb" );
		
		if(fichero)
		{
			rewind(fichero);
			clrscr();
			
			Dibujo2(2,10);
			textcolor(WHITE);
			
			gotoxy(40-13,y-6);
			cprintf("REGISTRO ACADEMICO UNI-RUSB");
			gotoxy(40-16,y-4);
			cprintf("ESCRIBIENDO DATOS DE lOS REGISTROS");
			fwrite( Alumno, sizeof(struct Data),20, fichero);
			delay(500);
		
			
			
			if(!fclose(fichero))
			{
				clrscr();
				
				Dibujo2(2,10);
				textcolor(WHITE);
				
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-5,y-4);
				cprintf("ESCRIBIENDO...");
				delay(500);
				
			} 
			else
			{
				clrscr();
				
				Dibujo2(2,10);
				textcolor(WHITE);
				
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-10,y-4);
				cprintf("ERROR AL ESCRIBIR...");
				delay(500);
				

			}
			
		}
		
		Indices=fopen("C:\\FileC\\INDICES.txt","w");
		
		if(Indices)
		{
			
			clrscr();
			
			Dibujo2(2,10);
			textcolor(WHITE);
			
			gotoxy(40-13,y-6);
			cprintf("REGISTRO ACADEMICO UNI-RUSB");
			gotoxy(40-11,y-4);
			cprintf("ESCRIBIENDO OTROS DATOS");
			delay(500);
			fprintf(Indices,"%d %d %d",Indi_Alu1,Indi_Alu2,NumCar);
			rewind(Indices);
		
			
			if(!fclose(Indices))
			{
				clrscr();
				
				Dibujo2(2,10);
				textcolor(WHITE);
				
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-8,y-4);
				cprintf("ESCRITURA EXITOSA...");
				delay(500);
				
			} 
			else
			{
				clrscr();
				
				Dibujo2(2,10);
				textcolor(WHITE);
				
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-8,y-4);
				cprintf("ERROR AL ESCRIBIR...");
				delay(500);
				

			}
		}
	}
	
	clrscr();
	
	Dibujo2(2,10);
	textcolor(WHITE);
	
	gotoxy(40-13,y-6);
	cprintf("REGISTRO ACADEMICO UNI-RUSB");
	gotoxy(40-4,y-4);
	cprintf("SALIENDO...");
	delay(1000);
	

}

void Menu(int Usuario)
{
	int Seleccion_y,x,y,a,b;
	int Lectura1,Lectura2,bolSalir,Seleccion,Clase;

	x=40-15;
	y=8;

	bolSalir=0;

	Clase=1;

	Seleccion=1;
	Seleccion_y=y;
	Lectura1=0;
	clrscr();

	textcolor(WHITE);

	while(bolSalir==0)
	{
		
			/*clrscr();*/
			
			Dibujo2(1,9);
			
			for(b=0;b<=40;b+=2)
			{
			
				for(a=y;a<=25-b;a++)
				{
					gotoxy(20-b,a+b);
					cprintf("%c",186);
				}
				
			}
			for(b=0;b<=40;b+=2)
			{
				for(a=y;a<=25-b;a++)
				{
					gotoxy(60+b,a+b);
					cprintf("%c",186);
				}
			}
			
			textcolor(WHITE);
			gotoxy(40-13,y-6);
			cprintf("REGISTRO ACADEMICO UNI-RUSB");
			gotoxy(40-11,y-4);
			cprintf("MENU PRINCIPAL - ");
			
			gotoxy(40-11+17,y-4);
			if(Clase==1)
			{
			textcolor(10);				
			cprintf("1M1-CO");
			}
			else if (Clase==-1)
			{	
			textcolor(11);
			cprintf("1M2-CO");
			}
			textcolor(WHITE);
			if(Usuario==2)
			{
				
				gotoxy(x,y);
				cprintf("  Cambiar de Seccion");
				gotoxy(x,y+2);
				cprintf("  Agregar");
				gotoxy(x,y+4);
				cprintf("  Buscar");
				gotoxy(x,y+6);
				cprintf("  Actualizar");
				gotoxy(x,y+8);
				cprintf("  Eliminar");
				gotoxy(x,y+10);
				cprintf("  Mostrar");
				gotoxy(x,y+12);
				cprintf("  Ayuda");
				gotoxy(x,y+14);
				cprintf("  Salir");
			}
			else
			{
				gotoxy(x,y);
				cprintf("  Cambiar de Seccion");
				gotoxy(x,y+2);
				cprintf("  Agregar");
				gotoxy(x,y+4);
				cprintf("  Buscar");
				gotoxy(x,y+6);
				cprintf("  Actualizar");
				gotoxy(x,y+8);
				cprintf("  Mostrar");
				gotoxy(x,y+10);
				cprintf("  Ayuda");
				gotoxy(x,y+12);
				cprintf("  Salir");	
			}
			
			/*gotoxy(x,y+16);
			cprintf("%d",Indi_Alu1);*/
		while(Lectura1!=13)
		{
			gotoxy(x-2,Seleccion_y);
			cprintf("%c",62);

			gotoxy(1,25);

			Lectura1=getch();
			if(Lectura1==0)Lectura2=getch();



			if((Lectura2==72)&&(Seleccion>1))
			{
				gotoxy(x-2,Seleccion_y);
				cprintf(" ");
				if(Usuario==2)
					Seleccion--;
				else
				{
					if(Seleccion==6)
					{
						Seleccion-=2;
					}
					else
						Seleccion--;
				}
				Seleccion_y-=2;
				
			}
			else if((Lectura2==80)&&(Seleccion<8))
			{
				gotoxy(x-2,Seleccion_y);
				cprintf(" ");
				if(Usuario==2)
					Seleccion++;
				else
				{
					if(Seleccion==4)
					{
						Seleccion+=2;
					}
					else
						Seleccion++;
				}
				Seleccion_y+=2;
			}
			Lectura2=0;
			
		
		}
		
		switch(Seleccion)
		{
			
			case 1:
			Clase*=-1;
			break;
		
			case 2:
			Agregar(Clase);
			clrscr();
			break;
			
			case 3:
			if((Indi_Alu1>0 && Clase==1)||(Indi_Alu2>ALU && Clase==-1))
			{
				Busqueda(Clase);
				clrscr();
			}
			break;
			
			case 4:
			if((Indi_Alu1>0 && Clase==1)||(Indi_Alu2>ALU && Clase==-1))
			{
				Lista(Clase,0);
				clrscr();
			}
			break;
			
			case 5:
			if((Indi_Alu1>0 && Clase==1)||(Indi_Alu2>ALU && Clase==-1))
			{
				Lista(Clase,1);
				clrscr();
			}
			break;
			
			case 6:
			if((Indi_Alu1>0 && Clase==1)||(Indi_Alu2>ALU && Clase==-1))
			{
				Mostrar(Clase);
				clrscr();
			}
			break;
			
			case 7:
			Ayuda();
			clrscr();
			break;
			
			case 8:
			bolSalir=1;
			clrscr();
			break;
		
		}
		Lectura1=0;
		
	}
	
}

void Agregar(int Seccion)
{
	int x,y,Lectura1,Lectura2,Seleccion_x,Seleccion,i,NomVali,Esp;
	clrscr();
	x=40-15;
	y=8;
	Seleccion_x=40-12-1;
	Seleccion=1;
	Lectura1=0;
	Esp=0;
	
	textcolor(WHITE);
	
	if(Seccion==1)
	{
		
		while(Seleccion!=2 && Indi_Alu1<ALU)
		{
				NomVali=0;
				clrscr();
				
				Dibujo2(3,11);
				
				textcolor(WHITE);
				
				Seleccion=1;
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-3,y-4);
				cprintf("AGREGAR");
				
				
				do
				{
					NomVali=0;
					Esp=0;
					gotoxy(x,y);
					cprintf("Ingrese los nombres del alumno:");
					gotoxy(x,y+2);
					CarEspacioValidacion(Alumno[Indi_Alu1].Nombres,0,PROLENOM);
					
					if(Alumno[Indi_Alu1].Nombres[0]==' ')
						NomVali++;
					
					for(i=0;i<strlen(Alumno[Indi_Alu1].Nombres);i++)
					{
						if(Alumno[Indi_Alu1].Nombres[i]==' ' && Alumno[Indi_Alu1].Nombres[i+1]==' ')
							NomVali++;
						
						if(Alumno[Indi_Alu1].Nombres[i]==' ')
							Esp++;
					}
					
					if(Esp>1)
						NomVali++;
					
					if(Alumno[Indi_Alu1].Nombres[strlen(Alumno[Indi_Alu1].Nombres)-1]==' ')
						NomVali++;

					if(NomVali!=0)
					{
						gotoxy(x,y+2);
						cprintf("                           ");
					}
					
				}
				while(NomVali!=0);
				
				
				do
				{
					NomVali=0;
					Esp=0;
					gotoxy(x,y+4);
					cprintf("Ingrese los apellidos del alumno:");
					gotoxy(x,y+6);
					CarEspacioValidacion(Alumno[Indi_Alu1].Apellidos,0,PROLENOM);
				
					if(Alumno[Indi_Alu1].Apellidos[0]==' ')
						NomVali++;
					
					for(i=0;i<strlen(Alumno[Indi_Alu1].Apellidos);i++)
					{
						if(Alumno[Indi_Alu1].Apellidos[i]==' ' && Alumno[Indi_Alu1].Apellidos[i+1]==' ')
							NomVali++;
						
						if(Alumno[Indi_Alu1].Apellidos[i]==' ')
							Esp++;
						
					}
					
					if(Esp!=1)
						NomVali++;
					
					if(Alumno[Indi_Alu1].Apellidos[strlen(Alumno[Indi_Alu1].Apellidos)-1]==' ')
						NomVali++;
					
					if(NomVali!=0)
					{
						gotoxy(x,y+6);
						cprintf("                           ");
					}
				
				}
				while(NomVali!=0);
				
				gotoxy(x,y+8);
				Carnet(Indi_Alu1);
				
				for(i=0;i<MAXCURSOS;i++)
				{
					Alumno[Indi_Alu1].bolCursos[i]=0;
					Alumno[Indi_Alu1].Cursos[i]=-1;
				}
				
				Clases(Indi_Alu1);
				
				for (i=0;i<MAXCURSOS;i++)
				{
					if (Alumno[Indi_Alu1].bolCursos[i]==0)Alumno[Indi_Alu1].Cursos[i]=-1;
					else if (Alumno[Indi_Alu1].bolCursos[i]==1)Alumno[Indi_Alu1].Cursos[i]=0;
				}
				
			
				clrscr();
				
				Dibujo2(3,11);
				textcolor(WHITE);
				
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-3,y-4);
				cprintf("AGREGAR");
				gotoxy(40-13,y);
				cprintf("Desea agregar otro alumno?");
				gotoxy(40-12,y+2);
				cprintf(" Si");
				gotoxy(40+8,y+2);
				cprintf(" No");
				
			while(Lectura1!=13)
			{
				gotoxy(Seleccion_x,y+2);
				cprintf("%c",62);
				
				gotoxy(x,y+14);
				
				Lectura1=getch();
				
				if(Lectura1==0)Lectura2=getch();
				
				if((Lectura2==75)&&(Seleccion>1))
				{
					gotoxy(Seleccion_x,y+2);
					cprintf(" ");
					Seleccion--;
					Seleccion_x-=20;
				}
				else if((Lectura2==77)&&(Seleccion<2))
				{
					gotoxy(Seleccion_x,y+2);
					cprintf(" ");
					Seleccion++;
					Seleccion_x+=20;
				}
				Lectura2=0;
			}
			Lectura1=0;
			
			Indi_Alu1++;

			
		}
		if(Indi_Alu1>=ALU)
		{
				clrscr();
				Dibujo2(3,11);
				textcolor(WHITE);
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-3,y-4);
				cprintf("AGREGAR");
				gotoxy(40-8,y);
				cprintf("Limite Alcanzado");
				delay(1000);
		}
		
	}
	else if(Seccion==-1)
	{
		
		while(Seleccion!=2 && Indi_Alu2<(ALU*2) && Indi_Alu2>=ALU)
		{
				NomVali=0;
				clrscr();
				Dibujo2(3,11);
				textcolor(WHITE);
				Seleccion=1;
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-3,y-4);
				cprintf("AGREGAR");
				do
				{
					NomVali=0;
					gotoxy(x,y);
					cprintf("Ingrese los nombres del alumno:");
					gotoxy(x,y+2);
					CarEspacioValidacion(Alumno[Indi_Alu2].Nombres,0,PROLENOM);
					
					if(Alumno[Indi_Alu2].Nombres[0]==' ')
						NomVali++;
					
					for(i=0;i<strlen(Alumno[Indi_Alu2].Nombres);i++)
						if(Alumno[Indi_Alu2].Nombres[i]==' ' && Alumno[Indi_Alu2].Nombres[i+1]==' ')
							NomVali++;

					if(Alumno[Indi_Alu2].Nombres[strlen(Alumno[Indi_Alu2].Nombres)-1]==' ')
						NomVali++;
					

					if(NomVali!=0)
					{
						gotoxy(x,y+2);
						cprintf("                           ");
					}
					
				}
				while(NomVali!=0);
				
				
				do
				{
					NomVali=0;
					gotoxy(x,y+4);
					cprintf("Ingrese los apellidos del alumno:");
					gotoxy(x,y+6);
					CarEspacioValidacion(Alumno[Indi_Alu2].Apellidos,0,PROLENOM);
				
					if(Alumno[Indi_Alu2].Apellidos[0]==' ')
						NomVali++;
					
					for(i=0;i<strlen(Alumno[Indi_Alu2].Apellidos);i++)
						if(Alumno[Indi_Alu2].Apellidos[i]==' ' && Alumno[Indi_Alu2].Apellidos[i+1]==' ')
							NomVali++;

					if(Alumno[Indi_Alu2].Apellidos[strlen(Alumno[Indi_Alu2].Apellidos)-1]==' ')
						NomVali++;
					
					
					if(NomVali!=0)
					{
						gotoxy(x,y+6);
						cprintf("                           ");
					}
				
				}
				while(NomVali!=0);
				
				
				gotoxy(x,y+8);
				Carnet(Indi_Alu2);
				
				
				for(i=0;i<MAXCURSOS;i++)
				{
					Alumno[Indi_Alu2].bolCursos[i]=0;
					Alumno[Indi_Alu2].Cursos[i]=-1;
				}
				
				Clases(Indi_Alu2);
				
				for (i=0;i<MAXCURSOS;i++)
				{
					if (Alumno[Indi_Alu2].bolCursos[i]==0)Alumno[Indi_Alu2].Cursos[i]=-1;
					else if (Alumno[Indi_Alu2].bolCursos[i]==1)Alumno[Indi_Alu2].Cursos[i]=0;
				}
				
			
				clrscr();
				Dibujo2(3,11);
				textcolor(WHITE);
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-3,y-4);
				cprintf("AGREGAR");
				gotoxy(40-13,y);
				cprintf("Desea agregar otro alumno?");
				gotoxy(40-12,y+2);
				cprintf(" Si");
				gotoxy(40+8,y+2);
				cprintf(" No");
				
			while(Lectura1!=13)
			{
				gotoxy(Seleccion_x,y+2);
				cprintf("%c",62);
				
				gotoxy(x,y+14);
				
				Lectura1=getch();
				
				if(Lectura1==0)Lectura2=getch();
				
				if((Lectura2==75)&&(Seleccion>1))
				{
					gotoxy(Seleccion_x,y+2);
					cprintf(" ");
					Seleccion--;
					Seleccion_x-=20;
				}
				else if((Lectura2==77)&&(Seleccion<2))
				{
					gotoxy(Seleccion_x,y+2);
					cprintf(" ");
					Seleccion++;
					Seleccion_x+=20;
				}
				Lectura2=0;
			}
			Lectura1=0;
			
			Indi_Alu2++;

			
		}
		if(Indi_Alu2>=(ALU*2))
		{
				clrscr();
				Dibujo2(3,11);
				textcolor(WHITE);
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-3,y-4);
				cprintf("AGREGAR");
				gotoxy(40-8,y);
				cprintf("Limite Alcanzado");
				delay(1000);
		}

	}
}

void Mostrar(int Seccion)
{
	int x,y,i,j,k,Espacios,Limite,Tandas,Espaciosx,PromAlu,ConCursosAlu,PromClase,ConPromClase;
	int Lectura1,Lectura2,Muestra;

	x=2;
	y=8;
	Limite=5;
	PromAlu=0;
	ConCursosAlu=0;
	PromClase=0;
	clrscr();
	ConPromClase=0;

	textcolor(WHITE);
	Espaciosx=0;
	Muestra=0;
	
	
	
	if(Seccion==1 && Indi_Alu1!=0)
	{
		Tandas=floor((Indi_Alu1-1)/Limite);
		PromAlu=0;
		ConCursosAlu=0;
		PromClase=0;
		ConPromClase=0;
		Espaciosx=0;
		Muestra=0;
		clrscr();
			while(Lectura1!=13 && Lectura1!=27)
			{
				
				Dibujo2(8,7);
				textcolor(WHITE);
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				if(Indi_Alu1>5)
				{
				gotoxy(40-12,y-4);
				cprintf("REGISTROS A MOSTRAR (%c %c)",27,26);
				}
				else
				{
				gotoxy(40-9,y-4);
				cprintf("REGISTROS A MOSTRAR");	
				}
				gotoxy(x,y-2);
				cprintf("Nombres y Apellidos");
				gotoxy(x+PROLENOM+2+1,y-2);
				cprintf("Carnet");
				gotoxy(x+PROLENOM+2+1+10+2,y-2);
				cprintf("IIC ");
				gotoxy(x+PROLENOM+2+1+10+2+4,y-2);
				cprintf("GeA ");
				gotoxy(x+PROLENOM+2+1+10+2+8,y-2);
				cprintf("Fil ");
				gotoxy(x+PROLENOM+2+1+10+2+12,y-2);
				cprintf("In1 ");
				gotoxy(x+PROLENOM+2+1+10+2+16,y-2);
				cprintf("In2 ");
				gotoxy(x+PROLENOM+2+1+10+2+20,y-2);
				cprintf("Red ");
				gotoxy(x+PROLENOM+2+1+10+2+24,y-2);
				cprintf("Ma1 ");
				gotoxy(x+PROLENOM+2+1+10+2+28,y-2);
				cprintf("Con ");
				gotoxy(x+PROLENOM+2+1+10+2+32,y-2);
				cprintf("Len ");
				gotoxy(x+PROLENOM+2+1+10+2+36,y-2);
				cprintf("PROM");
					
				for(j=0;j<Tandas;j++)
				{
					if(j*Limite<=Muestra && Muestra<(1+j)*Limite)
					{
						Espacios=0;
						for(i=Muestra;i<(1+j)*Limite;i++)
						{
							gotoxy(x,y+Espacios);
							cprintf("%d.%s",i+1,Alumno[i].Nombres);
							gotoxy(x,y+Espacios+1);
							cprintf("  %s",Alumno[i].Apellidos);
							gotoxy(x+PROLENOM+2+1,y+Espacios);
							cprintf("%s",Alumno[i].Carnet);
							
							Espaciosx=0;
							PromAlu=0;
							ConCursosAlu=0;
							
							for(k=0;k<9;k++)
							{	
								gotoxy(x+PROLENOM+2+1+10+2+Espaciosx,y+Espacios);
								if(Alumno[i].Cursos[k]>=0)
								{
									cprintf("%d",Alumno[i].Cursos[k]);
									PromAlu=PromAlu+Alumno[i].Cursos[k];
									ConCursosAlu++;
								}	
								
								Espaciosx+=4;
							}
							
							gotoxy(x+PROLENOM+2+1+10+2+Espaciosx,y+Espacios);
							if(ConCursosAlu>0)
								cprintf("%d",PromAlu/ConCursosAlu);
							
							Espacios+=3;
						}
				
					}
				}
				if (Muestra<Indi_Alu1 && Muestra>=(Tandas*Limite))
				{
						Espacios=0;
						for(i=Muestra;i<Indi_Alu1;i++)
						{
							gotoxy(x,y+Espacios);
							cprintf("%d.%s",i+1,Alumno[i].Nombres);
							gotoxy(x,y+Espacios+1);
							cprintf("  %s",Alumno[i].Apellidos);
							gotoxy(x+PROLENOM+2+1,y+Espacios);
							cprintf("%s",Alumno[i].Carnet);
							
							Espaciosx=0;
							PromAlu=0;
							ConCursosAlu=0;
							ConPromClase=0;
							for(k=0;k<9;k++)
							{	
								gotoxy(x+PROLENOM+2+1+10+2+Espaciosx,y+Espacios);
								if(Alumno[i].Cursos[k]>=0)
								{
									cprintf("%d",Alumno[i].Cursos[k]);
									PromAlu=PromAlu+Alumno[i].Cursos[k];
									ConCursosAlu++;
								}	
								
								Espaciosx+=4;
							}
							
							gotoxy(x+PROLENOM+2+1+10+2+Espaciosx,y+Espacios);
							if(ConCursosAlu>0)
								cprintf("%d",PromAlu/ConCursosAlu);
							
							Espacios+=3;
							
						}
							
				}
				
				Espaciosx=0;
				
				textcolor(WHITE);
				
				for(i=0;i<MAXCURSOS;i++)
				{
					ConPromClase=0;
					PromClase=0;
					for(j=0;j<Indi_Alu1;j++)
					{
						if (Alumno[j].bolCursos[i]==1)
						{
							PromClase=PromClase+Alumno[j].Cursos[i];
							ConPromClase++;
						}
					}
					gotoxy(x+PROLENOM+2+1+10+2+Espaciosx,y+15);
					if(ConPromClase>0)
						cprintf("%d",PromClase/ConPromClase);
							
					Espaciosx+=4;	
				}
						
				gotoxy(x,y+15);
				cprintf("Promedio por clases");
				
				/*Continuar codigo*/
				
				gotoxy(x,y+17);
				cprintf("Salir (ESC)");
				
				Lectura1=getch();
				
				if(Lectura1==0)
					Lectura2=getch();

				if((Lectura2==75)&&(Muestra>0))
				{
					Muestra-=5;
					clrscr();
					
				}
				else if((Lectura2==77)&&(Muestra<Tandas*Limite))
				{	
					Muestra+=5;
					clrscr();
				}
				Lectura2=0;
				
			}
			/*Lectura1=0;*/

	}
	if(Seccion==-1 && Indi_Alu2!=ALU)
	{
		PromAlu=0;
		ConCursosAlu=0;
		PromClase=0;
		ConPromClase=0;
		Espaciosx=0;
		Muestra=0;
		Tandas=floor((Indi_Alu2-ALU-1)/Limite);
		clrscr();
		
			while(Lectura1!=13 && Lectura1!=27)
			{
				
				Dibujo2(8,7);
				textcolor(WHITE);
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				if(Indi_Alu2-ALU>5)
				{
				gotoxy(40-12,y-4);
				cprintf("REGISTROS A MOSTRAR (%c %c)",27,26);
				}
				else
				{
				gotoxy(40-9,y-4);
				cprintf("REGISTROS A MOSTRAR");	
				}
				gotoxy(x,y-2);
				cprintf("Nombres y Apellidos");
				gotoxy(x+PROLENOM+2+1,y-2);
				cprintf("Carnet");
				gotoxy(x+PROLENOM+2+1+10+2,y-2);
				cprintf("IIC ");
				gotoxy(x+PROLENOM+2+1+10+2+4,y-2);
				cprintf("GeA ");
				gotoxy(x+PROLENOM+2+1+10+2+8,y-2);
				cprintf("Fil ");
				gotoxy(x+PROLENOM+2+1+10+2+12,y-2);
				cprintf("In1 ");
				gotoxy(x+PROLENOM+2+1+10+2+16,y-2);
				cprintf("In2 ");
				gotoxy(x+PROLENOM+2+1+10+2+20,y-2);
				cprintf("Red ");
				gotoxy(x+PROLENOM+2+1+10+2+24,y-2);
				cprintf("Ma1 ");
				gotoxy(x+PROLENOM+2+1+10+2+28,y-2);
				cprintf("Con ");
				gotoxy(x+PROLENOM+2+1+10+2+32,y-2);
				cprintf("Len ");
				gotoxy(x+PROLENOM+2+1+10+2+36,y-2);
				cprintf("PROM");
					
				for(j=0;j<Tandas;j++)
				{
					if(j*Limite<=Muestra && Muestra<(1+j)*Limite)
					{
						Espacios=0;
						for(i=Muestra;i<(1+j)*Limite;i++)
						{
							gotoxy(x,y+Espacios);
							cprintf("%d.%s",i+1,Alumno[i+ALU].Nombres);
							gotoxy(x,y+Espacios+1);
							cprintf("  %s",Alumno[i+ALU].Apellidos);
							gotoxy(x+PROLENOM+2+1,y+Espacios);
							cprintf("%s",Alumno[i+ALU].Carnet);
							
							Espaciosx=0;
							PromAlu=0;
							ConCursosAlu=0;
							
							for(k=0;k<9;k++)
							{	
								gotoxy(x+PROLENOM+2+1+10+2+Espaciosx,y+Espacios);
								if(Alumno[i+ALU].Cursos[k]>=0)
								{
									cprintf("%d",Alumno[i+ALU].Cursos[k]);
									PromAlu=PromAlu+Alumno[i+ALU].Cursos[k];
									ConCursosAlu++;
								}	
								
								Espaciosx+=4;
							}
							
							gotoxy(x+PROLENOM+2+1+10+2+Espaciosx,y+Espacios);
							if(ConCursosAlu>0)
								cprintf("%d",PromAlu/ConCursosAlu);
							
							Espacios+=3;
						}
				
					}
				}
				if (Muestra<(Indi_Alu2-ALU) && Muestra>=(Tandas*Limite))
				{
						Espacios=0;
						for(i=Muestra;i<Indi_Alu2-ALU;i++)
						{
							gotoxy(x,y+Espacios);
							cprintf("%d.%s",i+1,Alumno[i+ALU].Nombres);
							gotoxy(x,y+Espacios+1);
							cprintf("  %s",Alumno[i+ALU].Apellidos);
							gotoxy(x+PROLENOM+2+1,y+Espacios);
							cprintf("%s",Alumno[i+ALU].Carnet);
							
							Espaciosx=0;
							PromAlu=0;
							ConCursosAlu=0;
							ConPromClase=0;
							for(k=0;k<9;k++)
							{	
								gotoxy(x+PROLENOM+2+1+10+2+Espaciosx,y+Espacios);
								if(Alumno[i+ALU].Cursos[k]>=0)
								{
									cprintf("%d",Alumno[i+ALU].Cursos[k]);
									PromAlu=PromAlu+Alumno[i+ALU].Cursos[k];
									ConCursosAlu++;
								}	
								
								Espaciosx+=4;
							}
							
							gotoxy(x+PROLENOM+2+1+10+2+Espaciosx,y+Espacios);
							if(ConCursosAlu>0)
								cprintf("%d",PromAlu/ConCursosAlu);
							
							Espacios+=3;
							
						}
							
				}
				
				Espaciosx=0;
				
				textcolor(WHITE);
				
				for(i=0;i<MAXCURSOS;i++)
				{
					ConPromClase=0;
					PromClase=0;
					for(j=0;j<Indi_Alu2-ALU;j++)
					{
						if (Alumno[j+ALU].bolCursos[i]==1)
						{
							PromClase=PromClase+Alumno[j+ALU].Cursos[i];
							ConPromClase++;
						}
					}
					gotoxy(x+PROLENOM+2+1+10+2+Espaciosx,y+15);
					if(ConPromClase>0)
						cprintf("%d",PromClase/ConPromClase);
							
					Espaciosx+=4;	
				}
						
				gotoxy(x,y+15);
				cprintf("Promedio por clases");
				
				/*Continuar codigo*/
				
				gotoxy(x,y+17);
				cprintf("Salir (ESC)");
				Lectura1=getch();
				
				if(Lectura1==0)
					Lectura2=getch();

				if((Lectura2==75)&&(Muestra>0))
				{
					Muestra-=5;
					clrscr();
					
				}
				else if((Lectura2==77)&&(Muestra<Tandas*Limite))
				{
					Muestra+=5;
					clrscr();
				}
				Lectura2=0;
				
			}
			/*Lectura1=0;*/

	}
}

void Lista(int Seccion, int bol)
{
	int x,y,Seleccion_y,Seleccion_x,j,i,Espacios,Limite,Tandas,Muestra;
	int Lectura1,Lectura2,Seleccion,bolSalir;

	x=40-31;
	y=8;
	Limite=5;
	Espacios=0;
	clrscr();
	Seleccion_y=y;
	Seleccion_x=40-20;
	textcolor(WHITE);
	bolSalir=0;
	Seleccion=1;
	Muestra=0;
	Tandas=floor((Indi_Alu1-1)/Limite);
	
	if(Seccion==1 && Indi_Alu1!=0)
	{
		
		textcolor(WHITE);
		bolSalir=0;
		Seleccion=1;
		Muestra=0;
		Tandas=floor((Indi_Alu1-1)/Limite);
		
		
		while(bolSalir==0)
		{
			clrscr();
				
				
			while(Lectura1!=13 && Lectura1!=27)
			{
				/*clrscr();*/
				if(bol==0)
				{
					Dibujo2(5,13);
					textcolor(WHITE);
					gotoxy(40-13,y-6);
					cprintf("REGISTRO ACADEMICO UNI-RUSB");
					if(Indi_Alu1>5)
					{
						gotoxy(40-13,y-4);
						cprintf("ALUMNOS - ACTUALIZAR (%c %c)",27,26);
					}
					else
					{
						gotoxy(40-10,y-4);
						cprintf("ALUMNOS - ACTUALIZAR",27,26);
						
					}
				}
				else
				{
					Dibujo2(4,12);
					textcolor(WHITE);
					gotoxy(40-13,y-6);
					cprintf("REGISTRO ACADEMICO UNI-RUSB");
					if(Indi_Alu1>5)
					{
						gotoxy(40-12,y-4);
						cprintf("ALUMNOS - ELIMINAR (%c %c)",27,26);
					}
					else
					{
						gotoxy(40-9,y-4);
						cprintf("ALUMNOS - ELIMINAR",27,26);
					
					}
				}
				
			
				
				for(j=0;j<Tandas;j++)
				{
					if(j*Limite<=Muestra && Muestra<(1+j)*Limite)
					{
						Espacios=0;
						for(i=Muestra;i<(1+j)*Limite;i++)
						{
							
							gotoxy(x,y+Espacios);
							cprintf("  %d.%s %s",i+1,Alumno[i].Nombres,Alumno[i].Apellidos);
							gotoxy(x+4+(PROLENOM*2)+1+1,y+Espacios);
							cprintf("%s",Alumno[i].Carnet);
							Espacios+=3;
						}
						
						
					}
					
				}
				if (Muestra<Indi_Alu1 && Muestra>=(Tandas*Limite))
				{
						Espacios=0;
						for(i=Muestra;i<Indi_Alu1;i++)
						{
							
							gotoxy(x,y+Espacios);
							cprintf("  %d.%s %s",i+1,Alumno[i].Nombres,Alumno[i].Apellidos);
							gotoxy(x+4+(PROLENOM*2)+1+1,y+Espacios);
							cprintf("%s",Alumno[i].Carnet);
							Espacios+=3;
							
						}
						
							
				}
				
				gotoxy(x,Seleccion_y);
				cprintf("%c",62);
				gotoxy(x,y+16);
				cprintf("Salir (ESC)");
				/*Bloquer desmatricula si su nota esta aprobado*/
				/*cprintf("%d",Seleccion);*/
				
				Lectura1=getch();
				if(Lectura1==0)Lectura2=getch();
				
				if((Lectura2==75)&&(Muestra>0))
				{
					Seleccion-=5;
					Muestra-=5;
					clrscr();
				}
				else if((Lectura2==77)&&(Muestra<Tandas*Limite))
				{
					Seleccion+=5;
					Muestra+=5;
					clrscr();
				}
				else if((Lectura2==72)&&(Seleccion>(Muestra+1)))
				{
					gotoxy(x,Seleccion_y);
					cprintf(" ");
					Seleccion--;
					Seleccion_y-=3;
				}
				else if((Lectura2==80)&&(Seleccion<(Muestra+5))&&(Seleccion<Indi_Alu1))
				{
					gotoxy(x,Seleccion_y);
					cprintf(" ");
					Seleccion++;
					Seleccion_y+=3;
				}
				
				if(Seleccion>Indi_Alu1)
				{
					Seleccion=Indi_Alu1;
					Espacios=0;
					for(i=0;i<Limite;i++)
					{
						if(Muestra+i==(Indi_Alu1-1))
							Seleccion_y=y+Espacios;
						
						Espacios+=3;
					}
					
				}
				
				Lectura2=0;

			}
			
			if (Lectura1!=27)
			{

				Lectura1=0;
				
				
				if(bol==0)
				{
					
					Actualizar(Seleccion-1);
					
					Seleccion=1;
					Seleccion_x=40-20;
					clrscr();
					
					
						
						Dibujo2(5,13);
						textcolor(WHITE);
						gotoxy(40-13,y-6);
						cprintf("REGISTRO ACADEMICO UNI-RUSB");
						gotoxy(40-5,y-4);
						cprintf("ACTUALIZAR");
						gotoxy(40-20,y);
						cprintf("Desea realizar cambios a otros alumnos?");
						gotoxy(40-20,y+2);
						cprintf("  Si");
						gotoxy(40+20-8,y+2);
						cprintf("  No");
						
					while(Lectura1!=13)
					{
						
						gotoxy(Seleccion_x,y+2);
						cprintf("%c",62);
						
						gotoxy(x,y+14);
						/*cprintf("%d",Seleccion);*/
						
						Lectura1=getch();
						if(Lectura1==0)Lectura2=getch();
						
						if((Lectura2==75)&&(Seleccion>1))
						{
							gotoxy(Seleccion_x,y+2);
							cprintf(" ");
							Seleccion--;
							Seleccion_x-=32;
						}
						else if((Lectura2==77)&&(Seleccion<2))
						{
							gotoxy(Seleccion_x,y+2);
							cprintf(" ");
							Seleccion++;
							Seleccion_x+=32;
						}
						Lectura2=0;
					}
					if(Seleccion==2)
						bolSalir=1;
					
				}
				else
				{
					
					Eliminar(Seleccion-1,Seccion);
					Seleccion=1;
					Seleccion_x=40-13;
					
					if(Indi_Alu1!=0)
					{
							clrscr();
							Dibujo2(4,12);
							textcolor(WHITE);
							gotoxy(40-13,y-6);
							cprintf("REGISTRO ACADEMICO UNI-RUSB");
							gotoxy(40-4,y-4);
							cprintf("ELIMINAR");
							gotoxy(40-13,y);
							cprintf("Desea realizar mas cambios?");
							gotoxy(40-13,y+2);
							cprintf("  Si");
							gotoxy(40+13-4,y+2);
							cprintf("  No");
							
						while(Lectura1!=13)
						{
							
							gotoxy(Seleccion_x,y+2);
							cprintf("%c",62);
							
							gotoxy(x,y+14);
							/*cprintf("%d",Seleccion);*/
							
							Lectura1=getch();
							if(Lectura1==0)Lectura2=getch();
							
							if((Lectura2==75)&&(Seleccion>1))
							{
								gotoxy(Seleccion_x,y+2);
								cprintf(" ");
								Seleccion--;
								Seleccion_x-=22;
							}
							else if((Lectura2==77)&&(Seleccion<2))
							{
								gotoxy(Seleccion_x,y+2);
								cprintf(" ");
								Seleccion++;
								Seleccion_x+=22;
							}
							Lectura2=0;
						}
						
						if(Seleccion==2)
							bolSalir=1;
					
					}
					else
						bolSalir=1;
				}
			}
			else 
			{	
				bolSalir=1;
			}
			
			Lectura1=0;
			Seleccion=1;
			Muestra=0;
			Seleccion_y=y;
			Tandas=floor((Indi_Alu1-1)/Limite);
		}
		
	}
	else if(Seccion==-1 && Indi_Alu2!=ALU)
	{
		
		textcolor(WHITE);
		bolSalir=0;
		Seleccion=1;
		Muestra=0;
		Tandas=floor((Indi_Alu2-ALU-1)/Limite);
			
		while(bolSalir==0)
		{
			clrscr();
			
			while(Lectura1!=13 && Lectura1!=27)
			{
				
				
				if(bol==0)
				{
					Dibujo2(5,13);
					textcolor(WHITE);
					gotoxy(40-13,y-6);
					cprintf("REGISTRO ACADEMICO UNI-RUSB");
					if(Indi_Alu2-ALU>5)
					{
						gotoxy(40-13,y-4);
						cprintf("ALUMNOS - ACTUALIZAR (%c %c)",27,26);
					}
					else
					{
						gotoxy(40-10,y-4);
						cprintf("ALUMNOS - ACTUALIZAR",27,26);
						
					}
				}
				else
				{
					Dibujo2(4,12);
					textcolor(WHITE);
					gotoxy(40-13,y-6);
					cprintf("REGISTRO ACADEMICO UNI-RUSB");
					if(Indi_Alu2-ALU>5)
					{
						gotoxy(40-12,y-4);
						cprintf("ALUMNOS - ELIMINAR (%c %c)",27,26);
					}
					else
					{
						gotoxy(40-9,y-4);
						cprintf("ALUMNOS - ELIMINAR",27,26);
					
					}
				}
				
				for(j=0;j<Tandas;j++)
				{
					if(j*Limite<=Muestra && Muestra<(1+j)*Limite)
					{
						Espacios=0;
						for(i=Muestra;i<(1+j)*Limite;i++)
						{
							
							gotoxy(x,y+Espacios);
							cprintf("  %d.%s %s",i+1,Alumno[i+ALU].Nombres,Alumno[i+ALU].Apellidos);
							gotoxy(x+4+(PROLENOM*2)+1+1,y+Espacios);
							cprintf("%s",Alumno[i+ALU].Carnet);
							Espacios+=3;
						}
						
						
					}
					
				}
				if (Muestra<Indi_Alu2-ALU && Muestra>=(Tandas*Limite))
				{
						Espacios=0;
						for(i=Muestra;i<Indi_Alu2-ALU;i++)
						{
							
							gotoxy(x,y+Espacios);
							cprintf("  %d.%s %s",i+1,Alumno[i+ALU].Nombres,Alumno[i+ALU].Apellidos);
							gotoxy(x+4+(PROLENOM*2)+1+1,y+Espacios);
							cprintf("%s",Alumno[i+ALU].Carnet);
							Espacios+=3;
							
						}
						
							
				}
				
				gotoxy(x,Seleccion_y);
				cprintf("%c",62);
				
				gotoxy(x,y+16);
				cprintf("Salir (ESC)");
				/*Bloquer desmatricula si su nota esta aprobado*/
				/*cprintf("%d",Seleccion);*/
				
				Lectura1=getch();
				if(Lectura1==0)Lectura2=getch();
				
				if((Lectura2==75)&&(Muestra>0))
				{
					Seleccion-=5;
					Muestra-=5;
					clrscr();
				}
				else if((Lectura2==77)&&(Muestra<Tandas*Limite))
				{
					Seleccion+=5;
					Muestra+=5;
					clrscr();
				}
				else if((Lectura2==72)&&(Seleccion>(Muestra+1)))
				{
					gotoxy(x,Seleccion_y);
					cprintf(" ");
					Seleccion--;
					Seleccion_y-=3;
				}
				else if((Lectura2==80)&&(Seleccion<(Muestra+5))&&(Seleccion<Indi_Alu2-ALU))
				{
					gotoxy(x,Seleccion_y);
					cprintf(" ");
					Seleccion++;
					Seleccion_y+=3;
				}
				
				if(Seleccion>Indi_Alu2-ALU)
				{
					Seleccion=Indi_Alu2-ALU;
					Espacios=0;
					for(i=0;i<Limite;i++)
					{
						if(Muestra+i==(Indi_Alu2-ALU-1))
							Seleccion_y=y+Espacios;
						
						Espacios+=3;
					}
					
				}
				
				Lectura2=0;

			}
			
			if (Lectura1!=27)
			{

				Lectura1=0;
				
				
				if(bol==0)
				{
					
					Actualizar(ALU+Seleccion-1);
					
					Seleccion=1;
					Seleccion_x=40-20;
					clrscr();
						
						Dibujo2(5,13);
						textcolor(WHITE);
						gotoxy(40-13,y-6);
						cprintf("REGISTRO ACADEMICO UNI-RUSB");
						gotoxy(40-5,y-4);
						cprintf("ACTUALIZAR");
						gotoxy(40-20,y);
						cprintf("Desea realizar cambios a otros alumnos?");
						gotoxy(40-20,y+2);
						cprintf("  Si");
						gotoxy(40+20-8,y+2);
						cprintf("  No");
						
					while(Lectura1!=13)
					{
						gotoxy(Seleccion_x,y+2);
						cprintf("%c",62);
						
						gotoxy(x,y+14);
						/*cprintf("%d",Seleccion);*/
						
						Lectura1=getch();
						if(Lectura1==0)Lectura2=getch();
						
						if((Lectura2==75)&&(Seleccion>1))
						{
							gotoxy(Seleccion_x,y+2);
							cprintf(" ");
							Seleccion--;
							Seleccion_x-=32;
						}
						else if((Lectura2==77)&&(Seleccion<2))
						{
							gotoxy(Seleccion_x,y+2);
							cprintf(" ");
							Seleccion++;
							Seleccion_x+=32;
						}
						Lectura2=0;
					}
					if(Seleccion==2)
						bolSalir=1;
					
				}
				else
				{
					
					Eliminar(ALU+Seleccion-1,Seccion);
					Seleccion=1;
					Seleccion_x=40-13;
					
					if(Indi_Alu2-ALU!=0)
					{
						
							clrscr();
							Dibujo2(4,12);
							textcolor(WHITE);
							gotoxy(40-13,y-6);
							cprintf("REGISTRO ACADEMICO UNI-RUSB");
							gotoxy(40-4,y-4);
							cprintf("ELIMINAR");
							gotoxy(40-13,y);
							cprintf("Desea realizar mas cambios?");
							gotoxy(40-13,y+2);
							cprintf("  Si");
							gotoxy(40+13-4,y+2);
							cprintf("  No");
							
						while(Lectura1!=13)
						{
							gotoxy(Seleccion_x,y+2);
							cprintf("%c",62);
							
							gotoxy(x,y+14);
							/*cprintf("%d",Seleccion);*/
							
							Lectura1=getch();
							if(Lectura1==0)Lectura2=getch();
							
							if((Lectura2==75)&&(Seleccion>1))
							{
								gotoxy(Seleccion_x,y+2);
								cprintf(" ");
								Seleccion--;
								Seleccion_x-=22;
							}
							else if((Lectura2==77)&&(Seleccion<2))
							{
								gotoxy(Seleccion_x,y+2);
								cprintf(" ");
								Seleccion++;
								Seleccion_x+=22;
							}
							Lectura2=0;
						}
						
						if(Seleccion==2)
							bolSalir=1;
					
					}
					else
						bolSalir=1;
				}
			}
			else 
			{	
				bolSalir=1;
			}
			
			Lectura1=0;
			Seleccion=1;
			Muestra=0;
			Seleccion_y=y;
			Tandas=floor((Indi_Alu2-ALU-1)/Limite);
		}
		
	}
	
}

void Actualizar(int indice)
{
	int Seleccion_y,x,y;
	int Lectura1,Lectura2,bolSalir,Seleccion,Clase,i,NomVali,Esp;

	x=6+MARGIN;
	y=8;

	bolSalir=0;
	NomVali=0;
	Clase=1;

	Seleccion=1;
	Seleccion_y=y+4;

	clrscr();

	textcolor(WHITE);

	while(bolSalir==0)
	{
		clrscr();
		
			
			Dibujo2(5,13);
			textcolor(WHITE);
			gotoxy(40-13,y-6);
			cprintf("REGISTRO ACADEMICO UNI-RUSB");
			gotoxy(40-5,y-4);
			cprintf("ACTUALIZAR");
			gotoxy(40-((strlen(Alumno[indice].Nombres)+strlen(Alumno[indice].Apellidos)+strlen(Alumno[indice].Carnet))+2)/2,y);
			cprintf("%s %s %s",Alumno[indice].Nombres,Alumno[indice].Apellidos,Alumno[indice].Carnet);
			gotoxy(x,y+4);
			cprintf("  Actualizar Nombres");
			gotoxy(x,y+6);
			cprintf("  Actualizar Apellidos");
			gotoxy(x,y+8);
			cprintf("  Actualizar Notas");
			gotoxy(x,y+10);
			cprintf("  Actualizar Clases Matriculadas");
			gotoxy(x,y+12);
			cprintf("  Salir");
		
		while(Lectura1!=13)
		{
			
			gotoxy(x,Seleccion_y);
			cprintf("%c",62);

			gotoxy(x,y+14);
			/*cprintf("%d %d",indice,Seleccion);*/

			Lectura1=getch();
			if(Lectura1==0)Lectura2=getch();

			if((Lectura2==72)&&(Seleccion>1))
			{
				gotoxy(x,Seleccion_y);
				cprintf(" ");
				Seleccion--;
				Seleccion_y-=2;
			}
			else if((Lectura2==80)&&(Seleccion<5))
			{
				gotoxy(x,Seleccion_y);
				cprintf(" ");
				Seleccion++;
				Seleccion_y+=2;
			}
			Lectura2=0;
			
		
		}
		
		switch(Seleccion)
		{
			
			case 1:
				clrscr();
				/*Alumno[indice].Nombres*/
				Dibujo2(5,13);
				textcolor(WHITE);
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-5,y-4);
				cprintf("ACTUALIZAR");
				
				do
				{
					NomVali=0;
					Esp=0;
					gotoxy(40-15,y);
					cprintf("Ingrese los nombres del alumno:");
					gotoxy(40-15,y+2);
					CarEspacioValidacion(Alumno[indice].Nombres,0,PROLENOM);
					
					if(Alumno[indice].Nombres[0]==' ')
						NomVali++;
					
					for(i=0;i<strlen(Alumno[indice].Nombres);i++)
					{
						if(Alumno[indice].Nombres[i]==' ' && Alumno[indice].Nombres[i+1]==' ')
							NomVali++;
						
						if(Alumno[indice].Nombres[i]==' ')
							Esp++;
					}
					
					if(Esp>1)
						NomVali++;
					
					if(Alumno[indice].Nombres[strlen(Alumno[indice].Nombres)-1]==' ')
						NomVali++;

					if(NomVali!=0)
					{
						gotoxy(40-15,y+2);
						cprintf("                           ");
					}
					
				}
				while(NomVali!=0);
				
				
			
			break;
		
			case 2:
				clrscr();
				/*Alumno[indice].Nombres*/
				Dibujo2(5,13);
				textcolor(WHITE);
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-5,y-4);
				cprintf("ACTUALIZAR");
				
				do
				{
					NomVali=0;
					Esp=0;
					gotoxy(40-16,y);
					cprintf("Ingrese los Apellidos del alumno:");
					gotoxy(40-16,y+2);
					CarEspacioValidacion(Alumno[indice].Apellidos,0,PROLENOM);
					
					if(Alumno[indice].Apellidos[0]==' ')
						NomVali++;
					
					for(i=0;i<strlen(Alumno[indice].Apellidos);i++)
					{
						if(Alumno[indice].Apellidos[i]==' ' && Alumno[indice].Apellidos[i+1]==' ')
							NomVali++;
					
						if(Alumno[indice].Apellidos[i]==' ')
							Esp++;
					}
					
					if(Esp!=1)
						NomVali++;
					
					if(Alumno[indice].Apellidos[strlen(Alumno[indice].Apellidos)-1]==' ')
						NomVali++;

					if(NomVali!=0)
					{
						gotoxy(40-16,y+2);
						cprintf("                           ");
					}
					
				}
				while(NomVali!=0);
				
			break;
			
			case 3:
			
			Notas(indice);
			
			break;
			
			case 4:
			
			Clases(indice);
			
			for (i=0;i<MAXCURSOS;i++)
			{
				if (Alumno[indice].bolCursos[i]==0)
					Alumno[indice].Cursos[i]=-1;
				else if (Alumno[indice].bolCursos[i]==1 && Alumno[indice].Cursos[i]<0)
					Alumno[indice].Cursos[i]=0;
			}
			
			break;
			
			case 5:
			bolSalir=1;
			break;
		
		}
		
		Lectura1=0;
		
	}
	
}

void Eliminar(int indice, int Seccion)
{
	int x,y,Seleccion_x,j,i;
	int Lectura1,Lectura2,Seleccion,bolSalir;
					
	x=40-31;
	y=8;
	clrscr();
	Seleccion_x=40-19;
	textcolor(WHITE);
	Seleccion=1;
	
	
		clrscr();
		Dibujo2(4,12);
		textcolor(WHITE);
		gotoxy(40-13,y-6);
		cprintf("REGISTRO ACADEMICO UNI-RUSB");
		gotoxy(40-4,y-4);
		cprintf("ELIMINAR");
		gotoxy(40-((strlen(Alumno[indice].Nombres)+strlen(Alumno[indice].Apellidos)+strlen(Alumno[indice].Carnet))+2)/2,y);
		cprintf("%s %s %s",Alumno[indice].Nombres,Alumno[indice].Apellidos,Alumno[indice].Carnet);
		gotoxy(40-19,y+4);
		cprintf("Seguro que desea eliminar este alumno?");
		gotoxy(40-19,y+6);
		cprintf("  Si");
		gotoxy(40+19-8,y+6);
		cprintf("  No");
	while(Lectura1!=13)
	{
		
		gotoxy(Seleccion_x,y+6);
		cprintf("%c",62);
						
		gotoxy(x,y+14);
		/*cprintf("%d %d",Seleccion,indice);*/
						
		Lectura1=getch();
		if(Lectura1==0)Lectura2=getch();
						
		if((Lectura2==75)&&(Seleccion>1))
		{
			gotoxy(Seleccion_x,y+6);
			cprintf(" ");
			Seleccion--;
			Seleccion_x-=30;
		}
		else if((Lectura2==77)&&(Seleccion<2))
		{
			gotoxy(Seleccion_x,y+6);
			cprintf(" ");
			Seleccion++;
			Seleccion_x+=30;
		}
		Lectura2=0;
		
	}
	
	if(Seleccion==1)
	{
		if(Seccion==1)
		{
			for(i=indice;i<Indi_Alu1;i++)
			{
				if(i<Indi_Alu1-1)
				{
					
					strcpy(Alumno[i].Nombres,Alumno[i+1].Nombres);
					strcpy(Alumno[i].Apellidos,Alumno[i+1].Apellidos);
					strcpy(Alumno[i].Carnet,Alumno[i+1].Carnet);
					
					for(j=0;j<MAXCURSOS;j++)
					{
						Alumno[i].Cursos[j]=Alumno[i+1].Cursos[j];
						Alumno[i].bolCursos[j]=Alumno[i+1].bolCursos[j];
					}
					
				}
				else if(i==Indi_Alu1-1)
				{
					/*strcpy(Alumno[i].Nombres,"");
					strcpy(Alumno[i].Apellidos,"");
					strcpy(Alumno[i].Carnet,"");*/
					
					memset(Alumno[i].Nombres,0,PROLENOM);
					memset(Alumno[i].Apellidos,0,PROLENOM);
					memset(Alumno[i].Carnet,0,PROLENOM);
					
					for(j=0;j<MAXCURSOS;j++)
					{
						Alumno[i].Cursos[j]=NULL;
						Alumno[i].bolCursos[j]=NULL;
					}
					
				}
			}
			Indi_Alu1--;
		}
		else if(Seccion==-1)
		{
			for(i=indice;i<Indi_Alu2;i++)
			{
				if(i<Indi_Alu2)
				{
					
					strcpy(Alumno[i].Nombres,Alumno[i+1].Nombres);
					strcpy(Alumno[i].Apellidos,Alumno[i+1].Apellidos);
					strcpy(Alumno[i].Carnet,Alumno[i+1].Carnet);
					
					for(j=0;j<MAXCURSOS;j++)
					{
						Alumno[i].Cursos[j]=Alumno[i+1].Cursos[j];
						Alumno[i].bolCursos[j]=Alumno[i+1].bolCursos[j];
					}
					
				}
				else if(i==Indi_Alu2-1)
				{
					/*strcpy(Alumno[i].Nombres,"");
					strcpy(Alumno[i].Apellidos,"");
					strcpy(Alumno[i].Carnet,"");*/
					
					memset(Alumno[i].Nombres,0,PROLENOM);
					memset(Alumno[i].Apellidos,0,PROLENOM);
					memset(Alumno[i].Carnet,0,PROLENOM);
					
					for(j=0;j<MAXCURSOS;j++)
					{
						Alumno[i].Cursos[j]=NULL;
						Alumno[i].bolCursos[j]=NULL;
					}
					
				}
			}
			Indi_Alu2--;
		}
		
		clrscr();
		Dibujo2(4,12);
		textcolor(WHITE);
		gotoxy(40-13,y-6);
		cprintf("REGISTRO ACADEMICO UNI-RUSB");
		gotoxy(40-9,y-4);
		cprintf("ELIMINACION EXITOSA");
		gotoxy(x,y+16);
		/*cprintf("%d %d",Indi_Alu1,Indi_Alu2);*/
		
		delay(1000);
		
	}
	
	
}

void Busqueda(int Seccion)
{
	int x,y,a,b,Seleccion_y,Seleccion_x,j,i,Espacios,Limite,Tandas,Muestra;
	int Lectura1,Lectura2,Seleccion,bolSalir;

	x=40-17;
	y=8;
	clrscr();
	Seleccion_y=y+2;
	textcolor(WHITE);
	bolSalir=0;
	Seleccion=1;
	
		while(bolSalir==0 && ((Indi_Alu1!=0 && Seccion==1)||(Indi_Alu2!=ALU&& Seccion==-1)))
		{
		
				
					clrscr();
					Dibujo2(5,13);
					textcolor(WHITE);
					gotoxy(40-13,y-6);
					cprintf("REGISTRO ACADEMICO UNI-RUSB");
					gotoxy(40-3,y-4);
					cprintf("BUSCAR");
					gotoxy(40-floor(strlen("  Buscar por nombre")/2)-2,y+2);
					cprintf("  Buscar por nombre");
					gotoxy(40-floor(strlen("  Buscar por carnet")/2)-2,y+6);
					cprintf("  Buscar por carnet");
					gotoxy(40-floor(strlen("  Salir")/2)-2,y+10);
					cprintf("  Salir");
					
					/*cprintf("%d %d %d",Indi_Alu1,Indi_Alu2,Seleccion);*/
					
				while(Lectura1!=13)
				{
					gotoxy(x,Seleccion_y);
					cprintf("%c",62);

					gotoxy(x,y+16);
					
					Lectura1=getch();
					if(Lectura1==0)
						Lectura2=getch();

					if((Lectura2==72)&&(Seleccion>1))
					{
						gotoxy(x,Seleccion_y);
						cprintf(" ");
						/*if(Seleccion==2)
							Seleccion_y-=5;
						else*/
						Seleccion_y-=4;
						Seleccion--;
					}
					else if((Lectura2==80)&&(Seleccion<3))
					{
						gotoxy(x,Seleccion_y);
						cprintf(" ");
						/*if(Seleccion==1)
							Seleccion_y+=5;
						else*/
						Seleccion_y+=4;
						Seleccion++;
					}
					
					Lectura2=0;
				}
				
				
				switch(Seleccion)
				{
					
					case 1:
					BusquedaNC(0,Seccion);
					break;
				
					case 2:
					BusquedaNC(1,Seccion);
					break;
				
					case 3:
					bolSalir=1;	
					break;
					
				}

			Lectura1=0;
			
		}
	
	
}

void BusquedaNC(int bol,int Seccion)
{
	int x,x2,y,Seleccion_y,Seleccion_x,j,i,Espacios,Limite,Tandas,Muestra,Alumnos[10],ConAlumnos,ConCom,indice,NomVali;
	int Lectura1,Lectura2,Seleccion,bolSalir;
	int BNEspacio,k,l,Au,Rep;
	char BNombre[PROLENOM],BCarnet[MAX];

	x=40-31;
	x2=40-13;
	y=8;
	Limite=5;
	Espacios=0;
	clrscr();
	Seleccion_y=y;
	Seleccion_x=40-20;
	textcolor(WHITE);
	bolSalir=0;
	ConCom=0;
	ConAlumnos=0;
	indice=0;
	
	

	
	if(Seccion==1)
	{
		clrscr();
		Dibujo2(5,13);
		textcolor(WHITE);
		Seleccion=1;
		gotoxy(40-13,y-6);
		cprintf("REGISTRO ACADEMICO UNI-RUSB");
		gotoxy(40-3,y-4);
		cprintf("BUSCAR");
		
		if(bol==0)
		{
			do
			{
				NomVali=0;
				gotoxy(x2,y);
				cprintf("Ingrese nombre del alumno:");
				gotoxy(x2,y+2);
				CarEspacioValidacion(BNombre,0,PROLENOM);
					
					if(BNombre[0]==' ')
						NomVali++;
					
					for(i=0;i<strlen(BNombre);i++)
					{
						if(BNombre[i]==' ' && BNombre[i+1]==' ')
							NomVali++;
					}
					
					
					if(BNombre[strlen(BNombre)-1]==' ')
						NomVali++;

					if(NomVali!=0)
					{
						gotoxy(x2,y+2);
						cprintf("                           ");
					}
					
			}
			while(NomVali!=0);
				
				
			/*Adiciones*/	
				
			BNEspacio=0;
			
			for(i=0;i<strlen(BNombre);i++)
			{
				if(BNombre[i]==' ')
				{
					BNEspacio++;
				}	
			}
		}
		else
		{
			gotoxy(x2,y);
			cprintf("Ingrese carnet del alumno:");
			gotoxy(x2,y+2);
			CarNumSigValidacion(BCarnet,0,MAX);
		}
		
		ConAlumnos=0;
		
		if(bol==0)
		{
			if(BNEspacio!=0)
			{
				for(i=0;i<Indi_Alu1;i++)
				{
					if (strlen(BNombre)<=strlen(Alumno[i].Nombres))
					{
						ConCom=0;
						for(j=0;j<strlen(BNombre);j++)
						{
							if(tolower(BNombre[j])!=tolower(Alumno[i].Nombres[j]))
							{
								ConCom++;
							}
						}
						
						if(ConCom==0)
						{
							Alumnos[ConAlumnos]=i;
							ConAlumnos++;
						}
					}
				}
			}
			else
			{
				
				for(i=0;i<Indi_Alu1;i++)
				{
					
					k=0;
					
					while(Alumno[i].Nombres[k]!=' ' && Alumno[i].Nombres[k]!='\0')
					{
						k++;
					}
					
					if (strlen(BNombre)<=k)
					{
						ConCom=0;
						for(j=0;j<strlen(BNombre);j++)
						{
							if(tolower(BNombre[j])!=tolower(Alumno[i].Nombres[j]))
							{
								ConCom++;
							}
						}
						
						if(ConCom==0)
						{
							Alumnos[ConAlumnos]=i;
							ConAlumnos++;
						}
						
					}
				}
				
				
				for(i=0;i<Indi_Alu1;i++)
				{
					Au=0;
					k=0;
					
					while(Alumno[i].Nombres[k]!=' ' && Alumno[i].Nombres[k]!='\0')
					{
						k++;
					}
					
					if(Alumno[i].Nombres[k]==' ')
					{
						
						Au=k;
						
						k++;
						
						while(Alumno[i].Nombres[k]!=' ' && Alumno[i].Nombres[k]!='\0')
						{
							k++;
						}
						
						if ((strlen(BNombre)+Au)<=k)
						{
							
							ConCom=0;
							
							for(j=Au+1;j<=(strlen(BNombre)+Au);j++)
							{
								if(tolower(BNombre[j-(Au+1)])!=tolower(Alumno[i].Nombres[j]))
								{
									ConCom++;
								}
								
							}
							
							if(ConCom==0)
							{
								Rep=0;
								for(l=0;l<ConAlumnos;l++)
								{
									if(Alumnos[l]==i)
									{
										Rep++;
									}
								}
								
								if(Rep==0)
								{
									Alumnos[ConAlumnos]=i;
									ConAlumnos++;
								}
							}	
						}		
					}
				}
			}	
		}	
		else
		{
			for(i=0;i<Indi_Alu1;i++)
			{
				if (strlen(BCarnet)==strlen(Alumno[i].Carnet))
				{
					ConCom=0;

					for(j=0;j<(strlen(BCarnet)-1);j++)
					{
						if(BCarnet[j]!=Alumno[i].Carnet[j])
						{
							ConCom++;
						}

					}

					if(tolower(BCarnet[(strlen(BCarnet)-1)])!=tolower(Alumno[i].Carnet[(strlen(BCarnet)-1)]))
					{
						ConCom++;
					}
							
					if(ConCom==0)
					{
						Alumnos[ConAlumnos]=i;
						ConAlumnos++;
					}
							
				}
			}
		}
			
			
			
			/*
			for(i=0;i<Indi_Alu1;i++)
			{
				if(bol==0)
				{
					
					if (strlen(BNombre)<=strlen(Alumno[i].Nombres))
					{
						ConCom=0;
						for(j=0;j<strlen(BNombre);j++)
						{
							if(BNombre[j]!=Alumno[i].Nombres[j])
							{
								ConCom++;
							}
							
						}
						
						if(ConCom==0)
						{
							Alumnos[ConAlumnos]=i;
							ConAlumnos++;
						}
						
					}
						
				}
				else 
				{
					if (strlen(BCarnet)==strlen(Alumno[i].Carnet))
					{
						ConCom=0;
						for(j=0;j<strlen(BCarnet);j++)
						{
							if(BCarnet[j]!=Alumno[i].Carnet[j])
							{
								ConCom++;
							}
							
						}
						
						if(ConCom==0)
						{
							Alumnos[ConAlumnos]=i;
							ConAlumnos++;
						}
						
					}
					
				}
			}
			*/
			
			if(ConAlumnos>0)
			{	
				Seleccion=1;
				Muestra=0;
				Tandas=floor((ConAlumnos-1)/Limite);
				Lectura1=0;
				clrscr();
				
				while(Lectura1!=13 && Lectura1!=27)
				{
					
					Dibujo2(5,13);
					textcolor(WHITE);
					gotoxy(40-13,y-6);
					cprintf("REGISTRO ACADEMICO UNI-RUSB");
					if(ConAlumnos>5)
					{
						gotoxy(40-6,y-4);
						cprintf("BUSCAR (%c %c)",27,26);
					}
					else
					{
						gotoxy(40-3,y-4);
						cprintf("BUSCAR");
					}
					
					for(j=0;j<Tandas;j++)
					{
						if(j*Limite<=Muestra && Muestra<(1+j)*Limite)
						{
							Espacios=0;
							for(i=Muestra;i<Limite;i++)
							{
								
								gotoxy(x,y+Espacios);
								cprintf("  %d.%s %s",i+1,Alumno[Alumnos[i]].Nombres,Alumno[Alumnos[i]].Apellidos);
								gotoxy(x+4+(PROLENOM*2)+1+1,y+Espacios);
								cprintf("%s",Alumno[Alumnos[i]].Carnet);
								Espacios+=3;
							}
							
							
						}
						
					}
					
					if (Muestra<ConAlumnos && Muestra>=(Tandas*Limite))
					{
							Espacios=0;
							for(i=Muestra;i<ConAlumnos;i++)
							{
								
								gotoxy(x,y+Espacios);
								cprintf("  %d.%s %s",i+1,Alumno[Alumnos[i]].Nombres,Alumno[Alumnos[i]].Apellidos);
								gotoxy(x+4+(PROLENOM*2)+1+1,y+Espacios);
								cprintf("%s",Alumno[Alumnos[i]].Carnet);
								Espacios+=3;
								
							}
					}
					
					gotoxy(x,Seleccion_y);
					cprintf("%c",62);
					
					gotoxy(x,y+16);
					cprintf("Salir (ESC)");
					/*Bloquer desmatricula si su nota esta aprobado*/
					/*cprintf("%d",Seleccion);*/
					
					Lectura1=getch();
					if(Lectura1==0)Lectura2=getch();
					
					if((Lectura2==75)&&(Muestra>0))
					{
						
						Seleccion-=5;
						Muestra-=5;
						clrscr();
						
					}
					else if((Lectura2==77)&&(Muestra<Tandas*Limite))
					{
						Seleccion+=5;
						Muestra+=5;
						clrscr();
						
					}
					else if((Lectura2==72)&&(Seleccion>(Muestra+1)))
					{
						gotoxy(x,Seleccion_y);
						cprintf(" ");
						Seleccion--;
						Seleccion_y-=3;
					}
					else if((Lectura2==80)&&(Seleccion<(Muestra+5))&&(Seleccion<ConAlumnos))
					{
						gotoxy(x,Seleccion_y);
						cprintf(" ");
						Seleccion++;
						Seleccion_y+=3;
					}
					
					
					if(Seleccion>ConAlumnos)
					{
						Seleccion=ConAlumnos;
						Espacios=0;
						for(i=0;i<Limite;i++)
						{
							if(Muestra+i==(ConAlumnos-1))
								Seleccion_y=y+Espacios;
							
							Espacios+=3;
						}
					}
					
					Lectura2=0;
					
				}
				if(Lectura1==13)
				{
					for(i=0;i<ConAlumnos;i++)
					{
						if((Seleccion-1)==i)
						{
							indice=Alumnos[i];
				
						}
					}
					
					Actualizar(indice);
				}
			
			}
			else
			{
				
					clrscr();
					Dibujo2(5,13);
					textcolor(WHITE);
					gotoxy(40-13,y-6);
					cprintf("REGISTRO ACADEMICO UNI-RUSB");
					gotoxy(40-4,y-4);
					cprintf("INVALIDO");
					gotoxy(x,y+16);
					if(getch()==0)getch();
			
			}

	}
	else if(Seccion==-1)
	{
		
		clrscr();
		Dibujo2(5,13);
		textcolor(WHITE);
		Seleccion=1;
		gotoxy(40-13,y-6);
		cprintf("REGISTRO ACADEMICO UNI-RUSB");
		gotoxy(40-3,y-4);
		cprintf("BUSCAR");
		
		if(bol==0)
		{
			do
			{
				NomVali=0;
				gotoxy(x2,y);
				cprintf("Ingrese nombre del alumno:");
				gotoxy(x2,y+2);
				CarEspacioValidacion(BNombre,0,PROLENOM);
					
					if(BNombre[0]==' ')
						NomVali++;
					
					for(i=0;i<strlen(BNombre);i++)
						if(BNombre[i]==' ' && BNombre[i+1]==' ')
							NomVali++;

					if(BNombre[strlen(BNombre)-1]==' ')
						NomVali++;

					if(NomVali!=0)
					{
						gotoxy(x2,y+2);
						cprintf("                           ");
					}
					
			}
			while(NomVali!=0);
			
			BNEspacio=0;
			
			for(i=0;i<strlen(BNombre);i++)
			{
				if(BNombre[i]==' ')
				{
					BNEspacio++;
				}	
			}
			
			
		}
		else
		{
			gotoxy(x2,y);
			cprintf("Ingrese carnet del alumno:");
			gotoxy(x2,y+2);
			CarNumSigValidacion(BCarnet,0,MAX);
		}
		
		ConAlumnos=0;
		
		if(bol==0)
		{
			if(BNEspacio!=0)
			{
				for(i=ALU;i<Indi_Alu2;i++)
				{
					if (strlen(BNombre)<=strlen(Alumno[i].Nombres))
					{
						ConCom=0;
						for(j=0;j<strlen(BNombre);j++)
						{
							if(tolower(BNombre[j])!=tolower(Alumno[i].Nombres[j]))
							{
								ConCom++;
							}
						}
						
						if(ConCom==0)
						{
							Alumnos[ConAlumnos]=i;
							ConAlumnos++;
						}
					}
				}
			}
			else
			{
				
				for(i=ALU;i<Indi_Alu2;i++)
				{
					
					k=0;
					
					while(Alumno[i].Nombres[k]!=' ' && Alumno[i].Nombres[k]!='\0')
					{
						k++;
					}
					
					if (strlen(BNombre)<=k)
					{
						ConCom=0;
						for(j=0;j<strlen(BNombre);j++)
						{
							if(tolower(BNombre[j])!=tolower(Alumno[i].Nombres[j]))
							{
								ConCom++;
							}
						}
						
						if(ConCom==0)
						{
							Alumnos[ConAlumnos]=i;
							ConAlumnos++;
						}
						
					}
				}
				
				
				for(i=ALU;i<Indi_Alu2;i++)
				{
					Au=0;
					k=0;
					
					while(Alumno[i].Nombres[k]!=' ' && Alumno[i].Nombres[k]!='\0')
					{
						k++;
					}
					
					if(Alumno[i].Nombres[k]==' ')
					{
						
						Au=k;
						
						k++;
						
						while(Alumno[i].Nombres[k]!=' ' && Alumno[i].Nombres[k]!='\0')
						{
							k++;
						}
						
						if ((strlen(BNombre)+Au)<=k)
						{
							
							ConCom=0;
							
							for(j=Au+1;j<=(strlen(BNombre)+Au);j++)
							{
								if(tolower(BNombre[j-(Au+1)])!=tolower(Alumno[i].Nombres[j]))
								{
									ConCom++;
								}
								
							}
							
							if(ConCom==0)
							{
								Rep=0;
								for(l=0;l<ConAlumnos;l++)
								{
									if(Alumnos[l]==i)
									{
										Rep++;
									}
								}
								
								if(Rep==0)
								{
									Alumnos[ConAlumnos]=i;
									ConAlumnos++;
								}
							}	
						}		
					}
				}
			}	
		}	
		else
		{
			for(i=ALU;i<Indi_Alu2;i++)
			{
				if (strlen(BCarnet)==strlen(Alumno[i].Carnet))
				{
					ConCom=0;
					for(j=0;j<(strlen(BCarnet)-1);j++)
					{
						if(BCarnet[j]!=Alumno[i].Carnet[j])
						{
							ConCom++;
						}
								
					}
					
					if(tolower(BCarnet[(strlen(BCarnet)-1)])!=tolower(Alumno[i].Carnet[(strlen(BCarnet)-1)]))
					{
						ConCom++;
					}

					
					if(ConCom==0)
					{
						Alumnos[ConAlumnos]=i;
						ConAlumnos++;
					}
							
				}
			}
		}
		
		
			/*
			ConAlumnos=0;
			
			for(i=ALU;i<Indi_Alu2;i++)
			{
				if(bol==0)
				{
					
					if (strlen(BNombre)<=strlen(Alumno[i].Nombres))
					{
						ConCom=0;
						for(j=0;j<strlen(BNombre);j++)
						{
							if(BNombre[j]!=Alumno[i].Nombres[j])
							{
								ConCom++;
							}
							
						}
						
						if(ConCom==0)
						{
							Alumnos[ConAlumnos]=i;
							ConAlumnos++;
						}
						
					}
						
				}
				else 
				{
					if (strlen(BCarnet)==strlen(Alumno[i].Carnet))
					{
						ConCom=0;
						for(j=0;j<strlen(BCarnet);j++)
						{
							if(BCarnet[j]!=Alumno[i].Carnet[j])
							{
								ConCom++;
							}
							
						}
						
						if(ConCom==0)
						{
							Alumnos[ConAlumnos]=i;
							ConAlumnos++;
						}
						
					}
					
				}
			}
			*/
			
			if(ConAlumnos>0)
			{	
				Seleccion=1;
				Muestra=0;
				Tandas=floor((ConAlumnos-1)/Limite);
				Lectura1=0;
				clrscr();
				while(Lectura1!=13 && Lectura1!=27)
				{
					
					
					
					
					Dibujo2(5,13);
					textcolor(WHITE);
					gotoxy(40-13,y-6);
					cprintf("REGISTRO ACADEMICO UNI-RUSB");
					if(ConAlumnos>5)
					{
						gotoxy(40-6,y-4);
						cprintf("BUSCAR (%c %c)",27,26);
					}
					else
					{
						gotoxy(40-3,y-4);
						cprintf("BUSCAR");
					}
					
					
					for(j=0;j<Tandas;j++)
					{
						if(j*Limite<=Muestra && Muestra<(1+j)*Limite)
						{
							Espacios=0;
							for(i=Muestra;i<Limite;i++)
							{
								
								gotoxy(x,y+Espacios);
								cprintf("  %d.%s %s",i+1,Alumno[Alumnos[i]].Nombres,Alumno[Alumnos[i]].Apellidos);
								gotoxy(x+4+(PROLENOM*2)+1+1,y+Espacios);
								cprintf("%s",Alumno[Alumnos[i]].Carnet);
								Espacios+=3;
							}
							
							
						}
						
					}
					
					if (Muestra<ConAlumnos && Muestra>=(Tandas*Limite))
					{
							Espacios=0;
							for(i=Muestra;i<ConAlumnos;i++)
							{
								
								gotoxy(x,y+Espacios);
								cprintf("  %d.%s %s",i+1,Alumno[Alumnos[i]].Nombres,Alumno[Alumnos[i]].Apellidos);
								gotoxy(x+4+(PROLENOM*2)+1+1,y+Espacios);
								cprintf("%s",Alumno[Alumnos[i]].Carnet);
								Espacios+=3;
								
							}
					}
					
					gotoxy(x,Seleccion_y);
					cprintf("%c",62);
					
					gotoxy(x,y+16);
					cprintf("Salir (ESC)");
					/*Bloquer desmatricula si su nota esta aprobado*/
					/*cprintf("%d",Seleccion);*/
					
					Lectura1=getch();
					if(Lectura1==0)Lectura2=getch();
					
					if((Lectura2==75)&&(Muestra>0))
					{
						Seleccion-=5;
						Muestra-=5;
						clrscr();
					}
					else if((Lectura2==77)&&(Muestra<Tandas*Limite))
					{
						Seleccion+=5;
						Muestra+=5;
						clrscr();
					}
					else if((Lectura2==72)&&(Seleccion>(Muestra+1)))
					{
						gotoxy(x,Seleccion_y);
						cprintf(" ");
						Seleccion--;
						Seleccion_y-=3;
					}
					else if((Lectura2==80)&&(Seleccion<(Muestra+5))&&(Seleccion<ConAlumnos))
					{
						gotoxy(x,Seleccion_y);
						cprintf(" ");
						Seleccion++;
						Seleccion_y+=3;
					}
					
					
					if(Seleccion>ConAlumnos)
					{
						Seleccion=ConAlumnos;
						Espacios=0;
						for(i=0;i<Limite;i++)
						{
							if(Muestra+i==(ConAlumnos-1))
								Seleccion_y=y+Espacios;
							
							Espacios+=3;
						}
					}
					
					Lectura2=0;
					
				}
				if(Lectura1==13)
				{
					for(i=0;i<ConAlumnos;i++)
					{
						if((Seleccion-1)==i)
						{
							indice=Alumnos[i];
				
						}
					}
					
					Actualizar(indice);
				}
			
			}
			else
			{
				
					clrscr();
					Dibujo2(5,13);
					textcolor(WHITE);
					gotoxy(40-13,y-6);
					cprintf("REGISTRO ACADEMICO UNI-RUSB");
					gotoxy(40-4,y-4);
					cprintf("INVALIDO");
					gotoxy(x,y+16);
					if(getch()==0)getch();
			
			}
			
			

	}	
	
}

void Ayuda(void)
{
	
	int x,y;
	int Lectura1,Lectura2,bolSalir,Seleccion,Clase;
	
	y=8;
	clrscr();
	Seleccion=1;
	
	while(Lectura1!=13 && Lectura1!=27)
	{
		
		
		Dibujo2(2,10);
		
		textcolor(WHITE);
		gotoxy(40-13,y-6);
		cprintf("REGISTRO ACADEMICO UNI-RUSB");
		gotoxy(40-5,y-4);
		cprintf("AYUDA (%c %c)",27,26);
		switch(Seleccion)
		{
			case 1:
			gotoxy(1,y);
			cprintf("General: Este proyecto fue hecho por Jurgen Francisco Bermudez Picado 1M1-CO. Aliniciar se pide el acceso de algunos de los tres usuarios ya registrados el     cual uno de ellos es el administrador. Se usan ficheros para la lectura y       escritura de datos de los alumnos y otros datos. Use las direccionales, Enter o ESC para interactuar.");
			gotoxy(1,y+6);
			cprintf("Cambiar de Seccion: Esta opcion cambia directamente de seccion, mostrado en la  parte superior.");
			gotoxy(1,y+6+3);
			cprintf("Agregar: Se le pide los nombres (2 Max) y apellidos del alumno que desea anexar,a la vez que las clases que desea matricular (tiene que matricular al menos 1   clase para continuar), sus clases matriculadas tendran una nota inicial de 0.");
			gotoxy(1,y+6+3+4);
			cprintf("Buscar: Se abre un menu en el cual podras buscar alumnos por nombres o numero decarnet, si se encuentra, te mostrara una lista de alumnos los cuales puedes     actualizar la informacion, puedes presionar ESC para salir de la lista.");
			break;
			
			case 2:
			gotoxy(1,y);
			cprintf("Actualizar: Se mostrara una lista de alumnos ya matriculados y se dara la opcionde seleccionar uno para editar su informacion, o salir de la lista presionando  ESC. Puedes cambiar sus nombres, sus apellidos, notas de clases ya matriculadas y/o matricular o dejar de llevar clases.");
			gotoxy(1,y+5);
			cprintf("Eliminar: Esta opcion unicamente esta habilitada con el acceso como             administrador, en esta opcion se mostrara una lista de alumnos matriculados, se podra seleccionar cual se quiere eliminar, o puedes salir de la lista           presionando ESC.");
			gotoxy(1,y+5+5);
			cprintf("Mostrar: Te mostrara los nombres y apellidos, carnet, notas de las clases que   estan cursando, y los promedios por clases y por estudiantes. Usa las           direccionales para cambiar de pagina si hay muchos estudiantes, o pulsa ESC o   Enter para salir.");
			break;
			
		}
		
		gotoxy(1,25);
		cprintf("Salir (ESC)");
		
		Lectura1=getch();
		if(Lectura1==0)Lectura2=getch();
		
		if((Lectura2==75)&&(Seleccion>1))
		{
			clrscr();
			Seleccion--;
		}
		else if((Lectura2==77)&&(Seleccion<2))
		{
			clrscr();
			Seleccion++;
		}
		Lectura2=0;
		



		
	}
}


