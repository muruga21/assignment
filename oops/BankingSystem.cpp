#include<bits/stdc++.h>
using namespace std;

class Account{
    private:
    string AccountNumber;
    string AccountType;
    long long Bill = 0;
    long long CreditLimit = 0;
    long long Balance = 0;

    public:
    Account(string account_number) : AccountNumber(account_number){
        cout << " > Account type (S)avings/ (C)redit: "<<endl;
        string acc_type;
        cin >> acc_type;
        AccountType = acc_type;
        CreditLimit = 10000;
        Balance = 0;
    }
    string getAccountNumber(){
        return AccountNumber;
    }
    string getAccountType(){
        return AccountType;
    }

    void getBill(){
        cout << "\n > Your bill is " << Bill <<" your credit limit is " << CreditLimit <<"\n"<<endl;
        return ;
    }

    void getBalance(){
        cout << " > Your balance is " << Balance <<endl;
        return ;
    }

    void deposit_SavingAcc(int amount){
        Balance += amount;
        cout<<"ammount deposited successfully..!"<<endl;
    }

    void deposit_CreditAccount(int amount){
        if(Bill <= amount){
            cout<<"Invalid amound"<<endl;
            return;
        }
        Bill -= amount;
        cout<<"ammount deposited successfully..!"<<endl;
    }

};

class Bank {
    private:
    string BankName;
    vector<Account*> account;

    public:

    bool isValidAccount(string AccountNumber){
        for(auto x : account){
            if(x->getAccountNumber() == AccountNumber){
                return true;
            }
        }
        return false;
    }

    void addToBank(Account* accObj){
        account.push_back(accObj);
    }   

    Account* getAccountObj(string AccountNumber){
        for(auto x : account){
            if(x->getAccountNumber() == AccountNumber){
                return x;
            }
        }
        return nullptr;
    }

};

class Application : public Bank{
    public:

    Application(){
        cout<<" > Welcome to XYZ Bank..."<<endl;
    }

    void getOptions( Account* acc ){
        int selected_option;
        string acc_type = acc->getAccountType();
        while(true){
            cout << "1. View Balance. \n2. Deposit \n3. Withdraw \n0. Main Menu " <<endl;
            cin >> selected_option;
            if(selected_option == 0) break;
            else if(selected_option == 1) (acc_type == "credit") ? acc->getBill() : acc->getBalance();
            else if(selected_option == 2){
                int amount;
                cout <<" > Enter the amount need to deposited.."<<endl;
                cin>>amount;
                (acc_type == "credit") ? acc->deposit_CreditAccount(amount) : acc->deposit_SavingAcc(amount);
            }
            else if(selected_option == 3) ;
            else cout << " > Invalid Option.. !" << endl ;
        }
    }

    void startApplication(){
        string account_number;
        while(true){
            cout << " > Enter account num: "<<endl;
            cin >> account_number;
            Account* acc = nullptr;


            if(!isValidAccount(account_number)){
                cout<<" > New account creation: "<<endl;
                acc = new Account(account_number);
                addToBank(acc);
                cout<<"\n > Account created successfully ! \n"<< endl;
            }
            else{
                acc = getAccountObj(account_number);
                cout << acc->getAccountType() <<  " card account is selected " << endl; 
                cout << "\n > Select the options : "<<endl;
                getOptions(acc);
            }

        }
    }

};

int main(){
    Application app;
    app.startApplication();
    return 0;
}