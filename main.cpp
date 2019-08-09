#include<bits/stdc++.h>
#include"Execution.h"
#include"Validation.h"
#include"Memory_Allocation.h"
using namespace std;

//SIDDHANT THAPLIYAL 8085 SIMULATOR

int main(int argc , char*argv[])
{
	map<string,string> memory;
	vector<string> sequence;
	string input;
		ifstream infile("test.txt");
	if(argc!=0)	
	{
			ifstream infile(argv[1]);
	}
	string start="",pc="";
	string end="HLT",s;
	string registers[7];
	bool flag[8];
	for(int i=0;i<7;i++)
			registers[i]="";
	for(int i=0;i<8;i++)
			flag[i]=false;	
	cout<<"Starting Memory Address :: ";
	cin>>start;
	pc=start;
	/*if(memoryValidation(start))
	/{
				cout<<endl<<"INVALID/MEMORY ADDRESS OR RESERVED ADDRESS"<<endl;
					return 0;
	}*/	
	getline(infile,s);
	//cin>>s;
	while(s.compare(end))
	{
				//if(inputValidation(s))
				//{
					sequence.push_back(pc);
					memory[pc]=s;
					pc=allocate_memory(s,pc);
					getline(infile,s);
					//}		
				/*else
				{
							cout<<"INVALID INPUT"<<endl;
							return 0;	
			}*/
	}
	pc=start;
	int last=sequence.size()-1;
	while(pc.compare(sequence[last]))
	{
							pc=execute_statement(memory[pc],flag,registers,memory,pc);
	}
	cout<<"REGISTERS"<<endl;
	for(int i=0;i<7;i++)	
				cout<<registers[i]<<" ";
	cout<<endl;
	cout<<"flag"<<endl;
	for(int i=0;i<7;i++)	
				cout<<flag[i]<<" ";
	cout<<endl;
return 0;
}
