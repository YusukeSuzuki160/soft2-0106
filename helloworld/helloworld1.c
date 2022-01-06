#include "calc_magicnumber.h"

int main(void) //環境はUbuntu(windows11,WSL2),vscodeで実装、実行。CPUはAMD RYZEN5
{
    char s[] = "Hello,World\n";
    float *f = parse_char_to_f32(s);

    // "Hello,World\n" と出力してほしい
    printf("%s", (char *)f);
    free(f);
    return 0;
}
