int get_gcd(int a, int b)
{
    int i,f=1;
    for(i=1;i<=a;i++)
    {
        if((a%i==0)&&(b%i==0))
        {
            f=i;
        }
    }
    return f;
}
