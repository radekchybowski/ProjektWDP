
Dokumentacja projektu - Kółko i Krzyżyk
=======================================

### Autorzy: Patrycja Gołdyś, Radosław Chybowski

### [Link do repozytorium](https://github.com/radekchybowski/ProjektWDP)

Opis aplikacji
--------------

Jest to prosta implementacja gry w kółko i krzyżyk pozwalająca na grę z komputerem. Po zakończeniu rozgrywki gracz zostaje poinformowany o wyniku gry i może rozpocząć kolejną partię oraz zapisać planszę do pliku board.txt w tej samej lokalizacji co uruchamiany plik. Program zamiast nadpisywać plik dopisuje do niego nowe plansze, pozwala więc trzymać historię rozgrywek.

Technikalia
-----------

GUI aplikacji i interakcja z użytkownikiem osiągniete zostały przy użyciu biblioteki graficznej **Raylib**. Wykorzystuje ona openGL do renderowania wyglądu aplikacji. Klatki i elementy na ekranie rysowane są 30 razy na sekundę. AI gra optymalnie, to znaczy nigdy nie przegrywa. Osiągnięte to zostało przy wykorzystaniu algorytmu minimax. Aktualny stan gry przechowywany jest w tablicy `char grid[3][3]`, ale z uwagi na fakt, że algorytm AI iteruje przez wszystkie możliwe kombinacje ruchów metody korzystają z własnego argumentu `char board[3][3]`, żeby nie wypisywać tych działań na ekranie.

Przedstawienie projektu
-----------------------

#### Po uruchomieniu gry użytkownika wita menu główne, pozwalające na rozpoczęcie gry lub zakończenie:

![](https://i.imgur.com/NmmfdKT.jpg)

#### Po naciśnięciu przycisku start game użytkownik widzi planszę 3x3 i może rozpocząć grę wybierając pole za pomocą lewego przycisku myszy:

![](https://i.imgur.com/QD8XObA.jpg)

#### W odpowiednim momencie gra oznajmia zakończenie i wynik gry:

![](https://i.imgur.com/EMgOBnn.jpg)

Instalacja zależności - biblioteka Raylib
-----------------------------------------

1.  [Strona biblioteki Raylib](https://www.raylib.com/)
2.  [Instrukcja konfiguracji dla VS Code](https://github.com/raysan5/raylib/wiki/Using-raylib-in-VSCode)
3.  **Opis instalacji dla CLion:**
    1.  Utwórz nowy projekt C++ Executable
    2.  Zastąp wygenerowany przez CLion plik CMakeLists plikiem z [repozytorium](https://github.com/radekchybowski/ProjektWDP/blob/main/CMakeLists.txt) 
    3.  Podmień argument w `project(projekt)` na nazwę folderu projektu.
    4.  Na windows usuń końcową część dedykowaną sprzętowi Apple.
    5.  Przekopiuj pliki cross.png i circle.png z repozytorium do katalogu `cmake-build-debug`.
    6.  Potwierdź że CLion zindeksował zmiany i zbuduj projekt.
4.  Alternatywnie można zainstalować raylib na systemie ściągając installer z oficjalnej strony raylib i zbudować projekt za pomocą komendy gcc main.cpp -lraylib -lopengl32.
    

#### Dziękujemy serdecznie za uwagę i poświęcony czas.

Wsprowadzenie do Programowania Projekt - Elektroniczne Przetwarzanie Informacji - Uniwersytet Jagielloński

Patrycja Gołdyś, Radosław Chybowski
