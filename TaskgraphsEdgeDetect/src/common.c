#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "config.h"

void rgbToGrayscale(int input_image[H][W * 3], int output_image[H][W])
{
    int i, j, jj;

    for (i = 0; i < H; i++)
    {
        for (j = 0, jj = 0; j < W; j++, jj += 3)
        {
            int r = input_image[i][jj];
            int g = input_image[i][jj + 1];
            int b = input_image[i][jj + 2];

            float gray = 0.299 * r + 0.587 * g + 0.114 * b;
            output_image[i][j] = (int)floor(gray);
        }
    }
}

void initialize(int temp_buf[H][W], int output[H][W])
{
    int i, j;

    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            temp_buf[i][j] = 0;
            output[i][j] = 0;
        }
    }
}

void combthreshold(int image_gray[H][W], int temp_buf[H][W], int output[H][W])
{
    int i, j;
    int temp1;
    int temp2;
    int temp3;

    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; ++j)
        {
            temp1 = abs(image_gray[i][j]);
            temp2 = abs(temp_buf[i][j]);
            temp3 = (temp1 > temp2) ? temp1 : temp2;
            output[i][j] = (temp3 > T) ? 255 : 0;
        }
    }
}

void input_dsp(int buf[H][W * 3])
{
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W * 3; j++)
        {
            if (i > 5 && i < H - 5)
            {
                if (j == 5 || j == W * 3 - 5)
                {
                    buf[i][j] = 200;
                    buf[i][j - 1] = 200;
                    buf[i][j - 2] = 200;
                    buf[i][j - 3] = 200;
                    buf[i][j - 4] = 200;
                }
            }
            else if (i == 5 || i == H - 5)
            {
                if (j >= 5 && j <= W * 3 - 5)
                {
                    buf[i][j] = 200;
                    buf[i - 1][j] = 200;
                    buf[i - 2][j] = 200;
                    buf[i - 3][j] = 200;
                    buf[i - 4][j] = 200;
                }
            }
            else
            {
                buf[i][j] = 0;
            }
        }
    }
}

int checksum(int buf[H][W])
{
    int n = 0;
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            n += buf[i][j];
        }
    }
    printf("Checksum: %d\n", n);
    return n;
}

void output_dsp(int buf[H][W])
{
    for (int i = 0; i <= W + 1; i++)
        printf("_");
    printf("\n");

    for (int i = 0; i < H; i++)
    {
        printf("|");
        for (int j = 0; j < W; j++)
        {
            char c = buf[i][j] == 0 ? ' ' : (buf[i][j] > 0 ? 'X' : 'O');
            printf("%c", c);
        }
        printf("|\n");
    }
    for (int i = 0; i <= W + 1; i++)
        printf("_");
    printf("\n\n");
}