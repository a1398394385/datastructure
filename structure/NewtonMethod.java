class NewtonMethod
{
    /**
     * 牛顿迭代法
     * 
     * @param x
     * @return
     */
    public int sqrt(int x) {
        if (x <= 1) return x;
        int r = x;
        while (r > x / r)
            r = (r + x / r) >>> 1;
        return r;
    }
}
