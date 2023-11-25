#include "String.h"
#include  "List.h"
class Student {
public:
    Student();
    Student(const char* name, size_t age);
    void Show() const;
    void AddMark(size_t m);
protected:
    String name;
    size_t age;
    List<size_t> marks;
};

inline Student::Student() : Student(nullptr, 0) {}

inline Student::Student(const char* name, size_t age) : name(name), age(age) {}

inline void Student::AddMark(size_t m) {
    marks.push_back(m);
}

inline void Student::Show() const
{
    cout << "Name: " << name << "\tage: " << age << "\nmarks: ";
    marks.print();
}