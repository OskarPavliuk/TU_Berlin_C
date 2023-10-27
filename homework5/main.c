#include <stdio.h>
#include <stdio.h>
#include <math.h>


int valid_pixel(Canvas c, int x, int y){
    return (x>=0 && x<canvas_width(c) && y>=0 && y<canvas_height(c));
}

Canvas recursive_line(Canvas c, int x, int y, int width) {
    if (width > 0){
        recursive_line(c,x+1, y, width -1);
        if (valid_pixel(c,x,y)){
            c = canvas_set_black(c,x,y);
        }
    }
    return c;
}

Canvas recursive_rectangle(Canvas c, int x, int y, int width, int height) {
    if (width > 0 && height > 0) {
        // Рекурсивно викликати функцію для малювання бічних ліній прямокутника
        c = recursive_rectangle(c, x, y + 1, width, height - 1);

        // Перевірка, чи піксель належить до полотна
        if (valid_pixel(c, x, y)) {
            c = canvas_set_black(c, x, y);
        }

        // Намалювати верхню горизонтальну лінію прямокутника
        c = recursive_line(c, x, y, width);
    }
    return c;
}

int power(int b, int exp){
    if (exp == 0) {
        return 1;
    } else {
        return b * power(b, exp - 1);
    }
}

Canvas sierpinski_carpet(Canvas c, int n, int x, int y){
    if (n == 0) {
        // Basisfall: Zeichne ein einzelnes schwarzes Pixel
        c = canvas_set_black(c, x, y);
    } else {
        // Berechne die Größe des aktuellen Sierpinski-Carpets
        int size = power(3, n - 1);

        // Zeichne acht kleinere Sierpinski-Carpets der Ordnung `n-1`
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) {
                    // Das Mittelstück überspringen (es bleibt leer)
                    continue;
                }

                int newX = x + i * size;
                int newY = y + j * size;
                c = sierpinski_carpet(c, n - 1, newX, newY);
            }
        }
    }

    return c;
}

Canvas bucket_fill(Canvas c, int x, int y) {
    // Überprüfen, ob die angegebenen Koordinaten innerhalb der Canvas-Grenzen liegen.
    if (x < 0 || x >= canvas_width(c) || y < 0 || y >= canvas_height(c)) {
        return c; // Koordinaten außerhalb des gültigen Bereichs.
    }

    // Überprüfen, ob der Pixel an den angegebenen Koordinaten bereits schwarz ist.
    if (pixel_is_black(c, x, y)) {
        return c; // Pixel ist bereits schwarz, keine Aktion erforderlich.
    }

    // Überprüfen, ob der Pixel an den angegebenen Koordinaten weiß ist.
    if (pixel_is_white(c, x, y)) {
        // Färbe den aktuellen Pixel schwarz.
        c = canvas_set_black(c, x, y);

        // Rekursiver Aufruf für benachbarte Pixel oben, unten, links und rechts.
        c = bucket_fill(c, x, y + 1); // Nach unten
        c = bucket_fill(c, x, y - 1); // Nach oben
        c = bucket_fill(c, x - 1, y); // Nach links
        c = bucket_fill(c, x + 1, y); // Nach rechts
    }

    return c;
}
