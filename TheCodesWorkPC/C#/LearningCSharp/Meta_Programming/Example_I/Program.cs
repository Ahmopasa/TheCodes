using System;

class myDataStructure <T>{
    // Ctors
    public myDataStructure(int size = 1)
    {
        if (size >= 1)
        {
            m_size = size;
            m_dataHolder = new List<T>(m_size);
            Console.Write("An object of type [myDataStructure] has come to life.\nSize : " + m_size + "\n");
        }
        else
        {
            m_size = 1;
            m_dataHolder = new List<T>(m_size);
        }
    }

    // Properties
    public int handleSize
    {
        get
        {
            return m_dataHolder.Capacity;
        }
    }
    public void printElemens()
    {
        System.Console.WriteLine("Printing Elements;");
        foreach (T item in m_dataHolder)
        {
            Console.WriteLine("[" + item + "]");
        }
    }
    public void addElements(T value)
    {
        m_dataHolder.Add(value);
        System.Console.WriteLine("A brand new element has been added : " + value);
    }
    
    private List<T> m_dataHolder;
    private int m_size;
}

class ExampleOne{
    static void Main(string[] args)
    {
        const int SIZE = 5;
        myDataStructure<int> firstObject = new myDataStructure<int>();
        firstObject.printElemens();
        for (int i = 0; i < SIZE; i++)
        {
            Random myRandom = new Random();
            int x = myRandom.Next(100);
            firstObject.addElements(x);
        }
        firstObject.printElemens();
    }
}