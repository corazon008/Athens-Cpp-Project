cmake_minimum_required(VERSION 3.31)
project(Project)

set(CMAKE_CXX_STANDARD 23)

# Définition des fichiers sources communs
set(SOURCES
        src/Card.cpp
        src/CardDisplay.cpp
        src/Cards/Distance.cpp
        src/Cards/Hazards.cpp
        src/Cards/Remedies.cpp
        src/Cards/Safeties.cpp
)

set(TESTS
        test/CardDisplayTest.cpp
)

add_executable(Project main.cpp ${SOURCES})

add_executable(Test test/main.cpp ${SOURCES})