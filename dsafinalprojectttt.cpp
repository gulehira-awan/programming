#include<iostream>
#include<stack>
#include<queue>
#include<cctype>
#include<string>
#include <stdlib.h>
using namespace std;
bool isValid(const string &name){
	for(int i=0;i<name.length();i++){
		if(isdigit(name[i])){
			return false;
		}
	}
	return true;
}
struct user{
    string name;
    string accountNumber;
    double balance;
    user* next;
    user(string n,string a,double b){
		name=n; 
		accountNumber=a;
		balance=b; 	
		next=NULL; 
	}
};
struct Transaction{
    string type;
    double amount;
    Transaction(string t,double a){
		type=t; 
		amount=a;
	}
};
class ReportRequest{
	public:
    	string type;
    	string accountNumber;
    	ReportRequest(string t,string acc){
			type=t; 
			accountNumber=acc; 
		}
};
class admin{
    user* head;
	public:
    	admin(){
			head=NULL;
		}
    bool login(){
        string adminName="admin";
        string password="password";
        string inputName;
        string inputPassword;
        cout<<"Enter name: ";
        cin>>inputName;
        cout<<"Enter password: ";
        cin>>inputPassword;
        if(adminName==inputName&&password==inputPassword){
            cout<<"You've successfully logged in!!"<<endl;
            return true;
        }
		else{
            cout<<"Oops! Incorrect username or password. Please try again!!"<<endl;
            return false;
        }
    }
    void createAccount(const string& n, const string& acno, double ba){
        user* newUser=new user(n, acno, ba);
        newUser->next=head;
        head=newUser;
        cout<<"Account created successfully for "<<n<<endl;
    }
    void deleteAccount(const string& acc){
        if(head==NULL){
            cout<<"No account is created!!"<<endl;
            return;
        }
        if(head->accountNumber==acc){
            user* del=head;
            cout<<head->accountNumber<<" account is deleted successfully!!"<<endl;
            head=head->next;
            delete del;
            return;
        }
        user* current=head;
        while(current->next!=NULL&&current->next->accountNumber!=acc){
            current=current->next;
        }
        if(current->next==NULL){
            cout<<"Account not found!!"<<endl;
        } 
		else{
            user* del=current->next;
            cout<<current->next->accountNumber<<" account is deleted successfully!!"<<endl;
            current->next=current->next->next;
            delete del;
        }
    }
    user* getUser(const string& accountNumber){
        user* current=head;
        while(current!=NULL){
            if(current->accountNumber==accountNumber){
                return current;
            }
            current=current->next;
        }
        return NULL;
    }
    void display()const{
        if(head==NULL){
            cout<<"No data!!"<<endl;
            return;
        }
        user* current = head;
        while(current!=NULL){
            cout<<"Name: "<<current->name<<"\tAccount no: "<<current->accountNumber<<"\tBalance: "<<current->balance<<endl;
            current=current->next;
        }
    }
};
class Transactions{
private:
    stack<Transaction> t;

public:
    void deposit(user& u, double amount) {
        u.balance += amount; 
        cout << amount << " deposited. \tNew Balance: " << u.balance << endl;
        t.push(Transaction("Deposit", amount)); 
    }
    void withdraw(user& u,double amount){
        if(amount>u.balance){
            cout<<"Insufficient balance. Current balance: "<<u.balance<<endl;
        } 
		else{
            u.balance -= amount; 
            cout<<amount<<" withdrawn. New Balance: "<<u.balance<<endl;
            t.push(Transaction("Withdraw", amount)); 
        }
    }
    void transfer(user& fromUser, user& toUser, double amount) {
        if(amount>fromUser.balance){
            cout<<"Insufficient balance. Current balance: "<<fromUser.balance<<endl;
        } 
		else{
            fromUser.balance -= amount; 
            toUser.balance += amount; 
            cout << amount << " transferred from " << fromUser.accountNumber << " to " << toUser.accountNumber << endl;
            t.push(Transaction("Transfer", amount)); 
        }
    }
    void printTransactions() {
        cout << "Transaction History:" << endl;
        stack<Transaction> s=t; // Creating a temporary stack
        while(!s.empty()){
            Transaction t1 = s.top();
            cout<<"Type: "<<t1.type<<", \tAmount: "<<t1.amount<<endl;
            s.pop();
        }
    }
};
class report{
	queue<ReportRequest> r;
	public:
    	void enqueue(const string& type, const string& accountNumber){
        	r.push(ReportRequest(type, accountNumber));
        	cout<<"Report requested: "<<type<<" for account "<<accountNumber<<"."<<endl;
   		}
    	ReportRequest dequeue(){
        	if(r.empty()){
            	cout<<"Queue is empty."<<endl;
            	return ReportRequest("", ""); 
        	}
        	ReportRequest request=r.front();
        	r.pop();
        	return request;
    	}
    	bool isEmpty()const{
        	return r.empty();
    	}
		void generateReports(){
        	if(r.empty()){
            	cout<<"No report requests found."<<endl;
            	return;
        	}
        	while(!r.empty()) {
            	ReportRequest request=dequeue();
            	cout<<"Generating report: "<<request.type<<" for account "<<request.accountNumber<<endl;
        	}
        	cout << "All report requests have been processed." << endl;
    	}
};
int main(){
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\t      Welcome"<<endl;
	cout<<"\t\t\t\t\tTo"<<endl;
	cout<<"\t\t\t\tGAFH TRANSACTION SYSYTEM"<<endl;
	cout<<"\t\t\t\t\t                                 "<<endl;
	cout<<"\t\t\t\t\t                                 "<<endl;
	cout<<"\t\t\t\t\t                                 "<<endl;
	system("color 08");
    char choice;
    cout<<"Enter a for Admin"<<endl;
    cout<<"Enter c for Customer"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;

    report rq; 

    switch(choice){
        case 'a':{
            admin a;
            int attempts=3;
            while(attempts>0){
                if(a.login()){
                    break;
                }
                attempts--;
                if(attempts==0) {
                    cout<<"Too many failed attempts. Program is exited."<<endl;
                    return 0;
                }
            }
            int choice1;
            do{
                cout<<"1. Create account"<<endl;
                cout<<"2. Delete account"<<endl;
                cout<<"3. Display details"<<endl;
                cout<<"4. Request report"<<endl; 
                cout<<"5. Exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>choice1;
                if(choice1==1){
                    string name;
                    string accountNumber;
                    cout<<"Enter name: ";
                    cin>>name;
                if(isValid(name)){
                    cout<<"Enter account number : ";
                    cin>>accountNumber;
                    double balance=5000.00;
                    a.createAccount(name, accountNumber, balance);
                }
                else{
                	cout<<"You have entered invalid name .You have to create account again. ";	
				}
                } 
				else if(choice1==2){
                    string accountNumber;
                    cout<<"Enter account number to delete: ";
                    cin>>accountNumber;
                    a.deleteAccount(accountNumber);
                } 
				else if(choice1==3){
                    a.display();
                } 
				else if(choice1==4){
                    string reportType, accountNumber;
                    cout<<"Enter report type: ";
                    cin>>reportType;
                    cout<<"Enter account number for report: ";
                    cin>>accountNumber;
                    rq.enqueue(reportType, accountNumber);
                } 
				else if(choice1==5){
                    cout<<"Exiting..."<<endl;
                } else {
                    cout<<"Invalid choice!"<<endl;
                }
            } while(choice1!=5);
            break;
        }
        case 'c': 
		{
            admin a1; 
            Transactions tt;
            int attempts=3;
            while(attempts>0){
                if(a1.login()){
                    break;
                }
                attempts--;
                if(attempts==0){
                    cout<<"Too many failed attempts. Program is exited."<<endl;
                    return 0;
                }
            }
            int choices;
            do{
                cout<<"1. Create account"<<endl;
                cout<<"2. Display details"<<endl;
                cout<<"3. Perform transactions"<<endl;
                cout<<"4. Print Transaction History"<<endl;
                cout<<"5. Generate report"<<endl; 
                cout<<"6. Exit"<<endl;
                cout<<"Enter your choice: ";
                cin>>choices;
                if(choices==1){
                    string name;
                    string accountNumber;
                    cout<<"Enter name: ";
                    cin>>name;
                if(isValid(name)){
                    cout<<"Enter account number : ";
                    cin>>accountNumber;
                    double balance=5000.00;
                    a1.createAccount(name, accountNumber, balance);
                }
                else{
                	cout<<"You have entered invalid name .You have to create account again. ";	
				}
                } 
				else if(choices==2){
                    a1.display();
                } 
				else if(choices==3){
                    string accountNumber;
                    cout<<"Enter your account number for transactions: ";
                    cin>>accountNumber;
                    user* users=a1.getUser(accountNumber);
                    if (!users){
                        cout<<"Account not found!"<<endl;
                        return 0;
                    }
                    int c;
                    do {
                        cout<<"1. Deposit"<<endl;
                        cout<<"2. Withdraw"<<endl;
                        cout<<"3. Transfer"<<endl;
                        cout<<"4. Exit"<<endl;
                        cout<<"Enter your choice: ";
                        cin>>c;
                        switch(c){
                            case 1: 
							{
                                double amount;
                                cout<<"Enter amount to deposit: ";
                                cin>>amount;
                                tt.deposit(*users, amount);
                                break;
                            }
                            case 2: 
							{
                                double amount;
                                cout<<"Enter amount to withdraw: ";
                                cin>>amount;
                                tt.withdraw(*users, amount);
                                break;
                            }
                            case 3: 
							{
                                string toAccountNumber;
                                double amount;
                                cout<<"Enter account number to transfer to: ";
                                cin>>toAccountNumber;
                                user* toUser=a1.getUser(toAccountNumber);
                                if (!toUser) {
                                    cout << "Recipient account not found!" << endl;
                                    break;
                                }
                                cout<<"Enter amount to transfer: ";
                                cin>>amount;
                                tt.transfer(*users, *toUser, amount);
                                break;
                            }
                            case 4:
                                cout<<"Exited transaction menu..."<<endl;
                                break;
                            default:
                                cout<<"Invalid choice. Please try again."<<endl;
                                break;
                        }
                    }while(c!=4);
                }
				else if(choices==4){
                    tt.printTransactions(); 
                } 
				else if(choices==5){
                    string reportType, accountNumber;
                    cout<<"Enter report type: ";
                    cin>>reportType;
                    cout<<"Enter account number for report: ";
                    cin>>accountNumber;
                    rq.enqueue(reportType, accountNumber); 
                    cout<<"Generating all requested reports sequentially:"<<endl;
                    rq.generateReports(); 
                } 
				else if(choices==6){
                    cout<<"Exiting..."<<endl;
                } 
				else{
                    cout<<"Invalid choice!"<<endl;
                }
            }while(choices!=6);
            break;
        }
        default:
            cout<<"Invalid choice!"<<endl;
            break;
    }
    

    return 0;
}
