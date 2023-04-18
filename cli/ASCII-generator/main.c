#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)
typedef struct {
   unsigned char signature[2];
   unsigned int fileSize;
   unsigned short reserved1;
   unsigned short reserved2;
   unsigned int dataOffset;
} BMPHeader;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct {
   unsigned int headerSize;
   int width;
   int height;
   unsigned short planes;
   unsigned short bitsPerPixel;
   unsigned int compression;
   unsigned int imageSize;
   int xResolution;
   int yResolution;
   unsigned int colorsUsed;
   unsigned int colorsImportant;
} BMPInfoHeader;
#pragma pack(pop)

char getPixel(unsigned char r, unsigned char g, unsigned char b) {
	unsigned char gray = (r + g + b) / 3;
	char grayChars[68] = {'@','B','%','8','&','W','M','#','*','o','a','h','b','k','d','p','q','w','m','Z','O','0','Q','L','C','J','U','Y','X','z','c','v','u','n','x','r','j','f','t','/','|','(',')','1','{','}','[',']','?','-','_','+','~','<','>','i','!','l','I',';',':',',','\\','^','`','.'};

	return grayChars[(67 * gray) / 255];
}

void printColors(const char* filename) {
   BMPHeader header;
   BMPInfoHeader infoHeader;

   unsigned char* buffer;
   int rowSize;
   int x, y;
   unsigned char r, g, b;

	// open file (read-binary)
   FILE* fptr = fopen(filename, "rb");

	// check if file exists
   if (fptr == NULL) {
		printf("Unable to read fptrn%s", filename);
      return;
   }

	// read file and add content to the header
   fread(&header, sizeof(BMPHeader), 1, fptr);
   if (header.signature[0] != 'B' || header.signature[1] != 'M') {
		printf("Invalid file format");
      fclose(fptr);
      return;
   }

	// read file and add content to the info header
   fread(&infoHeader, sizeof(BMPInfoHeader), 1, fptr);
   if (infoHeader.bitsPerPixel != 24) {
		printf("Invalid pixel format (BPP: %d instead of 24)", infoHeader.bitsPerPixel);
      fclose(fptr);
      return;
   }

	// calculate bytes in row (4-byte)
   rowSize = ((infoHeader.width * 3 + 3) / 4) * 4;
   buffer = (unsigned char*)malloc(rowSize * infoHeader.height);
   fseek(fptr, header.dataOffset, SEEK_SET);
   fread(buffer, 1, rowSize * infoHeader.height, fptr);
   fclose(fptr);

   for (y = 0; y < infoHeader.height; y++) {
      for (x = 0; x < infoHeader.width; x++) {
			int index = (y * infoHeader.width + x) * 3;
         b = buffer[index];
         g = buffer[index + 1];
         r = buffer[index + 2];
         printf("%s", getPixel(r,g,b));
      }

		printf("\n");
   }

   free(buffer);
}

int main(int argc, char* argv[]) {

	printColors(argv[1]);

	return 0;
}
