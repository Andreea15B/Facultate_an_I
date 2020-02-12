#include "MyString.h"
#include "string.h"

MyString::MyString()
{
    cout << "Default Constructor." << endl;

    this->sir = new char[16];
    sir[0] = 0;

    AllocatedSize = 16;
    Size = 0;
}

MyString::MyString(const char * text)
{
    cout << "Explicit Constructor." << endl;

    int len = strlen(text);

    sir = new char[len+1];
    AllocatedSize = len+1;

    strcpy(sir, text);
    Size = len;
}

const char* MyString::GetText()
{
    return sir;
}

MyString::~MyString()
{
    cout << "Destructor." << endl;

    delete sir;
    sir = NULL;
    Size = AllocatedSize = 0;
}

unsigned int MyString::GetSize()
{
    return strlen(sir);
}

void MyString::Set(const char *text)
{
    int len = strlen(text);

    if(len >= AllocatedSize) {
        sir = new char[len+1];
        AllocatedSize = len+1;
    }

    strcpy(sir, text);
    Size = len;
}

void MyString::Set(MyString &m)
{
    int len = strlen(m.GetText());

    if(len >= AllocatedSize) {
        sir = new char[len+1];
        AllocatedSize = len+1;
    }

    strcpy(sir, m.GetText());
    Size = len;
}

void MyString::Add(const char *text)
{
    sir = new char[strlen(sir)+strlen(text)];
    strcat(sir,text);
    AllocatedSize = strlen(sir)+strlen(text);
}
