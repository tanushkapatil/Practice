#include"stack.h"

int main() {
    BrowsingHistory browser;
    int choice;
    string page;

    do {
        cout << "\n----- Browser History Menu -----\n";
        cout << "1. Visit a new page\n";
        cout << "2. Navigate back\n";
        cout << "3. View current page\n";
        cout << "4. Check if history is empty\n";
        cout << "5. Clear browsing history\n";  
        cout << "6. Exit\n";
        cout << "Enter your choice (1 to 6): ";
        cin >> choice;

        switch (choice) {
            case 1:  
                cout << "Enter the page URL or title: ";
                cin >> page;
                browser.visitPage(page);
                break;

            case 2:  
                browser.goBack();
                break;

            case 3:  
                browser.viewCurrentPage();
                break;

            case 4:  
                browser.checkHistoryEmpty();
                break;

            case 5:  
                browser.clearHistory();
                break;

            case 6:  
                cout << "Exiting the browser history management system..." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid option (1 to 6)." << endl;
        }
    } while (choice != 6);  

    return 0;
}
