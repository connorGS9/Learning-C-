C++ Math Functions: A Complete Guide
In C++, mathematical functions are provided through the <cmath> header (or sometimes <math.h>). Unlike Java where you use Math.pow(), C++ functions don't require a class prefix - you call them directly.
Essential Header
To use mathematical functions, you must include the math library:
cpp#include <cmath>
Core Mathematical Functions
Power and Root Functions
The power function pow(base, exponent) raises a number to a given power, while sqrt() computes square roots:
cpp#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Power functions
    cout << pow(2, 3) << endl;      // 8.0 (2^3)
    cout << pow(5, 2) << endl;      // 25.0 (5^2)
    cout << pow(8, 0.5) << endl;    // 2.828... (square root of 8)
    
    // Square root
    cout << sqrt(16) << endl;       // 4.0
    cout << sqrt(25) << endl;       // 5.0
    
    // Cube root
    cout << cbrt(27) << endl;       // 3.0 (cube root of 27)
    
    return 0;
}
Absolute Value Functions
The absolute value functions remove the negative sign from numbers. C++ provides different versions for different data types:
cpp#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // For floating-point numbers
    cout << abs(-5.7) << endl;      // 5.7
    cout << fabs(-3.14) << endl;    // 3.14 (explicitly for float/double)
    
    // For integers (no #include needed)
    cout << abs(-10) << endl;       // 10
    cout << abs(15) << endl;        // 15
    
    return 0;
}
Rounding Functions
C++ offers multiple rounding options depending on your needs:
cpp#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double num = 4.7;
    
    cout << ceil(num) << endl;      // 5.0 (round up)
    cout << floor(num) << endl;     // 4.0 (round down)
    cout << round(num) << endl;     // 5.0 (round to nearest)
    
    // Negative numbers
    cout << ceil(-4.3) << endl;     // -4.0 (toward positive infinity)
    cout << floor(-4.3) << endl;    // -5.0 (toward negative infinity)
    cout << round(-4.7) << endl;    // -5.0 (to nearest)
    
    return 0;
}
Trigonometric Functions
Trigonometric functions work with angles in radians:
cpp#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double angle = M_PI / 4;  // 45 degrees in radians
    
    cout << sin(angle) << endl;     // ~0.707
    cout << cos(angle) << endl;     // ~0.707  
    cout << tan(angle) << endl;     // ~1.0
    
    // Convert degrees to radians
    double degrees = 90;
    double radians = degrees * M_PI / 180;
    cout << sin(radians) << endl;   // 1.0 (sin of 90°)
    
    return 0;
}
Logarithmic Functions
Logarithmic functions are essential for many algorithms:
cpp#include <iostream>
#include <cmath>
using namespace std;

int main() {
    cout << log(2.718) << endl;     // ~1.0 (natural log, base e)
    cout << log10(100) << endl;     // 2.0 (log base 10)
    cout << log2(8) << endl;        // 3.0 (log base 2)
    
    // Exponential
    cout << exp(1) << endl;         // ~2.718 (e^1)
    
    return 0;
}
Practical Competitive Programming Example
Here's how these functions work together in a typical competitive programming scenario:
cpp#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Problem: Calculate distance between two points
    double x1 = 1, y1 = 1;
    double x2 = 4, y2 = 5;
    
    // Distance formula: sqrt((x2-x1)² + (y2-y1)²)
    double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout << "Distance: " << distance << endl;  // 5.0
    
    // Round to nearest integer
    int roundedDistance = round(distance);
    cout << "Rounded: " << roundedDistance << endl;  // 5
    
    // Check if it's a perfect square
    int sqrtDist = sqrt(distance);
    if (pow(sqrtDist, 2) == distance) {
        cout << "Perfect square!" << endl;
    }
    
    return 0;
}
Important Notes
Return Types: Most math functions return double even if you pass integers, so be prepared to cast if needed:
cppint result = (int)pow(2, 3);  // Cast to int if needed
Performance: For simple operations like squaring, direct multiplication x * x is faster than pow(x, 2).
Constants: C++ provides mathematical constants like M_PI, M_E when you include <cmath>.
These mathematical functions form the foundation for solving many competitive programming problems involving geometry, number theory, and algorithmic calculations.
