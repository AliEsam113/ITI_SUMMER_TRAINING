/******************************************************/
/* Author    : Ahmed Abd Elghaffar                    */
/* Date      : 22 Jul 2022                            */
/* Version   : V01                                    */
/******************************************************/
#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(VAR,BIT)          VAR |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT)          VAR &= ~(1 << (BIT)) 
#define GET_BIT(VAR,BIT)          ((VAR >> BIT) & 1  )
#define TOG_BIT(VAR,BIT)          VAR ^=  (1 << (BIT))


#endif /* BIT_MATH_H */