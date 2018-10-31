#include<bits/stdc++.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

typedef long long int ll;

struct node1{
	int x;
	int y;
	struct node1 * next;
	struct node1 * prev;	
}*start,*last;

typedef struct node1 * node;

int arr[600][600] = {{0}};
for (int j=0;j<600;++j){
	arr[0][j] = 0;
	arr[599][j] = 0;
	putpixel(0,j,black);
	putpixel(599,j,black);
}
for (int j=0;j<600;++j){
	arr[j][0] = 0;
	arr[j][599] = 0;
	putpixel(j,0,black);
	putpixel(j,599,black);
}

node newnode(int x, int y){
	node temp = (node)malloc(sizeof(node));
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void startgame(){
	start = NULL;
	start = newnode(250,250);
	node temp = start;
	while (6--){
		putpixel(temp->x,temp->y,WHITE);
		arr[temp->x][temp->y] = 1;
		t = newnode(temp->x,temp->y + 1);
		temp->next = t;
		t->prev = temp;
		temp = t;
	}
	putpixel(temp->x,temp->y,WHITE);
	arr[temp->x][temp->y] = 1;
}

void moveup(){
	node temp = newnode(start->x,start->y+1);
	temp->next = start;
	start->prev = temp;
	start = temp;
	putpixel(start->x,start->y,WHITE);
	putpixel(last->x,last->y,BLACK);
	arr[start->x][start->y] = 0;
	arr[last->x][last->y] = 0;
	last = last->prev;
	last->next = NULL;
	free(last->next);
}

void movedown(){
	node temp = newnode(start->x,start->y-1);
	temp->next = start;
	start->prev = temp;
	start = temp;
	putpixel(start->x,start->y,WHITE);
	putpixel(last->x,last->y,BLACK);	
	arr[start->x][start->y] = 0;
	arr[last->x][last->y] = 0;
	last = last->prev;
	last->next = NULL;
	free(last->next);
}

void moveleft(){
	node temp = newnode(start->x-1,start->y);
	temp->next = start;
	start->prev = temp;
	start = temp;
	putpixel(start->x,start->y,WHITE);
	putpixel(last->x,last->y,BLACK);
	arr[start->x][start->y] = 0;
	arr[last->x][last->y] = 0;
	last = last->prev;
	last->next = NULL;
	free(last->next);
}

void moveright(){
	node temp = newnode(start->x+1,start->y);
	temp->next = start;
	start->prev = temp;
	start = temp;
	putpixel(start->x,start->y,WHITE);
	putpixel(last->x,last->y,BLACK);
	arr[start->x][start->y] = 0;
	arr[last->x][last->y] = 0;
	last = last->prev;
	last->next = NULL;
	free(last->next);
}

int main(){
	]
	char c;
	cin >> c; // input char for input 		taking w-a-s-d control method
	startgame();
	while (1){
		if (kbhit()){ // checking if any key was hitted by the user
			c = getch();
		}
		start->y;
		start->x;
		if (int(c) == 27) break; // checking if the key hitted was esc
		if (c == 'w') moveup();
		else if (c == 'a') moveleft();
		else if (c == 's') movedown();
		else if (c == 'd') moveright();
		
//		if (start->x == fruitx && start->y == fruity){
//				node temp = newnode(start->x+1,start->y);
//				temp->next = start;
//				start->prev = temp;
//				start = temp;
//		}
	}
	return 0;
}

