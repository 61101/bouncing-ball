// ### Bouncing Ball Animation ###

// --- Libraries ---
#include <iostream>
using namespace std;

#include <cmath> // Needed for mathematical functions
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
    int xMag = 100, yMag = 30;
    
    while (true) {
        
        // Sine returns a number between -1 and 1.
        // Multiplying inside parentheses controls rate of change.
        // Multiplying outside parentheses controls magnitude.
        // Adding an offset equal to the magnitude is used to keep the number positive (because the cursor's location can't be negative).
        x = (sin(i * 1) * xMag/2) + xMag/2;
        y = (sin(i * 4) * yMag/2) + yMag/2;
        
        // Cout here prints the ball at the correct position and draws a dotted line as the floor.
        // Normally, cout only prints when the program finishes or when "endl" is used; flush tells it to print right away.
        // Without flush, the output will be delayed until the program finishes (which will never happen in this case) or the character limit is exceeded.
        cout << location(x, y) << 'O' << location(0, yMag) << string(xMag, '-') << flush;
        wait(1);
        cls;
        
        // i increases slowly to create a smooth sine curve.
        i += 0.001;
        
    }
    
}
