//A C++ Program For Singing/Dance Competition
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
/*Function Prototypes*/
void add();      //To add a contestant to the file
void selects();  //To set status as ’S’ for a singing contestant
void selectd();  //To set status as ‘S’ for a dancing contestant
void wait(int&);   //To add a candidate to waiting list
void notsels();   //To set status as ‘N’ for a singing contestant
void notseld();  //To set status as ‘N’ for a dancing contestant
void menu();   //Displays a list of action that can be taken by the user
void dance();   //Displays a list of operations for a dancing contestant
void sing();   //Displays a list of operations for a singing contestant
void randcont(int&);   /*To randomly generate a contestant number who’d perform next*/
void contest();  //To view the details of all participants in file
void perform(int);  /*To display a list of operations to be done after a performance*/
void viewwait(); //Displays the dynamic wait list
void count();  //To set the number of records in counts and countd
int c,counts=0,countd=0,y=3;       //Global Objects
fstream f;
struct waiting
{
	int contno;
	char cate;
	waiting *next;
}*front,*rear;
class contestant
{
	int contno;
	char name[30];
	int age;
	char cat;
	char status;

	public:
	contestant()
	{
		contno=0;
		strcpy(name,"NULL");
		age=0;
		cat='0';
		status='0';
	}
	~contestant()
	{}
	void add();
	void display();
	void addstat(char);
	int returnno();
	friend void add();
}C1;
int contestant::returnno()
{
	return contno;
}
void contestant::add()
{
	clrscr();
	gotoxy(27,1);
	cout<<"World Talent Show 2017!";
	cout<<"\n\tEnter The Contestant Number : ";
	cin>>contno;
	cout<<"\n\tEnter The Name : ";
	gets(name);
	cout<<"\n\tEnter The Age : ";
	cin>>age;
	cout<<"\n\tEnter The Category(Dance-D/Sing-S): ";
	cin>>cat;
}
void contestant::display()
{
	clrscr();
	gotoxy(27,1);
	cout<<"World Talent Show 2017!";
	cout<<"\n\tContestant Number : "<<contno;
	cout<<"\n\tName : "<<name;
	cout<<"\n\tAge : "<<age;
	cout<<"\n\tCategory : "<<cat;
	cout<<"\n\tStatus : "<<status;
}
void contestant::addstat(char a)
{
	status=a;
}
void main()
{
	clrscr();
	char pass[7],s;
	front=NULL;
	rear=NULL;
	count();
	gotoxy(27,1);
	cout<<"World Talent Show 2017!";
	cout<<"\n\n\n\t\tEnter The Password : ";
	pass[6]='\0';
	for(int i=0;i<6;i++)
	{
	pass[i]=getch();
	}
	if(strcmp(pass,"pG9677")==0)
	menu();
	else
	{
	cout<<"\n\n\t\tAuthentication Error!";
	getch();
	exit(0);
	}
}
void menu()
{
	int o;
	do
	{
	clrscr();
	gotoxy(27,1);
	cout<<"World Talent Show 2017!";
	cout<<"\n\n\t1.Dance";
	cout<<"\n\n\t2.Singing";
	cout<<"\n\n\t3.Contestants Area";
	cout<<"\n\n\t4.View Waiting List";
	cout<<"\n\n\t5.Add Candidates";
	cout<<"\n\n\t6.Exit";
	cout<<"\n\tChoose Your Option : ";
	cin>>o;
	switch(o)
	 {
	case 1:dance();
		break;
	case 2:sing();
		break;
	case 3:contest();
		break;
	case 4:viewwait();
		break;
	case 5:add();
		break;
	case 6:exit(0);
	default:cout<<"\n\tEnter A Valid Choice!";
	 }
	delay(1000);
	}while(o!=6);
}
void count()
{
	f.open("contests.dat",ios::in|ios::binary);
	while(f.read((char*)&C1,sizeof(C1)))
		counts++;
	f.close();
	f.open("contestd.dat",ios::in|ios::binary);
	while(f.read((char*)&C1,sizeof(C1)))
		countd++;
	f.close();
}
void add()
{
	C1.add();
	if(C1.cat=='S')
	{
	if(counts==0)
	 {
	f.open("contests.dat",ios::out|ios::binary);
	f.write((char*)&C1,sizeof(C1));
	counts++;
	f.close();
	 }
	else
	 {
	f.open("contests.dat",ios::app|ios::binary);
	f.write((char*)&C1,sizeof(C1));
	counts++;
	f.close();
	 }
	}
	else
	{
	if(countd==0)
	 {
	f.open("contestd.dat",ios::out|ios::binary);
	f.write((char*)&C1,sizeof(C1));
	countd++;
	f.close();
	 }
	else
	 {
	f.open("contestd.dat",ios::app|ios::binary);
	f.write((char*)&C1,sizeof(C1));
	countd++;
	f.close();
	 }
	}
}
void dance()
{
	int p;
	do
	{
	clrscr();
	gotoxy(27,1);
	cout<<"World Talent Show 2017!";
	cout<<"\n\n\t1.Choose A Contestant";
	cout<<"\n\n\t2.Perform";
	cout<<"\n\n\t3.Singing Menu";
	cout<<"\n\n\t4.Main Menu";
	cout<<"\n\n\t5.Exit";
	cout<<"\n\n\tChoose Your Option : ";
	cin>>p;
	switch(p)
	 {
	case 1:randcont(1);
		break;
	case 2:perform(1);
		break;
	case 3:sing();
		break;
	case 4:menu();
		break;
	case 5:exit(0);
	default:cout<<"\n\tEnter A Valid Choice!";
	 }
	delay(1000);
	}while(p!=5);
}
void sing()
{
	int q;
	do
	{
	clrscr();
	gotoxy(27,1);
	cout<<"World Talent Show 2017!";
	cout<<"\n\n\t1.Choose A Contestant";
	cout<<"\n\n\t2.Perform";
	cout<<"\n\n\t3.Dance Menu";
	cout<<"\n\n\t4.Main Menu";
	cout<<"\n\n\t5.Exit";
	cout<<"\n\n\tChoose Your Option : ";
	cin>>q;
	switch(q)
	 {
	case 1:randcont(0);
		break;
	case 2:perform(0);
		break;
	case 3:dance();
		break;
	case 4:menu();
		break;
	case 5:exit(0);
	default:cout<<"\n\tEnter A Valid Choice!";
	 }
	delay(1000);
	}while(q!=5);
}
void contest()
{
	f.open("contests.dat",ios::in|ios::binary);
	while(f.read((char*)&C1,sizeof(C1)))
	{
	C1.display();
	getch();
	}
	f.close();
	f.open("contestd.dat",ios::in|ios::binary);
	while(f.read((char*)&C1,sizeof(C1)))
	{
	C1.display();
	getch();
	}
	f.close();

}
void randcont(int&a)
{
	clrscr();
	randomize();
	if(a==0)
	{
	 c=(random(counts)+1);
	gotoxy(27,1);
	cout<<"World Talent Show 2017!";
	cout<<"\n\n\t\tLucky Contestant Is : "<<c;
	}
	else
	{
	 c=(random(countd)+1);
	gotoxy(27,1);
	cout<<"World Talent Show 2017!";
	cout<<"\n\n\t\tLucky Contestant Is : "<<c;
	}

}
void perform(int x)
{
	int r;
	do
	{
	clrscr();
	gotoxy(27,1);
	cout<<"World Talent Show 2017!";
	cout<<"\n\n\t1.Selected";
	cout<<"\n\n\t2.Wait List";
	cout<<"\n\n\t3.Not Selected";
	cout<<"\n\n\t4.Main Menu";
	cout<<"\n\n\t5.Exit";
	cout<<"\n\n\tChoose Your Option : ";
	cin>>r;
	delay(3000);
	switch(r)
	 {
	case 1:if(x==0)
		selects();
		else
		selectd();
		break;
	case 2:wait(x);
		break;
	case 3:if(x==0)
		notsels();
		else
		notseld();
		break;
	case 4:menu();
		break;
	case 5:exit(0);
	default:cout<<"\n\tEnter A Valid Choice!";
	 }
	delay(1000);
	}while(r!=5);
}
void selects()
{
	ofstream f1;
	f.open("contests.dat",ios::in|ios::binary);
	f1.open("temp.dat",ios::out|ios::binary);
	while(f.read((char*)&C1,sizeof(C1)))
	{
	if(C1.returnno()==c)
	C1.addstat('S');
	f1.write((char*)&C1,sizeof(C1));
	}
	f1.close();
	f.close();
	remove("contests.dat");
	rename("temp.dat","contests.dat");
	clrscr();
	gotoxy(34,12);
	cout<<"Selected! :)";
	getch();
	menu();
}
void selectd()
{
	ofstream f1;
	f.open("contestd.dat",ios::in|ios::binary);
	f1.open("temp.dat",ios::out|ios::binary);
	while(f.read((char*)&C1,sizeof(C1)))
	{
	if(C1.returnno()==c)
	C1.addstat('S');
	f1.write((char*)&C1,sizeof(C1));
	}
	f1.close();
	f.close();
	remove("contestd.dat");
	rename("temp.dat","contestd.dat");
	clrscr();
	gotoxy(34,12);
	cout<<"Selected! :)";
	getch();
	menu();
}
void wait(int&b)
{
	clrscr();
	ofstream f1;
	if(b==0)
	{
	f.open("contests.dat",ios::in|ios::binary);
	f1.open("temp.dat",ios::out|ios::binary);
	while(f.read((char*)&C1,sizeof(C1)))
	 {
	if(C1.returnno()==c)
	C1.addstat('W');
	f1.write((char*)&C1,sizeof(C1));
	 }
	f1.close();
	f.close();
	remove("contests.dat");
	rename("temp.dat","contests.dat");
	}
	else
	{
	f.open("contestd.dat",ios::in|ios::binary);
	f1.open("temp.dat",ios::out|ios::binary);
	while(f.read((char*)&C1,sizeof(C1)))
	 {
	if(C1.returnno()==c)
	C1.addstat('W');
	f1.write((char*)&C1,sizeof(C1));
	 }
	f1.close();
	f.close();
	remove("contestd.dat");
	rename("temp.dat","contestd.dat");
	}
	waiting *temp=new waiting;
	if(temp==NULL)
	{
	cout<<"\nOut Of Memory!";
	menu();
	}
	else
	{
	temp->contno=c;
	if(b==0)
	temp->cate='S';
	else
	temp->cate='D';
	temp->next=NULL;
	}
	if(front==NULL)
	{
	front=temp;
	rear=temp;
	}
	else
	{
	rear->next=temp;
	rear=temp;
	}
	delete temp;
	clrscr();
	gotoxy(34,12);
	cout<<"Wait Listed! :|";
	getch();
	menu();
}
void notsels()
{
	ofstream f1;
	f.open("contests.dat",ios::in|ios::binary);
	f1.open("temp.dat",ios::out|ios::binary);
	while(f.read((char*)&C1,sizeof(C1)))
	{
	if(C1.returnno()==c)
	C1.addstat('N');
	f1.write((char*)&C1,sizeof(C1));
	}
	f1.close();
	f.close();
	remove("contests.dat");
	rename("temp.dat","contests.dat");
	clrscr();
	gotoxy(34,12);
	cout<<"Not Selected! :(";
	getch();
	menu();
}
void notseld()
{	ofstream f1;
	f.open("contestd.dat",ios::in|ios::binary);
	f1.open("temp.dat",ios::out|ios::binary);
	while(f.read((char*)&C1,sizeof(C1)))
	{
	if(C1.returnno()==c)
	C1.addstat('N');
	f1.write((char*)&C1,sizeof(C1));
	}
	f1.close();
	f.close();
	remove("contestd.dat");
	rename("temp.dat","contestd.dat");
	clrscr();
	gotoxy(34,12);
	cout<<"Not Selected! :(";
	getch();
	menu();
}
void viewwait()
{	waiting *tempo=front;
	clrscr();
	gotoxy(27,1);
	cout<<"World Talent Show 2017!";
	if(tempo==NULL)
	{
	cout<<"\n\tEmpty List!";
	getch();
	menu();
	}
	else
	{
	gotoxy(18,y);
	cout<<"Contestant Number";
	gotoxy(50,y);
	cout<<"Category";
	while(tempo!=NULL)
	 {
	gotoxy(18,y+2);
	cout<<tempo->contno;
	gotoxy(50,y+2);
	cout<<tempo->cate;
	tempo=tempo->next;
	  y+=2;
	delay(200);
	 }
} }