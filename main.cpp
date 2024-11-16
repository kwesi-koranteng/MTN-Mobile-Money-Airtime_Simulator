#include <iostream>
#include <fstream> // Include to handle file operations

using namespace std;

int main() {

    // All variable declarations
    string mtnUSSDcode = "*170#", userUSSDcode;
    int choice;
    string recipientNumber1, recipientNumber2, recipientname;
    float amount;
    string reference;
    int momoPIN2 = 1234, momoPIN1;
    int airtimechoice, airtimeself;
    int trials = 0;

    // File streams for MOMO and Airtime messages
    ofstream momoFile("momo_messages.txt", ios::app);
    ofstream airtimeFile("airtime_messages.txt", ios::app);
    
    do {
    	cout << "\nEnter the MOMO code " << endl;
    	cout << "USSD: ";
    	cin >> userUSSDcode;
    	trials++;
    	if (userUSSDcode != mtnUSSDcode) {
            cout << "Incorrect code! Try again.\n";
        }
        
    } while (userUSSDcode != mtnUSSDcode); // Repeat if the code is incorrect
	cout << "You have tried " << trials << " times" << endl;

    if (userUSSDcode == mtnUSSDcode) {
        cout << "\n\n    MTN MOMO" << endl;
        cout << "1. Transfer Money" << endl;
        cout << "2. MomoPay" << endl;
        cout << "3. Airtime/Bundle" << endl;
        cout << "4. Exit" << endl;

        cout << "\nChoice: " << endl;
        cin >> choice;

        switch (choice) {
            case 1: // MOMO Transfer Money
                cout << "\tTransfer Money" << endl;
                cout << "\n1. Momo User" << endl;
                cout << "2. Other Networks" << endl;

                // Making a choice in Networks to send money
                cout << "\nChoice: " << endl;
                cin >> choice;

                if (choice == 1) {
                    cout << "\nEnter Mobile Number" << endl;
                    cin >> recipientNumber1;

                    cout << "\nConfirm Mobile Number" << endl;
                    cin >> recipientNumber2;

                    if (recipientNumber1 == recipientNumber2) {
                        cout << "\nEnter the Amount" << endl;
                        cout << "Amount: ";
                        cin >> amount;

                        // Enter the Reference
                        cout << "\nEnter your Reference" << endl;
                        cout << "-> ";
                        cin >> reference;

                        cout << "\nTransfer to " << recipientNumber1 << ", an Amount of " << amount
                             << " with reference: " << reference << ". Fee is GHS 0.00, Tax GHS 0.00, total amount is "
                             << amount << "\nEnter Momo Pin OR any key to cancel";

                        cin >> momoPIN1;

                        if (momoPIN1 == momoPIN2) {
                            string momoMessage = "You sent " + to_string(amount) + " to " + recipientNumber1 + "\n";
                            cout << momoMessage;
                            momoFile << momoMessage; // Wcrite MOMO message to file
                        } else {
                            cout << "Wrong Pin" << endl;
                        }
                    } else {
                        cout << "Incorrect Number! Try again" << endl;
                    }
                }
                break;

            case 3: // Airtime/Bundle
                cout << "\tAirtime/Bundle" << endl;
                cout << "\n1. Airtime" << endl;
                cout << "2. Internet Bundles" << endl;
                cout << "3. Fixed Broadband" << endl;
                cout << "4. Schedule Airtime" << endl;
                cout << "5. Just4U" << endl;

                cout << "\nChoice: " << endl;
                cin >> airtimechoice;

                if (airtimechoice == 1) {
                    cout << "\tAirtime" << endl;
                    cout << "\n1. Self" << endl;
                    cout << "2. Others" << endl;

                    cout << "\nChoice: " << endl;
                    cin >> airtimeself;

                    if (airtimeself == 1) {
                        // Buy airtime for yourself
                        cout << "\nEnter the amount of airtime to buy: " << endl;
                        cin >> amount;

                        cout << "\nEnter your name: " << endl;
                        cin >> recipientname;

                        cout << "\nDEAR " << recipientname << ", Send GHS " << amount << " Airtime to self."
                             << " Fee is GHS 0.00." << "\nEnter Momo Pin OR any key to cancel" << endl;

                        cin >> momoPIN1;

                        if (momoPIN1 == momoPIN2) {
                            string airtimeMessage = "You sent GHS " + to_string(amount) + " to yourself\n";
                            cout << airtimeMessage;
                            airtimeFile << airtimeMessage; // Write Airtime message to file
                        } else {
                            cout << "\nWrong Pin" << endl;
                        }

                    } else if (airtimeself == 2) {
                        // Buy airtime for others
                        cout << "\nEnter Mobile Number" << endl;
                        cin >> recipientNumber1;

                        cout << "\nConfirm Mobile Number" << endl;
                        cin >> recipientNumber2;

                        if (recipientNumber1 == recipientNumber2) {
                            cout << "\nEnter the Amount" << endl;
                            cout << "Amount: ";
                            cin >> amount;

                            // Enter the Reference
                            cout << "\nEnter your Reference" << endl;
                            cout << "-> ";
                            cin >> reference;

                            cout << "\nSend GHS " << amount << " to " << recipientNumber1
                                 << ". Fee is GHS 0.00." << "\nEnter Momo Pin OR any key to cancel" << endl;

                            cin >> momoPIN1;

                            if (momoPIN1 == momoPIN2) {
                                string airtimeMessage = "You sent GHS " + to_string(amount) + " to " + recipientNumber1 + "\n";
                                cout << airtimeMessage;
                                airtimeFile << airtimeMessage; // Write Airtime message to file
                            } else {
                                cout << "\nWrong Pin" << endl;
                            }
                        }
                    }
                }
                break;

            case 4:
                cout << "Thanks for transacting with us!!!" << endl;
                break;

            default:
                cout << "Options are 1 - 4" << endl;
                break;
        }

    } else {
        cout << "Try with the MTN USSD code" << endl;
    }

    // Close files
    momoFile.close();
    airtimeFile.close();

    return 0;
}
