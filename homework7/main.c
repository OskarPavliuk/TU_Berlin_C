#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int32_t retrieve_from_pointer(int32_t *x) {
    return *x;
}

void set_through_pointer1(int32_t *x) {
    *x = 42;
    return;
}

void set_through_pointer2(int32_t *x, int32_t y) {
    *x = y;
    return;
}

void set_through_pointer3(int32_t *x, int32_t *y) {
    *x = *y;
    return;
}

void swap(int32_t *x, int32_t *y) {
    int32_t z = *x;
    *x = *y;
    *y = z;
    return;
}

bool point_to_equal_values(int32_t *x, int32_t *y) {
    if (*x == *y) {
        return true;
    }
    return false;
}

bool point_to_same_values(int32_t *x, int32_t *y) {
    return x == y;
}

typedef struct RGB_ {
    float r; /* Rotkomponente */
    float g; /* Grünkomponente */
    float b; /* Blaukomponente */
} RGB;

RGB retrieve_from_pointer_struct(RGB *x) {
    RGB color;
    color.r = x->r;
    color.g = x->g;
    color.b = x->b;
    return color;
}

void set_through_pointer_struct1(RGB *x) {
    x->r = 0.86;
    x->g = 0.82;
    x->b = 1.0;
    return;
}

void set_through_pointer_struct2(RGB *x, RGB y) {
    *x = y;
    return;
}

void set_through_pointer_struct3(RGB *x, RGB *y) {
    *x = *y;
    return;
}

void swap_struct(RGB *x, RGB *y) {
    RGB z = *x;
    *x = *y;
    *y = z;
    return;
}

bool point_to_equal_values_struct(RGB *x, RGB *y) {
    return (x->r == y->r) && (x->g == y->g) && (x->b == y->b);
}

bool point_to_same_values_struct(RGB *x, RGB *y) {
    return x == y;
}

float retrieve_from_pointer_field(RGB *x) {
    return x->b;
}

void set_through_pointer_field1(RGB *x) {
    x->b = 0;
    return;
}

void set_through_pointer_field2(RGB *x, RGB y) {
    x->b = y.b;
    return;
}

void set_through_pointer_field3(RGB *x, RGB *y) {
    x->b = y->b;
    return;
}

void swap_field(RGB *x, RGB *y) {
    float temp = x->b;  // Speichert den Wert der Blaukomponente der Farbe, auf die x zeigt, in temp
    x->b = y->b;        // Setzt die Blaukomponente der Farbe, auf die x zeigt, auf den Wert der Blaukomponente der Farbe, auf die y zeigt
    y->b = temp;
    return;
}

bool point_to_equal_values_field(RGB *x, RGB *y) {
    return (x->b == y->b);
}

bool point_to_same_values_field(RGB *x, RGB *y) {
    return (&(x->b) == &(y->b));
}


int32_t frumpleflabblefizzledipp(int32_t x) {
    // Berechnen Sie den flabble von x und den fizzledipp von x
    int32_t i = x;
    fizzledipp(&x);


    // Обчисліть flabble_result
    int32_t flabble_result = flabble(&i, &x);

    int32_t z;
    int32_t y = 27;

    // Обчисліть frumple_result
    frumple(flabble_result, &y, &z);

    return z;

}

typedef enum Layer_ {
    Fruit, Cream, ActualPancake
} Layer;

/*
Ein Pfannkuchenhaufen besteht aus einer Schicht, auf der möglicherweise ein weiterer Pfannkuchenhaufen liegt:
*/
typedef struct PileOfPancakes_ PileOfPancakes;
struct PileOfPancakes_ {
    Layer layer; /* Die unterste Schicht. */
    PileOfPancakes *further_layers; /* Weitere Schichten, oder `null` falls keine mehr folgen. */
};

int32_t count_fruit_layers(PileOfPancakes p) {
    if (p.layer == Fruit) {
        // Die aktuelle Schicht ist eine Fruchtschicht.
        // Zähle sie und überprüfe weitere Schichten, falls vorhanden.
        int32_t count = 1;
        if (p.further_layers != NULL) {
            count += count_fruit_layers(*p.further_layers);
        }
        return count;
    } else if (p.further_layers != NULL) {
        // Die aktuelle Schicht ist keine Fruchtschicht, aber es gibt weitere Schichten.
        // Überprüfe die nächsten Schichten.
        return count_fruit_layers(*p.further_layers);
    } else {
        // Es gibt keine weiteren Schichten oder Fruchtschichten.
        return 0;
    }
}


bool is_stable(PileOfPancakes p) {
    // Wenn der Pfannkuchenhaufen leer ist, ist er nicht stabil.
    if (p.layer == ActualPancake && p.further_layers == NULL) {
        return true;
    }

    // Überprüfe die erste Schicht auf "ActualPancake".
    if (p.layer != ActualPancake) {
        return false;
    }

    // Suchen Sie die letzte Schicht.
    PileOfPancakes *last_layer = &p;
    while (last_layer->further_layers != NULL) {
        last_layer = last_layer->further_layers;
    }

    // Überprüfen Sie, ob die letzte Schicht "ActualPancake" ist.
    return last_layer->layer == ActualPancake;
}