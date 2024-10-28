/*
 * Banking App
 * Project2.cpp
 *
 *  Date: 10/11/24
 *  Author: Brianna Peoples
 */

#include <iostream>
#include <cstdio>
using namespace std;
void displayMenu() {
  cout << endl;
  cout << "******************************" << endl;
  cout << "********* Data Input *********" << endl;
  cout << endl;
}


void withoutMonthlyDeposits(int years, double initial_investment, int annual_interest) {
  double total_amount = initial_investment;
  cout << endl;
  cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
  cout << "========================================================" << endl;
  cout << "Year      End Balance      End Earned Interest" << endl;
  cout << "--------------------------------------------------------" << endl;
  for (int i = 1; i <= years; i++) {
    double investment_after_annual_interest = (annual_interest * 0.01) * total_amount; 
    double year_end_earned_interest = investment_after_annual_interest + total_amount;
    total_amount = year_end_earned_interest;
    printf("%-10d$%-10.2f      $%-10.2f\n", i, year_end_earned_interest, investment_after_annual_interest);

  }
  cout << "--------------------------------------------------------" << endl;
  cout << endl; 
}



void withMonthlyDeposits(int years, double initial_investment, int annual_interest, double monthly_deposit) {
  double total_amount = initial_investment;
  cout << endl;
  cout << "Balance and Interest With Additional Monthly Deposits" << endl;
  cout << "========================================================" << endl;
  cout << "Year      End Balance      End Earned Interest" << endl;
  cout << "--------------------------------------------------------" << endl;
  for (int i = 1; i <= years; i++) {
    double yearly_interest = 0;
        for (int month = 1; month <= 12; month++) {
            total_amount += monthly_deposit;
            double monthly_interest = total_amount * (annual_interest / 100.0 / 12.0);
            total_amount += monthly_interest;
            yearly_interest += monthly_interest;
        }
    printf("%-10d$%-10.2f      $%-10.2f\n", i, total_amount, yearly_interest);

  }
  cout << "--------------------------------------------------------" << endl;
  cout << endl; 
}


int main() {

  displayMenu();

    double initialInvestment;
    double monthlyDeposit;
    int annualInterest;
    int numberYears;

    cout << "Initial Investment Amount: "; 
    cin >> initialInvestment;
    cout << "Monthly Deposit: "; 
    cin >> monthlyDeposit;
    cout << "Annual Interest: ";
    cin >> annualInterest;
    cout << "Number of Years: ";
    cin >> numberYears;

    cout << "Press enter to continue…" << endl;
    
    cin.ignore();
    cin.get();

    
    withoutMonthlyDeposits(numberYears, initialInvestment, annualInterest);
    withMonthlyDeposits(numberYears, initialInvestment, annualInterest, monthlyDeposit);

    return 0;
}