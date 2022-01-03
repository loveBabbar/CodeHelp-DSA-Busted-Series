using System;
namespace DSA
{
    class Class_HammingWeight
    {
        // To test the code uncomment "Class_HammingWeight.Test();" in Main.cs and run the code
        
        public static void Test()
        {
            Console.WriteLine("\nEnter number: ");
            int number = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Set bits in {0} i.e {1} in binary = {2}", number, Convert.ToString(number, toBase: 2), HammingWeight(number));
        }

        private static int HammingWeight(int num)
        {
            int count = 0, bit = 0;
            while (num != 0)
            {
                bit = num & 1;
                if (bit == 1)
                    count++;
                num = num >> 1;
            }
            return count;
        }
    }
}