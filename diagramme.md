```mermaid

---
title Diagramme de Classes - Jeu de la Vie
---
classDiagram
    class Grid {
        -int width
        -int height
        - vector<vector<Cell>> cells
        -bool isToric
        -int countNeighbors(int x, int y)
        +Grid(int width, int height)
        +update()
        +getWidth() int
        +getHeight() int
        +isAlive(int x, int y) bool
        +setAlive(int x, int y, bool alive)
    }
    
    class Cell {
        -bool alive
        -bool fixed
        +Cell()
        +setAlive(bool status)
        +isAlive() bool
    }
    
    class File {
        -string filename
        -int width
        -int height
        +File(string filename)
        +readFile() Grid
        +writeFile(Grid grid)
    }
    
    class GraphicDisplay {
        -const int cellSize
        +GraphicDisplay()
        +renderGrid(RenderWindow &window, const Grid &grid)
    }
    
    Grid "1" *-- "many" Cell : contains
    File --> Grid : creates/reads
    GraphicDisplay --> Grid : renders
    ```