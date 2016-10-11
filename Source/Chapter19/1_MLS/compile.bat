vbc /nologo /target:module /out:student.netmodule student.vb
csc /nologo /target:module /out:tree.netmodule tree.cs
cl /nologo /clr:pure /FUstudent.netmodule /FUtree.netmodule test.cpp
