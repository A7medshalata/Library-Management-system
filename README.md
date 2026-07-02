# Library Management System

A comprehensive C++ Object-Oriented Programming (OOP) application designed to manage a book library ecosystem. This system features user authentication and provides tailored interfaces (views) for both administrative staff (Librarians) and library members (Customers) to seamlessly manage books, tracking, and borrowing operations.

## 🚀 Features

### 👤 User Authentication & Roles
* [cite_start]**Dual-View System:** Separate dashboards and functionalities for Librarians and Customers[cite: 15].
* [cite_start]**Secure Sign-In:** Credentials verification using User ID, username, and password[cite: 8].

### 🔑 Librarian Capabilities (Admin)
* [cite_start]**User Management:** Add and remove customers, and view customer profiles along with their currently borrowed books[cite: 10].
* [cite_start]**Inventory Management:** Add new books to the library system or remove existing ones[cite: 5, 11].
* [cite_start]**Advanced Tracking:** View all books, track borrowed/unborrowed inventories, and search books by Title, Author, or Category[cite: 11, 12].

### 📖 Customer Capabilities
* [cite_start]**Catalog Browsing:** View available books and search the catalog by Title, Author, or Category[cite: 2, 13].
* [cite_start]**Flexible Search:** Case-insensitive, substring-matching search engine[cite: 16].
* [cite_start]**Borrow & Return:** Borrow books (up to a limit of 5 concurrent books) and return them to the library[cite: 14, 17].

---

## 🛠️ System Architecture & Code Design

[cite_start]The project is structured according to clean Object-Oriented Programming principles, emphasizing encapsulation, inheritance, polymorphism, and abstraction[cite: 20].

### Class Structure
1.  [cite_start]**Book:** Stores book metadata including title, author, category (Fiction, Romance, Children, Non-fiction, Horror, History), and availability status.
2.  [cite_start]**Library:** Manages the compilation of books using robust array storage and handles core search filter mechanisms.
3.  [cite_start]**User (Base Class):** Encapsulates core user data (ID, username, password).
4.  [cite_start]**Librarian (Derived Class):** Inherits from `User` to inject administrative control logic.
5.  [cite_start]**Customer (Derived Class):** Inherits from `User` to handle client-side borrowing constraints and records.

### Highlights
* [cite_start]**Robustness:** Implements comprehensive C++ Exception Handling to prevent runtime crashes[cite: 25].
* [cite_start]**Modular Design:** Clean separation of concerns with code cleanly organized into distinct header (`.h`) and source (`.cpp`) files.

---

## 📂 Directory Structure

[cite_start]All implementation files are organized within a single source directory as follows[cite: 18, 30]:
```text
├── SRC/                  # Contains all C++ source (.cpp) and header (.h) files
├── README.txt            # User manual with execution steps and team info
└── contribution.txt      # Team workload distribution and roles documentation
