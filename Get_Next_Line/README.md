# Get Next Line

## Chapter 1

### Goals
이 프로젝트는 당신의 콜렉션(아마 라이브러리)에 아주 편리한 함수를 추가하게 할 뿐만 아니라, C 프로그래밍에 있어서 아주 흥미롭고 새로운 개념인 '정적 변수'를 배울 수 있도록 도울 것입니다.

**정적 변수(Static Variable)**

정적변수는 함수 내부에서도 사용 가능하고, 전역에서도 사용 가능하다.

정적변수는 초기화해주지 않아도 0으로 초기화 된다.

내부에서 선언한 정적변수는 함수를 여러번 호출해도 한번만 초기화된다.

## Chapter 2

### Makefile


## Chapter 3

### Mandatory part - Get_next_line

|함수 이름|get_next_line|
|-|-|
|프로토타입|char *get_next_line(int fd);
|제출할 파일|get_next_line.c, get_next_line_utils.c, get_next_line.h|
매개변수	|읽어들일 파일의 디스크립터 (서술자)
반환값	|읽혀진 라인 : 한 줄이 제대로 읽힘 NULL : 읽을 라인이 더이상 없거나 에러 발생
사용가능한 외부 함수	|read, malloc, free
설명	|파일 디스크립터로부터 한 줄을 읽고, 반환하는 함수를 작성하시오.

