#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    string name;
    cout << "Enter student name: ";
    getline(cin, name);
    vector<string> excuses = {
        "{name} started the assignment on time, but the laptop suddenly began updating.",
        "After waiting for hours, {name} finally resumed work, but the Wi-Fi stopped working.",
        "{name} tried using mobile data, but it was extremely slow.",
        "Just when the assignment was almost complete, {name}'s system crashed.",
        "{name} restarted the system, only to find the file was corrupted.",
        "While rewriting the assignment, there was a sudden power cut.",
        "{name} waited for electricity, but it took too long to come back.",
        "{name} then tried to continue, but the keyboard stopped working properly.",
        "Frustrated, {name} attempted to finish it on phone, but formatting issues occurred.",
        "In the end, {name} could not complete the assignment on time."
    };
    srand(time(0));
    // Decide how many excuses to show (2 to 4)
    int count = rand() % 3 + 2;
    cout << "\nGenerated Excuse Story:\n";
    for (int i = 0; i < count; i++) {
        int index = rand() % excuses.size();
        string line = excuses[index];
        // Replace {name}
        size_t pos = line.find("{name}");
        while (pos != string::npos) {
            line.replace(pos, 6, name);
            pos = line.find("{name}");
        }
        cout << "- " << line << endl;
    }
    return 0;
}