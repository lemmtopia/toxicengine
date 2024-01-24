#pragma once

#include <SDL2/SDL.h>

#include "../ECS/ECS.h"
#include "../Components/TransformComponent.h"

#include <utility>

class RenderSystem: public System<TransformComponent> {
    public:
        void Update(SDL_Renderer* renderer) {
            for (auto obj: myPool->GetData()) {
                SDL_Rect dstRect = {obj.second.x, obj.second.y, obj.second.scaleX, obj.second.scaleY};

                SDL_RenderDrawRect(renderer, &dstRect);
            }
        }
};
