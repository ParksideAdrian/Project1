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

int main(){
    tripLength();
    departureTime();
    airFair();
    double carCost;
    carRental(carCost);
    conferenceFees();
    
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

/*
Amount of days on trip: 3

What time was Departure (Military Time): 1300
What time was the arrival (Military Time): 1600
Enter cost of round trip: 3000
Flight cost: 3000 Flight cost reimbursed: 3000

Did you rent a car? (y/n): n
Was a private vehicle used? (y/n): y
How many miles were driven? 600
Car cost is: 348 Car cost reimbursed: 348

Enter cost of conference registration fees: 60
Conference fees: 60 Conference fees reimbursed: 60

Program ended with exit code: 0
*/










