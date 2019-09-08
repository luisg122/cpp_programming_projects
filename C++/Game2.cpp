#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
using namespace std;

char map[29][99];
int mapx,mapy,level;
int px,py,stx,sty;
int light=0;

void levechoose(){
	cout<<"Its a simple maze game, S means player, X means the wall and E is the play you need to find!"<<endl;
	cout<<"use w(move uop), s(move down), a(move left) d(move right) for control"<<endl;
	cout<<"please choose the level:"<<endl;
	cout<<"1 for easy, 2 for hard, 0 for death hard";
	cin>>level;
	switch(level){
		case 0:
			mapx=99;
			mapy=29;
			break;
		case 1:
			mapx=39;
			mapy=19;
			light=1;
			break;
		case 2:
			mapx=39;
			mapy=19;
			break;
	}
}
void setup(){
	px=1;
	py=rand()%mapy-2;
//	cout<<py<<endl;
}
void setmap(){
	stx=px;
	sty=py;
	int pos=0;
	int chance;
	
	for(int i=0;i<mapy;i++){
		for(int ii=0;ii<mapx;ii++){
			if(i==0||i==mapy-1||ii==0||ii==mapx-1){
				map[i][ii]='x';
			}
			else{
				map[i][ii]=' ';		
			}						// set empty map
		}
		
	}
	
	
	while(stx<mapx-2){
		
		map[sty][stx]='o';
		
		if(map[sty-1][stx]==' '){
			if(map[sty+1][stx]==' '){
				pos=1;}
			else{
				pos=2;
			}
		}
		else if(map[sty-1][stx]!=' '){
			if(map[sty+1][stx]==' '){
				pos=3;
			}
			else{
				pos=4;
			}			
		}
		

		switch(pos){
			case 1:
				chance=rand()%3;
			//	cout<<"case1";
				break;
			case 2:
				chance=rand()%2;
			//	cout<<"case2";
				break;
			case 3:
				chance=rand()%2;
				if(chance=1){
					chance++;
				}
			//	cout<<"case3";
				break;
			case 4:
				chance=0;
			//	cout<<"case4";
				break;
		}
		//cout<<chance;
		switch(chance){
			case 0:
				stx++;
				break;
			case 1:
				sty--;
				break;
			case 2:
				sty++;
				break;	
		}
	}
	
	for(int i=1;i<mapy-1;i++){
		for(int ii=1;ii<mapx-1;ii++){
			if(map[i][ii]=='o'){
				map[i][ii]=' ';
			}											//filled wall
			else{
				int bb=rand()%3;
				switch(bb){
					case 0:
						map[i][ii]='x';
						break;
					case 1:
						map[i][ii]='x';
						break;
					case 2:
						map[i][ii]=' ';
						break;
			
				}
			
			}
		}
	}
	map[sty][stx]='E';	
}
void drawmap(){
	map[py][px]='S';
	
	switch(light){
	case 0:
		for(int i=py-1;i<=py+1;i++){
			for(int ii=px-1;ii<=px+1;ii++){
				cout<<map[i][ii];
			}
			cout<<endl;
		}
		
		break;
	case 1:
		for(int i=0;i<mapy;i++){
			for(int ii=0;ii<mapx;ii++){
			cout<<map[i][ii];
			}
			cout<<endl;
		}
		break;			
	}

}

void control(){
	char action;
	action=getch();
	map[py][px]='.'; // control footprint
	if(action=='o'){
		light=1;
	}
	if(action=='w'&&map[py-1][px]!='x'){
		py--;
	}
	if(action=='s'&&map[py+1][px]!='x'){
		py++;
	}	
	if(action=='a'&&map[py][px-1]!='x'){
		px--;
	}	
	if(action=='d'&&map[py][px+1]!='x'){
		px++;
	}	
	system("cls");
}



int main(){
	srand(time(NULL));	
	levechoose();	
	setup();
	setmap();
	system("cls");
	drawmap();
	int gameover=0;
	while(!gameover){
	control();
	drawmap();		
	if(py==sty&&px==stx){
		gameover=1;
	}	
	}	
	cout<<"	You Win!";		
	return 0;
}
