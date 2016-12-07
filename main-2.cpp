

//#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include <vector>
#include <cstdlib>
#include <string>


using namespace std;


class Student{
public:
	string firstName;  // krstne meno
	string lastName; // priezvisko
	Student() : firstName(""), lastName("") {}

	Student(string firstName, string lastName) : firstName(firstName), lastName(lastName) {}

	// DOPLNIT operator <
	friend bool operator< (const Student & a, const Student & b)
	{
		if((a.lastName)<(b.lastName)) {
			return true;
		}
		else if ((a.lastName)>(b.lastName)) {
			return false;
		}
		else {
			if((a.firstName)<(b.firstName)) {
				return true;
			}
			else if ((a.firstName)>(b.firstName)) {
				return false;
			}
		}
	} 
	
	// DOPLNIT operator <<
		friend ostream& operator<<(ostream& os, const Student & a)
	{
		os << (a.firstName) << " " << (a.lastName);
		 return os;
	}

};



// struktura, ktora predstavuje uzol v binarnom vyhladavacom strome
struct Node{

	Student student; // datova cast uzlu
	Node * left; // lavy potomok
	Node * right; // pravy potomok

	Node(Student student){
		this->student = student;
		this->left = 0;
		this->right = 0;
	}
};

class Tree{

public:
    
    //odtialto to treba prerobit:

	Node * root;

	Tree() {
                Student studentik("Jakub", "Komorny");
                Node root(studentik);
                
	}

	// pridanie studenta do stromu

        
        
        
        
        
        
bool addStudent(Student student, Node * temp) {


	Node novystudent(student);


    if(temp==NULL) {
        temp = root;
    }


    
	if((novystudent.student) < (temp->student)) {
			  if(temp->left == NULL) {
				    *(temp->left) = novystudent;
					return true;
			    }
        else {
            addStudent(student, temp->left);
            return false;
        }
    }
    
	if((novystudent.student.lastName) > (novystudent.student.lastName)) {
        if(temp->right == NULL) {
            *(temp->right) = novystudent;
			return true;
        }
        else {
            addStudent(student, temp->right);
            return false;
        }
    }

		return false; // <- ZMENIT (docasny return kvoli kompilacii)

	}

        
        
        
        
        
        
        
        
        //potadeto
        
        
        
	// vypis vsetkych studentov v strome (abecedne usporiadany)
	void print(Node * temp) { 

	        if(temp==NULL) {
        temp = root;
    }
 
        if(temp->left != NULL) {
            
            print(temp->left);
        }

		cout<<temp->student.firstName << " " <<temp->student.lastName << endl;
 
        if(temp->right != NULL) {
            
            print(temp->right);
        }
        
	}

	// vypis studentov v uzloch so zadanou hlbkou
	void printDepth(int hlbka, Node * temp){
		

	        if(temp==NULL) {
        temp = root;
    }
 
        if(temp->left != NULL) {
            
            printDepth(hlbka-1, temp->left);
        }

		if(hlbka==0) {
		cout<<temp->student.firstName << " " <<temp->student.lastName << endl;
		}
 
        if(temp->right != NULL) {
            
            printDepth(hlbka-1, temp->right);
        }



	}

};


// usporiadanie prvkov vektora (PODLA ZADANIA ZMENIT DEKLARACIU)
template<typename ElementType>
void sort(vector<ElementType> & data) {

	int n = data.size();
	int i, j;
	ElementType tmp;

	for (i=1; i<n; i++)
	{
		 j=i;
		tmp=data[i];
		while (j>0 && tmp<data[j-1])
		{
		       data[j]=data[j-1];
		      j--;
		 }
		 data[j]=tmp;
}
}

/*------------------------------------------------------------------------------
   Dalej nasleduju testovacie funkcie a main
 -----------------------------------------------------------------------------*/

// Testovacia funkcia (neupravovat! mozete len odkomentovat zakomentovane riadky)
void test1() {
	cout << "-------------------------------"<< endl;
	cout << "Test1: operator<" << endl;
    cout << "-------------------------------"<< endl;

    Student s1("Jan", "Bystricky");
    Student s2("Jan", "Sikovny");
    Student s3("Peter", "Sikovny");

//	cout << (s1 < s2 ? "OK" : "ERR") << " ";
//	cout << (s2 < s1 ? "ERR" : "OK") << " ";
//	cout << (s2 < s3 ? "OK" : "ERR") << " ";
//	cout << (s3 < s2 ? "ERR" : "OK") << " ";
	cout << endl << endl;
}

//Testovacia funkcia (neupravovat! mozete len odkomentovat zakomentovane riadky)
void test2() {
	cout << "-------------------------------"<< endl;
    cout << "Test2: operator<<" << endl;
	cout << "-------------------------------"<< endl;
    Student s1("Jan", "Bystricky");
//	cout << s1 << endl;
    cout << endl;
}

//Testovacia funkcia (neupravovat! mozete len odkomentovat zakomentovane riadky)
void test3a1() {
	cout << "-------------------------------"<< endl;
    cout << "Test3a1: sort int" << endl;
    cout << "-------------------------------"<< endl;

    int data[] = {10, 5, 2, 1, 12, 15, 80, 0, -1, 4};
    vector<int> v(data, data+10);
    sort(v);
    for(int i = 0; i < 10; i++) {
        cout << v[i] <<", ";
    }
    cout<< endl << endl;
}

//Testovacia funkcia (neupravovat! mozete len odkomentovat zakomentovane riadky)
void test3a2() {
	cout << "-------------------------------"<< endl;
    cout << "Test3a2: sort int (pole dlzky 1)" << endl;
	cout << "-------------------------------"<< endl;
    
    int data[] = {10};
    vector<int> v(data, data+1);
    sort(v);
    for(int i = 0; i < 1; i++) {
        cout << v[i] <<", ";
    }
    cout<< endl << endl;
}


//Testovacia funkcia (neupravovat! mozete len odkomentovat zakomentovane riadky)
void test3a3() {
	cout << "-------------------------------"<< endl;
    cout << "Test3a3: sort int (pole dlzky 0)" << endl;
	cout << "-------------------------------"<< endl;
    vector<int> v;
    sort(v);
    cout << endl << endl;
}

//Testovacia funkcia (neupravovat! mozete len odkomentovat zakomentovane riadky)
void test3b() {
	cout << "-------------------------------"<< endl;
    cout << "Test3b: sort Student" << endl;
    cout << "-------------------------------"<< endl;

    vector<Student> v;
    v.push_back(Student("Bb","Da"));
    v.push_back(Student("A" ,"Aa"));
    v.push_back(Student("C" ,"Cc"));
    v.push_back(Student("B" ,"Bb"));
    v.push_back(Student("Cc","Da"));
    v.push_back(Student("D" ,"Db"));
    v.push_back(Student("Aa","Da"));
    v.push_back(Student("Ab","Ee"));
    v.push_back(Student("B" ,"Ba"));
    v.push_back(Student("Aa","Ee"));
    
//    sort(v);
//    for(int i = 0; i < 10; i++) {
//        cout << v[i] <<", ";
//    }
    cout<< endl << endl;
}

//Testovacia funkcia (neupravovat! mozete len odkomentovat zakomentovane riadky)
Tree * testCreateTree(){

	const static int pocet = 8;
	string mena[]= {"Andrej", "Peter", "Igor", "Emil", "Petra", "Marek", "Jana", "Juraj"};
	string priezviska[]= {"Maly", "Maly", "Stredny", "Vysoky", "Vysoka", "Chladny", "Dvorska", "Balogh"};
	Tree * bst = new Tree();

	for (int i=0; i<pocet; i++)
		bst->addStudent(Student(mena[i], priezviska[i]), NULL);
	return bst;
}

//Testovacia funkcia (neupravovat! mozete len odkomentovat zakomentovane riadky)
void test4(){
	cout << "-------------------------------"<< endl;
	cout << "Test4: Testovanie navratovej hodnoty funkcie addStudent()" << endl;
	cout << "-------------------------------"<< endl;
	Tree tree;
	cout << tree.addStudent(Student("Andrej", "Maly"), NULL)    << " ";
	cout << tree.addStudent(Student("Peter" , "Maly"), NULL)    << " ";
	cout << tree.addStudent(Student("Igor"  , "Stredny"), NULL) << " ";
	cout << tree.addStudent(Student("Igor"  , "Stredny"), NULL) << " ";
	cout << tree.addStudent(Student("Rudolf", "Strassman"), NULL) << " ";
	cout << endl << endl;	
}

//Testovacia funkcia (neupravovat! mozete len odkomentovat zakomentovane riadky)
void test5(){
	cout << "-------------------------------"<< endl;
	cout << "Test5: Vypis vsetkych studentov v strome" << endl;
	cout << "-------------------------------"<< endl;
	Tree * bst =testCreateTree();
	bst->print(NULL);
	cout << endl;
}

//Testovacia funkcia (neupravovat! mozete len odkomentovat zakomentovane riadky)
void test6(int hlbka){
	cout << "-------------------------------"<< endl;
	cout << "Test6: Vypis studentov v hlbke " << hlbka << endl;
	cout << "-------------------------------"<< endl;
	Tree * bst =testCreateTree();
	bst->printDepth(hlbka, NULL); 
	cout << endl;
}


int main(){

	test1(); //operator <

    test2(); //operator <<

    test3a1(); //sort vektora int-ov
    test3a2();
    test3a3();
    test3b(); //sort vektora studentov

	testCreateTree(); //vytvorenie binarneho vyhladavacieho stromu
	test4(); //navratova hodnota addStudent
	
	test5(); //vypis vsetkych studentov v strome (abecedne usporiadani)
	
	test6(1); //vypis vsetkych studentov v danej hlbke - volanie funkcie printDepth()
	test6(2);
	test6(3);
	test6(8);

	system("pause");
}

