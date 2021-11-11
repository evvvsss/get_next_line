# get_next_line

CСылки на тесты:

1.https://github.com/Tripouille/gnlTester (самый лучший)

2.https://github.com/Mazoise/42TESTERS-GNL

3.https://github.com/charMstr/GNL_lover

4.https://github.com/mrjvs/42cursus_gnl_tests

++ короткий гнл 

int get_next_line(char **line)
{
 int rd = 0;
 int i = 0;
 char ch;
 char *buffer = malloc(100000);
 *line = buffer;
 while ((rd = read(0, &ch, 1)) > 0 && ch != '\n')
 buffer[i++] = ch;
 buffer[i] = '\0';
 return (rd);
}
