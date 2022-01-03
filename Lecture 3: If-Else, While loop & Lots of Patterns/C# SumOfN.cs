using System;
namespace DSA
{
    class Class_SumOfN
    {
        // To test the code uncomment "Class_SumOfN.Test();" in Main.cs and run the code
        public static void Test()
        {
            Console.WriteLine("\nEnter number: ");
            int number = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Sum till {0} (inclusive) = {1}", number, Sum(number));
        }
        private static int Sum(int number)
        {
            Console.WriteLine("Entered number = {0}", number);
            int i = 1, sum = 0;
            while (i <= number)
            {
                sum = sum + i;
                i = i + 1;
            }
            return sum;
        }
    }
}