//		TUGAS UAP DASAR-DASAR PEMROGRAMAN

//	    GAME PACMAN

//		KELOMPOK 11
//		> Al Farinsqi Nayuga [2317051012]
//		> Dhimas Dzulfajri [2317051076]
//		> M.Rizky Pratama  [2317051008] 

// -----------------------------------------------------------------------------


#include <iostream>
#include <conio.h>
#include<curses.h>
#include <unistd.h>
#include <windows.h>
using namespace std;

void loading(){
	system("color F5");
	initscr();
	for (int y=0; y<3; y++){
		mvprintw(12,55,"Loading");
		mvprintw(13,50,"-----------------");
		mvprintw(14,50,"|                |");
		mvprintw(15,50,"-----------------");
	}
	for (int i=1; i<=2; i++){
		mvprintw(14,51,"                ");
	for (int f=1; f<=15; f++){
		mvprintw(14,50+f,">>");
		refresh();
		Sleep(500);
	}
	}
	endwin();
}

void game(){
	loading();
string arr[15][15];
int i,j;
int n=1,m=1;
char move;
int score = 0;
//penyimpanan peta
 
for(i = 0; i < 15; i++){
	for(j = 0; j < 15; j++)
	{
		cout<<arr[i][j];
	}
}

//design peta
for(i = 0; i < 15; i++){
	for(j = 0; j < 15; j++)
	{
	if(i==0||i==14){
		arr[i][j]="#";
	}
	else if(j==0||j==14){
		arr[i][j]="#";
	}
    else if (i == 3 && j > 2 && j<=10){
    	arr[i][j]="#";
	}
	 else if (i == 12 && j > 1 && j<=11){
    	arr[i][j]="#";
	}
	else if ( j == 10 && i > 2 && i<=10){
    	arr[i][j]="#";
	}
	else if ( j == 12 && i > 1 && i<=11){
    	arr[i][j]="#";
	}
	else if ( j == 2 && i > 2 && i<=10){
    	arr[i][j]="#";
	}



	else{
		arr[13][12]="F";
		arr[i][j]=".";
	}
	
	}
	
}

//mencetak map
arr[n][m]="<";
cout<<"\t\t\tScore: "<<score;
cout<<endl;
for(i = 0; i < 15; i++){
	for(j = 0; j < 15; j++)
	{
		cout<<arr[i][j]<<" ";
	}
	cout<<endl;
}
while(true){
	move = getche();
	if(move=='s'){
	  
	 n++;	
     if(n>0){
     	
     	arr[n-1][m]=" ";
	 }

	}
	if(move=='w'){
	  
	 n--;	
     if(n>0){
     	
     	arr[n+1][m]=" ";
	 }

	}
		if(move=='w'){
	  
	 n--;	
     if(n>0){
     	
     	arr[n+1][m]=" ";
	 }

	}
	if(move=='a'){
	  
	 m--;	
     if(m>0){
     	
     	arr[n][m+1]=" ";
	 }

	}
	if(move=='d'){
	  
	 m++;	
     if(m>0){
     	
     	arr[n][m-1]=" ";
	 }

	}
	
	if(arr[n][m]=="F"){
	system("cls");
	cout<<"FINISH";
	cout<<"\t\t\tScore: "<<score;
cout<<endl;
	break;
	}
	
	else if(arr[n][m]=="#"){
	system("cls");
	cout<<"GAME OVER\n";
	cout<<"NICE TRY";
	cout<<"\t\t\tScore: "<<score;
cout<<endl;
	break;
	}

	else if(arr[n][m]=="."){
		score+=1;
	}
	
	system("cls");
	arr[n][m]="<";
	arr[n][m]="<";
cout<<"\t\t\tScore: "<<score;
cout<<endl;
for(i = 0; i < 15; i++){
	for(j = 0; j < 15; j++)
	{
		cout<<arr[i][j]<<" ";
	}
	cout<<endl;
}
}
}
int main(){
	system("color 30");
menu:
int n;	
cout<<">>>>>>>>>> WELCOME <<<<<<<<<<\n";
cout<<endl;
cout<<"\tGame Menu\n";
cout<<"1. Play\n";
cout<<"2. Exit\n";
cout<<endl;
cout<<"Choice One:\n";
cin>>n;
if(n==1){
	system("cls");
	game();
	
}
else if(n==2){
	system("cls");
	cout<<"Lemah Banget Sih!";
}
else{
	system("cls");
	goto menu;
}
}
