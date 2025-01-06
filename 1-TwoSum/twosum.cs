// NOTE: for simplicity, no safety or structure is added
// mcs twosum.cs -out:bin/twosumcs (mono compiler)

using System;
using System.Collections.Generic;

namespace Pizza
{
    public static class Program
    {
        static void Main(string[] args)
        {
            var result = TwoSumHash(new int[] { 2, 7, 11, 15 }, 9);
            Console.WriteLine($"indicies ({result[0]}, {result[1]}) equal 9");

            result = TwoSumHash(new int[] { 3, 2, 4 }, 6);
            Console.WriteLine($"indicies ({result[0]}, {result[1]}) equal 6");

            result = TwoSumHash(new int[] { 3, 3 }, 6);
            Console.WriteLine($"indicies ({result[0]}, {result[1]}) equal 6");
        }

        static int[] TwoSum(int[] nums, int target)
        {
            for (int x = 0; x < nums.Length; x++)
            {
                for (int y = x + 1; y < nums.Length; y++)
                {
                    if ((nums[x] + nums[y]) == target)
                        return new int[] { x, y };
                }
            }

            throw new Exception("pizza pizza");
        }

        static int[] TwoSumHash(int[] nums, int target)
        {
            // Value, Index
            Dictionary<int, int> cache = new Dictionary<int, int>();
            cache[nums[0]] = 0; // add the first so we can start the loop at pos 2
            for (int i = 1; i < nums.Length; i++)
            {
                int difference = target - nums[i];
                if (cache.ContainsKey(difference))
                    return new int[] { i, cache[difference] };

                cache[nums[i]] = i;
            }

            throw new Exception("pizza pizza");
        }
    }
}