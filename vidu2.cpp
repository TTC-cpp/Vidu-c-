#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Employee{
protected:
	int id;
	string name;
	int age;
	double salary;
	
	public:
		Employee(int _id, string _name, int _age, double _salary) : id (_id), name(_name), age(_age), salary(_salary) {}
		
	virtual void displayInfo() const{
		cout<<"ID: "<<id<<", Ten: "<<name<<", Tuoi: "<<age<<", Luong: "<<salary<<endl;	
	}
	
	virtual double getSalary() const{
		return salary;
	}
	void increaseSalary(double amount){
		salary += amount;
	}
};

class Manager : public Employee{
	private:
		int teamSize;
		
	public:
		Manager(int _id, string _name, int _age, int _salary, int _teamSize) : Employee(_id, _name, _age, _salary), teamSize(_teamSize){}
	
	void displayInfo() const override{
		Employee::displayInfo();
		cout<<"So nhan vien quan ly: "<<teamSize<<endl;
	}
	
	double getSalary() const override{
		return salary + (teamSize * 1000);
	}
};

class Company{
	private:
			vector<Employee*> employees;
		
	public:
		void addEmployee(Employee* emp){
			employees.push_back(emp);
		}
		
		void displayAllEmployees() const{
			for(const auto& emp : employees){
				emp->displayInfo();
				cout<<"----------------------"<<endl;
			}
		}	
		
		double getTotalSalary() const{
			double total = 0;
			for(const auto& emp : employees){
				total += emp->getSalary();
			}
			return total;
		}
		
		~Company(){
			for (auto emp : employees){
				delete emp;
			}
		}
};

int main(){
	Company myCompany;
	myCompany.addEmployee(new Employee(1, "Nguyen Van A", 30, 10000000));
	myCompany.addEmployee(new Employee(2, "Tran Thi B", 25, 8000000));
	myCompany.addEmployee(new Manager(3, "Le Van C", 40, 20000000, 5));
	
	cout<<"Thong tin tat ca nhien vien:" <<endl;
	myCompany.displayAllEmployees();
	
	cout<<"Tong luong cong ty: "<<myCompany.getTotalSalary()<<endl;
return 0;
}
