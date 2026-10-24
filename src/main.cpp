#include <SDL3/SDL.h>
#include<iostream>


int main(int argc, char* argv[])
{
    // Initialize SDL3
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "SDL Error: " << SDL_GetError() << '\n';
        return 1;
    }

    // Create window and renderer
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    if (!SDL_CreateWindowAndRenderer(
            "SDL3 - Centered Rectangle",
            800, 600,
            SDL_WINDOW_RESIZABLE,
            &window, &renderer)) {
        std::cout << "Window Error: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    // Rectangle dimensions
    float rectWidth = 200.0f;
    float rectHeight = 100.0f;

    // Calculate its center position
    SDL_FRect rect;
    rect.w = rectWidth;
    rect.h = rectHeight;
    rect.x = (800.0f - rectWidth) / 2.0f;
    rect.y = (600.0f - rectHeight) / 2.0f;

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        // Clear window with black
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Draw a red rectangle
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(renderer, &rect);

        // Display the frame
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
