#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int roomType, nights;
    double pricePerNight = 0.0, subtotal, disc1 = 0.0, disc2 = 0.0, finalTotal;
    char promo;

    //display room list
    cout << "============================================\n";
    cout << "      FTMK GRAND HOTEL BOOKING SYSTEM\n";
    cout << "============================================\n";
    cout << "1. Standard Room   RM150.00 per night\n";
    cout << "2. Deluxe Room     RM200.00 per night\n";
    cout << "3. Suite Room      RM300.00 per night\n";
    cout << "--------------------------------------------\n";

    //ask user to enter roomtype and number of nights
    cout << "\nEnter room type (1-3):";
    cin >> roomType;
    cout << "\nEnter number of nights:";
    cin >> nights;

    if (nights <= 0) {
        cout << "Error number of nights" << endl;
    }

    if (roomType == 1) {
        cout << "You selected Standard Room.";
    }
    else if (roomType == 2) {
        cout << "You selected Deluxe Room.";
    }
    else if (roomType == 3) {
        cout << "You selected Suite Room.";
    }
    else {
        cout << "Invalid room type!" << endl;
    }

    //determine price per night
    switch (roomType)
    {
    case 1: pricePerNight = 150;
        break;
    case 2: pricePerNight = 200;
        break;
    case 3: pricePerNight = 300;
        break;
    }

    subtotal = pricePerNight * nights;

    //calculate first discount
    if (nights >= 1 && nights <= 2)
        disc1 = 0;
    else if (nights >= 3 && nights <= 5)
        disc1 = 0.05 * subtotal;
    else
        disc1 = 0.10 * subtotal;

    double afterFirstDiscount = subtotal - disc1;

    //ask user for promo code 
    cout << "\nDo you have a promo code? (Y for yes / N for No): ";
    cin >> promo;

    if (promo == 'Y' || promo == 'y') {
        disc2 = 0.10 * afterFirstDiscount;
    }

    finalTotal = afterFirstDiscount - disc2;

    // display summary order
    cout << "\n============ BOOKING SUMMARY ============\n";
    cout << fixed << setprecision(2);
    cout << "Price per Night      : RM" << pricePerNight << endl;
    cout << "Nights Stayed        : " << nights << endl;
    cout << "Subtotal             : RM" << subtotal << endl;
    cout << "Discount (Nights)    : RM" << disc1 << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Final Total          : RM" << finalTotal << endl;
    cout << "-----------------------------------------\n";

    //display personalized message based on final total
    if (finalTotal > 1200) {
        cout << "VIP CUSTOMER :You are eligible for free airport pickup!\n";
        cout << "========================================================";
    }
    else if (finalTotal < 300) {
        cout << "Enjoy your vacation!\n";
        cout << "========================================================";
    }
    else {
        cout << "Thank you for booking with FTMK Grand Hotel.\n";
        cout << "========================================================";
    }

    return 0;
}