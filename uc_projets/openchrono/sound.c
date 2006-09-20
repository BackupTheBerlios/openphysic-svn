/*
 * send a sound (on or more beep(s))
 */
void beep(uint8_t n, double delay)
{
    // TO DO
    uint8_t i;
    for(i = 1; i<=n; i++)
    {
        //TO DO : send a beep
        if (n>1)
        {
            _delay_ms(delay);
        }
    }
}
