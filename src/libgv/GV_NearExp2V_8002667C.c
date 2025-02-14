void GV_NearExp2V_8002667C(short *a, short *b, int count)
{
    int ca, cb;
    int diff;
    int mid;

    while (--count >= 0)
    {
        ca = *a;
        cb = *b;
        
        diff = cb - ca;
        
        if ((diff > -2) && (diff < 2))
        {
            mid = cb;
        }
        else
        {
            mid = ca + diff / 2;
        }

        *a++ = mid;
        b++;
    } 
}
