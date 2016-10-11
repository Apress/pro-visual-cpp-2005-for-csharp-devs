using System;
using System.Collections.Generic;
namespace Sample
{
    public class Tree<T> where T : IComparable<T>
    {
        public class Leaf
        {
            public Leaf left = null;
            public Leaf right = null;
            public T data;
            public Leaf(T data)
            {
                this.data = data;
            }
            public static bool operator>=(Leaf lhs, Leaf rhs)
            {
                return lhs.data.CompareTo(rhs.data) >= 0;
            }
            public static bool operator<=(Leaf lhs, Leaf rhs)
            {
                return lhs.data.CompareTo(rhs.data) <= 0;
            }
            public override string ToString()
            {
                return data.ToString();
            }
        }
        public Leaf root = null;
        public void Add(T[] adata)
        {
            foreach(T data in adata)
            {
                Add(data);
            }
        }
        public void Add(T data)
        {
            Leaf leaf = new Leaf(data);
            if (root == null)
            {
                root = leaf;
            }
            else
            {
                Leaf current = root;
                for (;;)
                {
                    if (current >= leaf)
                    {
                        if (current.left == null)
                        {
                            current.left = leaf;
                            break;
                        }
                        else
                        {
                            current = current.left;
                        }
                    }
                    else
                    {
                        if (current.right == null)
                        {
                            current.right = leaf;
                            break;
                        }
                        else
                        {
                            current = current.right;
                        }
                    }
                }
            }
        }
        public virtual void VisitLeaf(Leaf leaf)
        {
            Console.WriteLine(leaf);
        }
        private void DoInorder(Leaf leaf)
        {
            if (leaf==null)
            {
                return;
            }
            DoInorder(leaf.left);
            VisitLeaf(leaf);
            DoInorder(leaf.right);
        }
        public virtual void Inorder()
        {
            DoInorder(root);
        }
    }
    class Test
    {
        public static void Main()
        {
            Tree<int> tree = new Tree<int>();
            tree.Add(3);
            tree.Add(1);
            tree.Add(5);
            tree.Inorder();
        }
    }
}
