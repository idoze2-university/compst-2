/* Ido Zeira 322607177
*/
#include <stdio.h>
#include "ex1.h"

/* function to show bytes in memory, from location start to start+n*/
void show_mem_rep(char *start, int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%02x|", start[i]);
    printf("\n");
}

/*
Returns wether or not the machine is big endian.
 */
int is_big_endian()
{
    int i = 1;
    char *c = (char *)&i;
    // c = |01|00|00|00| for little endian --> *c = 01 = True
    // c = |00|00|00|01| for big    endian --> *c = 00 = False
    // We flip the answer to get the correct return value.
    return !(*c);
}

/*
Copies the first 4 bytes of X and last 4 bytes of Y to a new long and returns it.
Algorithm changes depending on endianess.
 */
unsigned long merge_bytes(unsigned long x, unsigned long int y)
{
    unsigned long ret = 0;
    char *_ret = (char *)&ret;
    char *_x = (char *)&x;
    char *_y = (char *)&y;
    int i = 0;
    int flag = is_big_endian();
    for (; i < 4; i++)
    {
        //inline: if big endian, copy bytes MSB to MSB+3 from X to ret , else copy bytes LSB to LSB+3 from Y to ret.
        _ret[i] = flag ? *(_x + i) : *(_y + i);
    }
    for (; i < 8; i++)
    {
        //inline: if big endian, copy bytes MSB+4 to MSB+7 from Y to ret , else copy bytes LSB+4 to LSB+7 from X to ret.
        _ret[i] = flag ? *(_y + i) : *(_x + i);
    }
    return ret;
}
/*
Copies word b to index i in x;
*/
unsigned long put_byte(unsigned long x, unsigned char b, int i)
{
    unsigned long ret = x;
    char *_ret = (char *)&ret;
    int flag = is_big_endian();
    //inline: if big endian, copy to index MSB+i, else copy to index MSB+7-1 which is LSB+i.
    _ret[flag ? i : 7 - i] = *((char *)&b);
    return ret;
}