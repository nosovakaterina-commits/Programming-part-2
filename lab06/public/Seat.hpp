#pragma once

class Seat {
public:
    explicit Seat(int count = 5);

    int getCount() const;
    bool isComfortable() const;
    
    void adjust();
    void clean();

private:
    int count_;
    bool comfortable_;
};