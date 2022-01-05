using System;

namespace OOP
{
    class SimpleClass
    {
        // Public Section
            // Ctors
            public SimpleClass()
            {
                m_x = 1;
                m_y = 1;

                increaseCounter();
            }
            public SimpleClass(int x, int y)
            {
                m_x = x;
                m_y = y;

                increaseCounter();  
            }

            public SimpleClass(SimpleClass otherObj)
            {
                m_x = otherObj.m_x;
                m_y = otherObj.m_y;

                increaseCounter();
            }

            // Getters & Setters
            public int getMemberX
            {
                get
                {
                    return m_x;
                }
            }
            public int setMemberX
            {
                set
                {
                    if (value >= 1)
                    {
                        m_x = value;
                    }
                    else
                    {
                        Console.Write("Since the passed value is greater or equal to 1, the member m_x could not be changed. Current value is : {0}", m_x);
                    }
                }
            }
            public int getMemberY
            {
                get
                {
                    return m_y;
                }
            }
            public int setMemberY
            {
                set
                {
                    if (value >= 1)
                    {
                        m_y = value;
                    }
                    else
                    {
                        Console.Write("Since the passed value is greater or equal to 1, the member m_x could not be changed. Current value is : {0}", m_y);
                    }
                }
            }

        // Private Section
            // For Functions
            private void increaseCounter()
            {
                ++m_counter;
            }

            // For members
            private int m_x;
            private int m_y;
            private static int m_counter;
    }
}



