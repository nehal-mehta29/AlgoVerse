# 🌸 AlgoVerse

### Visualize · Analyze · Understand

**AlgoVerse** is an interactive, terminal-based Data Structures and Algorithms (DSA) visualizer built in C. It helps learners understand how sorting and searching algorithms work through step-by-step execution, visual representations of data structures, and algorithm cost analysis.

---

## 📌 Overview

Understanding an algorithm involves more than knowing its final output. AlgoVerse makes the process easier to follow by displaying intermediate operations, comparisons, swaps, pointer changes, and search progress directly in the terminal.

The project combines algorithm implementation with data structure visualization and performance analysis to create a practical learning experience using C.

## ✨ Features

- **Interactive Terminal Interface** — Navigate through sorting, searching, dataset management, and project information using menus.
- **Reusable Dataset** — Enter a dataset once and reuse it across different algorithms.
- **Step-by-Step Execution** — Follow the important operations performed during sorting and searching.
- **Pointer Visualization** — Observe linked-list connections being broken and re-established during sorting.
- **Tree Visualization** — Follow the current node, traversal progress, and search results in tree-based algorithms.
- **Cost Analysis** — View execution time, comparison counts, swap counts where applicable, theoretical estimates, and time and space complexity.
- **Colour-Coded Output** — Distinguish current elements, successful operations, pointer changes, and other visualization states.
- **Dataset Management** — Change the dataset without restarting the application.

## 🧮 Algorithms Implemented

### Sorting Algorithms

Sorting visualizations use a **doubly linked list**, demonstrating how node connections are manipulated during sorting.

| Algorithm | Core Concept |
|---|---|
| Bubble Sort | Repeatedly compares adjacent elements |
| Selection Sort | Selects the minimum element from the unsorted portion |
| Insertion Sort | Inserts elements into their correct positions |
| Merge Sort | Divides the list and merges sorted portions |
| Quick Sort | Partitions elements around a pivot |

### Searching Algorithms

| Algorithm | Core Concept |
|---|---|
| Linear Search | Checks elements sequentially |
| Binary Search | Repeatedly halves the search interval |
| Jump Search | Skips through blocks before searching within a block |
| Binary Search Tree (BST) Search | Follows tree branches to locate a key |
| Depth-First Search (DFS) | Explores a branch before backtracking |
| Breadth-First Search (BFS) | Explores nodes level by level |

**Note:** Binary Search and Jump Search require sorted data. AlgoVerse checks the dataset and sorts a working copy when necessary, leaving the stored dataset available for other algorithms.

## 📊 Cost Analysis

AlgoVerse presents practical execution measurements alongside theoretical algorithm analysis.

### Sorting

- Execution time
- Number of comparisons
- Number of swaps
- Theoretical comparison and swap estimates
- Best-case, average-case, and worst-case time complexity
- Space complexity

### Searching

- Execution time
- Number of comparisons
- Theoretical comparison estimates
- Best-case, average-case, and worst-case time complexity
- Space complexity

> **Note:** Execution time and operation counts depend on the implementation, input, and system environment. Theoretical estimates describe expected algorithmic behaviour and may differ from the actual operations counted by the program.

## 🛠️ Technology Stack

- **Programming Language:** C
- **Compiler:** GCC / MinGW
- **Development Environment:** Visual Studio Code
- **Interface:** Command-line terminal with ANSI colour sequences
- **Concepts Used:** Pointers, dynamic memory allocation, arrays, doubly linked lists, binary trees, recursion, sorting, searching, and complexity analysis

## 📁 Project Structure

```text
AlgoVerse/
├── include/
│   ├── sorting/
│   ├── searching/
│   ├── about.h
│   ├── colors.h
│   ├── controller.h
│   ├── cost.h
│   ├── dataSet.h
│   ├── datasetInput.h
│   ├── doublyLinkedList.h
│   ├── menu.h
│   ├── ui.h
│   └── utils.h
├── src/
│   ├── sorting/
│   ├── searching/
│   ├── about.c
│   ├── controller.c
│   ├── cost.c
│   ├── dataSet.c
│   ├── datasetInput.c
│   ├── doublyLinkedList.c
│   ├── menu.c
│   ├── ui.c
│   └── utils.c
├── main.c
└── README.md
```

## ⚙️ Installation and Setup

### Prerequisites

- Windows operating system
- GCC compiler installed through MinGW or MinGW-w64
- Visual Studio Code (recommended)

Verify that GCC is available in your terminal:

```powershell
gcc --version
```

### 1. Clone the Repository

```bash
git clone https://github.com/nehal-mehta29/AlgoVerse.git
cd AlgoVerse
```

### 2. Compile the Project

Open the project folder in VS Code. In the integrated **PowerShell terminal**, run the following commands from the project root:

```powershell
$files = Get-ChildItem .\src -Recurse -Filter *.c | ForEach-Object { $_.FullName }
gcc -I include main.c $files -o AlgoVerse.exe
```

This compiles `main.c` and the C source files inside `src`, using the header files in `include`.

### 3. Run AlgoVerse

```powershell
.\AlgoVerse.exe
```

**Terminal note:** Use a terminal that supports ANSI colour sequences for the intended visual experience.

## 🎮 How to Use

1. Launch AlgoVerse.
2. Enter the number of elements and the values for your dataset.
3. Select **Sorting** or **Searching** from the home menu.
4. Choose an algorithm from the relevant menu.
5. Follow the visualization to observe the algorithm's operations.
6. Review the cost analysis after execution.
7. Return to the home menu to try another algorithm, change the dataset, or view project information.
8. Select **Exit** to close the application.

## 🎯 Project Objectives

- Make sorting and searching algorithms easier to understand through terminal visualization.
- Demonstrate pointer manipulation through doubly linked-list operations.
- Connect theoretical complexity with practical execution measurements.
- Strengthen understanding of C programming, dynamic data structures, and algorithm design.

## 🔮 Future Scope

- Add more sorting and searching algorithms.
- Expand visualization options for additional data structures.
- Improve algorithm comparison and performance reporting.
- Extend the analysis of memory usage and execution behaviour.

## 👩‍💻 Author

**Nehal Mehta**

Developed as a C programming project focused on algorithm visualization, pointer manipulation, and complexity analysis.

---

<p align="center">
  <i>Learn the logic. Follow the pointers. Understand the algorithm.</i>
</p>