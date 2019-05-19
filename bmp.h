struct bmpheader {   
  char header[2]; // 2 bytes
  int size;  // 4 bytes
  short reserved1;  // 2 bytes
  short reserved2;  // 2 bytes
  int offset;  // 4 bytes
}__attribute__((packed));
typedef struct bmpheader BMP_header;

struct dibheader {   
  unsigned int size;
  signed int width;
  signed int height;
  unsigned short color_plane; 
  unsigned short bpp;
  unsigned int compression_method;
  unsigned int image_size;
  signed int h_resolution;  
  signed int v_resolution;  
  unsigned int color_used;
  unsigned int important_color;
}__attribute__((packed));
typedef struct dibheader DIB_header;