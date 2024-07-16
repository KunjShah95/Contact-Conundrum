# Contact-Conundrum
# C++ Multi-Purpose Utility App

This C++ application provides a simple and user-friendly interface for managing contacts and playing Tic-Tac-Toe.

## Features

* **Contact Management:**
    * **Add Contact:** Allows users to add new contacts with their first name, last name, phone number, and email address.
    * **Display Contacts:** Displays all the contacts stored in the application.
    * **Search Contact:** Enables users to search for a specific contact by their first name and last name.
    * **Delete Contact:** Allows users to delete a contact by their first name and last name.
* **Tic-Tac-Toe:**
    * **Play Game:** Provides a classic Tic-Tac-Toe game for two players.
    * **Win Detection:** Automatically detects if a player has won or if the game is a draw.
    * **Board Reset:** Resets the game board for a new game.

## Usage

1. **Compile:** Compile the `APP.CPP` file using a C++ compiler (e.g., g++).
2. **Run:** Execute the compiled executable file.
3. **Interact:** Follow the on-screen menu prompts to add, display, search, delete contacts, or play Tic-Tac-Toe.

## Code Structure

The code is organized into several functions:

* **`addContact(std::vector<Contact> &contacts)`:** Adds a new contact to the `contacts` vector.
* **`displayContacts(const std::vector<Contact> &contacts)`:** Displays all contacts in the `contacts` vector.
* **`searchContact(const std::vector<Contact> &contacts)`:** Searches for a contact in the `contacts` vector.
* **`deleteContact(std::vector<Contact> &contacts)`:** Deletes a contact from the `contacts` vector.
* **`drawBoard(const std::vector<std::vector<char>> &board)`:** Draws the Tic-Tac-Toe board.
* **`checkWin(const std::vector<std::vector<char>> &board, char player)`:** Checks if a player has won the Tic-Tac-Toe game.
* **`checkDraw(const std::vector<std::vector<char>> &board)`:** Checks if the Tic-Tac-Toe game is a draw.
* **`main()`:** The main function that handles the user interface and game logic.

## Contributing

Contributions are welcome! Feel free to fork the repository and submit pull requests for bug fixes, feature enhancements, or improvements to the code.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
