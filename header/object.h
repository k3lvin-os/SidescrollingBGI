struct Object{
	int x , y;
	void *img;
	int xMove, yMove;
	int width, height;
	
	Object(int x, int y, int xMove, int yMove, int width, int height){
		this->x = x;
		this->y = y;
		this->xMove = xMove;
		this->yMove = yMove;
		this->width = width;
		this->height = height;			
	} 
};

