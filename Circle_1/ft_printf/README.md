# ft_printf

## Contents
- [Chapter 1](#Chapter-1)
	- [가변 인자 함수](#가변-인자-함수)
- [Chapter 2](#Chapter-2)
- [Chapter 3](#Chapter-3)
- [Chapter 4](#Chapter-4)

## Chapter 1

그 동안 사용할 수 없었던 printf를 직접 구현하여 사용하게 된다.

printf 구현 시 가변 인자 함수를 배울 수 있다.

### 가변 인자 함수

함수를 만들 때 인자가 몇 개가 들어올 지 모를 때 사용한다. 기본적으로 하나의 인자는 포함되어야 사용할 수 있다.

```C
int	ft_printf(const char *format, ...)
```

### stdarg.h

가변 인자를 사용하기 위해서는 위와 같은 헤더를 포함시켜준다.

**va_list**

	현재 매개인자의 주소를 저장하는 타입
	1바이트 단위로 이동하기 위해서 va_list의 실제 타입은 char * 으로 사용되며 이는 va_arg에서의 포인터 연산에 활용된다. (__GNUC__ && __GNUC__ >= 3 에서는 컴파일러 별도의 타입을 사용..)
	보통 해당 자료형을 사용하는 변수명을 ap라고 작성하는데, 이는 arguments pointer를 뜻한다.

**va_start**

	va_list의 값을 가변인자의 첫 번째 매개변수의 값으로 초기화시킨다.
	매크로 함수의 인자로 들어오는 pN은 함수의 가변 인수 이전 마지막 매개인자이다.(... 이전의 마지막 인자) 가변인자를 사용할 때, (arg1, ...) 과 같이 활용하므로 ... 의 첫 번째 인자를 가리키기 위해서 pN의 다음 데이터를 가리키도록 인자를 변경해주고있다.

**va_end**

	가변인자를 모두 사용하고 난 후, ap의 값을 NULL로 변경한다.

**va_arg**

	va_list에 저장된 값을 바탕으로 현재 매개인자를 반환하고, va_list의 주소를 다음으로 이동시킨다.

## Chapter 2

### Common Instructions

**Makefile**

이제부터 libft의 함수들을 사용할 수 있다. 사용하기 위해서는 libft의 makefile로 먼저 libft의 라이브러리를 컴파일 한 다음, printf 프로그램을 컴파일 해야 한다.

## Chapter 3

### Mandatory Part

#### 1. 받아오는 인자의 유효성 검증

#### 2. 서식 지정자 탐색

#### 3. 

## Chapter 4