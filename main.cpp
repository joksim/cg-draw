#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
// #include <stdint.h>

SDL_Window* window;
SDL_Surface* surface;
uint32_t* pixels;

#define WIDTH 960
#define HEIGHT 480

void pixel(int x, int y, uint32_t color) {
  if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;
  pixels[y * WIDTH + x] = color;
}

uint32_t rgb(uint8_t r, uint8_t g, uint8_t b) {
  return (uint32_t)SDL_MapRGB(surface->format, r, g, b);
}

void line(int x0, int y0, int x1, int y1, uint32_t color) {
  int dx = x1 - x0;
  int dy = y1 - y0;

  int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

  if (!steps) steps++;  // avoid dividing by zero errors!
  float xinc = dx / (float)steps;
  float yinc = dy / (float)steps;

  float x = x0;
  float y = y0;

  for (int i = 0; i <= steps; i++) {
    pixel(roundf(x), roundf(y), color);
    x += xinc;
    y += yinc;
  }
}

int main() {
  SDL_Init(SDL_INIT_VIDEO);
  window = SDL_CreateWindow("Framebuffer Rendering!", SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
                            SDL_WINDOW_SHOWN);
  surface = SDL_GetWindowSurface(window);

  pixels = (uint32_t*)surface->pixels;
  bool quit = false;
  SDL_Event e;

  float x0 = 50;
  float x1 = 600;
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
    }
    SDL_LockSurface(surface);

    // Clean up the framebuffer with the specified color
    memset(pixels, 0, sizeof(uint32_t) * WIDTH * HEIGHT);

    // Draw pixels
    for (int y = 0; y < 255; y++) {
      for (int x = 0; x < 255; x++) {
        pixel(x + 100, y + 100, rgb(x, 0, y));
      }
    }


    // Draw a moving line
    line(x0, 50, x1, 400, rgb(255,255,255));
    x0+=.1; if (x0>=WIDTH) x0=0;
    x1-=.05; if (x1<0) x1=WIDTH;

    SDL_UnlockSurface(surface);
    SDL_UpdateWindowSurface(window);
  }

  SDL_DestroyWindow(window);
  SDL_Quit();
}
