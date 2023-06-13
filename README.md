<!DOCTYPE html>
<html>
<head>
  <meta charset="UTF-8" />
  <meta name="author" content="Patrycja Gołdyś, Radosław Chybowski">
  <title>WDP Projekt - dokumentacja</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-9ndCyUaIbzAi2FUVXJi0CjmCapSmO7SnpJef0486qhLnuZ2cdeRhO02iuK6FUUVM" crossorigin="anonymous">
</head>
<body class="container">
  <div class="row">
    <div class="col-md-8 mx-auto">
      <header>
        <h1 class="my-4">Dokumentacja projektu - Kółko i Krzyżyk</h1>
        <h3 class="my-3">Autorzy: Patrycja Gołdyś, Radosław Chybowski</h2>
          <h3 class="mb-5"><a href="https://github.com/radekchybowski/ProjektWDP">Link do repozytorium</h3></a>
      </header>
      <main>
        <h2>Opis aplikacji</h2>
        <p>Jest to prosta implementacja gry w kółko i krzyżyk pozwalająca na grę z komputerem. Po zakończeniu rozgrywki gracz zostaje poinformowany o wyniku gry i może rozpocząć kolejną partię oraz zapisać planszę do pliku board.txt w tej samej lokalizacji co uruchamiany plik. Program zamiast nadpisywać plik dopisuje do niego nowe plansze, pozwala więc trzymać historię rozgrywek.</p>
        
        <h2>Technikalia</h2>
        <p>GUI aplikacji i interakcja z użytkownikiem osiągniete zostały przy użyciu biblioteki graficznej <b>Raylib</b>. Wykorzystuje ona openGL do renderowania wyglądu aplikacji. Klatki i elementy na ekranie rysowane są 30 razy na sekundę. AI gra optymalnie, to znaczy nigdy nie przegrywa. Osiągnięte to zostało przy wykorzystaniu algorytmu minimax. Aktualny stan gry przechowywany jest w tablicy <code>char grid[3][3]</code>, ale z uwagi na fakt, że algorytm AI iteruje przez wszystkie możliwe kombinacje ruchów metody korzystają z własnego argumentu <code>char board[3][3]</code>, żeby nie wypisywać tych działań na ekranie.</p>

        <h2>Przedstawienie projektu</h2>
        <h4>Po uruchomieniu gry użytkownika wita menu główne, pozwalające na rozpoczęcie gry lub zakończenie:</h4>
        <img src="https://i.imgur.com/NmmfdKT.jpg"/>
        <h4>Po naciśnięciu przycisku start game użytkownik widzi planszę 3x3 i może rozpocząć grę wybierając pole za pomocą lewego przycisku myszy:</h4>
        <img src="https://i.imgur.com/QD8XObA.jpg"/>
        <h4>W odpowiednim momencie gra oznajmia zakończenie i wynik gry:</h4>
        <img src="https://i.imgur.com/EMgOBnn.jpg"/>
    
        <h2>Instalacja zależności - biblioteka Raylib</h2>
        <ol>
          <li>
            <a href="https://www.raylib.com/">Strona biblioteki Raylib</a>
          </li>
          <li>
            <a href="https://github.com/raysan5/raylib/wiki/Using-raylib-in-VSCode">Instrukcja konfiguracji dla VS Code</a>
          </li>
          <li>
            <b>Opis instalacji dla CLion:</b> 
            <ol>
              <li>Utwórz nowy projekt C++ Executable</li>
              <li>
                W pliku <i>CMakeLists.txt</i> zaznacz wszystko i wklej poniższy kod:
                <pre class="pre-scrollable" style="height: 400px;">
cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(projekt)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 4.5.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            DOWNLOAD_EXTRACT_TIMESTAMP OFF
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# Our Project

add_executable(${PROJECT_NAME} main.cpp)
#set(raylib_VERBOSE 1)
target_link_libraries(${PROJECT_NAME} raylib)

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an reelib.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif()

# Checks if OSX and links appropriate frameworks (Only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
    add_definitions('-std=c++11')
endif()
                </pre>
              </li>
              <li>
                Podmień argument w <code>project(projekt)</code> na nazwę folderu projektu.
              </li>
              <li>
                Przekopiuj pliki cross.png i circle.png z repozytorium do katalogu <code>cmake-build-debug</code>.
              </li>
              <li>
                Potwierdź że CLion zindeksował zmiany i zbuduj projekt.
              </li>
            </ol>

          </li>
          <li>
            <p>Alternatywnie można zainstalować raylib na systemie ściągając installer z oficjalnej strony raylib i zbudować projekt za pomocą komendy gcc main.cpp -lraylib -lopengl32.</p>
          </li>
        </ol>
        <h4 class="my-5">Dziękujemy serdecznie za uwagę i poświęcony czas.</h4>
      </main>
      <footer>
        <p>Wsprowadzenie do Programowania Projekt - Elektroniczne Przetwarzanie Informacji - Uniwersytet Jagielloński</p>
        <p>Patrycja Gołdyś, Radosław Chybowski</p>
      </footer>
    </div>
  </div>
  
  
  
</body>
</html>
