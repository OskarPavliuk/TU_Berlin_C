#include "04_canvas.h"
#include "04ex_helpers.h"
#include <stdio.h>

Canvas draw_odd_circle(Canvas c, int x, int y, int radius_from_middle) {
    int width = canvas_width(c);
    int height = canvas_height(c);

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int d = distance(x, y, i, j);

            if (d <= radius_from_middle) {
                c = canvas_set_black(c, i, j);
            }
        }
    }
    return c;
}

int my_distance(int x0, int y0, int x1, int y1) {
    int a = x1 - x0;
    int b = y1 - y0;
    int c = a * a + b * b;
    int answer = squareroot(c);
    return answer;
}

int my_squareroot(int n) {
    int result = 0;
    while (result * result <= n) {
        result++;
    }
    return result - 1;
}

Canvas draw_circle(Canvas c, int x, int y, int diameter) {
    int radius = diameter / 2; // Радіус кола

    double centerX = x + radius;
    double centerY = y + radius;

    double step = 0.01;

    for (double i = x; i < x + diameter; i += step) {
        for (double j = y; j < y + diameter; j += step) {
            double dx = i - centerX;
            double dy = j - centerY;
            double distance = dx * dx + dy * dy;

            if (distance <= radius * radius) {
                int pixel_x = (int) (i + 0.5);
                int pixel_y = (int) (j + 0.5);

                c = canvas_set_black(c, pixel_x, pixel_y);
            }
        }
    }

    return c;
}

int high_five() {
    int Feier = 5;
    return Feier;
}

int hailstone(int n) {
    int steps = 0; // Initialisieren Sie die Anzahl der Schritte auf 0.

    while (n > 1) {
        if (n % 2 == 0) {
            // Wenn n gerade ist, teilen Sie es durch 2.
            n /= 2;
        } else {
            // Wenn n ungerade ist, multiplizieren Sie es mit 3 und addieren 1.
            n = 3 * n + 1;
        }
        steps++; // Erhöhen Sie die Anzahl der Schritte.
    }

    return steps;
}

int bring_your_own_tests() {
    int verstanden = 99;
    return verstanden;
}
