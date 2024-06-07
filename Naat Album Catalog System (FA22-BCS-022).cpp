#include<iostream>
#include<vector>
#include<stdexcept>
#include<string>


using namespace std;

class Album
{
		//Initializing Vector Method for chrcking duplicate Albums in Album Class	
	vector<Album>albums;
	int id;
	string title;
	string naatKha;
	int date;
	
		
	public:
		
		//Parameterized-Constructor for Album Class
			
		Album(int identity,string ttl,string nk,int dt): id(identity), title(ttl),naatKha(nk),date(dt) {}
		
		//Default constructor for Album Class		
		
		Album() : id(0),title(""),naatKha(""),date(0) {}		

		// defining get-set inside album class	

		void setId(int);
		int getId();
		
		void setTitle(string);
		string getTitle();
		
		void setNaatKha(string);
		string getNaatKha();
		
		void setDate(int);
		int getDate();
		
		string display()
		{
			return to_string(id) + ' ' + title + ' ' + naatKha +' '+ to_string(date);
		}
		
		string searchTitle(string searchedTitle)
		{
			if(searchedTitle==title)
			{
				cout<<"Title found :"<<title<<endl;
			}
			else
				cout<<"Title Not Found!"<<endl;
		}
//		Adding an album to the collection

		void addAlbum(int id,string title, string naatKha ,int date)
		{
			for (const Album& album : albums) 
			{
            	if (album.title == title && album.naatKha == naatKha) 
				{
                	throw runtime_error("Duplicate album found.");
            	}
        	}
			
			albums.push_back(Album(id,title,naatKha,date));
		}
		
//		Displaying the album to the Collection

		void displayAlbum()
		{
			for(Album& album : albums )
			{
				cout<<"Id: "<<album.id<<" ,Title: "<<album.title<<" ,Naatkha: "<<album.naatKha<<",Date: "<<endl;
			}
		}
		
		
};

		//Accessing Get-Set Outside Album Class

		void Album::setId(int i)
		{
			id = i;
		}
		int Album::getId()
		{
			return id;
		}
		
		void Album::setTitle(string t)
		{
			title = t;
		}
		
		string Album::getTitle()
		{
			return title;
		}
		
		void Album::setNaatKha(string n)
		{
			naatKha = n;
		}
		
		string Album::getNaatKha()
		{
			return naatKha;
		}
		
		void Album::setDate(int d)
		{
			date = d;
		}
		
		int Album::getDate()
		{
			return date;
		}


class Catalog
{
	
		//Initializing Vector Method for checking the duplicate albums in Catalog Class	
	vector<Album> ctlgAlbum;
	string albumName;
	Album naatObj;

		//Parameterized Constructor for Class Catalog
	public:
		Catalog(string an,Album &no): albumName(an), naatObj(no) {}
		
		//Default Constriuctor for Catalog class
		
		Catalog(): albumName(""),naatObj() {}
			
		//defining Getter setter for Catalog Attributes	
		
	void setAlbumName(string);
	string getAlbumName();
	
	void setNaatObj(Album);
	Album getNaatObj();
	
		//defining getter setter from Naat Album 
	
	void setCtlgId(int); 
	int getCtlgId();
		
	void setCtlgTitle(string);
	string getCtlgTitle();
		
	void setCtlgNaatKha(string);
	string getCtlgNaatKha();
		
	void setCtlgDate(int);
	int getCtlgDate();		
	
	string diplayCatalog()
	{
		return albumName + ' ' + naatObj.display(); 
	}
	
	void addAlbum(const Album& album) {
        ctlgAlbum.push_back(album);
    }
	
};

		//Accessing Get-Set outside Catalog Class	
void Catalog::setAlbumName(string an)
{
	albumName = an;
}

string Catalog::getAlbumName()
{
	return albumName;
}

void Catalog::setNaatObj(Album tmpNaatObj)
{
	naatObj = tmpNaatObj;
}

Album Catalog::getNaatObj()
{
	return naatObj;
}

		//Accessing Get-Set of Naat Album Outside Catalog Class	
		
	void Catalog::setCtlgId(int tmpId)
		{
			naatObj.setId(tmpId);
		}
		
	int Catalog::getCtlgId()
		{
			return naatObj.getId();
		}
		
		
	void Catalog::setCtlgTitle(string tmpTitle)
		{
			naatObj.setTitle(tmpTitle);
		}
		
	string Catalog::getCtlgTitle()
		{
			return naatObj.getTitle();
		}
		
		
	void Catalog::setCtlgNaatKha(string tmpNaatKha)
		{
			naatObj.setNaatKha(tmpNaatKha);
		}
		
	string Catalog::getCtlgNaatKha()
		{
			return naatObj.getNaatKha();
		}
		
		
	void Catalog::setCtlgDate(int tmpDate)
		{
			naatObj.setDate(tmpDate);
		}
		
	int Catalog::getCtlgDate()
		{
			return naatObj.getDate();
		}
		
		
int main(int argc, char* argv[])
{
		
//	For Displaying the collection of Albums
Album myalbums;
	try 
	{
		
	myalbums.addAlbum(23,"ehefh","jsjs",342);
	myalbums.addAlbum(24,"dfsdf","fgfs",234);
	myalbums.addAlbum(24,"dfsdf","fgfs",234);
	myalbums.displayAlbum();
	}
	catch(const runtime_error& except)
	{
		cout<< "Error: "<<except.what()<<endl;
	}

	//	Command_Line_Arguments 
	
	if (argc > 1)
	{
		cout<<endl<<"Arguments entered by user are:"<<endl;
		for (int i=1; i<argc; i++)
		{
			cout <<argv[i] <<endl;	
		}
	}
	else
		cout<<endl<<"No argument has been entered by the user";
		
	
	//Giving Arguments to the Album Constructor	
	Album obj1(12,"sda","sdad",123);
	Album obj2(11,"ghj","rty",463);
	
	//Get-Set in the Album Class	
	obj1.setId(23);
	obj1.setNaatKha("haris");
	obj1.setTitle("kjadh");
	obj1.setDate(1222);
	
	
	
	//Giving Arguments to the Catalog Class	
	Catalog ntalbum("asda",obj1);
	cout<<endl<<obj1.display()<<endl;
	
//	Finding title by name in Class
	obj1.searchTitle("kjadh");

	return 0;
}
