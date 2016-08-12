// #define MY_CONDITION

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace attribute_csharp
{
    public class myClass
    {
        [Conditional("MY_CONDITION")]
        public static void Message(string msg)
        {
            Console.WriteLine(msg);
        }
    }

    public class timePeriod
    {
        private double seconds;
        public double hours
        {
            get { return seconds * 3600; }
            set { seconds = hours * 3600; }
        }
    }
    class Program
    {
        static void function1()
        {
            myClass.Message("In function 1.");
            function2();
        }
        static void function2()
        {
            myClass.Message("In function 2.");
        }
        static void Main(string[] args)
        {
            myClass.Message("In function main.");
            function1();
            Console.ReadKey();
        }
    }
}
