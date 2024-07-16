#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Define the Contact structure
struct Contact {
    std::string firstName;
    std::string lastName;
    std::string phone;
    std::string email;
};

// Function to add a contact to the list
void addContact(std::vector<Contact> &contacts) {
    Contact newContact;
    std::cout << "Enter first name: ";
    std::cin >> newContact.firstName;

    std::cout << "Enter last name: ";
    std::cin >> newContact.lastName;

    std::cout << "Enter phone: ";
    std::cin.ignore(); // Consume the newline character left in the buffer
    std::getline(std::cin, newContact.phone); // Read the phone number on a new line

    std::cout << "Enter email: ";
    std::getline(std::cin, newContact.email); // Read the email on a new line

    contacts.push_back(newContact);
    std::cout << "Contact added." << std::endl;
}

// Function to display all contacts
void displayContacts(const std::vector<Contact> &contacts) {
    if (contacts.empty()) {
        std::cout << "No contacts found." << std::endl;
        return;
    }
    for (const auto &contact : contacts) {
        std::cout << "First Name: " << contact.firstName << std::endl;
        std::cout << "Last Name: " << contact.lastName << std::endl;
        std::cout << "Phone: " << contact.phone << std::endl;
        std::cout << "Email: " << contact.email << std::endl;
        std::cout << std::endl; // Add an extra line between contacts
    }
}

// Function to search for a contact by first name and last name
void searchContact(const std::vector<Contact> &contacts) {
    std::string firstName, lastName;
    std::cout << "Enter first name to search: ";
    std::cin >> firstName;
    std::cout << "Enter last name to search: ";
    std::cin >> lastName;

    auto it = std::find_if(contacts.begin(), contacts.end(),
                           [&firstName, &lastName](const Contact &contact) {
                               return contact.firstName == firstName && contact.lastName == lastName;
                           });

    if (it != contacts.end()) {
        const Contact &foundContact = *it;
        std::cout << "First Name: " << foundContact.firstName << std::endl;
        std::cout << "Last Name: " << foundContact.lastName << std::endl;
        std::cout << "Phone: " << foundContact.phone << std::endl;
        std::cout << "Email: " << foundContact.email << std::endl;
    } else {
        std::cout << "Contact not found." << std::endl;
    }
}

// Function to delete a contact by first name and last name
void deleteContact(std::vector<Contact> &contacts) {
    std::string firstName, lastName;
    std::cout << "Enter first name of contact to delete: ";
    std::cin >> firstName;
    std::cout << "Enter last name of contact to delete: ";
    std::cin >> lastName;

    auto it = std::remove_if(contacts.begin(), contacts.end(),
                            [&firstName, &lastName](const Contact &contact) {
                                return contact.firstName == firstName && contact.lastName == lastName;
                            });

    if (it != contacts.end()) {
        contacts.erase(it, contacts.end());
        std::cout << "Contact deleted." << std::endl;
    } else {
        std::cout << "Contact not found." << std::endl;
    }
}

// Function to draw the Tic-Tac-Toe board
void drawBoard(const std::vector<std::vector<char>> &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a player has won
bool checkWin(const std::vector<std::vector<char>> &board, char player) {
    // Check rows and columns for a win
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals for a win
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check if the game is a draw
bool checkDraw(const std::vector<std::vector<char>> &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<Contact> contacts;
    std::vector<std::vector<char>> board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    int choice;

    while (true) {
        std::cout << "\n1. Add Contact" << std::endl;
        std::cout << "2. Display Contacts" << std::endl;
        std::cout << "3. Search Contact" << std::endl;
        std::cout << "4. Delete Contact" << std::endl;
        std::cout << "5. Play Tic-Tac-Toe" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                displayContacts(contacts);
                break;
            case 3:
                searchContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5: {
                bool gameOver = false;
                while (!gameOver) {
                    std::cout << "\nTic-Tac-Toe\n";
                    drawBoard(board);
                    int row, col;
                    std::cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
                    std::cin >> row >> col;

                    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
                        board[row][col] = currentPlayer;
                        if (checkWin(board, currentPlayer)) {
                            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                            gameOver = true;
                        } else if (checkDraw(board)) {
                            std::cout << "It's a draw!" << std::endl;
                            gameOver = true;
                        } else {
                            currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
                        }
                    } else {
                        std::cout << "Invalid move, try again." << std::endl;
                    }
                }
                // Reset the board for a new game
                board = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
                currentPlayer = 'X';
                break;
            }
            case 6:
                std::cout << "Exiting..." << std::endl;
                return 0; // Exit the program
            default:
                std::cout << "Invalid choice, try again." << std::endl;
                break;
        }
    }

    return 0;
}
