# Sudoku Solver

A C-based Sudoku solver utilizing a recursive backtracking algorithm to efficiently resolve complex grids.

## 📂 Project Overview

This project is an automated Sudoku solver developed in C. It uses a **recursive backtracking algorithm** to explore the solution space and find the correct configuration for any valid Sudoku grid. The application includes a graphical user interface powered by the **libMLV** library.

* **Key Concepts:** Backtracking, Recursion, Grid State Management, Graphical Interface.
* **External Library:** libMLV (Multimedia Library).

## 🛠️ Prerequisites

To compile and run this project, you must have the **libMLV** library installed on your system.

### Installing libMLV

The library is available at the official address: [http://www-igm.univ-mlv.fr/~borie/libMLV/](https://www.google.com/search?q=http://www-igm.univ-mlv.fr/~borie/libMLV/)

On Debian/Ubuntu-based systems, you can typically install the development headers using:

```bash
sudo apt-get install libmlv3-dev

```

## 🚀 Getting Started

### Compilation

The project uses a `Makefile` for easy compilation. Open your terminal and run:

```bash
make

```

### Execution

Once compiled, launch the solver with the following command:

```bash
./sudoku path/to/your/grid_file

```

### Cleaning Up

To remove temporary object files and the executable, use:

```bash
make clean

```

## 📄 File Structure

* `main.c`: Entry point of the application.
* `sudoku.c / .h`: Core logic and backtracking algorithm.
* `graphic.c / .h`: Graphical interface management using libMLV.
* `in_out.c / .h`: Input/Output operations for grid loading.

---

*Developed as part of the ESIEE Paris engineering curriculum.*
