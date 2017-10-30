//
//  main.cpp
//  Project
//
//  Created by Adrian Salazar on 10/26/17.
//  Copyright © 2017 Adrian Salazar. All rights reserved.
//

#include <iostream>
using namespace std;
const double PER_MILE = 0.58;
double carCost;

void carRental(double &refVar1);
void costPerMile(double &refVar);
void airFair();
void tripLength();
void conferenceFees();
void carRental();
void costPerMile();
void departureTime();
void checkTime();
int departureTime(int &);
void checkint(int &);
int getTotalDays();
double taxiFee(int);


int main(){
    tripLength();
    departureTime();
    airFair();
    double carCost;
    carRental(carCost);
    conferenceFees();
    int departure,
    arrival;
    departure = departureTime(arrival);
    int days;
    double taxiSpent;
    days = getTotalDays();
    taxiSpent = taxiFee(days);
    cout << taxiSpent;
    
    
    cout << departure << " " << arrival << endl;
    
    return 0;
}
/***********************************************
 
 void carRental() function determines the amount
 of cars rented, if a car was rented at all
 
 **********************************************/

void carRental(double &refVar1){
    char ch;
    char privateCar;

    
    cout << "Did you rent a car? (y/n): ";
    cin >> ch;
        if (ch == 'y' || ch == 'Y'){
            cout << "Enter cost of the rental car: ";
            cin >> refVar1;
            }
        else if(ch == 'n' || ch =='N'){
            cout << "Was a private vehicle used? (y/n): ";
            cin >> privateCar;
            
            if( privateCar == 'y' ||  privateCar == 'Y' ){
            costPerMile(refVar1);
            }
            else if(privateCar == 'n' || privateCar == 'N'){
                refVar1 = 0;
            }
        else if (ch != 'Y' || ch!= 'y' || ch != 'N' || ch != 'n'){
            cout << "Error. Invalid input, please try again";
            cin >> ch;
            }
        }
    cout << "Car cost is: " << refVar1 << " Car cost reimbursed: " << refVar1 << endl;
    cout << endl;
    }
    
    

/************************************
 
 Miles Driven
 Vehicle allowance is $0.58 per mile.
 
 ************************************/

void costPerMile(double &refVar){
    int milesDriven;
    
    cout << "How many miles were driven? ";
    cin >> milesDriven;
    
    refVar = milesDriven * PER_MILE;
    
}

void tripLength()
{
    int days;
    cout << "Amount of days on trip: ";
    cin >> days;
    cout << endl;
}

void airFair()
{
    double cost, reimbursement;
    cout << "Enter cost of round trip: ";
    cin >> cost;
    reimbursement = cost;
    cout << "Flight cost: " << cost << " " << "Flight cost reimbursed: " << reimbursement << endl;
    cout << endl;
}

void conferenceFees()
{
    double conferenceFee, reimbursement;
    cout << "Enter cost of conference registration fees: ";
    cin >> conferenceFee;
    reimbursement = conferenceFee;
    cout << "Conference fees: "<< conferenceFee << " Conference fees reimbursed: " << reimbursement << endl;
    cout << endl;
}

/*****************************************************************
 *              Departure Time and Return Time                    *
 *                                                                *
 *    This Function receives information on the departure time    *
 *         and the return time for the business person            *
 *****************************************************************/
void departureTime()
{
    double timeDepart,
    timeReturn;
    
    cout << "What time was Departure (Military Time): ";
    cin  >> timeDepart;
    while(timeDepart < 0 || timeDepart > 2459){
        cout << "ERROR! Invalid Time! Re-Enter Time: ";
        cin  >> timeDepart;
    }
    
    cout << "What time was the arrival (Military Time): ";
    cin  >> timeReturn;
    while(timeReturn < 0 || timeReturn > 2459){
        cout << "ERROR! Invalid Time! Re-Enter Time: ";
        cin  >> timeReturn;
        cout << endl;
    }
}



///**************************************************************************************************
///**************************************************************************************************
///**************************************************************************************************
///**************************************************************************************************
///**************************************************************************************************
///**************************************************************************************************
///**************************************************************************************************
///**************************************************************************************************
///**************************************************************************************************
///**************************************************************************************************
///**************************************************************************************************
///**************************************************************************************************


/*****************************************************************
 *              Departure Time and Return Time                    *
 *                                                                *
 *    This Function receives information on the departure time    *
 *         and the return time for the business person            *
 *****************************************************************/
int departureTime(int & timeReturn)
{
    int    timeDepart;
    
    cout << "Enter the time of Departure (Military Time, excluding colon): ";
    cin  >> timeDepart;
    checkint(timeDepart);
    
    cout << "Enter the time of Return (Military Time, excluding colon): ";
    cin  >> timeReturn;
    checkint(timeReturn);
    
    return timeDepart;
}
/*****************************************************************
 *                        Time Validation                         *
 *                                                                *
 *    This Function reads for invalid time inputs such as 12:88   *
 *****************************************************************/
void checkint(int & time)
{
    int hundreds = time / 100,
    tens     = time - (hundreds * 100);
    
    while(hundreds > 23 || tens > 59){
        cout << "ERROR! That is an invalid time input. Please Re-Enter: ";
        cin  >> time;
        
        hundreds = time / 100;
        tens     = time - (hundreds * 100);
    }
}

//BULLETS 1 AND 7
/**********************************************************
 *                        Taxi Fee                         *
 *                                                         *
 *   This function asks the user to input a fee for Taxi   *
 *   and if it goes over the allowance, the buisnessperson *
 *   must pay the remainder out of pocket                  *
 *                                                         *
 **********************************************************/

double taxiFee(int days)
{
    int     timeFrame = 1;
    double  taxiSpent = 0.0,
    value     = 0.0;
    
    for(int i = 1; i <= days; i++){
        cout << " Total: " << taxiSpent << " Value: " << value << endl;
        cout << "How much was spent on day " << timeFrame << ": ";
        cin  >> value;
        taxiSpent = taxiSpent + value;
        timeFrame++;
        cout << " Total: " << taxiSpent << " Value: " << value << endl;
    }
    return taxiSpent;
}
/***************************************************************************
 *                            getTotalDays                                 *
 * This function asks for and returns total number of days spent on trip.  *
 **************************************************************************/
int getTotalDays(){
    int numDays;
    cout << "Enter total number of days spent on trip: ";
    cin >> numDays;
    while(numDays < 0){
        cout << "Error: Negative number of days invalid, re-enter: ";
        cin >> numDays;
    }
    return numDays;
}



