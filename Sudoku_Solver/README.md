# 🧩 Custom Sudoku Game & Generator (C++ / SFML)

A fully interactive Sudoku game built in **C++** using **SFML**, featuring automatic puzzle generation, live rule validation, and a graphical user interface.

Unlike traditional Sudoku solvers, this project generates playable puzzles dynamically and allows users to solve them interactively with immediate visual feedback.

Developed as part of the **CodeAlpha C++ Programming Internship**.

---

# ✨ Features

✔ Graphical User Interface using SFML
✔ Procedural Sudoku puzzle generation
✔ Backtracking-based valid board generation
✔ Interactive gameplay
✔ Mouse cell selection
✔ Keyboard number input (1–9)
✔ Live Sudoku rule checking
✔ Invalid moves highlighted in red
✔ Locked original clues
✔ Win detection system
✔ Instant puzzle regeneration (`R` key)

---

# 🛠 Technologies Used

* **Language:** C++
* **Framework:** SFML
* **Standard:** Latest C++ Standard

### Concepts Applied

* Object-Oriented Thinking
* Backtracking Algorithms
* Recursive Solving
* Event Handling
* GUI Programming
* State Management
* 2D Rendering

---

# 🎮 Controls

| Action              | Input              |
| ------------------- | ------------------ |
| Select Cell         | Left Click         |
| Enter Number        | Keyboard (1–9)     |
| Delete Number       | Backspace / Delete |
| Generate New Puzzle | R                  |

---

# ⚙ How It Works

## 1. Puzzle Generation

The application starts by generating a complete valid Sudoku board using recursive backtracking.

```text
Generate Empty Grid
       ↓
Fill Valid Numbers
       ↓
Create Solved Board
       ↓
Remove Cells
       ↓
Generate Playable Puzzle
```

---

## 2. Live Rule Validation

Every player move is checked immediately against:

* Row constraints
* Column constraints
* 3×3 subgrid rules

Invalid moves appear visually in red.

---

## 3. Win Detection

The game automatically checks:

✔ Grid completely filled
✔ No rule violations

If successful:

```text
CONGRATULATIONS!
You solved the Sudoku completely!
```

---

# 🖥 Interface Features

### Visual Indicators

🟦 Selected Cell Highlight
⬜ Editable Cells
🔵 Original Locked Numbers
🔴 Invalid User Entries

---

# ▶ How to play

* Just double click on the Sudoko.exe file and the game will launch!
* (Note: make sure that the SFML dependencies are present with the Sudoko.exe file)

---

# 📂 Project Structure

```text
Sudoku-SFML/
│
├── Source.cpp
├── arial.ttf
├── SFML Dependencies
├── Sudoko.exe(Executable Build)
└── README.md
```

---

# 🧠 Challenges & Learning

This project helped improve:

* Recursive problem solving
* GUI architecture
* Event-driven programming
* Grid-based game design
* Real-time validation systems
* Procedural content generation
* User experience design

---

# 🚀 Future Improvements

* Difficulty levels
* Timer system
* Hint feature
* Save & resume
* Animated transitions
* Solver mode
* Multiple themes
* Leaderboards

---

# 📜 Internship Information

Completed as part of the **CodeAlpha C++ Programming Internship**.

This project includes the optional GUI implementation beyond the core internship requirements.

---

## 👨‍💻 Author

**Kyrollos (KO2468)**

GitHub:
<https://github.com/KO2468>
