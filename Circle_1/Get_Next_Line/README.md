# Get Next Line

## Contents

- [Get Next Line](#Get-Next-Line)
  - [Contents](#contents)
  - [Chapter 1](#Chapter-1)
	- [Goals](#Goals)
  - [Chapter 2](#Chapter-2)
  	- [Common Instructions](#Common-Instructions)
  - [Chapter 3](#Chapter-3)
  	- [Mandatory part](#Mandatory-part)
	  - [read](#read)
	- [진행 과정](#진행-과정)
	- [주의 사항](#주의-사항)
  - [Chapter 4](#Chapter-4)
	- [Bonus part](#Bonus-part)



## Chapter 1

### Goals
이 프로젝트는 당신의 콜렉션(아마 라이브러리)에 아주 편리한 함수를 추가하게 할 뿐만 아니라, C 프로그래밍에 있어서 아주 흥미롭고 새로운 개념인 '정적 변수'를 배울 수 있도록 도울 것입니다.

**정적 변수(Static Variable)**

정적변수는 함수 내부에서도 사용 가능하고, 전역에서도 사용 가능하다.

정적변수는 초기화해주지 않아도 0으로 초기화 된다.

내부에서 선언한 정적변수는 함수를 여러번 호출해도 한번만 초기화된다.

## Chapter 2

### Common Instructions

makefile은 만들 필요가 없다.

메모리 누수를 신경 써야 한다. 보너스 파트를 linked-list로 할 것이라면 더더욱.

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

### 진행 과정

get_next_line 함수는 fd를 인자로 받는다. 받아온 fd와 컴파일 시 입력하는 -D 옵션으로 버퍼사이즈를 설정해주어 메모리 누수 없이 한 줄씩 읽어주면 된다.

기본적인 구조는 다음과 같다.
- fd, BUFFER_SIZE 검사하기
- buf 할당해서 read를 통해 저장하기
- backup의 상태에 따라
	- 백업 안에 개행문자가 있다면 개행 전까지 한 줄을 뽑아서 반환하기
	- 백업 안에 개행문자가 없다면 한번 더 read해서 backup에 저장하기
- 한 줄 반환, 다음 작업을 위해 백업 정리

### 주의 사항

메모리 누수에 민감해야한다.

```C++
char	*ft_strjoin(char *s1, char *s2)
{
	int		idx;
	int		size_s1;
	int		size_s2;
	char	*join;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (size_s1 + size_s2) + 1);
	if (!join)
		return (NULL);
	idx = 0;
	while (*s1)
		join[idx++] = *s1++;
	while (*s2)
		join[idx++] = *s2++;
	join[idx] = '\0';
	return (join);
}


static char	*read_buf(int fd, char **backup, char *buf)
{
	ssize_t	read_size;
	char	*new_backup;

	buf[BUFFER_SIZE] = '\0';
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = '\0';
		new_backup = ft_strjoin(*backup, buf);
		free(*backup);
		*backup = new_backup;
		if (ft_strchr(*backup) != -1)
			return (read_line(backup, buf));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (read_line(backup, buf));
}
```

while 문을 보면 backup과 buf를 합쳐줄 때, strjoin을 사용했다. strjoin은 함수 내에서 새로운 문자열을 할당 후, 반환하는 것으로 
```C++
*backup = ft_strjoin(*backup, buf); 
```
과 같이 썼을 경우, 기존 backup의 주소를 잃어버리게 된다. 이런 포인터를 '댕글링 포인터'라고 하며 다음과 같은 문제를 발생하게 한다.

- 메모리 접근시 예측 불가능한 동작
- 메모리 접근 불가 시 Segmentation fault
- 잠재적인 보안 위험 

이러한 유형의 문제는 다음과 같은 동작의 결과로 발생한다.

- 메모리 해제 후, 해제된 메모리에 접근
- 함수 호출에서 자동 변수를 가리키는 포인터의 반환

이런 경우에 주의하기 위해 새로운 backup을 잠시 저장하기 위한 공간을 설정한 뒤, 저장하고, 기존 backup을 해제한 뒤, 새로 저장된 backup을 기존 backup에 연결한다.

또, 인덱스 계산을 잘 해서 Segmentation fault가 발생하지 않도록 주의한다.

## Chapter 4

### Bonus part

보너스 파트는 크게 두 방법으로 진행할 수 있다. 기존 mandatory part의 코드에 배열을 추가하여 다중 fd에 대응할 수 있도록 하는 방법과, linked-list를 사용하여 대응하는 방법이 있다.

linked-list를 이용하는 방법으로 과제를 해결하였는데, 자세한 설명은 생략하도록 하겠다.
- [bonus.c](https://github.com/Chanwoong1/42Seoul/blob/master/Circle_1/Get_Next_Line/srcs/get_next_line_bonus.c)
- [utils_bonus.c](https://github.com/Chanwoong1/42Seoul/blob/master/Circle_1/Get_Next_Line/srcs/get_next_line_utils_bonus.c)

## 과제 수행 후 느낀 점

mandatory part를 끝낸 후, 배열로 bonus part를 해결하는 것은 생각보다 쉽게 구현할 수 있어 보였다. 나는 linked-list에 대해 조금 더 공부해보고 싶었기 때문에 이걸로 구현해 보았다.

처음에는 mandatory 코드를 수정하여 구현했는데, 결과는 잘 출력되지만, 메모리 누수를 잡는것이 굉장히 어려웠고, 처음부터 다시 코드를 짜게 되었다.

보너스 부분을 수행하는데만 3일이 넘게 걸린것같은데 그만큼 배울것도 알아가는것도 많았던 과제였다.