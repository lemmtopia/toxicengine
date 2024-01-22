#pragma once

struct TransformComponent {
    int x, y;

    TransformComponent(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }
};
