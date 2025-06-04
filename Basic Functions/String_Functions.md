                                                    * Strings In C++ *
When working with strings in C++, you'll need the <string> header to access the full functionality of the std::string class. While basic operations work without explicit includes, it's good practice to always include the header.
```
cpp
#include <string>
Basic String Properties and Access
Understanding string length and accessing individual characters forms the foundation of most string operations. The length() and size() methods are interchangeable, both returning the number of characters.
cppstring s = "hello world";
cout << s.length() << endl;     // 11
cout << s.size() << endl;       // 11 (identical to length)

// Character access
cout << s[0] << endl;           // 'h'
cout << s[s.length()-1] << endl; // 'd'
cout << s.at(5) << endl;        // ' ' (safer, throws exception if out of bounds)

// Check if empty
if (s.empty()) {
    cout << "String is empty" << endl;
}
```

String Modification and Building
Building and modifying strings efficiently is crucial for many algorithms. The += operator and push_back() method are your primary tools for string construction.
```
cpp
string result = "";
result += "Hello";              // Append string
result += ' ';                  // Append character
result += "World";              

string name = "Alice";
result.push_back('!');          // Add single character
result.append(name);            // Append another string

cout << result << endl;         // "Hello World!Alice"

// Clear and modify
result.clear();                 // Empty the string
result = "New content";         // Direct assignment
Substring Operations
Extracting portions of strings is essential for parsing and text processing. The substr() method provides flexible substring extraction with optional length parameters.
cppstring text = "programming";

// substr(start_position, length)
cout << text.substr(0, 4) << endl;    // "prog"
cout << text.substr(3, 4) << endl;    // "gram"
cout << text.substr(7) << endl;       // "ming" (from position 7 to end)

// Common pattern: check prefixes/suffixes
string filename = "document.txt";
if (filename.substr(filename.length() - 4) == ".txt") {
    cout << "Text file detected" << endl;
}
```
Search and Find Operations
Finding characters or substrings within strings returns the position of the first occurrence, or string::npos if not found.
```
cpp
string sentence = "the quick brown fox";

// Find character
size_t pos = sentence.find('q');
if (pos != string::npos) {
    cout << "Found 'q' at position: " << pos << endl;  // 4
}

// Find substring
pos = sentence.find("brown");
cout << "Found 'brown' at: " << pos << endl;          // 10

// Find from specific position
pos = sentence.find('o', 12);  // Start searching from position 12
cout << "Found 'o' after position 12: " << pos << endl;

// Find last occurrence
pos = sentence.rfind('o');
cout << "Last 'o' at position: " << pos << endl;
String Replacement and Insertion
Modifying strings in-place can be more efficient than creating new strings for certain operations.
cppstring text = "Hello World";

// Replace portion of string
text.replace(6, 5, "C++");     // Replace 5 chars starting at position 6
cout << text << endl;          // "Hello C++"

// Insert text at position
text.insert(5, " Modern");     // Insert at position 5
cout << text << endl;          // "Hello Modern C++"

// Erase characters
text.erase(5, 7);             // Remove 7 chars starting at position 5
cout << text << endl;          // "Hello C++"
String Comparison and Ordering
String comparisons in C++ follow lexicographic ordering, making them perfect for sorting and alphabetical operations.
cppstring a = "apple";
string b = "banana";
string c = "apple";

// Direct comparison operators
cout << (a == c) << endl;      // 1 (true)
cout << (a < b) << endl;       // 1 (true) - lexicographic order
cout << (a > b) << endl;       // 0 (false)

// Compare method returns int
int result = a.compare(b);
if (result < 0) {
    cout << "a comes before b" << endl;
} else if (result > 0) {
    cout << "a comes after b" << endl;
} else {
    cout << "strings are equal" << endl;
}
```
Type Conversion Functions
Converting between strings and numbers is frequent in competitive programming, especially when processing input.
```
cpp
// String to number conversion
string numStr = "12345";
int num = stoi(numStr);           // String to int
long longNum = stol(numStr);      // String to long
double decimal = stod("3.14159"); // String to double

cout << num + 1 << endl;          // 12346

// Number to string conversion
int value = 42;
string str = to_string(value);    // "42"
double pi = 3.14159;
string piStr = to_string(pi);     // "3.141590"

cout << "Number as string: " << str << endl;
```
Case Conversion
While C++ doesn't have built-in string case conversion methods, character-level functions work effectively with loops.
```
cpp
#include <cctype>  // For character functions

string text = "Hello World";

// Convert to lowercase
for (char &c : text) {
    c = tolower(c);
}
cout << text << endl;             // "hello world"

// Convert to uppercase
for (char &c : text) {
    c = toupper(c);
}
cout << text << endl;             // "HELLO WORLD"

// Check character properties
char ch = 'A';
cout << isalpha(ch) << endl;      // 1 (is alphabetic)
cout << isdigit('5') << endl;     // 1 (is digit)
cout << islower('a') << endl;     // 1 (is lowercase)
```
This was a comprehensive list of most of the most-common string methods and their practical uses in C++, 
