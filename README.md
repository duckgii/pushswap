# pushswap
42서울의 2서클 과제입니다.

## 과제 소개
[소개 블로그](https://duckgi.tistory.com/12)

## 빌드
- 빌드 명령어
```
make
```

- 목적파일(.o)만 삭제
```
make clean
```
- 아카이브 파일(.a)까지 같이 삭제
```
make fclean
```

- fclean 후 다시 make
```
make re
```

- 파일 실행
```
./push_swap num1 num2 num3...
```

- 체커 실행 (숫자 배열을 넣고 해당 명령어를 수행하면 정렬이 완료되는지 확인해주는 프로그램)
```
./chcker  num1 num2 num3...
cmd1
cmd2
.
.
.
(cmd + d) -> 입력 완료
```
  - 정렬이 되는 경우 : OK 출력
  - 정렬이 되지 않는 경우 : KO 출력
  - 이상한 입력이 있는 경우 : Error 출력
