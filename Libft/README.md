# LIBFT

## 나만의 라이브러리 만들기

향후 42seoul 본과정에서 계속 쓰일 함수들을 만들고, 모듈화 시켜서 지속적으로 사용하게 된다.

모든것을 자기 손으로 직접 만들어보라는 42의 뜻이지 않을까 싶다.

-----------------------

웬만한 것들은 라피신 기간동안 했던 것들이나, 조금씩 달라지거나 아예 처음 만들어야하는 함수들도 있었다.

그것들 위주로 소개해보려 한다.

----------------------

1. memory

memory 부분은 string 부분과 다르게 공백문자일 경우 반환하지 않고, 공백 문자가 들어간 공간도 하나의 공간으로 생각해서 비교, 복사, 이동할 수 있다는 것이 인상깊었다.

또한, memcpy와 memmove의 기능은 거의 흡사한데, memcpy의 경우 dst와 src의 메모리 주소값이 겹칠 경우, 초기값을 저장하지 않아 주소값을 잃어버릴 수도 있지만, move의 경우는 겹칠 경우도 고려해야해서 조금 더 안정적이라는 것을 알 수 있었다.

<pre><code>{
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

}

<pre><code>{
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
}</code></pre>