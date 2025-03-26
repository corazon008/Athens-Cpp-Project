cmake_minimum_required(VERSION 3.31)
project(Project)

set(CMAKE_CXX_STANDARD 23)

add_compile_options(-Wall -pedantic -Wno-long-long -O0)

# Définition des fichiers sources communs
set(SOURCES
        src/Game.cpp
        src/Utils/Utils.cpp
)

set(Player
        src/Player/Player.cpp
        src/Player/Deck.cpp
)
set(CARDS
        src/Cards/Card.cpp
        src/Cards/CardDisplay.cpp
        src/Cards/CardType/Distance.cpp
        src/Cards/CardType/Hazards.cpp
        src/Cards/CardType/Remedies.cpp
        src/Cards/CardType/Safeties.cpp
)

set(TESTS
        test/CardDisplayTest.cpp
)

add_executable(Project src/main.cpp ${SOURCES} ${Player} ${CARDS})

add_executable(Test test/main.cpp ${SOURCES} ${Player} ${CARDS})

add_executable(TestFile test/testFile.cpp)