//========<<if-else>>========//

if (/* podmínka */)
{
    /* code 1 */
}
else
{
    /* code 1 */
}

/*-------------------------------------------------------------------------------------*
 *   +-----+   +--------+   +----+   +------+                                          *
 * >-|`if(`|->-|podmínka|->-|`){`|->-|code 1|->-+->----------->---------->------->-+-> *
 *   +-----+   +--------+   +----+   +------+   |                                  |   *
 *                                              |   +------+    +------+   +---+   |   *
 *                                              +->-|`else{`|->-|code 2|->-|`}`|->-+   *
 *                                                  +------+    +------+   +---+       *
 *-------------------------------------------------------------------------------------*/


//=========<<switch>>=======//

switch (/* proměnná */)
{
case /* compile-time konstanta */:
    /* code x */
    break;
default:
    /* code 2 */
    break;
}

/*------------------------------------------------------------------------------------------------------------------------------*
 *   +---------+   +--------+   +----+       +------+   +----------------------+   +---+   +------+       +--------+            *
 * >-|`switch(`|->-|promenná|->-|`){`|->-+->-|`case`|->-|compile-time konstanta|->-|`:`|->-|code x|->-+->-|`break;`|->-+        *
 *   +---------+   +--------+   +----+   |   +------+   +----------------------+   +---+   +------+   |   +--------+   |        *
 *                                       |                                                            |                |        *
 *                                       ^                                                            +->------------>-+        *
 *                                       |                                                                             |        *
 *                                       |                                                                             |        *
 *                                       +-<---------<----<----------<---<-------<----<--<----------<---<------------<-+        *
 *                                       |                                                                             |        *
 *                                       |   +----------+   +------+       +--------+                                  V  +---+ *
 *                                       +->-|`default:`|->-|code 2|->-+->-|`break;`|->-+----------->--->------------>-+->|`}`| *
 *                                           +----------+   +------+   |   +--------+   |                                 +---+ *
 *                                                                     |                |                                       *
 *                                                                     +->------->---->-+                                       *
 *------------------------------------------------------------------------------------------------------------------------------*/


//=========<<while>>=========//

while (/* podmínka */)
{
    /* code */
}

/*-------------------------------------------------------*
 *   +--------+   +--------+   +----+   +----+   +---+   *
 * >-|`while(`|->-|podmínka|->-|`)}`|->-|code|->-|`}`|-> *
 *   +--------+   +--------+   +----+   +----+   +---+   *
 *-------------------------------------------------------*/


//========<<do-while>>=======//

do
{
    /* code */
} while (/* podmínka */);

/*----------------------------------------------------------*
 *   +-----+   +----+   +---------+   +--------+   +----+   *
 * >-|`do{`|->-|code|->-|`}while(`|->-|podmínka|->-|`);`|-> *
 *   +-----+   +----+   +---------+   +--------+   +----+   *
 *----------------------------------------------------------*/


//==========<<for>>==========//

for (/* inicializace */; /* podmínka */; /* update */)
{
    /* code */
}

/*------------------------------------------------------------------------------------------------------------------------*
 *   +------+       +------------+       +---+       +--------+      +---+       +------+       +----+   +----+   +---+   *
 * >-|`for(`|->-+->-|inicializace|->-+->-|`;`|->-+->-|podmínka|->-+->|`;`|->-+->-|update|->-+->-|`){`|->-|code|->-|`}`|-> *
 *   +------+   |   +------------+   |   +---+   |   +--------+   |  +---+   |   +------+   |   +----+   +----+   +---+   *
 *              |                    |           |                |          |              |                             *
 *              +->---------------->-+           +->------------>-+          +->---------->-+                             *
 *------------------------------------------------------------------------------------------------------------------------*/


//=========<<funkce>>========//

/* typ */ /* jméno */(/* typ */ /* jméno prarametru */)
{
    /* code */
}

/*-------------------------------------------------------------------------------------------------------------*
 *       +---+          +-----+   +---+           +---+   +---------------+           +---+   +----+   +---+   *
 * >-+->-|typ|->-->-+->-|jméno|->-|`(`|->-+->-+->-|typ|->-|jméno parametru|->-+->-+->-|`{`|->-|code|->-|`}`|-> *
 *   |   +---+      |   +-----+   +---+   |   |   +---+   +---------------+   |   |   +---+   +----+   +---+   *
 *   |   +------+   |                     |   |                       +---+   |   |                            *
 *   +->-|`void`|->-+                     |   +-<-------<-----------<-|`,`|-<-+   |                            *
 *       +------+                         |                           +---+       |                            *
 *                                        |   +------+                            |                            *
 *                                        +->-|`void`|->------------>------->--->-+                            *
 *                                        |   +------+                            |                            *
 *                                        |                                       |                            *
 *                                        +->---------->------------>------->--->-+                            *
 *-------------------------------------------------------------------------------------------------------------*/


//===<<struct definition>>===//

typedef struct /* struct name */
{
    /* typ */ /* field name */;
} /* type name */;

/*-------------------------------------------------------------------------------------------------------------------------------------*
 *   +----------------+       +-----------+       +---+       +---+   +----------+   +---+       +---+       +---------+       +---+   *
 * >-|`typedef struct`|->-+->-|struct name|->-+->-|`{`|->-+->-|typ|->-|field name|->-|`;`|->-+->-|`}`|->-+->-|type name|->-+->-|`;`|-> *
 *   +----------------+   |   +-----------+   |   +---+   |   +---+   +----------+   +---+   |   +---+   |   +---------+   |   +---+   *
 *                        |                   |           |                                  |           |                 |           *
 *                        +->--------------->-+           +-<-------<--------------<-------<-+           +->------------->-+           *
 *-------------------------------------------------------------------------------------------------------------------------------------*/