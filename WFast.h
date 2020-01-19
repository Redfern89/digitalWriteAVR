/*
 * WFast.h
 *
 * Created: 19.01.2020 7:29:49
 *  Author: redfern89
 *  Idea: https://github.com/NicksonYap/digitalWriteFast
 */ 


#ifndef WFAST_H_
#define WFAST_H_

// Service functions
#ifndef bitRead
#define bitRead(value, bit) ((value) & (1UL << (bit)))
#endif

#ifndef bitSet
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#endif

#ifndef bitClear
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#endif

#ifndef bitWrite
#define bitWrite(value, bit, bitValue) (bitValue ? bitSet(value, bit) : bitClear(value, bit))
#endif

#ifndef HIGH
#define HIGH 1
#endif

#ifndef LOW
#define LOW 0
#endif

#ifndef OUTPUT
#define OUTPUT 1
#endif

#ifndef INPUT
#define INPUT 0
#endif

// digital port addressing

// PORTB
#ifndef B0
#define B0 0
#endif

#ifndef B1
#define B1 1
#endif

#ifndef B2
#define B2 2
#endif

#ifndef B3
#define B3 3
#endif

#ifndef B4
#define B4 4
#endif

#ifndef B5
#define B5 5
#endif

#ifndef B6
#define B6 6
#endif

#ifndef B7
#define B7 7
#endif


// PORTC
#ifndef C0
#define C0 8
#endif

#ifndef C1
#define C1 9
#endif

#ifndef C2
#define C2 10
#endif

#ifndef C3
#define C3 11
#endif

#ifndef C4
#define C4 12
#endif

#ifndef C5
#define C5 13
#endif

#ifndef C6
#define C6 14
#endif

#ifndef C7
#define C7 15
#endif

// PORTD
#ifndef D0
#define D0 16
#endif

#ifndef D1
#define D1 17
#endif

#ifndef D2
#define D2 18
#endif

#ifndef D3
#define D3 19
#endif

#ifndef D4
#define D4 20
#endif

#ifndef D5
#define D5 21
#endif

#ifndef D6
#define D6 22
#endif

#ifndef D7
#define D7 23
#endif

#define __digitalPinToPORTReg(P) \
(((P) >= 0 && (P) <= 7) ? &PORTB : \
(((P) >= 8 && (P) <= 15) ? &PORTC : &PORTD))

#define __digitalPinToDDRReg(P) \
(((P) >= 0 && (P) <= 7) ? &DDRB : \
(((P) >= 8 && (P) <= 15) ? &DDRC : &DDRD))

#define __digitalPinToPINReg(P) \
(((P) >= 0 && (P) <= 7) ? &PINB : \
(((P) >= 8 && (P) <= 15) ? &PINC : &PIND))

#define __digitalPinToBit(P) \
(((P) >= 0 && (P) <= 7) ? P : \
(((P) >= 8) && (P) <= 15) ? (P) - 7 : (P) - 23)

#if (defined(__AVR__))
#ifndef digitalWrite
#define digitalWrite(P, V) \
bitWrite( *__digitalPinToPORTReg(P), __digitalPinToBit(P), (V) );
#endif

#ifndef pinMode
#define pinMode(P, V) \
bitWrite( *__digitalPinToDDRReg(P), __digitalPinToBit(P), (V));
#endif

#ifndef digitalRead
#define digitalRead(P) \
bitRead( *__digitalPinToPINReg(P), __digitalPinToBit(P) );
#endif
#else
#error Non-AVR device, not supported
#endif

#endif /* WFAST_H_ */
