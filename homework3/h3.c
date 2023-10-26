#include <stdio.h>
#include "03_canvas.h"

int is_multiple_of(int n, int k) {
    int remainder = n % k;
    return remainder == 0;
}

int sum_of_divisibles(int n, int m) {
    int sum = 0;
    int count = 0;
    int number = 1;
    while (count < n) {
        if (is_multiple_of(number, m) == 1) {
            sum = sum + number;
            count++;
        }
        number++;
    }
    return sum;
}

int sum_of_doubly_divisibles(int n, int l, int m) {
    int sum = 0;
    int count = 0;
    int number = 1;
    while (count < n) {
        if (is_multiple_of(number, l) == 1 && is_multiple_of(number, m) == 1) {
            sum += number;
            count++;
        }
        number++;
    }
    return sum;
}

Canvas first_canvas_exercise(Canvas c) {
    c = canvas_set_black(c, 1, 5);
    c = canvas_set_black(c, 2, 1);
    c = canvas_set_black(c, 13, 4);
    return c;
}

Canvas color_corners(Canvas c) {
    int width = canvas_width(c);
    int height = canvas_height(c);
    c = canvas_set_black(c, 0, 0);
    c = canvas_set_black(c, 0, height - 1);
    c = canvas_set_black(c, width - 1, 0);
    c = canvas_set_black(c, width - 1, height - 1);
    return c;
}

Canvas paint_it_black(Canvas c) {
    int height = canvas_height(c);
    int width = canvas_width(c);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            c = canvas_set_black(c, x, y);
        }
    }
    return c;
}

Canvas descending_diagonal(Canvas c) {
    int width = canvas_width(c);
    int height = canvas_height(c);
    for (int x = 0; x < width && x < height; x++) {
        c = canvas_set_black(c, x, height - x - 1);

        for (int y = x + 1; y < height; y++) {
            c = canvas_set_black(c, x, height - y - 1);
        }
    }

    return c;
}

Canvas draw_rectangle(Canvas c, int x, int y, int width, int height) {
if (width > 0 && height > 0) {
                for (int j = y; j > y - height; j--) {
                    for (int i = x; i < x + width; i++) {
                        if (valid_pixel(c, i, j)){
                            c = canvas_set_black(c, i, j);
                        }}
                }
            }
    return c;
}

Canvas draw_rectangle_via_corners(Canvas c, int x0, int y0, int x1, int y1) {
    if (canvas_width(c) > 0 && canvas_height(c) > 0) {
        for (int j = y0; j >= y1; j--) {
            for (int i = x0; i <= x1; i++) {
                if (valid_pixel(c, i, j)){
                    c = canvas_set_black(c, i, j);
                }}
        }
    }
    return c;
}
