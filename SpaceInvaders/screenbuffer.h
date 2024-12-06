#pragma once

struct ScreenBuffer {
public:
    ScreenBuffer() : row_(0), col_(0), buffer_(nullptr) {}

    ScreenBuffer(int x, int y) : row_(x), col_(y), buffer_(nullptr) {
        buffer_ = new char* [row_];
        for (int i = 0; i < row_; ++i) {
            buffer_[i] = new char[col_];
        }
    };

    ~ScreenBuffer() {
        for (int i = 0; i < row_; ++i) {
            delete[] buffer_[i];
        }
        delete[] buffer_;
    }

    ScreenBuffer& operator=(const ScreenBuffer& other) // Copy Assignment Operator
{
    if (this == &other) {
        return *this;
    }

    // Deallocate existing memory
    for (int i = 0; i < row_; ++i) {
        delete[] buffer_[i];
    }
    delete[] buffer_;

    // Allocate memory for new data
    row_ = other.row_;
    col_ = other.col_;
    buffer_ = new char* [row_];
    for (int i = 0; i < row_; ++i) {
        buffer_[i] = new char[col_];
    }

    // Copy the data from other to this object
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            buffer_[i][j] = other.buffer_[i][j];
        }
    }
    return *this;
}

    char& GetChar(int row, int col) {
        return buffer_[row][col];
    }

    void SetChar(int row, int col, char value) {
        buffer_[row][col] = value;
    }

private:
    int row_;
    int col_;
    char** buffer_;
};
