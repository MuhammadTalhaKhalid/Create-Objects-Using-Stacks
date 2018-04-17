#include<iostream>
#include<stdio.h>
#include <unistd.h>
#include<cstdlib>
using namespace std;
class Point { //My main class
protected:
string name;
int age;
public:
 void input() {
	cout<<"Enter name: ";
	cin>>name;
	cout<<"Enter age: ";
	cin>>age;
	}
	void show() {
		cout<<name<<"\t"<<age<<endl;
	}
};
Point *p2[5]; //object pointer
int top=-1;
void push() { //push to create object
	if(top==4){
		cerr<<"Stack full!!\n";
		}else {
			p2[++top]=new Point; //store Address of the objects in array
			cout<<"Sucessfully created "<<top<<" Objct\n";
		}
	}

void pop() { //pop to remove objects
if(top==-1) {
	cerr<<"Stack is empty!!\n";
	}else {
		p2[top];
		top--;
		cout<<"Sucessfully Remove "<<top<<" Objct\n";
	}
}

void Menu() {
	cout<<"\t\t\t\tMain menu Data entry\n\n";
	cout<<"Press 1 to create new object\nPress 2 for Delete Object\nPress 3 for Data entry into object\nPress 4 to display\nPress 5 to exit\n";
}
int Choice;
string Get="y";
int main() 
{
	do {
		system("clear");
Menu();
cout<<"Choose from above: ";
cin>>Choice;
switch (Choice) { //Create my new object address and store it in pointer
	case 1:
	do {
		system("clear");
		cout<<"\t\t\t\tCreate Rooom\n\n";
	push();
	cout<<"Wana continue y/n : ";
	cin>>Get;
	}while(Get!="n");
	break;
	case 2:
	do { //elete the object address
		system("clear");
		cout<<"\t\t\t\tDelete Rooom\n\n";
	pop();
	cout<<"Wana continue y/n : ";
	cin>>Get;
	}while(Get!="n");
	break;
	case 3:
	system("clear");
	cout<<"\t\t\t\tEnter data into room\n\n";
	if(top==-1) {
		cerr<<"No room created!!\n";
		system("read -p Press any key to continue"); //for linux
		//system("pause");//Windows
	}else {
		for(int i=0;i<top+1;i++) {
			p2[i]->input();
		}
	}
	break;
	case 4:
	system("clear");
	cout<<"\t\t\t\tDisplay room data\n\n";
	if(top==-1) {
		cerr<<"No room created!!\n";
		system("read -p Press any key to continue"); //for linux
		//system("pause");//Windows
	}else {
		do {
		for(int i=0;i<top+1;i++) {
			p2[i]->show();
		}
		cout<<"Wana continue y/n: ";
		cin>>Get;
			}while(Get!="n");
	}
	break;
	}
}while(Choice!=5);
return 0;
}//end 