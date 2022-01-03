using System;
namespace DSA
{
    class Class_isPrime
    {
        // To test the code uncomment "Class_isPrime.Test();" in Main.cs and run the code
        public static void Test()
        {
            Console.WriteLine("\nEnter number to be checked: ");
            int number = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("is prime = {0}", isPrime(number));
        }
        private static bool isPrime(int number)
        {
            Console.WriteLine("Entered number = {0}", number);
            int i = 2;
            while (i < number)
            {
                if (number % i == 0)
                    return false;
                i = i + 1;
            }
            return true;
        }
    }
}