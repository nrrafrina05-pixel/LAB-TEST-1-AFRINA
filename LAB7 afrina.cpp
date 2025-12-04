#include <iostream>
#include <iomanip>
using namespace std;

double getPrice(int roomType);
double calculateDiscount(int nights, double subtotal);
void computeAmounts(double pricePerNight, int nights, double &subtotal, double &disc1, double &afterFirstDiscount);
double applyPromo(double afterFirstDiscount, char promo);
void displaySummary(double pricePerNight, int nights, double subtotal, double disc1, double finalTotal);
void displayMessage(double finalTotal);

int main()
{
    char booking;

    do {
        int roomType, nights;
        double pricePerNight = 0.0, subtotal, disc1 = 0.0, disc2 = 0.0, finalTotal;
        char promo;


        cout << "\n============================================\n";
        cout << "      FTMK GRAND HOTEL BOOKING SYSTEM\n";
        cout << "============================================\n";
        cout << "1. Standard Room   RM150.00 per night\n";
        cout << "2. Deluxe Room     RM200.00 per night\n";
        cout << "3. Suite Room      RM300.00 per night\n";
        cout << "--------------------------------------------\n";

        cout << "Enter room type (1-3): ";
        cin >> roomType;
        cout << "Enter number of nights: ";
        cin >> nights;

        if (nights <= 0) {
            cout << "Error number of nights" << endl;
        }

        if (roomType == 1) {
            cout << "\nYou selected Standard Room.";
        }
        else if (roomType == 2) {
            cout << "\nYou selected Deluxe Room.";
        }
        else if (roomType == 3) {
            cout << "\nYou selected Suite Room.";
        }
        else {
            cout << "\nInvalid room type!" << endl;
        }

        pricePerNight = getPrice(roomType);

        double afterFirstDiscount;
        computeAmounts(pricePerNight, nights, subtotal, disc1, afterFirstDiscount);

        cout << "\n\nDo you have a promo code? (Y/N): ";
        cin >> promo;

        double promoDisc = applyPromo(afterFirstDiscount, promo);

        finalTotal = afterFirstDiscount - disc2;

        displaySummary(pricePerNight, nights, subtotal, disc1, finalTotal);
        displayMessage(finalTotal);

        cout << "\nAdd another booking? (Y/N): ";
        cin >> booking;

    } while (booking == 'Y' || booking == 'y');

    return 0;
}

//function definition
double getPrice(int roomType)
{
    switch (roomType) {
    case 1:
        return 150;
    case 2:
        return 200;
    case 3:
        return 300;
    }
    return 0;
}

double calculateDiscount(int nights, double subtotal)
{
    if (nights >= 1 && nights <= 2) {
        return subtotal;
    }
    else if (nights >= 3 && nights <= 5) {
        return 0.05 * subtotal;
    }
    else
        return 0.10 * subtotal;
}

void computeAmounts(double pricePerNight, int nights, double& subtotal, double& disc1, double& afterFirstDiscount)
{
    subtotal = pricePerNight * nights;
    disc1 = calculateDiscount(nights, subtotal);
    afterFirstDiscount = subtotal - disc1;
}

double applyPromo(double afterFirstDiscount, char promo)
{
    if (promo == 'Y' || promo == 'y') {
        return 0.10 * afterFirstDiscount;
    }
    else
        return 0;
}

void displaySummary(double pricePerNight, int nights, double subtotal, double disc1, double finalTotal)
{
    cout << "\n============ BOOKING SUMMARY ============\n";
    cout << fixed << setprecision(2);
    cout << "Price per Night      : RM" << pricePerNight << endl;
    cout << "Nights Stayed        : " << nights << endl;
    cout << "Subtotal             : RM" << subtotal << endl;
    cout << "Discount (Nights)    : RM" << disc1 << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Final Total          : RM" << finalTotal << endl;
    cout << "-----------------------------------------\n";
}

void displayMessage(double finalTotal)
{
    if (finalTotal > 1200) {
        cout << "VIP CUSTOMER: You are eligible for free airport pickup!\n";
    }        
    else if (finalTotal < 300) {
        cout << "Enjoy your vacation!\n";
    }       
    else {
        cout << "Thank you for booking with FTMK Grand Hotel.\n";
    }
}
       