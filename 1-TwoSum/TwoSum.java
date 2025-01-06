// javac -d bin TwoSum.java
// java -cp bin TwoSum  (so I think you run java files, and I am telling it to find the compiled class in the bin?)

import java.util.HashMap;
import java.util.Map;

public class TwoSum {
    public static void main(String[] args) {
        twoSumHash(new int[] { 2, 7, 11, 15 }, 9);
        twoSumHash(new int[] { 3, 2, 4 }, 6);
        twoSumHash(new int[] { 3, 3 }, 6);
    }

    public static int[] twoSum(int[] nums, int target) {
        for (int x = 0; x < nums.length; x++) {
            for (int y = x + 1; y < nums.length; y++) {
                if (nums[x] + nums[y] == target) {
                    System.out.println(String.format("%d, %d equals %d", x, y, target));
                    return new int[] { x, y };
                }
            }
        }
        System.out.println("No Solution Founnd!");
        return null;
    }

    public static int[] twoSumHash(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int temp = target - nums[i];
            if (map.containsKey(temp)) {
                System.out.println(String.format("%d, %d equals %d", i, map.get(temp), target));
                return new int[] { i, map.get(temp) };
            }
            map.put(nums[i], i);
        }
        System.out.println("No Solution Founnd!");
        return null;
    }
}

/*
 * I find it odd that Map<Integer, Integer> -> HashMap<> works
 * I asume Map is an interface and HashMap is the class. But not doing HashMap<Integer, Integer>
 * is suprising. And also the fact I have to do Integer and not int.
 * I don't use Java so just something to look up one day.
 * 
 * Oh. Compiling and running is odd. I dont like the forcing of the class name
 * to be the file name. I need to play with that and see its limits.
 * For example, a class of enums and const that dont need to be in a class.
 * And then runing the .java and needing to reference the .class is odd.. 
 * Perhaps it is only an issue because I am not doing a project and the standard build system.
 */