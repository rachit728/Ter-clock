# Ter-clock

**Ter-clock** is a terminal-based clock that aims for memory efficiency and CPU friendliness.

It is an open-source tool with no dependencies on Windows and can be set up in just a few steps.

Created by **mcro** for Hack Club's **YSWS** project, Ter-clock is being frequently updated with performance improvements and new features.

---

# Update

## Current Version: v0.1

### Features

1. Support for template-based customization of the clock interface.
2. Uses system calls for sleeping and clearing the screen.
3. String substitution-based template engine.

---

# Dependencies

If you are using **Linux**, **macOS**, or **BSD**, you must install **ncurses**.

> **Windows:** No additional dependencies are required.

## Ubuntu / Debian

```bash
sudo apt install libncurses5-dev libncursesw5-dev
```

## Fedora / RHEL

```bash
sudo dnf install ncurses-devel
```

## macOS

```bash
brew install ncurses
```

## BSD (Berkeley Software Distribution)

```bash
pkg install ncurses
```

---

# Compiling the Project

Before compiling the project, clone the repository:

```bash
cd ~
git clone https://github.com/rachit728/Ter-clock.git
cd Ter-clock
```

## Windows

```bash
gcc src/main.c -o tclock
```

## Linux & BSD

```bash
gcc src/main.c -o tclock -lncurses
```

---

# Running the Program

Run the compiled binary using:

```bash
./tclock
```

Ter-clock uses a specialized template text-rendering engine to draw the user interface.

If the required template file (filename is clock.txt) is not available, **tclock** will refuse to start.

See **"How to Use the Template Engine"** below for more information.

---

# How to Use the Template Engine

To use Ter-clock's template engine:

1. Compile the project into a binary.
2. Place a file named **`clock.txt`** inside the project directory.

The file **must** contain the following placeholders. If any of them are missing, the template engine will fail during string substitution.

| Placeholder | Description |
|------------|-------------|
| `(time)` | Displays the current time in **Hour:Minute AM/PM** format. |
| `(date)` | Displays the current date in **Day, Month Date** format. |
| `(status)` | Displays the Wi-Fi connection status *(Under construction).* |

