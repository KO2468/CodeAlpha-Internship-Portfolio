#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 9;
const int CELL_SIZE = 60;
const int WINDOW_WIDTH = 540;
const int WINDOW_HEIGHT = 620;

int grid[N][N] = { 0 };
bool original[N][N] = { false };

int selectedRow = -1;
int selectedCol = -1;
bool gameWon = false;

// Core Sudoku rule checker
bool isSafe(int board[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num || board[x][col] == num) return false;
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

// Solves/Fills layouts for generation
bool fillGrid(int board[N][N]) {
    int row = -1, col = -1;
    bool isEmpty = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) { row = i; col = j; isEmpty = true; break; }
        }
        if (isEmpty) break;
    }
    if (!isEmpty) return true;

    vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
    for (int i = 0; i < 9; i++) {
        int r = i + rand() % (9 - i);
        swap(nums[i], nums[r]);
    }

    for (int i = 0; i < 9; i++) {
        int num = nums[i];
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (fillGrid(board)) return true;
            board[row][col] = 0;
        }
    }
    return false;
}

// LIVE RULE CHECKER: Checks if a cell's number breaks rules against the current board state
bool breaksSudokuRules(int row, int col, int num) {
    if (num == 0) return false;

    // 1. Check Row conflict (ignoring itself)
    for (int c = 0; c < N; c++) {
        if (c != col && grid[row][c] == num) return true;
    }

    // 2. Check Column conflict (ignoring itself)
    for (int r = 0; r < N; r++) {
        if (r != row && grid[r][col] == num) return true;
    }

    // 3. Check 3x3 Box conflict (ignoring itself)
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            int currentRow = r + startRow;
            int currentCol = c + startCol;
            if ((currentRow != row || currentCol != col) && grid[currentRow][currentCol] == num) {
                return true;
            }
        }
    }

    return false; // No conflicts!
}

// Check if the board is completely full and has absolutely zero rule violations
bool checkWinCondition() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grid[r][c] == 0 || breaksSudokuRules(r, c, grid[r][c])) {
                return false;
            }
        }
    }
    return true;
}

void generatePuzzle() {
    gameWon = false;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            grid[r][c] = 0;
            original[r][c] = false;
        }
    }

    fillGrid(grid); // Generate complete valid board

    // Peel away 40 numbers to let the user play
    int cellsToRemove = 40;
    while (cellsToRemove > 0) {
        int r = rand() % N;
        int c = rand() % N;
        if (grid[r][c] != 0) {
            grid[r][c] = 0;
            cellsToRemove--;
        }
    }

    // Lock original clues
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            if (grid[r][c] != 0) original[r][c] = true;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    generatePuzzle();

    sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "SFML 3.1 Custom Sudoku Game");

    sf::Font font;
    bool hasFont = font.openFromFile("arial.ttf");

    sf::Text infoText(font);
    if (hasFont) {
        infoText.setCharacterSize(16);
        infoText.setFillColor(sf::Color::Black);
        infoText.setPosition(sf::Vector2f(15.f, 560.f));
        infoText.setString("Click a cell. Use 1-9 to play. Press [R] for a new puzzle.");
    }

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            else if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (!gameWon && mouseButton->button == sf::Mouse::Button::Left) {
                    int mx = mouseButton->position.x;
                    int my = mouseButton->position.y;

                    if (mx >= 0 && mx < WINDOW_WIDTH && my >= 0 && my < 540) {
                        selectedRow = my / CELL_SIZE;
                        selectedCol = mx / CELL_SIZE;
                    }
                }
            }

            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->code == sf::Keyboard::Key::R) {
                    generatePuzzle();
                    selectedRow = -1;
                    selectedCol = -1;
                    if (hasFont) {
                        infoText.setFillColor(sf::Color::Black);
                        infoText.setString("Click a cell. Use 1-9 to play. Press [R] for a new puzzle.");
                    }
                }

                if (!gameWon && selectedRow != -1 && selectedCol != -1 && !original[selectedRow][selectedCol]) {
                    int valueToSet = -1;

                    if (keyPressed->code >= sf::Keyboard::Key::Num1 && keyPressed->code <= sf::Keyboard::Key::Num9) {
                        valueToSet = static_cast<int>(keyPressed->code) - static_cast<int>(sf::Keyboard::Key::Num1) + 1;
                    }
                    else if (keyPressed->code >= sf::Keyboard::Key::Numpad1 && keyPressed->code <= sf::Keyboard::Key::Numpad9) {
                        valueToSet = static_cast<int>(keyPressed->code) - static_cast<int>(sf::Keyboard::Key::Numpad1) + 1;
                    }
                    else if (keyPressed->code == sf::Keyboard::Key::Backspace || keyPressed->code == sf::Keyboard::Key::Delete) {
                        valueToSet = 0;
                    }

                    if (valueToSet != -1) {
                        grid[selectedRow][selectedCol] = valueToSet;

                        if (checkWinCondition()) {
                            gameWon = true;
                            selectedRow = -1;
                            selectedCol = -1;
                            if (hasFont) {
                                infoText.setFillColor(sf::Color(0, 150, 0));
                                infoText.setString("CONGRATULATIONS! You solved the Sudoku completely!");
                            }
                        }
                    }
                }
            }
        }

        window.clear(sf::Color(240, 240, 240));

        // DRAW BOX SQUARES
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                sf::RectangleShape cell(sf::Vector2f(static_cast<float>(CELL_SIZE - 1), static_cast<float>(CELL_SIZE - 1)));
                cell.setPosition(sf::Vector2f(static_cast<float>(c * CELL_SIZE), static_cast<float>(r * CELL_SIZE)));

                if (r == selectedRow && c == selectedCol) {
                    cell.setFillColor(sf::Color(210, 230, 250));
                }
                else if (original[r][c]) {
                    cell.setFillColor(sf::Color(235, 235, 235));
                }
                else {
                    cell.setFillColor(sf::Color::White);
                }
                window.draw(cell);

                // RENDER TYPED OR GENERATED DIGITS
                if (grid[r][c] != 0 && hasFont) {
                    sf::Text numText(font);
                    numText.setString(to_string(grid[r][c]));
                    numText.setCharacterSize(28);

                    if (original[r][c]) {
                        numText.setFillColor(sf::Color(20, 50, 150));
                        numText.setStyle(sf::Text::Bold);
                    }
                    else {
                        // Dynamic checking: ONLY turn red if it actively breaks a rule on the board!
                        if (breaksSudokuRules(r, c, grid[r][c])) {
                            numText.setFillColor(sf::Color(220, 0, 0)); // Visual rule conflict
                            numText.setStyle(sf::Text::Bold);
                        }
                        else {
                            numText.setFillColor(sf::Color::Black); // Otherwise, standard clean play state
                        }
                    }

                    numText.setPosition(sf::Vector2f(static_cast<float>(c * CELL_SIZE + 22), static_cast<float>(r * CELL_SIZE + 10)));
                    window.draw(numText);
                }
            }
        }

        // GRID BORDERS
        for (int i = 0; i <= 9; i++) {
            sf::RectangleShape line;
            float thickness = (i % 3 == 0) ? 4.f : 1.f;

            line.setSize(sf::Vector2f(thickness, 540.f));
            line.setPosition(sf::Vector2f(static_cast<float>(i * CELL_SIZE) - (thickness / 2.f), 0.f));
            line.setFillColor(sf::Color::Black);
            window.draw(line);

            line.setSize(sf::Vector2f(540.f, thickness));
            line.setPosition(sf::Vector2f(0.f, static_cast<float>(i * CELL_SIZE) - (thickness / 2.f)));
            line.setFillColor(sf::Color::Black);
            window.draw(line);
        }

        if (hasFont) {
            window.draw(infoText);
        }

        window.display();
    }

    return 0;
}