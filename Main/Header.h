#include <iostream>
using namespace std;
struct Student {
	int id; 
	char* studentName; 
	char* studentSurname; 
	char* cameTime; 
	int age;
	void allocateMemory() {  
		studentName = new char[21]; 
		studentSurname = new char[31]; 
		cameTime = new char[6]; 
	}
	void inputStudent() { 
		allocateMemory(); 
		cin >> id >> studentName >> studentSurname >> age >> cameTime; 
	}
	int convertTime() { 
		int i = 0; 
		int mm = 0; 
		int hh = 0; 
		while (true) { 
			if (cameTime[i] == ':') { 
				break; 
			}
			hh = hh * 10 + (cameTime[i] - '0'); 
			i++; 
		}
		i++; 
		while (true) {
			if (cameTime[i] == '\0') {
				break; 
			}
			mm = mm * 10 + (cameTime[i] - '0');
			i++; 
		}

		return hh * 60 + mm; 
	}
	void outputStudent() { 
		cout << "\t" << id << " " << studentName << " "
			<< studentSurname << " " << age << " " << cameTime << endl; 
	}
};
struct Group {
	char* groupName;
	int stNum; 
	Student* st;
	void allocateMemory() { 
		groupName = new char[10];
	}
	void inputGroup() { 
		allocateMemory(); 
		cin >> groupName >> stNum; 
	}
	double getAverageAge() { 
		double sum = 0; 
		for (int i = 0; i < stNum; i++) { 
			sum += st[i].age; 
		}
		return sum / stNum;
	}
	void outputGroup() { 
		cout << groupName << ":" << endl; 
	}
};
void convertUpper(char* text) { 
	for (int i = 0; i < strlen(text); i++) { 
		if (islower(text[i])) {  
			text[i] = toupper(text[i]); 
		}
	}
}

template <class T> 
bool operator>(T& a, T& b) { 
	return a.convertTime() > b.convertTime(); 
}

template <class T>
bool ascending(T& a, T& b) { 
	return a > b; 
}

template <class T>
bool operator<(T& a, T& b) { 
	return a.getAverageAge() < b.getAverageAge(); 

template <class T>
bool descending(T& a, T& b) { 
	return a < b; 
}
template <class T>
void bubbleSort(T* a, int n, bool (*compare)(T&, T&)) { 
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if ((*compare)(a[j], a[j + 1])) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}
int main() {
	int n; 
	cin >> n; 
	Group* gr = new Group[n]; 
	for (int i = 0; i < n; i++) {
		gr[i].inputGroup();
		convertUpper(gr[i].groupName); 
		gr[i].st = new Student[gr[i].stNum]; 
		for (int j = 0; j < gr[i].stNum; j++) { 
			gr[i].st[j].inputStudent(); 
			convertUpper(gr[i].st[j].studentName); 
			convertUpper(gr[i].st[j].studentSurname);
		}
		bubbleSort(gr[i].st, gr[i].stNum, ascending); 
	}
	bubbleSort(gr, n, descending); 
	for (int i = 0; i < n; i++) { 
		gr[i].outputGroup(); 
		for (int j = 0; j < gr[i].stNum; j++) { 
			gr[i].st[j].outputStudent(); 
		}
	}
	for (int i = 0; i < n; i++) { 
		for (int j = 0; j < gr[i].stNum; j++) {
			delete[] gr[i].st[j].studentName; 
			delete[] gr[i].st[j].studentSurname;
			delete[] gr[i].st[j].cameTime;
		}
		delete[] gr[i].st;  
		delete[] gr[i].groupName; 
	}

	delete[] gr; 

}




#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

void input(int* a, int m) {
	for (int* i = a; i < a + m; i++) {
		cin >> *i;
	}
}

void output(int* a, int m) {
	for (int* i = a; i < a + m; i++) {
		cout << *i << " ";
	}
	cout << endl;
}
bool isPrime(int a) {
	if (a == 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}

unsigned int countPrimes(int* a, int m) {
	int c = 0;
	for (int i = 0; i < m; i++) {
		if (isPrime(*(a + i))) {
			c++;
		}
	}
	return c;
}


int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	input(a, n);
	unsigned int total = countPrimes(a, n);
	cout << total;
}

#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

void input(int* a, int m) {
	for (int* i = a; i < a + m; i++) {
		cin >> *i;
	}
}

void output(int* a, int m) {
	for (int* i = a; i < a + m; i++) {
		cout << *i << " ";
	}
	cout << endl;
}
bool isPrime(int a) {
	if (a == 1) {
		return false;
	}
	for (int i = 2; i <= sqrt(a); i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}

unsigned int countPrimes(int* a, int m) {
	int c = 0;
	for (int i = 0; i < m; i++) {
		if (isPrime(*(a + i))) {
			c++;
		}
	}
	return c;
}
int findIwithMaxPrimes(int** a, int n, int m) {
	int maxp = 0;
	int index;
	for (int i = 0; i < n; i++) {
		int c = countPrimes(*(a + i), m);
		if (c > maxp) {
			maxp = c;
			index = i;
		}
	}
	return index;
}
void bublesort(int* a, int m) {
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < m - i - 1; j++) {
			if (a[j + 1] < a[j]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		*(a + i) = new int[m];
		input(*(a + i), m);
	}
	int index = findIwithMaxPrimes(a, n, m);
	bublesort(*(a + index), m);
	for (int i = 0; i < n; i++) {
		output(*(a + i), m);
	}
	for (int i = 0; i < n; i++) {
		delete[] * (a + i);
	}
	delete[]a;
}

#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

struct Subject {
	char* name;
	double grade;
	void allocatememory() {
		name = new char[31];
	}
	void input() {
		allocatememory();
		cin >> name >> grade;
	}
	void output() {
		cout << name << ' ' << grade << endl;
	}
	void deallocatememory() {
		delete[] name;
	}
};

struct Student {
	int id;
	char* name;
	char* surname;
	int numSubj;
	Subject* subjects;
	void allocatememory() {
		name = new char[31];
		surname = new char[31];
	}
	void input() {
		allocatememory();
		cin >> id >> name >> surname >> numSubj;
		subjects = new Subject[numSubj];
	}
	void output() {
		cout << id << ' ' << name << ' ' << surname << ' : ';
	}
	void deallocatememory() {
		delete[]name;
		delete[]surname;
	}
};


void bublesort(Subject* a, int m) {
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < m - i - 1; j++) {
			double grade1 = a[i].grade, grade2 = a[i + 1].grade;
			if (grade1 > grade2) {
				Subject temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main() {
	Student s1;
	s1.input();
	for (int i = 0; i < s1.numSubj; i++) {
		s1.subjects[i].input();
	}

	bublesort(s1.subjects, s1.numSubj);

	s1.output();
	for (int i = 0; i < s1.numSubj; i++) {
		s1.subjects[i].output();
	}
	for (int i = 0; i < s1.numSubj; i++) {
		s1.subjects[i].deallocatememory();
	}
	delete[] s1.subjects;
	return 0;
}



#include <iostream>
using namespace std;

struct Subject {
	char* name;
	double grade;
	void allocate_memory() {
		name = new char[30];
	}
	void input() {
		allocate_memory();
		cin >> name >> grade;
	}
	void output() {
		cout << name << " " << grade << ", ";
	}
	void deallocate_memory() {
		delete[] name;
	}
};


struct Student {
	int id;
	char* name;
	char* surname;
	int subjCol;
	Subject* subjects;
	void allocate_memory() {
		name = new char[30];
		surname = new char[30];
	}
	void input() {
		allocate_memory();
		cin >> id >> name >> surname >> subjCol;
		subjects = new Subject[subjCol];
	}
	void output() {
		cout << id << " " << name << " " << surname << " : ";
	}
	void deallocate_memory() {
		delete[] name;
		delete[] surname;
	}
};

void sortSubjects(Subject* arr, int n) {
	for (int hh = 0; hh < n; hh++) {
		for (int i = 0; i < n - hh - 1; i++) {
			double gradeOne = arr[i].grade, gradeTwo = arr[i + 1].grade;
			if (gradeOne > gradeTwo) {
				Subject tmpSubject = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmpSubject;
			}
		}
	}
}

double getGPA(Student myStudent) {
	double summaSubjs;
	for (int i = 0; i < myStudent.subjCol; i++) {
		summaSubjs += myStudent.subjects[i].grade;
	}
	return summaSubjs / double(myStudent.subjCol);
}

void sortStudents(Student* students, int n) {
	for (int hh = 0; hh < n; hh++) {
		for (int i = 0; i < n - hh - 1; i++) {
			double gpaF = getGPA(students[i]), gpaS = getGPA(students[i + 1]);
			if (gpaF < gpaS) {
				Student tmpStudent = students[i];
				students[i] = students[i + 1];
				students[i + 1] = tmpStudent;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	Student* students = new Student[n];

	for (int i = 0; i < n; i++) {
		students[i].input();
		for (int subjIndex = 0; subjIndex < students[i].subjCol; subjIndex++) {
			students[i].subjects[subjIndex].input();
		}
		sortSubjects(students[i].subjects, students[i].subjCol);
	}

	sortStudents(students, n);

	for (int i = 0; i < n; i++) {
		students[i].output();
		for (int subjIndex = 0; subjIndex < students[i].subjCol; subjIndex++) {
			students[i].subjects[subjIndex].output();
		}
		cout << "\n";
	}

	return 0;
	for (int i = 0; i < n; i++) {
		for (int subjIndex = 0; subjIndex < students[i].subjCol; subjIndex++) {
			students[i].subjects[i].deallocate_memory();
		}
		delete[] students[i].subjects;
	}
	delete[] students;
	return 0;
}

