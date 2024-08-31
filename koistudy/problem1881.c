long long int lcm(int c, int d)
{
    int s;
    long long int k;
    s=gcd(c,d);
    k=(long long)c*d/s;
    return k;


}
