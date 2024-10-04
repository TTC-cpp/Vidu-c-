#include<string>
#include<utility>
#include<vector>
#include<memory>

using namespace std;

class Borrowable{
public:
	virtual void borrow() = 0;
	virtual void returnItem() = 0;
	virtual bool isAvailable() const = 0;
	virtual ~Borrowable() = default;
};

class Library{
private:
	vector<unique_ptr<Borrowable>> items;
	
public:
	void addItem(unique_ptr<Borrowable> item){
		items.push_back(move(item));
	}
	
	void borrowItem(const string& title){
		auto it = find_if(items.begin(), items.end(), [&title](const auto& item){
			if (auto book = dynamic_cast<Book*>(item.get())){
				return book->getTitle() == title;
			}
			if(auto dvd = dynamic_cast<DVD*>(item.get())){
				return dvd->getTitle() == title;
			}
			return false;
		});
		
		if(it != items.end()){
			(*it)->borrow();
		}
		else{
			cout<<"Khong tim thay muc ' "<<title<<" ' trong thu vien."<<endl;
		}
	}
};

int main(){
	return 0;
}


