#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

static int p = 0; //special element
struct bus_reservation
{
char busn[5],seat[8][4][10];
string driver, arrival, depart, from, to;
string empty, position;
} bus[10];
void vline(char ch){
    for(int i=70; i>0;i--)
    cout<<ch;
}
void installing()
{
cout<<"Enter bus no: ";
cin>>bus[p].busn;
cout<<"Enter Driver's name: ";
getline(cin.ignore(), bus[p].driver);
cout<<" Arrival time: ";
getline(cin.ignore(),bus[p].arrival);
cout<<" Departure: ";
getline(cin.ignore(),bus[p].depart);
cout<<" From: \t";
getline(cin,bus[p].from);
cout<<" To: \t";
getline(cin,bus[p].to);
p++;
}
void reservation()
{
int seat;
char number[5];
top:
cout<<"Bus no: ";
cin>>number;
int n;
for(n=0;n<=p;n++)
{
if(strcmp(bus[n].busn, number)==0)
break;
}
while(n<p)
{
cout<<"\nSeat Number: ";
cin>>seat;
if(seat>32)
{
cout<<"\nThere are only 32 seats available in this bus.";
}
else
{
if (strcmp(bus[n].seat[seat/4][(seat%4)], "Empty")==0)
{
cout<<"Enter passanger's name: ";
cin>>bus[n].seat[seat/4][(seat%4)];
break;
}
else
cout<<"The seat no. is already reserved.\n";
}
}
if(n>p)
{
cout<<"Enter correct bus no.\n";
goto top;
}
}
void empty()
{
for(int i=0; i<8;i++)
{
for(int j=0;j<4;j++)
{
strcpy(bus[p].seat[i][j], "Empty");
}
}
}
void show_reservation()
{
int n;
char number[5];
cout<<"Enter bus no: ";
cin>>number;
for(n=0;n<=p;n++)
{
if(strcmp(bus[n].busn, number)==0)
break;
}
while(n<=p)
{
vline('*');
cout<<"\nBus no:"<<bus[n].busn<<"\t\t\tDriver: "<<bus[n].driver
<<"\nArrival time: "<<bus[n].arrival<<"\t\tDeparture Time: "
<<bus[n].depart<<"\nFrom: "<<bus[n].from<<"\t\tTo: "
<<bus[n].to<<endl;
vline('*');
bus[0];
int a=1;
for (int i=0; i<8; i++)
{
for(int j=0;j<4;j++)
{
a++;
if(strcmp(bus[n].seat[i][j],"Empty")==0)
cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
}
}
break;
}
if(n>p)
cout<<"Enter correct bus no: ";
}
void position(int l)
{
int s=0;p=0;
for (int i =0; i<8;i++)
{
cout<<"\n";
for (int j = 0;j<4; j++)
{
s++;
if(strcmp(bus[l].seat[i][j], "Empty")==0)
{
cout.width(5);
cout.fill(' ');
cout<<s<<".";
cout.width(10);
cout.fill(' ');
cout<<bus[l].seat[i][j];
p++;
}
else
{
cout.width(5);
cout.fill(' ');
cout<<s<<".";
cout.width(10);
cout.fill(' ');
cout<<bus[l].seat[i][j];
}
}
}
cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
}
void avail()
{
for(int n=0;n<p;n++)
{
//vline('_');
cout<<"\nBus no:"<<bus[n].busn<<"\t\t\tDriver: "<<bus[n].driver
<<"\nArrival time: "<<bus[n].arrival<<"\t\tDeparture Time: "
<<bus[n].depart<<"\nFrom: "<<bus[n].from<<"\t\tTo: "
<<bus[n].to<<endl;
//vline('_');
}
}
int main()
{
    system("Color 2E");
//system("cls");
empty();
int w;
while(1)
{
//system("cls");
cout<<"\n\n\n\n\n";
cout<<"\t\t\t1.Install\n\t\t\t"
<<"2.Reservation\n\t\t\t"
<<"3.Show\n\t\t\t"
<<"4.Buses Available. \n\t\t\t"
<<"5.Exit";
cout<<"\n\t\t\tEnter your choice:-> ";
cin>>w;
switch(w)
{
case 1: installing();
break;
case 2: reservation();
break;
case 3: show_reservation();
break;
case 4: avail();
break;
case 5: exit(0);
}
}
return 0;
}