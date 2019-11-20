#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
bool gameover;
const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100];
int nTail;
enum eDirection{STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;

void Setup(){
gameover=false;
dir=STOP;
x=width/2;
y=height/2;
fruitX=rand()%width;
fruitY=rand()%height;
score=0;
}

void Draw(){
system("cls");
for(int i=0;i<width+2;i++)
cout<<"*";
cout<<endl;
for(int i=0;i<height;i++){
for(int j=0;j<width;j++){

if(j==0)
cout<<"*";
if(i==y&&j==x)
cout<<"O";
else if(i==fruitY&&j==fruitX)
cout<<"@";
else{
bool print=false;
for(int k=0;k<nTail;k++){ 
if(tailX[k]==j&&tailY[k]==i){
cout<<"o";
print=true;
}
}
if(!print)
cout<<" " ;
}
if(j==width-1) cout<<"*";
}
cout<<endl;
}
for(int i=0;i<width+2;i++) cout<<"*";
cout<<endl;
cout<<"Score:"<<score<<endl;
}
void input()
{
	if(_kbhit())
	{
		switch(_getch())
		{
			case 'a':
				dir=LEFT;
				break;
			case 'd':
				dir=RIGHT;
				break;
			case 'w':
				dir=UP;
				break;
			case 's':
				dir=DOWN;
				break;
			case 'x':
				gameover=true;
				break;
		}
	}
}
void algorithm(){
int prevX =tailX[0];
int prevY=tailY[0];
int prev2X,prev2Y;
tailX[0]=x;
tailY[0]=y;
for(int i=1;i<nTail;i++)
{
	prev2X=tailX[i];
	prev2Y=tailY[i];
       /* tailX[i]=prevX;
	 tailY[i]=prevY;
	prevX=prev2X;
	prevY=prev2Y;*/
	tailX[i]=x;
		tailY[i]=y;
		prevX=prev2X;
		prevY=prev2Y;
}
	switch(dir)
	{
		case LEFT:
		x--;
		break;
		case RIGHT:
		x++;
		break;
		case UP:
		y--;
		break;	
		case DOWN:
		y++;
		break;
		default:
		break;
	}
	//uptaded==================if boundary touch
	if(x<0||x>width||y>height||y<0)
		gameover=true;
		//===========if self touch
		for(int i=0;i<nTail;i++)
	{
		if(x==tailX[i]&& y==tailY[i])
			gameover=true;
	}
	//=========
	if(x>=width) x=0; else if(x<0) x=width-1;
	if(y>=height) y=0; else if(y<0) y=height-1;

	/*for(int i=0;i<nTail;i++)  //pehle sara usme tha
	if(tailX[i]==x&& tailY[i]==y)
		gameover=true;*/
	if(x==fruitX && y==fruitY)
	{
		score+=10;
		fruitX =rand() % width;
		fruitY =rand() % height;
		nTail++;

	}
	}

int main(){
	int m,n;
     Setup();
     while(!gameover)
     {
	     Draw();
	     input();
	     algorithm();
     }
     for( m=0;m<100000;m++) //to slow
	{
		for(n=0;n<10000;n++)
		{
			
		}
	}
	for(m=0;m<1000;m++) //to slow
	{
		for(n=0;n<1000;n++)
		{
			
		}
	}
	return 0;
}

