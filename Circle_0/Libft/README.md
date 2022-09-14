# LIBFT

## Contents

- [Libft](#libft)
  - [Contents](#contents)
  - [나만의 라이브러리 만들기](#나만의-라이브러리-만들기)
	- [1. memory](#1.-memory)
	- [2. bonus(linked list)](#2.-bonus(linked-list))
  - [try](#try-(104점))
  - [retry](#retry-(105점))
  - [2nd retry](#2nd-retry-(125점))
  - [느낀 점](#과제-수행-후-느낀-점)

## 나만의 라이브러리 만들기

향후 42seoul 본과정에서 계속 쓰일 함수들을 만들고, 모듈화 시켜서 지속적으로 사용하게 된다.

모든것을 자기 손으로 직접 만들어보라는 42의 뜻이지 않을까 싶다.

-----------------------

웬만한 것들은 라피신 기간동안 했던 것들이나, 조금씩 달라지거나 아예 처음 만들어야하는 함수들도 있었다.

그것들 위주로 소개해보려 한다.

----------------------

### 1. memory

memory 부분은 string 부분과 다르게 공백문자일 경우 반환하지 않고, 공백 문자가 들어간 공간도 하나의 공간으로 생각해서 비교, 복사, 이동할 수 있다는 것이 인상깊었다.

또한, memcpy와 memmove의 기능은 거의 흡사한데, memcpy의 경우 dst와 src의 메모리 주소값이 겹칠 경우, 초기값을 저장하지 않아 주소값을 잃어버릴 수도 있지만, move의 경우는 겹칠 경우도 고려해야해서 조금 더 안정적이라는 것을 알 수 있었다.

```C
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
```

```C
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dst == src || len == 0)
		return (dst);
	if (dst < src)
	{
		d = (unsigned char *)dst;
		s = (unsigned char *)src;
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = (unsigned char *)dst + (len - 1);
		s = (unsigned char *)src + (len - 1);
		while (len--)
			*d-- = *s--;
	}
	return (dst);
}
```

### 2. bonus(linked list)

bonus 파트는 구조체를 통한 연결리스트 사용을 중점적으로 알아야 하는데, 많이 사용하지 않았던 개념이라 이해하는데에 시간이 좀 걸렸다.

bonus 파트에서 앞서 만든 연결리스트 함수들을 사용해야 하는 함수인 lstmap애 대해서만 알아보자면,


```C
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_next;
	t_list	*tmp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = ft_lstnew((f(lst->content)));
	if (new_lst == NULL)
		return (NULL);
	tmp = new_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		new_next = ft_lstnew(f(lst->content));
		if (new_next == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		tmp->next = new_next;
		tmp = new_next;
		lst = lst->next;
	}
	return (new_lst);
}
```


이런식으로 만들었는데, 기존 lst를 통해 함수 f를 적용하여 새로운 리스트를 반환하게 한다. 생성 도중 오류가 발생하게 된다면, 지금까지 만들었던 리스트들을 삭제하고 NULL을 반환하게 한다.

-------------------

## try (104점)

테스트기를 충분히 활용하였고, 모든 함수에 문제가 없다고 판단하여 제출하였으나, strrchr부분에서 문제가 발생하였다. 어떤 부분이 틀렸는지 명확하게 나오지 않아서 혼란스러웠다.

```C
char	*ft_strrchr(const char *s, int c)
{
	const char	*ss;

	ss = s;
	while (*s)
		s++;
	while (*s != (unsigned char)c)
	{
		if (*s == *ss)
			return (0);
		s--;
	}
	return ((char *)s);
}
```

이 부분인데, 모든 경우의 테스트를 통과했음에도 기계평가에서 오류가 발생하여 틀렸다고 나왔다.

-> 수정 : c를 unsigned char 형으로 변환시켰는데, 이 부분이 char 형인 s와 unsigned char인 c를 비교하는 과정에서 오류가 발생한 것이 아닐까 싶어서 (char)c 로 수정하여 제출할 에정이다.

-----------------------

## retry (105점)

```C
char	*ft_strrchr(const char *s, int c)
{
	const char	*ss;

	ss = s;
	while (*s)
		s++;
	while (*s != (char)c)
	{
		if (*s == *ss)
			return (0);
		s--;
	}
	return ((char *)s);
}
```

또 틀렸다. 형태의 문제가 아니었다.

다시 봤더니 while문 안의 if문의 조건이 잘못되었다. *를 붙이지 않아야 주소값을 비교해서 맨 처음까지 갈 수 있다. *를 붙였더니 맨 첫 주소값이 참조하는 값과 중간의 값이 같을 경우, 중간에서 while문이 끝나게 된다.

-> 수정 if문 안의 * 제거

------------------

## 2nd retry (125점)

드디어 고친것이 맞았다. 그 동안 평가 하면서 어떤게 틀렸는지 함께 고민해주신 동료 카뎃분들께 감사...

## 과제 수행 후 느낀 점

본과정 들어와서 첫 과제였는데, 생각보다 예외처리 사항이나, 만들어야하는 함수가 많아서 힘든 과제였던 것 같다. libft를 한번 만들어놓으면 향후 과제 수행에 계속 쓴다고 하니 잘 만들어 두어야 나중에 고생하지 않는다고 한다.

코딩 실력이 좀 더 좋아지면 코드를 조금씩 다듬는 식으로 계속 업데이트를 해봐야겠다.