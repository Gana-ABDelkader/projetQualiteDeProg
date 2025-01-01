@echo off
REM Compilation du programme
g++.exe -g main.cpp position.cpp manipulate.cpp observateur.cpp operateursGlobaux.cpp read.cpp readVector.cpp robot.cpp terrain.cpp algoMainDroite.cpp algoPledge.cpp caractereLabyrinthe.cpp lancementProgramme.cpp direction.cpp save.cpp testCasesVector.cpp -o main.exe

REM Vérification si la compilation a réussi
if %errorlevel% neq 0 (
    echo Erreur lors de la compilation.
    pause
    exit /b
)

REM Exécution du programme
main.exe
pause
