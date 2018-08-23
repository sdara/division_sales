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