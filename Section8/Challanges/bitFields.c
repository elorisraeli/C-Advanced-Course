#include <stdio.h>

/*
colors: 000 black, 001 red, 010 green, 011 yellow, 100 blue, 101 magenta, 110 cyan, 111 white
styles: 001 solid, 010 dotted, 011 dashed
*/

#define SOLID 0
#define DOTTED 1
#define DASHED 2

#define BLUE 4
#define GREEN 2
#define RED 1

#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char *colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

struct box_properties
{
    unsigned int : 6;
    unsigned int is_opaque : 1;
    unsigned int fill_color : 3;
    unsigned int border_visible : 1;
    unsigned int border_color : 3;
    unsigned int border_style : 2;
    // 16 bits at total
};

void show_settings(const struct box_properties *pb);

int main(void)
{
    /* create and initialize box_props structure */
    struct box_properties box = {1, YELLOW, 1, GREEN, DASHED};

    printf("Original box settings:\n");
    show_settings(&box);

    box.is_opaque = 0;
    box.fill_color = WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;
    printf("\nModified box settings:\n");
    show_settings(&box);

    return 0;
}

void show_settings(const struct box_properties *pb)
{
    printf("Box is %s.\n", pb->is_opaque == 1 ? "opaque" : "transparent");
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border %s.\n", pb->border_visible == 1 ? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf("The border style is ", colors[pb->border_color]);

    switch (pb->border_style)
    {
    case SOLID:
        printf("solid.\n");
        break;
    case DOTTED:
        printf("dotted.\n");
        break;
    case DASHED:
        printf("dashed.\n");
        break;
    default:
        printf("unknown style.");
        break;
    }
}
