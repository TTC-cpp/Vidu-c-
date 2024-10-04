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

class DVD : public Borrowable{
private:
	string title;
	string director;
	int duration;
	bool available;
	
public:
	DVD(string t, string d, int dur) : title(move(t)), director(move(d)), duration(move(dur)), available(true){}
	
		void borrow() override{
		if(available){
			available = false;
			cout<<"Dia '"<<title<<"' da duoc muon."<<endl;
		}
		else{
			cout<<"Dia '"<<title<<"' khong co san de muon."<<endl;
		}
	}
	
	void returnItem() override{
		available = true;
		cout<<"Dia '"<<title<<"' da duoc tra lai."<<endl;
	}
	
	bool isAvailable() const override{
		return available;
	}
	
	string getTitle() const{return title;}
	string getDirector() const{return director;}
	int getDuration() const{return duration;}	
};

int main(){
	return 0;
}
