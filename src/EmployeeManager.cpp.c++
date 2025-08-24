#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
    int id;          // Unique identifier for the employee
    string name;     // Name of the employee
    string position; // Position of the employee
    double salary;   // Salary of the employee

public:
    // Default and parameterized constructor
    Employee(int id = 0, string name = "", string position = "", double salary = 0.0)
        : id(id), name(name), position(position), salary(salary) {}

    // Setters
    void setId(int id) { this->id = id; }
    void setName(const string &name) { this->name = name; }
    void setPosition(const string &position) { this->position = position; }
    void setSalary(double salary) { this->salary = salary; }

    // Getters
    int getId() { return id; }
    string getName() { return name; }
    string getPosition() { return position; }
    double getSalary() { return salary; }

    // Display employee details
    void display() const
    {
        cout << "ID: " << id << "\nName: " << name
             << "\nPosition: " << position << "\nSalary: " << salary << endl;
    }
};
//===============================================================================
const int MAX_EMPLOYEES = 100; // Define the maximum number of employees

class EmployeeManagement
{
private:
    Employee employees[MAX_EMPLOYEES]; // Array to store employee records
    int count;                         // Number of employees currently in the array

public:
    // Constructor
    EmployeeManagement() : count(0)
    {
    }
    // Add an employee
    void addEmployee(const Employee &emp)
    {
        if (count < MAX_EMPLOYEES)
        {
            employees[count++] = emp; // Add employee to the array and increment count
            cout << "Employee added successfully." << endl;
        }
        else
        {
            cout << "Cannot add more employees. Array is full." << endl;
        }
    }

    // Display all employees
    void displayEmployees() const
    {
        if (count == 0)
        {
            cout << "No employees to display." << endl;
            return;
        }
        for (int i = 0; i < count; ++i)
        {
            employees[i].display(); // Call display method of each employee
            cout << "-------------------" << endl;
        }
    }

    // Update an employee by ID
    void updateEmployee(int id)
    {
        for (int i = 0; i < count; ++i)
        {
            if (employees[i].getId() == id)
            {
                string name, position;
                double salary;

                cout << "Updating employee with ID " << id << endl;
                cout << "Enter new Name: ";
                cin.ignore(); // Ignore leftover newline character
                getline(cin, name);
                cout << "Enter new Position: ";
                getline(cin, position);
                cout << "Enter new Salary: ";
                cin >> salary;

                // Update employee details
                employees[i].setName(name);
                employees[i].setPosition(position);
                employees[i].setSalary(salary);

                cout << "Employee updated successfully." << endl;
                return;
            }
        }
        cout << "Employee with ID " << id << " not found." << endl;
    }

    // Delete an employee by ID
    void deleteEmployee(int id)
    {
        bool found = false;
        for (int i = 0; i < count; ++i)
        {
            if (employees[i].getId() == id)
            {
                found = true;
                // Shift all employees after the removed one to the left
                for (int j = i; j < count - 1; ++j)
                {
                    employees[j] = employees[j + 1];
                }
                --count; // Decrement the count
                cout << "Employee with ID " << id << " has been deleted." << endl;
                return;
            }
        }
        if (!found)
        {
            cout << "Employee with ID " << id << " not found." << endl;
        }
    }
};
//========================================================================================
int main()
{
    EmployeeManagement empMgmt;
    int choice;
    bool running = true;

    while (running)
    {
        cout << "1. Add Employee" << endl;
        cout << "2. Display Employees" << endl;
        cout << "3. Update Employee" << endl;
        cout << "4. Delete Employee" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int id;
            string name, position;
            double salary;

            cout << "Enter ID: ";
            cin >> id;
            cin.ignore(); // Ignore leftover newline character
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Position: ";
            getline(cin, position);
            cout << "Enter Salary: ";
            cin >> salary;

            Employee emp(id, name, position, salary);
            empMgmt.addEmployee(emp);
            break;
        }
        case 2:
            empMgmt.displayEmployees();
            break;
        case 3:
        {
            int id;
            cout << "Enter ID of employee to update: ";
            cin >> id;
            empMgmt.updateEmployee(id);
            break;
        }
        case 4:
        {
            int id;
            cout << "Enter ID of employee to delete: ";
            cin >> id;
            empMgmt.deleteEmployee(id);
            break;
        }
        case 5:
            running = false;
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
//============================================================================