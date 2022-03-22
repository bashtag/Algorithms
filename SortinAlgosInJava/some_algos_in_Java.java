public class some_algos_in_Java {

    public static void main(String[] args) {
		// TODO Auto-generated method stub

		Solution solution = new Solution();
        int result[] = new int[] {2,7,11,15};
		int ques[] = solution.twoSum(result, 9);
		for (int i = 0; i < ques.length; i++)
			System.out.println(ques[i]);
	}
}