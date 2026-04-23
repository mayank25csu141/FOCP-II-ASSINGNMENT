#include <iostream>
#include <vector>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;
// Function to replace {name} with actual user name
string generateRoast(string temp, string name) {
    size_t pos = temp.find("{name}");
    while (pos != string::npos) {
        temp.replace(pos, 6, name); // 6 = length of "{name}"
        pos = temp.find("{name}");
    }
    return temp;
}
int main() {
    string name;  
    cout << "Enter your name: ";
    getline(cin, name);
    // Roast templates
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have a gold medal.",
        "{name}'s debugging style is basically staring at the screen until the bug gets embarrassed and leaves.",
        "{name} doesn't write bugs, they create undocumented features.",
        "{name}'s code has more twists than a Bollywood movie.",
        "{name} tried to fix a bug and ended up creating a sequel.",
        "{name}'s code runs... away from responsibility.",
        "{name} uses comments like: 'I don't know why this works, but it does.'",
        "{name}'s logic is like WiFi — sometimes connected, mostly not.",
        "{name} compiles code with hope and runs it with fear."
    };
    // Seed random number generator
    srand(time(0));
    // Pick random roast
    int index = rand() % roasts.size();
    // Generate final roast
    string finalRoast = generateRoast(roasts[index], name);
    // Output
    cout << "\n🔥 Your Roast:\n";
    cout << finalRoast << endl;
    return 0;
}