class sunOfNum{
    public static int sun(int n)
    {
       
        int temp = n%10;
        n=n/10;
        return  temp;

        int sum = sum +sun(n);
        if(n==0)
        return sum;

    }
    public static void main(String[] args) {
        int n=444;
        sun(n);
    }
    
}