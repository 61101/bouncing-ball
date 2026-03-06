// ### Bouncing Ball Animation ###

// --- Libraries ---
#include <iostream>
using namespace std;

#include <cmath> // Needed for sin function
#include <thread> // Needed for adding delay
#include <chrono> // Needed for adding delay

// --- Macros ---
#define location(x, y) "\033[" << (y + 25) << ";" << (x + 25) << "H" // Macro for changing cursor's position (add 25 to prevent negative values)
#define wait(ms) this_thread::sleep_for(chrono::milliseconds(ms)) // Macro for adding delay
#define cls cout << "\033[2J" // Macro for clearing the screen

// --- Main Function ---
int main() {
    
    float i = 0;
    int x, y;
    
    do {
        
        // Sin returns a value between -1 and 1. Multiplying inside parentheses controls rate of change. Multiplying outside parentheses controls magnitude.
        x = sin(i) * 20;
        y = sin(i * 4) * 10;
        
        // Normally, cout only prints when the program finishes or when "endl" is used; flush tells it to print right away. Without flush, the output will be delayed.
        cout << location(x, y) << "*" << flush;
        wait(50);
        cls;
        i += 0.1;
        
    } while (true);
    
}
