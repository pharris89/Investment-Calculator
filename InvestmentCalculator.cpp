#include "InvestmentCalculator.h"
#include <iomanip>
#include <string>

InvestmentCalculator::InvestmentCalculator()
    : initialInvestment(0.0), monthlyDeposit(0.0), annualInterestRate(0.0), years(0) {
}

void InvestmentCalculator::SetInitialInvestment(double value) { initialInvestment = value; }
void InvestmentCalculator::SetMonthlyDeposit(double value) { monthlyDeposit = value; }
void InvestmentCalculator::SetAnnualInterestRate(double value) { annualInterestRate = value; }
void InvestmentCalculator::SetYears(int value) { years = value; }

double InvestmentCalculator::GetInitialInvestment() const { return initialInvestment; }
double InvestmentCalculator::GetMonthlyDeposit() const { return monthlyDeposit; }
double InvestmentCalculator::GetAnnualInterestRate() const { return annualInterestRate; }
int InvestmentCalculator::GetYears() const { return years; }

double InvestmentCalculator::CalculateMonthlyInterest(double balance) const {
    // Monthly compounded interest: balance * (rate/100)/12
    return balance * (annualInterestRate / 100.0) / 12.0;
}

void InvestmentCalculator::PrintReportHeader(const std::string& title) const {
    std::cout << "\n";
    std::cout << "============================================\n";
    std::cout << title << "\n";
    std::cout << "============================================\n";
    std::cout << std::left
        << std::setw(6) << "Year"
        << std::setw(20) << "Year End Balance"
        << "Year End Earned Interest\n";
    std::cout << "--------------------------------------------\n";
}

void InvestmentCalculator::PrintReportWithoutMonthlyDeposits() const {
    PrintReportHeader("Balance and Interest Without Additional Monthly Deposits");

    double balance = initialInvestment;

    for (int year = 1; year <= years; ++year) {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            double interest = CalculateMonthlyInterest(balance);
            balance += interest;
            yearlyInterest += interest;
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::left
            << std::setw(6) << year
            << "$" << std::setw(19) << balance
            << "$" << yearlyInterest << "\n";
    }
}

void InvestmentCalculator::PrintReportWithMonthlyDeposits() const {
    PrintReportHeader("Balance and Interest With Additional Monthly Deposits");

    double balance = initialInvestment;

    for (int year = 1; year <= years; ++year) {
        double yearlyInterest = 0.0;

        for (int month = 1; month <= 12; ++month) {
            // Deposit first, then calculate interest on new balance 
            balance += monthlyDeposit;

            double interest = CalculateMonthlyInterest(balance);
            balance += interest;
            yearlyInterest += interest;
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << std::left
            << std::setw(6) << year
            << "$" << std::setw(19) << balance
            << "$" << yearlyInterest << "\n";
    }
}
