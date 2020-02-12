#include <string>
using namespace std;

class Log {
private:
    Log();
    ~Log();
    string fname;
    static Log* instanta;
public:
    static Log* GetInstance();
    void changeFileName(string N);
    void DebugMsg(string msg);
};

Log* Log::instanta = 0;

class GVisitor {
public:
    virtual void visit(GWindow*) = 0;
};

class PanelVisitor : public GVisitor {
public:
    virtual void visit(GWindow*) {Log.GetInstance()->DebugMsg("PanelVisitor");}
};

class ButonVisitor : public GVisitor {
public:
    virtual void visit(GWindow*);
};
