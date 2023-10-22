#include <stdio.h>
#include <math.h>

int sum_divisible_both(int n);

int sum_divisible_or(int n);

int sum_divisible_either(int n);

int signum(int x);

int is_leapyear(int year);

int greatest_of_three(int a, int b, int c);

int is_prime(int n);

int sum_first_primes(int n);

int main() {
    sum_divisible_both(13);
    sum_divisible_or(13);
    sum_divisible_either(13);
    signum(0);
    is_leapyear(400);
    greatest_of_three(1, 2, 3);
    is_prime(12);
    sum_first_primes(4);
    return 0;
}

int sum_divisible_both(int n) {
    int result = 0;
    /*
    Aufgabe 1a:
    Weisen Sie der Variable `result` die Summe aller Ganzzahlen zwischen `0` und `n` (inklusive) zu, welche sowohl
    durch `7` *als auch* durch `13` teilbar sind.
    */
    /* BEGIN CHANGES */
    for (int i = 0; i <= n; i++) {
        if (i % 7 == 0 && i % 13 == 0) {
            result = result + i;
        }
    }
    printf("result is: %d\n", result);
    /* END CHANGES */
    return result;
}


int sum_divisible_or(int n) {
    int result = 0;
/*
Aufgabe 1b:
Weisen Sie der Variable `result` die Summe aller Ganzzahlen zwischen `0` und `n` (inklusive) zu, welche
durch `7` *oder* durch `13` teilbar sind (das beinhaltet auch die Zahlen, die durch beides teilbar sind).
*/
/* BEGIN CHANGES */
    for (int i = 0; i <= n; i++) {
        if (i % 7 == 0 || i % 13 == 0) {
            result = result + i;
        }
    }
    printf("result is: %d\n", result);
/* END CHANGES */
    return result;
}


int sum_divisible_either(int n) {
    int result = 0;
    /*
    Aufgabe 1c:
    Weisen Sie der Variable `result` die Summe aller Ganzzahlen zwischen `0` und `n` (inklusive) zu, welche *entweder*
    durch `7` *oder* durch `13` teilbar sind (aber nicht durch beides).
    */
    /* BEGIN CHANGES */
    for (int i = 0; i <= n; i++) {
        if (i % 7 == 0 ^ i % 13 == 0) {
            result = result + i;
        }
    }
    printf("result is: %d\n", result);
    /* END CHANGES */
    return result;
}

int signum(int x) {
    int result = 0;
    /*
    Aufgabe 2a:
    Weisen Sie der Variable `result` den Wert `-1` zu, falls `x` strikt negativ ist, `0` falls `x` gleich `0` ist, und
    `1` falls `x` strikt positiv ist.
    */
    /* BEGIN CHANGES */
    if (x < 0) {
        result = -1;
    } else if (x == 0) {
        result = 0;
    } else result = 1;
    printf("result is: %d", result);
    /* END CHANGES */
    return result;
}

int is_leapyear(int year) {
    int result = 0;
    /*
    Aufgabe 2b:
    Im gregorianischen Kalender ist ein Jahr ein Schaltjahr, genau dann wenn die Jahreszahl durch 400 teilbar ist, oder
    wenn sie durch vier teilbar ist aber nicht durch 100.

    Weisen Sie der Variable `result` den Wert `1` zu, falls `year` ein Schaltjahr ist, und ansonsten `0`.
    */
    /* BEGIN CHANGES */
    // if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 !=0))){
    //        result = 1;}
    //    else result = 0;
    if (year % 400 == 0) {
        result = 1;
    } else if (year % 4 == 0) {
        if (year % 100 == 0) {
            result = 0;
        } else {
            result = 1;
        }
    } else result = 0;
    /* END CHANGES */
    printf("%d\n", result);
    return result;
}


int greatest_of_three(int a, int b, int c) {
    int result = 0;
    /*
    Aufgabe 2c:
    Weisen Sie der Variable `result` den größten Wert zu, den eine der drei Variablen `a`, `b`, `c` hat.
    */
    /* BEGIN CHANGES */
    if (a > b && a > c) {
        result = a;
    } else if (b > a && b > c) {
        result = b;
    } else { result = c; }
    printf("result is: %d\n", result);
    /* END CHANGES */
    return result;
}

int is_prime(int n) {
    int result = 0;
    /*
    Aufgabe 3a:
    Eine Primzahl ist eine natürliche Zahl größer gleich 2, deren einzigen ganzzahligen Teiler die eins und die Zahl selbst sind.
    Die ersten Primzahlen sind 2, 3, 5, 7, 11, 13, ...

    Weisen Sie der Variable `result` den Wert `1` zu, falls `n` eine Primzahl ist, und ansonsten `0`.
    */
    /* BEGIN CHANGES */
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            result = 0;
        } else result = 1;
    }
    printf("result is: %d\n", result);
    /* END CHANGES */
    return result;
}

int sum_first_primes(int n) {
    int result = 0;
    /*
    Aufgabe 3b:
    Weisen Sie der Variable `result` die Summe der ersten `n` Primzahlen zu zu.
    Beispiel für `n = 4`: `2 + 3 + 5 + 7 = 17`.
    */
    /* BEGIN CHANGES */
    int prime_sum = 0;
    int num = 2;
    int primes_found = 0;
    while (primes_found < n) {
        if (is_prime(num) == 1) {
            prime_sum += num;
            primes_found++;
        }
        num++;
    }
    result = prime_sum;
    printf("%d", result);
    /* END CHANGES */
    return result;
}







