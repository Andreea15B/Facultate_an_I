#include <vector>
#include <string>
using namespace std;

class GWindow {
public:
    virtual void Paint()=0;
    GWindow(int x, int y, int w, int h, string N); // N este string, numele componentei (P1, B1 etc)
    void Add(GWindow *obj);
protected:
    int x, y, w, h;
    string N;
    vector<GWindow*> objs;
};

class Panel : public GWindow {
public:
    void Paint() {}
    Panel(int x, int y, int w, int h, string N):GWindow(x,y,w,h,N){}
};

class Buton : public GWindow {
public:
    void Paint() {}
    Buton(int x, int y, int w, int h, string N):GWindow(x,y,w,h,N){}
};
