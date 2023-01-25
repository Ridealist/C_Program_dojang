#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    // 1. 서식을 지정해 파일에 문자열 쓰기

    // FILE 구조체는 <stdio.h> 헤더 파일에 정의되어 있음
    // 구조체 포인터 종류인 "파일 포인터"
    FILE *fp = fopen("../Hello.txt", "w");  // 파일을 쓰기 모드로 열기 -> 파일 포인터 반환

    // fopen("C://home/project/hello.txt",   ) -> 절대 경로도 가능
    // fopen("../Hello.txt",   ) -> 상대 경로도 가능

    fprintf(fp, "%s %d\n", "Hello", 100);  // 서식을 지정하여 파일에 문자열 저장

    // fprintf(stdout, ...) == printf(...) 와 완전히 동일!

    fclose(fp);  // 파일 포인터 닫기


    // 2. 서식을 지정해 파일에 문자열 읽기
    char s1[10];
    int num1;

    FILE *fpp = fopen("Hello.txt", "r");

    fscanf(fpp, "%s %d", s1, &num1);  // 서식을 지정하여 파일에서 문자열 읽기

    // fscanf(stdin, ...) == scanf(...) 와 완전히 동일!  ->  서식을 지정하여 표준 입력(stdin)에서 문자열 읽기

    printf("%s %d\n", s1, num1);    

    fclose(fpp);


    // 3. (서식 없이) 파일에 문자열 쓰기
    FILE *fppp = fopen("Hello.txt", "w");
    char *str1 = "Hello, world!";

    // 3-1. fputs()
    // fputs(버퍼, 파일포인터);
    fputs("Hello world!", fppp);

    // 파일 포인터 대신 stdout을 지정하면 표준 출력(화면)에 출력됨!
    // fputs("Hello world!", stdout);

    fclose(fppp); 
    
    FILE *fpppp = fopen("Hello.txt", "w");

    // 3-2. fwrite
    // fwrite(버퍼, 쓰기크기, 쓰기횟수, 파일포인터)
    fwrite(str1, strlen(str1), 1, fpppp);  // 문자열의 길이만큼 1번 파일에 저장

    fclose(fpppp); 


    // 4. (서식 없이) 파일에서 문자열 읽기
    char buffer[20];

    FILE *fp2 = fopen("Hello.txt", "r");

    // 4-1. fgets
    // fgets(버퍼, 버퍼크기, 파일포인터);
    // -> 이처럼 fgets 함수는 \n에 따라 읽은 결과가 달라지므로 사용에 주의!!!
    fgets(buffer, sizeof(buffer), fp2);

    printf("%s\n", buffer);    // Hello, world!: 파일의 내용 출력

    fclose(fp2);    // 파일 포인터 닫기

    // 4-2. fread
    char buf[20] = { 0, };    // 파일을 읽을 때 사용할 임시 공간, 미리 0으로 전부 초기화

    FILE *fp3 = fopen("hello.txt", "r");     // hello.txt 파일을 읽기 모드로 열기.
                                            // 파일 포인터를 반환

    // fread(버퍼, 읽기크기, 읽기횟수, 파일포인터);
    fread(buf, sizeof(buf), 1, fp3);   // hello.txt에서 버퍼 크기(20바이트)만큼 1번 값을 읽음
    // -> fread 함수는 fgets 함수와는 달리 \n이 있든 없든 무조건 지정된 크기만큼 읽음

    printf("%s\n", buf);    // Hello, world!: 파일의 내용 출력

    fclose(fp3);    // 파일 포인터 닫기   

    return 0;
}