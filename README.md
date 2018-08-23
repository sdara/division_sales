11-09-2004
CSC153-02
Project #07

Psuedocode


Part I – File Output (Write)
Include header files, function prototypes, and global variables for use within the program.

Create a structure defining division information and then create an array of 4 structures for each division.

Allow the user to enter the data for each dicision quarter by quarter.

At the end, output the data into a file called “DivisionSales.dat”, which will be in the same directory that this program runs from

Part II – File Input (Read)
Include header files, function prototypes, and global variables for use within the program.

Create a structure defining division information and then initialize this array with the names of the divisions.

Once the array has been initialized with names, open and read the “DivisionSales.dat” and take each value and store them into the structure/array.

Using the newly populated structure, calculate various information such as quarterly sales, division sales, total sales, average sales, and highest and lowest divisions.



Source Code (Part I)

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
 
void MakeDATFile(void);
 
void main(void)
{
 
 
 
 
 
 
 
 
cout << setiosflags(ios::fixed | ios::right | ios::showpoint) << setprecision(2);
 
for(int x=0;x<4;x++)
{
cout<<"===================================="<<endl;
	cout<<NewDivSales[x].DivisionName<<"ern Sales Figures:"<<endl;
	cout<<"===================================="<<endl;
for(int i=0;i<4;i++)
{
	
	do{
		cout<<"Please enter the "<< NewDivSales[x].DivisionName<<"ern sales figures for quarter "<<i+1<<"."<<endl<<endl;
	cin>>NewDivSales[x].QuarterlySales[i];
	if(NewDivSales[x].QuarterlySales[i]<0)
		cout<<endl<<" *** Please enter a NON negative number ***"<<endl<<endl;
	}while(NewDivSales[x].QuarterlySales[i]<0);
	cout<<endl;
}
}
	
MakeDATFile();
}
 
void MakeDATFile(void){
fstream inputFile;
 
inputFile.open("DivisionSales.dat",ios::out);
 
 
if(!inputFile)
{
	cout<<"Error creating file to write to!"<<endl<<endl;
	return;
}
 
for(int x=0;x<4;x++)
{
	
	for(int i=0;i<4;i++)
{
	
	inputFile<<NewDivSales[x].QuarterlySales[i]<<"\n";
}
}
inputFile.close();
 
cout << "Output file created successfully!"<<endl<<endl;
 
}

Output File (DivisionSales.dat)

123
456
678
978
6534
4
32
77
68
65
321
76
231
65
87
5

Source Code (Part II)

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

Program Output (Part I)

====================================
Northern Sales Figures:
====================================
Please enter the Northern sales figures for quarter 1.
 
123
 
Please enter the Northern sales figures for quarter 2.
 
456
 
Please enter the Northern sales figures for quarter 3.
 
678
 
Please enter the Northern sales figures for quarter 4.
 
978
 
====================================
Southern Sales Figures:
====================================
Please enter the Southern sales figures for quarter 1.
 
6534
 
Please enter the Southern sales figures for quarter 2.
 
4
 
Please enter the Southern sales figures for quarter 3.
 
32
 
Please enter the Southern sales figures for quarter 4.
 
77
 
====================================
Eastern Sales Figures:
====================================
Please enter the Eastern sales figures for quarter 1.
 
68
 
Please enter the Eastern sales figures for quarter 2.
 
65
 
Please enter the Eastern sales figures for quarter 3.
 
321
 
Please enter the Eastern sales figures for quarter 4.
 
76
 
====================================
Western Sales Figures:
====================================
Please enter the Western sales figures for quarter 1.
 
231
 
Please enter the Western sales figures for quarter 2.
 
65
 
Please enter the Western sales figures for quarter 3.
 
87
 
Please enter the Western sales figures for quarter 4.
 
5
 
Output file created successfully!
 
Press any key to continue


Program Output (Part II)

================================
Total Corporate sales for each quarter
================================
Quarter 1:
Division 1: $123.00
Division 2: $6534.00
Division 3: $68.00
Division 4: $231.00
Total: $6956.00
 
Quarter 2:
Division 1: $456.00
Division 2: $4.00
Division 3: $65.00
Division 4: $65.00
Total: $590.00
 
Quarter 3:
Division 1: $678.00
Division 2: $32.00
Division 3: $321.00
Division 4: $87.00
Total: $1118.00
 
Quarter 4:
Division 1: $978.00
Division 2: $77.00
Division 3: $76.00
Division 4: $5.00
Total: $1136.00
 
================================
Total Yearly Sales For Each Division
================================
Division 1:
Quarter 1: $123.00
Quarter 2: $456.00
Quarter 3: $678.00
Quarter 4: $978.00
Total: $2235.00
 
Division 2:
Quarter 1: $6534.00
Quarter 2: $4.00
Quarter 3: $32.00
Quarter 4: $77.00
Total: $6647.00
 
Division 3:
Quarter 1: $68.00
Quarter 2: $65.00
Quarter 3: $321.00
Quarter 4: $76.00
Total: $530.00
 
Division 4:
Quarter 1: $231.00
Quarter 2: $65.00
Quarter 3: $87.00
Quarter 4: $5.00
Total: $388.00
 
================================
Total Yearly Corporate Sales
================================
Total: $9800.00
 
================================
Average Quarterly Sales for the divisions
================================
Quarter 1:
Average: $558.75
 
Quarter 2:
Average: $1661.75
 
Quarter 3:
Average: $132.50
 
Quarter 4:
Average: $97.00
 
================================
Highest/Lowest Quarters for the Corporation
================================
Highest Quarter: 2.00
Highest Quarter (Total $): $6647.00
 
Lowest Quarter: 4.00
Lowest Quarter (Total $): $388.00
 
Press any key to continue
