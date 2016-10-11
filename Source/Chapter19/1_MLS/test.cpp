#using "System.dll"
using namespace System;
using namespace Collections::Generic;
using namespace Sample;
generic <typename T>
where T : IComparable<T>
ref struct LList : public Tree<T>
{
    LinkedList<T> list;
    virtual void VisitLeaf(Leaf^ leaf) override
    {
        list.AddLast(leaf->data);
    }
    virtual void Dump()
    {
        for each (T t in list)
        {
            Console::WriteLine(t);
        }
    }
};
void main()
{
    array<Student^>^ students = Student::NewStudents(25, 46, 34, 12, 1);
    LList<Student^>^ ll = gcnew LList<Student^>();
    ll->Add(students);
    ll->Inorder();
    ll->Dump();
}
