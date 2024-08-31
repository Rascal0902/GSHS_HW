int mid(int d, int b, int c)
{

    if(max(d,b)==b)
    {
        if(max(b,c)==c)
        {
            return b;
        }
        else if(min(d,c)==c)
        {
            return d;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if(max(d,c)==c)
        {
            return d;
        }
        else if(min(b,c)==c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }


}
