#include <cstdlib>
#define DMAX 256

class BigNumber {

   private:

      char Number[DMAX]; //nr inversat

      int  CharactersCount;

   public:

      BigNumber (); // Constructor implicit (creeaza numarul 0 [field-ul Number contine "0", field-ul CharactersCount contine valoarea 1 - un caracter]

      BigNumber (int value);

      BigNumber (const char * number);

      BigNumber (const BigNumber & number);


      void Print();

      bool Set(int value);

      bool Set(const char * number);



      BigNumber operator+ (const BigNumber & number);

      BigNumber operator* (const BigNumber & number);

      BigNumber operator- (const BigNumber & number);

      BigNumber operator/ (const BigNumber & number);


      friend bool operator == (const BigNumber & n1, const BigNumber & n2);

      friend bool operator != (const BigNumber & n1, const BigNumber & n2);

      friend bool operator < (const BigNumber & n1, const BigNumber & n2);

      friend bool operator > (const BigNumber & n1, const BigNumber & n2);

      friend bool operator >= (const BigNumber & n1, const BigNumber & n2);

      friend bool operator <= (const BigNumber & n1, const BigNumber & n2);

      operator int();
      char operator[] (int index); // returneaza caracterul de pe pozitia index sau \0 in rest
      BigNumber operator() (int start, int ending); // returneaza numarul de la caracterul dat de pozitia "start" pana la caracterul dat de pozitia "end" sau "0" daca start/end nu sunt valide.
};
