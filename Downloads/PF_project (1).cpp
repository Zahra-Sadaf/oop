#include <iostream>
#include <conio.h>
using namespace std;
main()
{
    int total_employee = 550;
    int current_employee = 10;
    int n;

    // Data Structure
    string employee_name[total_employee] = {"ali", "zara", "faiza", "nisa", "shayaan", "ayaan", "abdullah", "manal", "faria", "gul"};
    int employee_ID[total_employee] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
    float employee_salary[total_employee] = {60000, 50000, 70000, 56000, 90000, 45000, 78000, 65000, 55000, 78000};
    int employee_age[total_employee] = {25, 56, 45, 32, 23, 34, 35, 33, 22, 40};
    string employee_address[total_employee] = {"lahore", "Munro", "Islamabad", "Karachi", "Multan", "Mianwali", "Gojra", "Dgkhan", "peshawar", "basti"};
    int job_applicant[n];
    // CRUD
    while (true)
    {
        // Main Header Of Software House Management System
        system("cls");
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        cout << "-----------------    --------SOFTWARE HOUSE MANAGEMENT SYSTEM--------       ---------------------------------" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;

        cout << endl;
        // User Menu display
        cout << "1.Admin" << endl;
        cout << "2.Employee" << endl;
        cout << endl;

        int choice;
        cout << "Enter your choice:";
        cin >> choice;
        cout << endl;
        cout << "Your choice is:" << choice << endl;
        cout << endl;
        if (choice == 1)
        {

            // Admin login Attempt

            system("cls");
            int count_attempt = 0;
            for (int i = 1; i <= 3; i++)
            {
                string user_name;
                int password;
                cout << "Enter the username:";
                cin >> user_name;
                cout << "Enter the password:";
                cin >> password;
                if (user_name == "Admin" && password == 1234)
                {
                    cout << "Admin login successful!" << endl;

                    cout << endl;
                    while (true)
                    {
                        system("cls");
                        // Admin Menu Display
                        cout << "1. View all Employee record" << endl;
                        cout << "2. Add New Employee record" << endl;
                        cout << "3. Delete Employee record" << endl;
                        cout << "4. Update Employee record" << endl;
                        cout << "5. Search Employee by Name " << endl;
                        cout << "6. Employee's increment" << endl;
                        cout << "7. Sorting Employee record" << endl;
                        cout << "8. Viewing Job Applicant " << endl;
                        cout << "9. Hiring of Job applicant" << endl;
                        cout << "10. Exit" << endl;
                        cout << endl;
                        //========= ===Admin choice=== ==============
                        int admin_choice;
                        cout << "Enter your choice:" << endl;
                        cin >> admin_choice;
                        cout << endl;
                        cout << "Your choice is:\t" << admin_choice;
                        cout << endl;
                        cout << "=====================================";
                        if (admin_choice == 1)
                        {
                            // ============= ===View all Employee record==== ================
                            cout << "Name \t employee_age\t employee_salary\t employee_ID\temployee_address";
                            cout << endl;
                            for (int i = 0; i < current_employee; i++)
                            {
                                if (employee_name[i] != "")
                                {
                                    cout << employee_name[i] << "\t\t" << employee_age[i] << "\t\t" << employee_salary[i] << "\t\t" << employee_ID[i] << "\t\t" << employee_address[i];
                                    cout << endl;
                                }
                            }
                            cout << "================================================================================";
                        }
                        else if (admin_choice == 2)
                        {
                            //========= ====Add New Employee record==== =====================
                            int n, age, Id;
                            string name, address;
                            float salary;
                            cout << "Enter the number of employees to be added:";
                            cin >> n;
                            cout << "Enter the name of employee to be added:";
                            for (int i = 0; i < n; i++)
                            {
                                cin >> name;
                            }
                            cout << "Enter the employee's age:";
                            for (int j = 0; j < n; j++)
                            {
                                cin >> age;
                            }
                            cout << "Enter the customer address:";
                            for (int k = 0; k < n; k++)
                            {
                                cin >> address;
                            }
                            cout << "Enter the employee ID:";
                            for (int m = 0; m < n; m++)
                            {
                                cin >> Id;
                            }
                            cout << "Enter the employees monthly salary:";
                            for (int l = 0; l < n; l++)
                            {
                                cin >> salary;
                            }
                            total_employee++;
                            cout << endl;
                            cout << "==============================================";
                        }
                        else if (admin_choice == 3)
                        {

                            //================ ===Delete Employee's Record=== =========================
                            cout << " Enter the employee name you want to delete record of : ";
                            string name;
                            cin >> name;
                            bool found = false;
                            int found_index = -1;
                            for (int i = 0; i < current_employee; i++)
                            {
                                if (employee_name[i] == name)
                                {
                                    found_index = i;
                                    found = true;
                                }
                            }
                            if (found == true)
                            {
                                employee_name[found_index] = "";
                                employee_age[found_index] = 0;
                                employee_address[found_index] = "";
                                employee_ID[found_index] = 0;
                                employee_salary[found_index] = 0;

                                cout << " Record of " << name << " Deleted " << endl;
                            }
                            else
                            {
                                cout << " Record not found " << endl;
                            }
                        }
                        else if (admin_choice == 4)
                        {
                            //======= ===update employee record=== =====================
                            cout << " Enter the name you want to update record of : ";
                            string name;
                            cin >> name;
                            bool found = false;
                            int found_index = -1;
                            for (int i = 0; i < current_employee; i++)
                            {
                                if (employee_name[i] == name)
                                {
                                    found_index = i;
                                    found = true;
                                }
                            }
                            if (found == true)
                            {
                                int age, ID;
                                float salary;
                                string name, address;
                                cout << " ------- OLD RECORD ------- " << endl;
                                cout << " Name \tAge \t address \temployee ID \tEmployee address\t Employee salary " << endl;
                                cout << employee_name[found_index] << "\t" << employee_age[found_index] << "\t" << employee_salary[found_index] << "\t" << employee_address[found_index] << "\t" << employee_ID[found_index] << "\t";
                                cout << endl;
                                cout << "------- Updated Record---------" << endl;
                                cout << "Enter the name you want to update:";
                                cin >> name;
                                cout << "Enter the address you want to update:";
                                cin >> address;
                                cout << "Enter the ID you want to update:";
                                cin >> ID;
                                cout << "Enter the age you want to update:";
                                cin >> age;
                                cout << "Enter the salary you want to update:";
                                cin >> salary;
                                cout << endl;

                                employee_name[found_index] = name;
                                employee_address[found_index] = address;
                                employee_ID[found_index] = ID;
                                employee_age[found_index] = age;
                                employee_salary[found_index] = salary;

                                cout << "Record Updated Successfully!" << endl;
                            }
                            cout << "===================================================";
                        }
                        else if (admin_choice == 5)
                        {
                            //============= ===Search Employee by Record by name=== =========================
                            cout << " Enter the name you want to search : ";
                            string name;
                            cin >> name;
                            bool found = false;
                            int found_index = -1;
                            for (int i = 0; i < current_employee; i++)
                            {
                                if (employee_name[i] == name)
                                {
                                    found_index = i;
                                    found = true;
                                }
                            }
                            if (found == false)
                            {
                                cout << " Record not found against name " << name << endl;
                            }
                            cout << "=========================================================";
                        }

                        else if (admin_choice == 6)
                        {
                            //=========== ===Employee's annual increment=== =====================
                            string name;
                            cout << "Enter the name of employee for increment:";
                            for (int m = 0; m < current_employee; m++)
                            {
                                cin >> name;

                                bool found = false;
                                int found_index = -1;

                                for (int i = 0; i < current_employee; i++)
                                {
                                    if (employee_name[i] == name)
                                    {
                                        found = true;
                                        found_index = i;
                                        break;
                                    }
                                }

                                if (found == true)
                                {
                                    float percent = 10; // 10% annual increment

                                    cout << "Old Salary: " << employee_salary[found_index] << endl;

                                    employee_salary[found_index] +=
                                        employee_salary[found_index] * (percent / 100);

                                    cout << "New Salary after 10% annual increment: " << employee_salary[found_index] << endl;

                                    cout << "Annual Increment Applied Successfully!" << endl;
                                }
                                else
                                {
                                    cout << "Employee not found!" << endl;
                                }
                            }
                            cout << "==========================================================";
                        }
                        else if (admin_choice == 7)
                        {
                            for (int i = 0; i < current_employee; i++)
                            {
                                for (int j = 0; j < current_employee - 1; j++)
                                {
                                    if (employee_salary[j] > employee_salary[j + 1])
                                    {
                                        if (employee_salary[j] > employee_salary[j + 1])
                                        {
                                            // swap salary
                                            float tempSalary = employee_salary[j];
                                            employee_salary[j] = employee_salary[j + 1];
                                            employee_salary[j + 1] = tempSalary;

                                            // swap name
                                            string tempName = employee_name[j];
                                            employee_name[j] = employee_name[j + 1];
                                            employee_name[j + 1] = tempName;

                                            // swap ID
                                            int tempID = employee_ID[j];
                                            employee_ID[j] = employee_ID[j + 1];
                                            employee_ID[j + 1] = tempID;

                                            // swap age
                                            int tempAge = employee_age[j];
                                            employee_age[j] = employee_age[j + 1];
                                            employee_age[j + 1] = tempAge;

                                            // swap address
                                            string tempAddress = employee_address[j];
                                            employee_address[j] = employee_address[j + 1];
                                            employee_address[j + 1] = tempAddress;
                                        }
                                    }
                                }
                            }
                            cout << "Employees sorted by salary (ascending):\n";

                            for (int i = 0; i < current_employee; i++)
                            {
                                cout << employee_name[i] << "\t"
                                     << employee_age[i] << "\t"
                                     << employee_salary[i] << "\t"
                                     << employee_ID[i] << "\t"
                                     << employee_address[i] << endl;
                            }
                        }
                        //===== ===Viewing Job applicant=== ===============
                        else if (admin_choice == 8)
                        {
                            int experience, age;
                            float salary;
                            string name;
                            cout << "Enter the number of job applicants:";
                            cin >> n;
                            cout << "Enter the name of job applicant:";
                            for (int i = 0; i < n; i++)
                            {
                                cin >> name;
                                cout << endl;
                            }
                            cout << "Enter the age :";
                            for (int m = 0; m < n; m++)
                            {
                                cin >> age;
                            }
                            cout << "Enter the desired salary:";
                            for (int k = 0; k < n; k++)
                            {
                                cin >> salary;
                            }
                            cout << "Enter the experience:";
                            for (int l = 0; l < n; l++)
                            {
                                cin >> experience;
                            }
                            cout << endl;
                        }
                        else if (admin_choice == 9)
                        {
                            //===========  ===Hiring of Job Applicants=== ===============
                            int experience;
                            string name;
                            cout << "Enter the number of job applicants:";
                            cin >> n;
                            cout << "Enter the name of job applicant:";
                            for (int i = 0; i < n; i++)
                            {
                                cin >> name;
                                cout << endl;
                                cout << "Enter the Experience:";
                                for (int k = 0; k < n; k++)
                                {
                                    cin >> experience;
                                    n++;
                                    if (experience > 5)
                                    {
                                        cout << "Congratulations! You have been hired.";
                                    }
                                    else
                                    {
                                        cout << "Doesnot meet requirement!";
                                    }
                                }
                            }
                        }
                        else if (admin_choice == 10)
                        {
                            cout << " You Exitted the program";
                        }
                        else
                        {
                            cout << "Press any key to continue!";
                            getch();
                        }
                    }
                }
                else if (choice == 2)
                {
                    system("cls");
                    //==========  ====Employee Interface===  ==============
                    cout << "---------------   ---Employee Menu---   ----------------";
                    cout << endl;
                    cout << "1. view My Profile";
                    cout << "2. Update my profile";
                    cout << "3. View Salary ";
                    cout << "4. Increment Record";
                    cout << "5. View Meetings";
                    cout << endl;
                    int n;
                    cout << "Enter your choice: ";
                    cin >> n;
                    cout << endl;
                    if (choice == 1)
                    {
                        //======== ===View Your Profile=== ==================
                        cout << "========= ==My Profile== =====================";
                        int id;
                        cout << "Enter your Employee ID: ";
                        cin >> id;

                        bool found = false;

                        for (int i = 0; i < current_employee; i++)
                        {
                            if (employee_ID[i] == id)
                            {
                                cout << "Name: " << employee_name[i] << endl;
                                cout << "Age: " << employee_age[i] << endl;
                                cout << "Salary: " << employee_salary[i] << endl;
                                cout << "ID: " << employee_ID[i] << endl;
                                cout << "Address: " << employee_address[i] << endl;

                                found = true;
                                break;
                            }
                        }

                        if (!found)
                        {
                            cout << "Employee not found!" << endl;
                        }
                        cout << "===============================================";
                    }
                    else if (choice == 2)
                    {
                        //=============== =====Update My Profile==== ===================
                        cout << "====== ====Updation Of Profile==== ======================";
                        cout << "Enter your Employee ID: ";
                        int id,age;
                        cin >> id;
                        string address;
                        bool found = false;

                        for (int i = 0; i < current_employee; i++)
                        {
                            if (employee_ID[i] == id)
                            {
                                found = true;

                                cout << "=========Your Current Record========";
                                cout<<endl;
                                cout << "Name: " << employee_name[i] << endl;
                                cout << "Age: " << employee_age[i] << endl;
                                cout << "Address: " << employee_address[i] << endl;

                                cout<<"======== ===Updated Record=== =========";
                                cout << "Enter new address: "<<endl;
                                cin >> address;

                                cout << "Enter new age: ";
                                cin >> age;
                                employee_age[i]=age;
                                employee_address[i]=address;

                                cout << "Record Updated Successfully!";
                                cout <<  endl;
                                break;
                                

                            }
                        }

                        if (found == false)
                        {
                            cout << "Employee not found!";
                        }
                        cout<<"========================================================";
                    }
                    else if(choice==3){
                     //===========    ===View Salary===   =============================
                     cout<<"=========== ===View Salary===  ========================";
                     int id;
                     cout<<"Enter your Employee Id:";
                     cin>> id;
                     bool found=false;
                     
                     for(int i=0;i<current_employee;i++){
                        if(employee_ID[i]==id){

                            cout<<"You can view your Salary:";
                            cout<<endl;
                            for(int i=0;i<current_employee;i++){
                                  cout<<employee_salary[i];
                            }
                        }
                        else{
                            cout<<"Incorrect ID!";
                        }
                     }
                    }
                }
            }
        }
    }
}
