#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

void Logo (void);
void Carga (void);

void Logo (void)
{
	int x,y,i,j,Margin;
	clrscr();
	

	textcolor(BLUE);
	Margin=10;
	i=0;
	j=0;
	x=6+Margin;
	y=5;
	
	for(j=0;j<8;j++)
	{
		for(i=0;i<15;i++)
		{
			gotoxy(x+j,y+i);
			cprintf("%c",219);
			sound(155.56);
			delay(10);
			
			
		}
	}
				
	nosound();
	y=16;
	x=14+Margin;
	
	for(j=0;j<20;j++)
	{
		for(i=0;i<4;i++)
		{
			gotoxy(x+j,y+i);
			cprintf("%c",219);
			sound(185.00);
			delay(10);
			
		}
	}
	nosound();

	
	x=26+Margin;
	y=10;
	
	
	for(j=0;j<8;j++)
	{
		for(i=0;i<6;i++)
		{
			gotoxy(x+j,y+i);
			cprintf("%c",219);
			sound(207.65);
			delay(10);
			
		}
	}
	nosound();

	
	x=16+Margin;
	y=5;
	
	for(j=0;j<8;j++)
	{
		for(i=0;i<10;i++)
		{
			gotoxy(x+j,y+i);
			cprintf("%c",219);
			sound(233.08);
			delay(10);
			
		}
	}
	nosound();

	
	x=24+Margin;
	y=5;
	
	for(j=0;j<12;j++)
	{
		for(i=0;i<4;i++)
		{
			gotoxy(x+j,y+i);
			cprintf("%c",219);
			sound(277.18);
			delay(10);
			
		}
	}
	nosound();

	
	x=36+Margin;
	y=5;
	
	for(j=0;j<8;j++)
	{
		for(i=0;i<15;i++)
		{
			gotoxy(x+j,y+i);
			cprintf("%c",219);
			sound(233.08);
			delay(10);
			
		}
	}
	nosound();

	
	x=44+Margin;
	y=16;
	
	for(j=0;j<2;j++)
	{
		for(i=0;i<4;i++)
		{
			gotoxy(x+j,y+i);
			cprintf("%c",219);
			sound(207.65);
			delay(10);
			
		}
	}
	nosound();

	
	x=46+Margin;
	y=10;
	
	for(j=0;j<8;j++)
	{
		for(i=0;i<10;i++)
		{
			gotoxy(x+j,y+i);
			cprintf("%c",219);
			sound(185.00);
			delay(10);
			
		}
	}
	nosound();
	
	
	x=46+Margin;
	y=5;
	
	for(j=0;j<8;j++)
	{
		for(i=0;i<4;i++)
		{
			gotoxy(x+j,y+i);
			cprintf("%c",219);
			sound(155.56);
			delay(10);
			
		}
	}
	
	gotoxy(23,22);
	
	nosound();
	
	delay(469);

	sound(311.13);
	delay(117);

	sound(369.99);
	delay(117);

	sound(415.30);
	delay(117);

	sound(466.16);
	delay(117);

	sound(554.37);
	delay(117);

	sound(466.16);
	delay(117);

	sound(415.30);
	delay(117);

	sound(369.99);
	delay(117);

	sound(311.13);
	delay(117);

	nosound();

	textcolor(WHITE+BLINK);
	cprintf("Universidad Nacional de Ingenieria.");

	sleep(3);
}



void Carga (void)
{
int carga,j,i,k,h,bolEnter,Enter,x,y,Vx,Vy,Movix,Moviy;
float barra;

srand(time(NULL));

textcolor(WHITE);

x=33;
y=3;

Movix=rand()%2;
Moviy=rand()%2;

if(Movix==0)Vx=1;
else if (Movix==1)Vx=-1;
if (Moviy==0)Vy=1;
else if (Moviy==1)Vy=-1;




clrscr();

carga=0;
barra=0;
bolEnter=0;

i=0;
j=0;

gotoxy(40,15);

for(i=0;i<100;i++)
{
	
	clrscr();
	textcolor(WHITE);
	carga+=1;
	barra+=0.7;
	gotoxy(3,13);
	cprintf("%c",219);
	gotoxy(80-4,13);
	cprintf("%c",219);	
	gotoxy(5,13);
	j=0;
	while (j!=(floor(barra)))
	{
		if(j<10)textcolor(7);
		else if(j>=10 && j<20)textcolor(14);
		else if(j>=20 && j<30)textcolor(3);
		else if(j>=30 && j<40)textcolor(2);
		else if(j>=40 && j<50)textcolor(5);
		else if(j>=50 && j<60)textcolor(4);
		else if(j>=60 && j<70)textcolor(1);
		
		gotoxy(5+j,13);
		cprintf("%c",219);
		j++;
	}
	
	
	textcolor(BLUE);
	
		for(h=0;h<6;h++)
		{
			for(k=0;k<2;k++)
			{
			gotoxy(x+k,y+h);
			cprintf("%c",219);
			}
		}
		
		for(h=0;h<1;h++)
		{
			for(k=0;k<8;k++)
			{
			gotoxy(x+2+k,y+5+h);
			cprintf("%c",219);
			}
		}
		
		for(h=0;h<4;h++)
		{
			for(k=0;k<2;k++)
			{
			gotoxy(x+4+4+k,y+5-h);
			cprintf("%c",219);
			}
		}
		
		for(h=0;h<4;h++)
		{
			for(k=0;k<2;k++)
			{
			gotoxy(x+4+k,y+h);
			cprintf("%c",219);
			}
		}
		
		for(h=0;h<1;h++)
		{
			for(k=0;k<8;k++)
			{
			gotoxy(x+6+k,y+h);
			cprintf("%c",219);
			}
		}
		
		for(h=0;h<6;h++)
		{
			for(k=0;k<2;k++)
			{
			gotoxy(x+6+6+k,y+h);
			cprintf("%c",219);
			}
		}
		
		for(h=0;h<1;h++)
		{
			for(k=0;k<4;k++)
			{
			gotoxy(x+6+6+2+k,y+5+h);
			cprintf("%c",219);
			}
		}
		
		for(h=0;h<4;h++)
		{
			for(k=0;k<2;k++)
			{
			gotoxy(x+6+6+2+2+k,y+5-h);
			cprintf("%c",219);
			}
		}
		
		for(h=0;h<4;h++)
		{
			for(k=0;k<2;k++)
			{
			gotoxy(x+6+6+2+2+k,y);
			cprintf("%c",219);
			}
		}
		
		x+=Vx;
		y+=Vy;
		
		if((x+20)>=79)
		{
			sound(329.73);
			delay(25);
			sound(277.18);
			delay(25);
			nosound();
			Vx*=-1;
		}
		else if((x-1)<=1)
		{
			sound(329.73);
			delay(25);
			sound(277.18);
			delay(25);
			nosound();
			Vx*=-1;
		}	
		if((y+6)>=12)Vy*=-1;
		else if((y-1)<=1)Vy*=-1;
		
	
		/*
		
		*/
	
	
	textcolor(WHITE);
	gotoxy(40-7,15);
	cprintf("Cargando... %d \%",carga);
	
	
	if(i==49)delay(100);
	else if (i==74)delay(300);
	else if (i==89)delay(900);
	else if (i==98)delay(3000);
	else delay(40);
	
	
}

for(h=1;h<80;h++)
{
	for(k=1;k<12;k++)
	{
		gotoxy(h,k);
		printf("%c",0);
	}
}

textcolor(BLUE);

x=33;
y=3;

for(h=0;h<6;h++)
{
	for(k=0;k<2;k++)
	{
		gotoxy(x+k,y+h);
		cprintf("%c",219);
	}
}
		
for(h=0;h<1;h++)
{
	for(k=0;k<8;k++)
	{
		gotoxy(x+2+k,y+5+h);
		cprintf("%c",219);
	}
}
		
for(h=0;h<4;h++)
{
	for(k=0;k<2;k++)
	{
		gotoxy(x+4+4+k,y+5-h);
		cprintf("%c",219);
	}
}
		
for(h=0;h<4;h++)
{
	for(k=0;k<2;k++)
	{
		gotoxy(x+4+k,y+h);
		cprintf("%c",219);
	}
}
		
for(h=0;h<1;h++)
{
	for(k=0;k<8;k++)
	{
		gotoxy(x+6+k,y+h);
		cprintf("%c",219);
	}
}
		
for(h=0;h<6;h++)
{
	for(k=0;k<2;k++)
	{
		gotoxy(x+6+6+k,y+h);
		cprintf("%c",219);
	}
}
		
for(h=0;h<1;h++)
{
	for(k=0;k<4;k++)
	{
		gotoxy(x+6+6+2+k,y+5+h);
		cprintf("%c",219);
	}
}
		
for(h=0;h<4;h++)
{
	for(k=0;k<2;k++)
	{
		gotoxy(x+6+6+2+2+k,y+5-h);
		cprintf("%c",219);
	}
}
		
for(h=0;h<4;h++)
{
	for(k=0;k<2;k++)
	{
	gotoxy(x+6+6+2+2+k,y);
	cprintf("%c",219);
	}
}
		


textcolor(WHITE+BLINK);
gotoxy(40-13,17+3);
cprintf("Presiona Enter para continuar");

sound(261.63);
delay(234);
sound(392.00);
delay(117);
nosound();
delay(234);
sound(261.63);
delay(234);
sound(392.00);
delay(117);
nosound();
delay(234);

fflush(stdin);

while(bolEnter==0)
{


	while(kbhit())
	{
		Enter=getch();
		if (Enter==13)bolEnter=1;
	}
}

sound(277.18);
delay(25*5);
sound(329.73);
delay(25*5);
nosound();
	
}