#include<iostream>
#include<string>

using namespace std;

class Webpage {
    public:
        int index;
        string name;
        string url;
        string content;

        Webpage(int i, string n, string u, string c) {
            index = i;
            name = n;
            url = u;
            content = c;

            cout << endl<< index << ". " << name << endl;

            for (int i = 0; i <= 40; i++) {
                cout << "-";
            }
            cout << endl;
        }

        void printInfo() {
            cout <<endl << "Name: " << name << endl;
            cout <<endl << "URL: " << url << endl;
            cout <<endl<< "Content: " << content << endl;
            for (int i = 0; i <= 40; i++) {
                cout << "-";
            }
            cout << endl;
        }
};

int binarySearch(int* arr, int len, int index);

int main() {

	cout << "Available Webpages:" << endl;
    // Create webpage objects
    Webpage w1(0, "Google", "https://google.com", "Your Destination for all the web content");
    Webpage w2(1, "Facebook", "https://facebook.com", "Connect with your friends online");
    Webpage w3(2, "YouTube", "https://youtube.com", "Share videos with everyone");

    // Array of pointers to Webpage objects
    Webpage* pages[] = { &w1, &w2, &w3 };

    // Array of indices for binary search
    int arr[] = { w1.index, w2.index, w3.index };
    int len = sizeof(arr) / sizeof(arr[0]);

    string arr_names[] = {w1.name, w2.name, w3.name};
    int names_len = sizeof(arr_names)/sizeof(arr_names[0]);

    int index;

    int choice;

    cout<<"Choose: 1) Search by Index 2) Search by Name "<<endl;
    cin>>choice;

    if(choice == 1){
        while (true) {
            cout << "Enter the index to visit the website: " << endl;
            cin >> index;

            // Check if the input is valid
            if (cin.fail()) {
                // Clear the error flag
                cin.clear();
                // Ignore invalid input in the buffer
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a valid integer." << endl;
            } else {
                // Valid input received, exit the loop
                break;
            }
        }

        int pos = binarySearch(arr, len, index);

        if (pos != -1) {
            // Print info of the webpage found
            pages[pos]->printInfo();
        } else {
            cout << "Webpage not found!" << endl;
        }
    }
    else if(choice == 2){
        // code for linear search
        string name;
        cout << "Enter the name of the website: ";
        cin.ignore(); // To clear the buffer
        getline(cin, name); // To allow spaces in the name

        // Linear search logic
        bool found = false;
        for (int i = 0; i < len; i++) {
            if (pages[i]->name == name) {
                pages[i]->printInfo();
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "Webpage not found!" << endl;
        }
    }
    else{
        cout<<"Wrong Operator!"<<endl;
    }

    return 0;
}

int binarySearch(int* arr, int len, int index) {
    int l = 0;
    int r = len - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == index) {
            return mid; // return the position of the found index
        }
        else if (arr[mid] > index) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return -1; // if the index is not found
}
