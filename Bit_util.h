#define SET(reg, val) reg |= val

#define CLR(reg, val) reg &= ~val

#define SET_BIT(reg, bit) reg |= (1 << bit)

#define GET_BIT(reg, bit) ((reg >> bit) & 1)

#define CLR_BIT(reg, bit) reg &= ~(1 << bit)