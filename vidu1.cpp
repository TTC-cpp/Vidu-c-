#include<iostream>
#include<string>

using namespace std;

class nhanvien{
	private:
		string ten;
		int tuoi;
		double giolam;
		
	public:
		nhanvien(string a, int b, double c) : ten(a), tuoi(b), giolam(c){}
		
		string getTen() const {return ten;}
		int getTuoi() const{return tuoi;}
		double getGiolam() const{return giolam;}
		
		void setTen(string a){ten = a;}
		void setTuoi(int b){tuoi = b;}
		void setGiolam(double c){giolam = c;}
		
		void displayInfo() const{
			cout<<"Ten: "<<ten<<endl;
			cout<<"Tuoi: "<<tuoi<<endl;
			cout<<"Gio lam: "<<giolam<<endl;
		}
};

int main(){
	nhanvien s1("Cao Tan Tai", 20, 3.5);
	cout<<"Thong tin sinh vien: "<<endl;
	s1.displayInfo();
	s1.setGiolam(3.8);
	
	cout<<"\nThong tin sau khi cap nhat gio lam: "<<endl;
	s1.displayInfo();
	
	return 0;
}
