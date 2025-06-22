# Conway's Game of Life (C, ncurses)

![Game of Life Gameplay](assets/gof.gif)

This is a terminal-based implementation of Conway's Game of Life written in C, using the `ncurses` library for rendering.

---

## Features

- Terminal interface with colored live cells, borders, and UI
- Adjustable simulation speed (`A` to speed up, `Z` to slow down)
- Simple start/stop control (`SPACE` to exit)
- Initial grid can be loaded from a `.txt` file

---

## Build & Run

### Dependencies

- GCC or Clang
- `ncurses` development library

### 🧪 Compile

```bash
make clean && make
```

---

### ▶️ Run

#### Option 1: Run with input from file

```bash
./gof < glider.txt
```

You can prepare a simple `.txt` file with rows of `0`s and `1`s separated by spaces:

**Example `glider.txt`:**
```
0 1 0
0 0 1
1 1 1
```

- You can use any grid size up to 25 rows × 80 columns (default defined by `HEIGHT` and `WIDTH`).
- Extra cells will be ignored; missing ones will be considered dead (`0`).

#### Option 2: Manual entry

You may also run the program and enter the grid directly in the terminal:
```bash
./gof
```
...then type rows of `0`s and `1`s and press `Enter` after each. Use `Ctrl+D` (EOF) to finish.

---

## ⌨️ Controls

- `A` – increase speed
- `Z` – decrease speed
- `SPACE` – exit simulation
