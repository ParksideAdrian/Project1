#include <iostream>
#include <iomanip>
#include <fstream>
#include <regex>
#include <string>

using namespace std;


const double PER_MILE = 0.58,
PARK_PER_DAY = 12.00,
TAXI_PER_DAY = 40.00,
HOTEL_PER_NIGHT = 90.00,
BREAKFAST = 18.00,
LUNCH = 12.00,
DINNER = 20.00;


//Bullet 1
int getTotalDays();

//Bullet 2
int departureTime(int &);
void checkint(int &);

//Bullet 3
double airFare();

//Bullet 4
double carRental();

//Bullet 5
double costPerMile();

//Bullet 6
double parkingFees(int, double&);

//Bullet 7
double taxiFee(int, double&);

//Bullet 8
double conferenceFees();

//Bullet 9
double hotelExpenses(int days, double &spentHotel);

//Bullet 10
void mealCost(int, int, int, double&, double&, double&, double&, double&, double&);

void checkYesNo(string &);

//Main Function consisting of function calls, cout receipt to console and
//output to a file "project.txt"
int main() {
    int days, timeReturn, timeDepart;
    double airFareCost, rentalCost, privateCar, actualParking, allowedParking,
    allowedTaxi, actualTaxi, conferenceCost, allowedHotel, actualHotel,
    actualBreakfast, actualLunch, actualDinner, allowedBreakfast,
    allowedLunch, allowedDinner;
    
    string name;
    
    cout << "Input employee name: ";
    getline(cin, name);
    
    days = getTotalDays();
    
    timeDepart = departureTime(timeReturn);
    
    airFareCost = airFare();
    
    
    rentalCost = carRental();
    
    
    if(rentalCost == 0)
        privateCar = costPerMile();
    else
        privateCar = 0;
    
    
    allowedParking = parkingFees(days, actualParking);
    
    allowedTaxi = taxiFee(days, actualTaxi);
    
    conferenceCost = conferenceFees();
    
    allowedHotel = hotelExpenses(days, actualHotel);
    
    mealCost(days, timeDepart, timeReturn, actualBreakfast, actualLunch,
             actualDinner, allowedBreakfast, allowedLunch, allowedDinner);
    
    
    system("cls");
    cout << showpoint << fixed << setprecision(2);
    cout << "\n\n\n" << endl;
    cout << setw(5) << "" << "Employee name:      " << name << endl;
    cout << setw(5) << "" << "Trip Length:        " << days << " days" << endl;
    cout << setw(5) << "" << "Leaving home at:    " << timeDepart << endl;
    cout << setw(5) << "" << "Returning home at:  " << timeReturn << endl;
    cout << "\n\n" << endl;
    cout << setw(40) << "ALLOWED" << setw(30) << "SPENT" << endl;
    cout << setw(5) << " " << "______________________________"
    << "______________________________________" << endl;
    cout << endl;
    cout << setw(5) << "" << setw(28) << left << "Air fare: " << "$" << setw(7) << right << airFareCost << setw(25) << "$" << setw(7) << airFareCost << right << endl;
    cout << setw(5) << "" << setw(28) << left <<"Car Rental: " << "$" << setw(7) << right << rentalCost << setw(25) << "$" << setw(7) << rentalCost << right << endl;
    cout << setw(5) << "" << setw(28) << left <<"Miles Driven: " << "$" << setw(7) << right << privateCar << setw(25) << "$" << setw(7) << privateCar << right << endl;
    cout << setw(5) << "" << setw(28) << left << "Total Parking: " << "$" <<  setw(7) << right << allowedParking << setw(25) << "$" << setw(7) << actualParking << right << endl;
    cout << setw(5) << "" << setw(28) << left << "Total Taxi: " << "$" <<  setw(7) << right << allowedTaxi << setw(25) << "$" << setw(7) << actualTaxi << right << endl;
    cout << setw(5) << "" << setw(28) << left << "Conference Fee: " << "$" <<  setw(7) << right << conferenceCost << setw(25) << "$" << setw(7) << conferenceCost << right << endl;
    cout << setw(5) << "" << setw(28) << left <<"Hotel Fee: " << "$" <<  setw(7) << right << allowedHotel << setw(25) << "$" << setw(7) << actualHotel << right << endl;
    cout << setw(5) << "" << setw(28) << left << "Breakfast: " << "$" <<  setw(7) << right << allowedBreakfast << setw(25) << "$" << setw(7) << actualBreakfast << right << endl;
    cout << setw(5) << "" << setw(28) << left << "Lunch: " << "$" <<  setw(7) << right << allowedLunch << setw(25) << "$" << setw(7) << actualLunch << right << endl;
    cout << setw(5) << "" << setw(28) << left <<"Dinner: " << "$" <<  setw(7) << right << allowedDinner << setw(25) << "$" << setw(7) << actualDinner << right << endl;
    cout << endl;
    cout << setw(5) << "" << "_______________________________"
    << "_____________________________________" << endl;
    
    ofstream outFile;
    
    outFile.open("Project.txt");
    outFile << showpoint << fixed << setprecision(2);
    outFile << "\n\n\n" << endl;
    outFile << setw(5) << "" << "Employee name:      " << name << endl;
    outFile << setw(5) << "" << "Trip Length:        " << days << " days" << endl;
    outFile << setw(5) << "" << "Leaving home at:    " << timeDepart << endl;
    outFile << setw(5) << "" << "Returning home at:  " << timeReturn << endl;
    outFile << "\n\n" << endl;
    outFile << setw(40) << "ALLOWED" << setw(30) << "SPENT" << endl;
    outFile << setw(5) << " " << "______________________________"
    << "_____________________________________" << endl;
    outFile << endl;
    outFile << setw(5) << "" << setw(28) << left << "Air fare: " << "$" << setw(7) << right << airFareCost << setw(25) << "$" << setw(7) << airFareCost << right << endl;
    outFile << setw(5) << "" << setw(28) << left <<"Car Rental: " << "$" << setw(7) << right << rentalCost << setw(25) << "$" << setw(7) << rentalCost << right << endl;
    outFile << setw(5) << "" << setw(28) << left <<"Miles Driven: " << "$" << setw(7) << right << privateCar << setw(25) << "$" << setw(7) << privateCar << right << endl;
    outFile << setw(5) << "" << setw(28) << left << "Total Parking: " << "$" <<  setw(7) << right << allowedParking << setw(25) << "$" << setw(7) << actualParking << right << endl;
    outFile << setw(5) << "" << setw(28) << left << "Total Taxi: " << "$" <<  setw(7) << right << allowedTaxi << setw(25) << "$" << setw(7) << actualTaxi << right << endl;
    outFile << setw(5) << "" << setw(28) << left << "Conference Fee: " << "$" <<  setw(7) << right << conferenceCost << setw(25) << "$" << setw(7) << conferenceCost << right << endl;
    outFile << setw(5) << "" << setw(28) << left <<"Hotel Fee: " << "$" <<  setw(7) << right << allowedHotel << setw(25) << "$" << setw(7) << actualHotel << right << endl;
    outFile << setw(5) << "" << setw(28) << left << "Breakfast: " << "$" <<  setw(7) << right << allowedBreakfast << setw(25) << "$" << setw(7) << actualBreakfast << right << endl;
    outFile << setw(5) << "" << setw(28) << left << "Lunch: " << "$" <<  setw(7) << right << allowedLunch << setw(25) << "$" << setw(7) << actualLunch << right << endl;
    outFile << setw(5) << "" << setw(28) << left <<"Dinner: " << "$" <<  setw(7) << right << allowedDinner << setw(25) << "$" << setw(7) << actualDinner << right << endl;
    outFile << endl;
    outFile << setw(5) << "" << "_______________________________"
    << "____________________________________" << endl;
    
    
    cout << "Receipt was sent to file." << endl;
    
    return 0;
}

//BULLET 1
/***************************************************************************
 *                            getTotalDays                                 *
 * This function asks for and returns total number of days spent on trip.  *
 ***************************************************************************
 */
int getTotalDays(){
    int numDays;
    cout << "Enter total number of days spent on trip: ";
    cin >> numDays;
    while(numDays <= 1){
        cout << "Error: Number of days must be greater than 1, re-enter: ";
        cin >> numDays;
    }
    return numDays;
}

//BULLET 2
/******************************************************************
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
/******************************************************************
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

//BULLET 3
/***************************************************************
 *                       Air Fare Cost                         *
 *       This Function returns how much was spent in           *
 *       Air Fare for the trip                                 *
 **************************************************************/
double airFare()
{
    double airFareCost;
    cout << "Enter cost of airfare: ";
    cin >> airFareCost;
    while(airFareCost < 0){
        cout << "Error: Negative value invalid, re-enter: ";
        cin >> airFareCost;
    }
    return airFareCost;
}

//BULLET 4
/****************************************************************
 *                           Car Rental                         *
 *       Asks the user if they rented a car and asks how much   *
 *       the rental was                                         *
 ***************************************************************/
double carRental(){
    string ch;
    double rentalCost;
    cout << "Did you rent a car? (y/n): ";
    cin >> ch;
    checkYesNo(ch);
    if (ch == "y" || ch == "Y"){
        cout << "Enter cost of the rental car: ";
        cin >> rentalCost;
        while(rentalCost < 0){
            cout << "Invalid cost, re-enter: ";
            cin >> rentalCost;
        }
    }
    else{
        rentalCost = 0.0;
    }
    return rentalCost;
}


//BULLET 5
/***************************************************************
 *                      Private Vehicle                        *
 *       Asks the user if a private vehicle was used in        *
 *       transportation and how many miles they drove          *
 *       in it                                                 *
 **************************************************************/
double costPerMile(){
    string ch;
    int milesDriven;
    
    cout << "Was a private vehicle used? (y/n): ";
    cin >> ch;
    checkYesNo(ch);
    /*while(ch != "Y" || ch != "y" || ch != "N" || ch != "n"){
     cout << "Error. Invalid input, please try again";
     cin >> ch;
     }*/
    
    if(ch == "y" ||  ch == "Y"){
        checkYesNo(ch);
        cout << "How many miles were driven? ";
        cin >> milesDriven;
        /*
         while(milesDriven < 0){
         cout << "Error: Invalid number of miles, re-enter: ";
         cin >> milesDriven;
         }
         */
    }
    else{
        milesDriven = 0;
    }
    return milesDriven * PER_MILE;
}

//BULLET 6
/*************************************************************
 *                      Parking Fees                         *
 *          Asks the user how much parking they had to pay   *
 *          for                                              *
 *************************************************************/
double parkingFees(int days, double &spentParking){
    
    cout << "How much was spent on parking during the trip? ";
    cin >> spentParking;
    
    while(spentParking < 0){
        cout << "Error. Please enter a positive number: ";
        cin >> spentParking;
    }
    
    return PARK_PER_DAY * days;
}

//BULLET 7
/***********************************************************
 *                        Taxi Fee                         *
 *                                                         *
 *   This function asks the user to input a fee for Taxi   *
 *   and if it goes over the allowance, the buisnessperson *
 *   must pay the remainder out of pocket                  *
 *                                                         *
 **********************************************************/

double taxiFee(int days, double &taxiSpent)
{
    int     timeFrame = 1;
    taxiSpent = 0.0;
    int numdays = 0;
    double value = 0.0;
    for(int i = 1; i <= days; i++){
        cout << "How much was spent on taxi on day " << timeFrame << ": ";
        cin  >> value;
        while(value < 0){
            cout << "Error: Negative cost invalid, re-enter: ";
            cin >> value;
        }
        if(value > 0){
            numdays++;
        }
        taxiSpent = taxiSpent + value;
        timeFrame++;
    }
    
    return numdays * TAXI_PER_DAY;
}

//BULLET 8
/*************************************************************
 *                       Conference Fees                     *
 *       Asks the user to input how much they had to spend   *
 *       in conference fees                                  *
 ************************************************************/
double conferenceFees()
{
    double conferenceFee;
    cout << "Enter cost of conference registration fees: ";
    cin >> conferenceFee;
    while(conferenceFee < 0){
        cout << "Error: Negative value invalid, re-enter: ";
        cin >> conferenceFee;
    }
    return conferenceFee;
}

//BULLET 9
/*************************************************************
 *                   Hotel Expenses                          *
 *       Calculates how much the businessperson has spent    *
 *       on hotel rooms                                      *
 ************************************************************/
double hotelExpenses(int days, double &spentHotel)
{
    double hotelRate;
    cout << "Enter hotel price per night: ";
    cin >> hotelRate;
    while(hotelRate < 0){
        cout << "Error: Negative rate invalid, enter again: ";
        cin >> hotelRate;
    }
    spentHotel = days * hotelRate;
    return HOTEL_PER_NIGHT * days;
}

//BULLET 10
/***********************************************************
 *                       Meal Cost                         *
 *       Asks the user to input how much they spent on     *
 *       meals every day for the time period they          *
 *       were on the business trip.                        *
 **********************************************************/
void mealCost(int days, int departure, int arrival, double &totalBreakfastSpent, double &totalLunchSpent, double &totalDinnerSpent,
              double &breakfastAllowed, double &lunchAllowed,
              double &dinnerAllowed){
    
    int numBreakfasts = days,
    numLunches = days,
    numDinners = days,
    breakfastSpent,
    lunchSpent,
    dinnerSpent,
    firstBreakfastDay = 1,
    firstLunchDay = 1,
    firstDinnerDay = 1;
    
    
    
    if(departure >= 700){
        numBreakfasts--;
        firstBreakfastDay++;
    }
    if(departure >= 1200){
        numLunches--;
        firstLunchDay++;
    }
    if(departure >= 1800){
        numDinners--;
        firstDinnerDay++;
    }
    if(arrival <= 800)
        numBreakfasts--;
    if(arrival <= 1300)
        numLunches--;
    if(arrival <= 1900)
        numDinners--;
    
    
    if(numBreakfasts > 0){
        for(int i = 1; i <= numBreakfasts; i++){
            cout << "Enter the amount spent on breakfast on day " << firstBreakfastDay << ": ";
            cin >> breakfastSpent;
            while(breakfastSpent < 0){
                cout << "Error: Negative amount invalid, re-enter: ";
                cin >> breakfastSpent;
            }
            totalBreakfastSpent += breakfastSpent;
            firstBreakfastDay++;
        }
        breakfastAllowed = numBreakfasts * BREAKFAST;
    }
    else{
        breakfastSpent = 0;
        breakfastAllowed = 0;
    }
    
    if(numLunches > 0){
        for(int i = 1; i <= numLunches; i++){
            cout << "Enter the amount spent on lunch on day " << firstLunchDay << ": ";
            cin >> lunchSpent;
            while(lunchSpent < 0){
                cout << "Error: Negative amount invalid, re-enter: ";
                cin >> lunchSpent;
            }
            totalLunchSpent += lunchSpent;
            firstLunchDay++;
        }
        lunchAllowed = numLunches * LUNCH;
    }
    else{
        lunchSpent = 0;
        lunchAllowed = 0;
    }
    
    if(numDinners > 0){
        for(int i = 1; i <= numDinners; i++){
            cout << "Enter the amount spent on dinner on day " << firstDinnerDay << ": ";
            cin >> dinnerSpent;
            while(dinnerSpent < 0){
                cout << "Error: Negative amount invalid, re-enter: ";
                cin >> dinnerSpent;
            }
            totalDinnerSpent += dinnerSpent;
            firstDinnerDay++;
        }
        dinnerAllowed = numDinners * DINNER;
    }
    else{
        dinnerSpent = 0;
        dinnerAllowed = 0;
    }
    
}

/*************************************************************
 *                   checkYesNo                              *
 *       Determines if a string input is either y or n       *
 ************************************************************/
void checkYesNo(string &ch){
    regex integer("^(?:Y|y|N|n)?");
    while(!(regex_match(ch, integer))){
        cout << "Wrong input. Please enter y/n or Y/N: ";
        cin >> ch;
        if(regex_match(ch, integer)){
            break;
        }
    }
}


