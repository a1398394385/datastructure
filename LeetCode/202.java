import java.util.HashSet;
import java.util.Set;

class Solution
{
    Set<Integer> set = new HashSet<>();

    int[] square = new int[] {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

    public boolean isHappy(int x) {
        return name(x);
    }

    public boolean name(int num) {
        if (set.contains(num)) return false;
        set.add(num);
        int sum = 0;
        while (num > 0) {
            sum += square[num % 10];
            num /= 10;
        }
        if (sum == 1) return true;
        return name(sum);
    }

    public boolean isHappy1(int n) {
        int fast = n;
        int slow = n;
        do {
            slow = squareSum(slow);
            fast = squareSum(fast);
            fast = squareSum(fast);
        } while (slow != fast);
        if (fast == 1)
            return true;
        else
            return false;
    }

    private int squareSum(int m) {
        int sum = 0;
        while (m != 0) {
            sum += (m % 10) * (m % 10);
            m /= 10;
        }
        return sum;
    }
}
