#include "raylib.h"
#include "iostream"
#define SQUARE_SIZE 133
#define LINE_WIDTH 10

class Game {
public:
    Color BTN_COLOR = BLUE;
    Color BTN_HOVERED = DARKBLUE;
    Color BACKGROUND = {53, 170, 176, 255};

    enum SCREENS {MENU, GAME};
    int currentScreen;

    char human = 'x', comp = 'o';
    char grid[3][3] = {0};

    enum TURN {TURN_COMP, TURN_HUMAN};
    int turn = TURN_HUMAN;

    Texture2D crossTexture;
    Texture2D circleTexture;

    Rectangle gridRec = {160, 100, 409, 409};



    //logika

    //Zwraca 1 jeśli wygra komputer, -1 jeśli wygra człowiek, 0 jeśli remis i 2 jeśli gra się nie zakończyła
    int gameWon() {
        //checking rows
        for (int y = 0; y < 3; y++) {
            if( (grid[y][0] == grid[y][1]) && (grid[y][1] == grid[y][2]) ) {
                if (grid[y][0] == comp) return 1;
                if (grid[y][0] == human) return -1;
            }
        }
        //checking columns
        for (int x = 0; x < 3; x++) {
            if( (grid[0][x] == grid[1][x]) && (grid[1][x] == grid[2][x]) ) {
                if (grid[0][x] == comp) return 1;
                if (grid[0][x] == human) return -1;
            }
        }
        //checking diagonals
        if( (grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2]) ) {
            if (grid[0][0] == comp) return 1;
            if (grid[0][0] == human) return -1;
        }
        if( (grid[0][2] == grid[1][1]) && (grid[1][1] == grid[2][0]) ) {
            if (grid[1][1] == comp) return 1;
            if (grid[1][1] == human) return -1;
        }
        //checking if there are available spots
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                if(grid[y][x] == 0) return 0;
            }
        }
        //return 2 if it's a tie
        return 2;
    }

    //funkcja minimax wybiera najbardziej optymalny ruch
    int minimax(char board[3][3], int depth, bool isMaximizing) {
        int isWon = gameWon();
        if (isWon != 0) {
            return isWon;
        }

        if(isMaximizing) {
            int bestScore = -1000000;
            for (int y = 0; y < 3; y++) {
                for (int x = 0; x < 3; x++) {
                    //checks if spot is available
                    if(board[y][x] == 0) {
                        board[y][x] = comp;
                        int score = minimax(board, depth+1, false);
                        board[y][x] = 0;
                        if(score > bestScore) {
                            bestScore = score;
                        }
                    }
                }
            }
            return bestScore;
        } else {
            int lovestScore = 1000000;
            for (int y = 0; y < 3; y++) {
                for (int x = 0; x < 3; x++) {
                    //checks if spot is available
                    if(board[y][x] == 0) {
                        board[y][x] = human;
                        int score = minimax(board,depth+1, true);
                        board[y][x] = 0;
                        if(score < lovestScore) {
                            lovestScore = score;
                        }
                    }
                }
            }
            return lovestScore;
        }
    }

    //wykonuje ruch komputera
    void aiMove(char board[3][3]) {
        int bestScore = -1000000;
        int bestMove[2] = {0};
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++) {
                if(board[y][x] == 0) {
                    board[y][x] = comp;
                    int score = minimax(board, 0, false);
                    board[y][x] = 0;
                    if (score > bestScore) {
                        bestScore = score;
                        bestMove[0]  = y;
                        bestMove[1] = x;
                    }
                }
            }
        }
        grid[bestMove[0]][bestMove[1]] = comp;
        turn = TURN_HUMAN;
    }



    //funkcje UI
    void mainMenu(){

        auto mousePoint = GetMousePosition();

        Rectangle startRec = {230, 250, 250, 50};
        Rectangle exitRec = {300, 310, 110, 50};
        Color startBtnColor = BTN_COLOR;
        Color exitBtnColor = BTN_COLOR;

        // wykrywanie klików i zmienianie koloru jeżeli jest najechane
        if (CheckCollisionPointRec(mousePoint, startRec)) {
            startBtnColor = BTN_HOVERED;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                currentScreen = GAME;
            }
        }

        if (CheckCollisionPointRec(mousePoint, exitRec)) {
            exitBtnColor = BTN_HOVERED;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                CloseWindow();
            }
        }

        DrawRectangle(startRec.x, startRec.y, startRec.width, startRec.height, startBtnColor);
        DrawText("START GAME", startRec.x + 20, startRec.y + 10, 30, WHITE);

        DrawRectangle(exitRec.x, exitRec.y, exitRec.width, exitRec.height, exitBtnColor);
        DrawText("EXIT", exitRec.x + 20, exitRec.y + 10, 30, WHITE);


    }


// rysuje zagrane kółka i krzyżyki
    void populateGrid(){

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {

                int square = grid[i][j];
                Texture2D texture;

                // wybieramy jaki obrazek
                if(square == 0)
                    continue;
                else if (square == comp)
                    texture = circleTexture;
                else if (square == human)
                    texture = crossTexture;

                // gdzie obrazek sie powinien pojawić
                int x = gridRec.x + i * SQUARE_SIZE + 20 ;
                int y = gridRec.y + j * SQUARE_SIZE + 20 ;

                DrawTexture(texture, x, y, WHITE);

            }
        }
    }



// wykonanie ruchu przez jednego z graczy
    void play(int i, int j){
        grid[i][j] = human;
        turn = TURN_COMP;
        aiMove(grid);
    }

    void drawWinnerAndReset(int winner) {

        // rysuje kto wygrał
        std::string win_text;
        if (winner == 1) win_text = "Computer won!";
        if (winner == -1) win_text = "Human won!";
        if(winner == 2) win_text = "It's a tie!";

        DrawText(win_text.c_str(), gridRec.x + 15, 550, 60, WHITE);

        // rysuje przycisk reset
        Rectangle resetRec = {gridRec.x + 120, 630, 180, 50};
        Color btnColor = BTN_COLOR;
        auto mousePoint = GetMousePosition();

        if (CheckCollisionPointRec(mousePoint, resetRec)) {
            btnColor = BTN_HOVERED;
            if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {

                // tutaj dać funckje do resetowania (jak na razie po prostu czyśći array)
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        grid[i][j] = 0;
                    }
                }
            }
        }

        DrawRectangle(resetRec.x, resetRec.y, resetRec.width, resetRec.height, btnColor);
        DrawText("RESTART", resetRec.x + 20, resetRec.y + 10, 30, WHITE);

    }

    void drawKogoTura(){
        std::string turn_text = (turn == TURN_HUMAN) ? "your turn!" : "computers' turn!";
        DrawText(turn_text.c_str(), gridRec.x, 30, 30, WHITE);
    }

    void gameScreen(){

        // rysuje grid
        for (int i = 0; i < 4; ++i) {
            DrawRectangle(gridRec.x + i*SQUARE_SIZE, gridRec.y, LINE_WIDTH, gridRec.height, WHITE);
            DrawRectangle(gridRec.x , gridRec.y + i*SQUARE_SIZE, gridRec.width, LINE_WIDTH, WHITE);
        }

        drawKogoTura();

        // pojedyńcza kratka w gridzie
        Rectangle square = {gridRec.x + LINE_WIDTH,
                            gridRec.y + LINE_WIDTH,
                            SQUARE_SIZE - LINE_WIDTH,
                            SQUARE_SIZE - LINE_WIDTH};


        // wykrywa która kratka została kliknięta
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {

                Rectangle rec = square;
                rec.x += i * SQUARE_SIZE;
                rec.y += j * SQUARE_SIZE;
                auto mousePoint = GetMousePosition();

                if (CheckCollisionPointRec(mousePoint, rec)) {
                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                        play(i, j);
                        std::cout << i << j << " ";
                    }

                }
            }
        }

        // rysuje zagrane kółka i krzyżyki
        populateGrid();

        // tu podepnąc wykrywanie wygranej
        int winner = gameWon();
        if(winner) drawWinnerAndReset(winner);

    }

};



int main(void){

    //nowy obiekt klasy Game
    Game game;

    InitWindow(720, 720, "Tic Tac Toe");
    SetTargetFPS(60);

    // ładowanie tekstur
    Image circleImg = LoadImage("circle.png");
    Image crossImg = LoadImage("cross.png");
    ImageResize(&circleImg, 100, 100);
    ImageResize(&crossImg, 100, 100);
    game.circleTexture = LoadTextureFromImage(circleImg);
    game.crossTexture = LoadTextureFromImage(crossImg);
    UnloadImage(circleImg);
    UnloadImage(crossImg);

    game.currentScreen = game.MENU;

    // głowny loop
    while (!WindowShouldClose()) {

        BeginDrawing();

        switch (game.currentScreen) {
            case game.MENU:
                game.mainMenu();
                break;
            case game.GAME:
                game.gameScreen();
                break;
        }

        ClearBackground(game.BACKGROUND);

        EndDrawing();
    }

    // sprzątanie
    CloseWindow();

    return 0;
}
