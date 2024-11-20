#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class Stack {
private:
    string arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string page) {
        if (top >= MAX - 1) { // Fix the boundary condition
            cout << "Stack is full" << endl;
        } else {
            top++;
            arr[top] = page;
        }
    }

    string pop() {
        if (top < 0) {
            return ""; // Return empty string if stack is empty
        } else {
            string poppedPage = arr[top];
            top--;
            return poppedPage;
        }
    }

    string peek() {
        if (top < 0) {
            return ""; // Return empty string if stack is empty
        } else {
            return arr[top];
        }
    }

    bool isEmpty() const {
        return (top == -1);
    }

    void clear() {
        top = -1;
    }
};

class BrowsingHistory {
private:
    Stack history;      // Stack to maintain history
    string currentPage; // Current page as a string

public:
    // diff betwn isEmpty and empty??
    // why const?? 
    void visitPage(string page) {
        if (!currentPage.empty()) { 
            history.push(currentPage);
        }
        currentPage = page; 
        cout << "Visited page: " << currentPage << endl;
    }

    void goBack() {
        if (history.isEmpty()) {
            cout << "No previous page to navigate back to." << endl;
        } else {
            currentPage = history.pop(); 
            cout << "Navigated back to: " << currentPage << endl;
        }
    }

    void viewCurrentPage() const {
        if (currentPage.empty()) {
            cout << "No page is currently open." << endl;
        } else {
            cout << "Current page: " << currentPage << endl;
        }
    }

    void checkHistoryEmpty() const {
        if (history.isEmpty()) {
            cout << "The browsing history is empty." << endl;
        } else {
            cout << "There are pages in the browsing history." << endl;
        }
    }

    void clearHistory() {
        history.clear();        
        currentPage.clear();    
        cout << "Browsing history has been cleared." << endl;
    }
};
