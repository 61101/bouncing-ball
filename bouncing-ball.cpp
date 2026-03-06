// ### Bouncing Ball Animation ###

// --- Libraries ---
#include <iostream>
using namespace std;

#include <cmath> // Needed for mathematical functions (sin and abs)
#include <thread> // Needed for wait macro
#include <chrono> // Needed for wait macro

// --- Macros ---
#define location(x, y) "\033[" << y << ";" << x << "H" // Used for changing cursor's position
#define wait(ms) this_thread::sleep_for(chrono::milliseconds(ms)) // Used for adding delay
#define cls cout << "\033[2J" // Used for clearing the screen

// --- Main Function ---
int main() {
    
    float i = 0;
    int x, y;
    
    while (true) {
        
        // Sin returns a number between -1 and 1.
        // The abs function is used to get the absolute value of sin (because the cursor's location can't be negative).
        // Multiplying inside parentheses controls rate of change.
        // Multiplying outside parentheses controls magnitude.
        x = abs(sin(i)) * 20;
        y = abs(sin(i * 4)) * 10;
        
        // Normally, cout only prints when the program finishes or when "endl" is used; flush tells it to print right away.
        // Without flush, the output will be delayed until the program finishes (which will never happen in this case) or the character limit is exceeded.
        cout << location(x, y) << '*' << flush;
        wait(50);
        cls;
        
        // i slowly increases to create a smooth sine curve.
        i += 0.1;
        
    }
    
}
