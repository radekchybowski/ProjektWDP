  WDP Projekt - dokumentacja  img { max-width: 400px; border-radius: 10px; margin-bottom: 15px; } footer { text-align: center; background-color: rgb(217, 217, 217); border-radius: 10px; padding: 10px; margin-bottom: 10px; }

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
    2.  W pliku _CMakeLists.txt_ zaznacz wszystko i wklej poniższy kod:
        
        cmake\_minimum\_required(VERSION 3.11) # FetchContent is available in 3.11+
        project(projekt)
        
        # Generate compile\_commands.json
        set(CMAKE\_EXPORT\_COMPILE\_COMMANDS ON)
        
        # Dependencies
        set(RAYLIB\_VERSION 4.5.0)
        find\_package(raylib ${RAYLIB\_VERSION} QUIET) # QUIET or REQUIRED
        if (NOT raylib\_FOUND) # If there's none, fetch and build raylib
            include(FetchContent)
            FetchContent\_Declare(
                    raylib
                    DOWNLOAD\_EXTRACT\_TIMESTAMP OFF
                    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB\_VERSION}.tar.gz
            )
            FetchContent\_GetProperties(raylib)
            if (NOT raylib\_POPULATED) # Have we downloaded raylib yet?
                set(FETCHCONTENT\_QUIET NO)
                FetchContent\_Populate(raylib)
                set(BUILD\_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
                add\_subdirectory(${raylib\_SOURCE\_DIR} ${raylib\_BINARY\_DIR})
            endif()
        endif()
        
        # Our Project
        
        add\_executable(${PROJECT\_NAME} main.cpp)
        #set(raylib\_VERBOSE 1)
        target\_link\_libraries(${PROJECT\_NAME} raylib)
        
        # Web Configurations
        if (${PLATFORM} STREQUAL "Web")
            # Tell Emscripten to build an reelib.html file.
            set\_target\_properties(${PROJECT\_NAME} PROPERTIES SUFFIX ".html")
        endif()
        
        # Checks if OSX and links appropriate frameworks (Only required on MacOS)
        if (APPLE)
            target\_link\_libraries(${PROJECT\_NAME} "-framework IOKit")
            target\_link\_libraries(${PROJECT\_NAME} "-framework Cocoa")
            target\_link\_libraries(${PROJECT\_NAME} "-framework OpenGL")
            add\_definitions('-std=c++11')
        endif()
                        
        
    3.  Podmień argument w `project(projekt)` na nazwę folderu projektu.
    4.  Przekopiuj pliki cross.png i circle.png z repozytorium do katalogu `cmake-build-debug`.
    5.  Potwierdź że CLion zindeksował zmiany i zbuduj projekt.
4.  Alternatywnie można zainstalować raylib na systemie ściągając installer z oficjalnej strony raylib i zbudować projekt za pomocą komendy gcc main.cpp -lraylib -lopengl32.
    

#### Dziękujemy serdecznie za uwagę i poświęcony czas.

Wsprowadzenie do Programowania Projekt - Elektroniczne Przetwarzanie Informacji - Uniwersytet Jagielloński

Patrycja Gołdyś, Radosław Chybowski
