#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Expense{
    public:    
        string Category;
        double amount;
        string date;

        //constructor(which initializess the object)
        Expense(const string& cat,double amt,const string& dt):Category(cat),amount(amt),date(dt){};

        void print() const{
            cout<<date<<":"<<Category<<"- rs."<<amount<<endl;
        }
};

class ExpenseTrack{
    private:
        vector<Expense> Expenses;
    public:
        // function to add new expense to our collection 
        void addexpenses(const string& Category,double amount,const string& date){
            Expense expense(Category,amount,date);
            Expenses.push_back(expense);
        }

        // function to view all the expenses;
        void viewexpense() const{
            for(const auto& expense:Expenses){
                expense.print();
            }
        }

        //Method to filter the expense;
        vector<Expense> filteringexpense(const string& Category="",const string& Startdate="",const string& Enddate="") const{
            vector<Expense> filter;
            for(const auto& expense:Expenses){
                if((Category.empty() || expense.Category==Category) && (Startdate.empty() || expense.date>=Startdate) && (Enddate.empty()||expense.date<=Enddate)){
                    filter.push_back(expense);
                }
            }
            return filter;
        }
        // delete an expense;
        void deletefn(int i){
            if(i>=0 && i<Expenses.size()){
                Expenses.erase(Expenses.begin()+i);
            }
        }
        //total calculation;
        double total() const{
            double tot=0;
            for(const auto& expense:Expenses){
                tot+=expense.amount;
            }
            return tot;
        }
};

int main(){
    ExpenseTrack tracker;
    tracker.addexpenses("Food", 50.5, "2024-07-01");
    tracker.addexpenses("Ac",1000,"2024-07-02");
    tracker.addexpenses("Transport",500,"2024-07-10");

    cout<<"view expenses"<<endl;
    tracker.viewexpense();

    cout<<"Expense b/f 10 july"<<endl;
    vector<Expense> filter=tracker.filteringexpense("","","2024-07-09");
    
    for(const auto& expense:filter){
        expense.print();
    }

    cout << "\nTotal Expenses:" <<endl;
    double total = tracker.total();
    cout<<total<<endl;
    
    cout << "\nDeleting first expense..." <<endl;
    tracker.deletefn(0);
    tracker.viewexpense();

    cout << "\nAll Expenses after deletion:" <<endl;
    tracker.viewexpense();
    return 0;
}


