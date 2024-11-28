#ifndef READFILE_H
#define READFILE_H

#include <vector>
#include <string>

class ReadFile {
private:
    std::vector<std::vector<bool>> grid;
    int rows, cols;

public:
    ReadFile(int r, int c);

    void setCell(int i, int j, bool value);
    bool getCell(int i, int j) const;
    int getRows() const;
    int getCols() const;

    static ReadFile readFromFile(const std::string& filename);
    void display() const;
};

#endif // READFILE_H