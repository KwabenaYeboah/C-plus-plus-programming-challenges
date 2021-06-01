//QUETION
/*
Mobile Service Provider
A mobile phone service provider has three different subscription packages for
its customers:
Package A: For $39.99 per month 450 minutes are provided. Additional
minutes are $0.45 per minute.
Package B: For $59.99 per month 900 minutes are provided. Additional
minutes are $0.40 per minute.
Package C: For $69.99 per month unlimited minutes provided.
Write a program that calculates a customer’s monthly bill. It should ask
which package the customer has purchased and how many minutes were used.
It should then display the total amount due.
Input Validation: Be sure the user only selects package A, B, or C.

Mobile Service Provider, Part 2
Modify the Program in Programming Challenge 25 so that it also displays how much
money Package A customers would save if they purchased packages B or C, and how
much money Package B customers would save if they purchased Package C. If there
would be no savings, no message should be printed.
*/

//CODE

#include <iostream>
using namespace std;

int main()
{
  //Defining some Variables and constants
  char user_choice;
  float user_minutes;
  double monthly_bill,
         money_saved;

  const double PACKAGE_A_FIXED_PRICE = 39.99,
               PACKAGE_B_FIXED_PRICE = 59.99,
               PACKAGE_C_FIXED_PRICE = 69.99,
               PACKAGE_A_ADDITONAL_CHARGE_PER_MINUTE = 0.45,
               PACKAGE_B_ADDITONAL_CHARGE_PER_MINUTE = 0.40;
        int    PACKAGE_A_MINUTES = 450,
               PACKAGE_B_MINUTES = 900;

  //Asking user for to choose a package
  cout <<"Package A: For $39.99 per month 450 minutes are provided.\n"
         "Additional minutes are $0.45 per minute.\n";
  cout <<"Package B: For $59.99 per month 900 minutes are provided.\n"
         "Additional minutes are $0.40 per minute.\n";
  cout <<"Package C: For $69.99 per month unlimited minutes provided.\n";
  cout <<"\nChoose a package by selecting A,B or C: ";
  cin >> user_choice;

  //Determining user choice and applying the monthly bill accordingly
  if (user_choice == 'A')
  {
    cout <<"How many minutes would be used: ";
    cin >> user_minutes;
    if (user_minutes <= PACKAGE_A_MINUTES)
    {
      monthly_bill = PACKAGE_A_FIXED_PRICE;
      cout <<"\nYour monthly bill = $"<<monthly_bill <<endl;
    }
    else
    //calculating monthly bill if user minutes excceeds Package A fixed minutes
    {
      monthly_bill = PACKAGE_A_FIXED_PRICE +  (user_minutes - \
                PACKAGE_A_MINUTES) * PACKAGE_A_ADDITONAL_CHARGE_PER_MINUTE;
      cout <<"\nYour monthly bill = $"<<monthly_bill<<endl;

      //calculating how much money Pakcage A customers would save if they
     //purchased Packages B or C
      if (monthly_bill > PACKAGE_B_FIXED_PRICE)
      {
        money_saved = monthly_bill - PACKAGE_B_FIXED_PRICE;
        cout <<"You will save $"<<money_saved <<" if you purchase Package B\n";

        //when monthly bill of Package A exceeds PACKAGE_C_FIXED_PRICE
        if (monthly_bill > PACKAGE_C_FIXED_PRICE)
        {
          money_saved = monthly_bill - PACKAGE_C_FIXED_PRICE;
          cout<<"You will save $"<<money_saved <<" if you purchase Package C\n";
        }
      }
    }
  }
  else if (user_choice == 'B')
  {
    cout <<"How many minutes would be used: ";
    cin >> user_minutes;
    if (user_minutes <= PACKAGE_B_MINUTES)
    {
      monthly_bill = PACKAGE_B_FIXED_PRICE;
      cout <<"\nYour monthly bill = $ "<<monthly_bill <<endl;
    }
    else
    {
      monthly_bill = PACKAGE_B_FIXED_PRICE +  (user_minutes - \
                PACKAGE_B_MINUTES) * PACKAGE_B_ADDITONAL_CHARGE_PER_MINUTE;
      cout <<"\nYour monthly bill = $ "<<monthly_bill <<endl;

      //when monthly bill of Package B exceeds PACKAGE_C_FIXED_PRICE
      if (monthly_bill > PACKAGE_C_FIXED_PRICE)
      {
        money_saved = monthly_bill - PACKAGE_C_FIXED_PRICE;
        cout<<"\nYou will save $"<<money_saved <<" if you purchase Package C\n";
      }
    }
  }
  else if (user_choice == 'C')
  {
    monthly_bill = PACKAGE_C_FIXED_PRICE;
    cout <<"\nYour monthly bill = $"<<monthly_bill <<endl;
  }
  else
    cout <<"\nYou didn't enter any of A, B or C. Run the program again.\n";
}
