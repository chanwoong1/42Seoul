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

-------------------

**file descriptor(fd)**

파일 디스크립터(File Descriptor)란 리눅스 혹은 유닉스 계열의 시스템에서 프로세스(process)가 파일(file)을 다룰 때 사용하는 개념으로, 프로세스에서 특정 파일에 접근할 때 사용하는 추상적인 값이다. 파일 디스크럽터는 일반적으로 0이 아닌 정수값을 갖는다. 

흔히 유닉스 시스템에서 모든 것을 파일이라고 한다. 일반적인 정규파일부터 디렉토리, 소켓, 파이프, 블록 디바이스, 케릭터 디바이스 등 모든 객체들을 파일로 관리한다. 유닉스 시스템에서 프로세스가 이 파일들을 접근할 때 파일 디스크립터라는 개념일 이용한다. 프로세스가 실행 중에 파일을 Open하면 커널은 해당 프로세스의 파일 디스크립터 숫자 중 사용하지 않는 가장 작은 값을 할당해준다. 그 다음 프로세스가 열려있는 파일에 시스템 콜을 이용해서 접근할 때, 파일 디스크립터(FD)값을 이용해서 파일을 지칭할 수 있다.

프로그램이 프로세스로 메모리에서 실행될 때, 기본적으로 할당되는 파일디스크립터는 표준입력(Standard Input), 표준 출력(Standard Output), 표준에러(Standard Error)이며 이들에게 각각 0, 1, 2라는 정수가 할당된다.

#### read
```C
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t count);
```
open(2), creat(2), socket(2), accept(2) 등으로 생성한 file descriptor로부터 데이터를 읽는다. 파일을 읽으면 읽은 size만큼 파일의 다음 읽을 위치가 이동됩니다. 읽을 위치가 파일의 끝에 도달하면 더 이상 읽을 데이터가 없으므로 0을 return한다.

**parameter**

- fd
    -  open(2), creat(2), socket(2), accept(2) 등을 통하여 정상적으로 open한 file descriptor
- buf
    - 읽을 데이터를 저장할 메모리 영역(buffer)
- count
    - 읽을 size (byte 수)

**return**

- 0보다 큰 수
    - 실제로 읽은 데이터 byte 수
    - 일반적으로 count와 같은 값을 return하지만, count보다 작은 경우에는 end of file에 도달하였거나, socket통신에서는 수신할 데이터가 아직 도착하지 않은 경우나 peer(상대)에서 socket을 close했을 때


- 0
    - end of file에 도달하여 더 이상 읽을 자료가 없는 경우


- -1
    - 오류가 발생한 경우이며 상세한 오류는 errno에 설정됨

	- ERRNO

		EAGAIN : file을 open할 때에 O_NONBLOCK flag이 설정되었으며, 
					현재 읽을 데이터가 없어서 read()함수를 바로 return함.
		
		EAGAIN or EWOULDBLOCK : fd가 socket이고 socket에 O_NONBLOCK으로 설정된 경우 
					읽을 데이터를 수신하지 못하여 바로 return함.
		
		EBADF :  fd가 유효하지 않은 file descriptor임.
		
		EFAULT : buf가 access할 수 없는 영역의 데이터 buffer임. 
					주로 변수를 pointer로 설정한 후에 malloc(3)하지 않은 경우
		
		EINTR : signal이 발생하여 interrupt됨.
		
		EINVAL : fd, buf, count 등의 변수가 잘못 설정된 경우. (예, count가 -값이 설정된 경우 등)
		
		EIO : I/O 오류. background process에서 terminal에 대한 I/O를 시도했다든 지...
		
		EISDIR : open된 fd가 directory인 경우

[![HitCount](https://hits.dwyl.com/Chanwoong1/Chanwoong1/42Seoul/Circle_1/Get_Next_Line.svg?style=flat-square)](http://hits.dwyl.com/Chanwoong1/Chanwoong1/42Seoul/Circle_1/Get_Next_Line)