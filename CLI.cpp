#include<iostream>
using namespace std;

int main(int argc,char* argv[])
{
	cout<<"total arguments: "<<argc<<endl;
	cout<<"program name: "<<argv[0]<<endl;
	
	if(argc>1)
	{
		cout<<endl<<"arguments entered are: "<<endl;
		for(int i=1;i<argc;i++)
		{
			cout<<argv[i]<<endl;
		}
	}
	else
		cout<<"No Arguments entered by user: "<<endl;
	
	return 0;
}
