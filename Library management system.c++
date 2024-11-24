#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
ofstream p;
fstream f;
int i, j, z;
class book_info
{
private:
    char name[30];
    char author[30];
    char publication[30];
    int no_ofcopies;
    int copies_issue;

public:
    void set(char *n, char *a, char *p, int c)
    {
        strcpy(name, n);
        strcpy(author, a);
        strcpy(publication, p);
        no_ofcopies = c;
    }
    void setc(int c)
    {
        copies_issue = c;
    }

    char *getname()
    {
        return name;
    }
    char *getauthor()
    {
        return author;
    }
    char *getpub()
    {
        return publication;
    }
    int getcopies()
    {
        return no_ofcopies;
    }
    int getCi()
    {
        return copies_issue;
    }
};
class student
{
private:
    char department[20];
    char student[29];
    int Class;
    char division[10];
    char b_name[3][20];
    int no_issue_book;

public:
    void set(char *s, char *d, char *di, int c)
    {
        strcpy(student, s);
        strcpy(department, d);
        strcpy(division, di);
        Class = c;
    }
    void setb(char *b, int n, int c)
    {
        strcpy(b_name[n], b);
        no_issue_book = c;
    }
    char *getS()
    {
        return student;
    }
    char *getD()
    {
        return department;
    }
    char *getDI()
    {
        return division;
    }
    char *getBO(int n)
    {
        return b_name[n];
    }
    int getC()
    {
        return Class;
    }
    int getNo()
    {
        return no_issue_book;
    }
} s[10];
class librarian_info
{
protected:
    char name[29];
    char qualification[29];
    int experience;

public:
    char *getname()
    {
        return name;
    }
    char *getqualification()
    {
        return qualification;
    }
    int getexp()
    {
        return experience;
    }
};
class library_info : public librarian_info
{
private:
    int number_of_books;
    char book_name[20];
    char person_name[20];
    int issue_details;
    book_info b[10];

public:
    void setb(char *n, char *a, char *p, int c, int pos)
    {
        b[pos].set(n, a, p, c);
    }
    void setcl(int cl, int pos)
    {
        b[pos].setc(cl);
    }
    char *getN(int a)
    {
        return b[a].getname();
    }
    char *getP(int a)
    {
        return b[a].getpub();
    }
    char *getA(int a)
    {
        return b[a].getauthor();
    }
    int getC(int a)
    {
        return b[a].getcopies();
    }
    int getCI(int a)
    {
        return b[a].getCi();
    }
    void setl(char *n, char *q, int e)
    {
        strcpy(name, n);
        strcpy(qualification, q);
        experience = e;
    }
} l;
void viewbook()
{
    string line;
    f.open("book_info.txt", ios::in);
    if (!f.is_open())
    {
        cout << "File is not opened";
    }
    else
    {
        while (!f.eof())
        {
            getline(f, line);
            cout << line << endl;
        }
    }
    f.close();
}
void viewlibrarian()
{
    string line;
    f.open("Librarain_info.txt", ios::in);
    if (!f.is_open())
    {
        cout << "File is not opened";
    }
    else
    {

        while (!f.eof())
        {
            getline(f, line);
            cout << line << endl;
        }
    }
    f.close();
}
void viewstudent()
{
    string line;
    f.open("student_info.txt", ios::in);
    if (!f.is_open())
    {
        cout << "File is not opened";
    }
    else
    {
        while (!f.eof())
        {
            getline(f, line);
            cout << line << endl;
        }
    }
    f.close();
}
void writel()
{
    p.open("Librarain_info.txt", ios::out);
    if (!p.is_open())
    {
        cout << "File not opened";
    }
    else
    {
        p << "Librarain detail:" << endl;
        p << "Name,Qualification,Experience" << endl;
        p << l.getname() << "," << l.getqualification() << "," << l.getexp();
    }
    p.close();
}
void writes(int n)
{
    p.open("student_info.txt", ios::out);
    if (n == 0)
    {
        cout << "Entered no of student is 0" << endl;
    }
    else
    {
        if (!p.is_open())
        {
            cout << "File not opened";
        }
        else
        {
            p << "Student Detail:" << endl;
            p << "No:Name,Dep,Division,Class,Total_Book,Book name" << endl;
            for (i = 0; i < n; i++)
            {

                p << i + 1 << ":" << s[i].getS() << "," << s[i].getD() << "," << s[i].getDI() << "," << s[i].getC() << "," << s[i].getNo();
                j = 0;
                while (j != s[i].getNo())
                {
                    p << "," << s[i].getBO(j);
                    j++;
                }
                if (i != n - 1)
                {
                    p << endl;
                }
            }
        }
    }
    p.close();
}
void writeb(int n)
{
    p.open("book_info.txt", ios::out);
    if (n == 0)
    {
        cout << "Entered no of book is 0";
    }
    else
    {

        if (!p.is_open())
        {
            cout << "File not opened";
        }
        else
        {
            p << "Book detail:" << endl;
            p << "No:Name,Author,Publication,Copies,Copies Left" << endl;
            for (i = 0; i < n; i++)
            {
                p << i + 1 << ":" << l.getN(i) << "," << l.getA(i) << "," << l.getP(i) << "," << l.getC(i) << "," << l.getC(i) - l.getCI(i);
                if (i != n - 1)
                {
                    p << endl;
                }
            }
        }
    }
    p.close();
}
int test(int n, int z, char book_name[20])
{
    for (j = 0; j < n; j++)
    {
        if (!strcmp(book_name, l.getN(j)) && (l.getC(j) - l.getCI(j)) > 0)
        {
            cout << "Book " << book_name << " is issued" << endl;
            z = 0;
            l.setcl(l.getCI(j) + 1, j);
            break;
        }
    }
    return z;
}
void modifylibrarian()
{
    int c, exp;
    char na[20], au[10];
    cout << "Enter 1 to change name \nEnter 2 to change qualification\nEnter 3 to change experience:" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
    {
        cout << "Enter name" << endl;
        cin >> na;
        l.setl(na, l.getqualification(), l.getexp());
        break;
    }
    case 2:
    {
        cout << "Enter qualification" << endl;
        cin >> au;
        l.setl(l.getname(), au, l.getexp());
        break;
    }
    case 3:
    {
        cout << "Enter experience " << endl;
        cin >> exp;
        l.setl(l.getname(), l.getqualification(), exp);
        break;
    }
    default:
    {
        cout << "Entered no is not 1-3(No modify)" << endl;
        l.setl(l.getname(), l.getqualification(), l.getexp());
        break;
    }
    }
    writel();
}
int addbook(int k)
{

    int n, copies;
    char na[30], au[30], pub[30];
    cout << "No of book in library to add";
    cin >> n;
    for (i = k; i < (n + k); i++)
    {
        cout << "--------Book " << i + 1 << " detail-------" << endl;
        cout << "Enter name" << endl;
        cin >> na;
        cout << "Enter author name" << endl;
        cin >> au;
        cout << "Enter publiction " << endl;
        cin >> pub;
        cout << "Enter number of copies " << endl;
        cin >> copies;
        l.setb(na, au, pub, copies, i);
        l.setcl(0, i);
    }
    p.open("book_info.txt", ios::app);
    if (!p.is_open())
    {
        cout << "File not opened";
    }
    else
    {
        p << endl;
        for (i = k; i < (n + k); i++)
        {
            p << i + 1 << ":" << l.getN(i) << "," << l.getA(i) << "," << l.getP(i) << "," << l.getC(i) << "," << l.getC(i) - l.getCI(i);
            if (i != k + n - 1)
            {
                p << endl;
            }
        }
    }
    p.close();
    return n + k;
}

int Issue(int k, int a)
{
    int n, c, t = 0;
    char na[20], b_na[20], Dep[10], div[5];
    cout << "Enter Student name" << endl;
    cin >> na;
    for (i = 0; i < k; i++)
    {
        if (!strcmp(na, s[i].getS()))
        {
            t = 1;
            c = i;
            break;
        }
    }
    if (t == 1)
    {
        cout << "------Registered student------\n"
             << endl;
        z = 1;
        while (z != 0)
        {
            cout << "Enter book name " << endl;
            cin >> b_na;
            if (s[c].getNo() >= 3)
            {
                break;
            }
            z = test(a, z, b_na);
            if (z == 1)
            {
                cout << "Book " << b_na << " is not issued(Book is not present or No Copies left)" << endl;
            }
        }
        if (s[c].getNo() >= 3)
        {
            cout << "Student " << s[c].getS() << "had max 3 books issued";
            cout << "No issued";
        }
        else
        {
            if (s[c].getNo() == 2)
            {
                s[c].setb(b_na, 2, 3);
            }
            else
            {
                s[c].setb(b_na, 1, 2);
            }
            writes(k);
        }
    }
    else
    {
        cout << "------UnRegistered student------" << endl;
        cout << "--------Student  " << k + 1 << " detail------" << endl;
        cout << "Enter your department name" << endl;
        cin >> Dep;
        cout << "Enter class" << endl;
        cin >> c;
        cout << "Enter division" << endl;
        cin >> div;
        z = 1;
        while (z != 0)
        {
            cout << "Enter book name " << endl;
            cin >> b_na;

            z = test(a, z, b_na);
            if (z == 1)
            {
                cout << "Book " << b_na << " is not issued(Book is not present or No Copies left)" << endl;
            }
        }
        s[i].set(na, Dep, div, c);
        s[i].setb(b_na, 0, 1);
        k = k + 1;
        p.open("student_info.txt", ios::app);
        if (!p.is_open())
        {
            cout << "File is not opened";
        }
        else
        {
            p << endl;
            p << k << ":" << s[i].getS() << "," << s[i].getD() << "," << s[i].getDI() << "," << s[i].getC()<< "," << s[i].getNo() << "," << s[i].getBO(0);
        }
        p.close();
    }
    writeb(a);
    return k;
}
int Return(int k, int a)
{
    int n, c;
    char na[20], b_na[20];
    cout << "Enter Student Name:";
    cin >> na;
    z = 0;
    c = -1;
    
    for (i = 0; i < k; i++)
    {
        
        if (!strcmp(s[i].getS(), na))
        {
            if (s[i].getNo() > 1)
            {
                n = s[i].getNo();
                cout << "Student " << s[i].getS() << " has issued books" << endl;
                while (z < n)
                {
                    cout << "Book" << z + 1 << ":" << s[i].getBO(z) << endl;
                    z++;
                }
                cout << "Enter book name:" << endl;
                cin >> b_na;
                for (j = 0; j < n && c == -1; j++)
                {

                    for (z = 0; z < a; z++)
                    {
                        if (!strcmp(b_na, s[i].getBO(j)) && !strcmp(b_na, l.getN(z)))
                        {
                            l.setcl(l.getCI(z) - 1, z);
                            c = j;
                            break;
                        }
                    }
                    if (j==n-1&& c == -1)
                    {
                        cout << "Entered book name is invalid(No Return)" << endl;
                        return k;
                    }
                    
                }
                for (z = 0; z < n; z++)
                {
                    if (c == z)
                    {
                        if (z == n - 1)
                        {
                            s[i].setb(s[i].getBO(z + 1), z, n - 1);
                        }
                        else
                        {
                            s[i].setb(s[i].getBO(z + 1), z, n);
                        }
                        c++;
                    }
                }
            }
            else
            {
                for (z = 0; z < a; z++)
                    {
                        if (!strcmp( s[i].getBO(0), l.getN(z)))
                        {
                            l.setcl(l.getCI(z) - 1, z);
                            break;
                        }
                    }
                for (z = 0; z < k; z++)
                {
                    if (z == i)
                    {
                        s[z].set(s[z + 1].getS(), s[z + 1].getD(), s[z + 1].getDI(), s[z + 1].getC());
                        s[z].setb(s[z + 1].getBO(0), 0, 1);
                        i++;
                    }
                }
                k = k - 1;
            }
            break;
        }
        else if (i==k-1)
        {
            cout << "Entered student name is invalid" << endl;
            return k;
        }
    }
    writeb(a);
    writes(k);
    return k;
}
int main()
{
    char na[20], au[20], pub[20];
    char l_na[20], l_q[20];
    char s_na[20], b_na[20], dep[10], div[5];
    int n_book, n_student, s_class, l_y, c, z, x,copies, c_issue;
    cout << "------librarian detail------" << endl;
    cout << "Enter name" << endl;
    cin >> l_na;
    cout << "Enter qualification" << endl;
    cin >> l_q;
    cout << "Enter experience " << endl;
    cin >> l_y;
    l.setl(l_na, l_q, l_y);
    writel();
    cout << "No of book in library";
    cin >> n_book;
    for (i = 0; i < n_book; i++)
    {
        cout << "--------Book " << i + 1 << "detail-------" << endl;
        cout << "Enter name" << endl;
        cin >> na;
        cout << "Enter author name" << endl;
        cin >> au;
        cout << "Enter publiction " << endl;
        cin >> pub;
        cout << "Enter number of copies " << endl;
        cin >> copies;
        c_issue = 0;
        l.setb(na, au, pub, copies, i);
        l.setcl(c_issue, i);
    }
    writeb(n_book);
    cout << endl;
    cout << "No of student to issue:";
    cin >> n_student;
    for (i = 0; i < n_student; i++)
    {
        cout << "--------Student  " << i + 1 << " detail------" << endl;
        cout << "Enter Student name" << endl;
        cin >> s_na;
        cout << "Enter your department name" << endl;
        cin >> dep;
        cout << "Enter division" << endl;
        cin >> div;
        cout << "Enter class" << endl;
        cin >> s_class;
        z = 1;
        while (z != 0)
        {
            cout << "Enter book name " << endl;
            cin >> b_na;
            z = test(n_book, z, b_na);
            if (z == 1)
            {
                cout << "Book " << b_na << " is not issued(Book is not present or No Copies left)" << endl;
            }
        }
        s[i].set(s_na, dep, div, s_class);
        s[i].setb(b_na, 0, 1);
    }
    writes(n_student);
    writeb(n_book);
    cout <<"\nOperation:"<< endl;
    cout << "Enter 1 to view data \nEnter 2 to modify librarian detail \nEnter 3 to add books \nEnter 4 to issue book \nEnter 5 to return book \n0 to close it\n";
    cin >> c;
    while (c != 0)
    {
        switch (c)
        {
        case 1:
            viewlibrarian();
            viewbook();
            viewstudent();
            break;
        case 2:
            modifylibrarian();
            break;

        case 3:
            n_book = addbook(n_book);
            break;

        case 4:
            n_student = Issue(n_student, n_book);
            break;
        case 5:
            n_student = Return(n_student, n_book);
            break;
        default:
            cout<<"Entered no is invalid"<<endl;
            break;
        }
        cout <<"\nOperation:"<< endl;
        cout << "Enter 1 to view data \nEnter 2 to modify librarian detail \nEnter 3 to add books \nEnter 4 to issue book \nEnter 5 to return book \n0 to close it\n";
        cin >> c;
    }
    return 0;
}