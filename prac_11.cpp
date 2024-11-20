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
int HashTable::hashFunction(int emp_id) {
    return emp_id%size ;
}

void HashTable::insertID() {
    Employee newEmp ;
    newEmp.read() ;
    int emp_id = newEmp.getID() ;
    int pos = hashFunction(emp_id) ;
    for(int i = 0 ; i < size ; i++) {
        pos = (pos + i) % size ;
        if(flag[pos] == 0){
            e[pos] = newEmp ;
            flag[pos] = 1 ;
            cout << "Employee inserted at position" << pos << endl ;
            return ;
        }
    }
    cout << "Hash Table is full" << endl;
}

void HashTable::deleteID() {
    int id ;
    cout << "Enter the employee id to be deleted" ;
    cin >> id ;
    int pos = hashFunction(id);
    if(id <= 0) {
        cout << "Invalid ID" ;
    }
    for(int i = 0 ; i < size ; i++) {
        pos = (pos + i) % size ;
        if (flag[pos] == 1 && e[pos].getID() == id){
            e[pos].clear() ;
            flag[pos] = 0 ;
            cout << "Employee with ID " << id << " deleted from position: " << pos << endl;
            return ;
        }
    }    
    cout << "Not Found" ;
}

void HashTable::displayTable() {
    cout << "Position\tID\tName\t\tSalary" << endl;
    for (int i = 0; i < size; i++) {
        cout << i << "\t\t";
        if (flag[i] == 1) { 
            e[i].display(); 
        } else {
            cout << "-\t-\t\t-" << endl; 
        }
    }
}
