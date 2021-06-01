//Box Office
/*
A movie theater only keeps a percentage of the revenue earned from ticket sales.
The remainder goes to the movie distributor. Write a program that calculates
a theater’s gross and net box office profit for a night. The program should
ask for the name of the movie, and how many adult and child tickets were sold.
(The price of an adult ticket is $10.00 and a child’s ticket is $6.00.)
It should display a report similar to

Movie Name:                     "Wheels of Fury"
Adult Tickets Sold:               382
Child Tickets Sold:               127
Gross Box Office Profit:       $ 4582.00
Net Box Office Profit:         $  916.40
Amount Paid to Distributor:    $ 3665.60

NOTE: Assume the theater keeps 20 percent of the gross box office profit.
*/

//Solution
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
  //Constants
  const float THEATER_PERCENTAGE = 0.20,
              ADULT_TICKET_PRICE = 10.00,
              CHILD_TICKET_PRICE =  6.00;

  //Variables
  string movie_name;
  int adult_tickets_sold,  //to hold the number of adult tickets sold
      child_tickets_sold;  //to hold the number of child tickets sold

  float adult_tickets_amount, //for money amount of the adult tickets sold
        child_tickets_amount; //for money amount of the adult tickts sold

  float gross_box_office_profit,
        net_box_office_profit,
        distributor_amount;

  //Asking user for the name of the movie, and many
  //adult and child tickets were sold.
  cout <<"\nWhat is the name of the movie: ";
  getline(cin, movie_name);
  cout <<"How many adult tickets were sold: ";
  cin >> adult_tickets_sold;
  cout <<"How many child tickets were sold: ";
  cin >> child_tickets_sold;

  //Calculating money amount for adult and child tickets sold
  adult_tickets_amount = adult_tickets_sold + ADULT_TICKET_PRICE;
  child_tickets_amount = child_tickets_sold * CHILD_TICKET_PRICE;

  //Calculating gross box office profit, net box office profit
  //and amout paid to movie distributor
  gross_box_office_profit = adult_tickets_amount + child_tickets_amount;
  net_box_office_profit = gross_box_office_profit * THEATER_PERCENTAGE;
  distributor_amount = gross_box_office_profit - net_box_office_profit;

  //Displaying results
  cout <<"\nMovie Name: " <<setw(33) <<movie_name <<endl;
  cout <<"Adult Tickets Sold: " <<setw(17) <<adult_tickets_sold <<endl;
  cout <<"Child Tickets Sold: " <<setw(17) <<child_tickets_sold <<endl;

  cout <<setprecision(2) <<fixed << showpoint;
  cout <<"Gross Box Office Profit:" <<setw(9) <<"$ "
       <<gross_box_office_profit <<endl;
  cout <<"Net Box Office Profit:" <<setw(12) <<"$  "
       <<net_box_office_profit <<endl;
  cout <<"Amount paid to Distributor:" <<setw(6) <<"$ "
       <<distributor_amount <<endl;
  return 0;
}
