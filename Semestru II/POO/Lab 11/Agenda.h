//
//
//  Generated by StarUML(tm) C++ Add-In
//
//  @ Project : Untitled
//  @ File Name : Agenda.h
//  @ Date : 16-May-18
//  @ Author : 
//
//


#if !defined(_AGENDA_H)
#define _AGENDA_H


class Agenda {
public:
	list<Contact*> contact;
	Contact* SearchContact(string nume_contact);
	bool AddContact(Contact* info_contact);
	bool DeleteContact(Contact* info_contact);
	list<Contact*> ReturnListaContact();
};

#endif  //_AGENDA_H