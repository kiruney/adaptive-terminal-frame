# Adaptive Terminal Frame

A lightweight C project that demonstrates two different approaches for drawing adaptive frames in the terminal console. The frame automatically adjusts to the terminal window size.

## Features

- **Two implementations** for terminal frame drawing:
  - Using standard C library only (`using_standart_library.c`)
  - Using ncurses library for cross-platform compatibility (`crossplatform_option.c`)
- **Dynamic resizing** - Frame adapts to terminal dimensions
- **Real-time console information** - Displays current rows and columns
- **Clean ANSI escape codes** or **ncurses-based** rendering

## Project Structure

```
adaptive-terminal-frame/
├── using_standart_library.c    # Standard C library implementation
├── crossplatform_option.c      # Ncurses-based implementation
├── Makefile                    # Build automation
└── README.md                   # This file
```

## Requirements

### For Arch Linux

```bash
# Install required packages
sudo pacman -S gcc make

# For crossplatform_option.c (ncurses)
sudo pacman -S ncurses
```

## Building

### Using Make (recommended)

```bash
# Build both executables
make

# Build specific executable
make using_standart_library
make crossplatform_option

# Clean build files
make clean
```

### Manual Compilation

```bash
# Standard library version (no dependencies)
gcc using_standart_library.c -o using_standart_library

# Ncurses version
gcc crossplatform_option.c -o crossplatform_option -lncurses
```

## Usage

### Standard Library Version
```bash
./using_standart_library
```
- Uses ANSI escape codes
- No external dependencies
- Works on any POSIX-compliant system

### Ncurses Version
```bash
./crossplatform_option
```
- Uses ncurses library
- More portable across different terminals
- Better control over terminal features

## How It Works

### Standard Library Implementation (`using_standart_library.c`)

1. Uses `ioctl()` with `TIOCGWINSZ` to get terminal dimensions
2. Draws frame using ANSI escape codes:
   - `\033[H\033[J` - Clear screen and move cursor home
   - `\x1B[%d;%df` - Position cursor (ANSI escape sequence)
3. Utilizes variable arguments for flexible text formatting

### Ncurses Implementation (`crossplatform_option.c`)

1. Initializes ncurses environment with `initscr()`
2. Gets terminal size via `getmaxyx()`
3. Draws frame using ncurses functions:
   - `mvaddch()` - Place characters at specific positions
   - `mvprintw()` - Print formatted strings
4. Provides better terminal control and portability

## Output Examples

Both programs will display:
```
##################################################
#                                                #
#                                                #
#                                                #
#        Crossplatform option with ncurses.      #
#              ROWS: 24   COLS: 80               #
#                                                #
#                                                #
#                                                #
##################################################
```

The frame dimensions automatically adjust based on your terminal window size.

## Key Differences Between Implementations

| Feature | Standard Library | Ncurses |
|---------|-----------------|---------|
| Dependencies | None | ncurses library |
| Portability | POSIX systems | Cross-platform |
| Terminal Control | Basic | Advanced |
| Code Complexity | Simple | Moderate |
| Feature Set | Limited | Extensive |

## Installation on Arch Linux

### Method 1: Clone and Build
```bash
# Clone the repository (if applicable)
git clone <repository-url>
cd adaptive-terminal-frame

# Build both versions
make

# Run the programs
./using_standart_library
./crossplatform_option
```

### Method 2: Manual Installation
```bash
# Create project directory
mkdir ~/adaptive-terminal-frame
cd ~/adaptive-terminal-frame

# Copy the source files
# ... (copy your .c files and Makefile here)

# Build
make
```

## Makefile Targets

- `make` or `make all` - Build both executables
- `make using_standart_library` - Build only standard library version
- `make crossplatform_option` - Build only ncurses version
- `make clean` - Remove compiled executables

## Troubleshooting

### Ncurses Not Found
```bash
# On Arch Linux
sudo pacman -S ncurses
```

### Permission Denied
```bash
chmod +x using_standart_library crossplatform_option
```

### Terminal Resizing Issues
- Ensure your terminal emulator supports ANSI escape codes
- For best results, use modern terminals like:
  - `alacritty`
  - `kitty`
  - `gnome-terminal`
  - `konsole`

## Development

### Adding Features
1. **Custom frame characters**: Modify the `'#'` character in draw functions
2. **Colors**: Add ANSI color codes or ncurses color functions
3. **Dynamic resizing**: Add signal handlers for window resize events

### Testing
```bash
# Test in different terminal sizes
resize -s 30 100  # Change terminal size
./using_standart_library
```

## License

This project is open source and available for educational and personal use.

## Contributing

Feel free to fork and modify for your own needs. Suggestions and improvements are welcome!

## Author

Developed as a learning project for terminal programming in C.

---
*Note: Both implementations serve as educational examples of terminal I/O in C. Choose the standard library version for minimal dependencies or the ncurses version for better terminal compatibility.*