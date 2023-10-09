// OLED
#ifdef OLED_ENABLE

// Rotate OLED
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

// Draw to OLED
bool oled_task_user() {
    // Set cursor position
    oled_set_cursor(0, 1);

    // Switch on current active layer
    switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write("Base    ", false);
            break;
        case 1 :
            oled_write("Extended", false);
            break;
        case 2 :
            oled_write("Function", false);
            break;
        case 3 :
            oled_write("Symbol  ", false);
            break;
    }

    return false;
}

#endif