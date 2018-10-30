#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

typedef long long int ll;

struct node1{
	int x;
	int y;
	struct node1 * next;
	struct node1 * prev;	
}*start,*last;

typedef struct node1 * node;

node newnode(int x, int y){
	node temp = (node)malloc(sizeof(node));
	temp->x = x;
	temp->y = y;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void moveup(){
	node temp = newnode(start->x,start->y+1);
	temp->next = start;
	start->prev = temp;
	start = temp;
	last = last->prev;
	last->next = NULL;
	free(last->next);
}

void movedown(){
	node temp = newnode(start->x,start->y-1);
	temp->next = start;
	start->prev = temp;
	start = temp;
	last = last->prev;
	last->next = NULL;
	free(last->next);
}

void moveleft(){
	node temp = newnode(start->x-1,start->y);
	temp->next = start;
	start->prev = temp;
	start = temp;
	last = last->prev;
	last->next = NULL;
	free(last->next);
}

void moveright(){
	node temp = newnode(start->x+1,start->y);
	temp->next = start;
	start->prev = temp;
	start = temp;
	last = last->prev;
	last->next = NULL;
	free(last->next);
}

int main(){
	char c;
	cin >> c; // input char for input 		taking wasd control method
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

