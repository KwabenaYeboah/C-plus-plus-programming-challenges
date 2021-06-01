// QUESTION
/*
Payroll Report
Write a program that displays a weekly payroll report. A loop in the program
should ask the user for the employee number, gross pay, state tax, federal tax,
and FICA withholdings.The loop will terminate when 0 is entered for the
employee number. After the data is entered, the program should display totals
for gross pay, state tax, federal tax, FICA withholdings, and net pay.
Input Validation: Do not accept negative numbers for any of the items entered.

Do not accept values for state, federal, or FICA withholdings that are greater
than the gross pay. If the sum state tax + federal tax + FICA withholdings for
any employee is greater than gross pay, print an error message and ask the user
to reenter the data for that employee.
*/

// CODE
#include <iostream>
using namespace std;

int main()
{
  int employee_number;
  double gross_pay,
         state_tax,
         federal_tax,
         FICA_withholdings,
         net_pay, totals;

  // Asking user for details
 cout <<"Enter the following details and enter zero(0) for employee number"
       <<" when done.\n";
  cout <<"Enter employee's number: ";
  cin >> employee_number;

  while (employee_number != 0)
  {
    cout <<"Enter gross pay: ";
    cin >> gross_pay;

    while(gross_pay < 0)
      {
        cout <<"Error: you entered a negative number for gross_pay:\n"
             <<"please enter non-negative number: ";
        cin >> gross_pay;
      }

    cout <<"Enter state tax: ";
    cin >> state_tax;

    while (state_tax > 0 && state_tax > gross_pay)
    {
      cout <<"Error: state tax can't be greater than gross pay.\n"
           <<"Enter a value less than gross pay: ";
      cin >> state_tax;
    }

    while (state_tax < 0)
    {
      cout <<"Error: you entered a negative number for state tax:\n"
           <<"please enter non-negative number: ";
      cin >> state_tax;
    }

    cout <<"Enter federal tax: ";
    cin >> federal_tax;
    while (federal_tax > 0 && federal_tax > gross_pay)
    {
      cout <<"Error: federal tax can't be greater than gross pay.\n"
           <<"Enter a value less than gross pay: ";
      cin >> federal_tax;
    }

    while (federal_tax < 0)
    {
      cout <<"\nError: you entered a negative number for federal tax:\n"
           <<"please enter non-negative number: ";
      cin >> federal_tax;
    }
    cout <<"Enter FICA withholdings: ";
    cin >> FICA_withholdings;

    while (FICA_withholdings > 0 && FICA_withholdings > gross_pay)
    {
      cout <<"\nError: FICA Witholdings can't be greater than gross pay.\n"
           <<"Enter a FICA value less than gross pay: ";
      cin >> FICA_withholdings;
    }

    while (FICA_withholdings < 0)
    {
      cout <<"\nError: you entered a negative number for FICA Witholdings:\n"
           <<"please enter non-negative number: ";
      cin >> FICA_withholdings;
    }

    totals = state_tax + federal_tax + FICA_withholdings;
    if (totals > gross_pay)
    {
      cout <<"\nError: total gross pay can't be negative. Reenter the data this"
           <<" particular employee: ";
    }
    else
    {
      net_pay = gross_pay - totals;
      cout <<"\nGross pay $"<<gross_pay <<"\nState tax = $"
           <<state_tax <<"\nFederal tax = $"<<federal_tax
           <<"\nFICA Witholdings = $"<<FICA_withholdings <<"\nNet pay = $"
           <<net_pay <<endl;
    }
    cout <<"\n\nEnter employee number: ";
    cin >> employee_number;
	}
	return 0;
}
