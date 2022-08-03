#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int main(void)
{
int i;
int j;

printf("%% test");
printf("f %%%%, [%%]\n");
printf("f %%5%%, [%5%]\n");
printf("f %%-5%%, [%-5%]\n");
printf("f %%05%%, [%05%]\n");
printf("f %%-05%%, [%-05%]\n");

printf("id basic test n width test \n");
printf("f %%i = 2147483647, [%i]\n", 2147483647);
printf("f %%d = -2147483648, [%d]\n", (int)(-2147483648));
printf("f %%d = 0, [%d]\n", 0);
printf("f %%7i = 33,  [%7i]\n", 33);
printf("f %%7d = -14, [%7d]\n", -14);
printf("f %%3i = 0, [%3i]\n", 0);
printf("f %%5d = 52625, [%5d]\n", 52625);
printf("f %%5i = -2562, [%5i]\n", -2562);
printf("f %%4d = 94827, [%4d]\n", 94827);
printf("f %%4i = -2464, [%4i]\n", -2464);
printf("f %%-7d = 33,  [%-7d]\n", 33);
printf("f %%-7i = -14, [%-7i]\n", -14);
printf("f %%-5i = 52625, [%-5i]\n", 52625);
printf("f %%-5d = -2562, [%-5d]\n", -2562);
printf("f %%-4d = 94827, [%-4d]\n", 94827);
printf("f %%-4i = -2464, [%-4i]\n\n", -2464);

printf("id precision test \n");
printf("f %%.i = 2, [%.i]\n", 2);
printf("f %%.d = -3, [%.d]\n", -3);
printf("f %%.5i = 2, [%.5i]\n", 2);
printf("f %%.6d = -3, [%.6d]\n", -3);
printf("f %%.3i = 0, [%.3i]\n", 0);
printf("f %%.5d = 5263,  [%.5d]\n", 5263);
printf("f %%.5d = -2372, [%.5d]\n", -2372);
printf("f %%.7i = 13862,  [%.7i]\n", 13862);
printf("f %%.7i = -23646, [%.7i]\n\n",-23646);

printf("id zero field width padding test \n");
printf("f %%05i = 43, [%05i]\n", 43);
printf("f %%07d = -54, [%07d]\n", -54);
printf("f %%03i = 0, [%03i]\n", 0);
printf("f %%04d = 634, [%04d]\n", 634);
printf("f %%04i = -532, [%04i]\n", -532);
printf("f %%04d = -4825, [%04d]\n\n", -4825);

printf("id width and precision test \n");
printf("f %%8.5i = 34, [%8.5i]\n", 34);
printf("f %%8.5i = 0, [%8.5i]\n", 0);
printf("f %%8.3d = 8375,  [%8.3d]\n", 8375);
printf("f %%8.3i = -8473, [%8.3i]\n", -8473);
printf("f %%3.7d = 3267,  [%3.7d]\n", 3267);
printf("f %%3.7i = -2375, [%3.7i]\n", -2375);
printf("f %%3.3d = 6983,  [%3.3d]\n", 6983);
printf("f %%3.3i = -8462, [%3.3i]\n", -8462);
printf("f %%-8.5i = 34, [%-8.5i]\n", 34);
printf("f %%-8.5i = 0, [%-8.5i]\n", 0);
printf("f %%-3.8d = 8375,  [%-3.8d]\n", 8375);
printf("f %%-3.8i = -8473, [%-3.8i]\n", -8473);
printf("f %%-3.7d = 3267,  [%-3.7d]\n", 3267);
printf("f %%-3.7i = -2375, [%-3.7i]\n", -2375);
printf("f %%-3.3d = 6983,  [%-3.3d]\n", 6983);
printf("f %%-3.3i = -8462, [%-3.3i]\n\n", -8462);

printf("id width and precision with zeropadding test \n");
printf("f %%08.5i = 34, [%08.5i]\n", 34);
printf("f %%010.5d = -216, [%010.5d]\n", -216);
printf("f %%08.5i = 0, [%08.5i]\n", 0);
printf("f %%08.3d = 8375,  [%08.3d]\n", 8375);
printf("f %%08.3i = -8473, [%08.3i]\n", -8473);
printf("f %%03.7d = 3267,  [%03.7d]\n", 3267);
printf("f %%03.7i = -2375, [%03.7i]\n", -2375);
printf("f %%03.3d = 6983,  [%03.3d]\n", 6983);
printf("f %%03.3i = -8462, [%03.3i]\n\n", -8462);

printf("id width and precision, left-justified with zeropadding test \n");
printf("f %%0-8.5i = 34, [%0-8.5i]\n", 34);
printf("f %%0-10.5d = -216, [%0-10.5d]\n", -216);
printf("f %%0-8.5i = 0, [%0-8.5i]\n", 0);
printf("f %%0-8.3d = 8375,  [%0-8.3d]\n", 8375);
printf("f %%0-8.3i = -8473, [%0-8.3i]\n", -8473);
printf("f %%0-3.7d = 3267,  [%0-3.7d]\n", 3267);
printf("f %%0-3.7i = -2375, [%0-3.7i]\n", -2375);
printf("f %%0-3.3d = 6983,  [%0-3.3d]\n", 6983);
printf("f %%0-3.3i = -8462, [%0-3.3i]\n\n", -8462);

printf("id zero test \n");
printf("f %%i = 0,   [%i]\n", 0);
printf("f %%5i = 0,   [%5i]\n", 0);
printf("f %%.0i = 0,   [%.0i]\n", 0);
printf("f %%.i = 0,    [%.i]\n", 0);
printf("f %%5.0i = 0,  [%5.0i]\n", 0);
printf("f %%5.i = 0,   [%5.i]\n", 0);
printf("f %%-5.0i = 0, [%-5.0i]\n", 0);
printf("f %%-5.i = 0,  [%-5.i]\n\n", 0);

printf("id space test \n");
printf("f %% i = 34, [% i]\n", 34);
printf("f %% d = -216, [% d]\n", -216);
printf("f %% 3.3d = 8375,  [% 3.3d]\n", 8375);
printf("f %% 3.3i = -8473, [% 3.3i]\n", -8473);
printf("f %% 8.3d = 8375,  [% 8.3d]\n", 8375);
printf("f %% 8.3i = -8473, [% 8.3i]\n", -8473);
printf("f %% 3.7d = 3267,  [% 3.7d]\n", 3267);
printf("f %% 3.7i = -2375, [% 3.7i]\n\n", -2375);

printf("id plus sign test \n");
printf("f %%+i = 34, [%+i]\n", 34);
printf("f %%+d = -216, [%+d]\n", -216);
printf("f %%+3.3d = 8375,  [%+3.3d]\n", 8375);
printf("f %%+3.3i = -8473, [%+3.3i]\n", -8473);
printf("f %%+8.3d = 8375,  [%+8.3d]\n", 8375);
printf("f %%+8.3i = -8473, [%+8.3i]\n", -8473);
printf("f %%+3.7d = 3267,  [%+3.7d]\n", 3267);
printf("f %%+3.7i = -2375, [%+3.7i]\n\n", -2375);

printf("id space with plus sign test \n");
printf("f %%+ i = 34, [%+ i]\n", 34);
printf("f %%+ d = -216, [%+ d]\n", -216);
printf("f %%+ 3.3d = 8375,  [%+ 3.3d]\n", 8375);
printf("f %%+ 3.3i = -8473, [%+ 3.3i]\n", -8473);
printf("f %%+ 8.3d = 8375,  [%+ 8.3d]\n", 8375);
printf("f %%+ 8.3i = -8473, [%+ 8.3i]\n", -8473);
printf("f %%+ 3.7d = 3267,  [%+ 3.7d]\n", 3267);
printf("f %%+ 3.7i = -2375, [%+ 3.7i]\n\n", -2375);

printf("u - unsigned int test \n");
printf("f %u\n", 4294967295u);
printf("%u\n", 42);
printf("Kashim a %u histoires à raconter\n", 1001);
printf("Il fait au moins %u\n", -8000);
printf("%u\n", -0);
printf("%u\n", 0);
printf("%u\n", INT_MAX);
printf("%u\n", INT_MIN);
printf("%u\n", INT_MIN - 1);
printf("%u\n", INT_MAX + 1);
printf("%%u 0000042 == |%u|\n", 0000042);
printf("%%u \t == |%u|\n", '\t');
printf("%%u Lydie == |%u|\n\n", 'L'+'y'+'d'+'i'+'e');

printf("X - unsigned hexadecimal test \n");
printf("f %%X = [%X]\n", 4294967295u);
printf("f %%-X = [%-X]\n", 42);
printf("f Kashim a [%X] histoires à raconter\n", 1001);
printf("f Il fait au moins [%X]\n", -8000);
printf("f %%08X = [%08X]\n", -0);
printf("f %%.8X = [%.8X]\n", 0);
printf("f %%#X = [%#X]\n", INT_MAX);
printf("f %%8.0X = [%8.0X]\n", INT_MIN);
printf("f %%0.8X = [%0.8X]\n", INT_MIN - 1);
printf("f %%8X = [%8X]\n", INT_MAX + 1);
printf("f %%8X 0000042 == |%8X|\n", 0000042);
printf("f %%-8X \t == |%-8X|\n", '\t');
printf("f %%-8.0X Lydie == |%-8.0X|\n\n", 'L'+'y'+'d'+'i'+'e');

printf("x - unsigned hexadecimal test \n");
printf("f %%x = [%x]\n", 4294967295u);
printf("f %%-x = [%-x]\n", 42);
printf("f Kashim a [%x] histoires à raconter\n", 1001);
printf("f Il fait au moins [%x]\n", -8000);
printf("f %%08x = [%08x]\n", -0);
printf("f %%.8x = [%.8x]\n", 0);
printf("f %%#x = [%#x]\n", INT_MAX);
printf("f %%8.0x = [%8.0x]\n", INT_MIN);
printf("f %%0.8x = [%0.8x]\n", INT_MIN - 1);
printf("f %%8x = [%8x]\n", INT_MAX + 1);
printf("f %%8x 0000042 == |%8x|\n", 0000042);
printf("f %%-8x \t == |%-8x|\n", '\t');
printf("f %%-8.0x Lydie == |%-8.0x|\n\n", 'L'+'y'+'d'+'i'+'e');

printf("p - pointer test \n");
printf("%p\n", NULL);
printf("%5p\n", NULL);
printf("%2p\n", NULL);
printf("%.p\n", NULL);
printf("%5.p\n", NULL);
printf("%2.p\n", NULL);;
printf("%9.2p\n", 1234);
printf("%2.9p\n", 1234);
printf("%.5p\n", 0);
printf("%.0p\n", 0);
printf("%5p\n\n", 0);

printf("c - char test \n");
printf("[%c]\n", 42);
printf("[Kashim a [%c] histoires à raconter\n", 1001);
printf("[Il fait au moins [%c]\n", -8000);
printf("[%c]\n", -0);
printf("[%c]\n", 0);
printf("[%c]\n", INT_MAX);
printf("[%4c]\n", 'c');
printf("[%-2c]\n", '\n');
printf("[%04c]\n", 'l');
printf("[% c]\n", 'y');
printf("[%c]\n", ' ');
printf("[%#c]\n", 'e');
printf("[%+c]\n", 's');
printf("[%.2c]\n", 't');
printf("[%c]\n", ' ');
printf("[%c]\n", 'f');
printf("[%c]\n", '\r');
printf("[%c]\n\n", '\t');


printf("s - string test \n");
printf("hello, %8s.\n", "gavin");
printf("%-8s\n", "testing testing");
printf("%08s%8.3s\n", "hello", "world");
printf("..%#8s stuff % 8s\n", "a", "b");
printf("this %s is empty\n", "");
printf("%s !", "Ceci n'est pas un \0 exercice !\n\n");
char *null_str = NULL;
printf("%s everywhere\n", null_str);

system("leaks test > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
} 