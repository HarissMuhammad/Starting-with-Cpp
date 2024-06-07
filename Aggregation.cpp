#include<iostream>
#include<vector>

using namespace std;

class Movie{
	string name;
	int year;
		
		public:
			Movie(string n,int y):name(n),year(y){}
			
		void setName(string);
		string getName();
		
		void setYear(int);
		int getYear();
			
		
		string getMovieDetails();
};

void Movie::setName(string tmpName)
{
	 name = tmpName;
}

string Movie::getName()
{
	return name;
}

void Movie::setYear(int tmpYear)
{
	year = tmpYear;
}

int Movie::getYear(){
	return year;
}

string Movie::getMovieDetails()
{
	return name + " ," + to_string(year);
}

class Director{
	string name;
	vector<Movie*> movi;
	
		public:
			Director(string n):name(n){}
			
		void addmovies(Movie*);
		void display();
	
		void setName(string tmpName)
		{
			tmpName = name;
		}
		
		string getName()
		{
			return name;
		}
};

void Director::addmovies(Movie *tmpMovie)
{
	movi.push_back(tmpMovie);
}

void Director::display()
{
	cout<<"Name: "<<getName()<<endl;
	cout<<"Movies->  ";
	for(Movie *tmpMovie : movi)
	{
		cout<<tmpMovie->getName()<<" ";
		cout<<tmpMovie->getYear()<<endl<<endl;
		
	}
}

int main()
{
	Movie obj1("kshhk",3423),obj2("32sdf",3424),obj3("fkjsnd",2344),obj4("fhsjdf",32424);
	
	Director dirObj("Christopher"),dirObj2("sjkfha");
	dirObj.addmovies(&obj1);
	
	dirObj.addmovies(&obj2);
	
	dirObj.display();
	
	dirObj2.addmovies(&obj3);
	dirObj2.addmovies(&obj4);
	dirObj2.display();
}
