#include <stdio.h>

// Funktionen deklarieren
int simple_assignment(int a, int b);

int nested_expressions(int x, int y);

int rotation(int a, int b, int c);

int while_loop(int n);

int for_loop(int n);

int ones_place(int n);

int tens_place(int n);

int main() { // Main input
    simple_assignment(2, 3);
    nested_expressions(2, 1);
    rotation(0, 3, 7);
    while_loop(4);
    for_loop(4);
    ones_place(543210);
    tens_place(1234);
    return 0;
}

// Initialisierung von Funktionen
// Aufgabe 1a
int simple_assignment(int a, int b) {
    int result = 0;
    result = a + b;
    printf("First task '1a', result is: %d\n", result);
    return result;
}


// Aufgabe 1b
int nested_expressions(int x, int y) {
    int result = 0;
    result = (x - y) * (x - y);
    printf("First task '1b', result is: %d\n", result);
    return result;
}

// Aufgabe 2a
int rotation(int a, int b, int c) {
    //  a=0;
    //  b=3;
    //  c=7;
    int z; // Hilfsvariable
    z = a;
    a = b;
    b = c;
    c = z;
    printf("Second task result is: a=%d, b=%d, c=%d\n", a, b, c);
    return 0; // Wir geben 0 als Stub zurück
}

// Aufgabe 3a
int while_loop(int n) {
    int result = 1; // Wir beginnen bei 1, denn wenn es bei 0 liegt, ist das Produkt immer 0
    int i = 1;
    while (i <= n) { // Wir multiplizieren unser Ergebnis mit jeder Iteration bis einschließlich n
        result = result * i;
        i++;
    }
    printf("Third task '3a' result is: %d\n", result);
    return result;
}

// Aufgabe 3b
int for_loop(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result = result * i;
    }
    printf("Third task '3b' result is: %d\n", result);
    return result;
}

// Aufgabe 4a
int ones_place(int n) {
    int result = 0;
    result = n % 10; // Der Rest bei der Division durch 10 ist im Wesentlichen die letzte Ziffer der Zahl
    printf("Fourth task '4a' result is: %d\n", result);
    return result;
}

// Aufgabe 4b
int tens_place(int n) {
    int result = 0;
    result = (n / 10) % 10; // Bei der ersten Operation entfernen wir die letzte Ziffer, da int den Rest entfernt
    printf("Fourth task '4b' result is: %d\n", result); // und dann bekommen wir schon % unseren Rest
    return result;
}

// Aufgabe 5a result 8
// Aufgabe 5b result 7
// Aufgabe 5c result 6174






