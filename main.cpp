#include<iostream>
#include<string>

using namespace std;

class Webpage {
    public:
        int index;
        string name;
        string content;

        Webpage(int i, string n, string c) {
            index = i;
            name = n;
            content = c;

            cout << endl<< index << ". " << name << endl;

            for (int i = 0; i <= 40; i++) {
                cout << "-";
            }
            cout << endl;
        }

        void printInfo() {
            cout <<endl << "Name: " << name << endl;
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
    Webpage w1(0, "Google", "Your Destination for all the web content");
    Webpage w2(1, "Facebook", "Connect with your friends online");
    Webpage w3(2, "YouTube", "Share videos with everyone");

    // Array of pointers to Webpage objects
    Webpage* pages[] = { &w1, &w2, &w3 };

    // Array of indices for binary search
    int arr[] = { w1.index, w2.index, w3.index };
    int len = sizeof(arr) / sizeof(arr[0]);

    int index;

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
