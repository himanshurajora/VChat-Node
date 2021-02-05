#include<iostream>
using namespace std;

class Account{
	string name;
	int age;
	int accnumber;
	public:
	friend void display(Account a);
	void setdata(string fname, int fage, int faccnumber);
};

void Account::setdata(string fname, int fage, int faccnumber){
	name = fname;
	age = fage;
	accnumber = faccnumber;
	
}

void display(Account a){
	cout<<"*******************\n"<<a.name<<"\n"<<a.age<<"\n"<<a.accnumber<<"\n"<<"*******************\n"<<endl;
}

int main(){
	Account a1;
	a1.setdata("Himanshu Jangid", 17, 1503);
	display(a1);
	return 0;

}

