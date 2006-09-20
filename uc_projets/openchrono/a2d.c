/*
 * convert from analog to digital (10 bits)
 */
unsigned short adcConvert10bit(uint8_t ch)
{
    //a2dCompleteFlag = 0;				// clear conversion complete flag
    ADMUX = ((ADMUX) & ~0x1F) | (ch & 0x1F);	// set channel ADC_MUX_MASK=0x1F
    ADCSRA |= (_BV(ADIF)); // clear hardware "conversion complete" flag
    ADCSRA |= (_BV(ADSC)); // start conversion

    //while(!a2dCompleteFlag);				// wait until conversion complete
    //while( bit_is_clear(ADCSR, ADIF) );		// wait until conversion complete
    while( bit_is_set(ADCSRA, ADSC) )
        ;		// wait until conversion complete

    // CAUTION: MUST READ ADCL BEFORE ADCH!!!
    return ((ADCL) | ((ADCH)<<8));	// read ADC (full 10 bits);
}

/*
 * convert from analog to digital (8 bits)
 * starts conversion, waits until conversion is done, and returns result
 */
unsigned char adcConvert8bit(unsigned char ch)
{
    // do 10-bit conversion and return highest 8 bits
    return adcConvert10bit(ch)>>2;			// return ADC MSB byte
}
