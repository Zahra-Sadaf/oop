#include <iostream>
#include <string>
#include <limits>
using namespace std;

// ===================== CONSTANTS =====================
const int MAX_EMPLOYEES = 550;
const int MAX_MEETINGS  = 50;

// ===================== GLOBAL DATA =====================
int current_employee = 10;
int meeting_count    = 3;

string employee_name[MAX_EMPLOYEES]    = {"ali","zara","faiza","nisa","shayaan","ayaan","abdullah","manal","faria","gul"};
int    employee_ID[MAX_EMPLOYEES]      = {101,102,103,104,105,106,107,108,109,110};
float  employee_salary[MAX_EMPLOYEES]  = {60000,50000,70000,56000,90000,45000,78000,65000,55000,78000};
int    employee_age[MAX_EMPLOYEES]     = {25,56,45,32,23,34,35,33,22,40};
string employee_address[MAX_EMPLOYEES] = {"Lahore","Murree","Islamabad","Karachi","Multan","Mianwali","Gojra","DGKhan","Peshawar","Basti"};
float  increment_record[MAX_EMPLOYEES] = {0};

string meeting_title[MAX_MEETINGS]  = {"Team Standup","Project Review","HR Meeting"};
string meeting_date[MAX_MEETINGS]   = {"2025-04-22","2025-04-25","2025-05-01"};
string meeting_time_arr[MAX_MEETINGS]   = {"09:00 AM","02:00 PM","11:00 AM"};
int    meeting_emp_id[MAX_MEETINGS] = {0, 102, 101};

// ===================== HELPERS =====================
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

void pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void printHeader(const string& title) {
    cout << "=============================================" << endl;
    cout << "  " << title                                  << endl;
    cout << "=============================================" << endl;
}

void printDivider() {
    cout << "---------------------------------------------" << endl;
}

// ===================== FIND HELPERS =====================
int findByID(int id) {
    for (int i = 0; i < current_employee; i++)
        if (employee_ID[i] == id) return i;
    return -1;
}

int findByName(const string& name) {
    for (int i = 0; i < current_employee; i++)
        if (employee_name[i] == name) return i;
    return -1;
}

// ===================== ADMIN FEATURES =====================
void viewAllEmployees() {
    cout << "\n";
    printHeader("All Employee Records");
    cout << "Name\t\tAge\tSalary\t\tID\tAddress" << endl;
    printDivider();
    for (int i = 0; i < current_employee; i++) {
        if (employee_name[i] != "") {
            cout << employee_name[i]    << "\t\t"
                 << employee_age[i]     << "\t"
                 << employee_salary[i]  << "\t\t"
                 << employee_ID[i]      << "\t"
                 << employee_address[i] << endl;
        }
    }
    printDivider();
}

void addEmployee() {
    if (current_employee >= MAX_EMPLOYEES) {
        cout << "Maximum employee limit reached!" << endl;
        return;
    }
    int idx = current_employee;
    cout << "\n";
    printHeader("Add New Employee");
    cout << "Enter employee name    : "; cin >> employee_name[idx];
    cout << "Enter employee age     : "; cin >> employee_age[idx];
    cout << "Enter employee address : "; cin >> employee_address[idx];
    cout << "Enter employee ID      : "; cin >> employee_ID[idx];
    cout << "Enter employee salary  : "; cin >> employee_salary[idx];
    increment_record[idx] = 0;
    current_employee++;
    cout << "\nEmployee added successfully!" << endl;
}

void deleteEmployee() {
    cout << "\n";
    printHeader("Delete Employee Record");
    cout << "Enter employee name to delete: ";
    string name; cin >> name;

    int idx = findByName(name);
    if (idx == -1) { cout << "Employee not found!" << endl; return; }

    employee_name[idx]    = "";
    employee_age[idx]     = 0;
    employee_address[idx] = "";
    employee_ID[idx]      = 0;
    employee_salary[idx]  = 0;
    increment_record[idx] = 0;
    cout << "Record of " << name << " deleted successfully." << endl;
}

void updateEmployee() {
    cout << "\n";
    printHeader("Update Employee Record");
    cout << "Enter employee name to update: ";
    string name; cin >> name;

    int idx = findByName(name);
    if (idx == -1) { cout << "Employee not found!" << endl; return; }

    cout << "\n------- OLD RECORD -------" << endl;
    cout << "Name: "    << employee_name[idx]
         << " | Age: "  << employee_age[idx]
         << " | Salary: Rs." << employee_salary[idx]
         << " | ID: "   << employee_ID[idx]
         << " | Address: " << employee_address[idx] << endl;

    cout << "\n------- Enter New Details -------" << endl;
    cout << "New name    : "; cin >> employee_name[idx];
    cout << "New address : "; cin >> employee_address[idx];
    cout << "New ID      : "; cin >> employee_ID[idx];
    cout << "New age     : "; cin >> employee_age[idx];
    cout << "New salary  : "; cin >> employee_salary[idx];
    cout << "\nRecord updated successfully!" << endl;
}

void searchEmployee() {
    cout << "\n";
    printHeader("Search Employee");
    cout << "Enter employee name to search: ";
    string name; cin >> name;

    int idx = findByName(name);
    if (idx == -1) { cout << "No record found for: " << name << endl; return; }

    cout << "\n------- Employee Found -------" << endl;
    cout << "Name    : " << employee_name[idx]    << endl;
    cout << "Age     : " << employee_age[idx]     << endl;
    cout << "Salary  : Rs. " << employee_salary[idx] << endl;
    cout << "ID      : " << employee_ID[idx]      << endl;
    cout << "Address : " << employee_address[idx] << endl;
    printDivider();
}

void applyIncrement() {
    cout << "\n";
    printHeader("Apply Salary Increment");
    cout << "Enter employee name for increment: ";
    string name; cin >> name;

    int idx = findByName(name);
    if (idx == -1) { cout << "Employee not found!" << endl; return; }

    // BUG FIX: original compared array pointer to int (employee_salary >= 60000)
    // and used wrong arithmetic (added 1 then multiplied without assigning).
    // Fixed: properly calculate 10% and apply only if salary >= 60000.
    if (employee_salary[idx] >= 60000) {
        float incAmount = employee_salary[idx] * (10.0f / 100.0f);
        cout << "Old Salary : Rs. " << employee_salary[idx] << endl;
        employee_salary[idx]  += incAmount;
        increment_record[idx] += incAmount;
        cout << "New Salary : Rs. " << employee_salary[idx] << endl;
        cout << "10% annual increment applied successfully!" << endl;
    } else {
        cout << "Salary is below Rs.60000. Increment not applicable." << endl;
    }
}

void sortEmployees() {
    // Bubble sort by salary ascending
    for (int i = 0; i < current_employee - 1; i++) {
        for (int j = 0; j < current_employee - 1 - i; j++) {
            if (employee_salary[j] > employee_salary[j + 1]) {
                swap(employee_salary[j],  employee_salary[j + 1]);
                swap(employee_name[j],    employee_name[j + 1]);
                swap(employee_ID[j],      employee_ID[j + 1]);
                swap(employee_age[j],     employee_age[j + 1]);
                swap(employee_address[j], employee_address[j + 1]);
                swap(increment_record[j], increment_record[j + 1]);
            }
        }
    }
    cout << "\nEmployees sorted by salary (ascending):" << endl;
    cout << "Name\t\tAge\tSalary\t\tID\tAddress" << endl;
    printDivider();
    for (int i = 0; i < current_employee; i++) {
        if (employee_name[i] != "") {
            cout << employee_name[i]    << "\t\t"
                 << employee_age[i]     << "\t"
                 << employee_salary[i]  << "\t\t"
                 << employee_ID[i]      << "\t"
                 << employee_address[i] << endl;
        }
    }
    printDivider();
}

void viewJobApplicants() {
    cout << "\n";
    printHeader("View Job Applicants");
    int n;
    cout << "Enter number of job applicants: "; cin >> n;
    for (int i = 0; i < n; i++) {
        string name;
        int age, experience;
        float salary;
        cout << "\n--- Applicant " << (i + 1) << " ---" << endl;
        cout << "Name             : "; cin >> name;
        cout << "Age              : "; cin >> age;
        cout << "Desired Salary   : "; cin >> salary;
        cout << "Experience (yrs) : "; cin >> experience;
        cout << "Details recorded for " << name << "." << endl;
    }
}

void hireApplicants() {
    cout << "\n";
    printHeader("Hire Job Applicants");
    int n;
    cout << "Enter number of applicants to process: "; cin >> n;
    // BUG FIX: original had n++ inside the loop causing infinite loop
    for (int i = 0; i < n; i++) {
        string name;
        int experience;
        cout << "\n--- Applicant " << (i + 1) << " ---" << endl;
        cout << "Enter name             : "; cin >> name;
        cout << "Enter experience (yrs) : "; cin >> experience;
        if (experience > 5)
            cout << "Congratulations " << name << "! You have been hired." << endl;
        else
            cout << name << " does not meet the experience requirement (> 5 years)." << endl;
    }
}

void addMeeting() {
    if (meeting_count >= MAX_MEETINGS) { cout << "Meeting limit reached!" << endl; return; }
    cout << "\n";
    printHeader("Add Meeting");
    cout << "Enter meeting title             : "; cin >> meeting_title[meeting_count];
    cout << "Enter meeting date (YYYY-MM-DD) : "; cin >> meeting_date[meeting_count];
    cout << "Enter meeting time              : "; cin >> meeting_time_arr[meeting_count];
    cout << "Enter employee ID (0 = all)     : "; cin >> meeting_emp_id[meeting_count];
    meeting_count++;
    cout << "Meeting added successfully!" << endl;
}

// ===================== EMPLOYEE FEATURES =====================
void viewMyProfile(int idx) {
    cout << "\n";
    printHeader("My Profile");
    cout << "Name    : " << employee_name[idx]    << endl;
    cout << "ID      : " << employee_ID[idx]      << endl;
    cout << "Age     : " << employee_age[idx]     << endl;
    cout << "Address : " << employee_address[idx] << endl;
    cout << "Salary  : Rs. " << employee_salary[idx] << endl;
    printDivider();
}

void updateMyProfile(int idx) {
    cout << "\n";
    printHeader("Update My Profile");
    cout << "Current Name: " << employee_name[idx] << endl;
    cout << "Enter new name (type 0 to keep): ";
    string newName; cin >> newName;
    if (newName != "0") employee_name[idx] = newName;

    cout << "Current Age: " << employee_age[idx] << endl;
    cout << "Enter new age (0 to keep): ";
    int newAge; cin >> newAge;
    if (newAge != 0) employee_age[idx] = newAge;

    cout << "Current Address: " << employee_address[idx] << endl;
    cout << "Enter new address (0 to keep): ";
    string newAddr; cin >> newAddr;
    if (newAddr != "0") employee_address[idx] = newAddr;

    cout << "\nProfile updated successfully!" << endl;
}

void viewSalary(int idx) {
    cout << "\n";
    printHeader("Salary Details");
    cout << "Employee Name  : " << employee_name[idx]   << endl;
    cout << "Employee ID    : " << employee_ID[idx]     << endl;
    cout << "Monthly Salary : Rs. " << employee_salary[idx] << endl;
    printDivider();
}

void viewIncrementRecord(int idx) {
    cout << "\n";
    printHeader("Increment Record");
    cout << "Employee Name : " << employee_name[idx] << endl;
    cout << "Employee ID   : " << employee_ID[idx]   << endl;
    // BUG FIX: original had empty loop body — now actually shows data
    if (increment_record[idx] == 0)
        cout << "No increment has been applied yet." << endl;
    else {
        cout << "Total Increment Applied : Rs. " << increment_record[idx] << endl;
        cout << "Current Salary          : Rs. " << employee_salary[idx]  << endl;
    }
    printDivider();
}

void viewMeetings(int empID) {
    cout << "\n";
    printHeader("My Meetings");
    bool found = false;
    for (int i = 0; i < meeting_count; i++) {
        if (meeting_emp_id[i] == 0 || meeting_emp_id[i] == empID) {
            cout << "Title : " << meeting_title[i]    << endl;
            cout << "Date  : " << meeting_date[i]     << endl;
            cout << "Time  : " << meeting_time_arr[i] << endl;
            printDivider();
            found = true;
        }
    }
    if (!found)
        cout << "No meetings scheduled for you." << endl;
}

// ===================== EMPLOYEE MENU =====================
void employeeMenu() {
    cout << "\n";
    printHeader("Employee Login");
    cout << "Enter your Employee ID: ";
    int empID; cin >> empID;

    int idx = findByID(empID);
    if (idx == -1) {
        cout << "Employee ID not found! Access denied." << endl;
        pauseScreen();
        return;
    }
    cout << "\nWelcome, " << employee_name[idx] << "!" << endl;

    while (true) {
        clearScreen();
        printHeader("EMPLOYEE PORTAL");
        cout << "1. View My Profile"       << endl;
        cout << "2. Update My Profile"     << endl;
        cout << "3. View Salary"           << endl;
        cout << "4. View Increment Record" << endl;
        cout << "5. View Meetings"         << endl;
        cout << "6. Logout"                << endl;
        printDivider();
        cout << "Enter your choice: ";
        int choice; cin >> choice;

        if      (choice == 1) viewMyProfile(idx);
        else if (choice == 2) updateMyProfile(idx);
        else if (choice == 3) viewSalary(idx);
        else if (choice == 4) viewIncrementRecord(idx);
        else if (choice == 5) viewMeetings(empID);
        else if (choice == 6) {
            cout << "Logging out. Goodbye, " << employee_name[idx] << "!" << endl;
            pauseScreen();
            break;
        }
        else cout << "Invalid choice! Please try again." << endl;

        pauseScreen();
    }
}

// ===================== ADMIN MENU =====================
void adminMenu() {
    printHeader("Admin Login");
    bool loggedIn = false;

    for (int attempt = 1; attempt <= 3; attempt++) {
        string username;
        int password;
        cout << "Enter username: "; cin >> username;
        cout << "Enter password: "; cin >> password;

        if (username == "Admin" && password == 1234) {
            cout << "\nAdmin login successful!" << endl;
            loggedIn = true;
            break;
        }
        cout << "Incorrect credentials! Attempts left: " << (3 - attempt) << endl;
    }

    if (!loggedIn) {
        cout << "Too many failed attempts. Returning to main menu." << endl;
        pauseScreen();
        return;
    }

    while (true) {
        clearScreen();
        printHeader("ADMIN PANEL");
        cout << " 1.  View All Employee Records" << endl;
        cout << " 2.  Add New Employee"           << endl;
        cout << " 3.  Delete Employee Record"     << endl;
        cout << " 4.  Update Employee Record"     << endl;
        cout << " 5.  Search Employee by Name"    << endl;
        cout << " 6.  Apply Salary Increment"     << endl;
        cout << " 7.  Sort Employees by Salary"   << endl;
        cout << " 8.  View Job Applicants"        << endl;
        cout << " 9.  Hire Job Applicants"        << endl;
        cout << "10.  Add Meeting"                << endl;
        cout << "11.  Exit Admin Panel"           << endl;
        printDivider();
        cout << "Enter your choice: ";
        int choice; cin >> choice;

        if      (choice == 1)  viewAllEmployees();
        else if (choice == 2)  addEmployee();
        else if (choice == 3)  deleteEmployee();
        else if (choice == 4)  updateEmployee();
        else if (choice == 5)  searchEmployee();
        else if (choice == 6)  applyIncrement();
        else if (choice == 7)  sortEmployees();
        else if (choice == 8)  viewJobApplicants();
        else if (choice == 9)  hireApplicants();
        else if (choice == 10) addMeeting();
        else if (choice == 11) {
            cout << "Exiting Admin Panel..." << endl;
            pauseScreen();
            break;
        }
        else cout << "Invalid choice! Please enter a number between 1-11." << endl;

        pauseScreen();
    }
}

// ===================== MAIN =====================
int main() {
    while (true) {
        clearScreen();
        cout << "=============================================" << endl;
        cout << "   SOFTWARE HOUSE MANAGEMENT SYSTEM"          << endl;
        cout << "=============================================" << endl;
        cout << "1. Admin"    << endl;
        cout << "2. Employee" << endl;
        cout << "3. Exit"     << endl;
        printDivider();
        cout << "Enter your choice: ";
        int choice; cin >> choice;

        if (choice == 1) {
            clearScreen();
            adminMenu();
        }
        else if (choice == 2) {
            clearScreen();
            employeeMenu();
        }
        else if (choice == 3) {
            cout << "Exiting system. Goodbye!" << endl;
            break;
        }
        else {
            cout << "Invalid choice! Try again." << endl;
            pauseScreen();
        }
    }
    return 0;
}
