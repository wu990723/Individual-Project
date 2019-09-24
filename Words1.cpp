
#include <stdio.h>
#include <tchar.h>
#include "iostream"
#include "iomanip"
#include "fstream"
#include "cstring"
using namespace std;
struct letterType
{
	char letter;
	int letterCount;
	double persent;
};
void giveLetter(letterType capital[],letterType minusClues[]);
void openFile(ifstream& infile,int& length,char text[]);
void count(letterType capital[],letterType minusClues[],char text[],int length,int& capitalCount,int& minusCount);
void PrintResult(letterType capital[],letterType minusClues[],int capitalCount,int minusCount,ofstream& outfile,char text[]);

int _tmain(int argc, _TCHAR* argv[])
{
	letterType capital[26];
	letterType minusClues[26];
	char text[10000];
	int length=0;
	int capitalCount=0;
	int minusCount=0;
	ifstream infile;
	ofstream outfile;
	strcpy(text,argv[1]);
	infile.open(text,ios::in);
	outfile.open(argv[2],ios::out);
    giveLetter(capital,minusClues);
	openFile(infile,length,text);
	count(capital,minusClues,text,length,capitalCount,minusCount);
	PrintResult(capital,minusClues,capitalCount,minusCount,outfile,text);
	return 0;
}
void giveLetter(letterType capital[],letterType minusClues[])
{
	int i;
	for (i=65;i<91;i++)
	{
        capital[i-65].letter=i;
        capital[i-65].letterCount=0;
	}
	for (i=97;i<123;i++)
	{
		minusClues[i-97].letter=i;
		minusClues[i-97].letterCount=0;
	}
}
void openFile(ifstream& infile,int& length,char text[])
{
	infile.get(text,10000);
	length=strlen(text);
}
void count(letterType capital[],letterType minusClues[],char text[],int length,int& capitalCount,int& minusCount)
{
	int i,j;
	for (i=0;i<length;i++)
	{
		for (j=0;j<26;j++)
		{
			if(minusClues[j].letter==text[i])
			{
				minusClues[j].letterCount++;
				break;
			}
		    else if (capital[j].letter==text[i])
		    {
				capital[j].letterCount++;
				break;
		    }

		}
	}
	for (i=0;i<26;i++)
	{
		capitalCount=capitalCount+capital[i].letterCount;
		minusCount=minusCount+minusClues[i].letterCount;
	}
	
}
void PrintResult(letterType capital[],letterType minusClues[],int capitalCount,int minusCount,ofstream& outfile,char text[])
{
	int i;
	outfile<<fixed<<setprecision(2);
	outfile<<text<<endl<<endl;
	for(i=0;i<26;i++)
	{
		capital[i].persent=(double)capital[i].letterCount/capitalCount;
		minusClues[i].persent=(double)minusClues[i].letterCount/minusCount;
	}

	if (minusCount==0&&capitalCount!=0)
	{
		outfile<<"该文档中没有小写字母。\n";
		outfile<<"字母    出现次数      百分比\n";
		for (i=0;i<26;i++)
			outfile<<left<<setw(10)<<capital[i].letter<<setw(12)<<capital[i].letterCount<<(double)capital[i].persent*100<<"%"<<endl;
	}
	else if (capitalCount==0&&minusCount!=0)
	{
		outfile<<"该文档中没有大写字母。\n";
		outfile<<"字母    出现次数      百分比\n";
		for (i=0;i<26;i++)
			outfile<<left<<setw(10)<<minusClues[i].letter<<setw(12)<<minusClues[i].letterCount<<(double)minusClues[i].persent*100<<"%"<<endl;

	}
	else
	{
	    outfile<<"字母    出现次数      百分比\n";
	    for (i=0;i<26;i++)
	        outfile<<left<<setw(10)<<minusClues[i].letter<<setw(12)<<minusClues[i].letterCount<<(double)minusClues[i].persent*100<<"%"<<endl;
	    outfile<<endl<<endl;
	    for (i=0;i<26;i++)
		    outfile<<left<<setw(10)<<capital[i].letter<<setw(12)<<capital[i].letterCount<<(double)capital[i].persent*100<<"%"<<endl;
	}
	
} 
