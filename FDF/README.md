# FDF

## Description
FDF is a 3D wireframe viewer written in C. It reads a map file describing a 3D landscape and renders it in a window using the MiniLibX graphics library. The project demonstrates file parsing, matrix manipulation, and real-time rendering with user interaction.

## Features
- Reads and parses .fdf map files (heightmaps, optionally with color)
- Renders 3D wireframe projections (isometric, top, perspective)
- Interactive controls for zoom, pan, rotation, and projection
- Custom color support for map points
- Example/test maps included in `test_maps/`
- Python script to generate maps from images (`convertor/map_generator.py`)

## Build Instructions
### Prerequisites
- CC
- Make
- X11 development libraries (Linux):
  - `xorg`, `libxext-dev`, `libbsd-dev`
- Python 3 and Pillow (for map generator)

### Build
```sh
make
```
This will build the `fdf` executable and required libraries (libft, gnl, mlx).

## Usage
```sh
./fdf <map_file.fdf>
```
Example:
```sh
./fdf test_maps/plat.fdf
```

## Controls
| Key         | Action                        |
|-------------|------------------------------|
| Arrow keys  | Pan view                     |
| W/A/S/D     | Pan view (alternative)       |
| J/K         | Zoom in/out                  |
| T           | Top view                     |
| I           | Isometric projection         |
| P           | Perspective projection       |
| X/Y/Z       | Rotate around axis           |
| R           | Reset view                   |
| ESC         | Exit                         |

## Map File Format
- Each line: space-separated integers (z values), optionally with color (e.g., `10,0xFF0000`)
- Example:
  ```
  0 0 0 0
  0 10 20,0xFF0000 10
  ```
- See `test.fdf` and files in `test_maps/` for more examples.

## Map Generator
Convert PNG or JPG images to .fdf maps using the Python script:
```sh
cd convertor
python3 map_generator.py
```
Requires [Pillow](https://python-pillow.org/):
```sh
pip install Pillow
```

## Dependencies
- [MiniLibX (mlx)](library/mlx/README.md): X11 graphics library
- [libft](library/libft/): Custom C standard library
- [gnl](library/gnl/): get_next_line for file reading

## Credits
- Developed by mansargs (42 school project)
- MiniLibX by Olivier Crouzet

---

For more details, see source code and comments.
