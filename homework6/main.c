#include <stdio.h>

int width = canvas_width(c);
int height = canvas_height(c);

for (int x = 0; x < width; x++) {
for (int y = 0; y < height; y++) {
c = canvas_set_r(c, x, y, (float)x / (width - 1));
c = canvas_set_g(c, x, y, 1.0 - (float)y / (height - 1));
}
}

return c;
}

typedef enum ColorChannel_ {
    Red,
    Green,
    Blue
} ColorChannel;

Canvas canvas_set_channel(Canvas c, int x, int y, ColorChannel channel, float v) {
    if (channel == Red) {
        return canvas_set_r(c, x, y, v);
    } else if (channel == Green) {
        return canvas_set_g(c, x, y, v);
    } else {
        return canvas_set_b(c, x, y, v);
    }
}

Canvas swatch_rgb(Canvas c, ColorChannel channel_x, ColorChannel channel_y) {
    return c;
}

typedef struct RGBByTheWayThisCanBeNamedArbitrarilygSinceWeAreUsingTheTypedefAnyways {
    float r;
    float g;
    float b;
} RGB;

RGB lilac() {
    RGB color;
    color.r = 0.86;
    color.g = 0.82;
    color.b = 1.0;
    return color;
}


Canvas canvas_set_rgb_struct(Canvas c, int x, int y, RGB color) {
    c = canvas_set_r(c, x, y, color.r);
    c = canvas_set_g(c, x, y, color.g);
    c = canvas_set_b(c, x, y, color.b);
    return c;
}

RGB rgb_to_gray(RGB color) {
    float gray_value = 0.2989 * color.r + 0.587 * color.g + 0.1140 * color.b;
    color.r = gray_value;
    color.g = gray_value;
    color.b = gray_value;
    return color;
}

Canvas canvas_to_gray(Canvas c) {
    int width = canvas_width(c);
    int height = canvas_height(c);

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            RGB color;
            color.r = canvas_get_r(c, x, y);
            color.g = canvas_get_g(c, x, y);
            color.b = canvas_get_b(c, x, y);

            color = rgb_to_gray(color);

            c = canvas_set_rgb_struct(c, x, y, color);
        }
    }

    return c;
}