//#include<iostream>
//using namespace std;
//
//int main(int argc , char* argv[])
//{
//	cout<<"You have Entered: "<<argc<<" Arguments"<<endl;
//	
//	if(argc>1)
//	{
//		cout<<endl<<"The Arguments Entered are: "<<endl;	
//	for(int i=0;i<argc;i++)
//	{
//		cout<<"\n\tTHE VALUE IS: "<<argv[i]<<endl;
//		
//		for(int j=0;j<1;j++)
//		{
//			cout<<"\n\t-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-"<<endl;
//		}
//	}
//	}
//	else
//	{
//		cout<<"No Arguments Entered: "<<endl;
//	}
//}

#include<iostream>
using namespace std;

class Book{
	private:
		int ac;
		string title;
		int price;
	
	public:
		
		Book(int a,string t,float p):ac(a),title(t),price(p){}
		
		string toString()
		{
			return to_string(ac) + " " + title + " " + to_string(price);
		}
		
		float estimateprice(int tmpNoBooks)
		{
			return price * tmpNoBooks;
		}
		
		~Book()
		{
			cout<<"\n\tThe object "<<this->title<<" Has Been Deleted";
		}
};

int main()
{
	Book myBook(234,"Sapiens",2200);
	cout<<"Estimated Price("<<myBook.estimateprice(10)<<")";
	
	return 0;
}
