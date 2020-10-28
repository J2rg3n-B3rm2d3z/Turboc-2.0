#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#include<math.h>
#include<dos.h>

#define MAX 11
#define MARGIN 13
#define PROLENOM 23
#define MAXCURSOS 9
#define ALU 10


extern struct Data Alumno[20];
 
extern int Indi_Alu1,Indi_Alu2,NumCar;
 
int verifi(char * nombre,char * contra,char * nombrev,char * contrav);/*Funcion para verificar las credenciales*/
 
int Acceso(void);/*Funcion para el acceso al sistema*/

void Carnet(int indice);/*Funcion para Asignar Carnet Automaticamente*/

void Clases(int indice);/*Funcion para elegir las clases a cursar*/

void Notas(int indice);/*Funcion para Editar Notas*/

void Dibujo2(int Color1,int Color2);


void Dibujo2(int Color1,int Color2)
{
	int a,b,y;
	y=8;
	
	textcolor(Color1);
		
		for(a=1;a<40-20;a++)
		{
			for(b=1;b<y-3;b++)
			{
				gotoxy(a,b);
				if(a<10)
					cprintf("%c",176);
				else if(a>=10 && a<15) 
					cprintf("%c",177);
				else if(a>=15 && a<20) 
					cprintf("%c",178);
				else
					cprintf(" ");
			}
		}
		
		
		
		for(a=40+21;a<81;a++)
		{
			for(b=1;b<y-3;b++)
			{
				gotoxy(a,b);
				if(a<40+20+5)
					cprintf("%c",178);
				else if(a>=40+20+5 && a<40+20+10) 
					cprintf("%c",177);
				else 
					cprintf("%c",176);
			}
		}
		
		
		textcolor(Color2);
		
		for(a=1;a<y-3;a++)
		{
			gotoxy(40-20,a);
			cprintf("%c",186);
		}
		
			gotoxy(40-20,y-3);
			cprintf("%c",200);
		
		for(a=40-19;a<40+20;a++)
		{
			gotoxy(a,y-3);
			cprintf("%c",205);
		}
			
			gotoxy(40+20,y-3);
			cprintf("%c",188);
		
		for(a=1;a<y-3;a++)
		{
			gotoxy(40+20,a);
			cprintf("%c",186);
		}
	
}

void Notas(int indice)
{
	int x,y,Lectura1,Lectura2,Seleccion_x,Seleccion_y,Seleccion,i,bolTemp[MAXCURSOS],Separacion;
	clrscr();
	x=MARGIN-5;
	y=8;
	Seleccion_x=x;
	Seleccion_y=y+2;
	Seleccion=1;
	Lectura1=0;
	Separacion=35;
	
	while(Seleccion!=5)
	{
		
		
			
			Dibujo2(5,13);
			textcolor(WHITE);
			gotoxy(40-13,y-6);
			cprintf("REGISTRO ACADEMICO UNI-RUSB");
			gotoxy(40-2,y-4);
			cprintf("NOTAS");
			gotoxy(x,y);
			cprintf("  I SEMESTRE");
			
			gotoxy(x,y+2);
			
			if (Alumno[indice].bolCursos[0]==0)
			{
				textcolor(8);
				cprintf("  Introduccion a Ing. en Comp.:");
			}
			else
			{
				textcolor(WHITE);
				cprintf("  Introduccion a Ing. en Comp.: %d",Alumno[indice].Cursos[0]);
			}
			
			gotoxy(x,y+4);
			
			if (Alumno[indice].bolCursos[1]==0)
			{
				textcolor(8);
				cprintf("  Geometria Analitica:");
			}
			else
			{
				textcolor(WHITE);
				cprintf("  Geometria Analitica: %d",Alumno[indice].Cursos[1]);
			}
			
			gotoxy(x,y+6);
			
			if (Alumno[indice].bolCursos[2]==0)
			{
				textcolor(8);
				cprintf("  Filosofia:");
			}
			else
			{
				textcolor(WHITE);
				cprintf("  Filosofia: %d",Alumno[indice].Cursos[2]);
			}
			
			gotoxy(x,y+8);
			
			if (Alumno[indice].bolCursos[3]==0)
			{
				textcolor(8);
				cprintf("  Ingles I:");
			}
			else
			{
				textcolor(WHITE);
				cprintf("  Ingles I: %d",Alumno[indice].Cursos[3]);
			}
			
			
			textcolor(9);
			
			gotoxy(x,y+10);
			
			cprintf("  Guardar cambios");
			
			textcolor(WHITE);
			
			gotoxy(x+Separacion,y);
			
			cprintf("  II SEMESTRE");
			
			gotoxy(x+Separacion,y+2);
			
			if (Alumno[indice].bolCursos[4]==0)
			{
				textcolor(8);
				cprintf("  Ingles II:");
			}
			else
			{
				textcolor(WHITE);
				cprintf("  Ingles II: %d",Alumno[indice].Cursos[4]);
			}
			
			gotoxy(x+Separacion,y+4);
			
			if (Alumno[indice].bolCursos[5]==0)
			{
				textcolor(8);
				cprintf("  Redaccion tecnica:");
			}
			else
			{
				textcolor(WHITE);
				cprintf("  Redaccion tecnica: %d",Alumno[indice].Cursos[5]);
			}

			gotoxy(x+Separacion,y+6);
			
			if (Alumno[indice].bolCursos[6]==0)
			{
				textcolor(8);
				cprintf("  Matematicas I:");
			}
			else
			{
				textcolor(WHITE);
				cprintf("  Matematicas I: %d",Alumno[indice].Cursos[6]);
			}
			
			gotoxy(x+Separacion,y+8);
			
			
			if (Alumno[indice].bolCursos[7]==0)
			{
				textcolor(8);
				cprintf("  Conceptos de lenguajes:");
			}
			else
			{
				textcolor(WHITE);
				cprintf("  Conceptos de lenguajes: %d",Alumno[indice].Cursos[7]);
			}
			
			gotoxy(x+Separacion,y+10);
			
			if (Alumno[indice].bolCursos[8]==0)
			{
				textcolor(8);
				cprintf("  Lenguajes de programacion:");
			}
			else
			{
				textcolor(WHITE);
				cprintf("  Lenguajes de programacion: %d",Alumno[indice].Cursos[8]);
			}
			
		while(Lectura1!=13)
		{
			
			textcolor(WHITE);
			
			gotoxy(Seleccion_x,Seleccion_y);
			cprintf("%c",62);
			
			gotoxy(x,y+14);
			
			/*Bloquer desmatricula si su nota esta aprobado*/
			
			/*cprintf("%d %d",Seleccion,indice);*/
			
			Lectura1=getch();
			if(Lectura1==0)Lectura2=getch();
			
			if((Lectura2==75)&&(Seleccion_x>x))
			{
				gotoxy(Seleccion_x,Seleccion_y);
				cprintf(" ");
				Seleccion-=5;
				Seleccion_x-=Separacion;
			}
			else if((Lectura2==77)&&(Seleccion_x<(x+Separacion)))
			{
				gotoxy(Seleccion_x,Seleccion_y);
				cprintf(" ");
				Seleccion+=5;
				Seleccion_x+=Separacion;
			}
			else if((Lectura2==72)&&(Seleccion_y>(y+2)))
			{
				gotoxy(Seleccion_x,Seleccion_y);
				cprintf(" ");
				Seleccion--;
				Seleccion_y-=2;
			}
			else if((Lectura2==80)&&(Seleccion_y<(y+10)))
			{
				gotoxy(Seleccion_x,Seleccion_y);
				cprintf(" ");
				Seleccion++;
				Seleccion_y+=2;
			}
			Lectura2=0;
		
			
		
		}
		Lectura1=0;
		
		
		if(Seleccion<5)
		{	
			if (Alumno[indice].bolCursos[Seleccion-1]==1)
			{
				clrscr();
				Dibujo2(5,13);
				textcolor(WHITE);
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-2,y-4);
				cprintf("NOTAS");
				gotoxy(40-16,y);
				cprintf("Ingrese la nota correspondiente:");
				gotoxy(40-16,y+2);
				Alumno[indice].Cursos[Seleccion-1]=intValidacion();
				
				while (Alumno[indice].Cursos[Seleccion-1]<0 || Alumno[indice].Cursos[Seleccion-1]>100)
				{
					clrscr();
					Dibujo2(5,13);
					textcolor(WHITE);
					gotoxy(40-13,y-6);
					cprintf("REGISTRO ACADEMICO UNI-RUSB");
					gotoxy(40-2,y-4);
					cprintf("NOTAS");
					gotoxy(40-12,y);
					cprintf("Valor ingresado invalido");
					gotoxy(40-16,y+2);
					cprintf("Ingrese la nota correspondiente:");
					gotoxy(40-16,y+4);
					Alumno[indice].Cursos[Seleccion-1]=intValidacion();
					
				}
				clrscr();
			}
		}
		else if (Seleccion>5 && Seleccion<11)
		{
			
			if (Alumno[indice].bolCursos[Seleccion-2]==1)
			{
				clrscr();
				Dibujo2(5,13);
				textcolor(WHITE);
				gotoxy(40-13,y-6);
				cprintf("REGISTRO ACADEMICO UNI-RUSB");
				gotoxy(40-2,y-4);
				cprintf("NOTAS");
				gotoxy(40-16,y);
				cprintf("Ingrese la nota correspondiente:");
				gotoxy(40-16,y+2);
				Alumno[indice].Cursos[Seleccion-2]=intValidacion();
				
				while (Alumno[indice].Cursos[Seleccion-2]<0 || Alumno[indice].Cursos[Seleccion-2]>100)
				{
					clrscr();
					Dibujo2(5,13);
					textcolor(WHITE);
					gotoxy(40-13,y-6);
					cprintf("REGISTRO ACADEMICO UNI-RUSB");
					gotoxy(40-2,y-4);
					cprintf("NOTAS");
					gotoxy(40-12,y);
					cprintf("Valor ingresado invalido");
					gotoxy(40-16,y+2);
					cprintf("Ingrese la nota correspondiente:");
					gotoxy(40-16,y+4);
					Alumno[indice].Cursos[Seleccion-2]=intValidacion();
					
				}
				clrscr();
			}
			
		}
		
	}
	
	
}

void Clases(int indice)
{
	int x,y,Lectura1,Lectura2,Seleccion_x,Seleccion_y,Seleccion,i,bolTemp[MAXCURSOS],ConbolTemp;
	clrscr();
	x=MARGIN;
	y=8;
	Seleccion_x=x;
	Seleccion_y=y+2;
	Seleccion=1;
	Lectura1=0;
	ConbolTemp=0;
	
	for(i=0;i<MAXCURSOS;i++)
	{
		bolTemp[i]=Alumno[indice].bolCursos[i];
	}
	
	while(Seleccion!=5 || ConbolTemp==0)
	{
		
			/*clrscr();*/
			
			Dibujo2(3,11);
			textcolor(WHITE);
			gotoxy(40-13,y-6);
			cprintf("REGISTRO ACADEMICO UNI-RUSB");
			gotoxy(40-5,y-4);
			cprintf("MATRICULAR");
			gotoxy(x,y);
			cprintf("  I SEMESTRE");
			if (Alumno[indice].Cursos[0]>=60)
				textcolor(14);
			else
			{
				if (bolTemp[0]==0)textcolor(WHITE);
				else textcolor(10);
			}
			
			gotoxy(x,y+2);
			cprintf("  Introduccion a Ing. en Comp.");
			
			if (Alumno[indice].Cursos[1]>=60)
				textcolor(14);
			else
			{
				if (bolTemp[1]==0)textcolor(WHITE);
				else textcolor(10);
			}
			
			gotoxy(x,y+4);
			cprintf("  Geometria Analitica");
			
			if (Alumno[indice].Cursos[2]>=60)
				textcolor(14);
			else
			{
				if (bolTemp[2]==0)textcolor(WHITE);
				else textcolor(10);
			}
			
			gotoxy(x,y+6);
			cprintf("  Filosofia");
			
			if (Alumno[indice].Cursos[3]>=60)
				textcolor(14);
			else
			{
				if (bolTemp[3]==0)textcolor(WHITE);
				else textcolor(10);
			}
			
			gotoxy(x,y+8);
			cprintf("  Ingles I");
			
			textcolor(9);
			
			gotoxy(x,y+10);
			cprintf("  Guardar cambios");
			
			textcolor(WHITE);
			
			gotoxy(x+33,y);
			cprintf("  II SEMESTRE");
			
			if (Alumno[indice].Cursos[4]>=60)
				textcolor(14);
			else
			{
				if (bolTemp[4]==0)textcolor(WHITE);
				else textcolor(10);
			}
			
			gotoxy(x+33,y+2);
			cprintf("  Ingles II");
			
			gotoxy(x+33,y+4);
			
			if (Alumno[indice].Cursos[5]>=60)
				textcolor(14);
			else
			{
				if (bolTemp[5]==0)textcolor(WHITE);
				else textcolor(10);
			}
			
			cprintf("  Redaccion tecnica");
			gotoxy(x+33,y+6);
			
			if (Alumno[indice].Cursos[6]>=60)
				textcolor(14);
			else
			{
				if (bolTemp[6]==0)textcolor(WHITE);
				else textcolor(10);
			}
			
			cprintf("  Matematicas I");
			gotoxy(x+33,y+8);
			
			if (Alumno[indice].Cursos[7]>=60)
				textcolor(14);
			else
			{
				if (bolTemp[7]==0)textcolor(WHITE);
				else textcolor(10);
			}
			
			cprintf("  Conceptos de lenguajes");
			gotoxy(x+33,y+10);
			
			if (Alumno[indice].Cursos[8]>=60)
				textcolor(14);
			else
			{
				if (bolTemp[8]==0)textcolor(WHITE);
				else textcolor(10);
			}
			
			cprintf("  Lenguajes de programacion");
			
		while(Lectura1!=13)
		{	
			textcolor(WHITE);
			
			gotoxy(Seleccion_x,Seleccion_y);
			cprintf("%c",62);
			
			gotoxy(x,y+14);
			
			/*Bloquer desmatricula si su nota esta aprobado*/
			
			/*cprintf("%d",Seleccion);*/
			
			Lectura1=getch();
			if(Lectura1==0)Lectura2=getch();
			
			if((Lectura2==75)&&(Seleccion_x>x))
			{
				gotoxy(Seleccion_x,Seleccion_y);
				cprintf(" ");
				Seleccion-=5;
				Seleccion_x-=33;
			}
			else if((Lectura2==77)&&(Seleccion_x<(x+33)))
			{
				gotoxy(Seleccion_x,Seleccion_y);
				cprintf(" ");
				Seleccion+=5;
				Seleccion_x+=33;
			}
			else if((Lectura2==72)&&(Seleccion_y>(y+2)))
			{
				gotoxy(Seleccion_x,Seleccion_y);
				cprintf(" ");
				Seleccion--;
				Seleccion_y-=2;
			}
			else if((Lectura2==80)&&(Seleccion_y<(y+10)))
			{
				gotoxy(Seleccion_x,Seleccion_y);
				cprintf(" ");
				Seleccion++;
				Seleccion_y+=2;
			}
			Lectura2=0;
		
			
		
		}
		Lectura1=0;
		
		
		if(Seleccion<5)
		{	
			if (Alumno[indice].Cursos[Seleccion-1]<60)
			{
				if(bolTemp[Seleccion-1]==0)
					bolTemp[Seleccion-1]=1;
				
				else if(bolTemp[Seleccion-1]==1)
					bolTemp[Seleccion-1]=0;
				
			}
		}
		else if (Seleccion==6)
		{
			
			if(Alumno[indice].Cursos[3]>=60)
			{
				if (Alumno[indice].Cursos[Seleccion-2]<60)
				{
				
					if(bolTemp[Seleccion-2]==0)
						bolTemp[Seleccion-2]=1;
					
					else if(bolTemp[Seleccion-2]==1)
						bolTemp[Seleccion-2]=0;
				}

			}
			
		}
		else if (Seleccion>6 && Seleccion<10)
		{
			if (Alumno[indice].Cursos[Seleccion-2]<60)
			{
				
				if(bolTemp[Seleccion-2]==0)
					bolTemp[Seleccion-2]=1;
				
				else if(bolTemp[Seleccion-2]==1)
					bolTemp[Seleccion-2]=0;
				
			}
		}
		else if (Seleccion==10)
		{
			
			if(Alumno[indice].Cursos[0]>=60)
			{
				if (Alumno[indice].Cursos[Seleccion-2]<60)
				{
					if(bolTemp[Seleccion-2]==0)
						bolTemp[Seleccion-2]=1;
					
					else if(bolTemp[Seleccion-2]==1)
						bolTemp[Seleccion-2]=0;
				}
			}
			
		}
		
		ConbolTemp=0;

		for (i=0;i<MAXCURSOS;i++)
		{
			if (bolTemp[i]==1)
				ConbolTemp++;
		}
		
	}
	
	clrscr();
	
	for (i=0;i<MAXCURSOS;i++)
	{
		Alumno[indice].bolCursos[i]=bolTemp[i];
	}
	

}

void Carnet(int indice)
{
	int anyo,i,anyorest,Nucartem,Nucartemrest;
	char Car_Tem[MAX];
	time_t Presente;
	struct tm *Anyovi;
	clrscr();
	
	anyorest=0;
	time(&Presente);
	Anyovi=localtime(&Presente);
	anyo=(Anyovi->tm_year)+1900;
	
	
	for (i=0;i<4;i++)
	{
		Car_Tem[i]='0'+(floor(anyo/pow(10,3-i)));
		
		anyorest=(pow(10,3-i)*floor(anyo/pow(10,3-i)));
		
		anyo=anyo-anyorest;
	}
	
	Car_Tem[4]='-';
	
	if(NumCar>=9090)NumCar=0;
	else NumCar+=10;
	
	Nucartem=NumCar;
	
	
	for (i=5;i<9;i++)
	{
		Car_Tem[i]='0'+(floor(Nucartem/pow(10,3-(i-5))));
		
		Nucartemrest=(pow(10,3-(i-5))*floor(Nucartem/pow(10,3-(i-5))));
		
		Nucartem=Nucartem-Nucartemrest;
	}
	
	Car_Tem[9]='U';
	
	Car_Tem[10]='\0';
	
	stpcpy(Alumno[indice].Carnet,Car_Tem);
	
}
 
 int Acceso(void)
{
	char Usuario[MAX],Contra[MAX],UsuCom[MAX],ConCom[MAX];
	int Verificacion,Intentos,x,y,i;
	FILE *Acc;
	
	x=6+MARGIN;
	y=8;

	fflush(stdin);

	textcolor(WHITE);

	Intentos=3;

	do
	{
		clrscr();
		
		Dibujo2(2,10);
		
		textcolor(WHITE);
		
		gotoxy(40-13,y-6);
		cprintf("REGISTRO ACADEMICO UNI-RUSB");
		gotoxy(40-6,y-4);
		cprintf("CREDENCIALES");
		gotoxy(40-11,y);
		cprintf("Usted tiene %d intentos.",Intentos);
		gotoxy(40-14,y+4);
		cprintf("Ingrese su nombre de Usuario:");
		gotoxy(40-14,y+6);
		SoloCarValidacion(UsuCom,0,MAX);
		gotoxy(40-14,y+8);
		cprintf("Ingrese su contrasena:");
		gotoxy(40-14,y+10);
		CarNumSigValidacion(ConCom,1,MAX);
		i=0;
		
		Acc=fopen( "C:\\FileC\\ACCESO.txt", "r" );
		
		while(i<3 && Verificacion!=0)
		{
			fscanf(Acc,"%s %s ",Usuario,Contra);
			Verificacion=verifi(UsuCom,ConCom,Usuario,Contra);
			i++;
			
		}
		
		fclose(Acc);
		
		Intentos--;

	}
	while(Verificacion!=0 && Intentos>0);

	if(Verificacion==0 && i!=3)return 1;
	else if (Verificacion==0 && i==3)return 2;
	else return 0;


}
 
 int verifi(char * nombre,char * contra,char * nombrev,char * contrav)
{

	int ComCU,ComCC,ComU,ComC,ConCom,i;

	ConCom=0;
	i=0;

	ComCU=strcmp(nombrev,nombre);

	if (ComCU<=0)
	{
		ComU=(strlen(nombre));
	}
	else
	{
		ComU=(strlen(nombrev));
	}

	while(i!=ComU)
	{
		if(nombrev[i]!=nombre[i])
		{
			ConCom++;
		}
		i++;
	}
	i=0;

	ComCC=strcmp(contrav,contra);

	if (ComCC<=0)
	{
		ComC=(strlen(contra));
	}
	else
	{
		ComC=(strlen(contrav));
	}

	while(i!=ComC)
	{
		if(contrav[i]!=contra[i])
		{
			ConCom++;
		}
		i++;
	}
	return ConCom;
}

