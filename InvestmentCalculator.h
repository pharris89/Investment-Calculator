#ifndef INVESTMENTCALCULATOR_H
#define INVESTMENTCALCULATOR_H

#include <iostream>

class InvestmentCalculator {
public:
    InvestmentCalculator();

    void SetInitialInvestment(double value);
    void SetMonthlyDeposit(double value);
    void SetAnnualInterestRate(double value);
    void SetYears(int value);

    double GetInitialInvestment() const;
    double GetMonthlyDeposit() const;
    double GetAnnualInterestRate() const;
    int GetYears() const;

    void PrintReportWithoutMonthlyDeposits() const;
    void PrintReportWithMonthlyDeposits() const;

private:
    double initialInvestment;
    double monthlyDeposit;
    double annualInterestRate;
    int years;

    double CalculateMonthlyInterest(double balance) const;
    void PrintReportHeader(const std::string& title) const;
};

#endif
