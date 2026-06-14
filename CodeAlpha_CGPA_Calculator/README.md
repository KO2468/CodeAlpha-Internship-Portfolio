# 🎓 CGPA Calculator (C++)

A C++ application that calculates a student's **Semester GPA** and **Overall CGPA** based on course grades and credit hours.

This project was developed as part of the **CodeAlpha C++ Programming Internship** and focuses on applying core programming concepts including data structures, user input handling, and mathematical calculations.

---

# 📌 Features

✔ Input multiple courses per semester  
✔ Support course names with spaces  
✔ Calculate Semester GPA automatically  
✔ Calculate cumulative CGPA using previous semester data  
✔ Display course-by-course breakdown  
✔ Clean formatted terminal output  

---

# 🛠 Technologies Used

- **Language:** C++
- **Standard:** Latest C++ Standard
- **Concepts Applied:**
  - Structures (`struct`)
  - Vectors
  - Input validation concepts
  - Formatted output
  - GPA/CGPA calculations

---

# ⚙ How It Works

### 1. Enter Semester Data

The user enters:

- Number of courses
- Course name
- Grade (0.0 – 4.0)
- Credit hours

---

### 2. GPA Calculation

For each course:

```text
Grade Points = Grade × Credit Hours
```

Semester GPA:

```text
Semester GPA = Total Grade Points ÷ Total Credits
```

---

### 3. Optional CGPA Calculation

If previous semester data exists:

```text
CGPA =
(Current Grade Points + Previous Grade Points)
÷
(Current Credits + Previous Credits)
```

---

# ▶ Example Run

```text
--- GPA Calculator ---

Enter the number of courses taken this semester: 3

Course 1 Name: Calculus
Enter grade (0.0 - 4.0): 3.7
Enter credit hours: 3

Course 2 Name: Physics
Enter grade (0.0 - 4.0): 3.5
Enter credit hours: 4

Course 3 Name: Programming
Enter grade (0.0 - 4.0): 4.0
Enter credit hours: 3

Do you have previous semester data to calculate CGPA? (y/n): y

Enter previous grade points: 45
Enter previous credits: 12

========================================
Individual Course Results:
Course: Calculus
Course: Physics
Course: Programming

----------------------------------------
Semester GPA: 3.72
Final CGPA: 3.81
========================================
```

---

# 📂 Project Structure

```text
CGPA-Calculator/
│
├── CodeAlpha_CGPA_Calculator.cpp
└── README.md
```

---

# 🧠 Challenges & Learning

While building this project, I practiced:

- Handling user input correctly with `getline()` and `cin.ignore()`
- Designing structured data using `struct`
- Working with vectors for dynamic course storage
- Formatting console output for readability
- Implementing GPA and CGPA calculation logic

---

# 🚀 Future Improvements

- Add grade validation
- Support letter grades (A+, A, B...)
- Export semester reports
- GUI version using SFML
- Save semester history

---

# 📜 Internship Information

Project completed as part of the **CodeAlpha C++ Programming Internship**.

---

## 👨‍💻 Author

**Kyrollos (KO2468)**

GitHub: <https://github.com/KO2468>
