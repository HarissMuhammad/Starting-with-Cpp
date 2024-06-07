#include<iostream>
#include<string>
using namespace std;

class Book
{
	private:
		int accessionNo;
		string title;
		float price;
	
	public:
		Book(int An,string ti,float pr)
			: accessionNo(An),title(ti),price(pr){}
				
		void reset()
		{
			accessionNo = 0;
			title = "...";
			price = 0.0;
		}
		
		string tostring()
		{
			return to_string(accessionNo) + ", " + title + ", " + to_string(price);
		}
		
		~Book()
		{
			cout<<"\nThe object"<<this->title<<" has been deleted."<<endl;
		}		
				
};

class Library
{
	private:
		string name;
		Book cBook;
		Book *aBook;
		
	public:
		Library(string n,Book cb,Book* ab)
					:name(n),cBook(cb),aBook(ab){}
		
		void reset()
		{
			name = "..";
			cBook.reset();
			aBook->reset();	
		}
		
		string toString()
		{
			return "\n\t\t" + name + "\n\t\t" + cBook.tostring() +
										 "\n\t\t" + aBook->tostring();
		}
		
		~Library()
		{
			cout<<"\nThe Object " <<this->name <<" Has Been Deleted";
		}
								
};

int main ()
{
	Book bookInUet(243,"The Forest gump",2543.3);
	cout<<"\nBook in Uet ("<<addressof(bookInUet)<<")-> "<<bookInUet.tostring()<<endl;
	Book BookInHit(567,"The desert imp",7462.78);
	cout<<"\nBook in Hit("<<addressof(BookInHit)<<")-> "<<BookInHit.tostring()<<endl;
	
	Library Cuilib("CuiLib",bookInUet,&BookInHit);
	cout<<"\nCuiLibrary ("<<addressof(Cuilib)<<") ->"<<Cuilib.toString()<<endl; 
	
	cout<<"_____________________________________________________"<<endl;
	cout<<"\tResetting both the values"<<endl;
	bookInUet.reset();
	BookInHit.reset();
	
	cout<<bookInUet.tostring()<<endl;
	cout<<BookInHit.tostring()<<endl;
	
	cout<<"--------------------------------------------";
	cout<<"reprint"<<endl;
	
	cout<<Cuilib.toString()<<endl;
}
