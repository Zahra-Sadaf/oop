using System;

class Employee
{
    public string name;
    public int id;
    public float salary;
    public int age;
    public string address;
    public int meetingTime;
    public int leaves;

    // Constructor
    public Employee(string name, int id, float salary, int age, string address, int meetingTime, int leaves)
    {
        this.name = name;
        this.id = id;
        this.salary = salary;
        this.age = age;
        this.address = address;
        this.meetingTime = meetingTime;
        this.leaves = leaves;
    }
}

class Applicant
{
    public string name;
    public int age;
    public float expectedSalary;
    public int experience;

    // Constructor
    public Applicant(string name, int age, float expectedSalary, int experience)
    {
        this.name = name;
        this.age = age;
        this.expectedSalary = expectedSalary;
        this.experience = experience;
    }
}

class Program
{
    const int totalEmployees = 550;
    static int currentEmployees = 10;

    static Employee[] employees = new Employee[totalEmployees];

    static void Main()
    {
        // Initial employee data
        employees[0] = new Employee("ali", 101, 60000, 25, "lahore", 2, 15);
        employees[1] = new Employee("zara", 102, 50000, 56, "Munro", 4, 8);
        employees[2] = new Employee("faiza", 103, 70000, 45, "Islamabad", 6, 9);
        employees[3] = new Employee("nisa", 104, 56000, 32, "Karachi", 8, 5);
        employees[4] = new Employee("shayaan", 105, 90000, 23, "Multan", 9, 3);
        employees[5] = new Employee("ayaan", 106, 45000, 34, "Mianwali", 3, 0);
        employees[6] = new Employee("abdullah", 107, 78000, 35, "Gojra", 5, 2);
        employees[7] = new Employee("manal", 108, 65000, 33, "Dgkhan", 6, 3);
        employees[8] = new Employee("faria", 109, 55000, 22, "peshawar", 5, 4);
        employees[9] = new Employee("gul", 110, 78000, 40, "basti", 2, 5);

        while (true)
        {
            Console.Clear();
            showMainMenu();

            Console.Write("Enter your choice: ");
            int choice = int.Parse(Console.ReadLine());

            if (choice == 1)
            {
                Console.Clear();

                bool login = verifyAdminCredentials();

                if (login)
                {
                    handleAdminInterface();
                }
                else
                {
                    Console.WriteLine("Wrong try!");
                    Console.WriteLine("Press any key to continue...");
                    Console.ReadKey();
                }
            }
            else if (choice == 2)
            {
                handleEmployeeInterface();
            }
            else if (choice == 3)
            {
                Console.WriteLine("Exiting!");
                break;
            }
            else
            {
                Console.WriteLine("Wrong option entered!");
                Console.WriteLine("Press any key...");
                Console.ReadKey();
            }
        }
    }

    static void showMainMenu()
    {
        Console.WriteLine("------------------------------------------------------------");
        Console.WriteLine("          SOFTWARE HOUSE MANAGEMENT SYSTEM");
        Console.WriteLine("------------------------------------------------------------");
        Console.WriteLine();
        Console.WriteLine("1. Admin");
        Console.WriteLine("2. Employee");
        Console.WriteLine("3. Exit");
        Console.WriteLine();
    }

    static bool verifyAdminCredentials()
    {
        for (int i = 1; i <= 3; i++)
        {
            Console.Write("Enter the username: ");
            string username = Console.ReadLine();

            Console.Write("Enter the password: ");
            int password = int.Parse(Console.ReadLine());

            if (username == "Admin" && password == 1234)
            {
                Console.WriteLine("Admin Login successful!");
                return true;
            }
            else
            {
                Console.WriteLine("Wrong username or password!");
            }
        }

        return false;
    }

    static void handleAdminInterface()
    {
        while (true)
        {
            Console.Clear();

            Console.WriteLine("==================== Admin Interface ====================");
            Console.WriteLine("1. View all employees");
            Console.WriteLine("2. Add new employee");
            Console.WriteLine("3. Delete employee");
            Console.WriteLine("4. Update employee");
            Console.WriteLine("5. Search employee");
            Console.WriteLine("6. Give annual increment");
            Console.WriteLine("7. View job applicants");
            Console.WriteLine("8. Hire job applicants");
            Console.WriteLine("9. Sort employee records");
            Console.WriteLine("10. Exit admin interface");
            Console.WriteLine("==========================================================");

            Console.Write("Enter your choice: ");
            int option = int.Parse(Console.ReadLine());

            if (option == 1)
            {
                showAllEmployees();
            }
            else if (option == 2)
            {
                addNewEmployees();
            }
            else if (option == 3)
            {
                deleteEmployee();
            }
            else if (option == 4)
            {
                updateEmployeeInfo();
            }
            else if (option == 5)
            {
                searchEmployee();
            }
            else if (option == 6)
            {
                giveAnnualIncrement();
            }
            else if (option == 7)
            {
                viewJobApplicants();
            }
            else if (option == 8)
            {
                hireJobApplicants();
            }
            else if (option == 9)
            {
                sortingEmployeeRecord();
            }
            else if (option == 10)
            {
                Console.WriteLine("Exit the admin interface!");
                break;
            }
            else
            {
                Console.WriteLine("Invalid option!");
                Console.ReadKey();
            }
        }
    }

    static void showAllEmployees()
    {
        Console.Clear();

        Console.WriteLine("Name\tAge\tSalary\tID\tAddress");

        for (int i = 0; i < currentEmployees; i++)
        {
            if (employees[i] != null && employees[i].name != "")
            {
                Console.WriteLine(
                    employees[i].name + "\t" +
                    employees[i].age + "\t" +
                    employees[i].salary + "\t" +
                    employees[i].id + "\t" +
                    employees[i].address
                );
            }
        }

        Console.WriteLine();
        Console.WriteLine("Press any key to continue!");
        Console.ReadKey();
    }

    static void addNewEmployees()
    {
        Console.Clear();

        Console.Write("Enter the number of employees you want to add: ");
        int number = int.Parse(Console.ReadLine());

        for (int i = 0; i < number; i++)
        {
            if (currentEmployees < totalEmployees)
            {
                Console.Write("Name: ");
                string name = Console.ReadLine();

                Console.Write("Age: ");
                int age = int.Parse(Console.ReadLine());

                Console.Write("Address: ");
                string address = Console.ReadLine();

                Console.Write("ID: ");
                int id = int.Parse(Console.ReadLine());

                Console.Write("Salary: ");
                float salary = float.Parse(Console.ReadLine());

                Console.Write("Meeting time: ");
                int meetingTime = int.Parse(Console.ReadLine());

                employees[currentEmployees] =
                    new Employee(name, id, salary, age, address, meetingTime, 0);

                currentEmployees++;

                Console.WriteLine("Employee added successfully!");
            }
            else
            {
                Console.WriteLine("Employee cannot be added!");
                break;
            }
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void deleteEmployee()
    {
        Console.Clear();

        Console.Write("Enter employee name to delete: ");
        string name = Console.ReadLine();

        int index = -1;

        for (int i = 0; i < currentEmployees; i++)
        {
            if (employees[i] != null && employees[i].name == name)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            employees[index] = null;
            Console.WriteLine("Record has been deleted!");
        }
        else
        {
            Console.WriteLine("No record found.");
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void updateEmployeeInfo()
    {
        Console.Clear();

        Console.Write("Enter employee name to update: ");
        string oldName = Console.ReadLine();

        int index = -1;

        for (int i = 0; i < currentEmployees; i++)
        {
            if (employees[i] != null && employees[i].name == oldName)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            Console.WriteLine("--- OLD RECORD ---");
            Console.WriteLine("Name: " + employees[index].name);
            Console.WriteLine("Age: " + employees[index].age);
            Console.WriteLine("Salary: " + employees[index].salary);
            Console.WriteLine("Address: " + employees[index].address);
            Console.WriteLine("ID: " + employees[index].id);

            Console.WriteLine();
            Console.WriteLine("--- ENTER NEW DATA ---");

            Console.Write("Enter name: ");
            string name = Console.ReadLine();

            Console.Write("Enter address: ");
            string address = Console.ReadLine();

            Console.Write("Enter ID: ");
            int id = int.Parse(Console.ReadLine());

            Console.Write("Enter age: ");
            int age = int.Parse(Console.ReadLine());

            Console.Write("Enter salary: ");
            float salary = float.Parse(Console.ReadLine());

            employees[index].name = name;
            employees[index].address = address;
            employees[index].id = id;
            employees[index].age = age;
            employees[index].salary = salary;

            Console.WriteLine("Record updated successfully!");
        }
        else
        {
            Console.WriteLine("Employee not found!");
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void searchEmployee()
    {
        Console.Clear();

        Console.Write("Enter name to search: ");
        string name = Console.ReadLine();

        int index = -1;

        for (int i = 0; i < currentEmployees; i++)
        {
            if (employees[i] != null && employees[i].name == name)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            Console.WriteLine("Name: " + employees[index].name);
            Console.WriteLine("Age: " + employees[index].age);
            Console.WriteLine("Salary: " + employees[index].salary);
            Console.WriteLine("ID: " + employees[index].id);
            Console.WriteLine("Address: " + employees[index].address);
            Console.WriteLine("Meeting hours: " + employees[index].meetingTime);
        }
        else
        {
            Console.WriteLine("No employee found.");
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void giveAnnualIncrement()
    {
        Console.Clear();

        Console.Write("Enter employee name for increment: ");
        string name = Console.ReadLine();

        int index = -1;

        for (int i = 0; i < currentEmployees; i++)
        {
            if (employees[i] != null && employees[i].name == name)
            {
                index = i;
                break;
            }
        }

        if (index != -1)
        {
            float percent = 10;
            float oldSalary = employees[index].salary;
            float increment = oldSalary * percent / 100;

            employees[index].salary = oldSalary + increment;

            Console.WriteLine("Old Salary: " + oldSalary);
            Console.WriteLine("Salary after increment: " + employees[index].salary);
        }
        else
        {
            Console.WriteLine("Employee not found!");
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void viewJobApplicants()
    {
        Console.Clear();

        Console.Write("Enter number of applicants: ");
        int count = int.Parse(Console.ReadLine());

        Applicant[] applicants = new Applicant[count];

        for (int i = 0; i < count; i++)
        {
            Console.Write("Name: ");
            string name = Console.ReadLine();

            Console.Write("Age: ");
            int age = int.Parse(Console.ReadLine());

            Console.Write("Expected salary: ");
            float salary = float.Parse(Console.ReadLine());

            Console.Write("Experience in years: ");
            int experience = int.Parse(Console.ReadLine());

            applicants[i] = new Applicant(name, age, salary, experience);
        }

        Console.WriteLine();
        Console.WriteLine("--- APPLICANTS ---");

        for (int i = 0; i < count; i++)
        {
            Console.WriteLine("Name: " + applicants[i].name);
            Console.WriteLine("Age: " + applicants[i].age);
            Console.WriteLine("Expected Salary: " + applicants[i].expectedSalary);
            Console.WriteLine("Experience: " + applicants[i].experience);
            Console.WriteLine();
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void hireJobApplicants()
    {
        Console.Clear();

        Console.Write("Enter number of applicants you want to review: ");
        int count = int.Parse(Console.ReadLine());

        for (int i = 0; i < count; i++)
        {
            Console.Write("Name: ");
            string name = Console.ReadLine();

            Console.Write("Enter your experience: ");
            int experience = int.Parse(Console.ReadLine());

            if (experience > 5)
            {
                Console.WriteLine("Congratulations! You are hired!");
            }
            else
            {
                Console.WriteLine("You need more experience!");
            }
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static int findEmployeeById(int id)
    {
        for (int i = 0; i < currentEmployees; i++)
        {
            if (employees[i] != null && employees[i].id == id)
            {
                return i;
            }
        }

        return -1;
    }

    static void viewMyProfile()
    {
        Console.Clear();

        Console.WriteLine("--- MY PROFILE ---");

        Console.Write("Enter your Employee ID: ");
        int id = int.Parse(Console.ReadLine());

        int index = findEmployeeById(id);

        if (index != -1)
        {
            Console.WriteLine("--- MY DETAILS ---");
            Console.WriteLine("Name: " + employees[index].name);
            Console.WriteLine("Age: " + employees[index].age);
            Console.WriteLine("Salary: " + employees[index].salary);
            Console.WriteLine("ID: " + employees[index].id);
            Console.WriteLine("Address: " + employees[index].address);
            Console.WriteLine("Meeting hours: " + employees[index].meetingTime);
        }
        else
        {
            Console.WriteLine("Employee ID not found!");
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void updateMyProfile()
    {
        Console.Clear();

        Console.WriteLine("--- UPDATE MY PROFILE ---");

        Console.Write("Enter your Employee ID: ");
        int id = int.Parse(Console.ReadLine());

        int index = findEmployeeById(id);

        if (index != -1)
        {
            Console.WriteLine("Name: " + employees[index].name);
            Console.WriteLine("Age: " + employees[index].age);
            Console.WriteLine("Address: " + employees[index].address);

            Console.Write("Updated address: ");
            string address = Console.ReadLine();

            Console.Write("Updated age: ");
            int age = int.Parse(Console.ReadLine());

            employees[index].age = age;
            employees[index].address = address;

            Console.WriteLine("Profile updated!");
        }
        else
        {
            Console.WriteLine("Employee ID not found!");
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void viewMySalary()
    {
        Console.Clear();

        Console.Write("Enter your Employee ID: ");
        int id = int.Parse(Console.ReadLine());

        int index = findEmployeeById(id);

        if (index != -1)
        {
            Console.WriteLine("Current salary is: " + employees[index].salary);
        }
        else
        {
            Console.WriteLine("Wrong ID!");
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void checkMyIncrement()
    {
        Console.Clear();

        Console.WriteLine("--- MY INCREMENT ---");

        Console.Write("Enter your Employee ID: ");
        int id = int.Parse(Console.ReadLine());

        int index = findEmployeeById(id);

        if (index != -1)
        {
            float percent = 10;
            float oldSalary = employees[index].salary;
            float increment = oldSalary * percent / 100;

            employees[index].salary = oldSalary + increment;

            Console.WriteLine("Old Salary: " + oldSalary);
            Console.WriteLine("Salary after increment: " + employees[index].salary);
            Console.WriteLine("Annual increment applied!");
        }
        else
        {
            Console.WriteLine("Employee not found!");
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void viewMeetingSchedule()
    {
        Console.Clear();

        Console.WriteLine("--- MEETING SCHEDULE ---");

        Console.Write("Enter your Employee ID: ");
        int id = int.Parse(Console.ReadLine());

        int index = findEmployeeById(id);

        if (index != -1)
        {
            Console.WriteLine("Employee: " + employees[index].name);
            Console.WriteLine("Your meeting time: " + employees[index].meetingTime);
        }
        else
        {
            Console.WriteLine("Wrong ID!");
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void applyForLeave()
    {
        Console.Clear();

        Console.Write("Enter your Employee ID: ");
        int id = int.Parse(Console.ReadLine());

        int index = findEmployeeById(id);

        if (index != -1)
        {
            Console.WriteLine("Employee Name: " + employees[index].name);
            Console.WriteLine("Remaining Leaves: " + employees[index].leaves);

            Console.Write("Enter the number of days for leave: ");
            int leave = int.Parse(Console.ReadLine());

            if (leave <= 0)
            {
                Console.WriteLine("Invalid number of days!");
            }
            else if (leave <= employees[index].leaves)
            {
                employees[index].leaves = employees[index].leaves - leave;

                Console.WriteLine("Your leave has been approved!");
                Console.WriteLine("Leave days: " + leave);
                Console.WriteLine("Remaining leaves: " + employees[index].leaves);
            }
            else
            {
                Console.WriteLine("Leave not available!");
            }
        }
        else
        {
            Console.WriteLine("Employee ID not found!");
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void sortingEmployeeRecord()
    {
        Console.Clear();

        // Simple bubble sort
        for (int i = 0; i < currentEmployees - 1; i++)
        {
            for (int j = 0; j < currentEmployees - 1 - i; j++)
            {
                if (employees[j] != null && employees[j + 1] != null &&
                    employees[j].name.CompareTo(employees[j + 1].name) > 0)
                {
                    Employee temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }

        Console.WriteLine("Sorted Data of Employees:");

        for (int i = 0; i < currentEmployees; i++)
        {
            if (employees[i] != null)
            {
                Console.WriteLine(
                    employees[i].name + "\t" +
                    employees[i].age + "\t" +
                    employees[i].salary + "\t" +
                    employees[i].id + "\t" +
                    employees[i].address
                );
            }
        }

        Console.WriteLine("Press any key to continue...");
        Console.ReadKey();
    }

    static void handleEmployeeInterface()
    {
        while (true)
        {
            Console.Clear();

            Console.WriteLine("==================== Employee Interface ====================");
            Console.WriteLine("1. View my profile");
            Console.WriteLine("2. Update my profile");
            Console.WriteLine("3. View my salary");
            Console.WriteLine("4. Check my increment");
            Console.WriteLine("5. View meeting schedule");
            Console.WriteLine("6. Apply for leave");
            Console.WriteLine("7. Exit");
            Console.WriteLine("============================================================");

            Console.Write("Enter your choice: ");
            int option = int.Parse(Console.ReadLine());

            if (option == 1)
            {
                viewMyProfile();
            }
            else if (option == 2)
            {
                updateMyProfile();
            }
            else if (option == 3)
            {
                viewMySalary();
            }
            else if (option == 4)
            {
                checkMyIncrement();
            }
            else if (option == 5)
            {
                viewMeetingSchedule();
            }
            else if (option == 6)
            {
                applyForLeave();
            }
            else if (option == 7)
            {
                Console.WriteLine("Leaving employee interface...");
                break;
            }
            else
            {
                Console.WriteLine("Invalid option!");
                Console.ReadKey();
            }
        }
    }
}
