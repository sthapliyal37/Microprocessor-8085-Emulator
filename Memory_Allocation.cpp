#include<bits/stdc++.h>
#include"Validation.h"
using namespace std;
string allocate_memory(string s,string pc)
{
		string size1[]={"MOV","LDAX","STAX","XCHG","ADD","DCR","INR","SUB","INX","DCX","CMP","CMA","DAD"};
		string size2[]={"ADI","SUI","MVI"};
		string size3[]={"LDA","LXI","STA","SHLD","LHLD","JMP","JC","JNC","JZ","JNZ","SET"};
		int num=0;
		int n=pc.length();
		for(int i=0;i<n;i++)
		{	
				int a=stoi(pc[i]);
				num=(num*10) + a; 
		}
		//cout<<num<<endl;
		//cout<<s<<endl;
		//cout<<split(s)<<endl;
		
		n=sizeof(size1)/sizeof(size1[0]);
		for(int i=0;i<n;i++)
		{
			if(!size1[i].compare(s)){
							pc=itos(num+1);
								return pc;
				}
				
				else if(!size1[i].compare(split(s))){
							pc=itos(num+1);
								return pc;
				}
		}
		n=sizeof(size2)/sizeof(size2[0]);
		for(int i=0;i<n;i++)
		{
				if(!size2[i].compare(s)){
								pc=itos(num+2);
								return pc;
				}			
				else if(!size2[i].compare(split(s))){
								pc=itos(num+2);
								return pc;
				}				
		}
		n=sizeof(size3)/sizeof(size3[0]);
		for(int i=0;i<n;i++)
		{
				if(!size3[i].compare(s)){
								pc=itos(num+3);
								return pc;
				}
				else if(!size3[i].compare(split(s))){
								pc=itos(num+3);
								
								return pc;
				}				
		}
}
