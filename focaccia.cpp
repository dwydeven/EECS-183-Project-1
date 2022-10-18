/**
 * focaccia.cpp
 *
 * <Dominic Wydeven>
 * <dwydeven>
 *
 * EECS 183: Project 1
 * Fall 2022
 *
 * Project UID: d435ced1b1ee1e06372665b53322301c67d2d4a0
 */

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/**
 * Returns the singular or plural form of a word, based on number
 *
 * Requires: singular is the singular form of the word.
 *           plural is the plural form of the word.
 *           number determines how many things there are; must be >= 0.
 * Modifies: Nothing.
 * Effects:  Returns return the singular form of the word if number == 1.
 *           Otherwise, returns the plural form.
 * Examples:
 *           // prints "bag"
 *           cout << pluralize("bag", "bags", 1);
 *
 *           // prints "pounds"
 *           string temp = pluralize("pound", "pounds", 3);
 *           cout << temp;
 */
string pluralize(string singular, string plural, int number);



int main() {

    /*Program Specifications: Calculation for Loaves per Container*/

    /*Ingredients per Loaf*/
    const double CUPSFLOUR = 5.0;
    const double TSPNYEAST = 1.75;
    const double TSPNSALT = 1.875;
    const double TBLSPNOLOIL = 2.0;
    /*Ingredients per Container*/
    const int CUPSFLOURBAG = 20;
    const double TSPNYEASTPACKAGE = 2.25;
        /*Salt comes in 30 gram containers with 5 grams a teaspoon*/
    const double TSPNSALTCANISTER = 30 / 5;
        /*Olive Oil comes in 500 mL bottle, with 14.8 mL a tablespoon*/
    const double TBLSPNOLOILBOTTLE = 500 / 14.8;
    /*Loaves per Container*/
    const double CupsFlourLoaf = CUPSFLOURBAG / CUPSFLOUR;
    const double TspnYeastLoaf = TSPNYEASTPACKAGE / TSPNYEAST;
    const double CnstrSaltLoaf = TSPNSALTCANISTER / TSPNSALT;
    const double OlOilLoaf = TBLSPNOLOILBOTTLE / TBLSPNOLOIL;
    /*Cost Per Container*/
    const double COSTBAGFLOUR = 2.69;
    const double COSTPCKGYEAST = 0.40;
    const double COSTCNTRSALT = 0.49;
    const double COSTBOTTLEOLOIL = 6.39;

    /*Beginning of Program*/

    int people;
        cout << "How many people do you need to serve? ";
        cin >> people;
    cout << "\n";
    
    int NumLoaves = ceil(people / 4.0);
        cout << "You need to make: " << NumLoaves << " " <<
            pluralize("loaf", "loaves", NumLoaves) <<
            " of focaccia" << "\n" << endl;

    double NumBagsFlour = ceil(NumLoaves / CupsFlourLoaf);
    double NumPckgYeast = ceil(NumLoaves / TspnYeastLoaf);
    double NumCnstrSalt = ceil(NumLoaves / CnstrSaltLoaf);
    double NumBottleOlOil = ceil(NumLoaves / OlOilLoaf);

    double FlourCost = NumBagsFlour * COSTBAGFLOUR;
    double YeastCost = NumPckgYeast * COSTPCKGYEAST;
    double SaltCost = NumCnstrSalt * COSTCNTRSALT;
    double OlOilCost = NumBottleOlOil * COSTBOTTLEOLOIL;

    cout << "Shopping List for Focaccia Bread" << endl <<
        "--------------------------------" << endl;
    
    cout << NumBagsFlour << " " <<
        pluralize("bag", "bags", NumBagsFlour) << 
        " of flour" << endl;
    
    cout << NumPckgYeast << " " <<
        pluralize("package", "packages", NumPckgYeast) <<
        " of yeast" << endl;

    cout << NumCnstrSalt << " " <<
        pluralize("canister", "canisters", NumCnstrSalt) <<
        " of salt" << endl;
   
    cout << NumBottleOlOil << " " <<
        pluralize("bottle", "bottles", NumBottleOlOil) <<
        " of olive oil" << endl << endl;

    double TotCost = FlourCost + YeastCost + SaltCost + OlOilCost;

    cout << "Total expected cost of ingredients: $" << TotCost << endl << endl;
    cout << "Have a great party!";

        cout << endl << endl;


    return 0;
}

// ----------------------------------------------
// *** DO NOT CHANGE ANYTHING BELOW THIS LINE ***

string pluralize(string singular, string plural, int number) {
    if (number == 1) {
        return singular;
    }
    return plural;
}


