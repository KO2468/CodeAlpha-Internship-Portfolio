# 🔐 Login & Registration System (C++)

A secure console-based authentication system built in C++ that allows users to register accounts, log in, and access a simple user dashboard.

This project was developed as part of the **CodeAlpha C++ Programming Internship** and focuses on authentication logic, file handling, hashing concepts, and modular program design.

---

# 📌 Features

✔ User registration system  
✔ Secure password hashing before storage  
✔ Duplicate username detection  
✔ Login authentication  
✔ Persistent user database using file storage  
✔ Logged-in dashboard interface  
✔ Account information display  
✔ Session logout system  

---

# 🛠 Technologies Used

- **Language:** C++
- **Standard:** Latest C++ Standard
- **Storage:** Text File Database (`users.txt`)
- **Core Concepts:**
  - File Handling
  - Hashing
  - Authentication Logic
  - Functions & Modularity
  - Console UI

---

# ⚙ System Workflow

```text
Start
 │
 ├── Register
 │     ├── Check duplicate username
 │     ├── Validate password
 │     └── Save hashed credentials
 │
 └── Login
       ├── Read stored users
       ├── Hash entered password
       ├── Verify credentials
       └── Open dashboard
```

---

# 🔒 Security Features

### Password Hashing

Passwords are not stored directly.

Instead:

```text
User Password
      ↓
Hash Function
      ↓
Stored Hashed Value
```

This reduces direct exposure of credentials.

### Duplicate Prevention

The system scans existing users before creating new accounts.

### Authentication Verification

Login succeeds only if:

- Username exists
- Password hash matches stored data

---

# ▶ Example Usage

```text
=================================
        SECURE ACCESS SYSTEM
=================================

1. Register New User
2. Login to Existing Account
3. Close System

Enter your choice: 1
```

Registration:

```text
Enter username:
kero

Enter password:
secure123

[SUCCESS] Registration successful!
```

Login:

```text
Enter username:
kero

Enter password:
secure123

[SUCCESS] Credentials verified.
```

Dashboard:

```text
WELCOME BACK, KERO!

1. View Profile Details
2. Account Status
3. Secure Logout
```

---

# 📂 Project Structure

```text
Login-Registration-System/
│
├── CodeAlpha_Login_and_Registration_System.cpp
├── users.txt
└── README.md
```

---

# ▶ Build & Run

Compile:

```bash
g++ CodeAlpha_Login_and_Registration_System.cpp -std=c++23
```

Run:

```bash
./program
```

---

# 🧠 Concepts Practiced

This project helped strengthen understanding of:

- File-based databases
- User authentication systems
- Password hashing concepts
- Program modularization
- Secure credential storage ideas
- Designing user workflows

---

# 🚀 Future Improvements

- Hidden password input
- Strong password requirements
- Password reset
- Account deletion
- Encryption instead of basic hashing
- GUI version using SFML
- Multi-user account management

---

# 📜 Internship Information

Project completed as part of the **CodeAlpha C++ Programming Internship**.

---

## 👨‍💻 Author

**Kyrollos (KO2468)**

GitHub: <https://github.com/KO2468>
