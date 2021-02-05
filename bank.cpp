#include<iostream>
 
 using namespace std;
 
 struct account
 {
 		string name;
 		int age;
 		int acnumber;
 		float acbalance;	
 };
 class bank{
 	public:
 	int lastaccount = 0;
 	int currentEditAccount = 0;
	struct account newaccount[100];
	void OpenNewAccount()
	{
		cout << "Enter New Account Name: ";
		cin >> newaccount[lastaccount].name;
		cout << "Enter Age: ";
		cin >> newaccount[lastaccount].age;
		cout << "Enter Account Number: ";
		cin >> newaccount[lastaccount].acnumber;
		cout << "Enter Account Balance: ";
		cin >> newaccount[lastaccount].acbalance;
		
		lastaccount++;	
		cout<<"\n\n";
//		cout<<"\n" << newaccount.name;
	}
	int SearchAccount(int accountNumber){
		int i;
		for(i = 0; i<lastaccount; i++){
			if(newaccount[i].acnumber == accountNumber){
				currentEditAccount = i;
				return i;
			}
			else{
				cout<<"No such account!!!!";
				break;
			}
		}
	}
	void ShowDetails(){
		int accountNumber;
		cout << "Enter Account Number: ";
		cin >> accountNumber;
		int i = SearchAccount(accountNumber);
		cout << "*****************Details******************\n";
		cout << "Account Name: " << newaccount[i].name << "\n";
		cout << "Age: " << newaccount[i].age << "\n";
		cout << "Account Number: " << newaccount[i].acnumber << "\n";
		cout << "Account Balance: " << newaccount[i].acbalance << "\n";
		cout << "*****************Details******************";
		cout<<"\n\n";
	}
	void WithdrawMoney(){
		int amount;
		int accountNumber;
		cout << "Enter Account Number: ";
		cin >> accountNumber;
		int i = SearchAccount(accountNumber);
		cout<<"Enter Withdraw Amount: ";
		cin>>amount;
		if(amount > newaccount[i].acbalance){
			cout<<"Not Enough Money in the Account\n";
		}
		else{
			newaccount[i].acbalance -= amount;
			cout<<"Success Withdraw\n";
			cout<<"Current Account Balance: "<<newaccount[i].acbalance<<"\n";	
		}
		cout<<"\n\n";
	}
	void DepositMoney(){
		int amount;
		int accountNumber;
		cout << "Enter Account Number: ";
		cin >> accountNumber;
		int i = SearchAccount(accountNumber);
		cout<<"Enter Deposit Amount: ";
		cin>>amount;
		newaccount[i].acbalance += amount;
		cout<<"Success Deposit\n";
		cout<<"Current Account Balance: "<<newaccount[i].acbalance<<"\n";
		cout<<"\n\n";
	}
 };
 
 void menu(bank b){
 	cout << "1. Open New Account\n";
 	cout << "2. Show Account Details\n";
 	cout << "3. Withdraw Money\n";
 	cout << "4. Deposit Amount\n";
 	cout << "5. Exit\n";
 	cout<<"Enter Option: ";
 	int option;
 	cin>>option;
 	cout<<"\n\n";
 	switch(option){
 		case 1:
 			b.OpenNewAccount();
 			break;
 		case 2:
 			b.ShowDetails();
 			break;
 		case 3:
 			b.WithdrawMoney();
 			break;
 		case 4:
 			b.DepositMoney();
 			break;
 		case 5:
 			exit(3);
 			break;
 		default:
 			break;
	 }
	 
	menu(b);
 }
 
 int main(){
 	bank sbi;
 	menu(sbi);
 	return 0;
 }
