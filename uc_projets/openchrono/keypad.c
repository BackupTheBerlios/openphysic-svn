#define Nbuts 6
#define B_OK 0
#define B_CANCEL 1
#define B_LEFT 2
#define B_RIGHT 3
#define B_UP 4
#define B_DOWN 5


inline void SeekButtons(void)
{
    if ( !((PINB>>B_OK)&0x01) )
    { // OK
        StartStopChronometer();
    }

    if ( !((PINB>>B_CANCEL)&0x01) )
    { // CANCEL

    }

    if ( !((PINB>>B_LEFT)&0x01) )
    { // LEFT

    }

    if ( !((PINB>>B_RIGHT)&0x01) )
    { // RIGHT

    }

    if ( !((PINB>>B_UP)&0x01) )
    { // UP

    }

    if ( !((PINB>>B_DOWN)&0x01) )
    { // DOWN

    }
}
