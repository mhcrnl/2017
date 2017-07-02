#include <stdio.h>

int main(int argc, char **argv)
{
    FILE* sourceFile;
    FILE* destFile;
    char buf[50];
    int numBytes;

    if(argc!=3)
    {
        printf("Usage: fcopy source destination\n");
        return 1;
    }

    sourceFile = fopen(argv[1], "rb");
    destFile = fopen(argv[2], "wb");

    if(sourceFile==NULL)
    {
        printf("Could not open source file\n");
        return 2;
    }
    if(destFile==NULL)
    {
        printf("Could not open destination file\n");
        return 3;
    }

    while(numBytes=fread(buf, 1, 50, sourceFile))
    {
        fwrite(buf, 1, numBytes, destFile);
    }

    fclose(sourceFile);
    fclose(destFile);

    return 0;
}
