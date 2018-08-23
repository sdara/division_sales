//header files
#include<iostream.h>
#include<iomanip.h>
#include<fstream.h>

//constant and global variable
const Elements=4;

//stucture for program
struct DivisionSales
{
	char DivisionName[10];
	float QuarterlySales[4];
};

//initialize the array of stuctures with elements and values
	DivisionSales NewDivSales[Elements] = {
	{"North"},
	{"South"},
	{"East"},
	{"West"},
		};


void main(void)
{

float CQSales=0,TYSDiv=0,TYCSales=0,AQSales=0,HighQ=0,LowQ=0,Tmp=0,TmpQtrH=0,TmpQtrL=0;

fstream inputFile;

inputFile.open("DivisionSales.dat",ios::in);




cout << setiosflags(ios::fixed | ios::right | ios::showpoint) << setprecision(2);

for(int x=0;x<4;x++)
{

for(int i=0;i<4;i++)
{
	
	
	inputFile >> NewDivSales[x].QuarterlySales[i];
	}
}

CQSales=0;

cout<<"================================\n";
cout<<"Total Corporate sales for each quarter\n";
cout<<"================================\n";


for(int a=0;a<4;a++)
{
CQSales=0;
cout<<"Quarter "<<a+1<<":"<<endl;
for(int b=0;b<4;b++)
{
	
	CQSales += NewDivSales[b].QuarterlySales[a];
	cout<<"Division "<<b+1<<": $"<<NewDivSales[b].QuarterlySales[a]<<endl;

}
cout<<"Total: $"<<CQSales<<endl<<endl;
}



	
cout<<"================================\n";
cout<<"Total Yearly Sales For Each Division\n";
cout<<"================================\n";


TYSDiv=0;

for(int c=0;c<4;c++)
{
TYSDiv=0;
cout<<"Division "<<c+1<<":"<<endl;
for(int d=0;d<4;d++)
{
	
	TYSDiv += NewDivSales[c].QuarterlySales[d];
	cout<<"Quarter "<<d+1<<": $"<<NewDivSales[c].QuarterlySales[d]<<endl;

}
cout<<"Total: $"<<TYSDiv<<endl<<endl;
}

cout<<"================================\n";
cout<<"Total Yearly Corporate Sales\n";
cout<<"================================\n";


TYCSales=0;

for(int e=0;e<4;e++)
{

for(int f=0;f<4;f++)
{
	
	TYCSales += NewDivSales[e].QuarterlySales[f];
	
}
}
cout<<"Total: $"<<TYCSales<<endl<<endl;

cout<<"================================\n";
cout<<"Average Quarterly Sales for the divisions\n";
cout<<"================================\n";

for(int g=0;g<4;g++)
{
AQSales=0;
cout<<"Quarter "<<g+1<<":"<<endl;
for(int h=0;h<4;h++)
{
	
	AQSales += NewDivSales[g].QuarterlySales[h];
	
}
AQSales=AQSales/4;
cout<<"Average: $"<<AQSales<<endl<<endl;
}

cout<<"================================\n";
cout<<"Highest/Lowest Quarters for the Corporation\n";
cout<<"================================\n";


for(int i=0;i<4;i++)
{
	Tmp=0;
for(int j=0;j<4;j++)
{
	
	Tmp += NewDivSales[i].QuarterlySales[j];

}
if(HighQ==0 && LowQ==0){
HighQ=Tmp;
LowQ=Tmp;
}

else if(HighQ<Tmp)	{
		HighQ=Tmp;
		TmpQtrH=i+1;
	}
	else if(Tmp<LowQ)
	{
		LowQ=Tmp;
		TmpQtrL=i+1;
	}
	
}
cout<<"Highest Quarter: "<<TmpQtrH<<endl<<"Highest Quarter (Total $): $"<<HighQ<<endl<<endl<<"Lowest Quarter: "<<TmpQtrL<<endl<<"Lowest Quarter (Total $): $"<<LowQ<<endl<<endl;

}

