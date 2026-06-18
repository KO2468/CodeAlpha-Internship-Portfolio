# 🏦 Banking System (C++)

A console-based banking management system developed in C++ that simulates customer registration, account management, transactions, and account statements.

---

# 📌 Features

✔ Register new customers  
✔ Create multiple bank accounts  
✔ Deposit and withdraw funds  
✔ Transfer money between accounts  
✔ Track transaction history  
✔ View account statements  
✔ Dynamic customer and account management  

---

# 🛠 Technologies Used

- **Language:** C++
- **Standard:** Latest C++ Standard
- **Core Concepts:**
  - Object-Oriented Programming (OOP)
  - Classes & Encapsulation
  - Dynamic Storage (`vector`)
  - Transaction Tracking
  - Console Interface Design

---

# 🧱 System Architecture

```text
Customer
│
├── Account
│     ├── Balance
│     ├── Deposit
│     ├── Withdraw
│     └── Transactions
│
└── Multiple Accounts

Transaction
├── Type
├── Amount
└── Details
```

---

# ⚙ System Workflow

```text
Start
 │
 ├── Register Customer
 │
 ├── Create Account
 │
 ├── Deposit
 │
 ├── Withdraw
 │
 ├── Transfer Funds
 │
 └── View Statement
```

---

# 💳 Banking Operations

### Customer Registration

Create customer profiles with:

- Full Name
- Automatically generated Customer ID

---

### Account Management

Customers can:

- Open accounts
- Store balances
- Manage transactions

---

### Transactions

Supported operations:

✔ Deposit  
✔ Withdrawal  
✔ Transfer  

Every operation is recorded in transaction history.

---

# ▶ Example Usage

```text
=================================
       APEX BANKING SYSTEM
=================================

1. Register New Customer
2. Open New Account
3. Deposit
4. Withdraw
5. Transfer Funds
6. View Statement
7. Exit
```

Example transfer:

```text
Enter Source Account:
1001

Enter Destination Account:
1002

Enter Amount:
250

[SUCCESS] Transfer complete.
```

Statement:

```text
Account Number: 1001
Current Balance: $1250.00

Type            | Amount      | Details
------------------------------------------------
Deposit          | $500.00     | Self Deposit
Transfer Out     | $250.00     | Transfer to #1002
```

---

# 📂 Project Structure

```text
Banking-System/
│
├── CodeAlpha_Banking_System.cpp
└── README.md
```

---

# ▶ Build & Run

Compile:

```bash
g++ CodeAlpha_Banking_System.cpp -std=c++23
```

Run:

```bash
./program
```

---

# 🧠 Concepts Practiced

Through this project I strengthened understanding of:

- OOP design
- Class relationships
- State management
- Transaction systems
- Data modeling
- Financial operation logic
- Working with vectors and objects

---

# 🚀 Future Improvements

- Persistent database storage
- User authentication
- Account deletion
- Interest calculations
- Monthly statements
- GUI interface using SFML
- Export transaction reports

---

## 👨‍💻 Author

**Kyrollos (KO2468)**

GitHub: <https://github.com/KO2468>
