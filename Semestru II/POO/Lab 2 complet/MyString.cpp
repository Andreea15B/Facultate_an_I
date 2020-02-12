#include "MyString.h"
#include <cstring>
#include <iostream>

using namespace std;

MyString::MyString() {
    cout<<"Constructor 1\n";
    sir = new char[16];
    AllocatedSize = 16;
    Size = 0;
    sir[0]=0;
}
MyString::MyString(const char * text) {
    cout<<"Constructor 2\n";
    int len = strlen(text);
    sir = new char[len+1];
    AllocatedSize = Size = len+1;
    strcpy(sir,text);
}
MyString::~MyString() {
    cout<<"Destructor\n";
    delete sir;
}
void MyString::Set(const char *text) {
    int len = strlen(text);
    if(len>=AllocatedSize) {
        delete[] sir;
        sir = new char[len+1];
        AllocatedSize = len+1;
    }
    strcpy(sir,text);
    Size = len;
}
void MyString::Set(MyString &m) {
    int len = strlen(m.GetText());
    if(len >= AllocatedSize) {
        delete[] sir;
        sir = new char[len+1];
        AllocatedSize = len+1;
    }
    strcpy(sir,m.GetText());
    Size = len;
}
void MyString::Add(const char *text) {
    int len = strlen(text);
    //char tmp[strlen(sir)+1];
    char tmp[this->GetSize()];
    strcpy(tmp,sir);
    if(Size+len+1 > AllocatedSize) {
        delete[] sir;
        sir = new char[Size+len+1];
        AllocatedSize = Size+len+1;
        strcpy(sir,tmp);
    }
    strcat(sir,text);
    Size += len;
}
void MyString::Add(MyString &m) {
    Add(m.GetText());
}
MyString* MyString::SubString(unsigned int start, unsigned int Size) {
    int len = this->GetSize();
    if(start<0 || Size<0 || start+Size>len) return NULL;
    char tmp[Size + 1];
    int j=0;
    for(int i=start-1; i< start + Size-1; ++i) {
        tmp[j++] = sir[i];
    }
    tmp[j]=NULL;
    MyString c((const char *)tmp);
    return &c;
}
bool MyString::Delete(unsigned int start, unsigned int Size) {
    int len = this->GetSize();
    if(start<0 || Size<0 || start+Size>len) return false;
    strcpy (&sir[start-1], &sir[start + Size - 1]);
    return true;
}
int MyString::Compare(const char * text) {
    return strcmp(sir,text);
}
int MyString::Compare(MyString &m) {
    return strcmp(sir,m.GetText());
}
char MyString::GetChar(unsigned int index) {
    if(index>this->GetSize()) return 0;
    return sir[index-1];
}
bool MyString::Insert(unsigned int index, const char* text) {
    int lenSir = this->GetSize();
    int lenText = strlen(text);
    if(index<0 || index>lenSir) return false;
    char tmp[lenSir+lenText];
    strncpy(tmp,sir,index);
    strcpy(tmp+index,text);
    strcpy(tmp+index+lenText,sir+index+1);
    if(lenSir+lenText > AllocatedSize) {
        delete[] sir;
        sir = new char[lenSir+lenText];
        AllocatedSize = lenSir+lenText+1;
    }
    strcpy(sir,tmp);
    Size = lenSir+lenText;
    return true;
}
bool MyString::Insert(unsigned int index, MyString &m) {
    Insert(index,m.GetText());
}
int MyString::Find(const char * text) {
    char *p = strstr(sir, text);
    if(p!=NULL) return p-sir+1;
    return -1;
}
int MyString::FindLast(const char * text) {
    char *p;
    for(int i=this->GetSize()-1; i>=0; i--) {
        p = strstr(sir+i, text);
        if(p!=NULL) return p-sir+1;
    }
    return -1;
}
unsigned int MyString::GetSize() {
    return strlen(sir);
}
const char* MyString::GetText() {
    return sir;
}
