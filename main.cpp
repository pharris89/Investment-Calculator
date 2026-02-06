#include <iostream>
#include <limits>
#include <iomanip>
#include "InvestmentCalculator.h"

using namespace std;

static double ReadPositiveDouble(const string& prompt, bool allowZero) {
    double value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail()) {
            if ((allowZero && value >= 0.0) || (!allowZero && value > 0.0)) {
                return value;
            }
        }

        cout << "Invalid input. Please enter a " << (allowZero ? "non-negative" : "positive")
            << " number.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

static int ReadPositiveInt(const string& prompt) {
    int value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (!cin.fail() && value > 0) {
            return value;
        }

        cout << "Invalid input. Please enter a positive whole number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

static void WaitForKey() {
    cout << "\nPress Enter to continue . . .";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

static void PrintInputScreen(double initial, double monthly, double rate, int years) {
    cout << "**********************************\n";
    cout << "************* Data Input *********\n";
    cout << fixed << setprecision(2);
    cout << "Initial Investment Amount: $" << initial << "\n";
    cout << "Monthly Deposit:           $" << monthly << "\n";
    cout << fixed << setprecision(2);
    cout << "Annual Interest:           " << rate << "%\n";
    cout << "Number of years:           " << years << "\n";
    cout << "Press any key to continue . . .\n";
    cout << "**********************************\n";
}

int main() {
    char runAgain = 'Y';

    while (runAgain == 'Y' || runAgain == 'y') {
        cout << "**********************************\n";
        cout << "************* Data Input *********\n";
        cout << "**********************************\n";

        double initial = ReadPositiveDouble("Initial Investment Amount: ", false);
        double monthly = ReadPositiveDouble("Monthly Deposit: ", true);
        double rate = ReadPositiveDouble("Annual Interest (percent): ", true);
        int years = ReadPositiveInt("Number of years: ");

        // Show summary 
        PrintInputScreen(initial, monthly, rate, years);

        // Pause before showing reports
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        InvestmentCalculator calc;
        calc.SetInitialInvestment(initial);
        calc.SetMonthlyDeposit(monthly);
        calc.SetAnnualInterestRate(rate);
        calc.SetYears(years);

        calc.PrintReportWithoutMonthlyDeposits();
        calc.PrintReportWithMonthlyDeposits();

        cout << "\nRun again with different values? (Y/N): ";
        cin >> runAgain;

        // Clean leftover newline
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n";
    }

    return 0;
}
