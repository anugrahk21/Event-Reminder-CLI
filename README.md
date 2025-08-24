# Event Reminder CLI

A simple yet powerful Command Line Interface (CLI) application for managing events and reminders, developed as part of C++ and DSA training at CipherSchools.

## Overview

This Event Reminder CLI application helps users organize and remember important events through a terminal-based interface. The project demonstrates the practical application of fundamental programming concepts and data structures in C++.

## Features

- **Add Event**: Create new events with name, date, and optional notes
- **Remove Event**: Delete events by name
- **View All Events**: Display all upcoming events in chronological order
- **Search Event**: Find specific events by name
- **Edit Event**: Update existing event details
- **Input Validation**: Ensures valid dates and prevents duplicate event names

## Technical Implementation

### Data Structures Used
- **Linked Lists**: Events are stored as nodes in a singly linked list for dynamic memory management
- **Insertion Sort**: Maintains chronological order when adding new events
- **Linear Search**: Traverses the list to find events by name

### Key Programming Concepts
- Dynamic memory allocation (new/delete)
- Pointer manipulation for linked list operations
- Input validation and error handling
- Object-oriented design with classes

## How to Use

### Compilation
```bash
g++ -static event_reminder.cpp -o event_reminder.exe
```

### Running the Application
```bash
./event_reminder.exe
```

### Menu Options
1. **Add Event**: Enter event name, date (YYYY-MM-DD format), and optional note
2. **Remove Event**: Enter the name of the event to delete
3. **View All Events**: See all events sorted by date
4. **Search Event**: Find an event by its name
5. **Edit Event**: Modify an existing event's date and note
6. **Exit**: Close the application

### Date Format
All dates must be entered in YYYY-MM-DD format (e.g., 2025-12-25)

## Project Structure

```
Event-Reminder-CLI/
├── event_reminder.cpp    # Main application source code
├── event_reminder.exe    # Compiled executable
└── README.md            # Project documentation
```

## Code Features

- **Memory Management**: Proper allocation and deallocation to prevent memory leaks
- **Sorted Insertion**: Events are automatically placed in chronological order
- **Error Handling**: Comprehensive input validation and error messages
- **Clean Interface**: Simple, user-friendly command-line interface

## Learning Outcomes

This project demonstrates:
- Linked list implementation and manipulation
- Dynamic memory management in C++
- Algorithm implementation (sorting, searching)
- User input validation and error handling
- Object-oriented programming principles
- Command-line interface design

## Requirements

- C++ compiler (GCC/MinGW recommended)
- Windows/Linux/macOS terminal

## Future Enhancements

- Persistent data storage (file I/O)
- Event categories and priorities
- Recurring events support
- Email/notification reminders