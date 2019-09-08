#include<iostream>
#include<conio.h>
#include<windows.h>
#include<cstdlib>
#include<ctime>
using namespace std;
int	mapx=61;
int	mapy=20;
char map[20][61];
int x=(mapx-1)/2;
int y=mapy-3;
int speed=100;
char motion;
int score=0;
int gameover=0;

void setdrop(){
	int slowdown=rand()%8;
	if(slowdown==0){
		int px=rand()%(mapx-3)+1;
		int py=rand()%3+1;
		map[py][px]='F';
	}
	if(slowdown==1){
		int px=rand()%(mapx-3)+1;
		int py=rand()%3+1;
		map[py][px]='B';			
	}
}
void drop(){
	for(int i=0;i<mapy;i++){
		for(int j=0;j<mapx;j++){
			if(map[i][j]=='F'){
				if(map[i+1][j]=='x'){
					map[i][j]=' ';
				}
				else if(map[i+1][j]=='_'){
					score++;
					map[i][j]=' ';
				}
				else{
					map[i][j]=' ';
					map[i+1][j]='f';
				}	
			}
		}
	}	
	for(int i=0;i<mapy;i++){
		for(int j=0;j<mapx;j++){
			if(map[i][j]=='f'){
				map[i][j]='F';}
    	}
	}
	
	for(int i=0;i<mapy;i++){
		for(int j=0;j<mapx;j++){
			if(map[i][j]=='B'){
				if(map[i+1][j]=='x'){
					map[i][j]=' ';
				}
				else if(map[i+1][j]=='_'){
					score--;
					map[i][j]=' ';
				}
				else{
					map[i][j]=' ';
					map[i+1][j]='b';
				}	
			}
		}
	}	
	for(int i=0;i<mapy;i++){
		for(int j=0;j<mapx;j++){
			if(map[i][j]=='b'){
				map[i][j]='B';}
    	}
	}
}

void setup(){	
//------------------------------------------------------------------------------------------	print map
	for(int i=0;i<mapy;i++){
		for(int j=0;j<mapx;j++){
			if(i==0||i==mapy-1||j==0||j==mapx-1||i==mapy-2){
				map[i][j]='x';
			}
			else{
				map[i][j]=' ';
			}
		}
	}
//--------------------------------------------------------------------------
	map[y][x]='_';
	map[y][x-1]='_';
	map[y][x+1]='_';
}
void draw(){
	system("cls");
	map[y][x]='_';
	map[y][x-1]='_';
	map[y][x+1]='_';
	for(int i=0;i<mapy;i++){
		for(int j=0;j<mapx;j++){
			cout<<map[i][j];
		}
	cout<<endl;
	}
	if(score==10){
		gameover=1;
	}
	else{
	cout<<score;
	}
}
void control(){
	if(_kbhit()){
	
		switch(_getch()){
			case 'a':
				motion='L';				
				break;
			case 'd':
				motion='R';		
				break;
			case 's':
				motion='s';		
				break;
		}
	}
	map[y][x]=' ';
	map[y][x-1]=' ';
	map[y][x+1]=' ';
}
void controllogic(){
	switch(motion){
		case 'L':
			if(x-2==0){
				motion='R';
			}			
			else{
				x=x-2;
			}
			break;
		case'R':
			if(x+2==mapx-1){
				motion='L';
			}			
			else{
				x=x+2;}			
			break;
		case's':
			break;
		default:
			break;
	}
}	





int main(){
	srand(time(NULL));	
	setup();
	while(!gameover){
	draw();
	drop();
	control();	
	controllogic();
	Sleep(speed);
	setdrop();
	}
	system("cls");
	cout<<"YOU WIN!!";
	return 0;
}
