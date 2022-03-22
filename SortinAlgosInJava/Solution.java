public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int arrayLength = nums.length;
        int result[] = new int[2];
        boolean flag = true;
        for (int i = 0; i < arrayLength && flag; i++)
        {
            for (int j = i + 1; j < arrayLength && flag; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                //	System.out.println(i + j);
                    result[0] = i;
                    result[1] = j;
                    flag = false;
                }
            }
        }
        return (result);
    }

}