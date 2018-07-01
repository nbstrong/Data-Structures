using namespace std;

// Preprocessing directives that prevents multiple definitions.
#ifndef Book_H
#define Book_H

// Good resource for class definition with strings to be used for 
// binary file: https://www.youtube.com/watch?v=P7XGOBoVzW4

class Book
{
	// Data attributes.
	char title[80];
	char author[40];
	int year;
	int ISBN;	

	// Declaring friends.
	friend ostream &operator << (ostream& out, const Book& theBook);
public:
    Book();
	Book(char *theTitle, char *theAuthor, int theYear, int theISBN);
	void print();
	
	// Get and set methods or member functions.	
	string getTitle() const;	
	string getAuthor() const;	
	int getYear() const;
	int getISBN() const;	
	void setTitle(char *theTitle);
	void setAuthor(char *theAuthor);	
	void setYear(int theYear);	
	void setISBN(int theISBN);	
};

#endif