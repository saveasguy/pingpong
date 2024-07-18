#ifndef PINGPONG_BOX_H
#define PINGPONG_BOX_H

#include <ncurses.h>
#include <new>

namespace pingpong {

class Box final {
public:
    explicit Box(int x, int y, int width, int height);

    WINDOW *get() noexcept { return win_; }
    const WINDOW *get() const noexcept { return win_; }

    int x() const noexcept { return x_; }
    int y() const noexcept { return y_; }
    int width() const noexcept { return width_; }
    int height() const noexcept { return height_; }

    ~Box();

private:
    WINDOW *win_;
    int x_, y_, width_, height_;
};

void refresh(Box &box);

class NcursesWindowAllocationError : public std::bad_alloc {
public:
    const char *what() const throw() override;
};

}

#endif
