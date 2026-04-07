class Robot {
    int w, h, p, P;
    bool moved;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        P = 2 * (w + h - 2);
        p = 0;
        moved = false;
    }
    
    void step(int num) {
        p = (p + num) % P;
        moved = true;
    }
    
    vector<int> getPos() {
        if (p == 0) return {0, 0};
        if (p < w) return {p, 0};
        if (p < w + h - 1) return {w - 1, p - (w - 1)};
        if (p < 2 * w + h - 2) return {w - 1 - (p - (w + h - 2)), h - 1};
        return {0, h - 1 - (p - (2 * w + h - 3))};
    }
    
    string getDir() {
        if (p == 0) return moved ? "South" : "East";
        if (p < w) return "East";
        if (p < w + h - 1) return "North";
        if (p < 2 * w + h - 2) return "West";
        return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */