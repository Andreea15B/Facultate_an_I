#include <algorithm> 
class Compare {
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};


template<class T>
class ArrayIterator {
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
public:
	ArrayIterator();
	ArrayIterator& operator++ ();
	ArrayIterator& operator-- ();
	bool operator= (ArrayIterator<T> &);
	bool operator!=(ArrayIterator<T> &);
	T* GetElement();
};


template<class T>
class Array {
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
	void realloc(int newElems);
public:
	Array(); // Lista nu e alocata, Capacity si Size = 0
	~Array(); // destructor
	Array(int capacity); // Lista e alocata cu 'capacity' elemente
	Array(const Array<T> &otherArray); // constructor de copiere

	T& operator[] (int index); // arunca exceptie daca index este out of range
	bool operator=(const Array<T> &otherArray);
	const Array<T>& operator+=(const T &newElem); // adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& Insert(int index, const T &newElem); // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T> otherArray); // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index); // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

	void Sort(); // sorteaza folosind comparatia intre elementele din T
	void Sort(int(*compare)(const T&, const T&)); // sorteaza folosind o functie de comparatie
	void Sort(Compare *comparator); // sorteaza folosind un obiect de comparatie

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, Compare *comparator);//  cauta un element folosind binary search si un comparator

	int Find(const T& elem); // cauta un element in Array
	int Find(const T& elem, int(*compare)(const T&, const T&)); // cauta un element folosind o functie de comparatie
	int Find(const T& elem, Compare *comparator); // cauta un element folosind un comparator

	int GetSize(); 
	int GetCapacity();

	ArrayIterator<T> GetBeginIterator();
	ArrayIterator<T> GetEndIterator();
};

template<class T>
Array<T>::Array() {
	List = nullptr;
	Capacity = 0;
	Size = 0;
}

template<class T>
Array<T>::~Array() {
	delete[] List;
}

template<class T>
Array<T>::Array(int capacity) {
		List = new T*[capacity];
		Size = 0;
		Capacity = capacity;
}

template<class T>
Array<T>::Array(const Array<T> &otherArray) {
	Size = otherArray.Size;
	Capacity = otherArray.Capacity;
	List = new T*[Capacity];
	for(int i = 0; i < Size; i++) {
		List[i] = new T;
		*List[i] = *otherArray.List[i];
	}
}

template<class T>
T& Array<T>::operator[] (int index) {
	if(index < 0 || index >= Size) throw "Operator[]: Index out of range";
	else return *List[index];
}

template<class T>
bool Array<T>::operator= (const Array<T> &otherArray) {
	this(&otherArray);
	return true;
}

template<class T>
int Array<T>::GetSize() {
	return Size;
}

template<class T>
int Array<T>::GetCapacity() { 
	return Capacity; 
}

template<class T>
const Array<T>& Array<T>::operator+=(const T &newElem) {
	if(Size == Capacity) realloc(sizeof(newElem));
	List[Size] = new T;
	*List[Size++] = newElem;
	return *this;
}

template<class T>
void Array<T>::realloc(int newElems) {
	int newCapacity = min(2*Capacity, Size+newElems);
	T** newList = new T*[newCapacity];

	for(int i = 0; i < Size; ++i) newList[i] = List[i];

	Capacity = newCapacity;
	List = newList;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const T &newElem) {
	if(index<0 || index>Size) throw "Insert element error: Index out of range";
	if(Size == Capacity) realloc(sizeof(newElem));
	List[Size] = new T;
	for (int i = Size-1; i >= index; i--) *List[i+1] = *List[i];
	*List[index] = newElem;
	Size++;
	return *this;
}

template<class T>
const Array<T>& Array<T>::Insert(int index, const Array<T> otherArray) {
	if(index<0 || index>Size) throw "Insert Array error: Index out of range";
	if(Size + otherArray.Size > Capacity) realloc(Size + otherArray.Size);

	for(int i = Size-1; i >= index; i--) {
		List[i + otherArray.Size] = new T;
		*List[i + otherArray.Size] = *List[i];
	}
	for(int i = 0; i < otherArray.Size; i++) {
		List[index + i] = new T;
		*List[index + i] = *otherArray.List[i];
	}
	Size += otherArray.Size;
	return *this;
}

template<class T>
const Array<T>& Array<T>::Delete(int index) {
	if(index<0 || index>Size) throw "Delete error: Index out of range";
	delete List[index];
	for(int i = index; i < Size-1; i++) List[i] = List[i+1];
	Size--;
	return *this;
}

int Compare::CompareElements(void* e1, void* e2) {
	if(e1 < e2) return 1;
	return 0;
}

template<class T>
void Array<T>::Sort() {
	int i, sortat=0;
	while(sortat == 0) {
		sortat = 1;
		for(i=0; i<Size-1; i++) {
			if(*List[i] > *List[i+1]) {
				sortat = 0;
				swap(List[i], List[i+1]);
			}
		}
	}
}