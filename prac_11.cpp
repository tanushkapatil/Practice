#include <iostream>
using namespace std ;

#define size 10 

class Employee {
    int emp_id ;
    string emp_name ;
    long emp_salary ;
public :
    Employee() {
        emp_id = -1 ;
        emp_name = " " ;
        emp_salary = 0 ;
    }

    void read() {
        cout << "Enter employee ID: ";
        cin >> emp_id;
        cout << "Enter employee name: ";
        cin >> emp_name;
        cout << "Enter employee salary: ";
        cin >> emp_salary;
    }

    void display() {
        if (emp_id != -1) { // If employee ID is valid
            cout << emp_id << "\t" << emp_name << "\t" << emp_salary << endl;
        } else {
            cout << "-\t-\t-" << endl; // If employee slot is empty
        }
    }

    void clear () {
        emp_id = -1 ;
        emp_name = " " ;
        emp_salary = 0 ;
    }

    int getID() {
        return emp_id;
    }
};
class HashTable {
    Employee e[size] ;
    int flag[size] ;

public :
    HashTable() {
        for (int i = 0; i < size; i++) {
            flag[i] = 0; // Initialize all slots as empty
        }
    }
    void insertID();
    void deleteID();
    void displayTable();
    int hashFunction(int emp_id);
};
