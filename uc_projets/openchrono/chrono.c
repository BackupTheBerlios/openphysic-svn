/*
 * start or stop chronometer
 */
inline void StartStopChronometer(void)
{
    beep(1,100);
    led_alarm(3,50);
    if (running_chronometer)
    {
        //running_chronometer = false; // false = 0
        if (compare_time(&current_time,&best_time) == 1)
        {
            // better time them the best time
            copy_time(&current_time,&best_time);
            led_alarm(3,50);
        }
        if (compare_time(&current_time,&last_time) == 1)
        {
            // better time them the last time
            led_alarm(1,50);
        }
        copy_time(&current_time,&last_time);
        init_time(&current_time);
    }
    else
    {
        // this is before first lap (start from pit)
        running_chronometer = true; // true = -1
        // this is after first lap
    }
}


void TestRunningChronometer(void)
{
    if (running_chronometer)
    {
        switch_on_led(8);
        _delay_ms(100);
        switch_off_led(8);
        _delay_ms(100);
    }
}

