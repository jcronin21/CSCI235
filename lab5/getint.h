#ifndef _GETINT_H_
#define _GETINT_H_

int getch(void);

void ungetch(int c);

/* getint: get next integer from input to *pn */
int getint(int *pn);

#endif
