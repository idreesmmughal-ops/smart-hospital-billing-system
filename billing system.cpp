#include <iostream>
using namespace std;

/* ---------- Lab 03: Constants ---------- */
const double GENERAL_CHARGE   = 2000;
const double ICU_CHARGE       = 5000;
const double EMERGENCY_CHARGE = 8000;
const double SENIOR_DISCOUNT  = 0.10;


int patientCount = 0;

/* ---------- Function Prototypes (Lab 12) ---------- */
void addPatient(int id[], int age[], int days[]);
void generateBill(int age[], int days[], double bill[], double dailyCharge[]);
void displayRecords(int id[], int age[], int days[], double bill[]);
void applyDiscount(double* amount);         
void showSummary(double bill[]);

int main() {

    /* ---------- Lab 11: Arrays ---------- */
    int patientID[50];
    int age[50], days[50];
    double bill[50], dailyCharge[50];

    int choice;

    /* ---------- Lab 09: Do-While Loop ---------- */
    do {
        cout << "\n--- SMART HOSPITAL MANAGEMENT SYSTEM ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Generate Bill\n";
        cout << "3. Display Patient Records\n";
        cout << "4. Hospital Summary Report\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        /* ---------- Lab 08: Switch Statement ---------- */
        switch (choice) {

        case 1:
            addPatient(patientID, age, days);
            break;

        case 2:
            if (patientCount > 0)
                generateBill(age, days, bill, dailyCharge);
            else
                cout << "No patient record found.\n";
            break;

        case 3:
            displayRecords(patientID, age, days, bill);
            break;

        case 4:
            showSummary(bill);
            break;

        case 5:
            cout << "System exited successfully.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);

    return 0;
}

/* ---------- Function Definitions ---------- */

void addPatient(int id[], int age[], int days[]) {

    id[patientCount] = 1000 + patientCount;   // Patient ID system

    cout << "Enter patient age: ";
    cin >> age[patientCount];

    cout << "Enter days admitted: ";
    cin >> days[patientCount];

    cout << "Patient added successfully.\n";
    cout << "Assigned Patient ID: " << id[patientCount] << endl;

    patientCount++;
}

void generateBill(int age[], int days[], double bill[], double dailyCharge[]) {

    int type;

    cout << "Select Patient Type:\n";
    cout << "1. General\n";
    cout << "2. ICU\n";
    cout << "3. Emergency\n";
    cout << "Enter choice: ";
    cin >> type;

    /* ---------- Lab 07: If-Else Ladder ---------- */
    if (type == 1)
        dailyCharge[patientCount - 1] = GENERAL_CHARGE;
    else if (type == 2)
        dailyCharge[patientCount - 1] = ICU_CHARGE;
    else
        dailyCharge[patientCount - 1] = EMERGENCY_CHARGE;

    bill[patientCount - 1] =
        dailyCharge[patientCount - 1] * days[patientCount - 1];

    /* ---------- Lab 05 + Lab 13 ---------- */
    if (age[patientCount - 1] >= 60) {
        applyDiscount(&bill[patientCount - 1]);   // Pointer usage
    }

    cout << "Bill generated successfully.\n";
}

void displayRecords(int id[], int age[], int days[], double bill[]) {

    /* ---------- Lab 10: For Loop ---------- */
    for (int i = 0; i < patientCount; i++) {
        cout << "\nPatient ID: " << id[i];
        cout << "\nAge: " << age[i];
        cout << "\nDays Admitted: " << days[i];
        cout << "\nTotal Bill: " << bill[i] << endl;
    }
}

void showSummary(double bill[]) {

    double totalRevenue = 0;

    for (int i = 0; i < patientCount; i++) {
        totalRevenue += bill[i];
    }

    cout << "\n--- HOSPITAL SUMMARY REPORT ---\n";
    cout << "Total Patients: " << patientCount << endl;
    cout << "Total Revenue: " << totalRevenue << endl;
}

/* ---------- Lab 13: Pointer Function ---------- */
void applyDiscount(double* amount) {
    *amount = *amount - (*amount * SENIOR_DISCOUNT);
}

