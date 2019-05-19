#include <stdio.h>
#include <assert.h>
#include "bmp.h"

#define W 593 
#define H 600

int main(void)
{
  FILE *fp;
  BMP_header bh;
  DIB_header dh;
  unsigned char pix[H][(W * 24 + 31) / 32 * 4], avg;
  unsigned char b, g, r;
  int i, j, ind;

  fp = fopen("mybmp.bmp", "r");
  assert(fp != NULL);

  fread(&bh, 14, 1, fp);
  fread(&dh, 40, 1, fp);
  fread(pix, 1, dh.image_size, fp);
  fclose(fp);

  for (i = 0; i < dh.height; i++)
    for (j = 0; j < dh.width; j++) {
      b = pix[i][3 * j];
      g = pix[i][3 * j + 1];
      r = pix[i][3 * j + 2];
      avg = (b + g + r) / 3;
      pix[i][3 * j] = pix[i][3 * j + 1] = pix[i][3 * j + 2] = avg;
    }

  fp = fopen("my-gray.bmp", "w");
  assert(fp != NULL);
  
  fwrite(&bh, 14, 1, fp);
  fwrite(&dh, 40, 1, fp);
  fwrite(pix, 1, dh.image_size, fp);
  
  fclose(fp);
  return 0;
}
