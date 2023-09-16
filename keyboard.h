enum {
    ESC = 27,
    ARROW_UP = 328,
    ARROW_DOWN = 336,
    ARROW_LEFT = 331,
    ARROW_RIGHT = 333,
    F1 = 315,
    CTRL_L = 12,
    ENTRER = 13,
    ALPHA_a = 97,
    ALPHA_z = 122,
    ALPHA_A = 65,
    ALPHA_Z = 90,
    KEY_0 = 48,
    KEY_9 = 57,
    BACK_SPACE = 8,
    SPACE_BAR = 32
};

int getkey(void) //lit une touche du clavier tout en gerant le buffer
{
    int ch;
    clearkeybuf();
    ch = getch();
    if (ch == 0 || ch == 224)
        ch = getch() + 256;
    return ch;
}