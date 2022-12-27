#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
class Bank{
	private :
		int acno;
		char name[30], fname[30], add[50];
		long balance;
		public :
			void openAccount(){
				cout<<".......FILL THE DETAILS CAREFULLY......."<<endl<<endl;
				cout<<"Enter customer name:"<<endl;
				cin>>name;
				cout<<"Enter Account Number:"<<endl;
				cin>>acno;
				cout<<"Enter coustomer Father's name:"<<endl;
				cin>>fname;
				cout<<"Enter Coustomer Address: "<<endl;
				cin>>add;
				cout<<"Enter the Amount which coustomer Deposting WHILE ACCOUNT is Opening:"<<endl;
				cin>>balance;
			}
			void showAccount(){
				cout<<endl<<"This is the information about  "<<name<<" s/o "<<fname<<endl<<endl;
				cout<<"Coustomer Account Number: "<<acno<<endl;
				cout<<"Customer Name is: "<<name<<endl;
				cout<<"Customer Father's Name: "<<fname<<endl;
				cout<<"Coustomer Address: "<<add<<endl;
				cout<<"Total Balance Amount is: "<<balance<<endl;
			}
			void Deposit(){
				cout<<"Deposit Balance in the Account Number: "<<acno<<endl<<endl;
				long amt;
				cout<<"Enter the Balance which you want to Deposit: "<<endl;
				cin>>amt;
				cout<<"your Entered Balance is: "<<amt<<endl;
				balance=balance+amt;
				cout<<"The total Balance in Your Account is :"<<balance<<" Rupees Only"<<endl;
			}
			void Withdraw(){
				long wamt;
				cout<<"Withdraw The Amount Account Number: "<<acno<<endl;
				cout<<"Enter The Amount which you want to withdraw: "<<endl;
				cin>>wamt;
				if(balance>=wamt){
					balance=balance-wamt;
					cout<<"Your Reamaing Ammount in your Account is: "<<balance<<endl;
				}
				else{
					cout<<"Your Account is insufficent funds"<<endl<<"or"<<endl<<"Please Check the Amount which you Entered"<<endl<<"Less Balance"<<endl<<".........Thank you"<<endl;
				}
			}
			int search(int);
			int sn();
};
int Bank::search(int a){
	if(acno==a){
		showAccount();
		return(1);
	}
	return(0);
}
int Bank::sn(){
	char n[30];
	gets(n);
	int e;
	e=strcmp(name,n);
	if(e==0){
		showAccount();
		return(1);
	}
	return(0);
}
int main(){
	Bank c[3];
	char n[30];
	int found=0,a,ch,i;
	for(i=0;i<=2;i++){
		c[i].openAccount();
	}
	do{
		back:
		cout<<"........WELCOME......."<<endl<<endl;
		cout<<"1.Show All Account"<<endl<<"2.Display by Account Number:"<<endl<<"3.Display By name"<<endl<<"4.Deposit The Ammount:"<<endl<<"5.Withdraw Ammount:"<<endl<<"6.EXIT........"<<endl;
		cout<<"Chose a Option to Do Certain Action: ";
		cin>>ch;
		switch(ch){
			case 1: 
			for(i=0;i<=2;i++){
				c[i].showAccount();
			}
			goto back;
			case 2:
				cout<<"Account Number...?...:";
				cin>>a;
				for(i=0;i<=2;i++){
					found=c[i].search(a);
					if(found)
						break;
				}
				goto back;
				if(!found){
					cout<<"Record Not Found"<<endl;
					break;
				}
				case 3:
					cout<<"coustomer name...?..."<<endl;
					for(i=0;i<=2;i++){
						found=c[i].sn();
						if(found)
						break;
						}
						goto back;
					if(!found){
						cout<<"Record not Found"<<endl;
						break;
					}
				case 4:
					cout<<endl<<"Deposit The Amount"<<endl<<endl;
					cout<<"Account Number...?...:"<<endl;
					cin>>a;
					for(i=0;i<=2;i++){
						found=c[i].search(a);
						if(found){
							c[i].Deposit();
							break;
						}
					}
					goto back;
					if(!found){
						cout<<"Record not found"<<endl;
					}
				case 5:
				cout<<endl<<"WITHDRAW AMOUNT"<<endl<<endl;
				cout<<"Account Number...?...:"<<endl;
				cin>>a;
				for(i=0;i<=2;i++){
					found=c[i].search(a);
					if(found){
					c[i].Withdraw();
					break;
					}
				}
				goto back;
				if(!found){
					cout<<"record not found"<<endl;
				}	
				case 6:
					cout<<"HAVE A NICE DAY "<<endl<<"    THANK YOU    "<<endl;
					break;
				default :
					cout<<"Wrong option "<<endl<<"   ERROR   "<<endl;
		}	
	}while(ch==6);
	return 0;
}
