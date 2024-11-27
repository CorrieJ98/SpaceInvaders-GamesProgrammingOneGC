#pragma once

struct ScreenBuffer {
public:
	ScreenBuffer() : row_(0), col_(0), buffer_(nullptr) {}
	ScreenBuffer(int x, int y) : row_(x), col_(y) {
		buffer_ = new char* [row_];			// ahhh this is probably bad
		for (int i = 0; i < row_; ++i) {
			buffer_[i] = new char[col_];	// and this!!
		}
	};

	~ScreenBuffer() {
		for (int i = 0; i < row_; ++i) {
			delete[] buffer_[i];
		}

		delete[] buffer_;
	}

	// Move Assignment
	ScreenBuffer& operator=(ScreenBuffer&& other) noexcept {
		// check if both objects match
		if (this == &other) {
			return *this;
		}

		// deallocate existing memory
		for (int i = 0; i < row_; ++i) {
			delete[] buffer_[i];
		}
		delete[] buffer_;

		// Transfer ownership
		row_ = other.row_;
		col_ = other.col_;
		buffer_ = other.buffer_;

		// Reset source object
		other.row_ = 0;
		other.col_ = 0;
		other.buffer_ = nullptr;
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