//
// Created by michael on 3/10/20.
//

#include "Speaker.h"

Speaker::Speaker() {
    buffer.loadFromFile(menu_voice_path);
    menu_voice.setBuffer(buffer);
    buffer.loadFromFile(cursor_voice_path);
    cursor_voice.setBuffer(buffer);

}