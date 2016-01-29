#include <iostream>
#include "graphics.h"
#include "header/lamp.h"
#include "header/object.h"
using namespace std;

/*Busca e retorna uma imagem com as informações passadas por parâmetro*/
void* GetImage(char path[], int width, int height)
{
		
	void *pImg;
	readimagefile(path,0,0,width,height); 
	int size = imagesize(0,0,width,height);
	pImg = malloc(size);
	getimage(0,0,width,height,pImg); 
	return pImg;
}	

// Shows a protytpe of lamp on screen
void DisplayLamp(Lamp l)
{
	setcolor(l.color);
	setfillstyle(1,l.color);
	fillellipse(l.x,l.y,l.RADIUS,l.RADIUS);
}

// Moves a x and y position based in arrow key input
void Move(int *x, int *y, int amount)
{
	if(GetKeyState(VK_LEFT) & 0x80){
		*x -= amount;	
	}
	
	if(GetKeyState(VK_RIGHT) & 0x80){
		*x += amount;	
	}
	
	if(GetKeyState(VK_DOWN) & 0x80){
		*y+= amount;
	}
	
	if(GetKeyState(VK_UP) & 0x80){
		*y-= amount;
	}
}


// Move character based in the background (sidescrolling)
void SidescrollingMove(Object *character, Object *background, Object screen)
{
	
	
	
	if(GetKeyState(VK_RIGHT) & 0x80){
		
		if(character->x >= screen.width / 2)
		{
			background->x -= background->xMove;		
		}
		else
		{
			character->x += character->xMove;

		}		
	}
		
		

	
}


int main()
{
	
	
	const int FAKE_FPS = 30;
	const int SCREEN_HEIGHT = 600;
	const int SCREEN_WIDTH = 1200;
	
	void *temp;
	int pg = 1;
	
	initwindow(5736,SCREEN_HEIGHT,"Sidescrolling");
	setactivepage(pg);
	cout << "maxX =" << getmaxx(); 

	Object screen(0,0,0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	screen.img = malloc(imagesize(0,0,SCREEN_WIDTH,SCREEN_HEIGHT));
	getimage(0,0,SCREEN_WIDTH,SCREEN_HEIGHT,screen.img);
	
	Object background(0,0,10,0,5736,468);
	background.img = GetImage("street.bmp",5736,468);
	
	Object character(0,0,10,10,32,32);
	character.img = GetImage("Eua10.bmp",32,32);
	
	

	
	Lamp myLamp;	
	myLamp.x = myLamp.RADIUS * 2;
	myLamp.y = 200;
	myLamp.color = RED;
	
	setvisualpage(pg);
	while(1)
	{
		if(pg == 1)
			pg = 2;
		else
			pg = 1;
		setactivepage(pg);
		cleardevice();
		putimage(background.x,background.y,background.img,COPY_PUT);
		DisplayLamp(myLamp);
		putimage(character.x,character.y, character.img, COPY_PUT);
		setvisualpage(pg);
		SidescrollingMove(&character,&background,screen);
		
		delay(FAKE_FPS);
	
	}	
	free(background.img);	
	free(screen.img);
	free(character.img);
	return 0;
}
