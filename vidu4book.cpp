#include<iostream>
#include<string>
#include<utility>
#include<vector>

using namespace std;

class Borrowable{
public:
	virtual void borrow() = 0;
	virtual void returnItem() = 0;
	virtual bool isAvailable() const = 0;
	virtual ~Borrowable() = default;
};

class Book : public Borrowable{
private:
	string title;
	string author;
	string ISBN;
	bool available;
	
public:
	Book(string t, string a, string i) : title(move(t)), author(move(a)), ISBN(move(i)), available(true){}
	
	void borrow() override{
		if(available){
			available = false;
			cout<<"Sach '"<<title<<"' da duoc muon."<<endl;
		}
		else{
			cout<<"Sach '"<<title<<"' khong co san de muong."<<endl;
		}
	}
	
	void returnItem() override{
		available = true;
		cout<<"sach '"<<title<<"' da duoc tra lai."<<endl;
	}
	
	bool isAvailable() const override{
		return available;
	}
	
	string getTitle() const{return title;}
	string getAuthor() const{return author;}
	string getISBN() const{return ISBN;}	
};

int main(){
	return 0;
}
