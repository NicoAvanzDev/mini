#include "lzw/lzw.h"

int main()
{
    FILE* f_in = fopen("../lzw_in.txt", "rb");
    FILE* f_out = fopen("../lzw_out.txt", "wb");

    lzw_encode(f_in, f_out);

    fclose(f_in);
    fclose(f_out);

    f_out = fopen("../lzw_out.txt", "rb");

    lzw_decode(f_out, NULL);

    fclose(f_out);

    return 0;
}
