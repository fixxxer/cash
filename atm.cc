#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


//functions and its conditions


void printBalance(double savings);
/* Pre conditions:take in two double value (account balance) as parameter
Postcondition: print the value of the parameter.
*/

string readInput();
/*Precondition: prints menu choices and prompts the user to enter number of menu choice
Postcondition: returns valid menu choice
*/

double withdraw(double& balance);
/*Precondition: take in a double (account balance) as a parameter and Prompt the user to enter a withdrawal amount
Postcondition: update the account balance so that the change is reflected outside of the function
*/

double deposit(double balance, double& amount);
/*Precondition: take in two double values (account balance and deposit amount) as parameters. Update account balance.
Postcondition: return updated account balance
*/

int main()
{
    double savings = 0, amount;
    string choice;
    string key;
    do
    {

        key = "x";
        system("clear");
        choice = readInput();

        if ( choice ==  "1" ) {
        	cout <<"How much would you like to deposit? $";
                cin>> amount;
                if ( amount < 10000){
                    savings = deposit(savings, amount);
                }else{
                    cout <<"The MAX amount to deposit is $10,000\n";
                    cout <<"Press [c] to continue\n";
                    while (key != "c")
                    cin>>key;
                }
	}
        else if ( choice == "2" ) {
                printBalance(savings);
                cout <<"Press [c] to continue\n";
                while (key != "c")
                    cin>>key;
	}         
        else if ( choice ==  "3" ) {
                withdraw(savings);
	}
        else if ( choice == "4" ) {
                key="e";
	}
    }while(key != "e"); 
    return 0;
}

void printBalance(double savings)//function to print balance
{
//used to format output values and print savings balance
    cout.setf(ios::fixed);
    cout.setf(ios::left);
    cout.precision(2);
    cout<<"Your savings balance is: $" << savings <<"\n\n";
}

string readInput()
{

    string choice;
    cout<<" What would you like to do?\n\n";
    cout<<"(0) Home\n";
    cout<<"(1) Deposit\n";
    cout<<"(2) Balance\n" ;
    cout<<"(3) Withdraw\n";
    cout<<"(4) Exit \n\n";
    cout<<"Enter the number associated with the choice you would like: ";
    cin >> choice;
    return choice;
}


double withdraw(double& balance)//function for withdrawing
{
    double withdraw = 0;
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;
    int coins = 0;
    string key = "x";
    do
    {
        cout<<"Enter the amount you would like to withdraw: ";//ask for amount to withdraw
        cin >> withdraw;//stores input
    }while(withdraw < 0);
    //do while loop ensures not negatives are being inputted
    
    if (withdraw <= balance)
    {
        coins = (int)withdraw;
        cout<<"Total amount of withdraw: "<<coins<<endl;
        cout<<"Bills of 500 pesos: "<<coins / 500<<endl;
        coins = coins % 500;
        cout<<"Bills of 200 pesos: "<<coins / 200<<endl;
        coins = coins % 200;
        cout<<"Bills of 100 pesos: "<<coins / 100<<endl;
        coins = coins % 100;
        cout<<"Bills of  50 pesos: "<<coins / 50<<endl;
        coins = coins % 50;
        cout<<"Coins of  20 pesos: "<<coins / 20<<endl;
        coins = coins % 20;
        cout<<"Coins of  10 pesos: "<<coins / 10<<endl;
        coins = coins % 10;
        cout<<"Coins of   5 pesos: "<<coins / 5<<endl;
        coins = coins % 5;
        cout<<"Coins of   1 pesos: "<<coins<<endl;
    
        cout <<"'\nPress [c] to continue\n";
        while (key != "c")
            cin>>key;
        
        balance = balance - withdraw; //updates balance by subtracted balance from amount wished to withdraw
        return balance;
    } 
    else
    {
        cout<<"You do not have enough money in your account for this transaction\n";
        cout <<"'\nPress [c] to continue\n";
        while (key != "c")
            cin>>key;
    

    }//if loop to prevent overdrafts
}

double deposit(double balance, double& amount)//function for deposits
{
    do{
        balance = balance + amount;//updates balance by adding the amount deposited to the remaining balance

    } while (deposit < 0);// do while loop to ensure no negatives are being inputted
    return balance;
}

