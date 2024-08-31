int sqrt(long long int k)
{
    int s,i;
    for(i=1;i<=100000000;i++)
    {
        if((long long)i*i>k)
        {
            return i-1;
        }
    }

}

