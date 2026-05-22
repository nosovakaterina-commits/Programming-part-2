#pragma once

class Wheel {
public:
    explicit Wheel(int count = 4);

    int getCount() const;
    bool isIntact() const;
    
    void rotate();
    void repair();

private:
    int count_;
    bool intact_;
};