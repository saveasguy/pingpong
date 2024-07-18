#include "Box.h"

using namespace pingpong;

pingpong::Box::Box(int x, int y, int width, int height) : x_(x), y_(y), width_(width), height_(height) {
    win_ = newwin(y, x, height, width);
    if (!win_)
        throw std::bad_alloc();
}

pingpong::Box::~Box() {
    delwin(win_);
}

void pingpong::refresh(Box &box) {
    wrefresh(box.get());
}

const char *pingpong::NcursesWindowAllocationError::what() const throw() {
    return "ncurses failed to allocate the window";
}
