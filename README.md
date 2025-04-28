# Raycasting Demo (C++17 + SDL2)

A basic 2D raycasting engine written in modern **C++17** using **SDL2** and **SDL2_ttf** for rendering and FPS display.
Inspired by classic games like *Wolfenstein 3D*, this project showcases the fundamentals of raycasting in a simple, modular structure.

---

## Features

- Modular C++17 codebase
- Simple 2D map rendering
- Real-time raycasting and 3D wall rendering
- Player movement and rotation
- Basic FPS counter using SDL2_ttf

---


## Requirements

- **g++** (supporting C++17)
- **SDL2** library
- **SDL2_ttf** library

On Ubuntu/Debian you can install them with:
```bash
sudo apt update
sudo apt install g++ libsdl2-dev libsdl2-ttf-dev
```

---

## Build and Run

You can use the provided `run.sh` script:

```bash
chmod +x run.sh
./run.sh
```

What `run.sh` does:
```bash
g++ -std=c++17 ./../src/main.cpp \
    ./../src/map/map.h ./../src/map/map.cpp \
    ./../src/render/render.h ./../src/render/render.cpp \
    -o raycaster -lSDL2 -lSDL2_ttf
./raycaster
```
<br>

```

---

## Controls

- **Arrow Left/Right**: Rotate player
- **Arrow Up**: Move forward
- **Arrow Down**: Move backward

---

## Notes

- Make sure SDL2 and SDL2_ttf are properly installed.
- The font path may need adjustment based on your system (currently hardcoded to DejaVuSans.ttf).
- Target frame rate is capped at ~30 FPS for simplicity.

---

## License

This project is released under the MIT License. Feel free to use and modify it as you like!

---

## TODO (Future Improvements)

- Add collision response (currently basic wall collision handling)
- Implement textures for walls
- Add enemy sprites
- Refactor input handling
- Modularize player movement into its own module


