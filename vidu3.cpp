#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Account {
protected:
	string accountNumber;
	string ownerName;
	double balance;
	
public:
	Account(string number, string name, double initalBalance) : accountNumber(number), ownerName(name), balance(initalBalance){}
	
	virtual void deposit(double amount){
		if(amount > 0){
			balance += amount;
			cout<<"Da nap "<<amount<<"vao tai khoan."<<endl;
		}
		else{
			cout<<"So tien khong hop le."<<endl;
		}
	}
	virtual bool withdraw(double amount){
		if(amount>0 && balance >= amount){
			balance -= amount;
			cout<<"Da rut "<<amount<<" tu tai khoan."<<endl;
			return true;
		}
		else{
			cout<<"khong the rut tien. So du khong du hoac so tien khong hop le."<<endl;
			return false;
		}
	}
	
	virtual void displayInfo() const{
		cout<<"So tai khoan: "<<accountNumber<<endl;
		cout<<"Chu tai khoan: "<<ownerName<<endl;
		cout<<"So du: "<<balance<<endl;
	}
	
	virtual ~Account(){}
};

class SavingAccount : public Account{
private:
	double interestRate;
	
public:
	SavingAccount(string number, string name, double initalBalance, double rate) : Account(number, name, initalBalance), interestRate(rate){}

	void applyInterest(){
		double interest = balance * interestRate;
		deposit(interest);
		cout<<"Da cong lai: "<<interest<<endl;
	}
	
	void displayInfo() const override{
		Account::displayInfo();
		cout<<"Lai suat: "<<(interestRate * 100)<<"%"<<endl;
	}
	
};

class CheckingAccount : public Account{
private:
	double overdraftLimit;
	
public:
	CheckingAccount(string number, string name, double initialBalance, double limit):Account(number, name, initialBalance), overdraftLimit(limit){}
	
	bool withdraw(double amount) override {
		if ( amount > 0 && (balance + overdraftLimit) >= amount){
			balance -= amount;
			cout<<"Da rut "<<amount<<" tu tai khoan."<<endl;
			return true;
		}
		else{
			cout<<"khong the rut tien. Vuot qua gioi han thau chi hoac so tien khong hop le."<<endl;
			return false;
		}
	}
	
	void displayInfo() const override{
		Account::displayInfo();
		cout<<"gioi han thau chi: "<<overdraftLimit<<endl;
	}
};

class Bank{
private:
	vector<Account*> accounts;
	
public:
	void addAccount(Account* account){
		accounts.push_back(account);
	}
	
	void displayAllAccount() const{
		for(const auto& account : accounts){
			account->displayInfo();
			cout<<"----------------------------------"<<endl;
		}
	}
	
	~Bank(){
		for(auto account : accounts){
			delete account;
		}
	}
};

int main(){
	Bank myBank;
	
	myBank.addAccount(new SavingAccount("SA001", "Nguyen Van A", 1000000, 0.05));
	myBank.addAccount(new CheckingAccount("CA001", "Tran Thi B", 200000, 500000));
	
	cout<<"Thong tin tat ca tai khoan: "<<endl;
	myBank.displayAllAccount();
	
return 0;
}

