Imports System
Namespace Sample
    Public Class Student
        Implements IComparable(Of Student)
        ' Constructor
        Private Sub New(ByVal Id As Integer)
            Me.Id = Id
        End Sub
        ' IComparable
        Public Function CompareTo(ByVal other As Student) As Integer _
            Implements System.IComparable(Of Student).CompareTo
            Return Me.Id.CompareTo(other.Id)
        End Function
        Public Shared Function NewStudents(ByVal ParamArray Ids As Integer()) As Student()
            Dim students As Student() = New Student(Ids.Length - 1) {}
            Dim index As Integer = 0
            For Each id As Integer In Ids
                students(index) = New Student(id)
                index += 1
            Next
            Return students
        End Function
        Public Overrides Function ToString() As String
            Return String.Format("ID:{0}", Me.Id)
        End Function
        ' Fields
        Private Id As Integer
    End Class
    Module Run
    Sub Main()
        Dim students As Student() = Nothing
        students = Student.NewStudents(5, 2, 6, 8, 10, 9, 7, 1, 3, 4)
        For Each student As Student In students
            Console.WriteLine(student)
        Next
    End Sub
    End Module
End Namespace
