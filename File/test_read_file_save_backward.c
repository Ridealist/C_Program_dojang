#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer;
    int size;

    FILE *fp = fopen("words.txt", "r");

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);

    rewind(fp); // TODO 파일 사이즈 측정을 위해 fp를 뒤로 옮겼으면, 다시 앞으로 돌려놔줘야 함

    buffer = (char *)malloc(size + 1);
    memset(buffer, 0, size + 1);

    fread(buffer, size, 1, fp);

    // TODO fwrite는 버퍼로 포인터를 받으므로 &buffer[i]와 같이 앞에 &를 붙여서 해당 요소의 주소(포인터)를 넣어야 함
    for (int i = size - 1; i >= 0; i--) {   // fwrite을 반복해서 저장하면 뒤에 계속 이어서 파일 내용 저장됨.
        fwrite(&buffer[i], sizeof(char), 1, stdout);
    }
    printf("\n");
    
    return 0;
}